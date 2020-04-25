#include "audioplayer.h"
#include <iostream>
using namespace Mafia;
AudioPlayer::AudioPlayer(QObject *parent) : QObject(parent)
{
    QAudioDeviceInfo *info = new QAudioDeviceInfo();
    whole = new QByteArray();
    QAudioFormat format = info->availableDevices(QAudio::AudioOutput)[0].preferredFormat();
   // std::cout << "Output format prefered: " << format.channelCount() << " " << format.sampleRate() << " " << format.sampleSize() << " " << format.codec().toStdString() << " " << format.byteOrder() << " " <<format.sampleType() << std::endl;
    format.setChannelCount(1);
    format.setSampleRate(8000);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);
//    format.setChannelCount(2);
//    format.setSampleRate(11025);
//    format.setSampleSize(16);
//    format.setCodec("audio/pcm");
//    format.setByteOrder(QAudioFormat::LittleEndian);
//    format.setSampleType(QAudioFormat::SignedInt);
    outAudio = new QAudioOutput(format, this);
    outAudio->setVolume(1.0);
    outAudio->setBufferSize(30000);
    player = outAudio->start();
    connect(outAudio, &QAudioOutput::stateChanged, this, &AudioPlayer::stch);
    std::cout << "Player support: " << info->availableDevices(QAudio::AudioOutput)[0].isFormatSupported(format) << std::endl;
    std::cout << "Interrupt state: " << QAudio::InterruptedState << std::endl;
    std::cout << "Stop state: " << QAudio::StoppedState << std::endl;
    std::cout << "Active state: " << QAudio::ActiveState << std::endl;
    std::cout << "Suspend state: " << QAudio::SuspendedState << std::endl;
    std::cout << "Just state: " << QAudio::State() << std::endl;
    std::cout << "Idle state: " << QAudio::IdleState << std::endl;
}

void AudioPlayer::appendAudio(QByteArray audio) {
    //outAudio->setBufferSize(audio.size());

    player->write(audio);
    //outAudio->start();
    //std::cout << "Whole size: " <<player->size() << std::endl;
}

void AudioPlayer::stch(QAudio::State ns) {
    //std::cout << "New state: " << ns << std::endl;
}
