#include "mainmenu.h"
#include "enterwindow.h"
#include "createwindow.h"

using namespace Mafia;

MainMenu::MainMenu(QWidget *parent, NetWorker_c* networker): QMainWindow(parent)
{
    this->resize(window_width, window_height);
    this->setMinimumSize(min_window_width, min_window_height);
    this->setWindowTitle("Online Mafia");
    EnterButton = new QPushButton(this);
    CreateButton = new QPushButton(this);
    SettingsButton = new QPushButton(this);
    repaint();
    connect(EnterButton, &QPushButton::clicked, this, &MainMenu::EnterGame);
    connect(CreateButton, &QPushButton::clicked, this, &MainMenu::CreateGame);
    connect(SettingsButton, &QPushButton::clicked, this, &MainMenu::Settings);
    Cwindow = new MyCreateWindow();
    Ewindow = new EnterWindow();
    connect(Ewindow, &EnterWindow::goIn, this, &MainMenu::GoIn);
    connect(Cwindow, &MyCreateWindow::sendName, this, &MainMenu::sendName);
    net = networker;
}

void MainMenu::sendName(QString name){
    net->sendMessage(*net->getAddrIn(), CHANGE_NAME_MESSAGE_ID, (char*)name.toStdString().c_str(), name.length());
}

void MainMenu::repaint() {
    EnterButton->setGeometry(100 * window_width / min_window_width, 20 * window_height / min_window_height, 200 * window_width / min_window_width, 70 * window_height / min_window_height);
    EnterButton->setText("Enter game");
    EnterButton->setFont(QFont("MS Shell Dlg 2", 12, QFont::Bold));
    CreateButton->setGeometry(100 * window_width / min_window_width, 110 * window_height / min_window_height, 200 * window_width / min_window_width, 70 * window_height / min_window_height);
    CreateButton->setText("Create new game");
    CreateButton->setFont(QFont("MS Shell Dlg 2", 12, QFont::Bold));
    SettingsButton->setGeometry(100 * window_width / min_window_width, 200 * window_height / min_window_height, 200 * window_width / min_window_width, 70 * window_height / min_window_height);
    SettingsButton->setText("Settings");
    SettingsButton->setFont(QFont("MS Shell Dlg 2", 12, QFont::Bold));
}

void MainMenu::EnterGame() {
    //EnterWindow window;
    Ewindow->setModal(true);
    Ewindow->exec();
    std::thread recTh(&NetWorker_c::processMessages, net);
    recTh.detach();
}

void MainMenu::GoIn(QString key, QString name, int roomId){
    net->setNickname(name.toStdString());
    net->setRoomId(roomId);
    net->connect(key.toStdString());
    this->close();
}

void MainMenu::gameCreated(int roomId, QString key){
    Cwindow->setup(key, roomId);
    Cwindow->setModal(true);
    Cwindow->exec();
    this->close();
}

void MainMenu::CreateGame() {
    net->setNickname("User");
    net->sendMessage(*net->getAddrIn(), CREATE_ROOM_MESSAGE_ID, (char*)"User", 5);
    std::thread recTh(&NetWorker_c::processMessages, net);
    recTh.detach();
}

void MainMenu::Settings() {

}

void MainMenu::resizeEvent(QResizeEvent *event) {
    window_width = event->size().width();
    window_height = event->size().height();
    repaint();
}

MainMenu::~MainMenu()
{

}
