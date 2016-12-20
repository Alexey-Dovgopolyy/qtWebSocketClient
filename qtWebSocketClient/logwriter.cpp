#include "logwriter.h"

LogWriter::LogWriter(QObject *parent) : QObject(parent)
{
    qDebug() << "LogWriter constructor";

    QDir directory;
    if (directory.mkdir("logs")) {
        qDebug() << "Log directory created";

    }
    else {
        qDebug() << "Can't create log directory";
    }

    if (directory.cd("./logs/")) {
        path = "./logs/";
    }
    else {
        path.clear();
    }
}

LogWriter::~LogWriter()
{
    qDebug() << "~LogWriter";
}

void LogWriter::writeLog(QString log)
{
    if (path.isEmpty()) {
        qDebug() << "Can't find log directory";
        return;
    }

    QString filename = QString("%1%2.log")
            .arg(path)
            .arg(QDateTime::currentDateTime().toUTC().toString("dd.MM.yyyy"));
    QFile file(filename);
    if(file.open(QIODevice::Append | QIODevice::Text))
    {
        QString toWrite = QString("[ %1 ] %2\n")
                .arg(QDateTime::currentDateTime().toUTC().toString("dd.MM.yyyy hh:mm:ss"))
                .arg(log);
        file.write(toWrite.toUtf8().data());
        file.close();
    }
}
