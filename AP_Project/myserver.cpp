#include "myserver.h"
#include <QtNetwork/QHostAddress>
myServer::myServer(QObject* parnet):QTcpServer (parnet)
{

}

void myServer::startServer()
{
    if(!listen(QHostAddress::Any,1234)){
        qDebug()<<"error";
    }else{
        qDebug()<<"listen...";
    }
}

void myServer::incomingConnection(qintptr ID){
    qDebug()<<ID<<" connecting";
    myThread *thread=new myThread(ID,this);
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    thread->start();
}
