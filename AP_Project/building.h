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
    building(){}
    building(double _base_price,long long _total_area,QString _address,QString _picture){
        base_price=_base_price;
        total_area=_total_area;
        address=_address;
        picture=_picture;
    }
    double get_base_price(){return base_price;}
    long long get_total_area(){return total_area;}
    QString get_address(){return address;}
    QString get_picture(){return picture;}
};

#endif // BUILDING_H
