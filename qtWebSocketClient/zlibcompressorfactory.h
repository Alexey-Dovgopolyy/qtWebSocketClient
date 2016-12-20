#ifndef ZLIBCOMPRESSORFACTORY_H
#define ZLIBCOMPRESSORFACTORY_H

#include <QDebug>
#include "abstractcompressorfacrory.h"
#include "zlibcompressor.h"

class ZlibCompressorFactory : public AbstractCompressorFacrory
{
public:
    ZlibCompressorFactory(QObject *parent = 0);
    ~ZlibCompressorFactory();

    AbstractCompressor* createCompressor(QObject *qobject);
};

#endif // ZLIBCOMPRESSORFACTORY_H
