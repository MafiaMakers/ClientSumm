#include "idpushbutton.h"
using namespace Mafia;

IdPushButton::IdPushButton(int id, QString text, QWidget *parent) : QPushButton(text, parent)
{
    myId = id;
    connect(this, &QPushButton::clicked, this, &IdPushButton::procClicked);
}

void IdPushButton::procClicked() {
    emit idClicked(myId);
}
