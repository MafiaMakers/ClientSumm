#ifndef IDSPINBOX_H
#define IDSPINBOX_H

#include <QWidget>
#include <QSpinBox>

namespace Mafia {
class IdSpinBox : public QSpinBox
{
    Q_OBJECT
public:
    explicit IdSpinBox(int id, QWidget *parent = nullptr);

private:
    int myId;

private slots:
    void procValChange(int nval);
signals:
    void idValueChanged(int id, int val);
};
}

#endif // IDSPINBOX_H
