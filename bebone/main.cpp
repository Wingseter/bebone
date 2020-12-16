#include "bebone.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bebone w;
    w.show();
    return a.exec();
}
