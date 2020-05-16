#ifndef NOTIFYSHOWER_H
#define NOTIFYSHOWER_H

#include <QObject>
#include <QLabel>
#include <QTimer>
#include "Calls/SuperList.h"
using namespace SuperFunctions;
namespace Mafia {

struct showingMessage {
    int type;
    QString content;
};

class NotifyShower : public QLabel
{
    Q_OBJECT
public:
    explicit NotifyShower(QWidget *parent);
    void sheriffResult(int idx, bool res);
    void dayKill(int idx);
    void nominate(int idx);
    void updateBounds(QSize nbounds);
    void setRelatives(SuperList<double> nbounds);
    void startSpeak();
    void stopSpeak();

private:
    SuperList<double> myDimens = SuperList<double>();
    QSize parBounds = QSize();
    int delay = 2500;
    void showMessage();
    SuperList<showingMessage> queue = SuperList<showingMessage>();

private slots:
    void closeMessage();
};
}

#endif // NOTIFYSHOWER_H
