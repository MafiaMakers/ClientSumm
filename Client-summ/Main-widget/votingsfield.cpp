#include "votingsfield.h"
using namespace Mafia;
#include <iostream>
VotingsField::VotingsField(QWidget *parent) : QObject()
{
    iconSource = QImage(":switch/img/treug");
    leftBut = new QPushButton(parent);
    rightBut = new QPushButton(parent);
    leftBut->setStyleSheet("background-color: #42F8F9;");
    rightBut->setStyleSheet("background-color: #42F8F9;");
    mainView = new QScrollArea(parent);
    mainView->setStyleSheet("background-color: #BBFE9C;"
                            "border: 1px solid #000000;");
    mainView->setWidgetResizable(true);
    mainView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mainView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
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
    mainView->setGeometry((myDimens[0]+0.03)*parSize.width(), myDimens[1]*parSize.height(), (myDimens[2]-0.06)*parSize.width(), myDimens[3]*parSize.height());
    leftBut->setGeometry(myDimens[0]*parSize.width(), myDimens[1]*parSize.height(), 0.03*parSize.width(), myDimens[3]*parSize.height());
    rightBut->setGeometry((myDimens[0]+myDimens[2]-0.03)*parSize.width(), myDimens[1]*parSize.height(), 0.03*parSize.width(), myDimens[3]*parSize.height());

    leftIcon = QIcon(QPixmap::fromImage(iconSource.mirrored(true, false)));
    rightIcon = QIcon(QPixmap::fromImage(iconSource));
    leftBut->setIcon(leftIcon);
    rightBut->setIcon(rightIcon);
    leftBut->setIconSize(QSize(leftBut->size().width()*0.5, leftBut->size().height()));
    rightBut->setIconSize(QSize(rightBut->size().width()*0.5, rightBut->size().height()));
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
