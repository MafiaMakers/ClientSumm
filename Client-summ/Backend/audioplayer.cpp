#include "audioplayer.h"
using namespace Mafia;
AudioPlayer::AudioPlayer(QObject *parent) : QObject(parent)
{
    whole = new QByteArray();
    QAudioFormat format;
    format.setChannelCount(2);
    format.setSampleRate(11025);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::SignedInt);
    outAudio = new QAudioOutput(format);
    player = new QBuffer(whole);
    player->open(QBuffer::ReadOnly);
    outAudio->setBufferSize(10000);
    outAudio->start(player);
}

void AudioPlayer::appendAudio(QByteArray audio) {
    whole->append(audio);
}
