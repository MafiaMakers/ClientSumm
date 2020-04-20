#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <camhelper.h>
#include <videoplayer.h>
#include <audioplayer.h>
#include <micphonehelper.h>
#include <QResizeEvent>
#include <QTextEdit>
#include <QList>
#include <samplerelative.h>
#include <relativewidget.h>
#include <videospace.h>

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
    void updateVotings(QList<QList<int>> votings);
    void updateFrame(int idx, QByteArray frame);
    void enableVotings(bool status);

private:
    virtual void resizeEvent(QResizeEvent *event) override;
    QList<Mafia::RelativeWidget*> fields;

private slots:
    void micphone_slot(bool status);
    void webkam_slot(bool status);
    void leave_room_slot();

signals:
    void micphoneSignal(bool status);
    void webkamSignal(bool status);
    void leaveRoomSignal();
};
}
QT_END_NAMESPACE
#endif // MAINWINDOW_H
