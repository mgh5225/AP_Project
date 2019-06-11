#ifndef SOUTH_VILLA_H
#define SOUTH_VILLA_H
#include "villa.h"

class south_villa:public villa
{
    long long yard_area;
    long long parking_area;
public:
    long double total_price(){
        return base_price*building_area+base_price*yard_area*0.3+base_price*parking_area*0.15;
    }
};

#endif // SOUTH_VILLA_H
