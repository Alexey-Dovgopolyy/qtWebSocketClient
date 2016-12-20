#include "mainwidget.h"

MainWidget::MainWidget(AbstractCompressorFacrory *factory)
{
    //AbstractCompressorFacrory* abstractFactory = new ZlibCompressorFactory(this);

    mClient        = new Client(factory, this);
    mDialog        = new WidgetDialog(this);
    mOptions       = new WidgetOptions(this);    

    addTab(mDialog, "Dialog");
    addTab(mOptions, "Options");

    connectionConfiguration();
}

void MainWidget::connectionConfiguration()
{
    connect(mOptions, &WidgetOptions::signalCompress, mClient, &Client::slotCompress);
    connect(mOptions, &WidgetOptions::signalBinary, mClient, &Client::slotBinary);
    connect(mOptions, &WidgetOptions::signalSetHost, mClient, &Client::slotSetHost);
    connect(mOptions, &WidgetOptions::signalSetPort, mClient, &Client::slotSetPort);

    connect(mDialog, &WidgetDialog::signalConnectToHost, mClient, &Client::slotConnect);
    connect(mDialog, &WidgetDialog::signalSendMessage, mClient, &Client::slotSendMessage);
    connect(mDialog, &WidgetDialog::signalDisconnectFromHost, mClient, &Client::slotDisconnect);

    connect(mClient, &Client::signalLogMessage, mDialog, &WidgetDialog::slotSetLog, Qt::QueuedConnection);

}



