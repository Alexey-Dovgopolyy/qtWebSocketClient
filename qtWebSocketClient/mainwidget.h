#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QtWidgets>

#include "widgetdialog.h"
#include "widgetoptions.h"
#include "client.h"

class MainWidget : public QTabWidget
{
    Q_OBJECT
public:
    MainWidget();

signals:

public slots:


private:
    WidgetDialog*       m_dialog;
    WidgetOptions*      m_options;
    Client*             m_client;
};

#endif // MAINWIDGET_H
