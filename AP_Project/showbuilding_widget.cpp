#include "showbuilding_widget.h"
#include "main_ui.h"
#include "apartment_details_ui.h"
#include "flat_details_ui.h"
#include "northvilla_details_ui.h"
#include "southvilla_details_ui.h"
ShowBuilding_widget::ShowBuilding_widget(person* _p,QWidget *parent,have_file* _file) : QWidget(nullptr)
{
    p=_p;
    this->parent=parent;

   if(!_file) throw "FUCK YOU";
   file_p=_file;
   final_price=new QLabel(QString::fromStdString("Final Price: "+to_string(file_p->total_price())));
   building* b=dynamic_cast<building*>(file_p);
   if(b){
       pic=new QLabel;
       pic->setPixmap(QPixmap(b->get_picture()).scaled(256,150));
       address=new QLabel("Address: " + b->get_address());
       total_area=new QLabel(QString::fromStdString("Total Area: "+to_string(b->get_total_area())));

   }else {
       flat* f=dynamic_cast<flat*>(file_p);
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
   this->setMaximumSize(260,260);
   installEventFilter(this);
}
bool ShowBuilding_widget::eventFilter(QObject *object, QEvent *event){
    if(object==this && (event->type()==QEvent::Enter || event->type()==QEvent::Leave)){
        if(event->type()==QEvent::Enter){
            pal->setColor(QPalette::Background,QColor(130, 130, 130));
            frame->setPalette(*pal);
        }
        else {
            pal->setColor(QPalette::Background,QColor(255, 255, 255));
            frame->setPalette(*pal);
        }
    }
}
void ShowBuilding_widget::mousePressEvent(QMouseEvent *event){
    north_villa* nv=dynamic_cast<north_villa*>(file_p);
    south_villa* sv=dynamic_cast<south_villa*>(file_p);
    apartment* ap=dynamic_cast<apartment*>(file_p);
    flat* fl=dynamic_cast<flat*>(file_p);
    user* u=dynamic_cast<user*>(p);
    manager* m=dynamic_cast<manager*>(p);
    try{
        s=&sales.at(file_p->get_id());
    }
    catch(out_of_range){
        s=nullptr;
    }
    try {
        r=&rents.at(file_p->get_id());
    } catch (out_of_range) {
        r=nullptr;
    }
    if(ap){
        Apartment_Details_UI* test=new Apartment_Details_UI(*ap,nullptr);

        test->show();
        if(u){
            test->UserMode();
        }
        else if(m){
            test->AdminMode();
        }

    }
    else if(fl){
        Flat_Details_UI* test=new Flat_Details_UI(1,p,s,r,*fl,nullptr);
        test->show();
    }
    else if(nv){
       NorthVilla_Details_UI* test=new NorthVilla_Details_UI(p,s,r,*nv,nullptr);
       test->show();
    }
    else if(sv){
        SouthVilla_Details_UI* test=new SouthVilla_Details_UI(s,r,*sv,nullptr);
        test->show();
        if(u){
            test->UserMode();
        }
        else if(m){
            test->AdminMode();
        }
    }
}
