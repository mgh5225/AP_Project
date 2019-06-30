#ifndef FILE_H
#define FILE_H
#include "have_file.h"
class file{
protected:
    static double commission;
    QString building_ID;
    have_file* building;
public:
    virtual double final_price()=0;

};
double file::commission=1000;
#endif // FILE_H
