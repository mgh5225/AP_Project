#ifndef MANAGER_PANEL_UI_H
#define MANAGER_PANEL_UI_H

#include "addbuilding.h"
#include "explorer.h"
#include <QWidget>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QResource>
#include <QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QMouseEvent>
#include <QFrame>
#include <QStyle>
#include <QDesktopWidget>
#include <QApplication>
#include <QDateEdit>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDebug>
#include <QComboBox>
#include <QGridLayout>
#include <QSizePolicy>
#include <QToolButton>
#include "manager.h"

class Manager_Panel_UI : public QWidget
{
    Q_OBJECT


    QToolButton *btn_addFile;

    QToolButton *btn_Exit;
    QToolButton *btn_LogOut;
    QToolButton *btn_Icon;
    QToolButton *btn_explore;
    QToolButton *btn_file_Management;

    QVBoxLayout *my_v_layout;
    QHBoxLayout *my_h_layout;
    QGridLayout *my_grid_layout;

    AddBuilding* Building;
    explorer* Explorer;
    manager& mgr;
    QWidget* parent;
public:
    explicit Manager_Panel_UI(manager& mgr,QWidget *parent = nullptr);

signals:

public slots:
        void add_building_clicked();
        void explorer_clicked();
        void on_btn_exit_clicked();
        //void on_btn_show_balance_clicked();
        void on_btn_logOut_clicked();
};

#endif // MANAGER_PANEL_UI_H
