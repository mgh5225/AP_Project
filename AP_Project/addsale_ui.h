#ifndef ADDSALE_UI_H
#define ADDSALE_UI_H

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
#include <QDialog>
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
#include <QRadioButton>

class AddSale_UI : public QDialog
{
    Q_OBJECT

    QLineEdit *led_Commission;
    QLineEdit *led_Condition;
    QPushButton *btn_Ok;
    QPushButton *btn_Cancel;
    QHBoxLayout *my_h_layout;
    QVBoxLayout *my_v_layout;

public:
    explicit AddSale_UI(QWidget *parent = nullptr);
    QString get_com();
    QString get_con();

signals:
public slots:
};

#endif // ADDSALE_UI_H
