    #include <QTextStream>
#include "clientmanager.h"
#include <iostream>
#include <thread>
#include <QMessageBox>
#include <QInputDialog>
#include "EnterWindow/mainmenu.h"

using namespace Mafia;
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

    menu = new MainMenu(nullptr, net);
    menu->show();
    canSpeak = true;
}

ClientManager::ClientManager(QObject *parent) : QObject(parent)
{
    aplayer = new AudioPlayer();
    audCheck = new QBuffer();
    audCheck->open(QBuffer::ReadWrite);
    mafUi =new UIManager();
    mafUi->show();
    muchPlayers = 1;
    mafUi->setPlayersCount(1);
    mafUi->setPlayersCount(muchPlayers);

    micphone = new MicphoneHelper();
    webcam = new CamHelper();
    net = new NetWorker_c();
    out = new QTextStream(stdout);
    votings.clear();
    meAdmin = false;
    canSpeak = true;
    camActive = true;
    myIdx = 0;
    audioSender = new QTimer();
    videoSender = new QTimer();
    audioSender->setInterval(10);
    videoSender->setInterval(100);
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
//    net->connect();
    mafUi->enableVotings(true);
    for(int i = 0; i < muchPlayers; i++) {
        QList<int> l;
        votings.append(l);
    }
    //mafUi->updateVotings(votings);
    inputFirstData();
    micphone->start();
    audioSender->start();
    videoSender->start();
}

ClientManager::~ClientManager() {

}

void ClientManager::getMessage(int id, char* data, int size) {
    std::string content = "";
    for(int i = 0; i < size; i++){
        content.insert(content.begin()+i, 1, data[i]);
    }
    switch (id) {
    case ERROR_MESSAGE_ID:
        throwError(content);
    break;
    case STAGE_MESSAGE_ID:
        changeStage(content);
    break;
    case ROLE_MESSAGE_ID:
        setRole(content);
    break;
    case DIE_HEAL_MESSAGE_ID:
        voteResult(content);
    break;
    case CLIENTS_COUNT_MESSAGE_ID:
        setupOthers(content);
    break;
    case SET_ADMIN_MESSAGE_ID:
        checkAdmin(content);
    break;
    case MADE_VOTE_MESSAGE:
        addVote(content);
    break;
    case INDEX_MESSAGE_ID:
        updateIndex(content);
    break;
    case EXIT_ROOM_MESSAGE_ID:
        leaveRoom();
    break;
    case SHERIFF_MESSAGE_ID:
        sheriffResult(content);
    break;
    case CLIENT_CONNECTED_DISCONNECTED_MESSAGE_ID:
        addPlayer(content);
    break;
    case CAN_SPEAK_MESSAGE_ID:
        enableSpeaking(content);
    break;
    case TEXT_MESSAGE_ID:{
        showTextInfo(content);
        break;
    }
    case VOTE_MESSAGE_ID:{
        vote(content);
        break;
    }
    case KEY_MESSAGE_ID:{
        getKeyFromServer(content);
        break;
    }
    case FATHER_MESSAGE_ID:{
        currentMafiaFather(content);
        break;
    }
    case CANDIDATES_MESSAGE_ID:{
        showCandidates(content);
        break;
    }
    case VIDEO_MESSAGE_ID:{
        processVideo(data, size);
        break;
    }
    case AUDIO_MESSAGE_ID:{
        processAudio(data, size);
        break;
    }
    case CLIENT_INDEX_MESSAGE_ID:{
        setMyIdx(content);
        break;
    }
    case CLIENTS_INFO_MESSAGE_ID:{
        setClientsInfo(content);
        break;
    }
    case RESULTS_MESSAGE_ID:{
        //int state = *(int*)data;
        processResults((int*)data, size/4);
        break;
    }
    case CHANGE_NAME_MESSAGE_ID:{
        changedName(data, size);
        break;
    }
    case FINISH_VOTING_MESSAGE_ID:{
        break;
    }
    default:
        std::cout << content << " error" << std::endl;
        throwError("Messge id - "+QString::number(id).toStdString()+"; content - "+content);
        break;
    }
}

void ClientManager::finishVoting(){
    mafUi->stopVoting();
}

void ClientManager::changedName(char *data, int size){
    int index = (int)data[0];
    char* name = data+1;
    playersNames[index] = QString::fromStdString(std::string(name, size - 1));
    std::cout << index << " changed name to " << std::string(name, size - 1) << std::endl;
}

