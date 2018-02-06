/****************************************************************************
** Meta object code from reading C++ file 'i-navigation-controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../source/controllers/i-navigation-controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'i-navigation-controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cm__controllers__INavigationController_t {
    QByteArrayData data[10];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cm__controllers__INavigationController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cm__controllers__INavigationController_t qt_meta_stringdata_cm__controllers__INavigationController = {
    {
QT_MOC_LITERAL(0, 0, 38), // "cm::controllers::INavigationC..."
QT_MOC_LITERAL(1, 39, 23), // "goCreateAppointmentView"
QT_MOC_LITERAL(2, 63, 0), // ""
QT_MOC_LITERAL(3, 64, 19), // "cm::models::Client*"
QT_MOC_LITERAL(4, 84, 6), // "client"
QT_MOC_LITERAL(5, 91, 18), // "goCreateClientView"
QT_MOC_LITERAL(6, 110, 15), // "goDashboardView"
QT_MOC_LITERAL(7, 126, 16), // "goEditClientView"
QT_MOC_LITERAL(8, 143, 16), // "goFindClientView"
QT_MOC_LITERAL(9, 160, 9) // "goRssView"

    },
    "cm::controllers::INavigationController\0"
    "goCreateAppointmentView\0\0cm::models::Client*\0"
    "client\0goCreateClientView\0goDashboardView\0"
    "goEditClientView\0goFindClientView\0"
    "goRssView"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cm__controllers__INavigationController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,
       6,    0,   48,    2, 0x06 /* Public */,
       7,    1,   49,    2, 0x06 /* Public */,
       8,    0,   52,    2, 0x06 /* Public */,
       9,    0,   53,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void cm::controllers::INavigationController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        INavigationController *_t = static_cast<INavigationController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->goCreateAppointmentView((*reinterpret_cast< cm::models::Client*(*)>(_a[1]))); break;
        case 1: _t->goCreateClientView(); break;
        case 2: _t->goDashboardView(); break;
        case 3: _t->goEditClientView((*reinterpret_cast< cm::models::Client*(*)>(_a[1]))); break;
        case 4: _t->goFindClientView(); break;
        case 5: _t->goRssView(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cm::models::Client* >(); break;
            }
            break;
        case 3:
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
            typedef void (INavigationController::*_t)(cm::models::Client * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&INavigationController::goCreateAppointmentView)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (INavigationController::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&INavigationController::goCreateClientView)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (INavigationController::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&INavigationController::goDashboardView)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (INavigationController::*_t)(cm::models::Client * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&INavigationController::goEditClientView)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (INavigationController::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&INavigationController::goFindClientView)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (INavigationController::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&INavigationController::goRssView)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject cm::controllers::INavigationController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_cm__controllers__INavigationController.data,
      qt_meta_data_cm__controllers__INavigationController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *cm::controllers::INavigationController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cm::controllers::INavigationController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cm__controllers__INavigationController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int cm::controllers::INavigationController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void cm::controllers::INavigationController::goCreateAppointmentView(cm::models::Client * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void cm::controllers::INavigationController::goCreateClientView()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void cm::controllers::INavigationController::goDashboardView()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void cm::controllers::INavigationController::goEditClientView(cm::models::Client * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void cm::controllers::INavigationController::goFindClientView()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void cm::controllers::INavigationController::goRssView()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
