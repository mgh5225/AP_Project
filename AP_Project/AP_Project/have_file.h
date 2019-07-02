#ifndef HAVE_FILE_H
#define HAVE_FILE_H
#include <QString>
#include <QJsonObject>
using namespace std;
class have_file
{
protected:
    QString ID;
public:
   virtual double total_price()=0;
    virtual ~have_file(){}
    QString get_id(){return ID;}
};

#endif // HAVE_FILE_H
