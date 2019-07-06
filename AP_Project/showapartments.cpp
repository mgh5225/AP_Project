#include "showapartments.h"
#include "headers.h"
ShowApartments::ShowApartments(QWidget *parent) : QWidget(nullptr)
{
    this->parent=parent;
    all=new QGridLayout;
    scr=new QScrollArea;
    for(auto i=apartments.begin();i!=apartments.end();i++){
        aptrs.push_back(new ShowBuilding_widget(nullptr,&i->second));
    }
    int k=0;
    bool flag=false;
    for(int i=0;;i++){

        for(int j=0;j<3;j++){
             if(k==aptrs.size()){
                 flag=true;
                 break;
             }
            all->addWidget(aptrs[k],i,j);
            k++;
        }
        if(flag==true)break;
    }
    all->setAlignment(Qt::AlignCenter);
    scr->setFixedSize(1100,880);
    scr->setWidgetResizable(true);
    search_by_flat=new QToolButton;
    search_by_meter=new QToolButton;
    search_by_rooms=new QToolButton;
    side_lay=new QVBoxLayout;
    side=new QFrame;
    body_lay=new QHBoxLayout;
    body=new QWidget(parent);
    side_lay->addWidget(search_by_flat);
    side_lay->addWidget(search_by_meter);
    side_lay->addWidget(search_by_rooms);
    side_lay->setMargin(0);
    side_lay->setSpacing(0);
    side_lay->setAlignment(Qt::AlignTop);




    search_by_flat->setMinimumSize(90,70);
    search_by_meter->setMinimumSize(90,70);
    search_by_rooms->setMinimumSize(90,70);


    search_by_flat->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );
    search_by_meter->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );
    search_by_rooms->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );



    search_by_flat->setText("Search by Flat");/////////////////////
     search_by_flat->setStyleSheet("font: bold");

    search_by_meter->setText("Search by Meter");/////////////////////////////////
     search_by_meter->setStyleSheet("font: bold");


    search_by_rooms->setText("Search by Rooms");//////////
    search_by_rooms->setStyleSheet("font: bold");





     side->setStyleSheet("background-color: #91a0a1");




    search_by_flat->setStyleSheet("QToolButton:hover{ background-color: #34495e; color: black;}QToolButton{border:0px;color:white;padding:10px;text-align:center}");
    search_by_meter->setStyleSheet("QToolButton:hover{ background-color: #34495e;color: black;}QToolButton{border:0px;color:white;padding:10px;text-align:center}");
    search_by_rooms->setStyleSheet("QToolButton:hover{ background-color: #34495e;color: black;}QToolButton{border:0px;color:white;padding:10px;text-align:center}");








    side->setLayout(side_lay);
    body_lay->addWidget(side);
    scr->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    temp=new QWidget;
    temp->setLayout(all);
    scr->setWidget(temp);
    body_lay->addWidget(scr);
    body_lay->setMargin(0);
    body_lay->setSpacing(0);
    body->setLayout(body_lay);

    QSize availableSize = qApp->desktop()->availableGeometry().size();
        int width = availableSize.width();
        int height = availableSize.height();
        //qDebug() << "Available dimensions " << width << "x" << height;
       width *= 0.73; // 90% of the screen size
        height *= 0.8; // 90% of the screen size
        //qDebug() << "Computed dimensions " << width << "x" << height;
        QSize newSize( width, height);

        body->setGeometry(
            QStyle::alignedRect(
                Qt::LeftToRight,
                Qt::AlignCenter,
                newSize,
                qApp->desktop()->availableGeometry()
            )
        );
        body->setFixedSize(width-128,height-95);
        scr->setFixedSize(scr->width(),body->height());
         body->move(138,95);
    body->setAttribute(Qt::WA_TranslucentBackground, true);
    body->setWindowFlags(Qt::FramelessWindowHint);
    connect(search_by_flat,SIGNAL(clicked()),this,SLOT(on_btn_search_by_flat_clicked()));
    connect(search_by_meter,SIGNAL(clicked()),this,SLOT(on_btn_search_by_meter_clicked()));
    connect(search_by_rooms,SIGNAL(clicked()),this,SLOT(on_btn_search_by_rooms_clicked()));
    body->show();


}
void ShowApartments::on_btn_search_by_flat_clicked()
{
    QInputDialog in;
    in.setWindowFlag(Qt::FramelessWindowHint);
    in.setStyleSheet("QInputDialog{border:3px solid black}");
    in.setLabelText("Please enter number which you want see apartments with flats more than that number:");
    in.setInputMode(QInputDialog::IntInput);
    if(!in.exec())return;
    if(!aptrs.empty()) aptrs.clear();
    for(auto i=flats.begin();i!=flats.end();i++){
        if(i->second.size()>in.intValue()){
            aptrs.push_back(new ShowBuilding_widget(nullptr,&apartments[i->first]));
        }
    }
    for (int i = 0; i < all->count(); ++i)
    {
      QWidget *widget = all->itemAt(i)->widget();
      if (widget != nullptr)
      {
          widget->close();
      }
    }
    int k=0;
    bool flag=false;
    for(int i=0;;i++){

        for(int j=0;j<3;j++){
             if(k==aptrs.size()){
                 flag=true;
                 break;
             }
            all->addWidget(aptrs[k],i,j);
            k++;
        }
        if(flag)break;
    }
}
void ShowApartments::on_btn_search_by_meter_clicked()
{
    QInputDialog in;
    in.setWindowFlag(Qt::FramelessWindowHint);
    in.setStyleSheet("QInputDialog{border:3px solid black}");
    in.setLabelText("Please enter number which you want see apartments with at least a flat with area more than that number:");
    in.setInputMode(QInputDialog::IntInput);
    if(!in.exec())return;
    if(!aptrs.empty()) aptrs.clear();
    for(auto i=flats.begin();i!=flats.end();i++){
        for(auto j=i->second.begin();j!=i->second.end();j++){
            if(j->get_building_area()>in.intValue()){
                aptrs.push_back(new ShowBuilding_widget(nullptr,&apartments[i->first]));
                break;
            }
        }
    }
    for (int i = 0; i < all->count(); ++i)
    {
      QWidget *widget = all->itemAt(i)->widget();
      if (widget != nullptr)
      {
          widget->close();
      }
    }
    int k=0;
    bool flag=false;
    for(int i=0;;i++){

        for(int j=0;j<3;j++){
             if(k==aptrs.size()){
                 flag=true;
                 break;
             }
            all->addWidget(aptrs[k],i,j);
            k++;
        }
        if(flag)break;
    }
}
void ShowApartments::on_btn_search_by_rooms_clicked()
{
    QInputDialog in;
    in.setWindowFlag(Qt::FramelessWindowHint);
    in.setStyleSheet("QInputDialog{border:3px solid black}");
    in.setLabelText("Please enter number which you want see apartments with at least a flat with rooms more than that number:");
    in.setInputMode(QInputDialog::IntInput);
    if(!in.exec())return;
    if(!aptrs.empty()) aptrs.clear();
    for(auto i=flats.begin();i!=flats.end();i++){
        for(auto j=i->second.begin();j!=i->second.end();j++){
            if(j->get_rooms()>in.intValue()){
                aptrs.push_back(new ShowBuilding_widget(nullptr,&apartments[i->first]));
                break;
            }
        }
    }
    for (int i = 0; i < all->count(); ++i)
    {
      QWidget *widget = all->itemAt(i)->widget();
      if (widget != nullptr)
      {
          widget->close();
      }
    }
    int k=0;
    bool flag=false;
    for(int i=0;;i++){

        for(int j=0;j<3;j++){
             if(k==aptrs.size()){
                 flag=true;
                 break;
             }
            all->addWidget(aptrs[k],i,j);
            k++;
        }
        if(flag)break;
    }
}


