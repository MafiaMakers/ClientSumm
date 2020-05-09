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
    QByteArrayData data[16];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mafia__ClientManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mafia__ClientManager_t qt_meta_stringdata_Mafia__ClientManager = {
    {
QT_MOC_LITERAL(0, 0, 20), // "Mafia::ClientManager"
QT_MOC_LITERAL(1, 21, 10), // "getMessage"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 2), // "id"
QT_MOC_LITERAL(4, 36, 5), // "char*"
QT_MOC_LITERAL(5, 42, 4), // "data"
QT_MOC_LITERAL(6, 47, 4), // "size"
QT_MOC_LITERAL(7, 52, 9), // "sendAudio"
QT_MOC_LITERAL(8, 62, 9), // "sendVideo"
QT_MOC_LITERAL(9, 72, 17), // "rolesSettingsSlot"
QT_MOC_LITERAL(10, 90, 10), // "QList<int>"
QT_MOC_LITERAL(11, 101, 10), // "selections"
QT_MOC_LITERAL(12, 112, 13), // "playersToPlay"
QT_MOC_LITERAL(13, 126, 13), // "nextStageSlot"
QT_MOC_LITERAL(14, 140, 13), // "startGameSlot"
QT_MOC_LITERAL(15, 154, 12) // "stopGameSlot"

    },
    "Mafia::ClientManager\0getMessage\0\0id\0"
    "char*\0data\0size\0sendAudio\0sendVideo\0"
    "rolesSettingsSlot\0QList<int>\0selections\0"
    "playersToPlay\0nextStageSlot\0startGameSlot\0"
    "stopGameSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mafia__ClientManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   49,    2, 0x08 /* Private */,
       7,    0,   56,    2, 0x08 /* Private */,
       8,    0,   57,    2, 0x08 /* Private */,
       9,    2,   58,    2, 0x08 /* Private */,
      13,    0,   63,    2, 0x08 /* Private */,
      14,    0,   64,    2, 0x08 /* Private */,
      15,    0,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 10,   11,   12,
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
        case 0: _t->getMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->sendAudio(); break;
        case 2: _t->sendVideo(); break;
        case 3: _t->rolesSettingsSlot((*reinterpret_cast< QList<int>(*)>(_a[1])),(*reinterpret_cast< QList<int>(*)>(_a[2]))); break;
        case 4: _t->nextStageSlot(); break;
        case 5: _t->startGameSlot(); break;
        case 6: _t->stopGameSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
