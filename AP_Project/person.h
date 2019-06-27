#ifndef PERSON_H
#define PERSON_H
#include <QString>
#include <iostream>
#include <time.h>
#include <vector>
#include <map>
#include <fstream>
#include <exception>
#include <functional>
#include <algorithm>
using namespace std;
class log
{
    QString person_ID;
    tm IO_time;
    bool status;
};
enum class PEX{
    BADUSERNAME,
    BADPASSWORD
};

class personException:public exception{
public:
    PEX type;
    personException& operator()(PEX _type){
        type=_type;
    }
}personEX;

class person{
protected:
    QString ID;
    QString name;
    tm birth_date;
    bool status;
    QString username;
    size_t password;
    long double balance;
public:
    person(){}
    person(QString _name,tm _birth_date,QString _username,QString _password){
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
    QString get_id(){return ID;}
    size_t get_pass(){return password;}
};

#endif
