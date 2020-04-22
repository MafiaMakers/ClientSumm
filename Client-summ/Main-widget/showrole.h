#ifndef SHOWROLE_H
#define SHOWROLE_H
#include <QLabel>
namespace Mafia {
class ShowRole
{
public:
    ShowRole(QWidget* parent);
    void setRelatives(QList<double> dimens);
    void updateBounds(QSize nsize);
    void Show_role(int role_id);
private:
    int CurrRole;
    QLabel *Role;
    QList<double> RoleDimens;
    QSize windowSize;
    void repaint();
};
}

#endif // SHOWROLE_H
