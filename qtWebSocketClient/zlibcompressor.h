#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <QObject>
#include <QDebug>
#include "abstractcompressor.h"
#include "zlib/zlib.h"

class ZlibCompressor : public AbstractCompressor
{
public:
    ZlibCompressor(QObject *parent = 0);
    ~ZlibCompressor();

    void compressMessage     (QByteArray &input);
    void uncompressMessage   (QByteArray &input);
};

#endif // COMPRESSOR_H
