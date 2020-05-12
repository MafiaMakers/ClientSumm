#include "camhelper.h"
using namespace Mafia;
CamHelper::CamHelper(QObject *parent) : QObject(parent)
{

}
//    lastFrame = QImage(0, 0);

//    cam = new QCamera;
//    cam->setCaptureMode(QCamera::CaptureStillImage);

//    capt = new QCameraImageCapture(cam);
//    capt->setCaptureDestination(QCameraImageCapture::CaptureToBuffer);

//    QImageEncoderSettings setts = capt->encodingSettings();
//    setts.setResolution(320, 240);
//    capt->setEncodingSettings(setts);

//    QObject::connect(capt, &QCameraImageCapture::imageCaptured, [=] (int id, QImage img) {
//        lastFrame = img;
//    });

//    QObject::connect(capt, &QCameraImageCapture::readyForCaptureChanged, [=] (bool state) {
//       if(state == true) {
//           cam->searchAndLock();
//           capt->capture();
//           cam->unlock();
//       }
//    });
//    //am->start();
QByteArray CamHelper::getFrame() {;
    QByteArray toSend;
    QBuffer buffer(&toSend);
    buffer.open(QIODevice::ReadWrite);
    lastFrame.mirrored(true, false).scaled(160, 120 ).save(&buffer, "jpg");
    return toSend;
}
