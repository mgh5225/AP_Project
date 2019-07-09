#include "requests_ui.h"
#include "headers.h"
#include <QTextStream>
Requests_Ui::Requests_Ui(manager& mgr,QWidget *parent) :mgr(mgr), QWidget(parent)
{



    listWidget_all = new QListWidget;
    QString temp;
    for(auto i=sales.begin();i!=sales.end();i++){
        if(i->second.get_user_ID()!=""&&i->second.get_is_accpted()==false&&i->second.get_manager_ID()==mgr.get_id()){
        temp="";
        temp+=i->second.get_building_ID()+" : ";
        temp+=i->second.get_user_ID();
        temp+=" Buy ";
        north_villa* nv=dynamic_cast<north_villa*>(i->second.get_building());
        south_villa* sv=dynamic_cast<south_villa*>(i->second.get_building());
        flat* fl=dynamic_cast<flat*>(i->second.get_building());
        if(nv)temp+=nv->get_address();
        if(sv)temp+=sv->get_address();
        if(fl)temp+=fl->get_current_apartment()->get_address()+QString::number(fl->get_unit());
        listWidget_all->addItem(temp);
    }
    }
    for(auto i=rents.begin();i!=rents.end();i++){
         if(i->second.get_user_ID()!=""&&i->second.get_is_accpted()==false&&i->second.get_manager_ID()==mgr.get_id()){
        temp="";
        temp+=i->second.get_building_ID()+" : ";
        temp+=i->second.get_user_ID();
        temp+=" Rent ";
        north_villa* nv=dynamic_cast<north_villa*>(i->second.get_building());
        south_villa* sv=dynamic_cast<south_villa*>(i->second.get_building());
        flat* fl=dynamic_cast<flat*>(i->second.get_building());
        if(nv)temp+=nv->get_address();
        if(sv)temp+=sv->get_address();
        if(fl)temp+=fl->get_current_apartment()->get_address()+QString::number(fl->get_unit());
        listWidget_all->addItem(temp);
         }
    }
    btn_deny = new QPushButton(tr("Deny"));
    btn_Accept = new QPushButton(tr("Accept"));

    widget_Request = new QWidget();
    widget_Request->setFixedWidth(700);
    lbl_Request = new QLabel(tr("Accept or Deny the Request!"));

    layout_all = new QVBoxLayout;
    layout_all->addWidget(listWidget_all);
    //layout_all->addWidget(widget_Request);

    layout_widget_H_Btn = new QHBoxLayout();

    layout_widget_H_Btn->addWidget(btn_Accept);
    layout_widget_H_Btn->addWidget(btn_deny);

    layout_widget_V = new QVBoxLayout();
    layout_widget_V->addWidget(lbl_Request);
    layout_widget_V->addLayout(layout_widget_H_Btn);
    widget_Request->hide();

    widget_Request->setLayout(layout_widget_V);
    widget_Request->setWindowFlags(Qt::FramelessWindowHint);
    this->setLayout(layout_all);
    connect(listWidget_all,SIGNAL(itemDoubleClicked(QListWidgetItem *)),this,SLOT(ListWidgetDoubleClicked(QListWidgetItem *)));
    connect(btn_Accept,SIGNAL(clicked()),this,SLOT(AccClicked()));
    connect(btn_deny,SIGNAL(clicked()),this,SLOT(DenClicked()));

    btn_Accept->setStyleSheet("QPushButton:pressed {background-color: #00cc00;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif} QPushButton{ background-color:#b3ffb3;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif}");
    btn_deny->setStyleSheet("QPushButton:pressed {background-color:#ff1a1a;color:#b30000;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif } QPushButton{ background-color:#ffb3b3;color:#b30000;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif }");
}

void Requests_Ui::ListWidgetDoubleClicked(QListWidgetItem *item)
{
    widget_Request->adjustSize();
    widget_Request->move(QApplication::desktop()->screen()->rect().center()
                         - widget_Request->rect().center());
    which=new QString;
    *which=item->text();
    QTextStream s(which);
    QString temp;
    s>>temp;
    *which=temp;


    widget_Request->show();
}

