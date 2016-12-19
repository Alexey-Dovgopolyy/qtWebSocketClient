#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QDebug>
#include <QtWebSockets/QWebSocket>
#include "compressor.h"

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    ~Client();

    void connectConfig();
    QWebSocket* getSocket();

signals:
    void signalLogMessage               (QString message);

public slots:
    void slotCompress                   (bool needToCompress);
    void slotBinary                     (bool binary);
    void slotSendMessage                (QString message);
    void slotSendTextMessage            (QString message);
    void slotReceiveTextMessage         (QString message);
    void slotSendBinaryMessage          (QByteArray message);
    void slotReceiveBinaryMessage       (QByteArray message);
    void slotSetHost                    (QString host);
    void slotSetPort                    (QString port);
    void slotConnect                    ();
    void slotDisconnect                 ();

private slots:
    void slotConnected                  ();
    void slotDisconnected               ();
    void slotErrorsHandler              (QAbstractSocket::SocketError error);

private:
    QWebSocket*     mSocket;
    Compressor*     mCompressor;
    QUrl            mUrl;
    QString         mHost;
    QString         mPort;
    bool            mIsConnected;
    bool            mIsBinary;
    bool            mNeedToCompress;
};

#endif // CLIENT_H
