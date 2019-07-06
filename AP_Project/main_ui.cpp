#include "main_ui.h"
#include <QPainter>
#include <QScrollArea>
#include<exception>
#include "headers.h"
void Main_UI::on_btn_log_in_clicked()
{
    this->hide();
    Login *l=new Login(this);
    l->show();
}

void Main_UI::on_btn_sign_up_clicked()
{
    try{
    this->hide();
    Register_UI *r=new Register_UI(this);
    r->show();
    }catch(exception ex){

    }
}



Main_UI::Main_UI(QWidget *parent,have_file* files[12]) : QMainWindow(parent)
{
    btn_exit = new QToolButton();
    btn_log_in = new QToolButton();
    btn_sign_up = new QToolButton();
    btn_exit->setMinimumSize(75,75);
    btn_log_in->setMinimumSize(75,75);
    btn_sign_up->setMinimumSize(75,75);



    QPixmap pixmap(":/icons/resource/icons/User_Login.png");
    QIcon btn_log_in_Icon(pixmap);

    btn_log_in->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btn_log_in->setIcon(btn_log_in_Icon);
    btn_log_in->setIconSize(QSize(30, 30));
    btn_log_in->setText("Log In");


    QPixmap pixmap2(":/icons/resource/icons/Black_Exit_Icon.png");
    QIcon btn_exit_Icon(pixmap2);

    btn_exit->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btn_exit->setIcon(btn_exit_Icon);
    btn_exit->setIconSize(QSize(30, 30));
    btn_exit->setText("Exit");

    QPixmap pixmap3(":/icons/resource/icons/Sign_Up_Icon.png");
    QIcon btn_sign_up_Icon(pixmap3);

    btn_sign_up->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btn_sign_up->setIcon(btn_sign_up_Icon);
    btn_sign_up->setIconSize(QSize(30, 30));
    btn_sign_up->setText("Sign up");


    obj_1=new ShowBuilding_widget(nullptr,files[0]);
    obj_2=new ShowBuilding_widget(nullptr,files[1]);
    obj_3=new ShowBuilding_widget(nullptr,files[2]);
    obj_4=new ShowBuilding_widget(nullptr,files[3]);
    obj_5=new ShowBuilding_widget(nullptr,files[4]);
    obj_6=new ShowBuilding_widget(nullptr,files[5]);
    obj_7=new ShowBuilding_widget(nullptr,files[6]);
    obj_8=new ShowBuilding_widget(nullptr,files[7]);
    obj_9=new ShowBuilding_widget(nullptr,files[8]);
    obj_10=new ShowBuilding_widget(nullptr,files[9]);
    obj_11=new ShowBuilding_widget(nullptr,files[10]);
    obj_12=new ShowBuilding_widget(nullptr,files[11]);



    toolbar = new QHBoxLayout();

    my_grid_layout = new QGridLayout();


    toolbar->addWidget(btn_log_in,0,Qt::AlignLeft);
    toolbar->addWidget(btn_sign_up,1,Qt::AlignLeft);
    toolbar->addWidget(btn_exit,0,Qt::AlignRight);



     my_grid_layout->addWidget(obj_1,0,0);
     my_grid_layout->addWidget(obj_2,0,1);
     my_grid_layout->addWidget(obj_3,0,2);
     my_grid_layout->addWidget(obj_4,0,3);
     my_grid_layout->addWidget(obj_5,1,0);
     my_grid_layout->addWidget(obj_6,1,1);
     my_grid_layout->addWidget(obj_7,1,2);
     my_grid_layout->addWidget(obj_8,1,3);
     my_grid_layout->addWidget(obj_9,2,0);
     my_grid_layout->addWidget(obj_10,2,1);
     my_grid_layout->addWidget(obj_11,2,2);
     my_grid_layout->addWidget(obj_12,2,3);
     my_grid_layout->setAlignment(Qt::AlignCenter);
     /*
     obj_1->animation= new QPropertyAnimation(obj_1, "geometry");
     obj_1->animation->setDuration(1000);
     obj_1->animation->setStartValue(QRect(0, 0, 200, 200));
     obj_1->animation->setEndValue(QRect(103, 110, 260, 260));
     obj_1->animation->start();
     obj_2->animation= new QPropertyAnimation(obj_2, "geometry");
     obj_2->animation->setDuration(1000);
     obj_2->animation->setStartValue(QRect(0, 0, 200, 200));
     obj_2->animation->setEndValue(QRect(380, 110, 260, 260));
     obj_2->animation->start();

    */
    ////////////////////////////////////////
     body=new QVBoxLayout;
     body->addLayout(toolbar);
     body->addLayout(my_grid_layout);
    QWidget *widget = new QWidget();
    this->setCentralWidget(widget);
    widget->setLayout(body);

    //this->centralWidget()->setStyleSheet("background-image:url(:/Images/resource/imgs/background.jpg); background-position: center;background-repeat:no-repeat;background-size:cover ");
    //w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        /////////////////

        //set the size of windows!its need to change!
        QSize availableSize = qApp->desktop()->availableGeometry().size();
            int width = availableSize.width();
            int height = availableSize.height();
            //qDebug() << "Available dimensions " << width << "x" << height;
            width *= 0.73; // 90% of the screen size
            height *= 0.9; // 90% of the screen size
            //qDebug() << "Computed dimensions " << width << "x" << height;
            QSize newSize( width, height );
            this->move(width/2,height/2);
            my_grid_layout->setSizeConstraint(QLayout::SetMinimumSize);
            this->setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    newSize,
                    qApp->desktop()->availableGeometry()
                )
            );
            QPixmap bkgnd(":/Images/resource/imgs/background.jpg");
                bkgnd = bkgnd.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
               // bkgnd.fill(Qt::transparent);
               // bkgnd=bkgnd.scaledToHeight(this->size().height(),Qt::SmoothTransformation);
                //bkgnd=bkgnd.scaledToWidth(this->size().width(),Qt::SmoothTransformation);
                QPalette palette;
                palette.setBrush(QPalette::Background, bkgnd);
                this->setPalette(palette);
                this->setMask(roundedRect(this->rect(),10));

                //this->setStyleSheet("");
