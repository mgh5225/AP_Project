#ifndef ADDBUILDING_H
#define ADDBUILDING_H
#include "addnewapartment_ui.h"
#include "addnewsouthvilla.h"
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
class AddBuilding : public QWidget
{
    Q_OBJECT

    QToolButton *btn_AddApartment;
    QToolButton *btn_AddSouthVilla;
    QToolButton *btn_AddNorthVilla;
    QToolButton *btn_AddFlat;

    QGridLayout *my_grid_Layout;

    AddNewApartment_UI *apartment;
    AddNewSouthVilla *soutVilla;
public:
    explicit AddBuilding(QWidget *parent = nullptr);

signals:

public slots:
    void AddApartment();
    void AddSoutVilla();
};

#endif // ADDBUILDING_H
