/****************************************************************************
** Meta object code from reading C++ file 'createwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../EnterWindow/createwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'createwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Mafia__MyCreateWindow_t {
    QByteArrayData data[8];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mafia__MyCreateWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mafia__MyCreateWindow_t qt_meta_stringdata_Mafia__MyCreateWindow = {
    {
QT_MOC_LITERAL(0, 0, 21), // "Mafia::MyCreateWindow"
QT_MOC_LITERAL(1, 22, 8), // "sendName"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 4), // "name"
QT_MOC_LITERAL(4, 37, 12), // "cancelSignal"
QT_MOC_LITERAL(5, 50, 8), // "OkButton"
QT_MOC_LITERAL(6, 59, 4), // "Copy"
QT_MOC_LITERAL(7, 64, 6) // "cancel"

    },
    "Mafia::MyCreateWindow\0sendName\0\0name\0"
    "cancelSignal\0OkButton\0Copy\0cancel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mafia__MyCreateWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    0,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Mafia::MyCreateWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyCreateWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->cancelSignal(); break;
        case 2: _t->OkButton(); break;
        case 3: _t->Copy(); break;
        case 4: _t->cancel(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyCreateWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyCreateWindow::sendName)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyCreateWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyCreateWindow::cancelSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Mafia::MyCreateWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Mafia__MyCreateWindow.data,
    qt_meta_data_Mafia__MyCreateWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Mafia::MyCreateWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mafia::MyCreateWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mafia__MyCreateWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Mafia::MyCreateWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Mafia::MyCreateWindow::sendName(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Mafia::MyCreateWindow::cancelSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
