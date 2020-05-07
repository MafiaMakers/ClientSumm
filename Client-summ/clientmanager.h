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
#include "Results-widget/resultswidget.h"

namespace Mafia {
    class ClientManager : public QObject
    {
        Q_OBJECT
public:
    explicit ClientManager(QObject *parent = nullptr);
    ~ClientManager();

private:
    void vote(std::string voteType);
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
    void setMyIdx(std::string newIdx);
    void setClientsInfo(std::string info);
    void processResults(int* resState, int size);
    int curStage;
    QList<QString> playersNames;
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
    void rolesSettingsSlot(QList<int> selections, QList<int> playersToPlay);
    void nextStageSlot();
    void startGameSlot();
    void stopGameSlot();
};
}

#endif // CLIENTMANAGER_H
