#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "Backend/camhelper.h"
#include "videoplayer.h"
#include "Backend/audioplayer.h"
#include "Backend/micphonehelper.h"
#include <QResizeEvent>
#include <QTextEdit>
#include <QList>
#include "samplerelative.h"
#include "videospace.h"
#include "userbuttonpanel.h"
#include "votingsfield.h"
#include "showrole.h"

QT_BEGIN_NAMESPACE

namespace Mafia {
class UIManager : public QMainWindow
{
    Q_OBJECT

public:
    UIManager(QWidget *parent = nullptr);
    ~UIManager();

    void setStage(int stage);
    void updateRole(int role);
    void setPlayersCount(int count);
    void setAdminActive(bool status);
    void enableSpeaking(bool status);
    void updateVotings(QList<QList<int>> votws);
    void updateFrame(int idx, QByteArray frame);
    void enableVotings(bool status);
    void askNextStage();

private:
    virtual void resizeEvent(QResizeEvent *event) override;
    SampleRelative *chat;
    ShowRole *roleIcon;
    VotingsField *votings;
    VideoSpace *camsSpace;
    UserButtonPanel *bottomBox;


private slots:
    void micphoneSlot(bool status);
    void webkamSlot(bool status);
    void leaveRoomSlot();
    void startGameSlot();
    void stopGameSlot();

signals:
    void micphoneSignal(bool status);
    void webkamSignal(bool status);
    void leaveRoomSignal();
    void nextStageSignal();
    void startGameSignal();
    void stopGameSignal();
};
}
QT_END_NAMESPACE
#endif // MAINWINDOW_H
