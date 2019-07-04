#ifndef VILLA_H
#define VILLA_H
#include "building.h"

class villa:public building
{
protected:
    int rooms;
    long long building_area;
public:
    villa(){}
    villa(double _base_price,long long _total_area,QString _address,QString _picture,int _rooms,long long _building_area):building(_base_price,_total_area,_address,_picture){
        rooms=_rooms;
        building_area=_building_area;
    }
};

#endif // VILLA_H
