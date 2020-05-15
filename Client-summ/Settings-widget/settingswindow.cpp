#include "settingswindow.h"
using namespace Mafia;
SettingsWindow::SettingsWindow(SuperList<QString> avaiRoles, SuperList<QString> participants) : QWidget()
{
    mapRoles = avaiRoles;
    roomParts = participants;

    for(int i = 0; i < avaiRoles.length(); i++) {
        call_void(rolesToPlay.append(0));
    }
    playersToPlay = SuperList<int>();

    this->setGeometry(650, 200, 600, 500);
    this->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    scrollRoles = new QScrollArea(this);
    glRoles = new QGridLayout(scrollRoles);

    glRoles->setAlignment(Qt::AlignTop);
    glRoles->setColumnMinimumWidth(0, 40);
    glRoles->setColumnMinimumWidth(2, 40);
    glRoles->setColumnStretch(1, 1000);
    glRoles->setColumnStretch(2, 0);

    toaddR = new QWidget();
    toaddR->setLayout(glRoles);
    scrollRoles->setWidget(toaddR);
    scrollRoles->setWidgetResizable(true);
    scrollRoles->setGeometry(20, 125, 260, 300);
    scrollRoles->setStyleSheet("background-color: #FFFFFF;");

    chRole = new QComboBox(this);
    chRole->setGeometry(50, 15, 300, 30);
    chRole->setStyleSheet("background-color: #FFFFFF;"
                          "font-size: 20px;");
    call_void(chRole->addItems(avaiRoles.toQtList()));
    QFont chFont = QFont();
    chFont.setLetterSpacing(QFont::AbsoluteSpacing, 1.5);
    chRole->setFont(chFont);

    addRole = new QPushButton(this);
    addRole->setText("Добавить роль");
    addRole->setGeometry(380, 15, 140, 30);
    addRole->setEnabled(false);

    valBorder = new QLabel(this);
    valBorder->setGeometry(45, 10, 480, 40);
    valBorder->setStyleSheet("border: 5px solid #FF2714;");
    valBorder->setForegroundRole(QPalette::NoRole);

    call_void(chRole->raise());
    call_void(addRole->raise());

    readyRoles = new SuperList<int>();

    apply = new QPushButton("Применить", this);
    apply->setGeometry(240, 440, 120, 45);
    apply->setStyleSheet("font-size: 20px;");

    tipRoles = new QLabel("Роли", this);
    tipRoles->setGeometry(40, 70, 120, 30);
    tipRoles->setStyleSheet("background-color: #FFFFFF;"
                            "font-size: 24px;");

    tipPlayers = new QLabel("Игроки", this);
    tipPlayers->setGeometry(420, 70, 120, 30);
    tipPlayers->setStyleSheet("background-color: #FFFFFF;"
                            "font-size: 24px;");

    scrollPlayers = new QScrollArea(this);
    glPlayers = new QGridLayout(scrollPlayers);
    glPlayers->setAlignment(Qt::AlignTop);
    glPlayers->setColumnStretch(1, 10);
    glPlayers->setSpacing(0);
    glPlayers->setContentsMargins(0, 0, 0, 0);

    toaddP = new QWidget();
    toaddP->setLayout(glPlayers);
    scrollPlayers->setWidget(toaddP);
    scrollPlayers->setWidgetResizable(true);
    scrollPlayers->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollPlayers->setGeometry(320, 125, 260, 300);
    scrollPlayers->setStyleSheet("background-color: #FFFFFF;");

    summRoles = new QLabel(this);
    summPlayers = new QLabel(this);
    summRoles->setGeometry(70, 440, 100, 30);
    summPlayers->setGeometry(430, 440, 100, 30);
    summRoles->setStyleSheet("background-color: #FFFFFF;");
    summPlayers->setStyleSheet("background-color: #FFFFFF;");
    summRoles->setText("Сумма: 0");
    summPlayers->setText("Сумма: 0");

    for(int i = 0; i < roomParts.length(); i++) {
        call_void(QLabel *serial = new QLabel(QString::number(i), this));
        call_void(QLabel *label = new QLabel(roomParts[i], this));
        call_void(IdCheckBox *ichb = new IdCheckBox(i, this));

        call_void(serial->setMinimumWidth(20));

        ichb->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        ichb->setMaximumHeight(40);
        label->setMaximumWidth(190);

        serial->setStyleSheet("font-size: 20px;");
        label->setStyleSheet("font-size: 16px;");

        serial->setContentsMargins(5, 0, 0, 0);
        label->setContentsMargins(5, 0, 5, 0);

        call_void(glPlayers->setRowMinimumHeight(i, 40));
        call_void(glPlayers->addWidget(serial, i, 0));
        call_void(glPlayers->addWidget(label, i, 1));
        call_void(glPlayers->addWidget(ichb, i, 2));

        connect(ichb, &IdCheckBox::statusChanged, this, &SettingsWindow::playerStch);
        call_void(ichb->setChecked(true));
    }



    connect(addRole, &QPushButton::clicked, this, &SettingsWindow::addPressed);
    connect(chRole, SIGNAL(currentIndexChanged(int)), this, SLOT(selectChanged(int)));
    connect(apply, &QPushButton::clicked, this, &SettingsWindow::applyPressed);
}

