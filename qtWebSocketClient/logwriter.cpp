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

    logAdaptation(log);

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

void LogWriter::logAdaptation(QString &log)
{
    int indexFirst = 0;
    int indexLast = 0;
    indexLast = log.indexOf('>');
    if (indexLast == -1) return;
    log.remove(0, indexLast + 1);
    indexFirst = log.indexOf('<');
    indexLast = log.indexOf('>');
    qDebug() << indexFirst << " " << indexLast;
    log.remove(indexFirst, ((indexLast + 1) - indexFirst));
}
