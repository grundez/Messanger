#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // создаем сокет и соединяем его с сигналами программы
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    nextBlockSize = 0; // блок памяти для сообщений

    // закидываем виджиты в общий интерфейс
    ui->stackedWidget->insertWidget(0, ui->widgetLogin);
    ui->stackedWidget->insertWidget(1, ui->widgetChat);

    // Устанавливаем текущую страницу
    ui->stackedWidget->setCurrentWidget(ui->widgetLogin); // Показываем первую страницу
    ui->usernameBanLabel->hide();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::SendToServer(QString username, QString message, QString info)
{
    MessageData.clear();
    QDataStream out(&MessageData, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << quint16(0) << QTime::currentTime() << username << message << info;
    out.device()->seek(0);
    out << quint16(MessageData.size() - sizeof(quint16));
    socket->write(MessageData);
    ui->lineEdit->clear();
}

void MainWindow::slotReadyRead()
{
    QVector <QString> reservUsersOnlise = usersOnline;
    usersOnline.clear();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if(in.status() == QDataStream::Ok){
        /*QString str;
        in >> str;
        ui->textBrowser->append(str);*/
        for(;;){
            if(nextBlockSize == 0){
                if(socket->bytesAvailable() < 2){
                    break;
                }
                in >> nextBlockSize;
            }
            if(socket->bytesAvailable() < nextBlockSize){
                break;
            }
            QString username, message, info;
            QTime time;
            in >> time >> username >> message >> info;
            nextBlockSize = 0;
            // выводим сообщение
            // если пришло сообщение о новом пользователе
            if (info == "log") {
                // Добавляем нового пользователя в список
                usersOnline.push_back(username);
            } else {
                // Выводим обычное сообщение
                ui->textBrowser->append(username + " " + time.toString());
                ui->textBrowser->append(message);
                ui->textBrowser->append("");
                usersOnline = reservUsersOnlise;
            }
        }
    }
    else{
        ui->textBrowser->append("Read error...");
    }

    // Очистка списка пользователей
    ui->userListWidget->clear();

    // Обновленного списка пользователей
    for (int i = 0; i <usersOnline.size(); i++) {
        QString param = usersOnline[i];
        if(usersOnline[i] == ui->lineUsername->text()){
            param = usersOnline[i] + " (Вы)";
        }
        QListWidgetItem *item = new QListWidgetItem(param);
        ui->userListWidget->insertItem(i, item);
    }
}

void MainWindow::on_loginButton_clicked()
{
    //адрес сервера для мессенджера
    if(ui->lineUsername->text() != ""){
        socket->connectToHost("127.0.0.1", 2323);
        ui->stackedWidget->setCurrentWidget(ui->widgetChat); // Показываем вторую страницу(чат)
        SendToServer(ui->lineUsername->text(), "newUserLoged", "log");
    }
    else{
        ui->usernameBanLabel->show();
    }
}

void MainWindow::on_lineUsername_returnPressed()
{
    if(ui->lineUsername->text() != ""){
        socket->connectToHost("127.0.0.1", 2323);
        ui->stackedWidget->setCurrentWidget(ui->widgetChat); // Показываем вторую страницу(чат)
        SendToServer(ui->lineUsername->text(), "newUserLoged", "log");
    }
    else{
        ui->usernameBanLabel->show();
    }
}

void MainWindow::on_sendMsgButton_clicked()
{
    if(ui->lineEdit->text() != ""){
        SendToServer(ui->lineUsername->text(), ui->lineEdit->text(), "msg");
    }
}

void MainWindow::on_lineEdit_returnPressed()
{
    if(ui->lineEdit->text() != ""){
        SendToServer(ui->lineUsername->text(), ui->lineEdit->text(), "msg");
    }
}



void MainWindow::on_lineUsername_textEdited(const QString &arg1)
{
    ui->usernameBanLabel->hide();
}

