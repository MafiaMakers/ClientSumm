#include "settingswindow.h"
using namespace Mafia;
SettingsWindow::SettingsWindow(QList<QString> avaiRoles) : QWidget()
{
    this->setGeometry(650, 200, 600, 600);
    //this->setSizePolicy(QSizePolicy::Fixed);
    scrollRoles = new QScrollArea(this);
    gl = new QGridLayout(scrollRoles);
    gl->setAlignment(Qt::AlignTop);
    gl->setColumnMinimumWidth(2, 20);
    gl->setColumnMinimumWidth(0, 40);
    gl->setColumnStretch(1, 10);
    gl->setColumnStretch(2, 0);
    QWidget *toadd = new QWidget();
    toadd->setLayout(gl);
    scrollRoles->setWidget(toadd);
    scrollRoles->setWidgetResizable(true);

    scrollRoles->setGeometry(100, 120, 400, 400);
    scrollRoles->setStyleSheet("background-color: #FFFFFF;");

    addRole = new QPushButton(this);
    addRole->setText("Добавить роль");
    addRole->setGeometry(400, 45, 140, 40);

    chRole = new QComboBox(this);
    chRole->setGeometry(50, 50, 300, 30);
    chRole->setStyleSheet("background-color: #FFFFFF;"
                          "font-size: 20px;");
    chRole->addItems(avaiRoles);
    QFont chFont = QFont();
    chFont.setLetterSpacing(QFont::AbsoluteSpacing, 1.5);
    chRole->setFont(chFont);


    connect(addRole, &QPushButton::clicked, this, &SettingsWindow::addPressed);
}

void SettingsWindow::addPressed() {
    QSpinBox *spb = new QSpinBox(this);
    spb->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spb->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    spb->setMaximumHeight(40);
    QLabel *label = new QLabel(chRole->currentText());
    label->setStyleSheet("font-size: 18px;");
    QPushButton *delItem = new QPushButton("del", this);
    int curRow = gl->rowCount()+1;
    gl->addWidget(spb, curRow, 0);
    gl->addWidget(label, curRow, 1);
    gl->addWidget(delItem, curRow, 2);
}
