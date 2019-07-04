#include "north_villa.h"
north_villa::north_villa():villa(){}
north_villa::north_villa(double _base_price,long long _total_area,QString _address,QString _picture,int _rooms,long long _building_area,long long _front_yard_area,long long _back_yard_area):villa (_base_price,_total_area,_address,_picture,_rooms,_building_area){
    front_yard_area=_front_yard_area;
    back_yard_area=_back_yard_area;
}
double north_villa::total_price(){
    return base_price*building_area+base_price*front_yard_area*0.3+base_price*back_yard_area*0.15;
}
void north_villa::read(QJsonObject& json){
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
void north_villa::write(QJsonObject& json){
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
