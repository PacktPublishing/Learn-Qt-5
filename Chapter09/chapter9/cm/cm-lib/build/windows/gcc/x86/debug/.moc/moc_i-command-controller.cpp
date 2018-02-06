/****************************************************************************
** Meta object code from reading C++ file 'i-command-controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../source/controllers/i-command-controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'i-command-controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cm__controllers__ICommandController_t {
    QByteArrayData data[15];
    char stringdata0[377];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cm__controllers__ICommandController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cm__controllers__ICommandController_t qt_meta_stringdata_cm__controllers__ICommandController = {
    {
QT_MOC_LITERAL(0, 0, 35), // "cm::controllers::ICommandCont..."
QT_MOC_LITERAL(1, 36, 26), // "onCreateClientSaveExecuted"
QT_MOC_LITERAL(2, 63, 0), // ""
QT_MOC_LITERAL(3, 64, 26), // "onEditClientDeleteExecuted"
QT_MOC_LITERAL(4, 91, 24), // "onEditClientSaveExecuted"
QT_MOC_LITERAL(5, 116, 26), // "onFindClientSearchExecuted"
QT_MOC_LITERAL(6, 143, 20), // "onRssRefreshExecuted"
QT_MOC_LITERAL(7, 164, 17), // "setSelectedClient"
QT_MOC_LITERAL(8, 182, 19), // "cm::models::Client*"
QT_MOC_LITERAL(9, 202, 6), // "client"
QT_MOC_LITERAL(10, 209, 34), // "ui_createClientViewContextCom..."
QT_MOC_LITERAL(11, 244, 40), // "QQmlListProperty<cm::framewor..."
QT_MOC_LITERAL(12, 285, 32), // "ui_editClientViewContextCommands"
QT_MOC_LITERAL(13, 318, 32), // "ui_findClientViewContextCommands"
QT_MOC_LITERAL(14, 351, 25) // "ui_rssViewContextCommands"

    },
    "cm::controllers::ICommandController\0"
    "onCreateClientSaveExecuted\0\0"
    "onEditClientDeleteExecuted\0"
    "onEditClientSaveExecuted\0"
    "onFindClientSearchExecuted\0"
    "onRssRefreshExecuted\0setSelectedClient\0"
    "cm::models::Client*\0client\0"
    "ui_createClientViewContextCommands\0"
    "QQmlListProperty<cm::framework::Command>\0"
    "ui_editClientViewContextCommands\0"
    "ui_findClientViewContextCommands\0"
    "ui_rssViewContextCommands"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cm__controllers__ICommandController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       4,   52, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    1,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

 // properties: name, type, flags
      10, 0x80000000 | 11, 0x00095409,
      12, 0x80000000 | 11, 0x00095409,
      13, 0x80000000 | 11, 0x00095409,
      14, 0x80000000 | 11, 0x00095409,

       0        // eod
};

void cm::controllers::ICommandController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ICommandController *_t = static_cast<ICommandController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onCreateClientSaveExecuted(); break;
        case 1: _t->onEditClientDeleteExecuted(); break;
        case 2: _t->onEditClientSaveExecuted(); break;
        case 3: _t->onFindClientSearchExecuted(); break;
        case 4: _t->onRssRefreshExecuted(); break;
        case 5: _t->setSelectedClient((*reinterpret_cast< cm::models::Client*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cm::models::Client* >(); break;
            }
            break;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ICommandController *_t = static_cast<ICommandController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QQmlListProperty<cm::framework::Command>*>(_v) = _t->ui_createClientViewContextCommands(); break;
        case 1: *reinterpret_cast< QQmlListProperty<cm::framework::Command>*>(_v) = _t->ui_editClientViewContextCommands(); break;
        case 2: *reinterpret_cast< QQmlListProperty<cm::framework::Command>*>(_v) = _t->ui_findClientViewContextCommands(); break;
        case 3: *reinterpret_cast< QQmlListProperty<cm::framework::Command>*>(_v) = _t->ui_rssViewContextCommands(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject cm::controllers::ICommandController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_cm__controllers__ICommandController.data,
      qt_meta_data_cm__controllers__ICommandController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *cm::controllers::ICommandController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cm::controllers::ICommandController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cm__controllers__ICommandController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int cm::controllers::ICommandController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
