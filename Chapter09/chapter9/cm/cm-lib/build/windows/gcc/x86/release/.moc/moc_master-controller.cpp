/****************************************************************************
** Meta object code from reading C++ file 'master-controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../source/controllers/master-controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'master-controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cm__controllers__MasterController_t {
    QByteArrayData data[21];
    char stringdata0[418];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cm__controllers__MasterController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cm__controllers__MasterController_t qt_meta_stringdata_cm__controllers__MasterController = {
    {
QT_MOC_LITERAL(0, 0, 33), // "cm::controllers::MasterContro..."
QT_MOC_LITERAL(1, 34, 17), // "rssChannelChanged"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 12), // "selectClient"
QT_MOC_LITERAL(4, 66, 19), // "cm::models::Client*"
QT_MOC_LITERAL(5, 86, 6), // "client"
QT_MOC_LITERAL(6, 93, 18), // "onRssReplyReceived"
QT_MOC_LITERAL(7, 112, 10), // "statusCode"
QT_MOC_LITERAL(8, 123, 4), // "body"
QT_MOC_LITERAL(9, 128, 17), // "ui_welcomeMessage"
QT_MOC_LITERAL(10, 146, 23), // "ui_navigationController"
QT_MOC_LITERAL(11, 170, 39), // "cm::controllers::INavigationC..."
QT_MOC_LITERAL(12, 210, 20), // "ui_commandController"
QT_MOC_LITERAL(13, 231, 36), // "cm::controllers::ICommandCont..."
QT_MOC_LITERAL(14, 268, 21), // "ui_databaseController"
QT_MOC_LITERAL(15, 290, 37), // "cm::controllers::IDatabaseCon..."
QT_MOC_LITERAL(16, 328, 12), // "ui_newClient"
QT_MOC_LITERAL(17, 341, 15), // "ui_clientSearch"
QT_MOC_LITERAL(18, 357, 25), // "cm::models::ClientSearch*"
QT_MOC_LITERAL(19, 383, 13), // "ui_rssChannel"
QT_MOC_LITERAL(20, 397, 20) // "cm::rss::RssChannel*"

    },
    "cm::controllers::MasterController\0"
    "rssChannelChanged\0\0selectClient\0"
    "cm::models::Client*\0client\0"
    "onRssReplyReceived\0statusCode\0body\0"
    "ui_welcomeMessage\0ui_navigationController\0"
    "cm::controllers::INavigationController*\0"
    "ui_commandController\0"
    "cm::controllers::ICommandController*\0"
    "ui_databaseController\0"
    "cm::controllers::IDatabaseController*\0"
    "ui_newClient\0ui_clientSearch\0"
    "cm::models::ClientSearch*\0ui_rssChannel\0"
    "cm::rss::RssChannel*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cm__controllers__MasterController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       7,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   30,    2, 0x0a /* Public */,
       6,    2,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray,    7,    8,

 // properties: name, type, flags
       9, QMetaType::QString, 0x00095401,
      10, 0x80000000 | 11, 0x00095409,
      12, 0x80000000 | 13, 0x00095409,
      14, 0x80000000 | 15, 0x00095409,
      16, 0x80000000 | 4, 0x00095409,
      17, 0x80000000 | 18, 0x00095409,
      19, 0x80000000 | 20, 0x00495009,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,
       0,
       0,

       0        // eod
};

void cm::controllers::MasterController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MasterController *_t = static_cast<MasterController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rssChannelChanged(); break;
        case 1: _t->selectClient((*reinterpret_cast< cm::models::Client*(*)>(_a[1]))); break;
        case 2: _t->onRssReplyReceived((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
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
            typedef void (MasterController::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MasterController::rssChannelChanged)) {
                *result = 0;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cm::controllers::ICommandController* >(); break;
        case 3:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cm::controllers::IDatabaseController* >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cm::controllers::INavigationController* >(); break;
        case 4:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cm::models::Client* >(); break;
        case 5:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cm::models::ClientSearch* >(); break;
        case 6:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cm::rss::RssChannel* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        MasterController *_t = static_cast<MasterController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->welcomeMessage(); break;
        case 1: *reinterpret_cast< cm::controllers::INavigationController**>(_v) = _t->navigationController(); break;
        case 2: *reinterpret_cast< cm::controllers::ICommandController**>(_v) = _t->commandController(); break;
        case 3: *reinterpret_cast< cm::controllers::IDatabaseController**>(_v) = _t->databaseController(); break;
        case 4: *reinterpret_cast< cm::models::Client**>(_v) = _t->newClient(); break;
        case 5: *reinterpret_cast< cm::models::ClientSearch**>(_v) = _t->clientSearch(); break;
        case 6: *reinterpret_cast< cm::rss::RssChannel**>(_v) = _t->rssChannel(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject cm::controllers::MasterController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_cm__controllers__MasterController.data,
      qt_meta_data_cm__controllers__MasterController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *cm::controllers::MasterController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cm::controllers::MasterController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cm__controllers__MasterController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int cm::controllers::MasterController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void cm::controllers::MasterController::rssChannelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
