#ifndef USER_PANEL_UI_H
#define USER_PANEL_UI_H

#include "addbuilding.h"
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
#include "user.h"
#include "explorer.h"
class User_Panel_UI : public QWidget
{
    Q_OBJECT

    QWidget* parent;
    QToolButton *btn_showBalance;
    QToolButton *btn_addFile;
    QToolButton *btn_explore;
    QToolButton *btn_Exit;
    QToolButton *btn_LogOut;
    QToolButton *btn_Icon;

    QVBoxLayout *my_v_layout;
    QHBoxLayout *my_h_layout;
    QGridLayout *my_grid_layout;

    AddBuilding* Building;
    explorer* Explorer;



    bool IsAddClicked = false;
public:
    explicit User_Panel_UI(user& usr,QWidget *parent = nullptr);

signals:

public slots:
    void add_building_clicked();
    void explorer_clicked();
    void on_btn_exit_clicked();
};

#endif // USER_PANEL_UI_H
