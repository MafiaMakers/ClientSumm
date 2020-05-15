#include "clientmanager.h"
#include "Settings-widget/settingswindow.h"
#include <QApplication>
#include "Calls/SuperList.h"
using namespace Mafia;
int main(int argc, char *argv[])
{
    __init__();
    QApplication a(argc, argv);
    ClientManager *w = new ClientManager();
    return a.exec();
}
