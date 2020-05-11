#include "videospace.h"
#include <iostream>
#include <cmath>
using namespace Mafia;
VideoSpace::VideoSpace(QWidget *parent)
{
    this->parent = parent;
    muchPlayers = 0;
    curVotePlayer = 0;
    curVotes = 0;
}

void VideoSpace::setPlayersCount(int count) {
    while(webcams.size() > 0) {
        delete webcams.last();
        webcams.pop_back();
    }
    muchPlayers = count;
    double k = 1.5;
    int wc = 0, hc = 0, margin = 10, wp = 0, hp = 0;
    int myWidth = myDimens[2]*parSize.width(), myHeight = myDimens[3]*parSize.height();
    while(wc*hc < muchPlayers) {
        wc += 1;
        wp = myWidth/wc - margin;
        hp = wp/k;
        hc = myHeight/(hp+margin);
    }
    const int wc_buf = wc, wp_buf = wp;
    wc = 0;
    hc = 0;
    wp = 0;
    hp = 0;
    while(wc*hc < muchPlayers) {
        hc += 1;
        hp = myHeight/hc - margin;
        wp = hp*k;
        wc = myWidth/(wp+margin);
    }
    if (wp_buf > wp) {
        wc = wc_buf;
        wp = wp_buf;
        hp = wp/k;
        hc = myHeight/(hp+margin);
    }
    for(int i = 0; i < count; i++) {
        webcams.append(new VideoPlayer(parent));
        int xc = i % wc, yc = i / wc;
        QList<double> rels = QList<double>() << (xc*(wp+margin)+margin)/(double)myWidth << (yc*(hp+margin)+margin)/(double)myHeight << wp/(double)myWidth << hp/(double)myHeight;
        webcams[i]->setRelatives(rels);
        webcams[i]->setNumPlayer(i + 1);
//        webcams[i]->setVotesCount(i - 1);
//        webcams[i]->setVoteOn(i + 1);
//        webcams[i]->startVoting();
        webcams[i]->updateBounds(QRect(myDimens[0]*parSize.width(), myDimens[1]*parSize.height(), myWidth, myHeight));
        connect(webcams[i], &VideoPlayer::vote, this, &VideoSpace::voteSlot);
    }
    repaint();
}

void VideoSpace::setRelatives(QList<double> dimens) {
    myDimens = dimens;
    repaint();
}

void VideoSpace::updateBounds(QSize nsize) {
    parSize = nsize;
    repaint();
}

void VideoSpace::addVoter(int voter, int votedFor){
    if(curVotePlayer == votedFor){
        webcams[voter]->setVoteOn(votedFor+1);
        webcams[votedFor]->setVotesCount(++curVotes);
    }
}

void VideoSpace::repaint() {
    //don't clear like in setPlayersCount
    double k = 1.2;
    int wc = 0, hc = 0, margin = 10, wp = 0, hp = 0;
    int myWidth = myDimens[2]*parSize.width(), myHeight = myDimens[3]*parSize.height();
    while(wc*hc < muchPlayers) {
        wc += 1;
        wp = myWidth/wc - margin;
        hp = wp/k;
        hc = myHeight/(hp+margin);
    }
    const int wc_buf = wc, wp_buf = wp;
    wc = 0;
    hc = 0;
    wp = 0;
    hp = 0;
    while(wc*hc < muchPlayers) {
        hc += 1;
        hp = myHeight/hc - margin;
        wp = hp*k;
        wc = myWidth/(wp+margin);
    }
    if (wp_buf > wp) {
        wc = wc_buf;
        wp = wp_buf;
        hp = wp/k;
        hc = myHeight/(hp+margin);
    }
    for(int i = 0; i < muchPlayers; i++) {
        //and don't append new VideoPlayers
        int xc = i % wc, yc = i / wc;
        QList<double> rels = QList<double>() << (xc*(wp+margin)+margin)/(double)myWidth << (yc*(hp+margin)+margin)/(double)myHeight << wp/(double)myWidth << hp/(double)myHeight;
        webcams[i]->setRelatives(rels);
        webcams[i]->updateBounds(QRect(myDimens[0]*parSize.width(), myDimens[1]*parSize.height(), myWidth, myHeight));
    }
}

void VideoSpace::updateFrame(int idx, QByteArray frame) {
    webcams[idx]->updateFrame(frame);
}

void VideoSpace::startGame()
{
    for (int i = 0; i < muchPlayers; i++) {
        webcams[i]->killPlayer(false);
    }
}

void VideoSpace::voteSlot(int index)
{
    curVotes++;
    endVoting();
    //startVoting(curVotePlayer + 1);
    emit vote(index);
}

void VideoSpace::startVoting(int player, QString action)
{

    if (curVotePlayer > 0) {
        webcams[curVotePlayer - 1]->setVotesCount(curVotes);
    }
    curVotes = 0;
    curVotePlayer = player;
    webcams[player - 1]->startVoting(action);
}

void VideoSpace::setCanVote(int player, bool yes)
{
    webcams[player - 1]->setCanVote(yes);
}

void VideoSpace::endVoting()
{
    if (curVotePlayer > 0)
        webcams[curVotePlayer - 1]->setVotesCount(curVotes);
}

void VideoSpace::startAllVoting(QString action){
    for(int i = 0; i < muchPlayers; i++){
        startVoting(i+1, action);
    }
    curVotes = 0;
    curVotePlayer = -1;
}

