/****************************************************************************
** Meta object code from reading C++ file 'clientmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qt/clientmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ClientModel_t {
    QByteArrayData data[31];
    char stringdata[403];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientModel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientModel_t qt_meta_stringdata_ClientModel = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ClientModel"
QT_MOC_LITERAL(1, 12, 21), // "numConnectionsChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 5), // "count"
QT_MOC_LITERAL(4, 41, 24), // "numI2PConnectionsChanged"
QT_MOC_LITERAL(5, 66, 16), // "numBlocksChanged"
QT_MOC_LITERAL(6, 83, 20), // "strStormnodesChanged"
QT_MOC_LITERAL(7, 104, 13), // "strStormnodes"
QT_MOC_LITERAL(8, 118, 13), // "alertsChanged"
QT_MOC_LITERAL(9, 132, 8), // "warnings"
QT_MOC_LITERAL(10, 141, 12), // "bytesChanged"
QT_MOC_LITERAL(11, 154, 12), // "totalBytesIn"
QT_MOC_LITERAL(12, 167, 13), // "totalBytesOut"
QT_MOC_LITERAL(13, 181, 7), // "message"
QT_MOC_LITERAL(14, 189, 5), // "title"
QT_MOC_LITERAL(15, 195, 5), // "modal"
QT_MOC_LITERAL(16, 201, 5), // "style"
QT_MOC_LITERAL(17, 207, 12), // "showProgress"
QT_MOC_LITERAL(18, 220, 9), // "nProgress"
QT_MOC_LITERAL(19, 230, 18), // "mempoolSizeChanged"
QT_MOC_LITERAL(20, 249, 6), // "size_t"
QT_MOC_LITERAL(21, 256, 18), // "mempoolSizeInBytes"
QT_MOC_LITERAL(22, 275, 11), // "updateTimer"
QT_MOC_LITERAL(23, 287, 13), // "updateSnTimer"
QT_MOC_LITERAL(24, 301, 20), // "updateNumConnections"
QT_MOC_LITERAL(25, 322, 14), // "numConnections"
QT_MOC_LITERAL(26, 337, 11), // "updateAlert"
QT_MOC_LITERAL(27, 349, 4), // "hash"
QT_MOC_LITERAL(28, 354, 6), // "status"
QT_MOC_LITERAL(29, 361, 23), // "updateNumI2PConnections"
QT_MOC_LITERAL(30, 385, 17) // "numI2PConnections"

    },
    "ClientModel\0numConnectionsChanged\0\0"
    "count\0numI2PConnectionsChanged\0"
    "numBlocksChanged\0strStormnodesChanged\0"
    "strStormnodes\0alertsChanged\0warnings\0"
    "bytesChanged\0totalBytesIn\0totalBytesOut\0"
    "message\0title\0modal\0style\0showProgress\0"
    "nProgress\0mempoolSizeChanged\0size_t\0"
    "mempoolSizeInBytes\0updateTimer\0"
    "updateSnTimer\0updateNumConnections\0"
    "numConnections\0updateAlert\0hash\0status\0"
    "updateNumI2PConnections\0numI2PConnections"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,
       5,    1,   90,    2, 0x06 /* Public */,
       6,    1,   93,    2, 0x06 /* Public */,
       8,    1,   96,    2, 0x06 /* Public */,
      10,    2,   99,    2, 0x06 /* Public */,
      13,    4,  104,    2, 0x06 /* Public */,
      17,    2,  113,    2, 0x06 /* Public */,
      19,    2,  118,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      22,    0,  123,    2, 0x0a /* Public */,
      23,    0,  124,    2, 0x0a /* Public */,
      24,    1,  125,    2, 0x0a /* Public */,
      26,    2,  128,    2, 0x0a /* Public */,
      29,    1,  133,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::ULongLong, QMetaType::ULongLong,   11,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::UInt,   14,   13,   15,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   14,   18,
    QMetaType::Void, QMetaType::Long, 0x80000000 | 20,    3,   21,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   27,   28,
    QMetaType::Void, QMetaType::Int,   30,

       0        // eod
};

void ClientModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClientModel *_t = static_cast<ClientModel *>(_o);
        switch (_id) {
        case 0: _t->numConnectionsChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->numI2PConnectionsChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->numBlocksChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->strStormnodesChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->alertsChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->bytesChanged((*reinterpret_cast< quint64(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2]))); break;
        case 6: _t->message((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4]))); break;
        case 7: _t->showProgress((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->mempoolSizeChanged((*reinterpret_cast< long(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2]))); break;
        case 9: _t->updateTimer(); break;
        case 10: _t->updateSnTimer(); break;
        case 11: _t->updateNumConnections((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->updateAlert((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->updateNumI2PConnections((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ClientModel::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientModel::numConnectionsChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (ClientModel::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientModel::numI2PConnectionsChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (ClientModel::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientModel::numBlocksChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (ClientModel::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientModel::strStormnodesChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (ClientModel::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientModel::alertsChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (ClientModel::*_t)(quint64 , quint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientModel::bytesChanged)) {
                *result = 5;
            }
        }
        {
            typedef void (ClientModel::*_t)(const QString & , const QString & , bool , unsigned int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientModel::message)) {
                *result = 6;
            }
        }
        {
            typedef void (ClientModel::*_t)(const QString & , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientModel::showProgress)) {
                *result = 7;
            }
        }
        {
            typedef void (ClientModel::*_t)(long , size_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientModel::mempoolSizeChanged)) {
                *result = 8;
            }
        }
    }
}

const QMetaObject ClientModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ClientModel.data,
      qt_meta_data_ClientModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ClientModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ClientModel.stringdata))
        return static_cast<void*>(const_cast< ClientModel*>(this));
    return QObject::qt_metacast(_clname);
}

int ClientModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ClientModel::numConnectionsChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClientModel::numI2PConnectionsChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ClientModel::numBlocksChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ClientModel::strStormnodesChanged(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ClientModel::alertsChanged(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ClientModel::bytesChanged(quint64 _t1, quint64 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ClientModel::message(const QString & _t1, const QString & _t2, bool _t3, unsigned int _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ClientModel::showProgress(const QString & _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ClientModel::mempoolSizeChanged(long _t1, size_t _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
