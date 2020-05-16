#include <QTextStream>
#include "clientmanager.h"
#include <iostream>
#include <thread>
#include <QMessageBox>
#include <QInputDialog>
#include "EnterWindow/mainmenu.h"

#include "Calls/SuperList.h"

using namespace Mafia;

void ClientManager::memento() {
    qWarning() << muchPlayers;
}

void ClientManager::posix_death_signal(int signum) {
    call_void(memento());
    call_void(signal(signum, SIG_DFL));
    call_void(exit(3));
}

void ClientManager::inputFirstData(){
    /*std::string name = QInputDialog::getText(0, "Nickname","Введите свой никнейм").toStdString();
    QMessageBox *myBox = new QMessageBox();

    myBox->setText("Вы хотите создать новую комнату?");
    myBox->setInformativeText("Ок - создать\nCancel - войти в существующую");
    myBox->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    myBox->setIcon(QMessageBox::Information);
    myBox->setDefaultButton(QMessageBox::Ok);
    int res = myBox->exec();
    if(res == QMessageBox::Ok){
        net->setNickname(name);
        net->sendMessage(*net->getAddrIn(), CREATE_ROOM_MESSAGE_ID, (char*)name.c_str(), name.length()+1);
    } else{
        int id = QInputDialog::getInt(0,"RoomId","Введите id комнаты");
        std::string key = QInputDialog::getText(0, "Key","Введите ключ комнаты").toStdString();
        net->setNickname(name);
        net->setRoomId((char)id);
        net->connect(key);

    }*/

    call_void(menu = new MainMenu(net));
    call_void(menu->show());
    connect(menu, &MainMenu::goIntoRoom, this, &ClientManager::goIntoRoom);
}

ClientManager::ClientManager(QObject *parent) : QObject(parent)
{
 //   signal(SIGSEGV, posix_death_signal);
    aplayer = new AudioPlayer();
    audCheck = new QBuffer();
    audCheck->open(QBuffer::ReadWrite);
    mafUi =new UIManager();
    mafUi->show();
    mafUi->setVisible(false);
    muchPlayers = 1;
    call_void(mafUi->setPlayersCount(muchPlayers, SuperList<QString>() << "Вы"));
    call_void(playersNames = SuperList<QString>());
    micphone = new MicphoneHelper();
    webcam = new CamHelper();
    net = new NetWorker_c();
    out = new QTextStream(stdout);
    meAdmin = false;
    canSpeak = true;
    camActive = true;
    micActive = true;
    myIdx = 0;
    audioSender = new QTimer();
    videoSender = new QTimer();
    call_void(audioSender->setInterval(10));
    call_void(videoSender->setInterval(100));
    //qRegisterMetaType<std::string>("std::string");
    connect(audioSender, &QTimer::timeout, this, &ClientManager::sendAudio);
    connect(videoSender, &QTimer::timeout, this, &ClientManager::sendVideo);
    connect(net, &NetWorker_c::messageReceived, this, &ClientManager::getMessage);
    connect(mafUi, &UIManager::leaveRoomSignal, this, &ClientManager::leaveRoom);

    connect(mafUi, &UIManager::nextStageSignal, this, &ClientManager::nextStageSlot);
    connect(mafUi, &UIManager::startGameSignal, this, &ClientManager::startGameSlot);
    connect(mafUi, &UIManager::stopGameSignal, this, &ClientManager::stopGameSlot);
    connect(mafUi, &UIManager::stopSpeakSignal, this, &ClientManager::stopSpeak);
    connect(mafUi, &UIManager::votedSignal, this, &ClientManager::voted);

    connect(mafUi, &UIManager::micphoneSignal, this, &ClientManager::micphoneSlot);
    connect(mafUi, &UIManager::webkamSignal, this, &ClientManager::webkamSlot);

//    net->connect();
    //mafUi->updateVotings(votings);
    call_void(micphone->start());
    call_void(audioSender->start());
    call_void(videoSender->start());
    call_void(mafUi->setAdminActive(false));
    call_void(inputFirstData());
}

