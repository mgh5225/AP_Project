#ifndef USER_H
#define USER_H
#include "person.h"
class user:public person{

public:
    user():person(){}
     user(string,tm,string,size_t);
};

user::user(string _name,tm _birth_date,string _username,size_t _password):person(_name,_birth_date,_username,_password){
}

#endif // USER_H
