#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QtWidgets>
#include <QtWebSockets/QWebSocket>

#include "widgetdialog.h"
#include "widgetoptions.h"
#include "client.h"
#include "compressor.h"

class MainWidget : public QTabWidget
{
    Q_OBJECT
public:
    MainWidget();

signals:

public slots:
    void slotSend(QString message, bool needToCompress);

private:
    WidgetDialog*       mDialog;
    WidgetOptions*      mOptions;
    Client*             mClient;
    Compressor*         mCompressor;
};

#endif // MAINWIDGET_H
