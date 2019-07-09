#include "apartment.h"
apartment::apartment():building(){}
apartment::apartment(double _base_price,long long _total_area,QString _address,QString _picture,int _floors,int _units,QString _apply):building(_base_price,_total_area,_address,_picture){
    floors=_floors;
    units=_units;
    apply=_apply;
}
double apartment::total_price(){
    return base_price*total_area*0.8;
}
void apartment::read(QJsonObject& json){
   ID=json["ID"].toString();
   base_price=json["base_price"].toDouble();
   total_area=json["total_area"].toString().toLongLong();
   address=json["address"].toString();
   picture=json["picture"].toString();
   floors=json["floors"].toInt();
   units=json["units"].toInt();
   apply=json["apply"].toString();
}
void apartment::write(QJsonObject& json){
   json["ID"]=ID;
   json["base_price"]=base_price;
   json["total_area"]=QString::fromStdString(to_string(total_area));
   json["address"]=address;
   json["picture"]=picture;
   json["floors"]=floors;
   json["units"]=units;
   json["apply"]=apply;
}

void apartment::set_floors(int _f)
{
    floors=_f;
}

void apartment::set_units(int _u)
{
    units=_u;
}
int apartment::get_floors(){return floors;}
flat::flat():have_file (){}
flat::flat(apartment *_current_apartment,int _floor_num,bool _lift,int _rooms,long long _building_area,QString _picture,int _units):have_file (){
    current_apartment=_current_apartment;
    current_apartment_ID=current_apartment->get_id();
    floor_num=_floor_num;
    lift=_lift;
    rooms=_rooms;
    building_area=_building_area;
    picture=_picture;
    unit_number=_units;
}
int apartment::get_units(){return units;}

QString apartment::get_picture()
{
    return picture;
}

QString apartment::get_apply()
{
    return apply;
}
double flat::total_price(){
    return current_apartment->get_base_price()*building_area;
}

void flat::set_unit_num(int _u)
{
    unit_number=_u;
}

void flat::set_floor_num(int _f)
{
    floor_num=_f;
}

void flat::set_lift(bool _l)
{
    lift=_l;
}

void flat::set_rooms(int _r)
{
    rooms=_r;
}

void flat::set_building_area(long long _b)
{
    building_area=_b;
}
void flat::read(QJsonObject& json){
   ID=json["ID"].toString();
   current_apartment_ID=json["current_apartment_ID"].toString();
   floor_num=json["floor_num"].toInt();
   rooms=json["rooms"].toInt();
   building_area=json["building_area"].toString().toLongLong();
   lift=json["lift"].toBool();
   picture=json["picture"].toString();
   unit_number=json["unit_number"].toInt();
}
void flat::write(QJsonObject& json){
   json["ID"]=ID;
   json["current_apartment_ID"]=current_apartment_ID;
   json["floor_num"]=floor_num;
   json["rooms"]=rooms;
   json["building_area"]=QString::fromStdString(to_string(building_area));
   json["lift"]=lift;
   json["picture"]=picture;
   json["unit_number"]=unit_number;

}

void flat::set_current_apartmeent(apartment * _a)
{
       current_apartment=_a;
}
QString flat::get_current_apartment_ID(){return current_apartment_ID;}
apartment* flat::get_current_apartment(){return current_apartment;}
int flat::get_floor_num(){return floor_num;}
int flat::get_rooms(){return rooms;}

int flat::get_unit()
{
    return unit_number;
}
long long flat::get_building_area(){return building_area;}
QString flat::get_picture(){return picture;}
bool flat::get_lift(){return lift;}
