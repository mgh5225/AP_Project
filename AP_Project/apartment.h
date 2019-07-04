#ifndef APARTMENT_H
#define APARTMENT_H
#include "building.h"
#include <vector>
class flat;
class apartment : public building
{

    int floors;
public:
    apartment(){}
    apartment(double _base_price,long long _total_area,QString _address,QString _picture,int _floors):building(_base_price,_total_area,_address,_picture){
        floors=_floors;
    }
    double total_price(){
        return base_price*total_area*0.8;
    }
    void read(QJsonObject& json){
       ID=json["ID"].toString();
       base_price=json["base_price"].toDouble();
       total_area=json["total_area"].toString().toLongLong();
       address=json["address"].toString();
       picture=json["picture"].toString();
       floors=json["floors"].toInt();
    }
    void write(QJsonObject& json){
       json["ID"]=ID;
       json["base_price"]=base_price;
       json["total_area"]=QString::fromStdString(to_string(total_area));
       json["address"]=address;
       json["picture"]=picture;
       json["floors"]=floors;
    }
    int get_floors(){return floors;}
};
class flat : public have_file
{
    QString current_apartment_ID;
    apartment * current_apartment;
    int floor_num;
    bool lift;
    int rooms;
    long long building_area;
    QString picture;
public:
    flat(apartment *_current_apartment,int _floor_num,bool _lift,int _rooms,long long _building_area,QString _picture){
        current_apartment=_current_apartment;
        current_apartment_ID=current_apartment->get_id();
        floor_num=_floor_num;
        lift=_lift;
        rooms=_rooms;
        building_area=_building_area;
        picture=_picture;
    }
    double total_price(){
        return current_apartment->get_base_price()*building_area;
    }
    void read(QJsonObject& json){
       ID=json["ID"].toString();
       current_apartment_ID=json["current_apartment_ID"].toString();
       floor_num=json["floor_num"].toInt();
       rooms=json["rooms"].toInt();
       building_area=json["building_area"].toString().toLongLong();
       lift=json["lift"].toBool();
       picture=json["picture"].toString();
    }
    void write(QJsonObject& json){
       json["ID"]=ID;
       json["current_apartment_ID"]=current_apartment_ID;
       json["floor_num"]=floor_num;
       json["rooms"]=rooms;
       json["building_area"]=QString::fromStdString(to_string(building_area));
       json["lift"]=lift;
       json["picture"]=picture;

    }
    QString get_current_apartment_ID(){return current_apartment_ID;}
    apartment* get_current_apartment(){return current_apartment;}
    int get_floor_num(){return floor_num;}
    long long get_building_area(){return building_area;}
    QString get_picture(){return picture;}
    bool get_lift(){return lift;}
};
#endif // APARTMENT_H
