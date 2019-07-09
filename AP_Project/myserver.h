#ifndef SERVER_H
#define SERVER_H
#include <QtNetwork/QTcpServer>
#include<QObject>
#include<QDebug>
#include<QtNetwork/QHostAddress>
#include"mythread.h"
class myServer : public QTcpServer
{
    Q_OBJECT
public:
    myServer(QObject* parent=nullptr);
    void startServer();
protected:
   void incomingConnection(qintptr ID);
};

#endif // SERVER_H
