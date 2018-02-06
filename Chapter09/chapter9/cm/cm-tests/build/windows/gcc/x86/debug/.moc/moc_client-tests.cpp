/****************************************************************************
** Meta object code from reading C++ file 'client-tests.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../source/models/client-tests.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client-tests.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cm__models__ClientTests_t {
    QByteArrayData data[10];
    char stringdata0[410];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cm__models__ClientTests_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cm__models__ClientTests_t qt_meta_stringdata_cm__models__ClientTests = {
    {
QT_MOC_LITERAL(0, 0, 23), // "cm::models::ClientTests"
QT_MOC_LITERAL(1, 24, 54), // "constructor_givenParent_setsP..."
QT_MOC_LITERAL(2, 79, 0), // ""
QT_MOC_LITERAL(3, 80, 60), // "constructor_givenParentAndJso..."
QT_MOC_LITERAL(4, 141, 43), // "toJson_withDefaultProperties_..."
QT_MOC_LITERAL(5, 185, 39), // "toJson_withSetProperties_cons..."
QT_MOC_LITERAL(6, 225, 40), // "update_givenJsonObject_update..."
QT_MOC_LITERAL(7, 266, 55), // "update_givenEmptyJsonObject_u..."
QT_MOC_LITERAL(8, 322, 41), // "id_givenPrimaryKeyWithNoValue..."
QT_MOC_LITERAL(9, 364, 45) // "id_givenPrimaryKeyWithValue_r..."

    },
    "cm::models::ClientTests\0"
    "constructor_givenParent_setsParentAndDefaultProperties\0"
    "\0constructor_givenParentAndJsonObject_setsParentAndProperties\0"
    "toJson_withDefaultProperties_constructsJson\0"
    "toJson_withSetProperties_constructsJson\0"
    "update_givenJsonObject_updatesProperties\0"
    "update_givenEmptyJsonObject_updatesPropertiesToDefaults\0"
    "id_givenPrimaryKeyWithNoValue_returnsUuid\0"
    "id_givenPrimaryKeyWithValue_returnsPrimaryKey"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cm__models__ClientTests[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void cm::models::ClientTests::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClientTests *_t = static_cast<ClientTests *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->constructor_givenParent_setsParentAndDefaultProperties(); break;
        case 1: _t->constructor_givenParentAndJsonObject_setsParentAndProperties(); break;
        case 2: _t->toJson_withDefaultProperties_constructsJson(); break;
        case 3: _t->toJson_withSetProperties_constructsJson(); break;
        case 4: _t->update_givenJsonObject_updatesProperties(); break;
        case 5: _t->update_givenEmptyJsonObject_updatesPropertiesToDefaults(); break;
        case 6: _t->id_givenPrimaryKeyWithNoValue_returnsUuid(); break;
        case 7: _t->id_givenPrimaryKeyWithValue_returnsPrimaryKey(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject cm::models::ClientTests::staticMetaObject = {
    { &TestSuite::staticMetaObject, qt_meta_stringdata_cm__models__ClientTests.data,
      qt_meta_data_cm__models__ClientTests,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *cm::models::ClientTests::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cm::models::ClientTests::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cm__models__ClientTests.stringdata0))
        return static_cast<void*>(this);
    return TestSuite::qt_metacast(_clname);
}

int cm::models::ClientTests::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TestSuite::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
