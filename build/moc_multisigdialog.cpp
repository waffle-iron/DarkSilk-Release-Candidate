/****************************************************************************
** Meta object code from reading C++ file 'multisigdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qt/multisigdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'multisigdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MultisigDialog_t {
    QByteArrayData data[25];
    char stringdata[568];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MultisigDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MultisigDialog_t qt_meta_stringdata_MultisigDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MultisigDialog"
QT_MOC_LITERAL(1, 15, 9), // "addPubKey"
QT_MOC_LITERAL(2, 25, 21), // "MultisigAddressEntry*"
QT_MOC_LITERAL(3, 47, 0), // ""
QT_MOC_LITERAL(4, 48, 5), // "clear"
QT_MOC_LITERAL(5, 54, 19), // "updateRemoveEnabled"
QT_MOC_LITERAL(6, 74, 8), // "addInput"
QT_MOC_LITERAL(7, 83, 19), // "MultisigInputEntry*"
QT_MOC_LITERAL(8, 103, 9), // "addOutput"
QT_MOC_LITERAL(9, 113, 15), // "SendCoinsEntry*"
QT_MOC_LITERAL(10, 129, 30), // "on_createAddressButton_clicked"
QT_MOC_LITERAL(11, 160, 36), // "on_copyMultisigAddressButton_..."
QT_MOC_LITERAL(12, 197, 33), // "on_copyRedeemScriptButton_cli..."
QT_MOC_LITERAL(13, 231, 33), // "on_saveRedeemScriptButton_cli..."
QT_MOC_LITERAL(14, 265, 36), // "on_saveMultisigAddressButton_..."
QT_MOC_LITERAL(15, 302, 11), // "removeEntry"
QT_MOC_LITERAL(16, 314, 5), // "entry"
QT_MOC_LITERAL(17, 320, 34), // "on_createTransactionButton_cl..."
QT_MOC_LITERAL(18, 355, 26), // "on_transaction_textChanged"
QT_MOC_LITERAL(19, 382, 32), // "on_copyTransactionButton_clicked"
QT_MOC_LITERAL(20, 415, 33), // "on_pasteTransactionButton_cli..."
QT_MOC_LITERAL(21, 449, 32), // "on_signTransactionButton_clicked"
QT_MOC_LITERAL(22, 482, 38), // "on_copySignedTransactionButto..."
QT_MOC_LITERAL(23, 521, 32), // "on_sendTransactionButton_clicked"
QT_MOC_LITERAL(24, 554, 13) // "updateAmounts"

    },
    "MultisigDialog\0addPubKey\0MultisigAddressEntry*\0"
    "\0clear\0updateRemoveEnabled\0addInput\0"
    "MultisigInputEntry*\0addOutput\0"
    "SendCoinsEntry*\0on_createAddressButton_clicked\0"
    "on_copyMultisigAddressButton_clicked\0"
    "on_copyRedeemScriptButton_clicked\0"
    "on_saveRedeemScriptButton_clicked\0"
    "on_saveMultisigAddressButton_clicked\0"
    "removeEntry\0entry\0on_createTransactionButton_clicked\0"
    "on_transaction_textChanged\0"
    "on_copyTransactionButton_clicked\0"
    "on_pasteTransactionButton_clicked\0"
    "on_signTransactionButton_clicked\0"
    "on_copySignedTransactionButton_clicked\0"
    "on_sendTransactionButton_clicked\0"
    "updateAmounts"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MultisigDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  119,    3, 0x0a /* Public */,
       4,    0,  120,    3, 0x0a /* Public */,
       5,    0,  121,    3, 0x0a /* Public */,
       6,    0,  122,    3, 0x0a /* Public */,
       8,    0,  123,    3, 0x0a /* Public */,
      10,    0,  124,    3, 0x08 /* Private */,
      11,    0,  125,    3, 0x08 /* Private */,
      12,    0,  126,    3, 0x08 /* Private */,
      13,    0,  127,    3, 0x08 /* Private */,
      14,    0,  128,    3, 0x08 /* Private */,
      15,    1,  129,    3, 0x08 /* Private */,
      17,    0,  132,    3, 0x08 /* Private */,
      18,    0,  133,    3, 0x08 /* Private */,
      19,    0,  134,    3, 0x08 /* Private */,
      20,    0,  135,    3, 0x08 /* Private */,
      21,    0,  136,    3, 0x08 /* Private */,
      22,    0,  137,    3, 0x08 /* Private */,
      23,    0,  138,    3, 0x08 /* Private */,
      15,    1,  139,    3, 0x08 /* Private */,
      15,    1,  142,    3, 0x08 /* Private */,
      24,    0,  145,    3, 0x08 /* Private */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 7,
    0x80000000 | 9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 2,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,   16,
    QMetaType::Void, 0x80000000 | 9,   16,
    QMetaType::Void,

       0        // eod
};

void MultisigDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MultisigDialog *_t = static_cast<MultisigDialog *>(_o);
        switch (_id) {
        case 0: { MultisigAddressEntry* _r = _t->addPubKey();
            if (_a[0]) *reinterpret_cast< MultisigAddressEntry**>(_a[0]) = _r; }  break;
        case 1: _t->clear(); break;
        case 2: _t->updateRemoveEnabled(); break;
        case 3: { MultisigInputEntry* _r = _t->addInput();
            if (_a[0]) *reinterpret_cast< MultisigInputEntry**>(_a[0]) = _r; }  break;
        case 4: { SendCoinsEntry* _r = _t->addOutput();
            if (_a[0]) *reinterpret_cast< SendCoinsEntry**>(_a[0]) = _r; }  break;
        case 5: _t->on_createAddressButton_clicked(); break;
        case 6: _t->on_copyMultisigAddressButton_clicked(); break;
        case 7: _t->on_copyRedeemScriptButton_clicked(); break;
        case 8: _t->on_saveRedeemScriptButton_clicked(); break;
        case 9: _t->on_saveMultisigAddressButton_clicked(); break;
        case 10: _t->removeEntry((*reinterpret_cast< MultisigAddressEntry*(*)>(_a[1]))); break;
        case 11: _t->on_createTransactionButton_clicked(); break;
        case 12: _t->on_transaction_textChanged(); break;
        case 13: _t->on_copyTransactionButton_clicked(); break;
        case 14: _t->on_pasteTransactionButton_clicked(); break;
        case 15: _t->on_signTransactionButton_clicked(); break;
        case 16: _t->on_copySignedTransactionButton_clicked(); break;
        case 17: _t->on_sendTransactionButton_clicked(); break;
        case 18: _t->removeEntry((*reinterpret_cast< MultisigInputEntry*(*)>(_a[1]))); break;
        case 19: _t->removeEntry((*reinterpret_cast< SendCoinsEntry*(*)>(_a[1]))); break;
        case 20: _t->updateAmounts(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MultisigAddressEntry* >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MultisigInputEntry* >(); break;
            }
            break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SendCoinsEntry* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MultisigDialog::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MultisigDialog.data,
      qt_meta_data_MultisigDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MultisigDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MultisigDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MultisigDialog.stringdata))
        return static_cast<void*>(const_cast< MultisigDialog*>(this));
    return QWidget::qt_metacast(_clname);
}

int MultisigDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
