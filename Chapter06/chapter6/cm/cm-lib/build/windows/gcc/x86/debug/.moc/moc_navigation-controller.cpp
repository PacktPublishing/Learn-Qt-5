/****************************************************************************
** Meta object code from reading C++ file 'navigation-controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../source/controllers/navigation-controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'navigation-controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cm__controllers__NavigationController_t {
    QByteArrayData data[8];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cm__controllers__NavigationController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cm__controllers__NavigationController_t qt_meta_stringdata_cm__controllers__NavigationController = {
    {
QT_MOC_LITERAL(0, 0, 37), // "cm::controllers::NavigationCo..."
QT_MOC_LITERAL(1, 38, 18), // "goCreateClientView"
QT_MOC_LITERAL(2, 57, 0), // ""
QT_MOC_LITERAL(3, 58, 15), // "goDashboardView"
QT_MOC_LITERAL(4, 74, 16), // "goEditClientView"
QT_MOC_LITERAL(5, 91, 19), // "cm::models::Client*"
QT_MOC_LITERAL(6, 111, 6), // "client"
QT_MOC_LITERAL(7, 118, 16) // "goFindClientView"

    },
    "cm::controllers::NavigationController\0"
    "goCreateClientView\0\0goDashboardView\0"
    "goEditClientView\0cm::models::Client*\0"
    "client\0goFindClientView"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cm__controllers__NavigationController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    1,   36,    2, 0x06 /* Public */,
       7,    0,   39,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,

       0        // eod
};

void cm::controllers::NavigationController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NavigationController *_t = static_cast<NavigationController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->goCreateClientView(); break;
        case 1: _t->goDashboardView(); break;
        case 2: _t->goEditClientView((*reinterpret_cast< cm::models::Client*(*)>(_a[1]))); break;
        case 3: _t->goFindClientView(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cm::models::Client* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (NavigationController::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavigationController::goCreateClientView)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (NavigationController::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavigationController::goDashboardView)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (NavigationController::*_t)(cm::models::Client * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavigationController::goEditClientView)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (NavigationController::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavigationController::goFindClientView)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject cm::controllers::NavigationController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_cm__controllers__NavigationController.data,
      qt_meta_data_cm__controllers__NavigationController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *cm::controllers::NavigationController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cm::controllers::NavigationController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cm__controllers__NavigationController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int cm::controllers::NavigationController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void cm::controllers::NavigationController::goCreateClientView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void cm::controllers::NavigationController::goDashboardView()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void cm::controllers::NavigationController::goEditClientView(cm::models::Client * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void cm::controllers::NavigationController::goFindClientView()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
