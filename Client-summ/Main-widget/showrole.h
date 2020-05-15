#ifndef SHOWROLE_H
#define SHOWROLE_H
#include <QLabel>
#include "Calls/SuperList.h"
using namespace SuperFunctions;
namespace Mafia {
class ShowRole
{
public:
    ShowRole(QWidget* parent);
    void setRelatives(SuperList<double> dimens);
    void updateBounds(QSize nsize);
    void Show_role(int role_id);
private:
    int CurrRole;
    QLabel *Role;
    SuperList<double> RoleDimens;
    QSize windowSize;
    void repaint();
};
}

#endif // SHOWROLE_H
