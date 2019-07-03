#ifndef SHOWBUILDING_WIDGET_H
#define SHOWBUILDING_WIDGET_H
#include <QWidget>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include <QLineEdit>
#include<QResource>
#include<QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QMouseEvent>
#include<QFrame>
#include <QStyle>
#include <QDesktopWidget>
#include <QApplication>
#include <QDateEdit>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDebug>
#include <QComboBox>
#include <QGridLayout>
#include "have_file.h"
#include "building.h"
#include "apartment.h"
#include "villa.h"
#include "north_villa.h"
#include "south_villa.h"
class ShowBuilding_widget : public QWidget
{
    Q_OBJECT

    have_file* file;

    QLabel *pic;
    QLabel *total_area;
    QLabel *address;
    QLabel *final_price;
    QGridLayout* my_grid_layout;
    QFrame *frame;
    QPalette *pal;
    QGridLayout *lay;
protected:
bool eventFilter(QObject *object, QEvent *event){
if(object==this && (event->type()==QEvent::Enter || event->type()==QEvent::Leave))
    if(event->type()==QEvent::Enter){
        pal->setColor(QPalette::Background,QColor(130, 130, 130));
        frame->setPalette(*pal);
    }
    else {
        pal->setColor(QPalette::Background,QColor(255, 255, 255));
        frame->setPalette(*pal);
    }
}
public:
    explicit ShowBuilding_widget(QWidget *parent = nullptr,have_file* _file=nullptr);

signals:

public slots:
};

#endif // SHOWBUILDING_WIDGET_H
