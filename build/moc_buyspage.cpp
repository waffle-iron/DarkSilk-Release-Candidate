/****************************************************************************
** Meta object code from reading C++ file 'buyspage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qt/buyspage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'buyspage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BuysPage_t {
    QByteArrayData data[9];
    char stringdata[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BuysPage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BuysPage_t qt_meta_stringdata_BuysPage = {
    {
QT_MOC_LITERAL(0, 0, 8), // "BuysPage"
QT_MOC_LITERAL(1, 9, 8), // "LoadBuys"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 35), // "on_tableWidget_itemSelectionC..."
QT_MOC_LITERAL(4, 55, 28), // "on_copyAddressButton_clicked"
QT_MOC_LITERAL(5, 84, 27), // "on_escrowLockButton_clicked"
QT_MOC_LITERAL(6, 112, 32), // "on_deliveryDetailsButton_clicked"
QT_MOC_LITERAL(7, 145, 20), // "on_payButton_clicked"
QT_MOC_LITERAL(8, 166, 23) // "on_refundButton_clicked"

    },
    "BuysPage\0LoadBuys\0\0"
    "on_tableWidget_itemSelectionChanged\0"
    "on_copyAddressButton_clicked\0"
    "on_escrowLockButton_clicked\0"
    "on_deliveryDetailsButton_clicked\0"
    "on_payButton_clicked\0on_refundButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BuysPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BuysPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BuysPage *_t = static_cast<BuysPage *>(_o);
        switch (_id) {
        case 0: _t->LoadBuys(); break;
        case 1: _t->on_tableWidget_itemSelectionChanged(); break;
        case 2: _t->on_copyAddressButton_clicked(); break;
        case 3: _t->on_escrowLockButton_clicked(); break;
        case 4: _t->on_deliveryDetailsButton_clicked(); break;
        case 5: _t->on_payButton_clicked(); break;
        case 6: _t->on_refundButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject BuysPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BuysPage.data,
      qt_meta_data_BuysPage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BuysPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BuysPage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BuysPage.stringdata))
        return static_cast<void*>(const_cast< BuysPage*>(this));
    return QWidget::qt_metacast(_clname);
}

int BuysPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
