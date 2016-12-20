#ifndef LOGWRITER_H
#define LOGWRITER_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QDir>

class LogWriter : public QObject
{
    Q_OBJECT
public:
    LogWriter(QObject *parent = 0);
    ~LogWriter();

    void writeLog(QString log);

private:
    QString path;
};

#endif // LOGWRITER_H
