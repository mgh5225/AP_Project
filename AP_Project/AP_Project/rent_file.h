#ifndef RENT_FILE_H
#define RENT_FILE_H
#include "file.h"
class rent_file:public file{
    int rent_duration;
public:
    double mortgage_price(){return 0.05*building->total_price();}
    double rent_price(){return 0.01*building->total_price();}
    double final_price(){return rent_duration*rent_price()+mortgage_price()+commission*mortgage_price();}
    void read(QJsonObject& json){
        commission=json["commission"].toDouble();
        building_ID=json["building_ID"].toString();
        rent_duration=json["rent_duration"].toInt();
        manager_ID=json["manager_ID"].toString();
    }
    void write(QJsonObject& json){
        json["commission"]=commission;
        json["building_ID"]=building_ID;
        json["rent_duration"]=rent_duration;
        json["manager_ID"]=manager_ID;
    }
};

#endif // RENT_FILE_H
