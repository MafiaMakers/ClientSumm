#include "clientmanager.h"
#include "Settings-widget/settingswindow.h"
#include <QApplication>
using namespace Mafia;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientManager *w = new ClientManager();
   // QList<QString> avroles = QList<QString>() << "Не выбрано" << "Мирный" << "Мафия" << "Шериф" << "Доктор";
    //QList<QString> avplayers = QList<QString>() << "Иван Гроозный" << "Игорь молодетс" << "Петр Первый топ молодец страну с колен поднял" << "Промлг игрок" << "Денис петух" << "228Я" << "ЯМыМафия" << "А я мирный!";
    //SettingsWindow w(avroles, avplayers);
   // w.show();
    return a.exec();
}
