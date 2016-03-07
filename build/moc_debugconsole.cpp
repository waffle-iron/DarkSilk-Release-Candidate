/****************************************************************************
** Meta object code from reading C++ file 'debugconsole.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qt/debugconsole.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'debugconsole.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DEBUGConsole_t {
    QByteArrayData data[57];
    char stringdata[807];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DEBUGConsole_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DEBUGConsole_t qt_meta_stringdata_DEBUGConsole = {
    {
QT_MOC_LITERAL(0, 0, 12), // "DEBUGConsole"
QT_MOC_LITERAL(1, 13, 12), // "stopExecutor"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "cmdRequest"
QT_MOC_LITERAL(4, 38, 7), // "command"
QT_MOC_LITERAL(5, 46, 25), // "on_lineEdit_returnPressed"
QT_MOC_LITERAL(6, 72, 27), // "on_tabWidget_currentChanged"
QT_MOC_LITERAL(7, 100, 5), // "index"
QT_MOC_LITERAL(8, 106, 33), // "on_openDebugLogfileButton_cli..."
QT_MOC_LITERAL(9, 140, 30), // "on_showCLOptionsButton_clicked"
QT_MOC_LITERAL(10, 171, 29), // "on_sldGraphRange_valueChanged"
QT_MOC_LITERAL(11, 201, 5), // "value"
QT_MOC_LITERAL(12, 207, 18), // "updateTrafficStats"
QT_MOC_LITERAL(13, 226, 12), // "totalBytesIn"
QT_MOC_LITERAL(14, 239, 13), // "totalBytesOut"
QT_MOC_LITERAL(15, 253, 31), // "on_btnClearTrafficGraph_clicked"
QT_MOC_LITERAL(16, 285, 11), // "resizeEvent"
QT_MOC_LITERAL(17, 297, 13), // "QResizeEvent*"
QT_MOC_LITERAL(18, 311, 5), // "event"
QT_MOC_LITERAL(19, 317, 9), // "showEvent"
QT_MOC_LITERAL(20, 327, 11), // "QShowEvent*"
QT_MOC_LITERAL(21, 339, 9), // "hideEvent"
QT_MOC_LITERAL(22, 349, 11), // "QHideEvent*"
QT_MOC_LITERAL(23, 361, 25), // "showPeersTableContextMenu"
QT_MOC_LITERAL(24, 387, 5), // "point"
QT_MOC_LITERAL(25, 393, 23), // "showBanTableContextMenu"
QT_MOC_LITERAL(26, 417, 28), // "showOrHideBanTableIfRequired"
QT_MOC_LITERAL(27, 446, 17), // "clearSelectedNode"
QT_MOC_LITERAL(28, 464, 5), // "clear"
QT_MOC_LITERAL(29, 470, 7), // "message"
QT_MOC_LITERAL(30, 478, 8), // "category"
QT_MOC_LITERAL(31, 487, 4), // "html"
QT_MOC_LITERAL(32, 492, 17), // "setNumConnections"
QT_MOC_LITERAL(33, 510, 5), // "count"
QT_MOC_LITERAL(34, 516, 12), // "setNumBlocks"
QT_MOC_LITERAL(35, 529, 17), // "setStormnodeCount"
QT_MOC_LITERAL(36, 547, 13), // "strStormnodes"
QT_MOC_LITERAL(37, 561, 9), // "showPeers"
QT_MOC_LITERAL(38, 571, 13), // "browseHistory"
QT_MOC_LITERAL(39, 585, 6), // "offset"
QT_MOC_LITERAL(40, 592, 11), // "scrollToEnd"
QT_MOC_LITERAL(41, 604, 12), // "peerSelected"
QT_MOC_LITERAL(42, 617, 14), // "QItemSelection"
QT_MOC_LITERAL(43, 632, 8), // "selected"
QT_MOC_LITERAL(44, 641, 10), // "deselected"
QT_MOC_LITERAL(45, 652, 17), // "peerLayoutChanged"
QT_MOC_LITERAL(46, 670, 14), // "setMempoolSize"
QT_MOC_LITERAL(47, 685, 11), // "numberOfTxs"
QT_MOC_LITERAL(48, 697, 6), // "size_t"
QT_MOC_LITERAL(49, 704, 8), // "dynUsage"
QT_MOC_LITERAL(50, 713, 22), // "disconnectSelectedNode"
QT_MOC_LITERAL(51, 736, 15), // "banSelectedNode"
QT_MOC_LITERAL(52, 752, 7), // "bantime"
QT_MOC_LITERAL(53, 760, 17), // "unbanSelectedNode"
QT_MOC_LITERAL(54, 778, 11), // "setTabFocus"
QT_MOC_LITERAL(55, 790, 8), // "TabTypes"
QT_MOC_LITERAL(56, 799, 7) // "tabType"

    },
    "DEBUGConsole\0stopExecutor\0\0cmdRequest\0"
    "command\0on_lineEdit_returnPressed\0"
    "on_tabWidget_currentChanged\0index\0"
    "on_openDebugLogfileButton_clicked\0"
    "on_showCLOptionsButton_clicked\0"
    "on_sldGraphRange_valueChanged\0value\0"
    "updateTrafficStats\0totalBytesIn\0"
    "totalBytesOut\0on_btnClearTrafficGraph_clicked\0"
    "resizeEvent\0QResizeEvent*\0event\0"
    "showEvent\0QShowEvent*\0hideEvent\0"
    "QHideEvent*\0showPeersTableContextMenu\0"
    "point\0showBanTableContextMenu\0"
    "showOrHideBanTableIfRequired\0"
    "clearSelectedNode\0clear\0message\0"
    "category\0html\0setNumConnections\0count\0"
    "setNumBlocks\0setStormnodeCount\0"
    "strStormnodes\0showPeers\0browseHistory\0"
    "offset\0scrollToEnd\0peerSelected\0"
    "QItemSelection\0selected\0deselected\0"
    "peerLayoutChanged\0setMempoolSize\0"
    "numberOfTxs\0size_t\0dynUsage\0"
    "disconnectSelectedNode\0banSelectedNode\0"
    "bantime\0unbanSelectedNode\0setTabFocus\0"
    "TabTypes\0tabType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DEBUGConsole[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  174,    2, 0x06 /* Public */,
       3,    1,  175,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  178,    2, 0x08 /* Private */,
       6,    1,  179,    2, 0x08 /* Private */,
       8,    0,  182,    2, 0x08 /* Private */,
       9,    0,  183,    2, 0x08 /* Private */,
      10,    1,  184,    2, 0x08 /* Private */,
      12,    2,  187,    2, 0x08 /* Private */,
      15,    0,  192,    2, 0x08 /* Private */,
      16,    1,  193,    2, 0x08 /* Private */,
      19,    1,  196,    2, 0x08 /* Private */,
      21,    1,  199,    2, 0x08 /* Private */,
      23,    1,  202,    2, 0x08 /* Private */,
      25,    1,  205,    2, 0x08 /* Private */,
      26,    0,  208,    2, 0x08 /* Private */,
      27,    0,  209,    2, 0x08 /* Private */,
      28,    0,  210,    2, 0x0a /* Public */,
      29,    3,  211,    2, 0x0a /* Public */,
      29,    2,  218,    2, 0x2a /* Public | MethodCloned */,
      32,    1,  223,    2, 0x0a /* Public */,
      34,    1,  226,    2, 0x0a /* Public */,
      35,    1,  229,    2, 0x0a /* Public */,
      37,    0,  232,    2, 0x0a /* Public */,
      38,    1,  233,    2, 0x0a /* Public */,
      40,    0,  236,    2, 0x0a /* Public */,
      41,    2,  237,    2, 0x0a /* Public */,
      45,    0,  242,    2, 0x0a /* Public */,
      46,    2,  243,    2, 0x0a /* Public */,
      50,    0,  248,    2, 0x0a /* Public */,
      51,    1,  249,    2, 0x0a /* Public */,
      53,    0,  252,    2, 0x0a /* Public */,
      54,    1,  253,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::ULongLong, QMetaType::ULongLong,   13,   14,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 20,   18,
    QMetaType::Void, 0x80000000 | 22,   18,
    QMetaType::Void, QMetaType::QPoint,   24,
    QMetaType::Void, QMetaType::QPoint,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Bool,   30,   29,   31,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   30,   29,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::QString,   36,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 42, 0x80000000 | 42,   43,   44,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Long, 0x80000000 | 48,   47,   49,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 55,   56,

       0        // eod
};

