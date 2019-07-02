#ifndef FILE_H
#define FILE_H
#include "have_file.h"
class file{
protected:
    double commission;
    QString building_ID;
    QString manager_ID;
    have_file* building;
public:
    virtual double final_price()=0;
    QString get_building_ID(){return building_ID;}
    QString get_manager_ID(){return manager_ID;}

};
#endif // FILE_H