ClientManager::~ClientManager() {

}

void ClientManager::getMessage(int id, char* data, int size) {
    //call_void(std::cout << typeid(*this).name() << "::" << __func__ << std::endl);
    std::string content = "";
    for(int i = 0; i < size; i++){
        call_void(content.insert(content.begin()+i, 1, data[i]));
    }
    //std::cout << id << std::endl;
    switch (id) {
    case ERROR_MESSAGE_ID:
        call_void(throwError(content));
    break;
    case STAGE_MESSAGE_ID:
        call_void(changeStage(content));
    break;
    case ROLE_MESSAGE_ID:
        call_void(setRole(content));
    break;
    case DIE_HEAL_MESSAGE_ID:
        call_void(voteResult(content));
    break;
    case CLIENTS_COUNT_MESSAGE_ID:
        call_void(setupOthers(content));
    break;
    case SET_ADMIN_MESSAGE_ID:
        call_void(checkAdmin(content));
    break;
    case MADE_VOTE_MESSAGE:
        call_void(addVote(content));
    break;
    case INDEX_MESSAGE_ID:
        call_void(updateIndex(content));
    break;
    case EXIT_ROOM_MESSAGE_ID:
        call_void(leaveRoom());
    break;
    case SHERIFF_MESSAGE_ID:
        call_void(sheriffResult(content));
    break;
    case CLIENT_CONNECTED_DISCONNECTED_MESSAGE_ID:
        call_void(addPlayer(content));
    break;
    case CAN_SPEAK_MESSAGE_ID:
        call_void(enableSpeaking(content));
    break;
    case TEXT_MESSAGE_ID:{
        call_void(showTextInfo(content));
        break;
    }
    case VOTE_MESSAGE_ID:{
        call_void(vote(content));
        break;
    }
    case KEY_MESSAGE_ID:{
        call_void(getKeyFromServer(content));
        break;
    }
    case FATHER_MESSAGE_ID:{
        call_void(currentMafiaFather(content));
        break;
    }
    case CANDIDATES_MESSAGE_ID:{
        call_void(showCandidates(content));
        break;
    }
    case VIDEO_MESSAGE_ID:{
        call_void(processVideo(data, size));
        break;
    }
    case AUDIO_MESSAGE_ID:{
        call_void(processAudio(data, size));
        break;
    }
    case CLIENT_INDEX_MESSAGE_ID:{
        call_void(setMyIdx(content));
        break;
    }
    case CLIENTS_INFO_MESSAGE_ID:{
        call_void(setClientsInfo(content));
        break;
    }
    case RESULTS_MESSAGE_ID:{
        call_void(processResults((int*)data, size/4));
        break;
    }
    case CHANGE_NAME_MESSAGE_ID:{
        call_void(changedName(data, size));
        break;
    }
    case FINISH_VOTING_MESSAGE_ID:{
        call_void(finishVoting());
        break;
    }
    case START_GAME_MESSAGE_ID:{
        startGame();
        break;
    }
    default:
        std::cout << content << " error" << std::endl;
        call_void(throwError("Messge id - "+QString::number(id).toStdString()+"; content - "+content));
        break;
    }
}

void ClientManager::finishVoting(){
    call_void(mafUi->stopVoting());
}

void ClientManager::startGame(){
    SuperList<QString> avroles;
    call(SuperList<QString>() << "Не выбрано" << "Мирный" << "Мафия" << "Шериф" << "Доктор", &avroles);
    //QList<QString> avplayers = QList<QString>() << "Иван Гроозный" << "Игорь молодетс" << "Петр Первый топ молодец страну с колен поднял" << "Промлг игрок" << "Денис петух" << "228Я" << "ЯМыМафия" << "А я мирный!";
    std::cout << "done!!!!!!!!!!!!!" << std::endl;
    call_void(setWind = new SettingsWindow(avroles, playersNames));
    connect(setWind, &SettingsWindow::applySignal, this, &ClientManager::rolesSettingsSlot);
    call_void(setWind->show());
}

