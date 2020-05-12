#include "userbuttonpanel.h"
#include <QPushButton>
#include <iostream>
#include "Network/defines_c.h"
Mafia::UserButtonPanel::UserButtonPanel(QWidget* parent)
{
    frame = new QFrame(parent);
    frame->setStyleSheet("background-color:grey;");
    exitButton = new QPushButton(parent);
    exitButton->setStyleSheet("color: red;");
    exitButton->setFont(QFont("Times", 15, QFont::Bold));
    microButton = new QPushButton(parent);
    cameraButton = new QPushButton(parent);
    startButton = new QPushButton(parent);
    startButton->setText("Начать игру");
    startButton->setStyleSheet("color: blue;");
    startButton->setFont(QFont("Times", 15, QFont::Bold));
    stopContinueButton = new QPushButton(parent);
    stopContinueButton->setIcon(iconStopGame);
    endGameButton = new QPushButton(parent);
    endGameButton->setIcon(iconEndGame);
    modeGame = 0;
    stopContinueButton->hide();
    endGameButton->hide();
    setCamera(true);
    setMicro(true);
    myDimens = QList<double>() << 0 << 0 << 0 << 0;

    currentGameStateLabel = new QLabel("Текущая стадия : ожидание игроков", parent);
    currentGameStateLabel->setGeometry(170, 70, 500, 30);
    currentGameStateLabel->setAlignment(Qt::AlignCenter);
    currentGameStateLabel->setStyleSheet("background-color: #FFFFFF;"
                            "font-size: 20px;");
    winsize = QSize(0, 0);
    exitButton->setGeometry(20, 20, 50, 50);
    exitButton->setText("Выйти");

    nextStageButton = new QPushButton(parent);
    nextStageButton->setText("Перейти к ночи");
    nextStageButton->setStyleSheet("color: blue;");
    nextStageButton->setFont(QFont("Times", 15, QFont::Bold));
    nextStageButton->hide();

    stopSpeakButton = new QPushButton(parent);
    stopSpeakButton->setText("Завершить речь");
    stopSpeakButton->setStyleSheet("color: blue;");
    stopSpeakButton->setFont(QFont("Times", 15, QFont::Bold));
    stopSpeakButton->hide();

    connect(exitButton, &QPushButton::clicked, this, &UserButtonPanel::passExit);
    connect(microButton, &QPushButton::clicked, this, &UserButtonPanel::microChanged);
    connect(cameraButton, &QPushButton::clicked, this, &UserButtonPanel::cameraChanged);
    connect(startButton, &QPushButton::clicked, this, &UserButtonPanel::startGameSlot);
    connect(stopContinueButton, &QPushButton::clicked, this, &UserButtonPanel::stopContinueSlot);
    connect(endGameButton, &QPushButton::clicked, this, &UserButtonPanel::endGameSlot);
    connect(nextStageButton, &QPushButton::clicked, this, &UserButtonPanel::nextStage);
    connect(stopSpeakButton, &QPushButton::clicked, this, &UserButtonPanel::stopSpeakingPressed);
}

void Mafia::UserButtonPanel::stopSpeakingPressed(){
    stopSpeakButton->hide();
    emit stopSpeaking();
}

void Mafia::UserButtonPanel::setAdminActive(bool isActive) {
    startButton->setVisible(isActive);
}

void Mafia::UserButtonPanel::startSpeking(){
    stopSpeakButton->show();
}

void Mafia::UserButtonPanel::setRelatives(QList<double> dimens)
{
    myDimens = dimens;
    repaint();
}

void Mafia::UserButtonPanel::updateBounds(QSize nsize)
{
    winsize = nsize;
    repaint();
}

void Mafia::UserButtonPanel::passExit()
{
    exitButton->hide();
    exitButton->show();
    emit exitApp();
}

void Mafia::UserButtonPanel::nextStage(){
    nextStageButton->hide();
    emit nextStageButtonPressed();
}

void Mafia::UserButtonPanel::showNextStageButton(){
    nextStageButton->show();
}

