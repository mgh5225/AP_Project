#include <QApplication>
#include <algorithm>
#include <functional>
#include <QFile>
#include "headers.h"
#include<utility>
int main(int argc, char *argv[])
{
    loading();
    QApplication a(argc, argv);
    apartment* aptr=new apartment(8456,5665,"asdaass","C:/Users/Babak/Desktop/unnamed.jpg",12);
    have_file* aptrs[12]={aptr,aptr,aptr,aptr,aptr,aptr,aptr,aptr,aptr,aptr,aptr,aptr};
    //ShowBuilding_widget w(nullptr,aptr);
    for(int i=0;i<20;i++){
        apartments.insert(pair<QString,apartment>(QString::number(i),*aptr));
    }
    flats["0"].push_back(flat(&apartments["0"],12,1,12,50," "));
    flats["0"].push_back(flat(&apartments["0"],12,1,12,200," "));
    flats["1"].push_back(flat(&apartments["1"],12,1,1,200," "));
    user usr;
    User_Panel_UI w(usr);
    //Main_UI w(nullptr,aptrs);
    w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    w.show();
    return a.exec();


}
