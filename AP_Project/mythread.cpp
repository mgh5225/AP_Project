#include "mythread.h"
myThread::myThread(qintptr ID,QObject* parent):QThread (parent)
{
    des=ID;
}

void myThread::run()
{
    qDebug()<<"Starting thread ID "<<des;
    socket=new QTcpSocket;
    if(!socket->setSocketDescriptor(des)){
        emit error(socket->error());
        return;
    }
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);

    qDebug()<<des<<" client connected";

    exec();
}

void myThread::readyRead()
{
    QByteArray data=socket->readAll();
    QTextCodec* codec=QTextCodec::codecForName("KOI8-R");
    QString str_data=codec->toUnicode(data);
    QJsonDocument doc_data= QJsonDocument::fromJson(str_data.toUtf8());
    QJsonObject json_data=doc_data.object();
    if(json_data["req"]=="login") login(json_data);
    if(json_data["req"]=="register") reg(json_data);
    else if(json_data["req"]=="logout") logout(json_data);
    else if(json_data["req"]=="show_buildings") showBuildings(json_data);
    else if(json_data["req"]=="logs") showLogs(json_data);

}

void myThread::disconnected()
{
    qDebug()<<des<<" disconnected";
    socket->deleteLater();
    exit(0);
}

void myThread::login(QJsonObject& json)
{
    person* p;
    try {
        if(json["mode"]=="user"){
            p=&login_usr(json["username"].toString(),json["password"].toString());
            QJsonObject ans;
            ans["code"]=true;
            ans["mode"]="user";
            ans["person"]=usersjson[p->get_user()].toObject();
            QByteArray arr=QJsonDocument(ans).toJson();
            time_t now;
            time(&now);
            struct tm t=*localtime(&now);
            log l(p->get_id(),t,true);
            logs[p->get_id()].push_back(l);
            QJsonObject temp;
            l.write(temp);
            logsjson[l.get_ID()]=temp;
            socket->write(arr);
        }
        if(json["mode"]=="manager"){
            p=&login_mgr(json["username"].toString(),json["password"].toString());
            QJsonObject ans;
            ans["code"]=true;
            ans["mode"]="manager";
            ans["person"]=managersjson[p->get_user()].toObject();
            QByteArray arr=QJsonDocument(ans).toJson();
            time_t now;
            time(&now);
            struct tm t=*localtime(&now);
            log l(p->get_id(),t,true);
            logs[p->get_id()].push_back(l);
            QJsonObject temp;
            l.write(temp);
            logsjson[l.get_ID()]=temp;
            socket->write(arr);
        }
    } catch (personException ex) {
        QJsonObject ans;
        ans["code"]=false;
        QByteArray arr=QJsonDocument(ans).toJson();
        socket->write(arr);
    }
}

void myThread::reg(QJsonObject& json)
{
    if(json["mode"]=="user"){
        QString date=json["birth_date"].toString();
        date.replace("/"," ");
        QTextStream stream(&date);
        tm t;
        QString year;
        QString month;
        QString day;
        stream>>month>>day>>year;
        t.tm_year=year.toInt();
        t.tm_mon=month.toInt();
        t.tm_mday=day.toInt();
        QJsonObject ans;
        ans["code"]=sign_up_usr(json["full_name"].toString(),t,json["username"].toString(),json["password"].toString());
        QByteArray arr=QJsonDocument(ans).toJson();
        socket->write(arr);
    }
    if(json["mode"]=="manager"){
        QString date=json["birth_date"].toString();
        date.replace("/"," ");
        QTextStream stream(&date);
        tm t;
        QString year;
        QString month;
        QString day;
        stream>>month>>day>>year;
        t.tm_year=year.toInt();
        t.tm_mon=month.toInt();
        t.tm_mday=day.toInt();
        QJsonObject ans;
        ans["code"]=sign_up_mgr(json["full_name"].toString(),t,json["username"].toString(),json["password"].toString());
        QByteArray arr=QJsonDocument(ans).toJson();
        socket->write(arr);
    }
}

void myThread::logout(QJsonObject &json)
{
    time_t now;
    time(&now);
    struct tm t=*localtime(&now);
    log l(json["ID"].toString(),t,false);
    logs[json["ID"].toString()].push_back(l);
    QJsonObject temp;
    l.write(temp);
    logsjson[l.get_ID()]=temp;
    QJsonObject ans;
    ans["code"]=true;
    QByteArray arr=QJsonDocument(ans).toJson();
    socket->write(arr);
}

void myThread::showBuildings(QJsonObject &json)
{
    QJsonObject ans;
    ans["code"]=true;
     QJsonObject all;
    if(json["mode"]=="apartment"){
        for(auto i=apartmentsjson.begin();i!=apartmentsjson.end();i++){
            QJsonObject v= i.value().toObject();
            v["final_price"]=apartments[i.key()].total_price();
            all.insert(i.key(),v);
        }
    }
    else if(json["mode"]=="north_villa"){
        for(auto i=nvillasjson.begin();i!=nvillasjson.end();i++){
            QJsonObject v= i.value().toObject();
            v["final_price"]=nvillas[i.key()].total_price();
            all.insert(i.key(),v);
        }
    }
    else if(json["mode"]=="south_villa"){
        for(auto i=svillasjson.begin();i!=svillasjson.end();i++){
            QJsonObject v= i.value().toObject();
            v["final_price"]=svillas[i.key()].total_price();
            all.insert(i.key(),v);
        }
    }
    else if(json["mode"]=="all"){
        for(auto i=apartmentsjson.begin();i!=apartmentsjson.end();i++){
            QJsonObject v= i.value().toObject();
            v["final_price"]=apartments[i.key()].total_price();
            all.insert(i.key(),v);
        }
        for(auto i=nvillasjson.begin();i!=nvillasjson.end();i++){
            QJsonObject v= i.value().toObject();
            v["final_price"]=nvillas[i.key()].total_price();
            all.insert(i.key(),v);
        }
        for(auto i=svillasjson.begin();i!=svillasjson.end();i++){
            QJsonObject v= i.value().toObject();
            v["final_price"]=svillas[i.key()].total_price();
            all.insert(i.key(),v);
        }

    }
    ans["buildings"]=all;
    QByteArray arr=QJsonDocument(ans).toJson();
    socket->write(arr);
}

void myThread::showLogs(QJsonObject &json)
{
    QJsonObject ans;
    ans["code"]=true;
    auto l=logs[json["ID"].toString()];
    QJsonObject json_l;
    for(auto ll:l){
        QJsonObject temp;
        ll.write(temp);
        json_l[ll.get_ID()]=temp;
    }
    ans["logs"]=json_l;
    QByteArray arr=QJsonDocument(ans).toJson();
    socket->write(arr);
}
