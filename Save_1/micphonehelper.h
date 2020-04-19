#ifndef MICPHONEHELPER_H
#define MICPHONEHELPER_H

#include <QObject>
#include <QAudioInput>
#include <QIODevice>
namespace Mafia {
class MicphoneHelper : public QObject
{
    Q_OBJECT
public:
    explicit MicphoneHelper(QObject *parent = nullptr);

private:
    QAudioInput* audio;
    QIODevice *buff;
public:
    QByteArray getAudio();

signals:

};
}

#endif // MICPHONEHELPER_H
