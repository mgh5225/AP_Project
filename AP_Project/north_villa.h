#ifndef NORTH_VILLA_H
#define NORTH_VILLA_H
#include "villa.h"

class north_villa : public villa
{
    long long front_yard_area;
    long long back_yard_area;
public:
    north_villa():villa(){}
    double total_price(){
        return base_price*building_area+base_price*front_yard_area*0.3+base_price*back_yard_area*0.15;
    }
    void read(QJsonObject& json){
        ID=json["ID"].toString();
        base_price=json["base_price"].toDouble();
        total_area=json["total_area"].toString().toLongLong();
        address=json["address"].toString();
        picture=json["picture"].toString();
        rooms=json["rooms"].toInt();
        building_area=json["building_area"].toString().toLongLong();
        front_yard_area=json["front_yard_area"].toString().toLongLong();
        back_yard_area=json["back_yard_area"].toString().toLongLong();
    }
    void write(QJsonObject& json){
       json["ID"]=ID;
       json["base_price"]=base_price;
       json["total_area"]=QString::fromStdString(to_string(total_area));
       json["address"]=address;
       json["picture"]=picture;
       json["rooms"]=rooms;
       json["building_area"]=QString::fromStdString(to_string(building_area));
       json["front_yard_area"]=QString::fromStdString(to_string(front_yard_area));
       json["back_yard_area"]=QString::fromStdString(to_string(back_yard_area));
    }
};

#endif // NORTH_VILLA_H
