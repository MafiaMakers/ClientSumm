#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QObject>
#include <QAudioOutput>
#include <QBuffer>
#include <QAudioFormat>

#include "Calls/SuperList.h"
using namespace SuperFunctions;

namespace Mafia {
class AudioPlayer : public QObject
{
    Q_OBJECT
public:
    explicit AudioPlayer(QObject *parent = nullptr);
    void appendAudio(QByteArray audio, int index);
    void addPlayer();
private:
    SuperList<QAudioOutput*> outAudio;
    SuperList<QIODevice*> player;
    QByteArray *whole;
    QAudioFormat format;

signals:

};
}

#endif // AUDIOPLAYER_H
