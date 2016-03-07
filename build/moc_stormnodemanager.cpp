/****************************************************************************
** Meta object code from reading C++ file 'stormnodemanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qt/stormnodemanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stormnodemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StormnodeManager_t {
    QByteArrayData data[15];
    char stringdata[225];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StormnodeManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StormnodeManager_t qt_meta_stringdata_StormnodeManager = {
    {
QT_MOC_LITERAL(0, 0, 16), // "StormnodeManager"
QT_MOC_LITERAL(1, 17, 14), // "updateNodeList"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 15), // "updateStormNode"
QT_MOC_LITERAL(4, 49, 5), // "alias"
QT_MOC_LITERAL(5, 55, 4), // "addr"
QT_MOC_LITERAL(6, 60, 7), // "privkey"
QT_MOC_LITERAL(7, 68, 6), // "txHash"
QT_MOC_LITERAL(8, 75, 7), // "txIndex"
QT_MOC_LITERAL(9, 83, 6), // "status"
QT_MOC_LITERAL(10, 90, 23), // "on_UpdateButton_clicked"
QT_MOC_LITERAL(11, 114, 23), // "on_createButton_clicked"
QT_MOC_LITERAL(12, 138, 22), // "on_startButton_clicked"
QT_MOC_LITERAL(13, 161, 25), // "on_startAllButton_clicked"
QT_MOC_LITERAL(14, 187, 37) // "on_tableWidget_2_itemSelectio..."

    },
    "StormnodeManager\0updateNodeList\0\0"
    "updateStormNode\0alias\0addr\0privkey\0"
    "txHash\0txIndex\0status\0on_UpdateButton_clicked\0"
    "on_createButton_clicked\0on_startButton_clicked\0"
    "on_startAllButton_clicked\0"
    "on_tableWidget_2_itemSelectionChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StormnodeManager[] = {

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
       3,    6,   50,    2, 0x0a /* Public */,
      10,    0,   63,    2, 0x0a /* Public */,
      11,    0,   64,    2, 0x08 /* Private */,
      12,    0,   65,    2, 0x08 /* Private */,
      13,    0,   66,    2, 0x08 /* Private */,
      14,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    5,    6,    7,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void StormnodeManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StormnodeManager *_t = static_cast<StormnodeManager *>(_o);
        switch (_id) {
        case 0: _t->updateNodeList(); break;
        case 1: _t->updateStormNode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 2: _t->on_UpdateButton_clicked(); break;
        case 3: _t->on_createButton_clicked(); break;
        case 4: _t->on_startButton_clicked(); break;
        case 5: _t->on_startAllButton_clicked(); break;
        case 6: _t->on_tableWidget_2_itemSelectionChanged(); break;
        default: ;
        }
    }
}

const QMetaObject StormnodeManager::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_StormnodeManager.data,
      qt_meta_data_StormnodeManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StormnodeManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StormnodeManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StormnodeManager.stringdata))
        return static_cast<void*>(const_cast< StormnodeManager*>(this));
    return QWidget::qt_metacast(_clname);
}

int StormnodeManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
