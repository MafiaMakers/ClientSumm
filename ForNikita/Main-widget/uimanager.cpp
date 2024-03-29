#include "uimanager.h"
#include <iostream>
using namespace Mafia;
UIManager::UIManager(QWidget *parent): QMainWindow(parent)
{
    this->resize(1280, 700);
    this->setMinimumSize(500, 500);

    chat = new SampleRelative(this);
    bottomBox = new UserButtonPanel(this);
    roleIcon = new ShowRole(this);
    camsSpace = new VideoSpace(this);
    votings = new VotingsField(this);

    camsSpace->setRelatives(QList<double>() << 10/1280.0 << 10/700.0 << 940/1280.0 << 500/700.0); // cams space
    votings->setRelatives(QList<double>() << 10/1280.0 << 520/700.0 << 940/1280.0 << 80/700.0); // votings field
    bottomBox->setRelatives(QList<double>() << 10/1280.0 << 610/700.0 << 940/1280.0 << 80/700.0); // bottom box
    roleIcon->setRelatives(QList<double>() << 960/1280.0 << 10/700.0 << 310/1280.0 << 250/700.0); // role icon
    chat->setRelatives(QList<double>() << 960/1280.0 << 270/700.0 << 310/1280.0 << 420.0/700.0); // chat

    connect(bottomBox, &UserButtonPanel::exitApp, this, &UIManager::leaveRoomSlot);
}

UIManager::~UIManager() {

}

void UIManager::resizeEvent(QResizeEvent *event) {
    chat->updateBounds(event->size());
    bottomBox->updateBounds(event->size());
    roleIcon->updateBounds(event->size());
    camsSpace->updateBounds(event->size());
    votings->updateBounds(event->size());
}
/////////////////////////////////////////////
void UIManager::micphoneSlot(bool status) { // Slots transition from widgets to client manager
    emit micphoneSignal(status);
}
void UIManager::webkamSlot(bool status) {
    emit webkamSignal(status);
}
void UIManager::leaveRoomSlot() {
    emit leaveRoomSignal();
}
//////////////////////////////////////////////////
void UIManager::updateRole(int role) {
    roleIcon->Show_role(role);
}

void UIManager::setAdminActive(bool status) {
    //bottomBox->setAdminActive(status);
}

void UIManager::setStage(int stage) {

}

void UIManager::setPlayersCount(int count) {
    camsSpace->setPlayersCount(count);
}

void UIManager::enableSpeaking(bool status) {
    bottomBox->setMicro(status);
}

void UIManager::updateVotings(QList<QList<int>> votes) {
    votings->setVotings(votes);
}

void UIManager::updateFrame(int idx, QByteArray frame) {
    camsSpace->updateFrame(idx, frame);
}

void UIManager::enableVotings(bool status) {
    if(status) {
        chat->setRelatives(QList<double>() << 960/1280.0 << 270/700.0 << 310/1280.0 << 420.0/700.0);
        votings->setVisible(true);
    } else {
        chat->setRelatives(QList<double>() << 960/1280.0 << 140/700.0 << 310/1280.0 << 550.0/700.0);
        votings->setVisible(false);
    }
}
