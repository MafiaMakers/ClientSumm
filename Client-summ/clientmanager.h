#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <QObject>
#include <QTextStream>
#include <uimanager.h>
#include <networker_c.h>
#include <camhelper.h>
#include <micphonehelper.h>
#include <QTimer>

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
    int curStage;
    int curRole;
    int muchPlayers;
    int myIdx;
    bool meAdmin;
    bool canSpeak;
    bool camActive;
    QString curName;
    QTextStream *out;
    UIManager *mafUi;
    QString serverIP;
    QTimer *hardSender;
    QList<QList<int>> votings;
    //SystemNotifier notifier; notifier
    NetWorker_c *net;
    MicphoneHelper *micphone;
    CamHelper *webcam;

signals:

private slots:
    void getMessage(int id, std::string content);
    void sendHardware();
};
}

#endif // CLIENTMANAGER_H
