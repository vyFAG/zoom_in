#include "zoom.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Zoom w;
    w.show();
    return a.exec();
}
