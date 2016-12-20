#include "zlibcompressorfactory.h"

ZlibCompressorFactory::ZlibCompressorFactory(QObject *parent)
    : AbstractCompressorFacrory(parent)
{
    qDebug() << "ZlibCompressorFactory constructor";
}

ZlibCompressorFactory::~ZlibCompressorFactory()
{
    qDebug() << "~ZlibCompressorFactory";
}

AbstractCompressor *ZlibCompressorFactory::createCompressor(QObject *qobject)
{
    return new ZlibCompressor(qobject);
}

