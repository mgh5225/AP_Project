#ifndef MANAGER_H
#define MANAGER_H
#include "person.h"
#include <QJsonObject>
#include <sstream>
class manager:public person{
 public:
    manager();
    manager(QString,tm,QString,QString);
    void write(QJsonObject&);
    void read(QJsonObject&);
};
#endif // MANAGER_H
