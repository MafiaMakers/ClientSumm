#include "audioplayer.h"
#include <iostream>
using namespace Mafia;
AudioPlayer::AudioPlayer(QObject *parent) : QObject(parent)
{
    QAudioDeviceInfo *info = new QAudioDeviceInfo();
    whole = new QByteArray();
    format.setSampleRate(8000); //set frequency to 8000
    format.setChannelCount(1); //set channels to mono
    format.setSampleSize(16); //set sample sze to 16 bit
    format.setSampleType(QAudioFormat::UnSignedInt ); //Sample type as usigned integer sample
    format.setByteOrder(QAudioFormat::LittleEndian); //Byte order
    format.setCodec("audio/pcm");
    outAudio = QList<QAudioOutput*>();
    //outAudio = new QAudioOutput(format, this);
    player = QList<QIODevice*>();
    //player = outAudio->start();
}

void AudioPlayer::appendAudio(QByteArray audio, int index) {
    if(index < player.length() && index >= 0){
        player[index]->write(audio);
    }

}

void AudioPlayer::addPlayer(){
    outAudio.append(new QAudioOutput(format, this));
    int idx = outAudio.length()-1;
    outAudio[idx]->setVolume(1.0);
    outAudio[idx]->setBufferSize(30000);
    player.append(outAudio[idx]->start());
    std::cout << "added player" << std::endl;
}
