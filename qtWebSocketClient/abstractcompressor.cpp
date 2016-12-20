#include "abstractcompressor.h"

AbstractCompressor::AbstractCompressor(QObject *parent)
        : QObject(parent)
{
    qDebug() << "AbstractCompressor constructor";
}

AbstractCompressor::~AbstractCompressor()
{
    qDebug() << "~AbstractCompressor";
}

