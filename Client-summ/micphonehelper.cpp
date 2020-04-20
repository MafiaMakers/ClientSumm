#include "micphonehelper.h"
using namespace Mafia;
MicphoneHelper::MicphoneHelper(QObject *parent) : QObject(parent)
{
    QAudioDeviceInfo *info = new QAudioDeviceInfo();
    QAudioFormat format;
    format.setChannelCount(2);
    format.setSampleRate(11025);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::SignedInt);
    audio = new QAudioInput(info->availableDevices(QAudio::AudioInput)[0], format);
    audio->setBufferSize(4000);
    buff = audio->start();
}

QByteArray MicphoneHelper::getAudio() {
    return buff->readAll();
}
