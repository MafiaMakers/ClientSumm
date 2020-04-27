#include "idcheckbox.h"
using namespace Mafia;
IdCheckBox::IdCheckBox(int id, QWidget *parent) : QCheckBox(parent)
{
    myId = id;
    connect(this, &QCheckBox::stateChanged, this, &IdCheckBox::procStch);
}

void IdCheckBox::procStch(bool b) {
    emit statusChanged(myId, b);
}
