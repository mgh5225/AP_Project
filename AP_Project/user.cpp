#include "user.h"
user::user(QString _name,tm _birth_date,QString _username,QString _password):person(_name,_birth_date,_username,_password){
}
void user::write(QJsonObject& json){
    json["ID"]=ID;
    json["name"]=name;
    QJsonObject date;
    date["year"]=birth_date.tm_year;
    date["month"]=birth_date.tm_mon;
    date["day"]=birth_date.tm_mday;
    json["birth_date"]=date;
    json["status"]=status;
    json["username"]=username;
    string temp=to_string(password);
    json["password"]=QString::fromStdString(temp);
    json["balance"]=balance;
}
void user::read(QJsonObject& json){
    ID=json["ID"].toString();
    name=json["name"].toString();
    QJsonObject date;
    date=json["birth_date"].toObject();
    birth_date.tm_year=date["year"].toInt();
    birth_date.tm_mon=date["month"].toInt();
    birth_date.tm_mday=date["day"].toInt();
    status=json["status"].toBool();
    username=json["username"].toString();
    QString temp=json["password"].toString();
    string temp2=temp.toStdString();
    stringstream ss(temp2);
    ss>>password;
    balance=json["balance"].toDouble();
}
