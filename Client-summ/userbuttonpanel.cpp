#include "userbuttonpanel.h"
#include "relativewidget.h"
#include <QPushButton>
#include <QMessageBox>
#include <QFrame>

Mafia::UserButtonPanel::UserButtonPanel(QWidget* parent)
{
    frame = new QFrame(parent);
    frame->setStyleSheet("background-color:grey;");
    exitButton = new QPushButton(parent);
    exitButton->setStyleSheet("color: red;");
    exitButton->setFont(QFont("Times", 15, QFont::Bold));
    microButton = new QPushButton(parent);
    cameraButton = new QPushButton(parent);
    setCamera(true);
    setMicro(true);
    myDimens = QList<double>() << 0 << 0 << 0 << 0;
    winsize = QSize(0, 0);
    exitButton->setGeometry(20, 20, 50, 50);
    exitButton->setText("Выйти");
    connect(exitButton, &QPushButton::clicked, this, &UserButtonPanel::passExit);
    connect(microButton, &QPushButton::clicked, this, &UserButtonPanel::microChanged);
    connect(cameraButton, &QPushButton::clicked, this, &UserButtonPanel::cameraChanged);
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
    emit exitApp();
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
}

void Mafia::UserButtonPanel::setCamera(bool on)
{
    cameraState = on;
    if (on)
        cameraButton->setIcon(iconCameraON);
    else
        cameraButton->setIcon(iconCameraOFF);
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