void SettingsWindow::addPressed() {
    int curRow = glRoles->rowCount();

    call_void(IdSpinBox *spb = new IdSpinBox(mapRoles.indexOf(chRole->currentText()), this));
    spb->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spb->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    spb->setMaximumHeight(40);
    spb->setStyleSheet("font-size: 24px;");
    call_void(spb->setValue(1));
    call_void(updateRoleCount(mapRoles.indexOf(chRole->currentText()), 1));

    QLabel *label = new QLabel(chRole->currentText());
    label->setStyleSheet("font-size: 24px;");

    glRoles->setRowMinimumHeight(curRow, 40);
    call_void(glRoles->addWidget(spb, curRow, 0));
    call_void(glRoles->addWidget(label, curRow, 1));

    call_void(readyRoles->append(mapRoles.indexOf(chRole->currentText())));
    call_void(chRole->setCurrentIndex(0));

    connect(spb, &IdSpinBox::idValueChanged, this, &SettingsWindow::updateRoleCount);
}

void SettingsWindow::selectChanged(int idCh) {
    int tId;
    call(rolesToPlay[idCh], &tId);
    if(tId != 0 || idCh == 0) {
        call_void(addRole->setEnabled(false));
        valBorder->setStyleSheet("border: 5px solid #FF2714;");
    } else {
        call_void(addRole->setEnabled(true));
        valBorder->setStyleSheet("border: 5px solid #0EE834;");
    }
}

void SettingsWindow::playerStch(int id, bool status) {
    if(status) {
        call_void(playersToPlay.append(id));

        call_void(glPlayers->itemAtPosition(id, 0)->widget()->setStyleSheet("background-color: #0EE834;"
                                                                  "font-size: 20px;"
                                                                  "border-bottom: 4px solid #000000;"));
        call_void(glPlayers->itemAtPosition(id, 1)->widget()->setStyleSheet("background-color: #0EE834;"
                                                                  "font-size: 16px;"
                                                                  "border-bottom: 4px solid #000000;"));
        call_void(glPlayers->itemAtPosition(id, 2)->widget()->setStyleSheet("background-color: #0EE834;"
                                                                  "border-bottom: 4px solid #000000;"));
    } else {
        call_void(playersToPlay.pop(playersToPlay.indexOf(id)));

        call_void(glPlayers->itemAtPosition(id, 0)->widget()->setStyleSheet("background-color: #FF2714;"
                                                                  "font-size: 20px;"
                                                                  "border-bottom: 4px solid #000000;"));
        call_void(glPlayers->itemAtPosition(id, 1)->widget()->setStyleSheet("background-color: #FF2714;"
                                                                  "font-size: 16px;"
                                                                  "border-bottom: 4px solid #000000;"));
        call_void(glPlayers->itemAtPosition(id, 2)->widget()->setStyleSheet("background-color: #FF2714;"
                                                                  "border-bottom: 4px solid #000000;"));
    }
    call_void(updateSumm());
}

void SettingsWindow::applyPressed() {
    call_void(emit applySignal(rolesToPlay, playersToPlay));
}

void SettingsWindow::updateRoleCount(int id, int nval) {
    call_void(rolesToPlay[id] = nval);
    call_void(updateSumm());
}

void SettingsWindow::updateSumm() {
    int sumRoles = 0;
    call_void(int sumPlayers = playersToPlay.length());
    for(int i = 0; i < rolesToPlay.length(); i++) {
        call_void(sumRoles += rolesToPlay[i]);
    }
    call_void(summRoles->setText("Сумма: " + QString::number(sumRoles)));
    call_void(summPlayers->setText("Сумма: " + QString::number(sumPlayers)));

    if(sumRoles == sumPlayers) {
        call_void(apply->setEnabled(true));
    } else {
        call_void(apply->setEnabled(false));
    }
}

/*
void SettingsWindow::delRole(int id) {
    QGridLayout *ng = new QGridLayout();
    ng->setAlignment(Qt::AlignTop);
    ng->setColumnMinimumWidth(0, 40);
    ng->setColumnMinimumWidth(2, 40);
    ng->setColumnStretch(1, 1000);
    ng->setColumnStretch(2, 0);

    int dichId = readyRoles->indexOf(id-1);

    for(int a = 1; a < glRoles->rowCount()-1; a++) {
        for(int i = 0; i < 3; i++) {
            if(a < dichId) {
                ng->addWidget(glRoles->itemAtPosition(a, i)->widget(), a, i);
            } else {
                ng->addWidget(glRoles->itemAtPosition(a+1, i)->widget(), a, i);
            }
        }
    }
    toaddR = new QWidget(this);
    glRoles = ng;
    toaddR->setLayout(glRoles);
    scrollRoles->setWidget(toaddR);

    std::cout << id << "\n";
    rolesToPlay[id] = 0;
    readyRoles->removeAt(readyRoles->indexOf(id-1));
    selectChanged(chRole->currentIndex());
    updateSumm();
}*/
