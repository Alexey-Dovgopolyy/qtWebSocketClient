#include <QApplication>
#include "mainwidget.h"
#include "zlibcompressorfactory.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ZlibCompressorFactory zlibFactory;
    MainWidget mainWidget(&zlibFactory);
    mainWidget.resize(600, 300);
    mainWidget.show();

    return a.exec();
}
