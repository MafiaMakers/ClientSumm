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
    void appendAudio(QByteArray audio);
private:
    QAudioOutput *outAudio;
    QIODevice *player;
    QByteArray *whole;

private slots:
    void stch(QAudio::State ns);

signals:

};
}

#endif // AUDIOPLAYER_H
