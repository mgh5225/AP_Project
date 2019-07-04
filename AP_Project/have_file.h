#ifndef HAVE_FILE_H
#define HAVE_FILE_H
#include <QString>
#include <QJsonObject>
#include<ctime>
using namespace std;
class have_file
{
protected:
    QString ID;
public:
    have_file(){
        time_t now;
        time(&now);
        struct tm *t=localtime(&now);
        string temp=to_string(t->tm_year)+to_string(t->tm_mon)+to_string(t->tm_mday)+to_string(t->tm_hour)+to_string(t->tm_min)+to_string(t->tm_sec);
        ID=QString::fromStdString(temp);
    }
    virtual double total_price()=0;
    virtual ~have_file(){}
    QString get_id(){return ID;}
};

#endif // HAVE_FILE_H
