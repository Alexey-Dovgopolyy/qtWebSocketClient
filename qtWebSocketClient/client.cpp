#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{
    qDebug() << "Client constructor";
}

Client::~Client()
{
    qDebug() << "~Client";
}
