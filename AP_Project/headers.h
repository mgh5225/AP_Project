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

extern vector<user*> users;
extern vector<manager*> managers;
extern vector<apartment*>apartments;
extern vector<south_villa*>south_villas;
extern vector<north_villa*>north_villas;
////TODO map<string,vector<flat*>> flats when reading from apartment file                    map<string,vector<log>> logs when reading from persons
#endif // HEADERS_H
