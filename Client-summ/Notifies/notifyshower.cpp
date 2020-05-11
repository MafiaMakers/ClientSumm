#include "notifyshower.h"
using namespace Mafia;

NotifyShower::NotifyShower(QWidget *parent) : QLabel(parent)
{
    this->setStyleSheet("background-color: #BBBBBB;"
                        "font-size: 24px;");
    this->setAlignment(Qt::AlignCenter);
}

void NotifyShower::dayKill(int idx) {
    msg = "Игрок "+QString::number(idx)+" убит";
}

void NotifyShower::nominate(int idx) {
    msg = "Игрок "+QString::number(idx)+" выдвинут";
}

void NotifyShower::sheriffResult(int idx, bool res) {
    msg = "Игрок "+QString::number(idx)+" ";
    if(res) msg += "мафия";
    else msg += "мирный";
}

void NotifyShower::updateBounds(QSize nbounds) {
    parBounds = nbounds;
}

void NotifyShower::setRelatives(QList<double> rels) {
    myDimens = rels;
}

void NotifyShower::showMessage() {
    QRect geom = QRect(myDimens[0]*parBounds.width(), myDimens[1]*parBounds.height(), myDimens[2]*parBounds.width(), myDimens[3]*parBounds.height());
    this->setGeometry(geom);
    this->setText(msg);
    this->show();
    this->raise();
    QTimer::singleShot(delay, this, &NotifyShower::closeMessage);
}

void NotifyShower::closeMessage() {
    this->close();
}
