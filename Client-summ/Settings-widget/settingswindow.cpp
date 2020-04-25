#include "settingswindow.h"
using namespace Mafia;
SettingsWindow::SettingsWindow() : QWidget()
{
    this->setGeometry(600, 200, 600, 400);
    roles = new QScrollArea();
    gl = new QGridLayout(roles);
    QWidget *toadd = new QWidget();
    toadd->setLayout(gl);
    roles->setWidget(toadd);
    roles->setWidgetResizable(true);

    addRole = new QPushButton(this);
    addRole->setText("Добавить роль");
    addRole->setGeometry(100, 50, 200, 100);
}
