#ifndef USERBUTTONPANEL_H
#define USERBUTTONPANEL_H

#include <QFrame>
#include <QPushButton>
#include <QLabel>
#include "Calls/SuperList.h"
using namespace SuperFunctions;
namespace Mafia {

class UserButtonPanel: public QObject
{
    Q_OBJECT
public:
    explicit UserButtonPanel(QWidget* parent);
    void setRelatives(SuperList<double> dimens);
    void updateBounds(QSize nsize);
    void setMicro(bool on);
    void setCamera(bool on);
    void showNextStageButton();
    void setCurrentStage(int stateId);
    void startSpeking();
    void setAdminActive(bool isActive);
    void hideSpeakOptions();
    void freeSpeak();

signals:
    void microStatus(bool on);
    void cameraStatus(bool on);
    void exitApp();
    void startGame();
    void gamePause(bool isPaused);
    void endGame();
    void nextStageButtonPressed();
    void stopSpeaking();

private slots:
    void passExit();
    void microChanged();
    void cameraChanged();
    void startGameSlot();
    void stopContinueSlot();
    void endGameSlot();
    void nextStage();
    void stopSpeakingPressed();

private:
    QFrame * frame;
    QPushButton * exitButton;
    QPushButton * microButton;
    QPushButton * cameraButton;
    QPushButton * startButton;
    QPushButton * endGameButton;
    QPushButton * stopContinueButton;
    QPushButton * nextStageButton;
    QPushButton * stopSpeakButton;
    QLabel * currentGameStateLabel;
    SuperList<double> myDimens;
    QSize winsize;
    bool microState, cameraState;
    int modeGame;
    int stage = 0;
    void repaint();
    const QIcon iconCameraON = QIcon(":UserPanel/img/Camera_ON"), iconCameraOFF = QIcon(":UserPanel/img/Camera_OFF"),
            iconMicroON = QIcon(":UserPanel/img/Microphone_ON"), iconMicroOFF = QIcon(":UserPanel/img/Microphone_OFF"),
            iconStopGame = QIcon(":UserPanel/img/StopGameButton.png"), iconContinue = QIcon(":UserPanel/img/ContinueButton.png"),
            iconEndGame = QIcon(":UserPanel/img/EndGameButton.png");
};
}

#endif // USERBUTTONPANEL_H
