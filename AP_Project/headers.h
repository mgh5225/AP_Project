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
map<string,user> users; //string -> username
map<string,manager> managers; //string->username
map<string,apartment>apartments; //string->ID
map<string,south_villa>south_villas;//string->ID
map<string,north_villa>north_villas;//string->ID
map<string,vector<flat>> flats;//string->ID_apartmant
map<string,vector<log>> logs;//string->ID log ha
////TODO map<string,vector<flat*>> flats when reading from apartment file                    map<string,vector<log>> logs when reading from persons
#endif // HEADERS_H
