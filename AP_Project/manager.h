#ifndef MANAGER_H
#define MANAGER_H
#include "person.h"
class manager:public person{
 public:
    manager():person(){}
    manager(QString,tm,QString,size_t);
};
manager::manager(QString _name,tm _birth_date,QString _username,size_t _password):person(_name,_birth_date,_username,_password){
}

#endif // MANAGER_H
