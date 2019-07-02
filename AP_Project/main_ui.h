#ifndef MAIN_UI_H
#define MAIN_UI_H

#include<QMainWindow>
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
#include <QToolButton>
#include"showbuilding_widget.h"
class Main_UI : public QMainWindow
{
    Q_OBJECT
    QHBoxLayout *toolbar;

    QToolButton *btn_sign_up;
    QToolButton *btn_log_in;
    QToolButton *btn_exit;

    QFrame *myFrame;
    QFrame *frameToolBar;

    QGridLayout *my_grid_layout;
    ShowBuilding_widget* obj_1;
    ShowBuilding_widget* obj_2;
    ShowBuilding_widget* obj_3;
    ShowBuilding_widget* obj_4;
    ShowBuilding_widget* obj_5;
    ShowBuilding_widget* obj_6;
    ShowBuilding_widget* obj_7;
    ShowBuilding_widget* obj_8;
    ShowBuilding_widget* obj_9;



public:
    explicit Main_UI(QWidget *parent = nullptr);



signals:

public slots:
};

#endif // MAIN_UI_H
