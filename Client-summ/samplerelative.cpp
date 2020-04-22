#include "samplerelative.h"
#include "iostream"
using namespace Mafia;
SampleRelative::SampleRelative(QWidget* parent)
{
    form = new QTextEdit(parent);
    windowSize = QSize(0, 0);
    myDimens = QList<double>() << 0 << 0 << 0 << 0;
}

void SampleRelative::setRelatives(QList<double> dimens) {
    myDimens = dimens;
    repaint();
}

void SampleRelative::updateBounds(QSize nsize) {
    windowSize = nsize;
    repaint();
}

void SampleRelative::repaint() {
    form->setGeometry(windowSize.width()*myDimens[0], windowSize.height()*myDimens[1], windowSize.width()*myDimens[2], windowSize.height()*myDimens[3]);
}

void SampleRelative::setRole(int role) {

}

void SampleRelative::setEnable(bool status) {

}
