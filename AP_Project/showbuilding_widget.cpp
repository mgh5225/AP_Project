#include "showbuilding_widget.h"
#include "main_ui.h"
ShowBuilding_widget::ShowBuilding_widget(QWidget *parent,have_file* _file) : QWidget(parent)
{
   if(!_file) throw "FUCK YOU";
   file=_file;
   final_price=new QLabel(QString::fromStdString("Final Price: "+to_string(file->total_price())));
   building* b=dynamic_cast<building*>(file);
   if(b){
       pic=new QLabel;
       pic->setPixmap(QPixmap(b->get_picture()).scaled(256,150));
       address=new QLabel("Address: " + b->get_address());
       total_area=new QLabel(QString::fromStdString("Total Area: "+to_string(b->get_total_area())));

   }else {
       flat* f=dynamic_cast<flat*>(file);
       if(f){
           pic=new QLabel;
           pic->setPixmap(QPixmap(f->get_picture()).scaled(256,150));
           address=new QLabel("Address: " + f->get_current_apartment()->get_address());
           total_area=new QLabel(QString::fromStdString("Total Area:" + to_string(f->get_building_area())));
       }
   }
   int id = QFontDatabase::addApplicationFont(":/fonts/resource/fonts/Viga-Regular.ttf");
   QString family = QFontDatabase::applicationFontFamilies(id).at(0);
   final_price->setFont(QFont(family,10,QFont::Bold));
   address->setFont(QFont(family,10,QFont::Thin));
   total_area->setFont(QFont(family,10,QFont::Thin));
   my_grid_layout=new QGridLayout;
   my_grid_layout->addWidget(pic,0,0,3,1,Qt::AlignTop);
   my_grid_layout->addWidget(address,3,0,1,1,Qt::AlignLeft);
   my_grid_layout->addWidget(total_area,4,0,1,1,Qt::AlignLeft);
   my_grid_layout->addWidget(final_price,5,0,1,1,Qt::AlignLeft);
   pal=new QPalette;
   // set black background
   pal->setColor(QPalette::Background,QColor(255, 255, 255));
   frame=new QFrame;
   frame->setAutoFillBackground(true);
   frame->setPalette(*pal);
   frame->setFrameShape(QFrame::Panel);
   frame->setLayout(my_grid_layout);
   lay=new QGridLayout;
   lay->addWidget(frame);
   frame->setLineWidth(1);
   this->setLayout(lay);
   this->setMinimumSize(260,260);
   installEventFilter(this);
}
