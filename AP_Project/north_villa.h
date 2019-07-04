#ifndef NORTH_VILLA_H
#define NORTH_VILLA_H
#include "villa.h"

class north_villa : public villa
{
    long long front_yard_area;
    long long back_yard_area;
public:
    north_villa();
    north_villa(double _base_price,long long _total_area,QString _address,QString _picture,int _rooms,long long _building_area,long long _front_yard_area,long long _back_yard_area);
    double total_price();
    void read(QJsonObject& json);
    void write(QJsonObject& json);
};

#endif // NORTH_VILLA_H
