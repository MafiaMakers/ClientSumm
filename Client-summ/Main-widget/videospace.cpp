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

void VideoSpace::setPlayersCount(int count,  SuperList<QString> names) {
    while(webcams.length() > 0) {
        call_void(((VideoPlayer*)webcams.getLast())->hide());
        call_void(delete ((VideoPlayer*)webcams.getLast()));
        call_void(webcams.pop(webcams.length()-1));
    }
    muchPlayers = count;
    double k = 1.5;
    int wc = 0, hc = 0, margin = 10, wp = 0, hp = 0;
    call_void(int myWidth = myDimens[2]*parSize.width());
    call_void(int myHeight = myDimens[3]*parSize.height());
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
        call_void(webcams.append(new VideoPlayer(parent)));
        int xc = i % wc, yc = i / wc;
        SuperList<double> rels;
        call(SuperList<double>() << (xc*(wp+margin)+margin)/(double)myWidth << (yc*(hp+margin)+margin)/(double)myHeight << wp/(double)myWidth << hp/(double)myHeight, &rels);
        call_void(((VideoPlayer*)webcams[i])->setRelatives(rels));
        std::cout << "before" << std::endl;
        call_void(((VideoPlayer*)webcams[i])->setNumPlayer(i + 1));

        if(names.length() > 0){
            call_void(((VideoPlayer*)webcams[i])->setName(names[i]));
        }
        std::cout << "after" << std::endl;
//        webcams[i]->setVotesCount(i - 1);
//        webcams[i]->setVoteOn(i + 1);
//        webcams[i]->startVoting();
        call_void(((VideoPlayer*)webcams[i])->updateBounds(QRect(myDimens[0]*parSize.width(), myDimens[1]*parSize.height(), myWidth, myHeight)));
        connect(((VideoPlayer*)webcams[i]), &VideoPlayer::vote, this, &VideoSpace::voteSlot);
    }
    std::cout << "repainting" << std::endl;
    call_void(repaint());
    std::cout << "well" << std::endl;
}

void VideoSpace::setName(QString name, int index){
    call_void(((VideoPlayer*)webcams[index])->setName(name));
}

void VideoSpace::setRelatives(SuperList<double> dimens) {
    call_void(myDimens = dimens);
    call_void(repaint());
}

void VideoSpace::updateBounds(QSize nsize) {
    parSize = nsize;
    call_void(repaint());
}

void VideoSpace::addVoter(int voter, int votedFor){
    std::cout << "made vote made" << std::endl;
    call_void(((VideoPlayer*)webcams[voter])->setVoteOn(votedFor + 1));
    call_void(((VideoPlayer*)webcams[votedFor])->raiseVotings());
}

void VideoSpace::repaint() {
    //don't clear like in setPlayersCount
    double k = 1.2;
    int wc = 0, hc = 0, margin = 10, wp = 0, hp = 0;
    call_void(int myWidth = myDimens[2]*parSize.width());
    call_void(int myHeight = myDimens[3]*parSize.height());
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
        SuperList<double> rels;
        call(SuperList<double>() << (xc*(wp+margin)+margin)/(double)myWidth << (yc*(hp+margin)+margin)/(double)myHeight << wp/(double)myWidth << hp/(double)myHeight, &rels);
        call_void(((VideoPlayer*)webcams[i])->setRelatives(rels));
        call_void(((VideoPlayer*)webcams[i])->updateBounds(QRect(myDimens[0]*parSize.width(), myDimens[1]*parSize.height(), myWidth, myHeight)));
    }
}

void VideoSpace::kill(int index){
    call_void(((VideoPlayer*)webcams[index])->killPlayer(true));
}

void VideoSpace::updateFrame(int idx, QByteArray frame) {
    call_void(((VideoPlayer*)webcams[idx])->updateFrame(frame));
}

void VideoSpace::startGame()
{
    for (int i = 0; i < muchPlayers; i++) {
        call_void(((VideoPlayer*)webcams[i])->killPlayer(false));
    }
}

void VideoSpace::voteSlot(int index)
{
    if(curVotePlayer == -1){
        call_void(endVotingForPlayer());
    }
    //startVoting(curVotePlayer + 1);
    call_void(emit vote(index));
}

void VideoSpace::startVoting(int player, QString action)
{

    if (curVotePlayer > 0) {
        //webcams[curVotePlayer - 1]->setVotesCount(curVotes);
    }
    curVotes = 0;
    curVotePlayer = player;
    call_void(((VideoPlayer*)webcams[player - 1])->startVoting(action));
}

void VideoSpace::setCanVote(int player, bool yes)
{
    call_void(((VideoPlayer*)webcams[player - 1])->setCanVote(yes));
}

void VideoSpace::endVotingForPlayer(){
    for(int i = 0; i < muchPlayers; i++){
        call_void(((VideoPlayer*)webcams[i])->setVoteOn(0));
        call_void(((VideoPlayer*)webcams[i])->setVotesCount(0));
        call_void(((VideoPlayer*)webcams[i])->endVoting());
    }
}

void VideoSpace::startAllVoting(QString action){
    for(int i = 0; i < muchPlayers; i++){
        bool cond;
        call(((VideoPlayer*)webcams[i])->isAlive(), &cond);
        if(cond){
            call_void(startVoting(i+1, action));
        }
    }
    curVotes = 0;
    curVotePlayer = -1;
}