void Requests_Ui::AccClicked()
{
    try {
        sales.at(*which).set_is_accpted(true);
        QJsonObject j;
        sales.at(*which).write(j);
        salesjson[*which]=j;
        try{
            users.at(sales[*which].get_user_ID()).set_balance(users.at(sales[*which].get_user_ID()).get_balance()-sales[*which].final_price());
            QJsonObject temp;
            users[sales[*which].get_user_ID()].write(temp);
            usersjson[sales[*which].get_user_ID()]=temp;
        }catch(out_of_range){
            managers.at(sales[*which].get_user_ID()).set_balance(managers.at(sales[*which].get_user_ID()).get_balance()-sales[*which].final_price());
            QJsonObject temp;
            managers[sales[*which].get_user_ID()].write(temp);
            managersjson[sales[*which].get_user_ID()]=temp;
        }

    } catch (out_of_range) {
        rents.at(*which).set_is_accpted(true);
        QJsonObject j;
        rents.at(*which).write(j);
        rentsjson[*which]=j;
        try{
            users.at(rents[*which].get_user_ID()).set_balance(users.at(rents[*which].get_user_ID()).get_balance()-rents[*which].final_price());
            QJsonObject temp;
            users[rents[*which].get_user_ID()].write(temp);
            usersjson[rents[*which].get_user_ID()]=temp;
        }
        catch(out_of_range){
            managers.at(rents[*which].get_user_ID()).set_balance(managers.at(rents[*which].get_user_ID()).get_balance()-rents[*which].final_price());
            QJsonObject temp;
            managers[rents[*which].get_user_ID()].write(temp);
            managersjson[rents[*which].get_user_ID()]=temp;
        }
    }
    widget_Request->close();
    listWidget_all->clear();
    QString temp;
    for(auto i=sales.begin();i!=sales.end();i++){
        if(i->second.get_user_ID()!=""&&i->second.get_is_accpted()==false&&i->second.get_manager_ID()==mgr.get_id()){
        temp="";
        temp+=i->second.get_building_ID()+" : ";
        temp+=i->second.get_user_ID();
        temp+=" Buy ";
        north_villa* nv=dynamic_cast<north_villa*>(i->second.get_building());
        south_villa* sv=dynamic_cast<south_villa*>(i->second.get_building());
        flat* fl=dynamic_cast<flat*>(i->second.get_building());
        if(nv)temp+=nv->get_address();
        if(sv)temp+=sv->get_address();
        if(fl)temp+=fl->get_current_apartment()->get_address()+QString::number(fl->get_unit());
        listWidget_all->addItem(temp);
    }
    }
    for(auto i=rents.begin();i!=rents.end();i++){
         if(i->second.get_user_ID()!=""&&i->second.get_is_accpted()==false&&i->second.get_manager_ID()==mgr.get_id()){
        temp="";
        temp+=i->second.get_building_ID()+" : ";
        temp+=i->second.get_user_ID();
        temp+=" Rent ";
        north_villa* nv=dynamic_cast<north_villa*>(i->second.get_building());
        south_villa* sv=dynamic_cast<south_villa*>(i->second.get_building());
        flat* fl=dynamic_cast<flat*>(i->second.get_building());
        if(nv)temp+=nv->get_address();
        if(sv)temp+=sv->get_address();
        if(fl)temp+=fl->get_current_apartment()->get_address()+QString::number(fl->get_unit());
        listWidget_all->addItem(temp);
         }
    }
}

void Requests_Ui::DenClicked()
{
    try {
        sales.at(*which).set_is_accpted(false);
        try{
            users.at(sales[*which].get_user_ID()).set_balance(users.at(sales[*which].get_user_ID()).get_balance()-sales[*which].final_price());
            QJsonObject temp;
            users[sales[*which].get_user_ID()].write(temp);
            usersjson[sales[*which].get_user_ID()]=temp;
        }
        catch(out_of_range){
            managers.at(sales[*which].get_user_ID()).set_balance(managers.at(sales[*which].get_user_ID()).get_balance()-sales[*which].final_price());
            QJsonObject temp;
            managers[sales[*which].get_user_ID()].write(temp);
            managersjson[sales[*which].get_user_ID()]=temp;
        }
        sales.at(*which).set_user_ID("");
        QJsonObject j;
        sales.at(*which).write(j);
        salesjson[*which]=j;

    } catch (out_of_range) {
        rents.at(*which).set_is_accpted(false);
        try{
            users.at(rents[*which].get_user_ID()).set_balance(users.at(rents[*which].get_user_ID()).get_balance()-rents[*which].final_price());
            QJsonObject temp;
            users[rents[*which].get_user_ID()].write(temp);
            usersjson[rents[*which].get_user_ID()]=temp;
        }
        catch(out_of_range){
            managers.at(rents[*which].get_user_ID()).set_balance(managers.at(rents[*which].get_user_ID()).get_balance()-rents[*which].final_price());
            QJsonObject temp;
            managers[rents[*which].get_user_ID()].write(temp);
            managersjson[rents[*which].get_user_ID()]=temp;
        }
        rents.at(*which).set_user_ID("");
        QJsonObject j;
        rents.at(*which).write(j);
        rentsjson[*which]=j;
    }
    widget_Request->close();
    listWidget_all->clear();
    QString temp;
    for(auto i=sales.begin();i!=sales.end();i++){
        if(i->second.get_user_ID()!=""&&i->second.get_is_accpted()==false&&i->second.get_manager_ID()==mgr.get_id()){
        temp="";
        temp+=i->second.get_building_ID()+" : ";
        temp+=i->second.get_user_ID();
        temp+=" Buy ";
        north_villa* nv=dynamic_cast<north_villa*>(i->second.get_building());
        south_villa* sv=dynamic_cast<south_villa*>(i->second.get_building());
        flat* fl=dynamic_cast<flat*>(i->second.get_building());
        if(nv)temp+=nv->get_address();
        if(sv)temp+=sv->get_address();
        if(fl)temp+=fl->get_current_apartment()->get_address()+QString::number(fl->get_unit());
        listWidget_all->addItem(temp);
    }
    }
    for(auto i=rents.begin();i!=rents.end();i++){
         if(i->second.get_user_ID()!=""&&i->second.get_is_accpted()==false&&i->second.get_manager_ID()==mgr.get_id()){
        temp="";
        temp+=i->second.get_building_ID()+" : ";
        temp+=i->second.get_user_ID();
        temp+=" Rent ";
        north_villa* nv=dynamic_cast<north_villa*>(i->second.get_building());
        south_villa* sv=dynamic_cast<south_villa*>(i->second.get_building());
        flat* fl=dynamic_cast<flat*>(i->second.get_building());
        if(nv)temp+=nv->get_address();
        if(sv)temp+=sv->get_address();
        if(fl)temp+=fl->get_current_apartment()->get_address()+QString::number(fl->get_unit());
        listWidget_all->addItem(temp);
         }
    }
}
