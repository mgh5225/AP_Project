#ifndef SOUTH_VILLA_H
#define SOUTH_VILLA_H
#include "villa.h"

class south_villa:public villa
{
    long long yard_area;
    long long parking_area;
public:
    south_villa():villa(){}
    south_villa(double _base_price,long long _total_area,QString _address,QString _picture,int _rooms,long long _building_area,long long _yard_area,long long _parking_area):villa (_base_price,_total_area,_address,_picture,_rooms,_building_area){
        yard_area=_yard_area;
        parking_area=_parking_area;
    }
    double total_price(){
        return base_price*building_area+base_price*yard_area*0.3+base_price*parking_area*0.15;
    }
    void read(QJsonObject& json){
        ID=json["ID"].toString();
        base_price=json["base_price"].toDouble();
        total_area=json["total_area"].toString().toLongLong();
        address=json["address"].toString();
        picture=json["picture"].toString();
        rooms=json["rooms"].toInt();
        building_area=json["building_area"].toString().toLongLong();
        yard_area=json["yard_area"].toString().toLongLong();
        parking_area=json["parking_area"].toString().toLongLong();
    }
    void write(QJsonObject& json){
       json["ID"]=ID;
       json["base_price"]=base_price;
       json["total_area"]=QString::fromStdString(to_string(total_area));
       json["address"]=address;
       json["picture"]=picture;
       json["rooms"]=rooms;
       json["building_area"]=QString::fromStdString(to_string(building_area));
       json["yard_area"]=QString::fromStdString(to_string(yard_area));
       json["parking_area"]=QString::fromStdString(to_string(yard_area));
    }
};

#endif // SOUTH_VILLA_H
