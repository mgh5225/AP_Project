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
    double get_base_price(){return base_price;}
};

#endif // BUILDING_H
