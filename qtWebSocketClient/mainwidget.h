#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QtWidgets>
#include <QtWebSockets/QWebSocket>

#include "widgetdialog.h"
#include "widgetoptions.h"
#include "client.h"

class MainWidget : public QTabWidget
{
    Q_OBJECT
public:
    MainWidget();

    void connectionConfiguration();

signals:

public slots:

private:
    WidgetDialog*       mDialog;
    WidgetOptions*      mOptions;
    Client*             mClient;

};

#endif // MAINWIDGET_H
