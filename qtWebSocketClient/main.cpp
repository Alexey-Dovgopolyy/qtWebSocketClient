#include <QApplication>
#include "mainwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWidget mainWidget;
    mainWidget.resize(600, 300);
    mainWidget.show();

    return a.exec();
}
