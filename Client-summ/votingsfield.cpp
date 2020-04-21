#include "votingsfield.h"
using namespace Mafia;
VotingsField::VotingsField(QWidget *parent) : QObject()
{
    mainView = new QScrollArea(parent);
    mainView->setStyleSheet("background-color: #BBFE9C;"
                            "border: 1px solid #000000;");
    mainView->setWidgetResizable(true);
    mainView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mainView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    gl = new QGridLayout(mainView);
    QWidget *toadd = new QWidget();
    toadd->setLayout(gl);
    mainView->setWidget(toadd);
    QLabel *l = new QLabel();
    QLabel *l2 = l;
    l->setText("11111");
    l->setStyleSheet("font-size: 24px;");
    gl->addWidget(l);
    gl->addWidget(l2);

}

void VotingsField::setRelatives(QList<double> dimens) {
    myDimens = dimens;
    repaint();
}

void VotingsField::updateBounds(QSize nsize) {
    parSize = nsize;
    repaint();
}

void VotingsField::repaint() {
    mainView->setGeometry(myDimens[0]*parSize.width(), myDimens[1]*parSize.height(), myDimens[2]*parSize.width(), myDimens[3]*parSize.height());
}

void VotingsField::setVotings(QList<QList<int> > votings) {
    qWarning("setting");
    QLayoutItem *ch;
    while ((ch = gl->takeAt(0))!= 0) {
        gl->removeItem(ch);
        ch->widget()->deleteLater();
        delete ch;
    }

    for(int i = 0; i < votings.size(); i++) {
        QList<int> voters  = votings[i];
        int target = i;
        QString s = QString::number(target) + ": ";

        foreach(int el, voters) {
            s.append(QString::number(el) + ",");
        }
        if(voters.size() == 0) {
            s.append("Никто");
        }

        QLabel *label = new QLabel();
        label->setStyleSheet("font-size: 16px;");
        label->setText(s);
        gl->addWidget(label, i%2, i/2);

    }

}

void VotingsField::setVisible(bool status) {
    mainView->setVisible(status);
}
