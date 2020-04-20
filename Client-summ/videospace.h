#ifndef VIDEOSPACE_H
#define VIDEOSPACE_H
#include <relativewidget.h>
#include <videoplayer.h>

namespace Mafia {
class VideoSpace : public RelativeWidget
{
public:
    VideoSpace(QWidget *parent);
    virtual void setPlayersCount(int count) override;
    virtual void updateBounds(QSize nsize) override;
    virtual void setRelatives(QList<double> dimens) override;
    virtual void updateFrame(int idx, QByteArray frame) override;
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
