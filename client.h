#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QDebug>

class Client: public QObject
{
    Q_OBJECT
public:
    explicit Client();
    bool Connect(QString ip,QString port);
    void sendData(int x,int y,int dir);
    int getX();
    int getY();
    int getDir();
private slots:
    void receiveData();

private:
    QTcpSocket socket;
    int x,y,dir; //对方数据
};

#endif // CLIENT_H
