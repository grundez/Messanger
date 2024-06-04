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
    qDebug() << "Client connected " << socketDescriptor;

    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    Sockets.push_back(socket);
}

void Server::SendUserJoinedNotification(QVector<QString> usersList)
{
    MessageData.clear();
    QDataStream out(&MessageData, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    QString info = "log";
    for(int i = 0; i<usersList.size(); i++){
        QString id = QString::number(i);
        out << quint16(0) << QTime::currentTime() << usersList[i] << id << info;
    }

    out.device()->seek(0);
    out << quint16(MessageData.size() - sizeof(quint16));
    for (int i = 0; i < Sockets.size(); ++i) {
        Sockets[i]->write(MessageData);
    }
}

void Server::SendUserMessages(QString user1, QString user2)
{
    MessageData.clear();
    QDataStream out(&MessageData, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    QString info = "usersListClicked";

    out.device()->seek(0);
    out << quint16(MessageData.size() - sizeof(quint16));
    for (int i = 0; i < Sockets.size(); ++i) {
        Sockets[i]->write(MessageData);
    }
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
            QString username, message, info;
            QTime time;
            in >> time >> username >> message >> info;
            qDebug() << info << " - " << username << ": " << message << " " << time;
            nextBlockSize = 0;
            if(info == "msg"){
                SendToClient(username, message);
            }
            else if(info == "usersListClicked"){
                //SendUserMessages(username, message, )
            }
            else{
                qDebug() << "New user: " << username;
                users.push_back(username);
                SendUserJoinedNotification(users);
            }
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
    QString info = "msg";
    out << quint16(0) << QTime::currentTime() << username << message << info;
    out.device()->seek(0);
    out << quint16(MessageData.size() - sizeof(quint16));
    for (int i = 0; i < Sockets.size(); ++i) {
        Sockets[i]->write(MessageData);
    }
}


