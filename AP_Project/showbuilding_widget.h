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

class ShowBuilding_widget : public QWidget
{
    Q_OBJECT

    //have_file* file;

    QLabel *pic;
    QLabel *total_area;
    QLabel *address;
    QLabel *final_price;

    QGridLayout* my_grid_layout;


public:
    //explicit ShowBuilding_widget(QWidget *parent = nullptr,have_file* _file=nullptr);

signals:

public slots:
};

#endif // SHOWBUILDING_WIDGET_H
