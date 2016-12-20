#ifndef ABSTRACTCOMPRESSORFACRORY_H
#define ABSTRACTCOMPRESSORFACRORY_H

#include <QObject>
#include <QDebug>
#include "abstractcompressor.h"

class AbstractCompressorFacrory : public QObject
{
public:
    AbstractCompressorFacrory(QObject *parent = 0);
    virtual ~AbstractCompressorFacrory();

    virtual AbstractCompressor* createCompressor(QObject *qobject) = 0;
};

#endif // ABSTRACTCOMPRESSORFACRORY_H
