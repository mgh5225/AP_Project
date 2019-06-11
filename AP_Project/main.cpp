#include "ap.h"
#include <QApplication>
#include "headers.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AP w;
    w.show();

    return a.exec();
}