//                this->setAttribute(Qt::WA_TranslucentBackground);
                this->setWindowFlags(Qt::FramelessWindowHint);


    //this->setMinimumSize(200,300);
    /////////////////////////////////////
    // round window!!
   // this->setAttribute(Qt::WA_TranslucentBackground, true);
    ////////////////////////////////////
    //css

    btn_log_in->setStyleSheet("QToolButton:pressed {background:none; background-color: #999999;color:#d9d9d9;} QToolButton{ background-color:#d9d9d9;color:#999999;padding:10px;border:1px solid #999999; font-weight:bold;font-family:Serif;border-radius : 5px;} ");
    btn_sign_up->setStyleSheet("QToolButton:pressed {background:none; background-color: #999999;color:#d9d9d9;} QToolButton{ background-color:#d9d9d9;color:#999999;padding:10px;border:1px solid #999999; font-weight:bold;font-family:Serif;border-radius : 5px;}");
    btn_exit->setStyleSheet("QToolButton:pressed {background:none; background-color: #999999;color:#d9d9d9;} QToolButton{ background-color:#d9d9d9;color:#999999;padding:10px;border:1px solid #999999; font-weight:bold;font-family:Serif;border-radius : 5px;}");

    connect(btn_log_in,SIGNAL(clicked()),this,SLOT(on_btn_log_in_clicked()));
    connect(btn_sign_up,SIGNAL(clicked()),this,SLOT(on_btn_sign_up_clicked()));
    connect(btn_exit,SIGNAL(clicked()),this,SLOT(on_btn_exit_clicked()));
}
void Main_UI::on_btn_exit_clicked()
{
    unloading();
    close();
}
