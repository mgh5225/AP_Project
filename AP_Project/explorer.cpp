#include "explorer.h"
explorer::explorer(QWidget *parent) : QWidget(nullptr)
{
    this->parent=parent;
    btn_ShowFlats = new QToolButton();
    btn_ShowApartments = new QToolButton();
    btn_ShowNorthVillas = new QToolButton();
    btn_ShowSouthVillas = new QToolButton();
    btn_ShowAllBuildings = new QToolButton();
    btn_ShowApartments->setText(tr("Show Apartments"));
    btn_ShowNorthVillas->setText(tr("Show North Villa"));
    btn_ShowFlats->setText(tr("Show Flats"));
    btn_ShowSouthVillas->setText(tr("Show South Villa"));
    btn_ShowAllBuildings->setText("Show All buildings");

    btn_ShowFlats->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );
    btn_ShowApartments->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );
    btn_ShowNorthVillas->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );
    btn_ShowSouthVillas->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );
    btn_ShowAllBuildings->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Minimum );


   btn_ShowApartments ->setStyleSheet("QToolButton:hover{ background-color: #91a0a1; color: wihte;}QToolButton{border:0px;background-color: #34495e;color:white;padding:40px ;text-align:center;}");
   btn_ShowNorthVillas ->setStyleSheet("QToolButton:hover{ background-color: #91a0a1; color: wihte;}QToolButton{border:0px;background-color: #34495e;color:white;padding:40px ;text-align:center;}");
   btn_ShowSouthVillas ->setStyleSheet("QToolButton:hover{ background-color: #91a0a1; color: wihte;}QToolButton{border:0px;background-color: #34495e;color:white;padding:40px ;text-align:center;}");
   btn_ShowFlats->setStyleSheet("QToolButton:hover{ background-color: #91a0a1; color: wihte;}QToolButton{border:0px;background-color: #34495e;color:white;padding:40px ;text-align:center;}");
   btn_ShowAllBuildings->setStyleSheet("QToolButton:hover{ background-color: #91a0a1; color: wihte;}QToolButton{border:0px;background-color: #34495e;color:white;padding:40px ;text-align:center;}");


    my_grid_Layout = new QGridLayout();

    my_grid_Layout->addWidget(btn_ShowApartments,0,0);

    my_grid_Layout->addWidget(btn_ShowNorthVillas,1,0);
    my_grid_Layout->addWidget(btn_ShowFlats,0,1);
    my_grid_Layout->addWidget(btn_ShowSouthVillas,1,1);
    my_grid_Layout->addWidget(btn_ShowAllBuildings,2,0,1,2,Qt::AlignVCenter);


    QFrame *myFrame = new QFrame();
    myFrame->setLayout(my_grid_Layout);
    myFrame->setStyleSheet("background-color:#e3e7e8;border-radius: 5px;");


    ////////////////////////////////////////
    //set frame

    QHBoxLayout *temp = new QHBoxLayout;
    temp->addWidget(myFrame);
    /////////////////////////////////////
    // round window!!
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    ////////////////////////////////////


    this->setLayout(temp);
    connect(btn_ShowApartments,SIGNAL(clicked()),this,SLOT(show_aptrs()));

}
void explorer::show_aptrs()
{
    aptrs=new ShowApartments(parent);
    btn_ShowApartments->hide();
    btn_ShowFlats->hide();
    btn_ShowNorthVillas->hide();
    btn_ShowSouthVillas->hide();
    btn_ShowAllBuildings->hide();
    my_grid_Layout->addWidget(aptrs,1,1);
}
