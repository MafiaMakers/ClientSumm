/****************************************************************************
** Meta object code from reading C++ file 'userbuttonpanel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Main-widget/userbuttonpanel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userbuttonpanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Mafia__UserButtonPanel_t {
    QByteArrayData data[18];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mafia__UserButtonPanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mafia__UserButtonPanel_t qt_meta_stringdata_Mafia__UserButtonPanel = {
    {
QT_MOC_LITERAL(0, 0, 22), // "Mafia::UserButtonPanel"
QT_MOC_LITERAL(1, 23, 11), // "microStatus"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 2), // "on"
QT_MOC_LITERAL(4, 39, 12), // "cameraStatus"
QT_MOC_LITERAL(5, 52, 7), // "exitApp"
QT_MOC_LITERAL(6, 60, 9), // "startGame"
QT_MOC_LITERAL(7, 70, 9), // "gamePause"
QT_MOC_LITERAL(8, 80, 8), // "isPaused"
QT_MOC_LITERAL(9, 89, 7), // "endGame"
QT_MOC_LITERAL(10, 97, 22), // "nextStageButtonPressed"
QT_MOC_LITERAL(11, 120, 8), // "passExit"
QT_MOC_LITERAL(12, 129, 12), // "microChanged"
QT_MOC_LITERAL(13, 142, 13), // "cameraChanged"
QT_MOC_LITERAL(14, 156, 13), // "startGameSlot"
QT_MOC_LITERAL(15, 170, 16), // "stopContinueSlot"
QT_MOC_LITERAL(16, 187, 11), // "endGameSlot"
QT_MOC_LITERAL(17, 199, 9) // "nextStage"

    },
    "Mafia::UserButtonPanel\0microStatus\0\0"
    "on\0cameraStatus\0exitApp\0startGame\0"
    "gamePause\0isPaused\0endGame\0"
    "nextStageButtonPressed\0passExit\0"
    "microChanged\0cameraChanged\0startGameSlot\0"
    "stopContinueSlot\0endGameSlot\0nextStage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mafia__UserButtonPanel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,
       5,    0,   90,    2, 0x06 /* Public */,
       6,    0,   91,    2, 0x06 /* Public */,
       7,    1,   92,    2, 0x06 /* Public */,
       9,    0,   95,    2, 0x06 /* Public */,
      10,    0,   96,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   97,    2, 0x08 /* Private */,
      12,    0,   98,    2, 0x08 /* Private */,
      13,    0,   99,    2, 0x08 /* Private */,
      14,    0,  100,    2, 0x08 /* Private */,
      15,    0,  101,    2, 0x08 /* Private */,
      16,    0,  102,    2, 0x08 /* Private */,
      17,    0,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Mafia::UserButtonPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UserButtonPanel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->microStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->cameraStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->exitApp(); break;
        case 3: _t->startGame(); break;
        case 4: _t->gamePause((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->endGame(); break;
        case 6: _t->nextStageButtonPressed(); break;
        case 7: _t->passExit(); break;
        case 8: _t->microChanged(); break;
        case 9: _t->cameraChanged(); break;
        case 10: _t->startGameSlot(); break;
        case 11: _t->stopContinueSlot(); break;
        case 12: _t->endGameSlot(); break;
        case 13: _t->nextStage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UserButtonPanel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserButtonPanel::microStatus)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UserButtonPanel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserButtonPanel::cameraStatus)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (UserButtonPanel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserButtonPanel::exitApp)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (UserButtonPanel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserButtonPanel::startGame)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (UserButtonPanel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserButtonPanel::gamePause)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (UserButtonPanel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserButtonPanel::endGame)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (UserButtonPanel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserButtonPanel::nextStageButtonPressed)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Mafia::UserButtonPanel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Mafia__UserButtonPanel.data,
    qt_meta_data_Mafia__UserButtonPanel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Mafia::UserButtonPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mafia::UserButtonPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mafia__UserButtonPanel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Mafia::UserButtonPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Mafia::UserButtonPanel::microStatus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Mafia::UserButtonPanel::cameraStatus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Mafia::UserButtonPanel::exitApp()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Mafia::UserButtonPanel::startGame()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Mafia::UserButtonPanel::gamePause(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Mafia::UserButtonPanel::endGame()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Mafia::UserButtonPanel::nextStageButtonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
