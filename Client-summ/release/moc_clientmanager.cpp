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
    QByteArrayData data[23];
    char stringdata0[243];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mafia__ClientManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mafia__ClientManager_t qt_meta_stringdata_Mafia__ClientManager = {
    {
QT_MOC_LITERAL(0, 0, 20), // "Mafia::ClientManager"
QT_MOC_LITERAL(1, 21, 10), // "goIntoRoom"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 5), // "voted"
QT_MOC_LITERAL(4, 39, 13), // "votedForIndex"
QT_MOC_LITERAL(5, 53, 9), // "stopSpeak"
QT_MOC_LITERAL(6, 63, 10), // "getMessage"
QT_MOC_LITERAL(7, 74, 2), // "id"
QT_MOC_LITERAL(8, 77, 5), // "char*"
QT_MOC_LITERAL(9, 83, 4), // "data"
QT_MOC_LITERAL(10, 88, 4), // "size"
QT_MOC_LITERAL(11, 93, 9), // "sendAudio"
QT_MOC_LITERAL(12, 103, 9), // "sendVideo"
QT_MOC_LITERAL(13, 113, 17), // "rolesSettingsSlot"
QT_MOC_LITERAL(14, 131, 14), // "SuperList<int>"
QT_MOC_LITERAL(15, 146, 10), // "selections"
QT_MOC_LITERAL(16, 157, 13), // "playersToPlay"
QT_MOC_LITERAL(17, 171, 13), // "nextStageSlot"
QT_MOC_LITERAL(18, 185, 13), // "startGameSlot"
QT_MOC_LITERAL(19, 199, 12), // "stopGameSlot"
QT_MOC_LITERAL(20, 212, 12), // "micphoneSlot"
QT_MOC_LITERAL(21, 225, 6), // "status"
QT_MOC_LITERAL(22, 232, 10) // "webkamSlot"

    },
    "Mafia::ClientManager\0goIntoRoom\0\0voted\0"
    "votedForIndex\0stopSpeak\0getMessage\0"
    "id\0char*\0data\0size\0sendAudio\0sendVideo\0"
    "rolesSettingsSlot\0SuperList<int>\0"
    "selections\0playersToPlay\0nextStageSlot\0"
    "startGameSlot\0stopGameSlot\0micphoneSlot\0"
    "status\0webkamSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mafia__ClientManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    1,   75,    2, 0x08 /* Private */,
       5,    0,   78,    2, 0x08 /* Private */,
       6,    3,   79,    2, 0x08 /* Private */,
      11,    0,   86,    2, 0x08 /* Private */,
      12,    0,   87,    2, 0x08 /* Private */,
      13,    2,   88,    2, 0x08 /* Private */,
      17,    0,   93,    2, 0x08 /* Private */,
      18,    0,   94,    2, 0x08 /* Private */,
      19,    0,   95,    2, 0x08 /* Private */,
      20,    1,   96,    2, 0x08 /* Private */,
      22,    1,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 8, QMetaType::Int,    7,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 14,   15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,

       0        // eod
};

void Mafia::ClientManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClientManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->goIntoRoom(); break;
        case 1: _t->voted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->stopSpeak(); break;
        case 3: _t->getMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->sendAudio(); break;
        case 5: _t->sendVideo(); break;
        case 6: _t->rolesSettingsSlot((*reinterpret_cast< SuperList<int>(*)>(_a[1])),(*reinterpret_cast< SuperList<int>(*)>(_a[2]))); break;
        case 7: _t->nextStageSlot(); break;
        case 8: _t->startGameSlot(); break;
        case 9: _t->stopGameSlot(); break;
        case 10: _t->micphoneSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->webkamSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
