#include "main_ui.h"
#include <QPainter>
static QRegion roundedRect(const QRect& rect, int r)
{
    QRegion region;
    // middle and borders
    region += rect.adjusted(r, 0, -r, 0);
    region += rect.adjusted(0, r, 0, -r);
    // top left
    QRect corner(rect.topLeft(), QSize(r*2, r*2));
    region += QRegion(corner, QRegion::Ellipse);
    // top right
    corner.moveTopRight(rect.topRight());
    region += QRegion(corner, QRegion::Ellipse);
    // bottom left
    corner.moveBottomLeft(rect.bottomLeft());
    region += QRegion(corner, QRegion::Ellipse);
    // bottom right
    corner.moveBottomRight(rect.bottomRight());
    region += QRegion(corner, QRegion::Ellipse);
    return region;
}
Main_UI::Main_UI(QWidget *parent) : QMainWindow(parent)
{
    btn_exit = new QToolButton();
    btn_log_in = new QToolButton();
    btn_sign_up = new QToolButton();
    btn_exit->setMinimumSize(70,70);
    btn_log_in->setMinimumSize(70,70);
    btn_sign_up->setMinimumSize(70,70);



    QPixmap pixmap(":/icons/resource/icons/User_Login.png");
    QIcon btn_log_in_Icon(pixmap);

    btn_log_in->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btn_log_in->setIcon(btn_log_in_Icon);
    btn_log_in->setIconSize(QSize(30, 30));
    btn_log_in->setText("Log In");


    QPixmap pixmap2(":/icons/resource/icons/Exit_Icon.png");
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








    toolbar = new QHBoxLayout();

    my_grid_layout = new QGridLayout();


    toolbar->addWidget(btn_log_in,0,Qt::AlignLeft);
    toolbar->addWidget(btn_sign_up,1,Qt::AlignLeft);
    toolbar->addWidget(btn_exit,0,Qt::AlignRight);



     my_grid_layout->addLayout(toolbar,0,0,1,5,Qt::AlignTop);




    ////////////////////////////////////////
    //set frame


    QWidget *widget = new QWidget();
    widget->setLayout(my_grid_layout);
    this->setCentralWidget(widget);
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
                this->setMask(roundedRect(this->rect(), 10));
                //this->setStyleSheet("");
//                this->setAttribute(Qt::WA_TranslucentBackground);
                this->setWindowFlags(Qt::FramelessWindowHint);

    //this->setMinimumSize(200,300);
    /////////////////////////////////////
    // round window!!
   // this->setAttribute(Qt::WA_TranslucentBackground, true);
    ////////////////////////////////////
    //css

    btn_log_in->setStyleSheet("QToolButton:pressed {background:none; background-color: #00cc00;color:#b3ffb3;} QToolButton{ background-color:#b3ffb3;color:#009900;padding:10px;border:1px solid #009900; font-weight:bold;font-family:Serif;border-radius : 5px;} ");
    btn_sign_up->setStyleSheet("QToolButton:pressed {background-color: #2980b9;color:#B3E5FC;} QToolButton{ background-color:#B3E5FC;color:#2980b9;padding:10px;border:1px solid #2980b9; font-weight:bold;font-family:Serif;border-radius : 5px;} ");
    btn_exit->setStyleSheet("QToolButton:pressed {background-color:#ff1a1a;color:#ffb3b3;} QToolButton{ background-color:#ffb3b3;color:#b30000;padding:10px;border:1px solid #b30000; font-weight:bold;font-family:Serif;border-radius : 5px; }");


}
