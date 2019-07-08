#ifndef APARTMENT_H
#define APARTMENT_H
#include "building.h"
#include <vector>
class flat;
class apartment : public building
{

    int floors;
    int units;
    QString apply;
public:
    apartment();
    apartment(double _base_price,long long _total_area,QString _address,QString _picture,int _floors,int _units,QString _apply);
    double total_price();
    void read(QJsonObject& json);
    void write(QJsonObject& json);
    int get_floors();
    int get_units();
    QString get_picture();
    QString get_apply();
};
class flat : public have_file
{
    int unit_number;
    QString current_apartment_ID;
    apartment * current_apartment;
    int floor_num;
    bool lift;
    int rooms;
    long long building_area;
    QString picture;
public:
    flat();
    flat(apartment *_current_apartment,int _floor_num,bool _lift,int _rooms,long long _building_area,QString _picture,int _unit);
    double total_price();
    void read(QJsonObject& json);
    void write(QJsonObject& json);
    void set_current_apartmeent(apartment*);
    QString get_current_apartment_ID();
    apartment* get_current_apartment();
    int get_floor_num();
    int get_rooms();
    int get_unit();
    long long get_building_area();
    QString get_picture();
    bool get_lift();
};
#endif // APARTMENT_H
