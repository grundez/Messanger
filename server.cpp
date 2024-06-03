#include "server.h"

Server::Server()
{
    if(this->listen(QHostAddress::Any,2323)){
        qDebug() << "start server";
    }
    else{
        qDebug() << "error connection";
    }
    nextBlockSize = 0;
}

void Server::incomingConnection(qintptr socketDescriptor){
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    Sockets.push_back(socket);
    qDebug() << "client " << " " << " connected " << socketDescriptor;
}

void Server::slotReadyRead(){
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if(in.status() == QDataStream::Ok){
        qDebug() << "read...";
        /*QString str;
        in >> str;
        qDebug() << str;
        SendToClient(str);*/
        for(;;){
            if(nextBlockSize == 0){
                qDebug() << "nextBlockSize = 0";
                if(socket->bytesAvailable() < 2){
                    qDebug() << "Data < 2byte, break";
                    break;
                }
                in >> nextBlockSize;
                qDebug() << "nextBlockSize = " << nextBlockSize;
            }
            if(socket->bytesAvailable() < nextBlockSize){
                qDebug() << "Data not full, break";
                break;
            }
            QString username, message;
            QTime time;
            in >> time >> username >> message;
            qDebug() << username << ": " << message << " " << time;
            nextBlockSize = 0;
            SendToClient(username, message);
            break;
        }
    }
    else{
        qDebug() << "DataStream reading error ...";
    }
}

void Server::SendToClient(QString username, QString message)
{
    MessageData.clear();
    QDataStream out(&MessageData, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << quint16(0) << QTime::currentTime() << username << message;
    out.device()->seek(0);
    out << quint16(MessageData.size() - sizeof(quint16));
    for (int i = 0; i < Sockets.size(); ++i) {
        Sockets[i]->write(MessageData);
    }
}
