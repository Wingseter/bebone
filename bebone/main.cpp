#include "bebone.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bebone w;
    w.setWindowTitle("Covid-19 Visitor List v1.0");
    w.show();
    return a.exec();
}
