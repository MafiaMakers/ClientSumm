#ifndef VIDEOSPACE_H
#define VIDEOSPACE_H
#include "videoplayer.h"

namespace Mafia {
class VideoSpace
{
public:
    VideoSpace(QWidget *parent);
    void setPlayersCount(int count);
    void updateBounds(QSize nsize);
    void setRelatives(QList<double> dimens);
    void updateFrame(int idx, QByteArray frame);
private:
    QSize parSize;
    QList<double> myDimens;
    void repaint();
    QWidget *parent;
    QList<VideoPlayer*> webcams;
    int muchPlayers;
};
}

#endif // VIDEOSPACE_H
