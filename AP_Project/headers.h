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
extern QJsonObject usersjson;
extern QJsonObject managersjson;
extern QJsonObject apartmentsjson;
extern QJsonObject svillasjson;
extern QJsonObject nvillasjson;
extern QJsonObject flatsjson;
extern QJsonObject logsjson;
extern QJsonObject rentsjson;
extern QJsonObject salesjson;
extern map<QString,user> users;
extern map<QString,manager> managers; //QString->username
extern map<QString,apartment>apartments; //QString->ID
extern map<QString,south_villa>svillas;//QString->ID
extern map<QString,north_villa>nvillas;//QString->ID
extern map<QString,vector<flat>> flats;//QString->ID_apartmant
extern map<QString,vector<log>> logs;//QString->ID log ha
extern map<QString,rent_file> rents;
extern map<QString,sale_file> sales;
void unloading();
void loading();
bool sign_up_usr(QString _name,tm _birth_date,QString _username,QString _password);
bool sign_up_mgr(QString _name,tm _birth_date,QString _username,QString _password);
user& login_usr(QString _username,QString _password);
manager& login_mgr(QString _username,QString _password);



////TODO map<QString,vector<flat*>> flats when reading from apartment file                    map<QString,vector<log>> logs when reading from persons
#endif // HEADERS_H
