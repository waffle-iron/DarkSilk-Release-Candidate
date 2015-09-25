/****************************************************************************
** Meta object code from reading C++ file 'sellspage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qt/sellspage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sellspage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SellsPage_t {
    QByteArrayData data[20];
    char stringdata[371];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SellsPage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SellsPage_t qt_meta_stringdata_SellsPage = {
    {
QT_MOC_LITERAL(0, 0, 9), // "SellsPage"
QT_MOC_LITERAL(1, 10, 13), // "updateListing"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 2), // "id"
QT_MOC_LITERAL(4, 28, 7), // "expires"
QT_MOC_LITERAL(5, 36, 5), // "price"
QT_MOC_LITERAL(6, 42, 5), // "title"
QT_MOC_LITERAL(7, 48, 9), // "LoadSells"
QT_MOC_LITERAL(8, 58, 15), // "LoadBuyRequests"
QT_MOC_LITERAL(9, 74, 1), // "q"
QT_MOC_LITERAL(10, 76, 23), // "on_createButton_clicked"
QT_MOC_LITERAL(11, 100, 43), // "on_listingsTableWidget_itemSe..."
QT_MOC_LITERAL(12, 144, 39), // "on_buysTableWidget_itemSelect..."
QT_MOC_LITERAL(13, 184, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(14, 208, 28), // "on_copyAddressButton_clicked"
QT_MOC_LITERAL(15, 237, 23), // "on_acceptButton_clicked"
QT_MOC_LITERAL(16, 261, 23), // "on_rejectButton_clicked"
QT_MOC_LITERAL(17, 285, 23), // "on_refundButton_clicked"
QT_MOC_LITERAL(18, 309, 31), // "on_requestPaymentButton_clicked"
QT_MOC_LITERAL(19, 341, 29) // "on_cancelEscrowButton_clicked"

    },
    "SellsPage\0updateListing\0\0id\0expires\0"
    "price\0title\0LoadSells\0LoadBuyRequests\0"
    "q\0on_createButton_clicked\0"
    "on_listingsTableWidget_itemSelectionChanged\0"
    "on_buysTableWidget_itemSelectionChanged\0"
    "on_cancelButton_clicked\0"
    "on_copyAddressButton_clicked\0"
    "on_acceptButton_clicked\0on_rejectButton_clicked\0"
    "on_refundButton_clicked\0"
    "on_requestPaymentButton_clicked\0"
    "on_cancelEscrowButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SellsPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   84,    2, 0x0a /* Public */,
       7,    0,   93,    2, 0x0a /* Public */,
       8,    1,   94,    2, 0x0a /* Public */,
       8,    0,   97,    2, 0x2a /* Public | MethodCloned */,
      10,    0,   98,    2, 0x08 /* Private */,
      11,    0,   99,    2, 0x08 /* Private */,
      12,    0,  100,    2, 0x08 /* Private */,
      13,    0,  101,    2, 0x08 /* Private */,
      14,    0,  102,    2, 0x08 /* Private */,
      15,    0,  103,    2, 0x08 /* Private */,
      16,    0,  104,    2, 0x08 /* Private */,
      17,    0,  105,    2, 0x08 /* Private */,
      18,    0,  106,    2, 0x08 /* Private */,
      19,    0,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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

void SellsPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SellsPage *_t = static_cast<SellsPage *>(_o);
        switch (_id) {
        case 0: _t->updateListing((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->LoadSells(); break;
        case 2: _t->LoadBuyRequests((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->LoadBuyRequests(); break;
        case 4: _t->on_createButton_clicked(); break;
        case 5: _t->on_listingsTableWidget_itemSelectionChanged(); break;
        case 6: _t->on_buysTableWidget_itemSelectionChanged(); break;
        case 7: _t->on_cancelButton_clicked(); break;
        case 8: _t->on_copyAddressButton_clicked(); break;
        case 9: _t->on_acceptButton_clicked(); break;
        case 10: _t->on_rejectButton_clicked(); break;
        case 11: _t->on_refundButton_clicked(); break;
        case 12: _t->on_requestPaymentButton_clicked(); break;
        case 13: _t->on_cancelEscrowButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject SellsPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SellsPage.data,
      qt_meta_data_SellsPage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SellsPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SellsPage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SellsPage.stringdata))
        return static_cast<void*>(const_cast< SellsPage*>(this));
    return QWidget::qt_metacast(_clname);
}

int SellsPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
