#include "notifyshower.h"
using namespace Mafia;

NotifyShower::NotifyShower(QWidget *parent) : QLabel(parent)
{
    call_void(this->close());
    call_void(this->setStyleSheet("background-color: #BBBBBB;"
                        "font-size: 24px;"));
    call_void(this->setAlignment(Qt::AlignCenter));
    call_void(this->raise());
}

void NotifyShower::dayKill(int idx) {
    call_void(QString msg = "Игрок "+QString::number(idx)+" убит");
    call_void(queue.append({1, msg}));
    call_void(showMessage());
}

void NotifyShower::nominate(int idx) {
    call_void(QString msg = "Игрок "+QString::number(idx)+" выдвинут");
    call_void(queue.append({1, msg}));
    call_void(showMessage());
}

void NotifyShower::sheriffResult(int idx, bool res) {
    call_void(QString msg = "Игрок, которого вы проверили, ");
    if(res) msg += "мафия";
    else msg += "мирный";
    call_void(queue.append({1, msg}));
    call_void(showMessage());
}

void NotifyShower::startSpeak() {
    call_void(QString msg = "Теперь вы МОЖЕТЕ говорить");
    call_void(queue.append({0, msg}));
    call_void(showMessage());
}

void NotifyShower::stopSpeak() {
    call_void(QString msg = "Теперь вы НЕ можете говорить");
    call_void(queue.append({0, msg}));
    call_void(showMessage());
}

void NotifyShower::updateBounds(QSize nbounds) {
    parBounds = nbounds;
}

void NotifyShower::setRelatives(SuperList<double> rels) {
    myDimens = rels;
}

void NotifyShower::showMessage() {
    if(queue.length() > 0 && !this->isVisible()) {
        int speakIndex = -1;
        for(int i = 0; i < queue.length(); i++) {
            if(((showingMessage)queue[i]).type == 0) {
                if(speakIndex != -1) {
                    queue.pop(speakIndex);
                }
                speakIndex = i;
            }
        }
        call_void(this->raise());
        call_void(QRect geom = QRect(myDimens[0]*parBounds.width(), myDimens[1]*parBounds.height(), myDimens[2]*parBounds.width(), myDimens[3]*parBounds.height()));
        call_void(this->setGeometry(geom));
        call_void(this->setText(((showingMessage)queue[0]).content));
        call_void(queue.pop(0));
        call_void(this->show());
        call_void(this->raise());
        call_void(QTimer::singleShot(delay, this, &NotifyShower::closeMessage));
    }
}

void NotifyShower::closeMessage() {
    call_void(this->close());
    call_void(showMessage());
}
