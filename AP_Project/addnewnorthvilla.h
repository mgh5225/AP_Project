#ifndef ADDNEWNORTHVILLA_H
#define ADDNEWNORTHVILLA_H


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


class AddNewNorthVilla : public QWidget
{
    Q_OBJECT



    QLabel *label_BuildArea;
    QLabel *label_FrontYardArea;
    QLabel *label_BackyardArea;
    QLabel *label_BuildingPicture;
    QLabel *label_FullArea;
    QLabel *label_NumberOfRooms;
    QLabel *label_BasePrice;
    QLabel *label_Address;
    QLabel *labelDragAndDrop;

    QLineEdit *lineEdit_BuildArea;
    QLineEdit *lineEdit_FrontYardArea;
    QLineEdit *lineEdit_BackYardArea;
    QLineEdit *lineEdit_FullArea;
    QLineEdit *lineEdit_NumberOfRooms;
    QLineEdit *lineEdit_BasePrice;
    QLineEdit *lineEdit_Address;

    QGridLayout *my_grid_layout;

    QPushButton *btn_Add;
    QPushButton *btn_Cancel;





public:
    explicit AddNewNorthVilla(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // ADDNEWNORTHVILLA_H
