/****************************************************************************
** Meta object code from reading C++ file 'int-decorator-tests.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../source/data/int-decorator-tests.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'int-decorator-tests.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cm__data__IntDecoratorTests_t {
    QByteArrayData data[10];
    char stringdata0[374];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cm__data__IntDecoratorTests_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cm__data__IntDecoratorTests_t qt_meta_stringdata_cm__data__IntDecoratorTests = {
    {
QT_MOC_LITERAL(0, 0, 27), // "cm::data::IntDecoratorTests"
QT_MOC_LITERAL(1, 28, 51), // "constructor_givenNoParameters..."
QT_MOC_LITERAL(2, 80, 0), // ""
QT_MOC_LITERAL(3, 81, 42), // "constructor_givenParameters_s..."
QT_MOC_LITERAL(4, 124, 49), // "setValue_givenNewValue_update..."
QT_MOC_LITERAL(5, 174, 37), // "setValue_givenSameValue_takes..."
QT_MOC_LITERAL(6, 212, 38), // "jsonValue_whenDefaultValue_re..."
QT_MOC_LITERAL(7, 251, 34), // "jsonValue_whenValueSet_return..."
QT_MOC_LITERAL(8, 286, 37), // "update_whenPresentInJson_upda..."
QT_MOC_LITERAL(9, 324, 49) // "update_whenNotPresentInJson_u..."

    },
    "cm::data::IntDecoratorTests\0"
    "constructor_givenNoParameters_setsDefaultProperties\0"
    "\0constructor_givenParameters_setsProperties\0"
    "setValue_givenNewValue_updatesValueAndEmitsSignal\0"
    "setValue_givenSameValue_takesNoAction\0"
    "jsonValue_whenDefaultValue_returnsJson\0"
    "jsonValue_whenValueSet_returnsJson\0"
    "update_whenPresentInJson_updatesValue\0"
    "update_whenNotPresentInJson_updatesValueToDefault"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cm__data__IntDecoratorTests[] = {

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

void cm::data::IntDecoratorTests::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IntDecoratorTests *_t = static_cast<IntDecoratorTests *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->constructor_givenNoParameters_setsDefaultProperties(); break;
        case 1: _t->constructor_givenParameters_setsProperties(); break;
        case 2: _t->setValue_givenNewValue_updatesValueAndEmitsSignal(); break;
        case 3: _t->setValue_givenSameValue_takesNoAction(); break;
        case 4: _t->jsonValue_whenDefaultValue_returnsJson(); break;
        case 5: _t->jsonValue_whenValueSet_returnsJson(); break;
        case 6: _t->update_whenPresentInJson_updatesValue(); break;
        case 7: _t->update_whenNotPresentInJson_updatesValueToDefault(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject cm::data::IntDecoratorTests::staticMetaObject = {
    { &TestSuite::staticMetaObject, qt_meta_stringdata_cm__data__IntDecoratorTests.data,
      qt_meta_data_cm__data__IntDecoratorTests,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *cm::data::IntDecoratorTests::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cm::data::IntDecoratorTests::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cm__data__IntDecoratorTests.stringdata0))
        return static_cast<void*>(this);
    return TestSuite::qt_metacast(_clname);
}

int cm::data::IntDecoratorTests::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
