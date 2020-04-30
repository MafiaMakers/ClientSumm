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

namespace Mafia {
    class ResultsWindow : public QWidget
    {
        Q_OBJECT
    public:
        explicit ResultsWindow(int winId, QList<int> rolesIndexes, QList<QString> names);
    private:
        QScrollArea* playersData;

    };
}
#endif
