#ifndef SALE_FILE_H
#define SALE_FILE_H
#include <string>
using namespace std;
#include "file.h"
class sale_file:public file{
    string condition;
public:
    long double final_price(){
        return building->total_price()+(commission*building->total_price());
    }
};

#endif // SALE_FILE_H
