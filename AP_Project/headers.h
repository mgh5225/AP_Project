#ifndef HEADERS_H
#define HEADERS_H
#include<QTextStream>
#include<QMessageBox>
#include<QJsonDocument>
#include <QJsonObject>
#include "have_file.h"
#include "building.h"
#include "apartment.h"
#include "villa.h"
#include "north_villa.h"
#include "south_villa.h"
#include "person.h"
#include "user.h"
#include "manager.h"
#include "file.h"
#include "sale_file.h"
#include "rent_file.h"
#include"main_ui.h"
#include<map>
//map<QString,user> users; //QString -> username
static QJsonObject usersjson;
static QJsonObject managersjson;
static QJsonObject apartmentsjson;
static QJsonObject svillasjson;
static QJsonObject nvillasjson;
static QJsonObject flatsjson;
static QJsonObject logsjson;
static QJsonObject rentsjson;
static QJsonObject salesjson;
static map<QString,user> users;
static map<QString,manager> managers; //QString->username
static map<QString,apartment>apartments; //QString->ID
static map<QString,south_villa>svillas;//QString->ID
static map<QString,north_villa>nvillas;//QString->ID
static map<QString,vector<flat>> flats;//QString->ID_apartmant
static map<QString,vector<log>> logs;//QString->ID log ha
static map<QString,rent_file> rents;
static map<QString,sale_file> sales;
static void unloading(){
    QFile saveuser(QStringLiteral("users.json"));
    saveuser.open(QIODevice::WriteOnly);
    QJsonDocument savedocuser(usersjson);
    saveuser.write(savedocuser.toJson());

    QFile savemanager(QStringLiteral("managers.json"));
    savemanager.open(QIODevice::WriteOnly);
    QJsonDocument savedocmanager(managersjson);
    savemanager.write(savedocmanager.toJson());

    QFile saveapartment(QStringLiteral("apartments.json"));
    saveapartment.open(QIODevice::WriteOnly);
    QJsonDocument savedocapartment(apartmentsjson);
    saveapartment.write(savedocapartment.toJson());

    QFile savesvilla(QStringLiteral("svillas.json"));
    savesvilla.open(QIODevice::WriteOnly);
    QJsonDocument savedocsvilla(svillasjson);
    savesvilla.write(savedocsvilla.toJson());

    QFile savenvilla(QStringLiteral("nvillas.json"));
    savenvilla.open(QIODevice::WriteOnly);
    QJsonDocument savedocnvilla(nvillasjson);
    savenvilla.write(savedocnvilla.toJson());

    QFile saveflat(QStringLiteral("flats.json"));
    saveflat.open(QIODevice::WriteOnly);
    QJsonDocument savedocflat(flatsjson);
    saveflat.write(savedocflat.toJson());

    QFile savelog(QStringLiteral("logs.json"));
    savelog.open(QIODevice::WriteOnly);
    QJsonDocument savedoclog(logsjson);
    savelog.write(savedoclog.toJson());

    QFile saverent(QStringLiteral("rents.json"));
    saverent.open(QIODevice::WriteOnly);
    QJsonDocument savedocrent(rentsjson);
    saverent.write(savedocrent.toJson());

    QFile savesale(QStringLiteral("sales.json"));
    savesale.open(QIODevice::WriteOnly);
    QJsonDocument savedocsale(salesjson);
    savesale.write(savedocsale.toJson());

    saveuser.close();
    savemanager.close();
    saveapartment.close();
    savesvilla.close();
    savenvilla.close();
    saveflat.close();
    savelog.close();
    saverent.close();
    savesale.close();


}
static void loading(){
    QFile loaduser(QStringLiteral("users.json"));
    loaduser.open(QIODevice::ReadOnly);
    QByteArray userdata=loaduser.readAll();
    QJsonDocument userdoc(QJsonDocument::fromJson(userdata));
    user u;
    QJsonObject temp;
    usersjson=userdoc.object();
    for (auto i=usersjson.begin();i!=usersjson.end();i++) {
       temp=i.value().toObject();
       u.read(temp);
       users[u.get_user()]=u;
    }

    QFile loadmanager(QStringLiteral("managers.json"));
    loadmanager.open(QIODevice::ReadOnly);
    QByteArray managerdata=loadmanager.readAll();
    QJsonDocument managerdoc(QJsonDocument::fromJson(managerdata));
    manager m;
    managersjson=managerdoc.object();
    for (auto i=managersjson.begin();i!=managersjson.end();i++) {
       temp=i.value().toObject();
       m.read(temp);
       managers[m.get_user()]=m;
    }

    QFile loadapartment(QStringLiteral("apartments.json"));
    loadapartment.open(QIODevice::ReadOnly);
    QByteArray apartmentdata=loadapartment.readAll();
    QJsonDocument apartmentdoc(QJsonDocument::fromJson(apartmentdata));
    apartment a;
    apartmentsjson=apartmentdoc.object();
    for (auto i=apartmentsjson.begin();i!=apartmentsjson.end();i++) {
       temp=i.value().toObject();
       a.read(temp);
       apartments[a.get_id()]=a;
    }

    QFile loadsvilla(QStringLiteral("svillas.json"));
    loadsvilla.open(QIODevice::ReadOnly);
    QByteArray svilladata=loadsvilla.readAll();
    QJsonDocument svilladoc(QJsonDocument::fromJson(svilladata));
    south_villa sv;
    svillasjson=svilladoc.object();
    for (auto i=svillasjson.begin();i!=svillasjson.end();i++) {
       temp=i.value().toObject();
       sv.read(temp);
       svillas[sv.get_id()]=sv;
    }

    QFile loadnvilla(QStringLiteral("nvillas.json"));
    loadnvilla.open(QIODevice::ReadOnly);
    QByteArray nvilladata=loadnvilla.readAll();
    QJsonDocument nvilladoc(QJsonDocument::fromJson(nvilladata));
    north_villa nv;
    nvillasjson=nvilladoc.object();
    for (auto i=nvillasjson.begin();i!=nvillasjson.end();i++) {
       temp=i.value().toObject();
       nv.read(temp);
       nvillas[nv.get_id()]=nv;
    }

    QFile loadflat(QStringLiteral("flats.json"));
    loadflat.open(QIODevice::ReadOnly);
    QByteArray flatdata=loadflat.readAll();
    QJsonDocument flatdoc(QJsonDocument::fromJson(flatdata));
    flat f;
    flatsjson=flatdoc.object();
    for (auto i=flatsjson.begin();i!=flatsjson.end();i++) {
       temp=i.value().toObject();
       f.read(temp);
       flats[f.get_current_apartment_ID()].push_back(f);
    }

    QFile loadlog(QStringLiteral("logs.json"));
    loadlog.open(QIODevice::ReadOnly);
    QByteArray logdata=loadlog.readAll();
    QJsonDocument logdoc(QJsonDocument::fromJson(logdata));
    log l;
    logsjson=logdoc.object();
    for (auto i=logsjson.begin();i!=logsjson.end();i++) {
       temp=i.value().toObject();
       l.read(temp);
       logs[l.get_person_ID()].push_back(l);
    }

    QFile loadrent(QStringLiteral("rents.json"));
    loadrent.open(QIODevice::ReadOnly);
    QByteArray rentdata=loadrent.readAll();
    QJsonDocument rentdoc(QJsonDocument::fromJson(rentdata));
    rent_file r;
    rentsjson=rentdoc.object();
    for (auto i=rentsjson.begin();i!=rentsjson.end();i++) {
       temp=i.value().toObject();
       r.read(temp);
       rents[r.get_building_ID()]=r;
    }

    QFile loadsale(QStringLiteral("sales.json"));
    loadsale.open(QIODevice::ReadOnly);
    QByteArray saledata=loadsale.readAll();
    QJsonDocument saledoc(QJsonDocument::fromJson(saledata));
    sale_file s;
    salesjson=saledoc.object();
    for (auto i=salesjson.begin();i!=salesjson.end();i++) {
       temp=i.value().toObject();
       s.read(temp);
       sales[s.get_building_ID()]=s;
    }

    loaduser.close();
    loadmanager.close();
    loadapartment.close();
    loadsvilla.close();
    loadnvilla.close();
    loadflat.close();
    loadlog.close();
    loadrent.close();
    loadsale.close();
}
void Main_UI::on_btn_exit_clicked()
{
    unloading();
    close();
}
void User_Panel_UI::on_btn_exit_clicked(){
    unloading();
    close();
}
static bool sign_up_usr(QString _name,tm _birth_date,QString _username,QString _password){
    if(users.count(_username)==1){
        return 0;
    }
     user u(_name,_birth_date,_username,_password);
     users[_username]=u;
     QJsonObject temp;
     u.write(temp);
     usersjson[_username]=temp;
     return 1;
}
static bool sign_up_mgr(QString _name,tm _birth_date,QString _username,QString _password){
    if(managers.count(_username)==1){
        return 0;
    }
     manager m(_name,_birth_date,_username,_password);
     managers[_username]=m;
     QJsonObject temp;
     m.write(temp);
     managersjson[_username]=temp;
     return 1;
}
static user& login_usr(QString _username,QString _password){
    hash<string> ph;
    personException personEX;
    if(users.count(_username)==1){
        if(users[_username].get_pass()==ph(_password.toStdString()))return users[_username];
        else throw personEX(PEX::BADPASSWORD);
    }
    else{
        throw personEX(PEX::BADUSERNAME);
    }
}
static manager& login_mgr(QString _username,QString _password){
    hash<string> ph;
    personException personEX;
    if(managers.count(_username)==1){
        if(managers[_username].get_pass()==ph(_password.toStdString()))return managers[_username];
        else throw personEX(PEX::BADPASSWORD);
    }
    else{
        throw personEX(PEX::BADUSERNAME);
    }
}
void Register_UI::on_btn_register_clicked()
{
    bool isUser=radioUser->isChecked();
    bool isRegistered;
    QString date=dateEditBirthday->text();
    date.replace("/"," ");
    QTextStream stream(&date);
    tm t;
    QString year;
    QString month;
    QString day;
    stream>>month>>day>>year;
    t.tm_year=year.toInt();
    t.tm_mon=month.toInt();
    t.tm_mday=day.toInt();
    if(isUser){
        isRegistered=sign_up_usr(lineEditFullName->text(),t,lineEditUsername->text(),lineEditPassword->text());
    }else{
        isRegistered=sign_up_mgr(lineEditFullName->text(),t,lineEditUsername->text(),lineEditPassword->text());
    }
    if(isRegistered){
        QMessageBox msg;
        msg.setText("Registered!");
        msg.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        msg.exec();
        this->close();
        parent->show();
    }else{
        QMessageBox msg;
        msg.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        msg.setText("Username already exists!");
        msg.exec();
    }
}
void Login::on_btn_login_clicked()
{
    bool isUser=radioUser->isChecked();
    if(isUser){
        try{
            user& usr=login_usr(lineEditUsername->text(),lineEditPassword->text());
            User_Panel_UI* u=new User_Panel_UI(usr,parent);
            this->hide();
            u->show();
        }catch(personException ex){
            switch (ex.type) {
            case PEX::BADUSERNAME:{
                QMessageBox msg;
                msg.setText("Username or Password is wrong!");
                msg.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
                msg.exec();
                break;
            }
            case PEX::BADPASSWORD:{
                QMessageBox msg;
                msg.setText("Username or Password is wrong!");
                msg.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
                msg.exec();
                break;
            }
        }
    }
}
}
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
        height *= 0.9; // 90% of the screen size
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
        scr->setFixedSize(scr->width(),height);
         body->setFixedSize(width-128,scr->height());
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
    in.setLabelText("Please enter number which you want see apartments more rooms from that number:");
    in.setInputMode(QInputDialog::IntInput);
    in.exec();
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
    in.setLabelText("Please enter number which you want see apartments with rooms more than that number:");
    in.setInputMode(QInputDialog::IntInput);
    in.exec();
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
    in.setLabelText("Please enter number which you want see apartments with rooms more than that number:");
    in.setInputMode(QInputDialog::IntInput);
    in.exec();
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
////TODO map<QString,vector<flat*>> flats when reading from apartment file                    map<QString,vector<log>> logs when reading from persons
#endif // HEADERS_H
