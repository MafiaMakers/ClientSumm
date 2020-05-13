#include "enterwindow.h"

using namespace Mafia;

EnterWindow::EnterWindow(QWidget *parent): QDialog(parent)
{
    this->resize(window_width, window_height);
    this->setFixedSize(window_width, window_height);
    this->setWindowTitle("Enter game");

    RoomId_label = new QLabel(this);
    RoomId_label->setGeometry(170, 40, 400, 30);
    RoomId_label->setText("Room Id");
    RoomId_label->setFont(QFont("MS Shell Dlg 2", 12, QFont::Bold));
    RoomId = new QSpinBox(this);
    RoomId->setGeometry(260, 40, 50, 30);
    RoomId->setFont(QFont("MS Shell Dlg 2", 12));

    RoomKey_label = new QLabel(this);
    RoomKey_label->setGeometry(20, 100, 400, 30);
    RoomKey_label->setText("Room Key");
    RoomKey_label->setFont(QFont("MS Shell Dlg 2", 12, QFont::Bold));
    RoomKey = new QLineEdit(this);
    RoomKey->setGeometry(130, 100, 270, 30);
    RoomKey->setFont(QFont("MS Shell Dlg 2", 12));

    PasteButton = new QPushButton(this);
    PasteButton->setGeometry(410, 100, 70, 30);
    PasteButton->setText("Paste");
    PasteButton->setFont(QFont("MS Shell Dlg 2", 12));

    Name_label = new QLabel(this);
    Name_label->setGeometry(20, 160, 400, 30);
    Name_label->setText("Your name");
    Name_label->setFont(QFont("MS Shell Dlg 2", 12, QFont::Bold));
    Name = new QLineEdit(this);
    Name->setGeometry(130, 160, 350, 30);
    Name->setFont(QFont("MS Shell Dlg 2", 12));

    CameraOn = new QCheckBox(this);
    CameraOn->setGeometry(30, 220, 400, 20);
    CameraOn->setText("Don't turn on my camera");
    CameraOn->setFont(QFont("MS Shell Dlg 2", 12));
    MicroOn = new QCheckBox(this);
    MicroOn->setGeometry(30, 260, 400, 20);
    MicroOn->setText("Don't turn on my microphone");
    MicroOn->setFont(QFont("MS Shell Dlg 2", 12));

    OkCancelBox = new QDialogButtonBox(Qt::Horizontal, this);
    OkCancelBox->setGeometry(170, 310, 160, 20);
    OkCancelBox->addButton(QDialogButtonBox::Ok);
    OkCancelBox->addButton(QDialogButtonBox::Cancel);

    RoomId_label->raise();
    RoomKey_label->raise();
    Name_label->raise();
    RoomId_label->raise();

    connect(OkCancelBox, &QDialogButtonBox::accepted, this, &EnterWindow::OkButton);
    connect(OkCancelBox, &QDialogButtonBox::rejected, this, &EnterWindow::cancel);
    connect(PasteButton, &QPushButton::clicked, this, &EnterWindow::Paste);
}

void EnterWindow::OkButton() {
    emit goIn(RoomKey->text(), Name->text(), RoomId->value());
    this->close();
//    EnterWindow::accept();
}

void EnterWindow::Paste() {
    RoomKey->clear();
    RoomKey->paste();
}

void EnterWindow::cancel() {
    this->close();
    emit cancelSignal();
}

EnterWindow::~EnterWindow()
{

}
