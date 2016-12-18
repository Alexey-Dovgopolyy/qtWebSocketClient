#include "mainwidget.h"

MainWidget::MainWidget()
{
    mDialog        = new WidgetDialog(this);
    mOptions       = new WidgetOptions(this);
    mClient        = new Client(this);
    mCompressor    = new Compressor(this);

    addTab(mDialog, "Dialog");
    addTab(mOptions, "Options");
}

void MainWidget::slotSend(QString message, bool needToCompress)
{
    if (needToCompress) {
        QByteArray bytes = message.toUtf8();
        mCompressor->compressMessage(bytes);
        message = QString(bytes);
    }
    mClient->getSocket()->sendTextMessage(message);
}

