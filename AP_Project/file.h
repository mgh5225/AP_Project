#ifndef FILE_H
#define FILE_H
#include "have_file.h"
class file{
protected:
    static long double commission;
    have_file* building;
public:
    virtual long double final_price()=0;

};
long double file::commission=1000;
#endif // FILE_H
