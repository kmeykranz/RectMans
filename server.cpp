#include "server.h"

Server::Server(QObject *parent)
    : QTcpServer{parent}
{
}

//开启监听
void Server::Connect(int port)
{
    listen(QHostAddress::Any,port);
}
//玩家连入（自动）
void Server::incomingConnection(qintptr handle){
    socket.setSocketDescriptor(handle);
    qDebug("成功连入");
    connect(&socket,SIGNAL(readyRead()),this,SLOT(receiveData()));
    isConnected=1;
}
//接收数据
void Server::receiveData()
{
    // QByteArray 转 int[]
    QByteArray array=socket.readAll();
    int data[3];
    for (int i=0; i<3; i++)
    {
        int unTemp;
        memcpy(&unTemp, array.data() + sizeof(int) * i, sizeof(int));
        data[i] = unTemp;
    }
    x=data[0];
    y=data[1];
    dir=data[2];
}
//发送数据
void Server::sendData(int x_self,int y_self,int dir_self)
{
    if(isConnected){
        //int[] 转 QByteArray
        int  self[3] = {x_self,y_self,dir_self};
        QByteArray array;
        array.append((char*)self, sizeof(int) * 3);
        socket.write(array);
    }
}
//获取数据
int Server::getX()
{
    return x;
}
int Server::getY()
{
    return y;
}
int Server::getDir()
{
    return dir;
}

