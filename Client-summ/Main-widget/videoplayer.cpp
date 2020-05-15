#include "videoplayer.h"
#include <QMessageBox>
#include <iostream>
Mafia::VideoPlayer::VideoPlayer(QWidget *parent)
{
    canVote = true;
    this->parent = parent;
    this->parBounds = QRect(0, 0, 0, 0);
    call(SuperList<double>() << 0 << 0 << 0 << 0, &this->myDimens);
    player = new QLabel(parent);
    player->setStyleSheet("background-color: #FFFFFF;"
                          "font-size: 24px;");
    player->setText("Видео\nне будэ");
    player->setAlignment(Qt::AlignCenter);
    player->show();
    textPlayer = new QLabel(parent);
    textPlayer->setStyleSheet("color: black;");
    textPlayer->hide();
    textVotes = new QLabel(parent);
    textVotes->hide();
    textVoteOn = new QLabel(parent);
    textVoteOn->hide();
    voteButton = new QPushButton(parent);
    voteButton->setStyleSheet("color: red;"
                              "background-color: lightblue");
    voteButton->setText("Расстрелять");
    voteButton->hide();
    timer = new QTimer();
    timer->setInterval(600);

    connect(timer, &QTimer::timeout, this, &VideoPlayer::noVideoSlot);
    connect(voteButton, &QPushButton::clicked, this, &VideoPlayer::voteSlot);
}

Mafia::VideoPlayer::~VideoPlayer() {
   // player->setVisible(false);
    delete player;
   // delete textPlayer;
   // delete parent;
}

void Mafia::VideoPlayer::hide(){
    textPlayer->close();
    voteButton->close();
    textVotes->close();
    textVoteOn->close();
    player->close();
}

void Mafia::VideoPlayer::raiseVotings(){
    votesForMe++;
    call_void(setVotesCount(votesForMe));
}

void Mafia::VideoPlayer::updateFrame(QByteArray frame) {
    timer->stop();
    timer->start();
    QPixmap pixmap;
    pixmap.loadFromData(frame, "jpg");
    call_void(player->setPixmap(pixmap.scaled(player->size())));
}

void Mafia::VideoPlayer::noVideoSlot() {
    call_void(player->setText("Видео\nне будэ"));
}

void Mafia::VideoPlayer::setBorder(int bw, QColor ncolor) {
    player->setStyleSheet("border: " + QString::number(bw) + "px solid " + ncolor.name() + ";");
}

void Mafia::VideoPlayer::setRelatives(SuperList<double> dimens) {
    call_void(myDimens = dimens);
    call_void(repaint());
}

void Mafia::VideoPlayer::updateBounds(QRect nbounds) {
    call_void(parBounds = nbounds);
    call_void(repaint());
}

void Mafia::VideoPlayer::repaint() {
    call_void(int x = myDimens[0]*parBounds.width()+parBounds.x());
    call_void(int y = myDimens[1]*parBounds.height()+parBounds.y());
    call_void(int width = myDimens[2]*parBounds.width());
    call_void(int height = myDimens[3]*parBounds.height());
    call_void(int space = (height - width / 1.5) / 3);
    player->setGeometry(x, y + space, width, width / 1.5);
    textPlayer->setGeometry(x, y, width, space);
    textPlayer->setFont(QFont("Times", space*0.9, QFont::Bold));
    textVotes->setGeometry(x, y + height - 2*space, width, space);
    textVotes->setFont(QFont("Times", space*0.9));
    textVoteOn->setGeometry(x, y + height - space, width, space + 5);
    textVoteOn->setFont(QFont("Times", space*0.9));
    voteButton->setGeometry(x, y + height - 2*space, width, 2*space);
    voteButton->setFont(QFont("Times", 1.5*space, QFont::Bold));
}

void Mafia::VideoPlayer::setNumPlayer(int num)
{
    myIndex = num-1;
}

void Mafia::VideoPlayer::setName(QString name){
    call_void(textPlayer->setText("(" + QString::number(myIndex) + ")" + name));
    call_void(textPlayer->show());
}

void Mafia::VideoPlayer::startVoting(QString action)
{
    call_void(voteButton->setText(action));
    call_void(textVotes->hide());
    call_void(textVoteOn->hide());
    if (canVote){
        call_void(voteButton->show());
    }
}

void Mafia::VideoPlayer::setVotesCount(int votes)
{
    votesForMe = votes;
    std::cout << "Now player's " << myIndex << " votes are " << votes << std::endl;
    QString str;
    if (votes == -1)
        str = "Не выставлен";
    else if (votes < 21 && votes > 9)
        str = QString::number(votes) + " голосов";
    else if (votes % 10 == 1)
        str = QString::number(votes) + " голос";
    else if (votes % 10 < 5 && votes % 10 > 1)
        str = QString::number(votes) + " голоса";
    else
        str = QString::number(votes) + " голосов";
    call_void(textVotes->setText(str));
    //voteButton->hide();
    call_void(textVotes->show());
}

void Mafia::VideoPlayer::endVoting()
{
    voteButton->hide();
    textVotes->hide();
    textVoteOn->hide();
}

bool Mafia::VideoPlayer::isAlive(){
    return alive;
}

void Mafia::VideoPlayer::setVoteOn(int player)
{
    std::cout << "Player " << myIndex << " voted for " << player << std::endl;
    call_void(textVoteOn->setText("Проголосовал за " + QString::number(player)));
    call_void(textVoteOn->show());
}

void Mafia::VideoPlayer::killPlayer(bool is_died)
{
    if (is_died)
    {
        alive = false;
        textVotes->setText("Ну сдох и сдох");
        textVoteOn->setText("что бубнить-то");
        textVotes->setStyleSheet("color: red;");
        textVoteOn->setStyleSheet("color: red;");
        voteButton->hide();
        textVotes->show();
        textVoteOn->show();
        textPlayer->setStyleSheet("color: red;");
    }
    else
    {
        alive = true;
        textVotes->setStyleSheet("color: black;");
        textVoteOn->setStyleSheet("color: black;");
        textPlayer->setStyleSheet("color: black;");
        textVotes->hide();
        textVoteOn->hide();
    }
}

void Mafia::VideoPlayer::voteSlot()
{
    voteButton->hide();
    textVotes->show();
    //textVotes->setText("Вы проголосовали");
    //textVotes->show();
    call_void(emit this->vote(myIndex));
}

void Mafia::VideoPlayer::setCanVote(bool yes)
{
    canVote = yes;
}
