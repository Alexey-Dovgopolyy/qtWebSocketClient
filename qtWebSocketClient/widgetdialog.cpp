#include "widgetdialog.h"

WidgetDialog::WidgetDialog(QWidget *parent) : QWidget(parent)
{
    qDebug() << "Dialog constructor";

    m_log                   = new QTextEdit;
    m_message               = new QLineEdit;
    m_buttonConnect         = new QPushButton("Connect");
    m_buttonSend            = new QPushButton("Send");
    m_buttonDisconnect      = new QPushButton("Disconnect");

    QHBoxLayout* horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(m_buttonConnect);
    horizontalLayout->addWidget(m_buttonSend);
    horizontalLayout->addWidget(m_buttonDisconnect);

    QVBoxLayout* verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(m_log);
    verticalLayout->addWidget(m_message);
    verticalLayout->addLayout(horizontalLayout);

    setLayout(verticalLayout);
}

WidgetDialog::~WidgetDialog()
{
    qDebug() << "~Dialog";
}

