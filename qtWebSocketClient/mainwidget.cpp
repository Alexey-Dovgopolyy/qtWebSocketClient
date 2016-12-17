#include "mainwidget.h"

MainWidget::MainWidget()
{
    m_dialog    = new WidgetDialog(this);
    m_options   = new WidgetOptions(this);
    m_client    = new Client(this);

    addTab(m_dialog, "Dialog");
    addTab(m_options, "Options");
}

