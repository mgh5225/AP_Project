#ifndef FILE_H
#define FILE_H
#include "have_file.h"
class file{
protected:
    double commission;
    QString building_ID;
    QString manager_ID;
    have_file* building;
    bool isAccepted;
    QString user_ID;
public:
    file();
    virtual~file();
    file(double _commission,QString _manager_ID,have_file* _building);
    virtual double final_price()=0;
    QString get_building_ID();
    QString get_manager_ID();
    QString get_user_ID();
    void set_user_ID(QString);
    bool get_is_accpted();
    void set_is_accpted(bool);
    void set_building(have_file*);

};
#endif // FILE_H
