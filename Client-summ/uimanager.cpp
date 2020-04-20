#include "uimanager.h"
#include <userbuttonpanel.h>

using namespace Mafia;
UIManager::UIManager(QWidget *parent): QMainWindow(parent)
{
    this->resize(1280, 700);
    this->setMinimumSize(500, 500);

    fields.append(new SampleRelative(this));
    fields.append(new UserButtonPanel(this));
    fields.append(new SampleRelative(this));
    fields.append(new VideoSpace(this));
    fields.append(new SampleRelative(this));

    fields[0]->setRelatives(QList<double>() << 960/1280.0 << 350/700.0 << 310/1280.0 << 340.0/700.0); // chat
    fields[1]->setRelatives(QList<double>() << 10/1280.0 << 610/700.0 << 940/1280.0 << 80/700.0); // bottom box
    fields[2]->setRelatives(QList<double>() << 960/1280.0 << 10/700.0 << 310/1280.0 << 160/700.0); // role icon
    fields[3]->setRelatives(QList<double>() << 10/1280.0 << 10/700.0 << 940/1280.0 << 590/700.0); // video space
    fields[4]->setRelatives(QList<double>() << 960/1280.0 << 180/700.0 << 310.0/1280.0 << 160/700.0); // votings field
    foreach(RelativeWidget* el, fields) {
       el->updateBounds(this->size());
    }
}

UIManager::~UIManager() {

}

void UIManager::resizeEvent(QResizeEvent *event) {
    foreach(RelativeWidget* el, fields) {
        el->updateBounds(event->size());
    }
}
/////////////////////////////////////////////
void UIManager::micphone_slot(bool status) { // Slots transition from widgets to client manager
    emit micphoneSignal(status);
}
void UIManager::webkam_slot(bool status) {
    emit webkamSignal(status);
}
void UIManager::leave_room_slot() {
    emit leaveRoomSignal();
}
//////////////////////////////////////////////////
void UIManager::updateRole(int role) {
    fields[2]->setRole(role);
}

void UIManager::setAdminActive(bool status) {
    fields[1]->setAdminActive(status);
}

void UIManager::setStage(int stage) {

}

void UIManager::setPlayersCount(int count) {
    fields[3]->setPlayersCount(count);
}

void UIManager::enableSpeaking(bool status) {
    fields[1]->enableSpeaking(status);
}

void UIManager::updateVotings(QList<QList<int> > votings) {
    fields[4]->setVotings(votings);
}

void UIManager::updateFrame(int idx, QByteArray frame) {
    fields[3]->updateFrame(idx, frame);
}

void UIManager::enableVotings(bool status) {
    fields[4]->setEnable(status);
}
