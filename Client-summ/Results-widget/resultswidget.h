#ifndef RESULTS_WIDGET
#define RESULTS_WIDGET

#include <QWidget>
#include <QScrollArea>
#include <QGridLayout>
#include <QPushButton>
#include <QComboBox>
#include <QFont>
#include <QLabel>
#include <QSpinBox>
#include <iostream>
#include <Network/defines_c.h>

#include "Calls/SuperList.h"
using namespace SuperFunctions;

namespace Mafia {
    class ResultsWindow : public QFrame
    {
        Q_OBJECT
    public:
        explicit ResultsWindow(int winId, SuperList<int> rolesIndexes, SuperList<QString> names);
    private:
        QScrollArea* playersData;
        QLabel* resultsLabel;
    };
}
#endif
