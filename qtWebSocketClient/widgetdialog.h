#ifndef WIDGETDIALOG_H
#define WIDGETDIALOG_H

#include <QtWidgets>
#include <QDebug>

class WidgetDialog : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetDialog(QWidget *parent = 0);
    ~WidgetDialog();

signals:

public slots:

private:
    QTextEdit*      mLog;
    QLineEdit*      mMessage;
    QPushButton*    mButtonConnect;
    QPushButton*    mButtonSend;
    QPushButton*    mButtonDisconnect;
};

#endif // WIDGETDIALOG_H
