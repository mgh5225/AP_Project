#include"file.h"
file::file(){}
file::file(double _commission,QString _manager_ID,have_file* _building){
    commission=_commission;
    manager_ID=_manager_ID;
    building=_building;
    building_ID=building->get_id();
}
QString file::get_building_ID(){return building_ID;}
QString file::get_manager_ID(){return manager_ID;}
file::~file(){}