void ClientManager::vote(std::string voteType){
    std::string trueString = std::string(voteType.c_str(), voteType.length() - 1);
    int index = *(int*)(char*)voteType.c_str();
    if(index > -1 && index < muchPlayers){
        mafUi->startVoting(index+1);
    } else{
        QString action = (trueString == "kill" ? "Убить"
                       : (trueString == "check" ? "Проверить"
                       : (trueString == "move for voting" ? "Выдвинуть"
                       : (trueString == "hill" ? "Вылечить" : "Ошибка!!"))));
        mafUi->startVoting(-1, action);
    }
}

void ClientManager::processResults(int* resState, int size){
    std::cout << "results processing - " << size - 1 << " " << playersNames.length() << std::endl;
    std::cout << resState[0] << " " << resState[1] << std::endl;
    QList<int> rolesRevealed = QList<int>();
    for(int i = 1; i < size; i++){
        std::cout << resState[1] << std::endl;
        rolesRevealed.append(resState[i]);
    }
    ResultsWindow* rw = new ResultsWindow(resState[0], rolesRevealed, playersNames);
    std::cout << "window created" << std::endl;
    rw->show();
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
    net->sendMessage(*net->getAddrIn(), VOTE_MESSAGE_ID, (char*)&index, 4);
    std::cout << "Me voted for " << index << std::endl;
}

void ClientManager::setClientsInfo(std::string info){
    muchPlayers = (int)info[0];
    playersNames = QList<QString>();
    QString tmp = "";
    for(int i = 1; i < info.length(); i++){
        if(info[i] == '\n'){
            playersNames.append(tmp);
            tmp = "";
        } else{
            tmp += info[i];
        }
    }
    if(meAdmin){
        QList<QString> avroles = QList<QString>() << "Не выбрано" << "Мирный" << "Мафия" << "Шериф" << "Доктор";
        //QList<QString> avplayers = QList<QString>() << "Иван Гроозный" << "Игорь молодетс" << "Петр Первый топ молодец страну с колен поднял" << "Промлг игрок" << "Денис петух" << "228Я" << "ЯМыМафия" << "А я мирный!";
        setWind = new SettingsWindow(avroles, playersNames);
        connect(setWind, &SettingsWindow::applySignal, this, &ClientManager::rolesSettingsSlot);
        setWind->show();
    }
}

void ClientManager::setMyIdx(std::string newIdx){
    myIdx = *(int*)((char*)newIdx.c_str());
}

void ClientManager::throwError(std::string err) {
    *out << "Game error: " << QString::fromStdString(err) << endl;
}

void ClientManager::changeStage(std::string nstage) {
    int nst = int(nstage.data()[0]);
    // update voting status requered
    std::cout << "stage - " << nst << std::endl;
    if(nst == DEATH_STAGE || nst == ARGUMENT_STAGE) {
        votings.clear();
        for(int i = 0; i < muchPlayers; i++) {
            QList<int> l;
            votings.append(l);
        }
        mafUi->updateVotings(votings);
        mafUi->enableVotings(true);
    }  else {
        votings.clear();
        mafUi->enableVotings(false);
    }

    if(nst == SPEAKING_STAGE && meAdmin) {
        mafUi->askNextStage();
    }

    curStage = nst;
    mafUi->setStage(curStage);
}

void ClientManager::processAudio(char* data, int size){
    int index = (int)data[0];
    QByteArray sound = QByteArray(data+1, size-1);
    //std::cout << "e" << std::endl;
    aplayer->appendAudio(sound, index);
}

void ClientManager::processVideo(char* data, int size){
    int id = (int)data[0];
    QByteArray frame = QByteArray(data + 1, size - 1);
    if(id != myIdx){
        mafUi->updateFrame(id, frame);
    }
}

void ClientManager::setRole(std::string role) {
    curRole = (int)role[0];
    std::cout << curRole << " - role" << std::endl;
    mafUi->updateRole(curRole);
}

void ClientManager::voteResult(std::string res) {

    const char* data = res.data();
    int idx = *(int*)(data + 1);
    std::cout << idx << " dead" << std::endl;
    bool flag = *(bool*)data;
    mafUi->dayKill(idx);
    // notify about results

}

void ClientManager::setupOthers(std::string count) {
    muchPlayers = *(int*)count.data();
    for(int i = 0; i < muchPlayers; i++){
        aplayer->addPlayer();
    }
    this->myIdx = muchPlayers;
    mafUi->setPlayersCount(muchPlayers);
}

void ClientManager::checkAdmin(std::string content) {
    int nadmin = *(int*)(content.data());
    if(nadmin == myIdx) {
        meAdmin = true;
        mafUi->setAdminActive(true);
    } else if(meAdmin) {
        meAdmin = false;
        mafUi->setAdminActive(false);
    }
}

