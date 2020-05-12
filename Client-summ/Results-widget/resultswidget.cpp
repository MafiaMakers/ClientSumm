#include "Results-widget/resultswidget.h"

using namespace Mafia;

ResultsWindow::ResultsWindow(int resState, QList<int> rolesIndexes, QList<QString> names) {
    this->setGeometry(650, 200, 600, 500);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->playersData = new QScrollArea(this);
    QGridLayout* ScrollLayout = new QGridLayout();
    ScrollLayout->setAlignment(Qt::AlignTop);
    QWidget* widget = new QWidget();
    widget->setLayout(ScrollLayout);
    playersData->setWidget(widget);
    playersData->setWidgetResizable(true);
    playersData->setGeometry(170, 125, 260, 300);
    QList<QString> rolesNames = QList<QString>() << "зритель" << "мирный" << "мафия" << "комиссар" << "доктор";
    for(int i = 0; i < names.length(); i++){
        std::cout << rolesIndexes[i] + 1 << std::endl;
        QLabel* label = new QLabel(names[i] + " - " + rolesNames[rolesIndexes[i] + 1], this);
        label->setStyleSheet("font-size: 16px;");
        ScrollLayout->addWidget(label, i, 1);
    }
    QString resText = (resState == 1 ? "Мирные победили!" : (resState == -1 ? " Мафия победила!" : " Игра завершена!"));
    resultsLabel = new QLabel(resText, this);
    resultsLabel->setGeometry(170, 70, 260, 30);
    resultsLabel->setAlignment(Qt::AlignCenter);
    resultsLabel->setStyleSheet("background-color: #FFFFFF;"
                            "font-size: 24px;");
}
