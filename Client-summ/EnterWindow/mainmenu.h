#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QPushButton>
#include <QResizeEvent>
#include "Network/networker_c.h"
#include "createwindow.h"
#include "enterwindow.h"
QT_BEGIN_NAMESPACE

namespace Mafia {
class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr, NetWorker_c* networker = nullptr);
    void gameCreated(int roomId, QString key);
    ~MainMenu();

private slots:
    void EnterGame();
    void CreateGame();
    void Settings();
    void sendName(QString name);
    void GoIn(QString key, QString name, int roomId);
private:
    MyCreateWindow* Cwindow;
    EnterWindow* Ewindow;
    NetWorker_c* net;
    QPushButton *EnterButton;
    QPushButton *CreateButton;
    QPushButton *SettingsButton;
    void repaint();
    virtual void resizeEvent(QResizeEvent *event) override;
    int window_width = 400, window_height = 300;
    const int min_window_width = 400, min_window_height = 300;
};
}
QT_END_NAMESPACE
#endif // MAINMENU_H
