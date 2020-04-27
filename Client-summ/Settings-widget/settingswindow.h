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

namespace Mafia {
class SettingsWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsWindow(QList<QString> avaiRoles, QList<QString> participants);

private:
    QScrollArea *scrollRoles;
    QScrollArea *scrollPlayers;
    QGridLayout *glRoles;
    QGridLayout *glPlayers;
    QPushButton *addRole;
    QComboBox *chRole;
    QLabel *valBorder;
    QList<int> *readyRoles;
    QPushButton *apply;
    QLabel *tipRoles;
    QLabel *tipPlayers;
    QList<QString> mapRoles;
    QList<QString> roomParts;
    QWidget *toaddP, *toaddR;
    QList<int> playersToPlay;
    QList<int> rolesToPlay;
private slots:
    void addPressed();
    void selectChanged(int idCh);
    void playerStch(int id, bool status);
    void delRole(int id);
    void applyPressed();
    void updateRoleCount(int id, int nval);

signals:
    void applySignal(QList<int> selections, QList<int> playersToPlay);

};
}

#endif // SETTINGSWINDOW_H
