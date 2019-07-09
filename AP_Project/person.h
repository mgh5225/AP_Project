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
#include<QJsonObject>
using namespace std;
class log
{
    QString ID;
    QString person_ID;
    tm IO_time;
    bool status;
public:
    void read(QJsonObject&);
    void write(QJsonObject&);
    QString get_person_ID();
    log(QString,struct tm,bool);
    log();
    QString get_ID();
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
        return *this;
    }
};

class person{
protected:
    QString ID;
    QString name;
    tm birth_date;
    bool status;
    QString username;
    size_t password;
    double balance;
public:
    person();
    person(QString _name,tm _birth_date,QString _username,QString _password);
    QString get_id();
    QString get_user();
    double get_balance();
    size_t get_pass();
    virtual ~person();
};

#endif
