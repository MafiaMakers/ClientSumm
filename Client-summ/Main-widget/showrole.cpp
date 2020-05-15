#include "showrole.h"

using namespace Mafia;

ShowRole::ShowRole(QWidget* parent)
{
    Role = new QLabel(parent);
    windowSize = QSize(0, 0);
    RoleDimens = SuperList<double>() << 0 << 0 << 0 << 0;
}

void ShowRole::setRelatives(SuperList<double> dimens) {
    RoleDimens = dimens;
    repaint();
}

void ShowRole::updateBounds(QSize nsize) {
    windowSize = nsize;
    repaint();
}

void ShowRole::Show_role(int role_id) {
    CurrRole = role_id;
    QString role_path;
    switch (role_id){
        case 0:
            role_path = ":/role/img/civilian.jpg";
            break;
        case 1:
            role_path = ":/role/img/mafia.jpg";
            break;
        case 2:
            role_path = ":/role/img/sheriff.jpg";
            break;
        case 3:
            role_path = ":/role/img/doctor.jpg";
            break;
    }
    QPixmap role(role_path);
    int width = RoleDimens[2]*windowSize.width();
    int height = RoleDimens[3]*windowSize.height();
    Role->setPixmap(role.scaled(width, height, Qt::KeepAspectRatio));
}

void ShowRole::repaint() {
    Role->setGeometry(windowSize.width()*RoleDimens[0], windowSize.height()*RoleDimens[1], windowSize.width()*RoleDimens[2], windowSize.height()*RoleDimens[3]);
    Show_role(CurrRole);
}
