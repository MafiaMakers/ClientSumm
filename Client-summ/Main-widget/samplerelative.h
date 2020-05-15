#ifndef SAMLPLERELATIVE_H
#define SAMLPLERELATIVE_H
#include <QTextEdit>
#include "Calls/SuperList.h"
using namespace SuperFunctions;
namespace Mafia {
class SampleRelative
{
public:
    SampleRelative(QWidget* parent);
    void setRelatives(SuperList<double> dimens);
    void updateBounds(QSize nsize);
    void setPlayersCount(int count);
    void setAdminActive(bool status);
    void setRole(int role);
    void setMicro(bool status);
    void setCamera(bool status);
    void setVotings(SuperList<SuperList<int>> votings);
    void setEnable(bool status);
    void updateFrame(int idx, QByteArray frame);
private:
    QTextEdit *form;
    SuperList<double> myDimens;
    QSize windowSize;
    void repaint();
};
}

#endif // SAMLPLERELATIVE_H
