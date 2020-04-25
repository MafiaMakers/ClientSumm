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
#include <Network/defines_c.h>

namespace Mafia {
class SettingsWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsWindow(QList<QString> avaiRoles);

private:
    QScrollArea *scrollRoles;
    QGridLayout *gl;
    QPushButton *addRole;
    QComboBox *chRole;
    QLabel *valBorder;

private slots:
    void addPressed();

};
}

#endif // SETTINGSWINDOW_H
