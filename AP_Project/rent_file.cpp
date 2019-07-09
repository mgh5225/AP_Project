#include"rent_file.h"
rent_file::rent_file():file(){}
rent_file::~rent_file(){}
rent_file::rent_file(double _commission,QString _manager_ID,have_file* _building,int _rent_duration):file(_commission,_manager_ID,_building){
    rent_duration=_rent_duration;
}
double rent_file::mortgage_price(){return 0.05*building->total_price();}
double rent_file::rent_price(){return 0.01*building->total_price();}
double rent_file::final_price(){return rent_duration*rent_price()+mortgage_price()+commission*mortgage_price();}

int rent_file::get_duration()
{
    return rent_duration;
}

void rent_file::set_duration(int _d)
{
    rent_duration=_d;
}
void rent_file::read(QJsonObject& json){
    commission=json["commission"].toDouble();
    building_ID=json["building_ID"].toString();
    rent_duration=json["rent_duration"].toInt();
    manager_ID=json["manager_ID"].toString();
    user_ID=json["user_ID"].toString();
    isAccepted=json["isAccepted"].toBool();
}
void rent_file::write(QJsonObject& json){
    json["commission"]=commission;
    json["building_ID"]=building_ID;
    json["rent_duration"]=rent_duration;
    json["manager_ID"]=manager_ID;
    json["user_ID"]=user_ID;
    json["isAccepted"]=isAccepted;
}
