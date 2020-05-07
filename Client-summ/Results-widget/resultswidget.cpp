#include "Results-widget/resultswidget.h"

using namespace Mafia;

ResultsWindow::ResultsWindow(int resState, QList<int> rolesIndexes, QList<QString> names) {
    this->setGeometry(650, 200, 600, 500);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->playersData = new QScrollArea(this);
    //QWidget* ScrollAreaWidgetContents = new QWidget(playersData);
    QGridLayout* ScrollLayout = new QGridLayout(playersData);
    ScrollLayout->setAlignment(Qt::AlignTop);
    ScrollLayout->setColumnMinimumWidth(0, 40);
    ScrollLayout->setColumnMinimumWidth(2, 40);
    ScrollLayout->setColumnStretch(1, 1000);
    ScrollLayout->setColumnStretch(2, 0);
    QWidget* widget = new QWidget(this);
    widget->setLayout(ScrollLayout);
    playersData->setWidget(widget);
    playersData->setWidgetResizable(true);
    playersData->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    playersData->setGeometry(170, 125, 260, 300);
    QList<QString> rolesNames = QList<QString>() << "зритель" << "мирный" << "мафия" << "комиссар" << "доктор";
    for(int i = 0; i < names.length(); i++){

        QLabel* label = new QLabel(names[i] + " - " + rolesNames[rolesIndexes[i] + 1], this);
        label->setMaximumWidth(190);
        label->setStyleSheet("font-size: 16px;");
        label->setContentsMargins(5, 0, 5, 0);
        ScrollLayout->addWidget(label, i, 1);
    }
    QString resText = (resState == 1 ? "Мирные победили!" : (resState == -1 ? " Мафия победила!" : " Игра завершена!"));
    resultsLabel = new QLabel(resText, this);
    resultsLabel->setGeometry(170, 70, 260, 30);
    resultsLabel->setAlignment(Qt::AlignCenter);
    resultsLabel->setStyleSheet("background-color: #FFFFFF;"
                            "font-size: 24px;");
}
