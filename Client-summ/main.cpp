#include "clientmanager.h"
#include <QStyle>
#include <QApplication>
using namespace Mafia;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientManager *w = new ClientManager();
    return a.exec();
}
