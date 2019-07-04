#ifndef SALE_FILE_H
#define SALE_FILE_H
#include <QString>
using namespace std;
#include "file.h"
class sale_file:public file{
    QString condition;
public:
    sale_file():file(){}
    sale_file(double _commission,QString _manager_ID,have_file* _building,QString _condition):file(_commission,_manager_ID,_building){
        condition=_condition;
    }
    double final_price(){
        return building->total_price()+(commission*building->total_price());
    }
    void read(QJsonObject& json){
        commission=json["commission"].toDouble();
        building_ID=json["building_ID"].toString();
        condition=json["condition"].toString();
        manager_ID=json["manager_ID"].toString();
    }
    void write(QJsonObject& json){
        json["commission"]=commission;
        json["building_ID"]=building_ID;
        json["condition"]=condition;
         json["manager_ID"]=manager_ID;
    }
};

#endif // SALE_FILE_H