void Mafia::UserButtonPanel::repaint()
{
    int myWidth = myDimens[2] * winsize.width(), myHeight = myDimens[3] * winsize.height();
    int myX = myDimens[0] * winsize.width(), myY = myDimens[1] * winsize.height();
    frame->setGeometry(myX, myY, myWidth, myHeight);
    exitButton->setGeometry(myX + myWidth - 110, myY + 10, 100, myHeight - 20);
    microButton->setGeometry(myX + 10, myY + 10, myHeight - 20, myHeight - 20);
    microButton->setIconSize(QSize((myHeight - 20) * 0.9, (myHeight - 20) * 0.8));
    cameraButton->setGeometry(myX + myHeight, myY + 10, myHeight - 20, myHeight - 20);
    cameraButton->setIconSize(QSize((myHeight - 20) * 0.9, (myHeight - 20) * 0.8));
    startButton->setGeometry(myX + 2 * myHeight, myY + 10, 150, myHeight - 20);
    nextStageButton->setGeometry(myX + 2 * myHeight, myY + 10, 200, myHeight - 20);
    stopSpeakButton->setGeometry(myX + 2 * myHeight, myY + 10, 200, myHeight - 20);
    stopContinueButton->setGeometry(myX + 2 * myHeight, myY + 10, myHeight - 20, myHeight - 20);
    stopContinueButton->setIconSize(QSize((myHeight - 20) * 0.8, (myHeight - 20) * 0.8));
    endGameButton->setGeometry(myX + 3 * myHeight - 10, myY + 10, myHeight - 20, myHeight - 20);
    endGameButton->setIconSize(QSize((myHeight - 20) * 0.8, (myHeight - 20) * 0.8));
    currentGameStateLabel->setGeometry(myX + myWidth - 540, myY + 10, 400, myHeight - 20);
}

void Mafia::UserButtonPanel::setCamera(bool on)
{
    cameraState = on;
    if (on)
        cameraButton->setIcon(iconCameraON);
    else
        cameraButton->setIcon(iconCameraOFF);
}

void Mafia::UserButtonPanel::setCurrentStage(int stateId){
    QList<QString> stateNames = QList<QString>() << "ожидание других игроков" << "свободный разговор"
                                            << "ночь" << "стадия аргументации" << "стадия повешанья" << "результаты";
    currentGameStateLabel->setText("Текущая стадия : " + stateNames[stateId]);
    if(stateId == SPEAKING_STAGE){
        nextStageButton->show();
        startButton->hide();
    }
}

void Mafia::UserButtonPanel::setMicro(bool on)
{
    microState = on;
    if (on)
        microButton->setIcon(iconMicroON);
    else
        microButton->setIcon(iconMicroOFF);
}

void Mafia::UserButtonPanel::cameraChanged()
{
    if (cameraState)
    {
        cameraState = false;
        cameraButton->setIcon(iconCameraOFF);
        emit cameraStatus(false);
    }
    else
    {
        cameraState = true;
        cameraButton->setIcon(iconCameraON);
        emit cameraStatus(true);
    }
}

void Mafia::UserButtonPanel::microChanged()
{
    if (microState)
    {
        microState = false;
        microButton->setIcon(iconMicroOFF);
        emit microStatus(false);
    }
    else
    {
        microState = true;
        microButton->setIcon(iconMicroON);
        emit microStatus(true);
    }
}

void Mafia::UserButtonPanel::startGameSlot()
{
    modeGame = 1;
    emit startGame();
    startButton->close();
    stopContinueButton->setIcon(iconStopGame);
    //stopContinueButton->show();
    //endGameButton->show();
}

void Mafia::UserButtonPanel::stopContinueSlot()
{
    if (modeGame == 1)
    {
        modeGame = 2;
        emit gamePause(true);
        stopContinueButton->setIcon(iconContinue);
    }
    else
    {
        modeGame = 1;
        emit gamePause(false);
        stopContinueButton->setIcon(iconStopGame);
    }
}

void Mafia::UserButtonPanel::endGameSlot()
{
    modeGame = 0;
    emit endGame();
    startButton->show();
    stopContinueButton->hide();
    endGameButton->hide();
}
