#ifndef RELATIVEWIDGET_H
#define RELATIVEWIDGET_H

#include <QObject>
#include <QRect>
#include <QSize>

namespace Mafia {
class RelativeWidget : public QObject
{
    Q_OBJECT
public:
    explicit RelativeWidget() {}
    virtual void setRelatives(QList<double> dimens) {}
    virtual void updateBounds(QSize nsize) {}
    virtual void setPlayersCount(int count) {}
    virtual void setAdminActive(bool status) {}
    virtual void setRole(int role) {}
    virtual void enableSpeaking(bool status) {}
    virtual void setVotings(QList<QList<int>> votings) {}
    virtual void setEnable(bool status) {}

};
}

#endif // RELATIVEWIDGET_H
