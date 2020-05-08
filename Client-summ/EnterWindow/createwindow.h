#ifndef CREATEWINDOW_H
#define CREATEWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QFrame>
#include <QLineEdit>
#include <QCheckBox>
#include <QDialogButtonBox>
#include <QApplication>
#include <QClipboard>

QT_BEGIN_NAMESPACE

namespace Mafia {
class MyCreateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MyCreateWindow(QWidget *parent = nullptr);
    ~MyCreateWindow();
    void setup(QString key = "ERROR", int roomId = -1);

signals:
    void sendName(QString name);
private slots:
    void OkButton();
    void Copy();


private:
    QLabel *RoomId_label;
    QLabel *RoomKey_label;
    QLabel *Name_label;
    QLabel *RoomId;
    QLabel *RoomKey;
    QLineEdit *Name;
    QPushButton *CopyButton;
    QFrame *Line;
    QCheckBox *CameraOn;
    QCheckBox *MicroOn;
    QDialogButtonBox *OkCancelBox;
    const int window_width = 400, window_height = 340;
};
}
QT_END_NAMESPACE
#endif // CREATEWINDOW_H
