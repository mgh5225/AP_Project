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
#include<map>
#include<vector>
//map<QString,user> users; //QString -> username
extern QJsonObject users;
map<QString,manager> managers; //QString->username
map<QString,apartment>apartments; //QString->ID
map<QString,south_villa>south_villas;//QString->ID
map<QString,north_villa>north_villas;//QString->ID
map<QString,vector<flat>> flats;//QString->ID_apartmant
map<QString,vector<log>> logs;//QString->ID log ha
////TODO map<QString,vector<flat*>> flats when reading from apartment file                    map<QString,vector<log>> logs when reading from persons
#endif // HEADERS_H
