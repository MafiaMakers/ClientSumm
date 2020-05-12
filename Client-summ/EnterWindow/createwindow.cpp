#include "createwindow.h"
#include <iostream>
using namespace Mafia;

MyCreateWindow::MyCreateWindow(QWidget *parent): QDialog(parent)
{
    this->resize(window_width, window_height);
    this->setFixedSize(window_width, window_height);
    this->setWindowTitle("Create new game");

    RoomId_label = new QLabel(this);
    RoomId_label->setGeometry(120, 10, 80, 30);
    RoomId_label->setText("Room Id:");
    RoomId_label->setFont(QFont("MS Shell Dlg 2", 12, QFont::Bold));
    RoomId_label->setTextInteractionFlags(Qt::TextSelectableByMouse);
    RoomId = new QLabel(this);
    RoomId->setGeometry(200, 10, 30, 30);
    RoomId->setTextInteractionFlags(Qt::TextSelectableByMouse);
    RoomId->setFont(QFont("MS Shell Dlg 2", 12));


    RoomKey_label = new QLabel(this);
    RoomKey_label->setGeometry(10, 50, 90, 30);
    RoomKey_label->setText("Room Key:");
    RoomKey_label->setFont(QFont("MS Shell Dlg 2", 12, QFont::Bold));
    RoomKey_label->setTextInteractionFlags(Qt::TextSelectableByMouse);
    RoomKey = new QLabel(this);
    RoomKey->setGeometry(110, 50, 280, 30);
    RoomKey->setTextInteractionFlags(Qt::TextSelectableByMouse);
    RoomKey->setFont(QFont("MS Shell Dlg 2", 12));


    CopyButton = new QPushButton(this);
    CopyButton->setGeometry(150, 90, 80, 30);
    CopyButton->setText("Copy");    

    Line = new QFrame(this);
    Line->setGeometry(0, 130, 400, 20);
    Line->setFrameShape(QFrame::HLine);
    Line->setFrameShadow(QFrame::Sunken);

    Name_label = new QLabel(this);
    Name_label->setGeometry(10, 170, 90, 30);
    Name_label->setText("Your name");
    Name_label->setFont(QFont("MS Shell Dlg 2", 12, QFont::Bold));
    Name = new QLineEdit(this);
    Name->setGeometry(110, 170, 270, 30);
    Name->setFont(QFont("MS Shell Dlg 2", 12));

    CameraOn = new QCheckBox(this);
    CameraOn->setGeometry(30, 220, 240, 20);
    CameraOn->setText("Don't turn on my camera");
    CameraOn->setFont(QFont("MS Shell Dlg 2", 12));
    MicroOn = new QCheckBox(this);
    MicroOn->setGeometry(30, 260, 240, 20);
    MicroOn->setText("Don't turn on my microphone");
    MicroOn->setFont(QFont("MS Shell Dlg 2", 12));

    OkCancelBox = new QDialogButtonBox(Qt::Horizontal, this);
    OkCancelBox->setGeometry(120, 300, 165, 20);
    OkCancelBox->addButton(QDialogButtonBox::Ok);
    OkCancelBox->addButton(QDialogButtonBox::Cancel);

    connect(OkCancelBox, &QDialogButtonBox::accepted, this, &MyCreateWindow::OkButton);
    connect(OkCancelBox, &QDialogButtonBox::rejected, this, &MyCreateWindow::cancel);
    connect(CopyButton, &QPushButton::clicked, this, &MyCreateWindow::Copy);
}

void MyCreateWindow::setup(QString key, int roomId){
    RoomKey->setText(key);
    RoomId->setText(QString::number(roomId));
    this->show();
}

void MyCreateWindow::OkButton() {
    std::cout << Name->text().toStdString() << std::endl;
    emit this->sendName(Name->text());
    this->close();
}

void MyCreateWindow::Copy() {
    QClipboard *cb = QApplication::clipboard();
    QString text = RoomId_label->text() + " " + RoomId->text() + "\n" + RoomKey_label->text() + " " + RoomKey->text();
    cb->setText(text);
}

void MyCreateWindow::cancel() {
    this->close();
    emit cancelSignal();
}

MyCreateWindow::~MyCreateWindow()
{

}
