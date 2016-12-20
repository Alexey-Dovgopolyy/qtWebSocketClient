#include "zlibcompressor.h"

ZlibCompressor::ZlibCompressor(QObject *parent) : AbstractCompressor(parent)
{
    qDebug() << "ZlibCompressor constructor";
}

ZlibCompressor::~ZlibCompressor()
{
    qDebug() << "~ZlibCompressor";
}

void ZlibCompressor::compressMessage(QByteArray &input)
{
    char    data_out[25000];
    ulong   size_out = sizeof(data_out);

    for (uint i = 0; i < size_out; ++i) {
        data_out[i]=0;
    }
    if (Z_OK != compress2((Bytef *)&data_out, &size_out,
                        (const Bytef *)input.data(), input.length(),
                        Z_BEST_COMPRESSION))
    {
        qDebug() << "Can't compress!";
        return;
    }
    input.clear();
    input = QByteArray(data_out,size_out);
}

void ZlibCompressor::uncompressMessage(QByteArray &input)
{
    char            final_data[20010];
    ulong           size_out = 10010;
    int             z_result;

    z_result = uncompress((Byte*)&final_data,
                          &size_out,
                          (const Byte*) input.data(),
                          input.length());

    switch(z_result)
    {
        case Z_OK :
            input.clear();
            input = QByteArray(final_data, size_out);
            return;

        case Z_MEM_ERROR :
            qDebug() << "Out of memory";
            return;

        case Z_BUF_ERROR :
            qDebug() << "Output buffer wasn't large enough!";
            return;

        case Z_DATA_ERROR :
            qDebug() << "Wrong data!";
            return;
    }
}
