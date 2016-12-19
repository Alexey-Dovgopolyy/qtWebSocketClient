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

    void connectConfig();

signals:
    void signalCompress(bool);
    void signalBinary(bool);
    void signalSetHost(QString);
    void signalSetPort(QString);

public slots:
    void slotSetChechableBinaryChb(bool state);

private:
    QLabel*         mLblHost;
    QLabel*         mLblPort;
    QLabel*         mLblCompress;
    QLabel*         mLblBinary;
    QLineEdit*      mHost;
    QLineEdit*      mPort;
    QCheckBox*      mChbIsCompress;
    QCheckBox*      mChbIsBinary;
};

#endif // WIDGETOPTIONS_H
