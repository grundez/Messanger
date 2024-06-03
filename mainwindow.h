#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTime>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void slotReadyRead();

private slots:
    void on_loginButton_clicked();
    void on_sendMsgButton_clicked();
    void on_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
    QTcpSocket* socket;
    QByteArray MessageData;
    void SendToServer(QString name, QString str);
    quint16 nextBlockSize;

};

#endif // MAINWINDOW_H
