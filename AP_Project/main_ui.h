#ifndef MAIN_UI_H
#define MAIN_UI_H
#include"showbuilding_widget.h"
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
#include<QFontDatabase>
#include "user_panel_ui.h"
#include "login.h"
#include "register_ui.h"
#include "explorer.h"
#include "manager_panel_ui.h"
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
class Main_UI : public QMainWindow
{
    Q_OBJECT
    QHBoxLayout *toolbar;
    QVBoxLayout *body;

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
    ShowBuilding_widget* obj_10;
    ShowBuilding_widget* obj_11;
    ShowBuilding_widget* obj_12;
private slots:
    void on_btn_log_in_clicked();
    void on_btn_sign_up_clicked();
    void on_btn_exit_clicked();
    //void on_widget_clicked();
public:
    explicit Main_UI(QWidget *parent = nullptr,have_file* files[12]={});
};
#endif // MAIN_UI_H
