#include "videoplayer.h"
using namespace Mafia;
VideoPlayer::VideoPlayer(QWidget *parent)
{
    this->parent = parent;
    this->parBounds = QRect(0, 0, 0, 0);
    this->myDimens = QList<double>() << 0 << 0 << 0 << 0;
    player = new QLabel(parent);
    player->setStyleSheet("background-color: #FFFFFF;"
                          "font-size: 24px;");
    player->setText("Video isn't available");
    player->show();
}

VideoPlayer::~VideoPlayer() {
   // player->setVisible(false);
    delete player;
   // delete parent;
}

void VideoPlayer::updateFrame(QByteArray frame) {
    QPixmap pixmap;
    pixmap.loadFromData(frame, "jpg");
    player->setPixmap(pixmap.scaled(player->size()));
}

void VideoPlayer::setBorder(int bw, QColor ncolor) {
    player->setStyleSheet("border: " + QString::number(bw) + "px solid " + ncolor.name() + ";");
}

void VideoPlayer::setRelatives(QList<double> dimens) {
    myDimens = dimens;
    repaint();
}

void VideoPlayer::updateBounds(QRect nbounds) {
    parBounds = nbounds;
    repaint();
}

void VideoPlayer::repaint() {
    QRect newGeometry = QRect(myDimens[0]*parBounds.width()+parBounds.x(), myDimens[1]*parBounds.height()+parBounds.y(), myDimens[2]*parBounds.width(), myDimens[3]*parBounds   .height());
    player->setGeometry(newGeometry);
}
