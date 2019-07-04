#ifndef USER_H
#define USER_H
#include "person.h"
#include <QJsonObject>
#include <QDate>
#include <QString>
#include <sstream>
class user:public person{

public:
    user():person(){}
    user(QString,tm,QString,QString);
    void write(QJsonObject&);
    void read(QJsonObject&);
};

#endif // USER_H
