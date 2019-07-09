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
    else if(json_data["req"]=="add_building") addNewBuilding(json_data);
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

void myThread::addNewBuilding(QJsonObject &json)
{
    QJsonObject ans;
    if(json["mode"]=="apartment"){
        apartment a(json["base_price"].toString().toDouble(),json["apartment_area"].toString().toLongLong(),json["address"].toString(),"",json["floors"].toString().toInt(),json["units"].toString().toInt(),json["status"].toString());
        apartments[a.get_id()]=a;
        QJsonObject j;
        a.write(j);
        apartmentsjson[a.get_id()]=j;

    }else if(json["mode"]=="flat"){
        flat f(&apartments[json["current_apartment_ID"].toString()],json["floor_num"].toString().toInt(),json["lift"].toBool(),json["rooms"].toString().toInt(),json["full_area"].toString().toLongLong(),"",json["unit_number"].toString().toInt());
        flats[json["current_apartment_ID"].toString()].push_back(f);
        QJsonObject j;
        f.write(j);
        flatsjson[f.get_id()]=j;
        if(json["status"]=="sale"){
            sale_file s(50000,json["ID"].toString(),&f,"Sale a building In website");
            sales[f.get_id()]=s;
            QJsonObject j2;
            s.write(j2);
            salesjson[f.get_id()]=j2;
        }
        else if(json["status"]=="rent"){
            rent_file r(50000,json["ID"].toString(),&f,100);
            rents[f.get_id()]=r;
            QJsonObject j3;
            r.write(j3);
            rentsjson[f.get_id()]=j3;
        }
        else if(json["status"]=="both"){
            sale_file s(50000,json["ID"].toString(),&f,"Sale a building In website");
            sales[f.get_id()]=s;
            QJsonObject j2;
            s.write(j2);
            salesjson[f.get_id()]=j2;
            rent_file r(50000,json["ID"].toString(),&f,100);
            rents[f.get_id()]=r;
            QJsonObject j3;
            r.write(j3);
            rentsjson[f.get_id()]=j3;
        }
    }else if(json["mode"]=="nvilla"){
        north_villa n(json["base_price"].toString().toDouble(),json["full_area"].toString().toLongLong(),json["address"].toString()," " ,json["rooms"].toString().toInt(),json["build_area"].toString().toLongLong(),json["front_yard_area"].toString().toLongLong(),json["back_yard_area"].toString().toLongLong());
        nvillas[n.get_id()]=n;
        QJsonObject j;
        n.write(j);
        nvillasjson[n.get_id()]=j;
        if(json["status"]=="sale"){
            sale_file s(50000,json["ID"].toString(),&n,"Sale a building In website");
            sales[n.get_id()]=s;
            QJsonObject j2;
            s.write(j2);
            salesjson[n.get_id()]=j2;
        }
        else if(json["status"]=="rent"){
            rent_file r(50000,json["ID"].toString(),&n,100);
            rents[n.get_id()]=r;
            QJsonObject j3;
            r.write(j3);
            rentsjson[n.get_id()]=j3;
        }
        else if(json["status"]=="both"){
            sale_file s(50000,json["ID"].toString(),&n,"Sale a building In website");
            sales[n.get_id()]=s;
            QJsonObject j2;
            s.write(j2);
            salesjson[n.get_id()]=j2;
            rent_file r(50000,json["ID"].toString(),&n,100);
            rents[n.get_id()]=r;
            QJsonObject j3;
            r.write(j3);
            rentsjson[n.get_id()]=j3;
        }

    }else if(json["mode"]=="svilla"){
        south_villa n(json["base_price"].toString().toDouble(),json["full_area"].toString().toLongLong(),json["address"].toString()," " ,json["rooms"].toString().toInt(),json["build_area"].toString().toLongLong(),json["yard_area"].toString().toLongLong(),json["parking_area"].toString().toLongLong());
        svillas[n.get_id()]=n;
        QJsonObject j;
        n.write(j);
        svillasjson[n.get_id()]=j;
        if(json["status"]=="sale"){
            sale_file s(50000,json["ID"].toString(),&n,"Sale a building In website");
            sales[n.get_id()]=s;
            QJsonObject j2;
            s.write(j2);
            salesjson[n.get_id()]=j2;
        }
        else if(json["status"]=="rent"){
            rent_file r(50000,json["ID"].toString(),&n,100);
            rents[n.get_id()]=r;
            QJsonObject j3;
            r.write(j3);
            rentsjson[n.get_id()]=j3;
        }
        else if(json["status"]=="both"){
            sale_file s(50000,json["ID"].toString(),&n,"Sale a building In website");
            sales[n.get_id()]=s;
            QJsonObject j2;
            s.write(j2);
            salesjson[n.get_id()]=j2;
            rent_file r(50000,json["ID"].toString(),&n,100);
            rents[n.get_id()]=r;
            QJsonObject j3;
            r.write(j3);
            rentsjson[n.get_id()]=j3;
        }
    }
    ans["code"]=true;
    QByteArray arr=QJsonDocument(ans).toJson();
    socket->write(arr);
}
