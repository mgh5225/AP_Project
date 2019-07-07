#ifndef ADDBUILDING_H
#define ADDBUILDING_H
#include "addnewapartment_ui.h"
#include "addnewsouthvilla.h"
#include "addnewnorthvilla.h"
#include "addnewflat_ui.h"
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
    AddNewNorthVilla *northVilla;
    AddNewFlat_UI *flat;
public:
    bool Enable = true;
    explicit AddBuilding(QWidget *parent = nullptr);
    //void show();

signals:

public slots:
    void AddApartment();
    void AddSoutVilla();
    void AddNorthVilla();
    void AddFlat();
};

#endif // ADDBUILDING_H
