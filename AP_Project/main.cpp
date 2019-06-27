#include "ap.h"
#include <QApplication>
#include "headers.h"
#include <QJsonObject>
#include <algorithm>
#include <functional>
bool sign_up_usr(QString _name,tm _birth_date,QString _username,QString _password){
    if(users.contains(_username)==1){
        return 0;
    }
     user u(_name,_birth_date,_username,_password);
     QJsonObject temp;
     u.write(temp);
     users[_username]=temp;
     return 1;
}
bool sign_up_mgr(QString _name,tm _birth_date,QString _username,size_t _password){
    if(managers.count(_username)==1){
        return 0;
    }
    manager m(_name,_birth_date,_username,_password);
     managers[m.get_id()]=m;
     return 1;
}
user login_usr(QString _username,QString _password){
    hash<string> ph;
    if(users[_username]!= QJsonValue::Undefined){
        user temp;
        QJsonObject temp2=users[_username].toObject();
        temp.read(temp2);
        if(temp.get_pass()==ph(_password.toStdString()))return temp;
        else throw personEX(PEX::BADPASSWORD);
    }
    else{
        throw personEX(PEX::BADUSERNAME);
    }
    else throw personEX;
}
manager& login_mgr(QString _username,size_t _password){
    if(managers.at(_username).get_pass()==_password)return managers[_username];
    else throw personEX;
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AP w;
    time_t now;
    time(&now);
    struct tm *t=localtime(&now);
    sign_up_usr("Arian",*t,"arianpotter",1234);

    w.show();

    return a.exec();
}
