#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QObject>
#include <QLabel>
namespace Mafia {
class VideoPlayer : public QObject
{
    Q_OBJECT
public:
    explicit VideoPlayer(QWidget *parent, QObject *cringe = nullptr);
    void setGeometry(int x, int y, int w, int h);
    void setBorder(int bw, QColor ncolor);
    void updateFrame(QByteArray frame);
private:
    int w, h;
    QColor borderColor;
    QWidget *parent;
    QLabel *player;
signals:

};
}

#endif // VIDEOPLAYER_H
