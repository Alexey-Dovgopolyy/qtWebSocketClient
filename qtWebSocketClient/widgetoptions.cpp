#include "widgetoptions.h"

WidgetOptions::WidgetOptions(QWidget *parent) : QWidget(parent)
{
    qDebug() << "Options constructor";

    mLblHost           = new QLabel("Host");
    mLblPort           = new QLabel("Port");
    mLblCompress       = new QLabel("Compress");
    mHost              = new QLineEdit("localhost");
    mPort              = new QLineEdit("2000");
    mChbIsCompress     = new QCheckBox;

    mLblHost->setFixedWidth(100);
    mLblPort->setFixedWidth(100);
    mLblCompress->setFixedWidth(100);
    mChbIsCompress->setChecked(false);

    QHBoxLayout* hLayoutHost = new QHBoxLayout;
    hLayoutHost->addWidget(mLblHost);
    hLayoutHost->addWidget(mHost);

    QHBoxLayout* hLayoutPort = new QHBoxLayout;
    hLayoutPort->addWidget(mLblPort);
    hLayoutPort->addWidget(mPort);

    QHBoxLayout* hLayoutCompress = new QHBoxLayout;
    hLayoutCompress->addWidget(mLblCompress);
    hLayoutCompress->addWidget(mChbIsCompress);

    QVBoxLayout* vLayout = new QVBoxLayout;
    vLayout->addLayout(hLayoutHost);
    vLayout->addLayout(hLayoutPort);
    vLayout->addLayout(hLayoutCompress);
    vLayout->addStretch(1);

    setLayout(vLayout);
}

WidgetOptions::~WidgetOptions()
{
    qDebug() << "~Options";
}

