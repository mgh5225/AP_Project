#include "showallbuildings.h"
#include "headers.h"
#include <map>
#include <utility>
ShowAllBuildings::ShowAllBuildings(QWidget *parent) : QWidget(parent)
{
    this->parent=parent;
    all=new QGridLayout;
    scr=new QScrollArea;
    for(auto i=apartments.begin();i!=apartments.end();i++){
        allbu.push_back(new ShowBuilding_widget(nullptr,&i->second));
    }
    for(auto i=flats.begin();i!=flats.end();i++){
        for(int j=0;j<i->second.size();j++){
             allbu.push_back(new ShowBuilding_widget(nullptr,&i->second[j]));
        }
    }
    for(auto i=svillas.begin();i!=svillas.end();i++){
        allbu.push_back(new ShowBuilding_widget(nullptr,&i->second));
    }
    for(auto i=nvillas.begin();i!=nvillas.end();i++){
        allbu.push_back(new ShowBuilding_widget(nullptr,&i->second));
    }
    int k=0;
    bool flag=false;
    for(int i=0;;i++){

        for(int j=0;j<3;j++){
             if(k==allbu.size()){
                 flag=true;
                 break;
             }
            all->addWidget(allbu[k],i,j);
            k++;
        }
        if(flag==true)break;
    }
    all->setAlignment(Qt::AlignCenter);
    scr->setFixedSize(1100,880);
    scr->setWidgetResizable(true);
    search_by_price_meter=new QToolButton;
    search_by_perimeter=new QToolButton;
    sort_by_price=new QToolButton;
    side_lay=new QVBoxLayout;
    side=new QFrame;
    body_lay=new QHBoxLayout;
    body=new QWidget(parent);
    side_lay->addWidget(search_by_price_meter);
    side_lay->addWidget(search_by_perimeter);
    side_lay->addWidget(sort_by_price);
    side_lay->setMargin(0);
    side_lay->setSpacing(0);
    side_lay->setAlignment(Qt::AlignTop);




    search_by_price_meter->setMinimumSize(90,70);
    search_by_perimeter->setMinimumSize(90,70);
    sort_by_price->setMinimumSize(90,70);


    search_by_price_meter->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );
    search_by_perimeter->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );
    sort_by_price->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );



    search_by_price_meter->setText("Search by Price Meter");/////////////////////
     search_by_price_meter->setStyleSheet("font: bold");

    search_by_perimeter->setText("Search by Perimeter");/////////////////////////////////
     search_by_perimeter->setStyleSheet("font: bold");


    sort_by_price->setText("Sort by Price");//////////
    sort_by_price->setStyleSheet("font: bold");





     side->setStyleSheet("background-color: #91a0a1");




    search_by_price_meter->setStyleSheet("QToolButton:hover{ background-color: #34495e; color: black;}QToolButton{border:0px;color:white;padding:10px;text-align:center}");
    search_by_perimeter->setStyleSheet("QToolButton:hover{ background-color: #34495e;color: black;}QToolButton{border:0px;color:white;padding:10px;text-align:center}");
    sort_by_price->setStyleSheet("QToolButton:hover{ background-color: #34495e;color: black;}QToolButton{border:0px;color:white;padding:10px;text-align:center}");








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
    connect(search_by_price_meter,SIGNAL(clicked()),this,SLOT(on_btn_search_by_price_meter_clicked()));
    connect(search_by_perimeter,SIGNAL(clicked()),this,SLOT(on_btn_search_by_perimeter_clicked()));
    connect(sort_by_price,SIGNAL(clicked()),this,SLOT(on_btn_sort_by_price_clicked()));
    body->show();
}

