#include "audioplayer.h"
#include <iostream>
using namespace Mafia;
AudioPlayer::AudioPlayer(QObject *parent) : QObject(parent)
{
    QAudioDeviceInfo *info = new QAudioDeviceInfo();
    whole = new QByteArray();
    QAudioFormat format;
    format.setSampleRate(8000); //set frequency to 8000
    format.setChannelCount(1); //set channels to mono
    format.setSampleSize(16); //set sample sze to 16 bit
    format.setSampleType(QAudioFormat::UnSignedInt ); //Sample type as usigned integer sample
    format.setByteOrder(QAudioFormat::LittleEndian); //Byte order
    format.setCodec("audio/pcm");
    outAudio = new QAudioOutput(format, this);
    outAudio->setVolume(1.0);
    outAudio->setBufferSize(30000);
    player = outAudio->start();
    connect(outAudio, &QAudioOutput::stateChanged, this, &AudioPlayer::stch);
}

void AudioPlayer::appendAudio(QByteArray audio) {
    player->write(audio);
}

void AudioPlayer::stch(QAudio::State ns) {
    std::cout << "New state: " << ns << std::endl;
}
