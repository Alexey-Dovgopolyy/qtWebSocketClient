#include "client.h"

Client::Client(QObject *parent)
    : QObject           (parent)
    , mHost             ("localhost")
    , mPort             ("10000")
    , mIsConnected      (false)
    , mIsBinary         (false)
    , mNeedToCompress   (false)
{
    qDebug() << "Client constructor";

    mCompressor = new Compressor(this);
    mSocket = new QWebSocket;

    connectConfig();
}

Client::~Client()
{
    qDebug() << "~Client";
    mSocket->deleteLater();
}

void Client::connectConfig()
{
    connect(mSocket, &QWebSocket::connected, this, &Client::slotConnected);
    connect(mSocket, &QWebSocket::disconnected, this, &Client::slotDisconnected);
    connect(mSocket, &QWebSocket::binaryMessageReceived, this, &Client::slotReceiveBinaryMessage);
    connect(mSocket, &QWebSocket::textMessageReceived, this, &Client::slotReceiveTextMessage);
    connect(mSocket,
            static_cast<void(QWebSocket::*)(QAbstractSocket::SocketError)>(&QWebSocket::error),
            this, &Client::slotErrorsHandler);
}

QWebSocket *Client::getSocket()
{
    return mSocket;
}

void Client::slotCompress(bool needToCompress)
{
    mNeedToCompress = needToCompress;
}

void Client::slotBinary(bool binary)
{
    mIsBinary = binary;
}

void Client::slotSendMessage(QString message)
{
    if (mIsBinary) {
        slotSendBinaryMessage(message.toUtf8());
    }
    else {
        slotSendTextMessage(message);
    }
}

void Client::slotSendTextMessage(QString message)
{
    qDebug() << message;
    int bytesSent = mSocket->sendTextMessage(message);
    QString log;
    log = "<FONT COLOR=BLUE>SENT: </FONT>" +
            QString::number(bytesSent) + " " + QString(message);
    qDebug() << log;
    emit signalLogMessage(log);
}

void Client::slotReceiveTextMessage(QString message)
{
    QString log = "<FONT COLOR=#006600>MSG: </FONT> " + message;
    emit signalLogMessage(log);
}

void Client::slotSendBinaryMessage(QByteArray message)
{
    if (mNeedToCompress) {
        mCompressor->compressMessage(message);
    }
    int bytesSent = mSocket->sendBinaryMessage(message);
    QString log = "<FONT COLOR=BLUE>SENT: </FONT>" +
            QString::number(bytesSent) + " " + QString(message);
    emit signalLogMessage(log);
}

void Client::slotReceiveBinaryMessage(QByteArray message)
{
    qDebug() << message;
    qDebug() << mNeedToCompress;
    if (mNeedToCompress) {
        mCompressor->uncompressMessage(message);
    }
    QString log = "<FONT COLOR=#006600>MSG: </FONT> " + QString(message);
    emit signalLogMessage(log);
}

void Client::slotSetHost(QString host)
{
    mHost = host;
    qDebug() << "host";
}

void Client::slotSetPort(QString port)
{
    mPort = port;
    qDebug() << "port";
}

void Client::slotConnect()
{
    QString log;
    if (!mIsConnected) {
        QString address = "ws://" + mHost + ":" + mPort;
        log = "<FONT COLOR=BLUE>LOG: </FONT>Server: " + address;
        emit signalLogMessage(log);
        mUrl = address;
        mSocket->open(mUrl);
    }
    else {
        log = "<FONT COLOR=BLUE>MSG: </FONT>Already connected";
        emit signalLogMessage(log);
    }
}

void Client::slotDisconnect()
{
    if (mSocket->state() == QAbstractSocket::ConnectedState) {
        emit signalLogMessage("<FONT COLOR=BLUE>LOG: </FONT>Disconnecting client...");
    }
    else {
        emit signalLogMessage("<FONT COLOR=BLUE>LOG: </FONT>Client not disconnected");
    }
    mSocket->close();
}

void Client::slotConnected()
{
    QString log = "<FONT COLOR=BLUE>LOG: </FONT>Connected";
    emit signalLogMessage(log);
    mIsConnected = true;
}

void Client::slotDisconnected()
{
    if (mIsConnected) {
        mIsConnected = false;
        emit signalLogMessage("<FONT COLOR=BLUE>LOG: </FONT>Disconnected");
    }
}

void Client::slotErrorsHandler(QAbstractSocket::SocketError error)
{
    QString log;
    log = "<FONT COLOR=RED>ERROR: </FONT> " + mSocket->errorString();
    emit signalLogMessage(log);
    mSocket->close();
    mIsConnected = false;
}
