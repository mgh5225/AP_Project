#include "showbuilding_widget.h"

ShowBuilding_widget::ShowBuilding_widget(QWidget *parent,have_file* _file) : QWidget(parent)
{
   if(!_file) throw "FUCK YOU";
   file=_file;
   final_price=new QLabel(QString::fromStdString("Final Price: "+to_string(file->total_price())));
   building* b=dynamic_cast<building*>(file);
   if(b){
       pic=new QLabel;
       pic->setPixmap(QPixmap(b->get_picture()).scaled(256,128));
       address=new QLabel("Address: " + b->get_address());
       total_area=new QLabel(QString::fromStdString("Total Area: "+to_string(b->get_total_area())));
   }else {
       flat* f=dynamic_cast<flat*>(file);
       if(f){
           pic=new QLabel;
           pic->setPixmap(QPixmap(f->get_picture()).scaled(256,128));
           address=new QLabel("Address: " + f->get_current_apartment()->get_address());
           total_area=new QLabel(QString::fromStdString("Total Area:" + to_string(f->get_building_area())));
       }
   }
   my_grid_layout=new QGridLayout;
   my_grid_layout->addWidget(pic,0,0,3,1,Qt::AlignTop);
   my_grid_layout->addWidget(address,3,0,1,1,Qt::AlignLeft);
   my_grid_layout->addWidget(total_area,4,0,1,1,Qt::AlignLeft);
   my_grid_layout->addWidget(final_price,5,0,1,1,Qt::AlignLeft);
   this->setLayout(my_grid_layout);
   this->setStyleSheet("background-color:white;font-weight:bold");
}
