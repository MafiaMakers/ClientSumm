#ifndef ENTERWINDOW_H
#define ENTERWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QSpinBox>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QDialogButtonBox>

QT_BEGIN_NAMESPACE

namespace Mafia {
class EnterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EnterWindow(QWidget *parent = nullptr);
    ~EnterWindow();

signals:
    void goIn(QString key, QString name, int rId);

private slots:
    void OkButton();
    void Paste();

private:
    QLabel *RoomId_label;
    QLabel *RoomKey_label;
    QLabel *Name_label;
    QSpinBox *RoomId;
    QLineEdit *RoomKey;
    QLineEdit *Name;
    QPushButton *PasteButton;
    QCheckBox *CameraOn;
    QCheckBox *MicroOn;
    QDialogButtonBox *OkCancelBox;
    const int window_width = 500, window_height = 350;
};
}
QT_END_NAMESPACE
#endif // ENTERWINDOW_H
