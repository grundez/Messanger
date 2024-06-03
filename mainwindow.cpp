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

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    socket->connectToHost("127.0.0.1", 2323);
    ui->stackedWidget->setCurrentWidget(ui->widgetChat); // Показываем первую страницу
}

void MainWindow::SendToServer(QString username, QString message)
{
    MessageData.clear();
    QDataStream out(&MessageData, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << quint16(0) << QTime::currentTime() << username << message;
    out.device()->seek(0);
    out << quint16(MessageData.size() - sizeof(quint16));
    socket->write(MessageData);
    ui->lineEdit->clear();
}

void MainWindow::slotReadyRead()
{
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
            QString username, message;
            QTime time;
            in >> time >> username >> message;
            nextBlockSize = 0;
            ui->textBrowser->append("[" + time.toString() + "] " + username + ": " + message);
        }
    }
    else{
        ui->textBrowser->append("Read error...");
    }
}

void MainWindow::on_sendMsgButton_clicked()
{
    SendToServer(ui->lineUsername->text(), ui->lineEdit->text());
}

void MainWindow::on_lineEdit_returnPressed()
{
    SendToServer(ui->lineUsername->text(), ui->lineEdit->text());
}

