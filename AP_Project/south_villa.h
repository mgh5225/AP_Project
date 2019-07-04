#ifndef SOUTH_VILLA_H
#define SOUTH_VILLA_H
#include "villa.h"

class south_villa:public villa
{
    long long yard_area;
    long long parking_area;
public:
    south_villa();
    south_villa(double _base_price,long long _total_area,QString _address,QString _picture,int _rooms,long long _building_area,long long _yard_area,long long _parking_area);
    double total_price();
    void read(QJsonObject& json);
    void write(QJsonObject& json);
};

#endif // SOUTH_VILLA_H
