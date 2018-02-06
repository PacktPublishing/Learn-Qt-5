/****************************************************************************
** Meta object code from reading C++ file 'web-request.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../source/networking/web-request.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'web-request.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cm__networking__WebRequest_t {
    QByteArrayData data[6];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cm__networking__WebRequest_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cm__networking__WebRequest_t qt_meta_stringdata_cm__networking__WebRequest = {
    {
QT_MOC_LITERAL(0, 0, 26), // "cm::networking::WebRequest"
QT_MOC_LITERAL(1, 27, 13), // "replyDelegate"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 17), // "sslErrorsDelegate"
QT_MOC_LITERAL(4, 60, 16), // "QList<QSslError>"
QT_MOC_LITERAL(5, 77, 7) // "_errors"

    },
    "cm::networking::WebRequest\0replyDelegate\0"
    "\0sslErrorsDelegate\0QList<QSslError>\0"
    "_errors"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cm__networking__WebRequest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x08 /* Private */,
       3,    1,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void cm::networking::WebRequest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WebRequest *_t = static_cast<WebRequest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->replyDelegate(); break;
        case 1: _t->sslErrorsDelegate((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSslError> >(); break;
            }
            break;
        }
    }
}

const QMetaObject cm::networking::WebRequest::staticMetaObject = {
    { &IWebRequest::staticMetaObject, qt_meta_stringdata_cm__networking__WebRequest.data,
      qt_meta_data_cm__networking__WebRequest,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *cm::networking::WebRequest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cm::networking::WebRequest::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cm__networking__WebRequest.stringdata0))
        return static_cast<void*>(this);
    return IWebRequest::qt_metacast(_clname);
}

int cm::networking::WebRequest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IWebRequest::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