void ClientManager::goIntoRoom(){
    call_void(menu->close());
    call_void(mafUi->setVisible(true));
}

void ClientManager::changedName(char *data, int size){
    int index = (int)data[0];
    char* name = data+1;
    call_void(std::cout << "bef - " << playersNames.length() << " " << index << std::endl);
    call_void(playersNames[index] = QString::fromStdString(std::string(name, size - 1)));
    //mafUi->setPlayersCount(muchPlayers, playersNames);
    call_void(mafUi->setPlayersName(playersNames[index], index));
    call_void(std::cout << index << " changed name to " << std::string(name, size - 1) << std::endl);
}

void ClientManager::vote(std::string voteType){
    std::string trueString = std::string(voteType.c_str(), voteType.length() - 1);
    std::cout << "vote - " << trueString << std::endl;
    int index = *(int*)(char*)voteType.c_str();
    if(index > -1 && index < muchPlayers && canVote){
        call_void(mafUi->startVoting(index+1));
    } else if(canVote){
        call_void(QString action = (trueString == "kill" ? "Убить"
                       : (trueString == "check" ? "Проверить"
                       : (trueString == "move for voting" ? "Выдвинуть"
                       : (trueString == "hill" ? "Вылечить" : "Ошибка!!")))));
        call_void(mafUi->startVoting(-1, action));
    }
}

void ClientManager::processResults(int* resState, int size){
    call_void(std::cout << "results processing - " << size - 1 << " " << playersNames.length() << std::endl);
    call_void(std::cout << resState[0] << " " << resState[1] << std::endl);
    SuperList<int> rolesRevealed = SuperList<int>();
    for(int i = 1; i < size; i++){
        call_void(std::cout << resState[1] << std::endl);
        call_void(rolesRevealed.append(resState[i]));
    }
    call_void(ResultsWindow* rw = new ResultsWindow(resState[0], rolesRevealed, playersNames));
    std::cout << "window created" << std::endl;
    call_void(rw->show());
    switch (resState[0]) {
    case -1:{
        std::cout << "Mafia wins!" << std::endl;
        break;
    }
    case 1:{
        std::cout << "Civilians wins!" << std::endl;
        break;
    }
    default:{
        std::cout << "results state error!" << std::endl;
        break;
    }
    }
    std::cout << "results processing successfully finished" << std::endl;
}

void ClientManager::voted(int index){
    call_void(net->sendMessage(*net->getAddrIn(), VOTE_MESSAGE_ID, (char*)&index, 4));
    canVote = false;
    std::cout << "Me voted for " << index << std::endl;
}

void ClientManager::setClientsInfo(std::string info){
    std::cout << "setClientsInfo" << std::endl;
    qWarning("start");
    call_void(bool firstStart = playersNames.length() == 0);
    call_void(muchPlayers = (int)info[0]);
    playersNames = SuperList<QString>();
    QString tmp = "";
    for(int i = 1; i < info.length(); i++){
        if(info[i] == '\n'){
            call_void(playersNames.append(tmp));
            tmp = "";
        } else{
            tmp += info[i];
        }
    }
    call_void(std::cout << muchPlayers << " - " << playersNames.length() << std::endl);
    std::cout << "setting..." << std::endl;
    if(muchPlayers > 0){
        std::cout << "do!!!" << std::endl;
            call_void(mafUi->setPlayersCount(muchPlayers, playersNames));
    }
    std::cout << "ok" << std::endl;

    qWarning("end");
    std::cout << "qwertyuiop[" << std::endl;

}

void ClientManager::setMyIdx(std::string newIdx){
    call_void(myIdx = *(int*)((char*)newIdx.c_str()));
}

void ClientManager::throwError(std::string err) {
    call_void(*out << "Game error: " << QString::fromStdString(err) << endl);
}

