#include "person.h"
void log::read(QJsonObject& json){
    person_ID=json["person_ID"].toString();
    QJsonObject date;
    date=json["IO_time"].toObject();
    IO_time.tm_year=date["year"].toInt();
    IO_time.tm_mon=date["month"].toInt();
    IO_time.tm_mday=date["day"].toInt();
    IO_time.tm_hour=date["hour"].toInt();
    IO_time.tm_min=date["minute"].toInt();
    IO_time.tm_sec=date["second"].toInt();
    status=json["status"].toBool();
}
void log::write(QJsonObject& json){
    json["person_ID"]=person_ID;
    QJsonObject date;
    date["year"]=IO_time.tm_year;
    date["month"]=IO_time.tm_mon;
    date["day"]=IO_time.tm_mday;
    date["hour"]=IO_time.tm_hour;
    date["minute"]=IO_time.tm_min;
    date["second"]=IO_time.tm_sec;
    json["IO_time"]=date;
    json["status"]=status;
}
person::person(){}
person::person(QString _name,tm _birth_date,QString _username,QString _password){
    name=_name;
    birth_date=_birth_date;
    username=_username;
    hash<string> ph;
    password=ph(_password.toStdString());
    time_t now;
    time(&now);
    struct tm *t=localtime(&now);
    string temp=to_string(t->tm_year)+to_string(t->tm_mon)+to_string(t->tm_mday)+to_string(t->tm_hour)+to_string(t->tm_min)+to_string(t->tm_sec);
    ID=QString::fromStdString(temp);
    balance=0;
}
QString person::get_id(){return ID;}
QString person::get_user(){return username;}

double person::get_balance()
{
    return balance;
}

void person::set_balance(double _b)
{
    balance=_b;
}
size_t person::get_pass(){return password;}

person::~person()
{

}

log::log(QString _ID, tm t, bool b)
{
    string temp=to_string(t.tm_year)+to_string(t.tm_mon)+to_string(t.tm_mday)+to_string(t.tm_hour)+to_string(t.tm_min)+to_string(t.tm_sec);
    ID=QString::fromStdString(temp);
    person_ID=_ID;
    IO_time=t;
    status=b;

}
QString log::get_ID(){return ID;}
QString log::get_person_ID(){return person_ID;}
log::log()
{

}
