#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <QObject>
#include <QDebug>
#include "zlib/zlib.h"

class Compressor : public QObject
{
public:
    Compressor(QObject *parent);
    ~Compressor();

    QByteArray compressMessage     (QByteArray &input);
    QByteArray uncompressMessage   (QByteArray &input);
};

#endif // COMPRESSOR_H
