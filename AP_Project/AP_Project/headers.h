#ifndef HEADERS_H
#define HEADERS_H
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
QJsonObject usersjson;
QJsonObject managersjson;
QJsonObject apartmentsjson;
QJsonObject svillasjson;
QJsonObject nvillasjson;
QJsonObject flatsjson;
QJsonObject logsjson;
QJsonObject rentsjson;
QJsonObject salesjson;
map<QString,user> users;
map<QString,manager> managers; //QString->username
map<QString,apartment>apartments; //QString->ID
map<QString,south_villa>svillas;//QString->ID
map<QString,north_villa>nvillas;//QString->ID
map<QString,vector<flat>> flats;//QString->ID_apartmant
map<QString,vector<log>> logs;//QString->ID log ha
map<QString,rent_file> rents;
map<QString,sale_file> sales;
////TODO map<QString,vector<flat*>> flats when reading from apartment file                    map<QString,vector<log>> logs when reading from persons
#endif // HEADERS_H
