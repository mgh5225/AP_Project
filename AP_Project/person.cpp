#include "person.h"
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
size_t person::get_pass(){return password;}
