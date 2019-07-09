#include "shownorthvillas.h"
#include "headers.h"
ShowNorthVillas::ShowNorthVillas(person* _p,QWidget *parent) : QWidget(nullptr)
{
    p=_p;
    this->parent=parent;
    all=new QGridLayout;
    scr=new QScrollArea(parent);
    for(auto i=nvillas.begin();i!=nvillas.end();i++){
        aptrs.push_back(new ShowBuilding_widget(p,parent,&i->second));
    }
    int k=0;
    bool flag=false;
    for(int i=0;;i++){

        for(int j=0;j<4;j++){
             if(k==aptrs.size()){
                 flag=true;
                 break;
             }
            all->addWidget(aptrs[k],i,j);
            k++;
        }
        if(flag==true)break;
    }
    all->setAlignment(Qt::AlignCenter);

    scr->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    temp=new QWidget;
    temp->setLayout(all);
    scr->setWidget(temp);

    QSize availableSize = qApp->desktop()->availableGeometry().size();
        int width = availableSize.width();
        int height = availableSize.height();
        //qDebug() << "Available dimensions " << width << "x" << height;
       width *= 0.73; // 90% of the screen size
        height *= 0.8; // 90% of the screen size
        //qDebug() << "Computed dimensions " << width << "x" << height;
        QSize newSize( width, height);

        scr->setGeometry(
            QStyle::alignedRect(
                Qt::LeftToRight,
                Qt::AlignCenter,
                newSize,
                qApp->desktop()->availableGeometry()
            )
        );
        scr->setAttribute(Qt::WA_TranslucentBackground, true);
        scr->setWindowFlags(Qt::FramelessWindowHint);
        scr->setFixedSize(width-128,height-95);
        scr->move(138,95);
        scr->show();

}
