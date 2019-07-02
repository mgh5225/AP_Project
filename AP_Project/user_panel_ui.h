#ifndef USER_PANEL_UI_H
#define USER_PANEL_UI_H

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

class User_Panel_UI : public QWidget
{
    Q_OBJECT


    QToolButton *btn_showBalance;
    QToolButton *btn_addFile;
    QToolButton *btn_explor;
    QToolButton *btn_Exit;
    QToolButton *btn_LogOut;
    QToolButton *btn_Icon;

    QVBoxLayout *my_v_layout;
    QHBoxLayout *my_h_layout;
    QGridLayout *my_grid_layout;





public:
    explicit User_Panel_UI(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // USER_PANEL_UI_H
