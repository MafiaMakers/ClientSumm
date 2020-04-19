#include "videoplayer.h"
using namespace Mafia;
VideoPlayer::VideoPlayer(QWidget *parent, QObject *cringe) : QObject(cringe)
{
    this->parent = parent;
    player = new QLabel(parent);
    setGeometry(10, 10, 10, 10);
}
void VideoPlayer::setGeometry(int x, int y, int w, int h) {
    this->w = w;
    this->h = h;
    player->setGeometry(x, y, w, h);
}

void VideoPlayer::updateFrame(QByteArray frame) {
    QPixmap pixmap;
    pixmap.loadFromData(frame, "jpg");
    player->setPixmap(pixmap.scaled(w, h));
}

void VideoPlayer::setBorder(int bw, QColor ncolor) {
    player->setStyleSheet("border: " + QString::number(bw) + "px solid " + ncolor.name() + ";");
}
