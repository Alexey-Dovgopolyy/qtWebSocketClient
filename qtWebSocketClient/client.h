#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QDebug>
#include <QtWebSockets/QWebSocket>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    ~Client();

signals:

public slots:

private:
    QWebSocket*     mSocket;
    QString         url;
    QString         host;
    QString         port;
};

#endif // CLIENT_H
