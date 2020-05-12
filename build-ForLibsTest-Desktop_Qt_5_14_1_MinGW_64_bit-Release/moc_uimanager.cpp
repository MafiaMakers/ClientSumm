/****************************************************************************
** Meta object code from reading C++ file 'uimanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Client-summ/Main-widget/uimanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uimanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Mafia__UIManager_t {
    QByteArrayData data[20];
    char stringdata0[261];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mafia__UIManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mafia__UIManager_t qt_meta_stringdata_Mafia__UIManager = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Mafia::UIManager"
QT_MOC_LITERAL(1, 17, 14), // "micphoneSignal"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 6), // "status"
QT_MOC_LITERAL(4, 40, 12), // "webkamSignal"
QT_MOC_LITERAL(5, 53, 15), // "stopSpeakSignal"
QT_MOC_LITERAL(6, 69, 15), // "leaveRoomSignal"
QT_MOC_LITERAL(7, 85, 15), // "nextStageSignal"
QT_MOC_LITERAL(8, 101, 15), // "startGameSignal"
QT_MOC_LITERAL(9, 117, 14), // "stopGameSignal"
QT_MOC_LITERAL(10, 132, 11), // "votedSignal"
QT_MOC_LITERAL(11, 144, 13), // "votedForIndex"
QT_MOC_LITERAL(12, 158, 12), // "micphoneSlot"
QT_MOC_LITERAL(13, 171, 10), // "webkamSlot"
QT_MOC_LITERAL(14, 182, 13), // "leaveRoomSlot"
QT_MOC_LITERAL(15, 196, 13), // "startGameSlot"
QT_MOC_LITERAL(16, 210, 12), // "stopGameSlot"
QT_MOC_LITERAL(17, 223, 13), // "nextStageSlot"
QT_MOC_LITERAL(18, 237, 13), // "stopSpeakSlot"
QT_MOC_LITERAL(19, 251, 9) // "votedSlot"

    },
    "Mafia::UIManager\0micphoneSignal\0\0"
    "status\0webkamSignal\0stopSpeakSignal\0"
    "leaveRoomSignal\0nextStageSignal\0"
    "startGameSignal\0stopGameSignal\0"
    "votedSignal\0votedForIndex\0micphoneSlot\0"
    "webkamSlot\0leaveRoomSlot\0startGameSlot\0"
    "stopGameSlot\0nextStageSlot\0stopSpeakSlot\0"
    "votedSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mafia__UIManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       4,    1,   97,    2, 0x06 /* Public */,
       5,    0,  100,    2, 0x06 /* Public */,
       6,    0,  101,    2, 0x06 /* Public */,
       7,    0,  102,    2, 0x06 /* Public */,
       8,    0,  103,    2, 0x06 /* Public */,
       9,    0,  104,    2, 0x06 /* Public */,
      10,    1,  105,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,  108,    2, 0x08 /* Private */,
      13,    1,  111,    2, 0x08 /* Private */,
      14,    0,  114,    2, 0x08 /* Private */,
      15,    0,  115,    2, 0x08 /* Private */,
      16,    0,  116,    2, 0x08 /* Private */,
      17,    0,  117,    2, 0x08 /* Private */,
      18,    0,  118,    2, 0x08 /* Private */,
      19,    1,  119,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void Mafia::UIManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UIManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->micphoneSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->webkamSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->stopSpeakSignal(); break;
        case 3: _t->leaveRoomSignal(); break;
        case 4: _t->nextStageSignal(); break;
        case 5: _t->startGameSignal(); break;
        case 6: _t->stopGameSignal(); break;
        case 7: _t->votedSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->micphoneSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->webkamSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->leaveRoomSlot(); break;
        case 11: _t->startGameSlot(); break;
        case 12: _t->stopGameSlot(); break;
        case 13: _t->nextStageSlot(); break;
        case 14: _t->stopSpeakSlot(); break;
        case 15: _t->votedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UIManager::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UIManager::micphoneSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UIManager::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UIManager::webkamSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (UIManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UIManager::stopSpeakSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (UIManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UIManager::leaveRoomSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (UIManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UIManager::nextStageSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (UIManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UIManager::startGameSignal)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (UIManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UIManager::stopGameSignal)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (UIManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UIManager::votedSignal)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Mafia::UIManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Mafia__UIManager.data,
    qt_meta_data_Mafia__UIManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Mafia::UIManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mafia::UIManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mafia__UIManager.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Mafia::UIManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void Mafia::UIManager::micphoneSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Mafia::UIManager::webkamSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Mafia::UIManager::stopSpeakSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Mafia::UIManager::leaveRoomSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Mafia::UIManager::nextStageSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Mafia::UIManager::startGameSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Mafia::UIManager::stopGameSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Mafia::UIManager::votedSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
