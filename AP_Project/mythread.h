#ifndef THREAD_H
#define THREAD_H
#include<QThread>
#include<QtNetwork/QTcpSocket>
#include <QObject>
#include<QJsonObject>
#include<QJsonDocument>
#include<QDebug>
#include<QString>
#include<QTextCodec>
#include<QFile>
#include <string>
#include"headers.h"
using namespace std;
class myThread : public QThread
{
    Q_OBJECT
    QTcpSocket *socket;
    qintptr des;
public:
    myThread(qintptr ID,QObject* parent=nullptr);
    void run();
    void login(QJsonObject& json);
    void reg(QJsonObject& json);
    void logout(QJsonObject& json);
    void showBuildings(QJsonObject& json);
    void showLogs(QJsonObject& json);
signals:
    void error(QTcpSocket::SocketError err);
public slots:
    void readyRead();
    void disconnected();
};

#endif // THREAD_H
