#ifndef USERBUTTONPANEL_H
#define USERBUTTONPANEL_H

#include <QFrame>
#include <QPushButton>

namespace Mafia {

class UserButtonPanel: public QObject
{
    Q_OBJECT
public:
    explicit UserButtonPanel(QWidget* parent);
     void setRelatives(QList<double> dimens);
     void updateBounds(QSize nsize);
     void setMicro(bool on);
     void setCamera(bool on);

signals:
    void microStatus(bool on);
    void cameraStatus(bool on);
    void exitApp();

private slots:
    void passExit();
    void microChanged();
    void cameraChanged();

private:
    QFrame * frame;
    QPushButton * exitButton;
    QPushButton * microButton;
    QPushButton * cameraButton;
    QList<double> myDimens;
    QSize winsize;
    bool microState, cameraState;
    void repaint();
    const QIcon iconCameraON = QIcon(":/Camera_ON"), iconCameraOFF = QIcon(":/Camera_OFF"),
            iconMicroON = QIcon(":/Microphone_ON"), iconMicroOFF = QIcon(":/Microphone_OFF");
};
}

#endif // USERBUTTONPANEL_H
