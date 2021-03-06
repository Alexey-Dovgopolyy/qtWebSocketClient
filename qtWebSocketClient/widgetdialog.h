#ifndef WIDGETDIALOG_H
#define WIDGETDIALOG_H

#include <QtWidgets>
#include <QDebug>
#include "logwriter.h"

class WidgetDialog : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetDialog(QWidget *parent = 0);
    ~WidgetDialog();

    void connctenConfig();

signals:
    void signalConnectToHost();
    void signalSendMessage(QString);
    void signalDisconnectFromHost();

public slots:
    void slotClickButtonSend();
    void slotSetLog(QString log);

private:
    QTextEdit*      mLog;
    QLineEdit*      mMessage;
    QPushButton*    mButtonConnect;
    QPushButton*    mButtonSend;
    QPushButton*    mButtonDisconnect;
    LogWriter*      mLogWriter;
};

#endif // WIDGETDIALOG_H
