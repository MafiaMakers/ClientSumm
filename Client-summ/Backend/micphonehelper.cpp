#include "micphonehelper.h"
#include <iostream>
using namespace Mafia;
MicphoneHelper::MicphoneHelper(QObject *parent) : QObject(parent)
{
  /*  QAudioDeviceInfo *info = new QAudioDeviceInfo();
    QAudioFormat format;
    format.setSampleRate(8000); //set frequency to 8000
    format.setChannelCount(1); //set channels to mono
    format.setSampleSize(16); //set sample sze to 16 bit
    format.setSampleType(QAudioFormat::UnSignedInt); //Sample type as usigned integer sample
    format.setByteOrder(QAudioFormat::LittleEndian); //Byte order
    format.setCodec("audio/pcm");

    audio = new QAudioInput(format);
    audio->setBufferSize(6000*///);
}

QByteArray MicphoneHelper::getAudio() {
   // return buff->readAll();
    return QByteArray();
}

int MicphoneHelper::bytesCount() {
    return 0;
}

void MicphoneHelper::start() {
   // buff = audio->start();
}

void MicphoneHelper::stop() {

}
