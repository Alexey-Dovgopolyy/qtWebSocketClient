#include "abstractcompressorfacrory.h"

AbstractCompressorFacrory::AbstractCompressorFacrory(QObject *parent)
    : QObject(parent)
{
    qDebug() << "AbstractCompressorFacrory constructor";
}

AbstractCompressorFacrory::~AbstractCompressorFacrory()
{
    qDebug() << "~AbstractCompressorFacrory";
}