void DEBUGConsole::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DEBUGConsole *_t = static_cast<DEBUGConsole *>(_o);
        switch (_id) {
        case 0: _t->stopExecutor(); break;
        case 1: _t->cmdRequest((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_lineEdit_returnPressed(); break;
        case 3: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_openDebugLogfileButton_clicked(); break;
        case 5: _t->on_showCLOptionsButton_clicked(); break;
        case 6: _t->on_sldGraphRange_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->updateTrafficStats((*reinterpret_cast< quint64(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2]))); break;
        case 8: _t->on_btnClearTrafficGraph_clicked(); break;
        case 9: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 10: _t->showEvent((*reinterpret_cast< QShowEvent*(*)>(_a[1]))); break;
        case 11: _t->hideEvent((*reinterpret_cast< QHideEvent*(*)>(_a[1]))); break;
        case 12: _t->showPeersTableContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 13: _t->showBanTableContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 14: _t->showOrHideBanTableIfRequired(); break;
        case 15: _t->clearSelectedNode(); break;
        case 16: _t->clear(); break;
        case 17: _t->message((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 18: _t->message((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 19: _t->setNumConnections((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->setNumBlocks((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->setStormnodeCount((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: _t->showPeers(); break;
        case 23: _t->browseHistory((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->scrollToEnd(); break;
        case 25: _t->peerSelected((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 26: _t->peerLayoutChanged(); break;
        case 27: _t->setMempoolSize((*reinterpret_cast< long(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2]))); break;
        case 28: _t->disconnectSelectedNode(); break;
        case 29: _t->banSelectedNode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->unbanSelectedNode(); break;
        case 31: _t->setTabFocus((*reinterpret_cast< TabTypes(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DEBUGConsole::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DEBUGConsole::stopExecutor)) {
                *result = 0;
            }
        }
        {
            typedef void (DEBUGConsole::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DEBUGConsole::cmdRequest)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject DEBUGConsole::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DEBUGConsole.data,
      qt_meta_data_DEBUGConsole,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DEBUGConsole::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DEBUGConsole::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DEBUGConsole.stringdata))
        return static_cast<void*>(const_cast< DEBUGConsole*>(this));
    return QDialog::qt_metacast(_clname);
}

int DEBUGConsole::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 32)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 32;
    }
    return _id;
}

// SIGNAL 0
void DEBUGConsole::stopExecutor()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void DEBUGConsole::cmdRequest(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
