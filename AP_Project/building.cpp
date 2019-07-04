#include "building.h"
building::building():have_file(){}
building::building(double _base_price,long long _total_area,QString _address,QString _picture):have_file(){
    base_price=_base_price;
    total_area=_total_area;
    address=_address;
    picture=_picture;
}
double building::get_base_price(){return base_price;}
long long building::get_total_area(){return total_area;}
QString building::get_address(){return address;}
QString building::get_picture(){return picture;}
