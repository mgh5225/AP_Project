#include "ap.h"
#include <QApplication>
#include <algorithm>
#include <functional>
#include <QFile>
#include "headers.h"

int main(int argc, char *argv[])
{
    loading();
    QApplication a(argc, argv);
    apartment* aptr=new apartment(8456,5665,"asdaass","C:/Users/Babak/Desktop/unnamed.jpg",12);
    //ShowBuilding_widget w(nullptr,aptr);
    have_file* aptrs[12]={aptr,aptr,aptr,aptr,aptr,aptr,aptr,aptr,aptr,aptr,aptr,aptr};
    Main_UI w(nullptr,aptrs);
    w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    w.show();
    return a.exec();


}
