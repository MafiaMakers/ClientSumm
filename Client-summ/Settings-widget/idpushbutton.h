#ifndef IDPUSHBUTTON_H
#define IDPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
namespace Mafia {
class IdPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit IdPushButton(int id, QString text, QWidget *parent = nullptr);

private:
    int myId;

private slots:
    void procClicked();

signals:
    void idClicked(int id);
};
}

#endif // IDPUSHBUTTON_H
