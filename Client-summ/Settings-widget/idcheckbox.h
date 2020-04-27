#ifndef IDCHECKBOX_H
#define IDCHECKBOX_H

#include <QWidget>
#include <QCheckBox>

namespace Mafia {
class IdCheckBox : public QCheckBox
{
    Q_OBJECT
public:
    explicit IdCheckBox(int id, QWidget *parent = nullptr);

private slots:
    void procStch(bool b);

private:
    int myId;

signals:
    void statusChanged(int, bool);

};
}

#endif // IDCHECKBOX_H
