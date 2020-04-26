#include <QTextStream>
#include "clientmanager.h"
#include <iostream>
#include <thread>
#include <QMessageBox>
#include <QInputDialog>
using namespace Mafia;
void ClientManager::inputFirstData(){
    QMessageBox *myBox = new QMessageBox();

    myBox->setText("Вы хотите создать новую комнату?");
    myBox->setInformativeText("Ок - создать\nCancel - войти в существующую");
    myBox->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    myBox->setIcon(QMessageBox::Information);
    myBox->setDefaultButton(QMessageBox::Ok);
    int res = myBox->exec();
    if(res == QMessageBox::Ok){
        net->sendMessage(*net->getAddrIn(), CREATE_ROOM_MESSAGE_ID, (char*)"123", 4);
    } else{
        int id = QInputDialog::getInt(0,"RoomId","Введите id комнаты");
        std::string key = QInputDialog::getText(0, "Key","Введите ключ комнаты").toStdString();
        net->setRoomId((char)id);
        net->connect(key);

    }
    canSpeak = true;
    std::thread recTh(&NetWorker_c::processMessages, net);
    recTh.detach();

}

ClientManager::ClientManager(QObject *parent) : QObject(parent)
{
    aplayer = new AudioPlayer();
    audCheck = new QBuffer();
    audCheck->open(QBuffer::ReadWrite);
    mafUi =new UIManager();
    mafUi->show();
    muchPlayers = 2;
    mafUi->setPlayersCount(1);
    mafUi->setPlayersCount(muchPlayers);
   // setWind = new SettingsWindow();
    //setWind->show();
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
    default:
        std::cout << content << " error" << std::endl;
        throwError("Messge id - "+QString::number(id).toStdString()+"; content - "+content);
        break;
    }
}

void ClientManager::throwError(std::string err) {
    *out << "Game error: " << QString::fromStdString(err) << endl;
}

void ClientManager::changeStage(std::string nstage) {
    int nst = int(nstage.data()[0]);
    // update voting status requered
    if(curStage == ARGUMENT_STAGE && nst == DEATH_STAGE) {
        votings.clear();
        for(int i = 0; i < muchPlayers; i++) {
            QList<int> l;
            votings.append(l);
        }
        mafUi->updateVotings(votings);
    } else if(nst == ARGUMENT_STAGE) {
        for(int i = 0; i < muchPlayers; i++) {
            QList<int> l;
            votings.append(l);
        }
        mafUi->enableVotings(true);
        mafUi->updateVotings(votings);
    } else {
        votings.clear();
        mafUi->enableVotings(false);
    }
    curStage = nst;
    mafUi->setStage(curStage);
}

void ClientManager::processAudio(char* data, int size){
    QByteArray sound = QByteArray(data, size);
    aplayer->appendAudio(sound);
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
    mafUi->updateRole(curRole);
}

void ClientManager::voteResult(std::string res) {
    const char* data = res.data();
    int idx = *(int*)(data + 1);
    bool flag = *(bool*)data;
    // notify about results

}

void ClientManager::setupOthers(std::string count) {
    muchPlayers = *(int*)count.data();
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
    mafUi->enableSpeaking(canSpeak);
}

void ClientManager::sendAudio() {
    std::cout << micphone->bytesCount() << std::endl;
    if(canSpeak && micphone->bytesCount() >= SOUND_SIZE) {
    micphone->bytesCount();
        QByteArray audio = micphone->getAudio(SOUND_SIZE);
        if(net->isConnected()) {
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
    mafUi->setPlayersCount(muchPlayers);
}

void ClientManager::sheriffResult(std::string content) {
    bool res = *(bool*)(&content.data()[0]);
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
    QMessageBox *myBox = new QMessageBox();
    myBox->setText("Key");
    myBox->setTextInteractionFlags(Qt::TextSelectableByMouse);
    myBox->setText("Вот ключ от вашей комнаты : " + QString(key.c_str()));
    //myBox->setInformativeText();

    myBox->exec();
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
    votings[voted].append(voter);
    mafUi->updateVotings(votings);
}
