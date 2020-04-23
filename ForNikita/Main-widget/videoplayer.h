#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QObject>
#include <QLabel>

namespace Mafia {
class VideoPlayer
{
public:
    explicit VideoPlayer(QWidget *parent);
    ~VideoPlayer();
    void setBorder(int bw, QColor ncolor);
    void updateFrame(QByteArray frame);
    void updateBounds(QRect nbounds);
    void setRelatives(QList<double> dimens);
private:
    int w, h;
    QColor borderColor;
    QWidget *parent;
    QLabel *player;
    QList<double> myDimens;
    QRect parBounds;

    void repaint();
signals:

};
}

#endif // VIDEOPLAYER_H
