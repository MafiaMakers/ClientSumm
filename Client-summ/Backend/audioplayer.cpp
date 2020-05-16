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
    outAudio = SuperList<QAudioOutput*>();
    //outAudio = new QAudioOutput(format, this);
    player = SuperList<QIODevice*>();
    //player = outAudio->start();
}

void AudioPlayer::appendAudio(QByteArray audio, int index) {
    if(index < player.length() && index >= 0){
        call_void(((QIODevice*)player[index])->write(audio));
    }

}

void AudioPlayer::addPlayer(){
    call_void(outAudio.append(new QAudioOutput(format, this)));
    int idx = outAudio.length()-1;
    call_void(((QAudioOutput*)outAudio[idx])->setVolume(1.0));
    call_void(((QAudioOutput*)outAudio[idx])->setBufferSize(30000));
    call_void(player.append(((QAudioOutput*)outAudio[idx])->start()));
    LOG << "added player" << std::endl;
}
