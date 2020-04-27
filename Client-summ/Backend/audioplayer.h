#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QObject>
#include <QAudioOutput>
#include <QBuffer>
#include <QAudioFormat>
namespace Mafia {
class AudioPlayer : public QObject
{
    Q_OBJECT
public:
    explicit AudioPlayer(QObject *parent = nullptr);
    void appendAudio(QByteArray audio, int index);
    void addPlayer();
private:
    QList<QAudioOutput*> outAudio;
    QList<QIODevice*> player;
    QByteArray *whole;
    QAudioFormat format;

signals:

};
}

#endif // AUDIOPLAYER_H
