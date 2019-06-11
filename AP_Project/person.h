#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;
class log
{
    string person_ID;
    tm IO_time;
    bool status;
};
using namespace std;
class person{
private:
    string ID;
    string name;
    struct tm birth_date;
    bool status;
    string username;
    size_t password;
    long double balance;
    vector<log> logs;

};

#endif
