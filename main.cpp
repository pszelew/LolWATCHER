#include "start.h"
#include "QDebug"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Start w;
    w.showMinimized();
    return a.exec();
}
