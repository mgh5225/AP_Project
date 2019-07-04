#include"have_file.h"
have_file::have_file(){
    time_t now;
    time(&now);
    struct tm *t=localtime(&now);
    string temp=to_string(t->tm_year)+to_string(t->tm_mon)+to_string(t->tm_mday)+to_string(t->tm_hour)+to_string(t->tm_min)+to_string(t->tm_sec);
    ID=QString::fromStdString(temp);
}
have_file::~have_file(){}
QString have_file::get_id(){return ID;}
