#ifndef MICPHONEHELPER_H
#define MICPHONEHELPER_H

#include <QObject>
#include <QAudioInput>
#include <QIODevice>
#include <QBuffer>

namespace Mafia {
class MicphoneHelper : public QObject
{
    Q_OBJECT
public:
    explicit MicphoneHelper(QObject *parent = nullptr);

private:
    QAudioInput* audio;
    QIODevice *buff;
    QByteArray whole;
public:
    QByteArray getAudio(int muchBytes);
    int bytesCount();
    void start();
    void stop();

signals:

};
}

#endif // MICPHONEHELPER_H
