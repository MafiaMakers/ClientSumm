
#include "userbuttonpanel.h"
#include <QPushButton>
#include <iostream>
#include "Network/defines_c.h"
Mafia::UserButtonPanel::UserButtonPanel(QWidget* parent)
{

    frame = new QFrame(parent);
    frame->setStyleSheet("background-color:grey;");
    currentGameStateLabel = new QLabel("Текущая стадия : ожидание игроков", parent);
    currentGameStateLabel->setGeometry(170, 70, 500, 30);
    currentGameStateLabel->setAlignment(Qt::AlignCenter);
    currentGameStateLabel->setStyleSheet("background-color: #FFFFFF;"
                            "font-size: 20px;");
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
    myDimens = SuperList<double>() << 0 << 0 << 0 << 0;

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
    call_void(emit stopSpeaking());
}

void Mafia::UserButtonPanel::hideSpeakOptions() {
    call_void(stopSpeakButton->hide());
    call_void(microButton->setEnabled(false));
}

void Mafia::UserButtonPanel::setAdminActive(bool isActive) {
    if(stage == WAITING_STAGE) {
        call_void(startButton->setVisible(isActive));
    }
}

void Mafia::UserButtonPanel::startSpeking(){
    call_void(stopSpeakButton->show());
    call_void(microButton->setEnabled(true));
}

void Mafia::UserButtonPanel::setRelatives(SuperList<double> dimens)
{
    call_void(myDimens = dimens);
    call_void(repaint());
}

void Mafia::UserButtonPanel::updateBounds(QSize nsize)
{
    winsize = nsize;
    call_void(repaint());
}

void Mafia::UserButtonPanel::passExit()
{
    call_void(exitButton->hide());
    call_void(exitButton->show());
    call_void(emit exitApp());
}

void Mafia::UserButtonPanel::nextStage(){
    call_void(nextStageButton->hide());
    call_void(emit nextStageButtonPressed());
}

void Mafia::UserButtonPanel::showNextStageButton(){
    call_void(nextStageButton->show());
    call_void(startButton->hide());
}

void Mafia::UserButtonPanel::repaint()
{
    call_void(int myWidth = myDimens[2] * winsize.width());
    call_void(int myHeight = myDimens[3] * winsize.height());
    call_void(int myX = myDimens[0] * winsize.width());
    call_void(int myY = myDimens[1] * winsize.height());
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
    currentGameStateLabel->setGeometry((myWidth - 540)*(myWidth >= 545)+myX+5, myY + 10, 395*(myWidth >= 400)+(myWidth-10)*(myWidth < 400), myHeight - 20);
}

void Mafia::UserButtonPanel::setCamera(bool on)
{
    cameraState = on;
    if (on){
        call_void(cameraButton->setIcon(iconCameraON));
    }
    else{
        call_void(cameraButton->setIcon(iconCameraOFF));
    }
}

void Mafia::UserButtonPanel::setCurrentStage(int stateId){
    stage = stateId;
    SuperList<QString> stateNames = SuperList<QString>() << "ожидание других игроков" << "свободный разговор"
                                            << "ночь" << "стадия аргументации" << "стадия повешанья" << "результаты";
    call_void(currentGameStateLabel->setText("Текущая стадия : " + stateNames[stateId]));
}

void Mafia::UserButtonPanel::setMicro(bool on)
{
    microState = on;
    if (on){
        call_void(microButton->setIcon(iconMicroON));
    }
    else{
        call_void(microButton->setIcon(iconMicroOFF));
    }
}

void Mafia::UserButtonPanel::cameraChanged()
{
    if (cameraState)
    {
        cameraState = false;
        call_void(cameraButton->setIcon(iconCameraOFF));
        call_void(emit cameraStatus(false));
    }
    else
    {
        cameraState = true;
        call_void(cameraButton->setIcon(iconCameraON));
        call_void(emit cameraStatus(true));
    }
}

void Mafia::UserButtonPanel::microChanged()
{
    if (microState)
    {
        microState = false;
        call_void(microButton->setIcon(iconMicroOFF));
        call_void(emit microStatus(false));
    }
    else
    {
        microState = true;
        call_void(microButton->setIcon(iconMicroON));
        call_void(emit microStatus(true));
    }
}

void Mafia::UserButtonPanel::startGameSlot()
{
    std::cout << "QWERTYU" << std::endl;
    modeGame = 1;
    call_void(startButton->close());
    call_void(emit startGame());
    call_void(stopContinueButton->setIcon(iconStopGame));
    //stopContinueButton->show();
    //endGameButton->show();
}

void Mafia::UserButtonPanel::stopContinueSlot()
{
    if (modeGame == 1)
    {
        modeGame = 2;
        call_void(emit gamePause(true));
        call_void(stopContinueButton->setIcon(iconContinue));
    }
    else
    {
        modeGame = 1;
        call_void(emit gamePause(false));
        call_void(stopContinueButton->setIcon(iconStopGame));
    }
}

void Mafia::UserButtonPanel::endGameSlot()
{
    modeGame = 0;
    call_void(emit endGame());
    call_void(startButton->show());
    call_void(stopContinueButton->hide());
    call_void(endGameButton->hide());
}
