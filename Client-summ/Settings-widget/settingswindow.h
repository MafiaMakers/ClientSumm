#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include <QScrollArea>
#include <QGridLayout>
#include <QPushButton>

namespace Mafia {
class SettingsWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsWindow();

private:
    QScrollArea *roles;
    QGridLayout *gl;
    QPushButton *addRole;

signals:

};
}

#endif // SETTINGSWINDOW_H
