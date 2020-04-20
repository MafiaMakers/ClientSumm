#include "videospace.h"
using namespace Mafia;
VideoSpace::VideoSpace(QWidget *parent)
{
    this->parent = parent;
    muchPlayers = 0;
}

void VideoSpace::setPlayersCount(int count) {
    muchPlayers = count;
    webcams.clear();
    double k = 1.5;
    int wc = 0, hc = 0, margin = 10, wp = 0, hp = 0;
    int myWidth = myDimens[2]*parSize.width(), myHeight = myDimens[3]*parSize.height();
    while(wc*hc < count) {
        wc += 1;
        wp = myWidth/wc - margin;
        hp = wp/k;
        hc = myHeight/(hp+margin);
    }
    for(int i = 0; i < count; i++) {
        webcams.append(new VideoPlayer(parent));
        int xc = i % wc, yc = i / wc;
        QList<double> rels = QList<double>() << (xc*(wp+margin)+margin)/(double)myWidth << (yc*(hp+margin)+margin)/(double)myHeight << wp/(double)myWidth << hp/(double)myHeight;
        webcams[i]->setRelatives(rels);
        webcams[i]->updateBounds(QRect(myDimens[0]*parSize.width(), myDimens[1]*parSize.height(), myWidth, myHeight));
    }
}

void VideoSpace::setRelatives(QList<double> dimens) {
    myDimens = dimens;
    repaint();
}

void VideoSpace::updateBounds(QSize nsize) {
    parSize = nsize;
    repaint();
}

void VideoSpace::repaint() {
    //don't clear like in setPlayersCount
    double k = 1.5;
    int wc = 0, hc = 0, margin = 10, wp = 0, hp = 0;
    int myWidth = myDimens[2]*parSize.width(), myHeight = myDimens[3]*parSize.height();
    while(wc*hc < muchPlayers) {
        wc += 1;
        wp = myWidth/wc - margin;
        hp = wp/k;
        hc = myHeight/(hp+margin);
    }
    for(int i = 0; i < muchPlayers; i++) {
        //and don't append new VideoPl ayers
        int xc = i % wc, yc = i / wc;
        QList<double> rels = QList<double>() << (xc*(wp+margin)+margin)/(double)myWidth << (yc*(hp+margin)+margin)/(double)myHeight << wp/(double)myWidth << hp/(double)myHeight;
        webcams[i]->setRelatives(rels);
        webcams[i]->updateBounds(QRect(myDimens[0]*parSize.width(), myDimens[1]*parSize.height(), myWidth, myHeight));
    }
}

void VideoSpace::updateFrame(int idx, QByteArray frame) {
    webcams[idx]->updateFrame(frame);
}
