#ifndef REQUESTS_UI_H
#define REQUESTS_UI_H

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
#include <QRadioButton>
#include <QListWidget>
#include <QDialog>

class Requests_Ui : public QWidget
{
    Q_OBJECT

    QListWidget * listWidget_all;

    QPushButton *btn_Accept;
    QPushButton *btn_deny;
    QWidget *widget_Request;
    QLabel *lbl_Request;

    QVBoxLayout *layout_all;
    QVBoxLayout *layout_widget_V;
    QHBoxLayout *layout_widget_H_Btn;
public:
    explicit Requests_Ui(QWidget *parent = nullptr);

signals:

public slots:
    void ListWidgetDoubleClicked(QListWidgetItem *item);
};

#endif // REQUESTS_UI_H
