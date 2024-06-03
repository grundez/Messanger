#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QMetaObject>
#include <QTime>

class Server : public QTcpServer
{
    Q_OBJECT;

public:
    Server();
    QTcpSocket *socket;

private:
    int usersOnlineCounter = 0;
    QVector<QTcpSocket*> Sockets;
    QVector<QString> users;
    QByteArray MessageData;
    void SendToClient(QString name, QString str);
    quint16 nextBlockSize;
    void SendUserJoinedNotification(QVector<QString> usersList);

public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();
};

#endif // SERVER_H
