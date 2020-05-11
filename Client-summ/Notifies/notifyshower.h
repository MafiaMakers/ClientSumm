#ifndef NOTIFYSHOWER_H
#define NOTIFYSHOWER_H

#include <QObject>
#include <QLabel>
#include <QTimer>

namespace Mafia {
class NotifyShower : public QLabel
{
    Q_OBJECT
public:
    explicit NotifyShower(QWidget *parent);
    void sheriffResult(int idx, bool res);
    void dayKill(int idx);
    void nominate(int idx);
    void updateBounds(QSize nbounds);
    void updateRelatives(QList<double> nbounds);

private:
    QList<double> myDimens = QList<double>();
    QSize parBounds = QSize();
    QString msg = "";
    int delay = 3000;
    void showMessage();

private slots:
    void closeMessage();

signals:

};
}

#endif // NOTIFYSHOWER_H
