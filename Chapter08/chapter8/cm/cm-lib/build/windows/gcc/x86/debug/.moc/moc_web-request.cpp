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
    QByteArrayData data[13];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cm__networking__WebRequest_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cm__networking__WebRequest_t qt_meta_stringdata_cm__networking__WebRequest = {
    {
QT_MOC_LITERAL(0, 0, 26), // "cm::networking::WebRequest"
QT_MOC_LITERAL(1, 27, 5), // "error"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 7), // "message"
QT_MOC_LITERAL(4, 42, 13), // "isBusyChanged"
QT_MOC_LITERAL(5, 56, 15), // "requestComplete"
QT_MOC_LITERAL(6, 72, 10), // "statusCode"
QT_MOC_LITERAL(7, 83, 4), // "body"
QT_MOC_LITERAL(8, 88, 10), // "urlChanged"
QT_MOC_LITERAL(9, 99, 13), // "replyDelegate"
QT_MOC_LITERAL(10, 113, 17), // "sslErrorsDelegate"
QT_MOC_LITERAL(11, 131, 16), // "QList<QSslError>"
QT_MOC_LITERAL(12, 148, 7) // "_errors"

    },
    "cm::networking::WebRequest\0error\0\0"
    "message\0isBusyChanged\0requestComplete\0"
    "statusCode\0body\0urlChanged\0replyDelegate\0"
    "sslErrorsDelegate\0QList<QSslError>\0"
    "_errors"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cm__networking__WebRequest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,
       5,    2,   48,    2, 0x06 /* Public */,
       8,    0,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   54,    2, 0x08 /* Private */,
      10,    1,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray,    6,    7,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void cm::networking::WebRequest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WebRequest *_t = static_cast<WebRequest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->isBusyChanged(); break;
        case 2: _t->requestComplete((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 3: _t->urlChanged(); break;
        case 4: _t->replyDelegate(); break;
        case 5: _t->sslErrorsDelegate((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSslError> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (WebRequest::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebRequest::error)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WebRequest::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebRequest::isBusyChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (WebRequest::*_t)(int , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebRequest::requestComplete)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (WebRequest::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebRequest::urlChanged)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject cm::networking::WebRequest::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_cm__networking__WebRequest.data,
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
    if (!strcmp(_clname, "IWebRequest"))
        return static_cast< IWebRequest*>(this);
    return QObject::qt_metacast(_clname);
}

int cm::networking::WebRequest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void cm::networking::WebRequest::error(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void cm::networking::WebRequest::isBusyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void cm::networking::WebRequest::requestComplete(int _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void cm::networking::WebRequest::urlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
