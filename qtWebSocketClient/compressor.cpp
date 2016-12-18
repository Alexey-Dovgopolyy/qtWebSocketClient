#include "compressor.h"

Compressor::Compressor(QObject *parent) : QObject(parent)
{
    qDebug() << "Compressor constructor";
}

Compressor::~Compressor()
{
    qDebug() << "~Compressor";
}

QByteArray Compressor::compressMessage(QByteArray &input)
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
        return QByteArray();
    }
    input.clear();
    input = QByteArray(data_out,size_out);
    return QByteArray();
}

QByteArray Compressor::uncompressMessage(QByteArray &input)
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
            return QByteArray(final_data, size_out);

        case Z_MEM_ERROR :
            qDebug() << "Out of memory";
            return QByteArray();

        case Z_BUF_ERROR :
            qDebug() << "Output buffer wasn't large enough!";
            return QByteArray();

        case Z_DATA_ERROR :
            qDebug() << "Wrong data!";
            return QByteArray();
    }
}
