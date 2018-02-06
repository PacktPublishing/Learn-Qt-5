/****************************************************************************
** Meta object code from reading C++ file 'rss-channel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../source/rss/rss-channel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rss-channel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cm__rss__RssChannel_t {
    QByteArrayData data[8];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cm__rss__RssChannel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cm__rss__RssChannel_t qt_meta_stringdata_cm__rss__RssChannel = {
    {
QT_MOC_LITERAL(0, 0, 19), // "cm::rss::RssChannel"
QT_MOC_LITERAL(1, 20, 14), // "ui_description"
QT_MOC_LITERAL(2, 35, 8), // "ui_image"
QT_MOC_LITERAL(3, 44, 18), // "cm::rss::RssImage*"
QT_MOC_LITERAL(4, 63, 8), // "ui_items"
QT_MOC_LITERAL(5, 72, 34), // "QQmlListProperty<cm::rss::Rss..."
QT_MOC_LITERAL(6, 107, 7), // "ui_link"
QT_MOC_LITERAL(7, 115, 8) // "ui_title"

    },
    "cm::rss::RssChannel\0ui_description\0"
    "ui_image\0cm::rss::RssImage*\0ui_items\0"
    "QQmlListProperty<cm::rss::RssItem>\0"
    "ui_link\0ui_title"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cm__rss__RssChannel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       5,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095401,
       2, 0x80000000 | 3, 0x00095409,
       4, 0x80000000 | 5, 0x00095409,
       6, QMetaType::QString, 0x00095401,
       7, QMetaType::QString, 0x00095401,

       0        // eod
};

void cm::rss::RssChannel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< cm::rss::RssImage* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        RssChannel *_t = static_cast<RssChannel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->description(); break;
        case 1: *reinterpret_cast< cm::rss::RssImage**>(_v) = _t->image(); break;
        case 2: *reinterpret_cast< QQmlListProperty<cm::rss::RssItem>*>(_v) = _t->ui_items(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->link(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->title(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
}

const QMetaObject cm::rss::RssChannel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_cm__rss__RssChannel.data,
      qt_meta_data_cm__rss__RssChannel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *cm::rss::RssChannel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cm::rss::RssChannel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cm__rss__RssChannel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int cm::rss::RssChannel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
