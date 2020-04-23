#include "clientmanager.h"
#include "Settings-widget/settingswindow.h"
#include <QApplication>
using namespace Mafia;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientManager *w = new ClientManager();
    //SettingsWindow w;
    //w.show();
    return a.exec();
}
