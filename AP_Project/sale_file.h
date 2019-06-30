#ifndef SALE_FILE_H
#define SALE_FILE_H
#include <QString>
using namespace std;
#include "file.h"
class sale_file:public file{
    QString condition;
public:
    double final_price(){
        return building->total_price()+(commission*building->total_price());
    }
    void read(QJsonObject& json){
        commission=json["commission"].toDouble();
        building_ID=json["building_ID"].toString();
        condition=json["condition"].toString();
    }
    void write(QJsonObject& json){
        json["commission"]=commission;
        json["building_ID"]=building_ID;
        json["condition"]=condition;
    }
};

#endif // SALE_FILE_H
