/****************************************************************************
** Meta object code from reading C++ file 'settingswindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Client-summ/Settings-widget/settingswindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Mafia__SettingsWindow_t {
    QByteArrayData data[15];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mafia__SettingsWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mafia__SettingsWindow_t qt_meta_stringdata_Mafia__SettingsWindow = {
    {
QT_MOC_LITERAL(0, 0, 21), // "Mafia::SettingsWindow"
QT_MOC_LITERAL(1, 22, 11), // "applySignal"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 14), // "SuperList<int>"
QT_MOC_LITERAL(4, 50, 11), // "rolesToPlay"
QT_MOC_LITERAL(5, 62, 13), // "playersToPlay"
QT_MOC_LITERAL(6, 76, 10), // "addPressed"
QT_MOC_LITERAL(7, 87, 13), // "selectChanged"
QT_MOC_LITERAL(8, 101, 4), // "idCh"
QT_MOC_LITERAL(9, 106, 10), // "playerStch"
QT_MOC_LITERAL(10, 117, 2), // "id"
QT_MOC_LITERAL(11, 120, 6), // "status"
QT_MOC_LITERAL(12, 127, 12), // "applyPressed"
QT_MOC_LITERAL(13, 140, 15), // "updateRoleCount"
QT_MOC_LITERAL(14, 156, 4) // "nval"

    },
    "Mafia::SettingsWindow\0applySignal\0\0"
    "SuperList<int>\0rolesToPlay\0playersToPlay\0"
    "addPressed\0selectChanged\0idCh\0playerStch\0"
    "id\0status\0applyPressed\0updateRoleCount\0"
    "nval"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mafia__SettingsWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   49,    2, 0x08 /* Private */,
       7,    1,   50,    2, 0x08 /* Private */,
       9,    2,   53,    2, 0x08 /* Private */,
      12,    0,   58,    2, 0x08 /* Private */,
      13,    2,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   10,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   14,

       0        // eod
};

void Mafia::SettingsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SettingsWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->applySignal((*reinterpret_cast< SuperList<int>(*)>(_a[1])),(*reinterpret_cast< SuperList<int>(*)>(_a[2]))); break;
        case 1: _t->addPressed(); break;
        case 2: _t->selectChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->playerStch((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->applyPressed(); break;
        case 5: _t->updateRoleCount((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SettingsWindow::*)(SuperList<int> , SuperList<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingsWindow::applySignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Mafia::SettingsWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Mafia__SettingsWindow.data,
    qt_meta_data_Mafia__SettingsWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Mafia::SettingsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mafia::SettingsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mafia__SettingsWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Mafia::SettingsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Mafia::SettingsWindow::applySignal(SuperList<int> _t1, SuperList<int> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
