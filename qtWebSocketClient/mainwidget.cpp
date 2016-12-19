#include "mainwidget.h"

MainWidget::MainWidget()
{
    mDialog        = new WidgetDialog(this);
    mOptions       = new WidgetOptions(this);
    mClient        = new Client(this);
    mCompressor    = new Compressor(this);

<<<<<<< HEAD
    addTab(m_dialog, "Dialog");
    addTab(m_options, "Options");

    connect()
=======
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
>>>>>>> 6ca05ff062614b0ea4d27d8bde255115e69c7d2d
}

