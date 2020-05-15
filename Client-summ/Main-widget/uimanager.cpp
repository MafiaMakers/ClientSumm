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

    call_void(camsSpace->setRelatives(SuperList<double>() << 10/1280.0 << 10/700.0 << 940/1280.0 << 500/700.0)); // cams space
    call_void(bottomBox->setRelatives(SuperList<double>() << 10/1280.0 << 610/700.0 << 940/1280.0 << 80/700.0)); // bottom box
    call_void(roleIcon->setRelatives(SuperList<double>() << 960/1280.0 << 10/700.0 << 310/1280.0 << 250/700.0)); // role icon
    call_void(chat->setRelatives(SuperList<double>() << 960/1280.0 << 270/700.0 << 310/1280.0 << 420.0/700.0); // chat
    call_void(notifies->setRelatives(SuperList<double>() << 300/1280.0 << 250/700.0 << 680/1280.0 << 200/700.0)));

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
    call_void(camsSpace->addVoter(voter, votedFor));
}

void UIManager::stopSpeakSlot(){
    call_void(stopSpeak());
    call_void(emit stopSpeakSignal());
}

void UIManager::stopSpeak(){
    call_void(camsSpace->endVotingForPlayer());
    call_void(bottomBox->hideSpeakOptions());
}

void UIManager::startSpeak(){
    call_void(bottomBox->startSpeking());
}

UIManager::~UIManager() {

}

void UIManager::nextStageSlot(){
    call_void(emit nextStageSignal());
}

void UIManager::resizeEvent(QResizeEvent *event) {
    call_void(chat->updateBounds(event->size()));
    call_void(bottomBox->updateBounds(event->size()));
    call_void(roleIcon->updateBounds(event->size()));
    call_void(camsSpace->updateBounds(event->size()));
    call_void(notifies->updateBounds(event->size()));
}
/////////////////////////////////////////////
void UIManager::micphoneSlot(bool status) { // Slots transition from widgets to client manager
    call_void(emit micphoneSignal(status));
}
void UIManager::webkamSlot(bool status) {
    call_void(emit webkamSignal(status));
}
void UIManager::leaveRoomSlot() {
    call_void(emit leaveRoomSignal());
}
//////////////////////////////////////////////////
void UIManager::updateRole(int role) {
    call_void(roleIcon->Show_role(role));
}

void UIManager::setAdminActive(bool status) {
    call_void(bottomBox->setAdminActive(status));
}

void UIManager::setStage(int stage) {
    call_void(bottomBox->setCurrentStage(stage));
}

void UIManager::setPlayersCount(int count, SuperList<QString> names) {
    call_void(camsSpace->setPlayersCount(count, names));
}

void UIManager::enableSpeaking(bool status) {
    call_void(bottomBox->setMicro(status));
}

void UIManager::setPlayersName(QString name, int index){
    call_void(camsSpace->setName(name, index));
}

void UIManager::updateFrame(int idx, QByteArray frame) {
    call_void(camsSpace->updateFrame(idx, frame));
}

void UIManager::startVoting(int candidateIndex, QString action){
    if(candidateIndex != -1){
        call_void(camsSpace->startVoting(candidateIndex, action));
    } else{
        call_void(camsSpace->startAllVoting(action));
    }

}

void UIManager::stopVoting(){
    call_void(camsSpace->endVotingForPlayer());
}

void UIManager::askNextStage() {
    call_void(bottomBox->showNextStageButton());
}

void UIManager::votedSlot(int votedForIndex){
    call_void(emit votedSignal(votedForIndex));
}

void UIManager::startGameSlot() {
    call_void(emit startGameSignal());
}

void UIManager::stopGameSlot() {
    call_void(emit stopGameSignal());
}

void UIManager::sheriffResult(int idx, bool res) {
    call_void(notifies->sheriffResult(idx, res));
}

void UIManager::dayKill(int idx) {
    call_void(camsSpace->kill(idx));
    call_void(notifies->dayKill(idx));
}

void UIManager::nominate(int idx) {
    call_void(notifies->nominate(idx));
}
