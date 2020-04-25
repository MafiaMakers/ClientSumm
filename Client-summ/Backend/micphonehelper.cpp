#include "micphonehelper.h"
#include <iostream>
using namespace Mafia;
MicphoneHelper::MicphoneHelper(QObject *parent) : QObject(parent)
{
    QAudioDeviceInfo *info = new QAudioDeviceInfo();
    QAudioFormat format;
    format.setSampleRate(8000); //set frequency to 8000
    format.setChannelCount(1); //set channels to mono
    format.setSampleSize(16); //set sample sze to 16 bit
    format.setSampleType(QAudioFormat::UnSignedInt ); //Sample type as usigned integer sample
    format.setByteOrder(QAudioFormat::LittleEndian); //Byte order
    format.setCodec("audio/pcm");

    audio = new QAudioInput(info->availableDevices(QAudio::AudioInput)[0], format);
    audio->setBufferSize(2000);
}

QByteArray MicphoneHelper::getAudio(int muchBytes) {
    QByteArray res = whole.left(muchBytes);
    whole = whole.right(whole.size()-muchBytes);
    return res;
}

int MicphoneHelper::bytesCount() {
    whole.append(buff->readAll());
    return whole.size();
}

void MicphoneHelper::start() {
    buff = audio->start();
}

void MicphoneHelper::stop() {

}
