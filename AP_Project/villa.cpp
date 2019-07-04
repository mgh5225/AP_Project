#include "villa.h"
villa::villa(){}
villa::villa(double _base_price,long long _total_area,QString _address,QString _picture,int _rooms,long long _building_area):building(_base_price,_total_area,_address,_picture){
    rooms=_rooms;
    building_area=_building_area;
}
