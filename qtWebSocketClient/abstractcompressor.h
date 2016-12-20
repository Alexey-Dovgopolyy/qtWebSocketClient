#ifndef ABSTRACTCOMPRESSOR_H
#define ABSTRACTCOMPRESSOR_H

#include <QObject>
#include <QDebug>

class AbstractCompressor : public QObject
{
public:
    AbstractCompressor(QObject* parent = 0);
    virtual ~AbstractCompressor();

    virtual void compressMessage(QByteArray &input) = 0;
    virtual void uncompressMessage(QByteArray &input) = 0;
};

#endif // ABSTRACTCOMPRESSOR_H
