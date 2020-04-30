#include "Results-widget/resultswidget.h"

using namespace Mafia;

ResultsWindow::ResultsWindow(int resState, QList<int> rolesIndexes, QList<QString> names) {
    this->setGeometry(650, 200, 600, 500);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->playersData = new QScrollArea(this);
    QWidget* ScrollAreaWidgetContents = new QWidget(playersData);
    QGridLayout* ScrollLayout = new QGridLayout(ScrollAreaWidgetContents);
    QList<QString> rolesNames = QList<QString>() << "зритель" << "мирный" << "мафия" << "доктор" << "комиссар";
    for(int i = 0; i < names.length(); i++){

        QLabel* label = new QLabel(names[i] + " - " + rolesNames[rolesIndexes[i] + 1], this);
        label->setMaximumWidth(190);
        label->setStyleSheet("font-size: 16px;");
        label->setContentsMargins(5, 0, 5, 0);
        ScrollLayout->addWidget(label);
    }
}
