#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <QObject>
#include <QTextStream>
#include <QTimer>
#include <QSaveFile>
#include <QMediaPlayer>
#include <QDir>
#include "Main-widget/uimanager.h"
#include "Network/networker_c.h"
#include "Backend/camhelper.h"
#include "Backend/micphonehelper.h"
#include "Settings-widget/settingswindow.h"

namespace Mafia {
class ClientManager : public QObject
{
    Q_OBJECT
public:
    explicit ClientManager(QObject *parent = nullptr);
    ~ClientManager();

private:
    void throwError(std::string error);
    void changeStage(std::string nstage);
    void setRole(std::string role);
    void voteResult(std::string res);
    void setupOthers(std::string count);
    void checkAdmin(std::string content);
    void addVote(std::string vote);
    void updateIndex(std::string content);
    void leaveRoom();
    void sheriffResult(std::string content);
    void addPlayer(std::string player);
    void enableSpeaking(std::string status);
    void showTextInfo(std::string info);
    void getKeyFromServer(std::string key);
    void currentMafiaFather(std::string fatherId);
    void showCandidates(std::string candidates);
    void inputFirstData();
    void processAudio(char* data, int size);
    void processVideo(char* data, int size);
    int curStage;
    int curRole;
    int muchPlayers;
    int myIdx;
    bool meAdmin;
    bool canSpeak = true;
    bool camActive;
    QString curName;
    QTextStream *out;
    UIManager *mafUi;
    QString serverIP;
    QTimer *audioSender;
    QTimer *videoSender;
    QList<QList<int>> votings;
    //SystemNotifier notifier; notifier
    NetWorker_c *net;
    MicphoneHelper *micphone;
    CamHelper *webcam;
    SettingsWindow *setWind;
    AudioPlayer *aplayer;
    QBuffer *audCheck;

signals:

private slots:
    void getMessage(int id, char* data, int size);
    void sendAudio();
    void sendVideo();
};
}

#endif // CLIENTMANAGER_H
