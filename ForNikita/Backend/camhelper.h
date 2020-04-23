#ifndef CAMHELPER_H
#define CAMHELPER_H

#include <QObject>
#include <QCamera>
#include <QCameraImageCapture>
#include <QBuffer>
namespace Mafia {
class CamHelper : public QObject
{
    Q_OBJECT
public:
    explicit CamHelper(QObject *parent = nullptr);
    QByteArray getFrame();
private:
    QCamera *cam;
    QCameraImageCapture *capt;
    QImage lastFrame;

signals:

};
}
#endif // CAMHELPER_H
