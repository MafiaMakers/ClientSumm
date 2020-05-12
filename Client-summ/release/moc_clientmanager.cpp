/****************************************************************************
** Meta object code from reading C++ file 'clientmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../clientmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Mafia__ClientManager_t {
    QByteArrayData data[19];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mafia__ClientManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mafia__ClientManager_t qt_meta_stringdata_Mafia__ClientManager = {
    {
QT_MOC_LITERAL(0, 0, 20), // "Mafia::ClientManager"
QT_MOC_LITERAL(1, 21, 5), // "voted"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 13), // "votedForIndex"
QT_MOC_LITERAL(4, 42, 9), // "stopSpeak"
QT_MOC_LITERAL(5, 52, 10), // "getMessage"
QT_MOC_LITERAL(6, 63, 2), // "id"
QT_MOC_LITERAL(7, 66, 5), // "char*"
QT_MOC_LITERAL(8, 72, 4), // "data"
QT_MOC_LITERAL(9, 77, 4), // "size"
QT_MOC_LITERAL(10, 82, 9), // "sendAudio"
QT_MOC_LITERAL(11, 92, 9), // "sendVideo"
QT_MOC_LITERAL(12, 102, 17), // "rolesSettingsSlot"
QT_MOC_LITERAL(13, 120, 10), // "QList<int>"
QT_MOC_LITERAL(14, 131, 10), // "selections"
QT_MOC_LITERAL(15, 142, 13), // "playersToPlay"
QT_MOC_LITERAL(16, 156, 13), // "nextStageSlot"
QT_MOC_LITERAL(17, 170, 13), // "startGameSlot"
QT_MOC_LITERAL(18, 184, 12) // "stopGameSlot"

    },
    "Mafia::ClientManager\0voted\0\0votedForIndex\0"
    "stopSpeak\0getMessage\0id\0char*\0data\0"
    "size\0sendAudio\0sendVideo\0rolesSettingsSlot\0"
    "QList<int>\0selections\0playersToPlay\0"
    "nextStageSlot\0startGameSlot\0stopGameSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mafia__ClientManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08 /* Private */,
       4,    0,   62,    2, 0x08 /* Private */,
       5,    3,   63,    2, 0x08 /* Private */,
      10,    0,   70,    2, 0x08 /* Private */,
      11,    0,   71,    2, 0x08 /* Private */,
      12,    2,   72,    2, 0x08 /* Private */,
      16,    0,   77,    2, 0x08 /* Private */,
      17,    0,   78,    2, 0x08 /* Private */,
      18,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 7, QMetaType::Int,    6,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 13,   14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Mafia::ClientManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClientManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->voted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->stopSpeak(); break;
        case 2: _t->getMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->sendAudio(); break;
        case 4: _t->sendVideo(); break;
        case 5: _t->rolesSettingsSlot((*reinterpret_cast< QList<int>(*)>(_a[1])),(*reinterpret_cast< QList<int>(*)>(_a[2]))); break;
        case 6: _t->nextStageSlot(); break;
        case 7: _t->startGameSlot(); break;
        case 8: _t->stopGameSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Mafia::ClientManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Mafia__ClientManager.data,
    qt_meta_data_Mafia__ClientManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Mafia::ClientManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mafia::ClientManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mafia__ClientManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Mafia::ClientManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
