/****************************************************************************
** Meta object code from reading C++ file 'darksilkmarket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qt/darksilkmarket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'darksilkmarket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DarkSilkMarket_t {
    QByteArrayData data[12];
    char stringdata[232];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DarkSilkMarket_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DarkSilkMarket_t qt_meta_stringdata_DarkSilkMarket = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DarkSilkMarket"
QT_MOC_LITERAL(1, 15, 14), // "updateCategory"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8), // "category"
QT_MOC_LITERAL(4, 40, 35), // "on_tableWidget_itemSelectionC..."
QT_MOC_LITERAL(5, 76, 42), // "on_categoriesListWidget_curre..."
QT_MOC_LITERAL(6, 119, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(7, 136, 7), // "current"
QT_MOC_LITERAL(8, 144, 8), // "previous"
QT_MOC_LITERAL(9, 153, 20), // "on_buyButton_clicked"
QT_MOC_LITERAL(10, 174, 28), // "on_viewDetailsButton_clicked"
QT_MOC_LITERAL(11, 203, 28) // "on_copyAddressButton_clicked"

    },
    "DarkSilkMarket\0updateCategory\0\0category\0"
    "on_tableWidget_itemSelectionChanged\0"
    "on_categoriesListWidget_currentItemChanged\0"
    "QListWidgetItem*\0current\0previous\0"
    "on_buyButton_clicked\0on_viewDetailsButton_clicked\0"
    "on_copyAddressButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DarkSilkMarket[] = {

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
       1,    1,   44,    2, 0x0a /* Public */,
       4,    0,   47,    2, 0x08 /* Private */,
       5,    2,   48,    2, 0x08 /* Private */,
       9,    0,   53,    2, 0x08 /* Private */,
      10,    0,   54,    2, 0x08 /* Private */,
      11,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DarkSilkMarket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DarkSilkMarket *_t = static_cast<DarkSilkMarket *>(_o);
        switch (_id) {
        case 0: _t->updateCategory((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_tableWidget_itemSelectionChanged(); break;
        case 2: _t->on_categoriesListWidget_currentItemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 3: _t->on_buyButton_clicked(); break;
        case 4: _t->on_viewDetailsButton_clicked(); break;
        case 5: _t->on_copyAddressButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject DarkSilkMarket::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DarkSilkMarket.data,
      qt_meta_data_DarkSilkMarket,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DarkSilkMarket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DarkSilkMarket::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DarkSilkMarket.stringdata))
        return static_cast<void*>(const_cast< DarkSilkMarket*>(this));
    return QWidget::qt_metacast(_clname);
}

int DarkSilkMarket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
