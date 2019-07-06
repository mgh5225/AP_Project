#include "headers.h"

void unloading(){
    QFile saveuser(QStringLiteral("users.json"));
    saveuser.open(QIODevice::WriteOnly);
    QJsonDocument savedocuser(usersjson);
    saveuser.write(savedocuser.toJson());

    QFile savemanager(QStringLiteral("managers.json"));
    savemanager.open(QIODevice::WriteOnly);
    QJsonDocument savedocmanager(managersjson);
    savemanager.write(savedocmanager.toJson());

    QFile saveapartment(QStringLiteral("apartments.json"));
    saveapartment.open(QIODevice::WriteOnly);
    QJsonDocument savedocapartment(apartmentsjson);
    saveapartment.write(savedocapartment.toJson());

    QFile savesvilla(QStringLiteral("svillas.json"));
    savesvilla.open(QIODevice::WriteOnly);
    QJsonDocument savedocsvilla(svillasjson);
    savesvilla.write(savedocsvilla.toJson());

    QFile savenvilla(QStringLiteral("nvillas.json"));
    savenvilla.open(QIODevice::WriteOnly);
    QJsonDocument savedocnvilla(nvillasjson);
    savenvilla.write(savedocnvilla.toJson());

    QFile saveflat(QStringLiteral("flats.json"));
    saveflat.open(QIODevice::WriteOnly);
    QJsonDocument savedocflat(flatsjson);
    saveflat.write(savedocflat.toJson());

    QFile savelog(QStringLiteral("logs.json"));
    savelog.open(QIODevice::WriteOnly);
    QJsonDocument savedoclog(logsjson);
    savelog.write(savedoclog.toJson());

    QFile saverent(QStringLiteral("rents.json"));
    saverent.open(QIODevice::WriteOnly);
    QJsonDocument savedocrent(rentsjson);
    saverent.write(savedocrent.toJson());

    QFile savesale(QStringLiteral("sales.json"));
    savesale.open(QIODevice::WriteOnly);
    QJsonDocument savedocsale(salesjson);
    savesale.write(savedocsale.toJson());

    saveuser.close();
    savemanager.close();
    saveapartment.close();
    savesvilla.close();
    savenvilla.close();
    saveflat.close();
    savelog.close();
    saverent.close();
    savesale.close();


}
void loading(){
    QFile loaduser(QStringLiteral("users.json"));
    loaduser.open(QIODevice::ReadOnly);
    QByteArray userdata=loaduser.readAll();
    QJsonDocument userdoc(QJsonDocument::fromJson(userdata));
    user u;
    QJsonObject temp;
    usersjson=userdoc.object();
    for (auto i=usersjson.begin();i!=usersjson.end();i++) {
       temp=i.value().toObject();
       u.read(temp);
       users[u.get_user()]=u;
    }

    QFile loadmanager(QStringLiteral("managers.json"));
    loadmanager.open(QIODevice::ReadOnly);
    QByteArray managerdata=loadmanager.readAll();
    QJsonDocument managerdoc(QJsonDocument::fromJson(managerdata));
    manager m;
    managersjson=managerdoc.object();
    for (auto i=managersjson.begin();i!=managersjson.end();i++) {
       temp=i.value().toObject();
       m.read(temp);
       managers[m.get_user()]=m;
    }

    QFile loadapartment(QStringLiteral("apartments.json"));
    loadapartment.open(QIODevice::ReadOnly);
    QByteArray apartmentdata=loadapartment.readAll();
    QJsonDocument apartmentdoc(QJsonDocument::fromJson(apartmentdata));
    apartment a;
    apartmentsjson=apartmentdoc.object();
    for (auto i=apartmentsjson.begin();i!=apartmentsjson.end();i++) {
       temp=i.value().toObject();
       a.read(temp);
       apartments[a.get_id()]=a;
    }

    QFile loadsvilla(QStringLiteral("svillas.json"));
    loadsvilla.open(QIODevice::ReadOnly);
    QByteArray svilladata=loadsvilla.readAll();
    QJsonDocument svilladoc(QJsonDocument::fromJson(svilladata));
    south_villa sv;
    svillasjson=svilladoc.object();
    for (auto i=svillasjson.begin();i!=svillasjson.end();i++) {
       temp=i.value().toObject();
       sv.read(temp);
       svillas[sv.get_id()]=sv;
    }

    QFile loadnvilla(QStringLiteral("nvillas.json"));
    loadnvilla.open(QIODevice::ReadOnly);
    QByteArray nvilladata=loadnvilla.readAll();
    QJsonDocument nvilladoc(QJsonDocument::fromJson(nvilladata));
    north_villa nv;
    nvillasjson=nvilladoc.object();
    for (auto i=nvillasjson.begin();i!=nvillasjson.end();i++) {
       temp=i.value().toObject();
       nv.read(temp);
       nvillas[nv.get_id()]=nv;
    }

    QFile loadflat(QStringLiteral("flats.json"));
    loadflat.open(QIODevice::ReadOnly);
    QByteArray flatdata=loadflat.readAll();
    QJsonDocument flatdoc(QJsonDocument::fromJson(flatdata));
    flat f;
    flatsjson=flatdoc.object();
    for (auto i=flatsjson.begin();i!=flatsjson.end();i++) {
       temp=i.value().toObject();
       f.read(temp);
       flats[f.get_current_apartment_ID()].push_back(f);
    }

    QFile loadlog(QStringLiteral("logs.json"));
    loadlog.open(QIODevice::ReadOnly);
    QByteArray logdata=loadlog.readAll();
    QJsonDocument logdoc(QJsonDocument::fromJson(logdata));
    log l;
    logsjson=logdoc.object();
    for (auto i=logsjson.begin();i!=logsjson.end();i++) {
       temp=i.value().toObject();
       l.read(temp);
       logs[l.get_person_ID()].push_back(l);
    }

    QFile loadrent(QStringLiteral("rents.json"));
    loadrent.open(QIODevice::ReadOnly);
    QByteArray rentdata=loadrent.readAll();
    QJsonDocument rentdoc(QJsonDocument::fromJson(rentdata));
    rent_file r;
    rentsjson=rentdoc.object();
    for (auto i=rentsjson.begin();i!=rentsjson.end();i++) {
       temp=i.value().toObject();
       r.read(temp);
       rents[r.get_building_ID()]=r;
    }

    QFile loadsale(QStringLiteral("sales.json"));
    loadsale.open(QIODevice::ReadOnly);
    QByteArray saledata=loadsale.readAll();
    QJsonDocument saledoc(QJsonDocument::fromJson(saledata));
    sale_file s;
    salesjson=saledoc.object();
    for (auto i=salesjson.begin();i!=salesjson.end();i++) {
       temp=i.value().toObject();
       s.read(temp);
       sales[s.get_building_ID()]=s;
    }

    loaduser.close();
    loadmanager.close();
    loadapartment.close();
    loadsvilla.close();
    loadnvilla.close();
    loadflat.close();
    loadlog.close();
    loadrent.close();
    loadsale.close();
}
bool sign_up_usr(QString _name,tm _birth_date,QString _username,QString _password){
    if(users.count(_username)==1){
        return 0;
    }
     user u(_name,_birth_date,_username,_password);
     users[_username]=u;
     QJsonObject temp;
     u.write(temp);
     usersjson[_username]=temp;
     return 1;
}
bool sign_up_mgr(QString _name,tm _birth_date,QString _username,QString _password){
    if(managers.count(_username)==1){
        return 0;
    }
     manager m(_name,_birth_date,_username,_password);
     managers[_username]=m;
     QJsonObject temp;
     m.write(temp);
     managersjson[_username]=temp;
     return 1;
}
user& login_usr(QString _username,QString _password){
    hash<string> ph;
    personException personEX;
    if(users.count(_username)==1){
        if(users[_username].get_pass()==ph(_password.toStdString()))return users[_username];
        else throw personEX(PEX::BADPASSWORD);
    }
    else{
        throw personEX(PEX::BADUSERNAME);
    }
}
manager& login_mgr(QString _username,QString _password){
    hash<string> ph;
    personException personEX;
    if(managers.count(_username)==1){
        if(managers[_username].get_pass()==ph(_password.toStdString()))return managers[_username];
        else throw personEX(PEX::BADPASSWORD);
    }
    else{
        throw personEX(PEX::BADUSERNAME);
    }
}
