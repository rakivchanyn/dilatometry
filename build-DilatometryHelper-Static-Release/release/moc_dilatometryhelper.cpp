/****************************************************************************
** Meta object code from reading C++ file 'dilatometryhelper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DilatometryHelper/dilatometryhelper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dilatometryhelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DilatometryHelper_t {
    QByteArrayData data[8];
    char stringdata[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_DilatometryHelper_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_DilatometryHelper_t qt_meta_stringdata_DilatometryHelper = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 22),
QT_MOC_LITERAL(2, 41, 0),
QT_MOC_LITERAL(3, 42, 22),
QT_MOC_LITERAL(4, 65, 25),
QT_MOC_LITERAL(5, 91, 36),
QT_MOC_LITERAL(6, 128, 31),
QT_MOC_LITERAL(7, 160, 29)
    },
    "DilatometryHelper\0on_pbOpenTempr_clicked\0"
    "\0on_pbOpenDilat_clicked\0"
    "on_pbStartProcess_clicked\0"
    "on_leFinalValueDilat_editingFinished\0"
    "on_leStartHight_editingFinished\0"
    "on_leFinHight_editingFinished\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DilatometryHelper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08,
       3,    0,   45,    2, 0x08,
       4,    0,   46,    2, 0x08,
       5,    0,   47,    2, 0x08,
       6,    0,   48,    2, 0x08,
       7,    0,   49,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DilatometryHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DilatometryHelper *_t = static_cast<DilatometryHelper *>(_o);
        switch (_id) {
        case 0: _t->on_pbOpenTempr_clicked(); break;
        case 1: _t->on_pbOpenDilat_clicked(); break;
        case 2: _t->on_pbStartProcess_clicked(); break;
        case 3: _t->on_leFinalValueDilat_editingFinished(); break;
        case 4: _t->on_leStartHight_editingFinished(); break;
        case 5: _t->on_leFinHight_editingFinished(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject DilatometryHelper::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DilatometryHelper.data,
      qt_meta_data_DilatometryHelper,  qt_static_metacall, 0, 0}
};


const QMetaObject *DilatometryHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DilatometryHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DilatometryHelper.stringdata))
        return static_cast<void*>(const_cast< DilatometryHelper*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int DilatometryHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
