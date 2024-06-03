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
    QVector<QTcpSocket*> Sockets;
    QByteArray MessageData;
    void SendToClient(QString name, QString str);
    quint16 nextBlockSize;

public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();
};

#endif // SERVER_H
