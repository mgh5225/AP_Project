#ifndef BUILDING_H
#define BUILDING_H
#include <QString>
#include "have_file.h"
using namespace std;

class building:public have_file
{
protected:
    double base_price;
    long long total_area;
    QString address;
    QString picture;
public:
    building();
    building(double _base_price,long long _total_area,QString _address,QString _picture);
    double get_base_price();
    long long get_total_area();
    QString get_address();
    QString get_picture();
    void set_address(QString);
    void set_base_price(double);
    void set_total_area(long long);
};

#endif // BUILDING_H
