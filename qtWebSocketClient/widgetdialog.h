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
    QTextEdit*      m_log;
    QLineEdit*      m_message;
    QPushButton*    m_buttonConnect;
    QPushButton*    m_buttonSend;
    QPushButton*    m_buttonDisconnect;
};

#endif // WIDGETDIALOG_H
