#ifndef WIDGETOPTIONS_H
#define WIDGETOPTIONS_H

#include <QtWidgets>
#include <QDebug>

class WidgetOptions : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetOptions(QWidget *parent = 0);
    ~WidgetOptions();

signals:

public slots:

private:
    QLabel*         mLblHost;
    QLabel*         mLblPort;
    QLabel*         mLblCompress;
    QLineEdit*      mHost;
    QLineEdit*      mPort;
    QCheckBox*      mChbIsCompress;
};

#endif // WIDGETOPTIONS_H
