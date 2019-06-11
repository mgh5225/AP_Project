#ifndef APARTMENT_H
#define APARTMENT_H
#include "building.h"
#include <vector>
class flat;
class apartment : public building
{
    bool lift;
    int floors;
    vector<flat*> flats;
public:
    long double total_price(){
        return base_price*total_area*0.8;
    }
};
class flat : public have_file
{
    apartment * current_apartment;
    int floor_num;
    int rooms;
    long long building_area;
    string picture;
public:
    long double total_price(){
        return current_apartment->get_base_price()*building_area;
    }
};
#endif // APARTMENT_H
