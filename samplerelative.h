#ifndef SAMLPLERELATIVE_H
#define SAMLPLERELATIVE_H
#include <relativewidget.h>
#include <QTextEdit>
namespace Mafia {
class SampleRelative : public RelativeWidget
{
public:
    SampleRelative(QWidget* parent);
    virtual void setRelatives(QList<double> dimens) override;
    virtual void updateBounds(QSize nsize) override;
private:
    QTextEdit *form;
    QList<double> myDimens;
    QSize windowSize;
    void repaint();
};
}

#endif // SAMLPLERELATIVE_H
