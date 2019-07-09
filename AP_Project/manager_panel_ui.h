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
#include"filemanagement_ui.h"
#include "editpanel_ui.h"
#include "showlog_ui.h"
class Manager_Panel_UI : public QWidget
{
    Q_OBJECT


    QToolButton *btn_addFile;

    QToolButton *btn_Exit;
    QToolButton *btn_LogOut;
    QToolButton *btn_Icon;
    QToolButton *btn_explore;
    QToolButton *btn_file_Management;
    QToolButton *btn_Change_User_Status;
    QToolButton *btn_Edit_Panel;
    QToolButton *btn_Show_Log;

    QVBoxLayout *my_v_layout;
    QHBoxLayout *my_h_layout;
    QGridLayout *my_grid_layout;

    AddBuilding* Building;
    explorer* Explorer;
    manager& mgr;
    QWidget* parent;
    FileManagement_UI * files;
    ChangeUserStatus_UI * userStatus;
    EditPanel_UI *edit;
    ShowLog_UI *showlog;
public:
    explicit Manager_Panel_UI(manager& mgr,QWidget *parent = nullptr);

signals:

public slots:
        void add_building_clicked();
        void explorer_clicked();
        void on_btn_exit_clicked();
        void change_user_status_cliced();
        //void on_btn_show_balance_clicked();
        void on_btn_logOut_clicked();
        void FileManageClicked();
        void edit_panel_clicked();
        void show_log_clicked();

};

#endif // MANAGER_PANEL_UI_H
