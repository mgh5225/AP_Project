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
    have_file();
    virtual double total_price()=0;
    virtual ~have_file();
    QString get_id();
};

#endif // HAVE_FILE_H
