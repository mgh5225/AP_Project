#ifndef ADDNEWSOUTHVILLA_H
#define ADDNEWSOUTHVILLA_H

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


class AddNewSouthVilla : public QWidget
{
    Q_OBJECT



    QLabel *label_BuildArea;
    QLabel *label_YardArea;
    QLabel *label_ParkingArea;
    QLabel *label_BuildingPicture;
    QLabel *label_FullArea;
    QLabel *label_NumberOfRooms;
    QLabel *label_BasePrice;
    QLabel *label_Address;
    QLabel *labelDragAndDrop;

    QLineEdit *lineEdit_BuildArea;
    QLineEdit *lineEdit_YardArea;
    QLineEdit *lineEdit_ParkingArea;
    QLineEdit *lineEdit_FullArea;
    QLineEdit *lineEdit_NumberOfRooms;
    QLineEdit *lineEdit_BasePrice;
    QLineEdit *lineEdit_Address;

    QGridLayout *my_grid_layout;

    QPushButton *btn_Add;
    QPushButton *btn_Cancel;





public:
    explicit AddNewSouthVilla(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // ADDNEWSOUTHVILLA_H
