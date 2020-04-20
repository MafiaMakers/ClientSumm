#ifndef VIDEOSPACE_H
#define VIDEOSPACE_H
#include <videoplayer.h>

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
    QList<VideoPlayer*> webcams;
    QList<double> myDimens;
    void repaint();
    QSize parSize;
    QWidget *parent;
    int muchPlayers;
};
}

#endif // VIDEOSPACE_H