void ClientManager::enableSpeaking(std::string status) {
    canSpeak = *(bool*)status.data();
    if(canSpeak && (curStage == ARGUMENT_STAGE || curStage == DEATH_STAGE)){
        mafUi->startSpeak();
    }
    mafUi->enableSpeaking(canSpeak);
}

void ClientManager::stopSpeak(){
    net->sendMessage(*net->getAddrIn(), STOP_SPEAK_MESSAGE_ID, (char*)"a", 2);
}

void ClientManager::sendAudio() {
    if(canSpeak/* && micphone->bytesCount() >= SOUND_SIZE*/) {
        QByteArray audio = micphone->getAudio();
        if(net->isConnected()) {
            //std::cout << "connected" << std::endl;
            //std::cout << audio.size() << std::endl;
            net->sendMessage(*net->getAddrIn(), AUDIO_MESSAGE_ID, (char*)audio.data(), audio.size());
        }
    }
}

void ClientManager::sendVideo() {
    QByteArray video = webcam->getFrame();
    if(camActive) {
        mafUi->updateFrame(myIdx, video);
    // send video via net
        if(net->isConnected()) {
            net->sendMessage(*net->getAddrIn(), VIDEO_MESSAGE_ID, (char*)video.data(), video.size());
        }
    }
}

void ClientManager::addPlayer(std::string player) {
    muchPlayers += 1;
    aplayer->addPlayer();
    playersNames.append(QString::fromStdString(player));
    mafUi->setPlayersCount(muchPlayers);
}

void ClientManager::sheriffResult(std::string content) {
    bool res = *(bool*)(&content.data()[0]);
    std::cout << "sher" << std::endl;
    mafUi->sheriffResult(0, res);
    // notify about sheriff vote
}

void ClientManager::showTextInfo(std::string info){
    //здесь надо сделать просто окошко с информацией
}

void ClientManager::showCandidates(std::string candidates){
    char* source = (char*)candidates.c_str();
    int size = candidates.length() / 4;
    int *candidatesIndexes = new int[size];
    for(int i = 0; i < size; i++){
        candidatesIndexes[i] = *(int*)(source + 4 * i);
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
    menu->gameCreated(net->getRoom(), QString::fromStdString(key));
    //это ключ, который надо отправить остальным посетителям комнаты для входа
}

void ClientManager::currentMafiaFather(std::string fatherId){
    int index = *(int*)((char*)fatherId.c_str());
    //это индекс дона мафии. Он приходит всем мафиям.
}

void ClientManager::leaveRoom() {
    mafUi->close();
}

void ClientManager::updateIndex(std::string content) {
    myIdx = *(int*)(content.data());
}

void ClientManager::addVote(std::string vote) {
    int voter = *(int*)((char*)vote.data());
    int voted = *(int*)((char*)vote.data() + 4);
    //votings[voted].append(voter);
    if(curStage == ARGUMENT_STAGE){
        mafUi->nominate(voted);
    }
    mafUi->addVote(voter, voted);
   // mafUi->updateVotings(votings);
}

void ClientManager::rolesSettingsSlot(QList<int> rolesToPlay, QList<int> playersToPlay) {
    setWind->close();

    int *dontPlaySend = new int[muchPlayers-playersToPlay.size()];
    int co = 0;
    for(int i = 0; i < muchPlayers; i++) {
        if(!playersToPlay.contains(i)) {
            dontPlaySend[co] = i;
            co += 1;
        }
    }
    int *rolesToSend = new int[MAX_ROLE_ID*4];
    for(int i = 1; i < rolesToPlay.size(); i++) {
        rolesToSend[i-1] = rolesToPlay[i];
        std::cout << i << " " << rolesToPlay[i] << std::endl;
    }
    net->sendMessage(*net->getAddrIn(), DONT_PLAY_MESSAGE_ID, (char*)dontPlaySend, (muchPlayers-playersToPlay.size())*4);
    net->sendMessage(*net->getAddrIn(), SETUP_MESSAGE_ID, (char*)rolesToSend, MAX_ROLE_ID*4);
    delete[] dontPlaySend;
    delete[] rolesToSend;
    //
}

void ClientManager::nextStageSlot() {
    net->sendMessage(*net->getAddrIn(), NEXT_STAGE_MESSAGE_ID, (char*)"a", 2);
}

void ClientManager::startGameSlot() {
    net->sendMessage(*net->getAddrIn(), NEXT_STAGE_MESSAGE_ID, (char*)"a", 2);
     // сюда надо еще список игроков и доступных ролей передавать, пока что это делается в конструкторе

}

void ClientManager::stopGameSlot() {

}
