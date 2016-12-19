#include "widgetdialog.h"

WidgetDialog::WidgetDialog(QWidget *parent) : QWidget(parent)
{
    qDebug() << "Dialog constructor";

    mLog                   = new QTextEdit;
    mMessage               = new QLineEdit;
    mButtonConnect         = new QPushButton("Connect");
    mButtonSend            = new QPushButton("Send");
    mButtonDisconnect      = new QPushButton("Disconnect");

    QHBoxLayout* horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(mButtonConnect);
    horizontalLayout->addWidget(mButtonSend);
    horizontalLayout->addWidget(mButtonDisconnect);

    QVBoxLayout* verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(mLog);
    verticalLayout->addWidget(mMessage);
    verticalLayout->addLayout(horizontalLayout);

    setLayout(verticalLayout);
}

WidgetDialog::~WidgetDialog()
{
    qDebug() << "~Dialog";
}

