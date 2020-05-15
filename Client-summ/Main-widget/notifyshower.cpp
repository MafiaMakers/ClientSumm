#include "notifyshower.h"
using namespace Mafia;

NotifyShower::NotifyShower(QWidget *parent) : QLabel(parent)
{
    this->close();
    this->setStyleSheet("background-color: #BBBBBB;"
                        "font-size: 24px;");
    this->setAlignment(Qt::AlignCenter);
    this->raise();
}

void NotifyShower::dayKill(int idx) {
    msg = "Игрок "+QString::number(idx)+" убит";
    showMessage();
}

void NotifyShower::nominate(int idx) {
    msg = "Игрок "+QString::number(idx)+" выдвинут";
    showMessage();
}

void NotifyShower::sheriffResult(int idx, bool res) {
    msg = "Игрок, которого вы проверили, ";
    if(res) msg += "мафия";
    else msg += "мирный";
    showMessage();
}

void NotifyShower::startSpeak() {
    msg = "Теперь вы МОЖЕТЕ говорить";
    showMessage();
}

void NotifyShower::stopSpeak() {
    msg = "Теперь вы НЕ можете говорить";
    showMessage();
}

void NotifyShower::updateBounds(QSize nbounds) {
    parBounds = nbounds;
}

void NotifyShower::setRelatives(SuperList<double> rels) {
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