void ShowAllBuildings::on_btn_search_by_price_meter_clicked()
{
    QInputDialog in;
    in.setWindowFlag(Qt::FramelessWindowHint);
    in.setStyleSheet("QInputDialog{border:3px solid black}");
    in.setLabelText("Please enter number which you want see buildings with base price less than that number:");
    in.setInputMode(QInputDialog::DoubleInput);
    in.setDoubleMaximum(1000000000000000);
    if(!in.exec())return;
    QInputDialog in2;
    in2.setWindowFlag(Qt::FramelessWindowHint);
    in2.setStyleSheet("QInputDialog{border:3px solid black}");
    in2.setLabelText("Please enter number which you want see buildings with area more than that number:");
    in2.setInputMode(QInputDialog::DoubleInput);
    in2.setIntMaximum(100000000000);
    if(!in2.exec())return;
    if(!allbu.empty()) allbu.clear();
    for(auto i=apartments.begin();i!=apartments.end();i++){
        if(i->second.get_base_price()<in.doubleValue()&&i->second.get_total_area()>in2.doubleValue())allbu.push_back(new ShowBuilding_widget(nullptr,&i->second));
    }
    for(auto i=flats.begin();i!=flats.end();i++){
        for(int j=0;j<i->second.size();j++){
             if(i->second[j].total_price()<in.doubleValue()&&i->second[j].get_building_area()>in2.doubleValue())allbu.push_back(new ShowBuilding_widget(nullptr,&i->second[j]));
        }
    }
    for(auto i=svillas.begin();i!=svillas.end();i++){
        if(i->second.get_base_price()<in.doubleValue()&&i->second.get_total_area()>in2.doubleValue())allbu.push_back(new ShowBuilding_widget(nullptr,&i->second));
    }
    for(auto i=nvillas.begin();i!=nvillas.end();i++){
        if(i->second.get_base_price()<in.doubleValue()&&i->second.get_total_area()>in2.doubleValue())allbu.push_back(new ShowBuilding_widget(nullptr,&i->second));
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
             if(k==allbu.size()){
                 flag=true;
                 break;
             }
            all->addWidget(allbu[k],i,j);
            k++;
        }
        if(flag)break;
    }
}

void ShowAllBuildings::on_btn_search_by_perimeter_clicked()
{
    QInputDialog in;
    in.setWindowFlag(Qt::FramelessWindowHint);
    in.setStyleSheet("QInputDialog{border:3px solid black}");
    in.setLabelText("Please enter address which you want see buildings within that area:");
    in.setInputMode(QInputDialog::TextInput);
    if(!in.exec())return;
    if(!allbu.empty()) allbu.clear();
    for(auto i=apartments.begin();i!=apartments.end();i++){
        if(i->second.get_address().contains(in.textValue()))allbu.push_back(new ShowBuilding_widget(nullptr,&i->second));
    }
    for(auto i=svillas.begin();i!=svillas.end();i++){
       if(i->second.get_address().contains(in.textValue()))allbu.push_back(new ShowBuilding_widget(nullptr,&i->second));
    }
    for(auto i=nvillas.begin();i!=nvillas.end();i++){
        if(i->second.get_address().contains(in.textValue()))allbu.push_back(new ShowBuilding_widget(nullptr,&i->second));
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
             if(k==allbu.size()){
                 flag=true;
                 break;
             }
            all->addWidget(allbu[k],i,j);
            k++;
        }
        if(flag)break;
    }
}

void ShowAllBuildings::on_btn_sort_by_price_clicked()
{
    if(!allbu.empty()) allbu.clear();
    multimap<double,have_file*> temp;
    for(auto i=apartments.begin();i!=apartments.end();i++){
        temp.insert({i->second.get_base_price(),&i->second});
    }
    for(auto i=flats.begin();i!=flats.end();i++){
        for(int j=0;j<i->second.size();j++){
            temp.insert({i->second[j].total_price(),&i->second[j]});
        }
    }
    for(auto i=svillas.begin();i!=svillas.end();i++){
        temp.insert({i->second.get_base_price(),&i->second});
    }
    for(auto i=nvillas.begin();i!=nvillas.end();i++){
       temp.insert({i->second.get_base_price(),&i->second});
    }
    for(auto i=temp.begin();i!=temp.end();i++){
        allbu.push_back(new ShowBuilding_widget(nullptr,i->second));
    }
    for (int i = 0; i < all->count(); ++i)
    {
      QWidget *widget = all->itemAt(i)->widget();
      if (widget != nullptr)
      {
          widget->close();
      }
    }
    auto k=0;
    bool flag=false;
    for(int i=0;;i++){

        for(int j=0;j<3;j++){
             if(k==allbu.size()){
                 flag=true;
                 break;
             }
            all->addWidget(allbu[k],i,j);
            k++;
        }
        if(flag)break;
    }

}
