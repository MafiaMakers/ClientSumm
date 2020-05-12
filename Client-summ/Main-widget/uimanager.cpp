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
    notifies = new NotifyShower(this);

    camsSpace->setRelatives(QList<double>() << 10/1280.0 << 10/700.0 << 940/1280.0 << 500/700.0); // cams space
    bottomBox->setRelatives(QList<double>() << 10/1280.0 << 610/700.0 << 940/1280.0 << 80/700.0); // bottom box
    roleIcon->setRelatives(QList<double>() << 960/1280.0 << 10/700.0 << 310/1280.0 << 250/700.0); // role icon
    chat->setRelatives(QList<double>() << 960/1280.0 << 270/700.0 << 310/1280.0 << 420.0/700.0); // chat
    notifies->setRelatives(QList<double>() << 300/1280.0 << 250/700.0 << 680/1280.0 << 200/700.0);

    connect(bottomBox, &UserButtonPanel::exitApp, this, &UIManager::leaveRoomSlot);
    connect(bottomBox, &UserButtonPanel::startGame, this, &UIManager::startGameSlot);
    connect(bottomBox, &UserButtonPanel::endGame, this, &UIManager::stopGameSlot);
    connect(bottomBox, &UserButtonPanel::nextStageButtonPressed, this, &UIManager::nextStageSlot);
    connect(bottomBox, &UserButtonPanel::stopSpeaking, this, &UIManager::stopSpeakSlot);
    connect(camsSpace, &VideoSpace::vote, this, &UIManager::votedSlot);

    connect(bottomBox, &UserButtonPanel::microStatus, this, &UIManager::micphoneSlot);
    connect(bottomBox, &UserButtonPanel::cameraStatus, this, &UIManager::webkamSlot);
}

void UIManager::addVote(int voter, int votedFor){
    camsSpace->addVoter(voter, votedFor);
}

void UIManager::stopSpeakSlot(){
    emit stopSpeakSignal();
}

void UIManager::startSpeak(){
    bottomBox->startSpeking();
}

UIManager::~UIManager() {

}

void UIManager::nextStageSlot(){
    emit nextStageSignal();
}

void UIManager::resizeEvent(QResizeEvent *event) {
    chat->updateBounds(event->size());
    bottomBox->updateBounds(event->size());
    roleIcon->updateBounds(event->size());
    camsSpace->updateBounds(event->size());
    notifies->updateBounds(event->size());
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
    bottomBox->setAdminActive(status);
}

void UIManager::setStage(int stage) {
    bottomBox->setCurrentStage(stage);
}

void UIManager::setPlayersCount(int count) {
    camsSpace->setPlayersCount(count);
}

void UIManager::enableSpeaking(bool status) {
    bottomBox->setMicro(status);
}

void UIManager::updateFrame(int idx, QByteArray frame) {
    camsSpace->updateFrame(idx, frame);
}

void UIManager::startVoting(int candidateIndex, QString action){
    if(candidateIndex != -1){
        camsSpace->startVoting(candidateIndex, action);
    } else{
        camsSpace->startAllVoting(action);
    }

}

void UIManager::stopVoting(){
    camsSpace->endVotingForPlayer();
}

void UIManager::askNextStage() {
    bottomBox->showNextStageButton();
}

void UIManager::votedSlot(int votedForIndex){
    emit votedSignal(votedForIndex);
}

void UIManager::startGameSlot() {
    emit startGameSignal();
}

void UIManager::stopGameSlot() {
    emit stopGameSignal();
}

void UIManager::sheriffResult(int idx, bool res) {
    notifies->sheriffResult(idx, res);
}

void UIManager::dayKill(int idx) {
    camsSpace->kill(idx);
    notifies->dayKill(idx);
}

void UIManager::nominate(int idx) {
    notifies->nominate(idx);
}