void ClientManager::changeStage(std::string nstage) {
    int nst = int(nstage.data()[0]);
    std::cout << "stage - " << nst << std::endl;
    if(curStage != nst) {
        canVote = true;
    }
    curStage = nst;
    call_void(mafUi->setStage(curStage));
    if(curStage == WAITING_STAGE && meAdmin){
        call_void(mafUi->setAdminActive(true));
    }
    if(curStage == SPEAKING_STAGE && meAdmin){
        call_void(mafUi->askNextStage());
    }
}

void ClientManager::processAudio(char* data, int size){
    int index = (int)data[0];
    call_void(QByteArray sound = QByteArray(data+1, size-1));
    call_void(aplayer->appendAudio(sound, index));
}

void ClientManager::processVideo(char* data, int size){
    int id = (int)data[0];
    QByteArray frame = QByteArray(data + 1, size - 1);
    if(id != myIdx){
        call_void(mafUi->updateFrame(id, frame));
    }
}

void ClientManager::setRole(std::string role) {
    curRole = (int)role[0];
    std::cout << curRole << " - role" << std::endl;
    call_void(mafUi->updateRole(curRole));
}

void ClientManager::voteResult(std::string res) {

    const char* data = res.data();
    int idx = *(int*)(data + 1);
    std::cout << idx << " dead" << std::endl;
    bool flag = *(bool*)data;
    call_void(mafUi->dayKill(idx));
    // notify about results

}

void ClientManager::setupOthers(std::string count) {
    std::cout << "others" << std::endl;
    if(menu->isVisible()) {
        call_void(menu->close());
    }
    call_void(mafUi->setVisible(true));

    call_void(muchPlayers = *(int*)count.data());
    for(int i = 0; i < muchPlayers; i++){
        call_void(aplayer->addPlayer());
    }
    //this->myIdx = muchPlayers;
    call_void(mafUi->setPlayersCount(muchPlayers));
}

void ClientManager::checkAdmin(std::string content) {
    int nadmin = *(int*)(content.data());
    if(nadmin == myIdx) {
        meAdmin = true;
        call_void(mafUi->setAdminActive(true));
    } else if(meAdmin) {
        meAdmin = false;
        call_void(mafUi->setAdminActive(false));
    }
}

void ClientManager::enableSpeaking(std::string status) {
    bool newSpeak = *(bool*)status.data();
    std::cout << "Now you " << canSpeak << " speak" << std::endl;
    if(newSpeak && (curStage == ARGUMENT_STAGE || curStage == DEATH_STAGE) && !canSpeak){
        call_void(mafUi->startSpeak());
    } else if(newSpeak && (curStage == WAITING_STAGE || curStage == KILLING_STAGE) && !canSpeak) {
        call_void(mafUi->freeSpeak());
    }else if(!newSpeak && canSpeak) {
        call_void(mafUi->stopSpeak());
    }
    canSpeak = newSpeak;
}

void ClientManager::stopSpeak(){
    call_void(net->sendMessage(*net->getAddrIn(), STOP_SPEAK_MESSAGE_ID, (char*)"a", 2));
}

void ClientManager::sendAudio() {
    if(micActive && canSpeak) {
        call_void(QByteArray audio = micphone->getAudio());
        if(net->isConnected()) {
            call_void(net->sendMessage(*net->getAddrIn(), AUDIO_MESSAGE_ID, (char*)audio.data(), audio.size()));
        }
    }
}

void ClientManager::sendVideo() {
    call_void(QByteArray video = webcam->getFrame());
    if(camActive) {
        if(muchPlayers > 0){
            call_void(mafUi->updateFrame(myIdx, video));
        }
        if(net->isConnected()) {
            call_void(net->sendMessage(*net->getAddrIn(), VIDEO_MESSAGE_ID, (char*)video.data(), video.size()));
        }
    }
}

void ClientManager::addPlayer(std::string player) {
    std::cout << "add!" << std::endl;
    muchPlayers += 1;
    call_void(aplayer->addPlayer());
    call_void(playersNames.append(QString::fromStdString(player)));
    call_void(mafUi->setPlayersCount(muchPlayers, playersNames));
    std::cout << "well done" << std::endl;
}

