#ifndef VILLA_H
#define VILLA_H
#include "building.h"

class villa:public building
{
protected:
    int rooms;
    long long building_area;
public:
    villa(){}
};

#endif // VILLA_H
