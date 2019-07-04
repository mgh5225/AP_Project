#ifndef RENT_FILE_H
#define RENT_FILE_H
#include "file.h"
class rent_file:public file{
    int rent_duration;
public:
    rent_file();
    ~rent_file();
    rent_file(double _commission,QString _manager_ID,have_file* _building,int _rent_duration);
    double mortgage_price();
    double rent_price();
    double final_price();
    void read(QJsonObject& json);
    void write(QJsonObject& json);
};

#endif // RENT_FILE_H
