#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include <QScrollArea>
#include <QGridLayout>
#include <QPushButton>
#include <QComboBox>
#include <QFont>
#include <QLabel>
#include <QSpinBox>
#include <iostream>
#include <Network/defines_c.h>
#include "idcheckbox.h"
#include "idpushbutton.h"
#include "idspinbox.h"

#include "Calls/SuperList.h"
using namespace SuperFunctions;

namespace Mafia {
class SettingsWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsWindow(SuperList<QString> avaiRoles, SuperList<QString> participants);

private:
    QScrollArea *scrollRoles;
    QScrollArea *scrollPlayers;
    QGridLayout *glRoles;
    QGridLayout *glPlayers;
    QPushButton *addRole;
    QComboBox *chRole;
    QLabel *valBorder;
    SuperList<int> *readyRoles;
    QPushButton *apply;
    QLabel *tipRoles;
    QLabel *tipPlayers;
    SuperList<QString> mapRoles;
    SuperList<QString> roomParts;
    QWidget *toaddP, *toaddR;
    SuperList<int> playersToPlay;
    SuperList<int> rolesToPlay;
    QLabel *summPlayers, *summRoles;

    void updateSumm();
private slots:
    void addPressed();
    void selectChanged(int idCh);
    void playerStch(int id, bool status);
  //  void delRole(int id);
    void applyPressed();
    void updateRoleCount(int id, int nval);

signals:
    void applySignal(SuperList<int> rolesToPlay, SuperList<int> playersToPlay);

};
}

#endif // SETTINGSWINDOW_H