void ClientManager::sheriffResult(std::string content) {
    bool res = *(bool*)(&content.data()[0]);
    std::cout << "sher" << std::endl;
    call_void(mafUi->sheriffResult(0, res));
    // notify about sheriff vote
}

void ClientManager::showTextInfo(std::string info){
    //здесь надо сделать просто окошко с информацией
}

void ClientManager::showCandidates(std::string candidates){
    char* source = (char*)candidates.c_str();
    call_void(int size = candidates.length() / 4);
    int *candidatesIndexes = new int[size];
    for(int i = 0; i < size; i++){
        call_void(candidatesIndexes[i] = *(int*)(source + 4 * i));
    }
    //это нужно для голосовалки - здесь надо отобразить кандидатов.
}

void ClientManager::getKeyFromServer(std::string key){
    /*QMessageBox *myBox = new QMessageBox();
    myBox->setText("Key");
    myBox->setTextInteractionFlags(Qt::TextSelectableByMouse);
    myBox->setText("Вот ключ от вашей комнаты : " + QString(key.c_str()));
    //myBox->setInformativeText();

    myBox->exec();*/
    call_void(menu->gameCreated(net->getRoom(), QString::fromStdString(key)));
    //это ключ, который надо отправить остальным посетителям комнаты для входа
}

void ClientManager::currentMafiaFather(std::string fatherId){
    call_void(int index = *(int*)((char*)fatherId.c_str()));
    //это индекс дона мафии. Он приходит всем мафиям.
}

void ClientManager::leaveRoom() {
    call_void(mafUi->close());
}

void ClientManager::updateIndex(std::string content) {
    call_void(myIdx = *(int*)(content.data()));
}

void ClientManager::addVote(std::string vote) {
    int voter = *(int*)((char*)vote.data());
    int voted = *(int*)((char*)vote.data() + 4);
    //votings[voted].append(voter);
    if(curStage == ARGUMENT_STAGE){
        call_void(mafUi->nominate(voted));
    }
    std::cout << "Made vote got" << std::endl;
    call_void(mafUi->addVote(voter, voted));
   // mafUi->updateVotings(votings);
}

void ClientManager::rolesSettingsSlot(SuperList<int> rolesToPlay, SuperList<int> playersToPlay) {
    call_void(setWind->close());

    call_void(int *dontPlaySend = new int[muchPlayers-playersToPlay.length()]);
    int co = 0;
    for(int i = 0; i < muchPlayers; i++) {
        bool cond;
        call(playersToPlay.contains(i), &cond);
        if(!cond) {
            call_void(dontPlaySend[co] = i);
            co += 1;
        }
    }
    int *rolesToSend = new int[MAX_ROLE_ID*4];
    for(int i = 1; i < rolesToPlay.length(); i++) {
        call_void(rolesToSend[i-1] = rolesToPlay[i]);
        call_void(std::cout << i << " " << rolesToPlay[i] << std::endl);
    }
    call_void(net->sendMessage(*net->getAddrIn(), DONT_PLAY_MESSAGE_ID, (char*)dontPlaySend, (muchPlayers-playersToPlay.length())*4));
    call_void(net->sendMessage(*net->getAddrIn(), SETUP_MESSAGE_ID, (char*)rolesToSend, MAX_ROLE_ID*4));
    call_void(delete[] dontPlaySend);
    call_void(delete[] rolesToSend);
}

void ClientManager::nextStageSlot() {
    call_void(net->sendMessage(*net->getAddrIn(), NEXT_STAGE_MESSAGE_ID, (char*)"a", 2));
}

void ClientManager::startGameSlot() {
    qWarning("beda");
    call_void(net->sendMessage(*net->getAddrIn(), NEXT_STAGE_MESSAGE_ID, (char*)"a", 2));
    std::cout << "sent to server!" << std::endl;
     // сюда надо еще список игроков и доступных ролей передавать, пока что это делается в конструкторе

}

void ClientManager::stopGameSlot() {

}

void ClientManager::micphoneSlot(bool status) {
    micActive = status;
}

void ClientManager::webkamSlot(bool status) {
    camActive = status;
}
