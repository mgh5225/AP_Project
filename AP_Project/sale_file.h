#ifndef SALE_FILE_H
#define SALE_FILE_H
#include <QString>
using namespace std;
#include "file.h"
class sale_file:public file{
    QString condition;
public:
    sale_file();
    ~sale_file();
    sale_file(double _commission,QString _manager_ID,have_file* _building,QString _condition);
    double final_price();
    QString get_condition();
    void read(QJsonObject& json);
    void write(QJsonObject& json);
    void set_condition(QString _con);
};

#endif // SALE_FILE_H
