#include "idspinbox.h"
using namespace Mafia;
IdSpinBox::IdSpinBox(int id, QWidget *parent) : QSpinBox(parent)
{
    myId = id;
    connect(this, SIGNAL(valueChanged(int)), this, SLOT(procValChange(int)));
}

void IdSpinBox::procValChange(int nval) {
    emit idValueChanged(myId, nval);
}
