#ifndef NORTH_VILLA_H
#define NORTH_VILLA_H
#include "villa.h"

class north_villa : public villa
{
    long long front_yard_area;
    long long back_yard_area;
public:
    long double total_price(){
        return base_price*building_area+base_price*front_yard_area*0.3+base_price*back_yard_area*0.15;
    }
};

#endif // NORTH_VILLA_H
