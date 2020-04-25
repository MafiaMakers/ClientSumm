#include "clientmanager.h"
#include "Settings-widget/settingswindow.h"
#include <QApplication>
using namespace Mafia;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientManager *w = new ClientManager();
//    QList<QString> avroles = QList<QString>() << "Не выбрано" << "Мирный" << "Мафия" << "Шериф" << "Доктор";
//    SettingsWindow w(avroles);
//    w.show();
    return a.exec();
}
