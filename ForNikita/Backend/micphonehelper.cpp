#include "micphonehelper.h"
#include <iostream>
using namespace Mafia;
MicphoneHelper::MicphoneHelper(QObject *parent) : QObject(parent)
{
    QAudioDeviceInfo *info = new QAudioDeviceInfo();
    QAudioFormat format = info->availableDevices(QAudio::AudioInput)[0].preferredFormat();
    //std::cout << "Input format prefered: " << format.channelCount() << " " << format.sampleRate() << " " << format.sampleSize() << " " << format.codec().toStdString() << " " << format.byteOrder() << " " <<format.sampleType() << std::endl;
    format.setChannelCount(1);
    format.setSampleRate(8000);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);
    audio = new QAudioInput(info->availableDevices(QAudio::AudioInput)[0], format);
    audio->setBufferSize(2000);
    buff = audio->start();
    std::cout << "Microphone support: " << info->availableDevices(QAudio::AudioInput)[0].isFormatSupported(format) << std::endl;
}

QByteArray MicphoneHelper::getAudio() {
    return buff->readAll();
}
