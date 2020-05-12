#ifndef VIDEOSPACE_H
#define VIDEOSPACE_H
#include "videoplayer.h"

namespace Mafia {
class VideoSpace: public QObject
{
    Q_OBJECT
public:
    VideoSpace(QWidget *parent);
    void setPlayersCount(int count);
    void updateBounds(QSize nsize);
    void setRelatives(QList<double> dimens);
    void updateFrame(int idx, QByteArray frame);

    void startGame();
    void startVoting(int player, QString action);
    void endVotingForPlayer();

    void startAllVoting(QString action);
    void setCanVote(int player, bool yes);
    void kill(int index);
    void addVoter(int voter, int votedFor);

signals:
    void vote(int player);

private:
    QSize parSize;
    QList<double> myDimens;
    void repaint();
    QWidget *parent;
    QList<VideoPlayer*> webcams;
    int muchPlayers;

    int curVotePlayer;
    int curVotes;

private slots:
    void voteSlot(int myIdx);
};
}

#endif // VIDEOSPACE_H
