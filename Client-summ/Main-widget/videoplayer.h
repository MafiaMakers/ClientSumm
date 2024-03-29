#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QObject>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

#include "Calls/SuperList.h"

using namespace SuperFunctions;

namespace Mafia {
class VideoPlayer: public QObject
{
    Q_OBJECT
public:
    explicit VideoPlayer(QWidget *parent);
    ~VideoPlayer();
    void setBorder(int bw, QColor ncolor);
    void updateFrame(QByteArray frame);
    void updateBounds(QRect nbounds);
    void setRelatives(SuperList<double> dimens);
    void setNumPlayer(int num);
    void endVoting();
    void setVotesCount(int votes);
    void startVoting(QString action = "Убить");
    void setVoteOn(int player);
    void killPlayer(bool is_died=true);
    void setCanVote(bool yes);
    void raiseVotings();
    bool isAlive();
    void setName(QString name);
    void hide();
    void hideButton();
signals:
    void vote(int myIdx);

private:
    int w, h;
    QColor borderColor;
    QWidget *parent;
    QLabel *player;
    SuperList<double> myDimens;
    QRect parBounds;
    QLabel *textPlayer;
    QLabel *textVotes;
    QLabel *textVoteOn;
    QPushButton *voteButton;
    bool canVote;
    int myIndex;
    int votesForMe = 0;
    bool alive = true;
    QTimer *timer;

    void repaint();

private slots:
    void voteSlot();
    void noVideoSlot();

};
}

#endif // VIDEOPLAYER_H
