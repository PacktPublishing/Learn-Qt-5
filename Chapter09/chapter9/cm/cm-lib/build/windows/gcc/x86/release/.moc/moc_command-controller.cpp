/****************************************************************************
** Meta object code from reading C++ file 'command-controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../source/controllers/command-controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'command-controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cm__controllers__CommandController_t {
    QByteArrayData data[15];
    char stringdata0[376];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cm__controllers__CommandController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cm__controllers__CommandController_t qt_meta_stringdata_cm__controllers__CommandController = {
    {
QT_MOC_LITERAL(0, 0, 34), // "cm::controllers::CommandContr..."
QT_MOC_LITERAL(1, 35, 17), // "setSelectedClient"
QT_MOC_LITERAL(2, 53, 0), // ""
QT_MOC_LITERAL(3, 54, 19), // "cm::models::Client*"
QT_MOC_LITERAL(4, 74, 6), // "client"
QT_MOC_LITERAL(5, 81, 26), // "onCreateClientSaveExecuted"
QT_MOC_LITERAL(6, 108, 26), // "onFindClientSearchExecuted"
QT_MOC_LITERAL(7, 135, 24), // "onEditClientSaveExecuted"
QT_MOC_LITERAL(8, 160, 26), // "onEditClientDeleteExecuted"
QT_MOC_LITERAL(9, 187, 20), // "onRssRefreshExecuted"
QT_MOC_LITERAL(10, 208, 34), // "ui_createClientViewContextCom..."
QT_MOC_LITERAL(11, 243, 40), // "QQmlListProperty<cm::framewor..."
QT_MOC_LITERAL(12, 284, 32), // "ui_findClientViewContextCommands"
QT_MOC_LITERAL(13, 317, 32), // "ui_editClientViewContextCommands"
QT_MOC_LITERAL(14, 350, 25) // "ui_rssViewContextCommands"

    },
    "cm::controllers::CommandController\0"
    "setSelectedClient\0\0cm::models::Client*\0"
    "client\0onCreateClientSaveExecuted\0"
    "onFindClientSearchExecuted\0"
    "onEditClientSaveExecuted\0"
    "onEditClientDeleteExecuted\0"
    "onRssRefreshExecuted\0"
    "ui_createClientViewContextCommands\0"
    "QQmlListProperty<cm::framework::Command>\0"
    "ui_findClientViewContextCommands\0"
    "ui_editClientViewContextCommands\0"
    "ui_rssViewContextCommands"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cm__controllers__CommandController[] = {

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
       1,    1,   44,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,
       8,    0,   50,    2, 0x0a /* Public */,
       9,    0,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      10, 0x80000000 | 11, 0x00095409,
      12, 0x80000000 | 11, 0x00095409,
      13, 0x80000000 | 11, 0x00095409,
      14, 0x80000000 | 11, 0x00095409,

       0        // eod
};

void cm::controllers::CommandController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CommandController *_t = static_cast<CommandController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setSelectedClient((*reinterpret_cast< cm::models::Client*(*)>(_a[1]))); break;
        case 1: _t->onCreateClientSaveExecuted(); break;
        case 2: _t->onFindClientSearchExecuted(); break;
        case 3: _t->onEditClientSaveExecuted(); break;
        case 4: _t->onEditClientDeleteExecuted(); break;
        case 5: _t->onRssRefreshExecuted(); break;
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
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        CommandController *_t = static_cast<CommandController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QQmlListProperty<cm::framework::Command>*>(_v) = _t->ui_createClientViewContextCommands(); break;
        case 1: *reinterpret_cast< QQmlListProperty<cm::framework::Command>*>(_v) = _t->ui_findClientViewContextCommands(); break;
        case 2: *reinterpret_cast< QQmlListProperty<cm::framework::Command>*>(_v) = _t->ui_editClientViewContextCommands(); break;
        case 3: *reinterpret_cast< QQmlListProperty<cm::framework::Command>*>(_v) = _t->ui_rssViewContextCommands(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject cm::controllers::CommandController::staticMetaObject = {
    { &ICommandController::staticMetaObject, qt_meta_stringdata_cm__controllers__CommandController.data,
      qt_meta_data_cm__controllers__CommandController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *cm::controllers::CommandController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cm::controllers::CommandController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cm__controllers__CommandController.stringdata0))
        return static_cast<void*>(this);
    return ICommandController::qt_metacast(_clname);
}

int cm::controllers::CommandController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ICommandController::qt_metacall(_c, _id, _a);
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
