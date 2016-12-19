#include "widgetoptions.h"

WidgetOptions::WidgetOptions(QWidget *parent) : QWidget(parent)
{
    qDebug() << "Options constructor";

    mLblHost            = new QLabel("Host");
    mLblPort            = new QLabel("Port");
    mLblCompress        = new QLabel("Compress");
    mLblBinary          = new QLabel("Binary");
    mHost               = new QLineEdit("localhost");
    mPort               = new QLineEdit("10000");
    mChbIsCompress      = new QCheckBox;
    mChbIsBinary        = new QCheckBox;

    mLblHost->setFixedWidth(100);
    mLblPort->setFixedWidth(100);
    mLblCompress->setFixedWidth(100);
    mLblBinary->setFixedWidth(100);
    mChbIsCompress->setChecked(false);
    mChbIsBinary->setChecked(false);
    mChbIsCompress->setCheckable(false);

    QHBoxLayout* hLayoutHost = new QHBoxLayout;
    hLayoutHost->addWidget(mLblHost);
    hLayoutHost->addWidget(mHost);

    QHBoxLayout* hLayoutPort = new QHBoxLayout;
    hLayoutPort->addWidget(mLblPort);
    hLayoutPort->addWidget(mPort);

    QHBoxLayout* hLayoutBinary = new QHBoxLayout;
    hLayoutBinary->addWidget(mLblBinary);
    hLayoutBinary->addWidget(mChbIsBinary);

    QHBoxLayout* hLayoutCompress = new QHBoxLayout;
    hLayoutCompress->addWidget(mLblCompress);
    hLayoutCompress->addWidget(mChbIsCompress);    

    QVBoxLayout* vLayout = new QVBoxLayout;
    vLayout->addLayout(hLayoutHost);
    vLayout->addLayout(hLayoutPort);    
    vLayout->addLayout(hLayoutBinary);
    vLayout->addLayout(hLayoutCompress);
    vLayout->addStretch(1);

    setLayout(vLayout);
    connectConfig();
}

WidgetOptions::~WidgetOptions()
{
    qDebug() << "~Options";
}

void WidgetOptions::connectConfig()
{
    connect(mChbIsBinary, &QCheckBox::clicked, this, &WidgetOptions::slotSetChechableBinaryChb);
    connect(mChbIsCompress, SIGNAL(clicked(bool)), SIGNAL(signalCompress(bool)));
    connect(mChbIsBinary, SIGNAL(clicked(bool)), SIGNAL(signalBinary(bool)));
    connect(mHost, SIGNAL(textChanged(QString)), SIGNAL(signalSetHost(QString)));
    connect(mPort, SIGNAL(textChanged(QString)), SIGNAL(signalSetPort(QString)));
}

void WidgetOptions::slotSetChechableBinaryChb(bool state)
{
    if (state) {
        mChbIsCompress->setCheckable(true);
    }
    else if (!state && mChbIsCompress->isChecked()) {
        mChbIsCompress->setCheckable(false);
        mChbIsCompress->repaint();
        emit signalCompress(false);
    }
}

