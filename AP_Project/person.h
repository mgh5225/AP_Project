#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
#include <time.h>
#include <vector>
#include <map>
#include <fstream>
#include <exception>
using namespace std;
class log
{
    string person_ID;
    tm IO_time;
    bool status;
};
class personException:public exception{

}personEX;

class person{
protected:
    string ID;
    string name;
    tm birth_date;
    bool status;
    string username;
    size_t password;
    long double balance;
public:
    person(){}
    person(string _name,tm _birth_date,string _username,size_t _password){
        name=_name;
        birth_date=_birth_date;
        username=_username;
        password=_password;
        time_t now;
        time(&now);
        struct tm *t=localtime(&now);
        ID=to_string(t->tm_year)+to_string(t->tm_mon)+to_string(t->tm_mday)+to_string(t->tm_hour)+to_string(t->tm_min)+to_string(t->tm_sec);
        balance=0;
    }
    string get_id(){return ID;}
    size_t get_pass(){return password;}
};

#endif
