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
    void startGame();
    void gamePause(bool isPaused);
    void endGame();

private slots:
    void passExit();
    void microChanged();
    void cameraChanged();
    void startGameSlot();
    void stopContinueSlot();
    void endGameSlot();

private:
    QFrame * frame;
    QPushButton * exitButton;
    QPushButton * microButton;
    QPushButton * cameraButton;
    QPushButton * startButton;
    QPushButton * endGameButton;
    QPushButton * stopContinueButton;
    QList<double> myDimens;
    QSize winsize;
    bool microState, cameraState;
    int modeGame;
    void repaint();
    const QIcon iconCameraON = QIcon(":/img/Camera_ON"), iconCameraOFF = QIcon(":/img/Camera_OFF"),
            iconMicroON = QIcon(":/img/Microphone_ON"), iconMicroOFF = QIcon(":/img/Microphone_OFF"),
            iconStopGame = QIcon(":/img/StopGameButton.png"), iconContinue = QIcon(":/img/ContinueButton.png"),
            iconEndGame = QIcon(":/img/EndGameButton.png");
};
}

#endif // USERBUTTONPANEL_H
