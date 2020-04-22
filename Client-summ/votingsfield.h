#ifndef VOTINGSFIELD_H
#define VOTINGSFIELD_H

#include <QObject>
#include <QSize>
#include <QLabel>
#include <QScrollArea>
#include <QGridLayout>
#include <QFrame>
#include <QPushButton>
#include <QIcon>
#include <QImage>

namespace Mafia {
class VotingsField : public QObject
{
    Q_OBJECT
public:
    explicit VotingsField(QWidget *parent);
    void updateBounds(QSize nsize);
    void setRelatives(QList<double> dimens);
    void setVotings(QList<QList<int>> votings);
    void setVisible(bool status);
private:
    QSize parSize;
    QList<double> myDimens;
    void repaint();
    QWidget *parent;
    QScrollArea *mainView;
    QGridLayout *gl;
    QPushButton *leftBut, *rightBut;
    QIcon leftIcon, rightIcon;
    QImage iconSource;

signals:

};
}

#endif // VOTINGSFIELD_H
