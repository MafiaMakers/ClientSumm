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
#include "showrole.h"
#include "notifyshower.h"

QT_BEGIN_NAMESPACE

namespace Mafia {
class UIManager : public QMainWindow
{
    Q_OBJECT

public:
    UIManager(QWidget *parent = nullptr);
    ~UIManager();
    void startVoting(int candidateIndex = -1, QString action = "Убить");
    void stopVoting();
    void setStage(int stage);
    void updateRole(int role);
    void setPlayersCount(int count, QList<QString> names = QList<QString>());
    void setAdminActive(bool status);
    void enableSpeaking(bool status);
    void updateFrame(int idx, QByteArray frame);
    void askNextStage();
    void startSpeak();
    void sheriffResult(int idx, bool res);
    void dayKill(int idx);
    void nominate(int idx);
    void addVote(int voter, int votedFor);
    void setPlayersName(QString name, int index);

private:
    virtual void resizeEvent(QResizeEvent *event) override;
    SampleRelative *chat;
    ShowRole *roleIcon;
    VideoSpace *camsSpace;
    UserButtonPanel *bottomBox;
    NotifyShower *notifies;


private slots:
    void micphoneSlot(bool status);
    void webkamSlot(bool status);
    void leaveRoomSlot();
    void startGameSlot();
    void stopGameSlot();
    void nextStageSlot();
    void stopSpeakSlot();
    void votedSlot(int votedForIndex);

signals:
    void micphoneSignal(bool status);
    void webkamSignal(bool status);
    void stopSpeakSignal();
    void leaveRoomSignal();
    void nextStageSignal();
    void startGameSignal();
    void stopGameSignal();
    void votedSignal(int votedForIndex);
};
}
QT_END_NAMESPACE
#endif // MAINWINDOW_H
