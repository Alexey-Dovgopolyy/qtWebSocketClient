#include "widgetdialog.h"

WidgetDialog::WidgetDialog(QWidget *parent) : QWidget(parent)
{
    qDebug() << "Dialog constructor";

    mLog                   = new QTextEdit;
    mMessage               = new QLineEdit;
    mButtonConnect         = new QPushButton("Connect");
    mButtonSend            = new QPushButton("Send");
    mButtonDisconnect      = new QPushButton("Disconnect");
    mLogWriter             = new LogWriter(this);

    QHBoxLayout* horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(mButtonConnect);
    horizontalLayout->addWidget(mButtonSend);
    horizontalLayout->addWidget(mButtonDisconnect);

    QVBoxLayout* verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(mLog);
    verticalLayout->addWidget(mMessage);
    verticalLayout->addLayout(horizontalLayout);

    setLayout(verticalLayout);
    connctenConfig();
}

WidgetDialog::~WidgetDialog()
{
    qDebug() << "~Dialog";
}

void WidgetDialog::connctenConfig()
{
    connect(mButtonConnect, &QPushButton::clicked, this, &WidgetDialog::signalConnectToHost);
    connect(mButtonSend, &QPushButton::clicked, this, &WidgetDialog::slotClickButtonSend);
    connect(mButtonDisconnect, &QPushButton::clicked, this, &WidgetDialog::signalDisconnectFromHost);
}

void WidgetDialog::slotClickButtonSend()
{
    emit signalSendMessage(mMessage->text());
}

void WidgetDialog::slotSetLog(QString log)
{
    mLog->append(log);
    mLogWriter->writeLog(log);
}
