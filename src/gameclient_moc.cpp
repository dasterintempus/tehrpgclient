/****************************************************************************
** Meta object code from reading C++ file 'gameclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gameclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_teh__GameClient_t {
    QByteArrayData data[14];
    char stringdata[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_teh__GameClient_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_teh__GameClient_t qt_meta_stringdata_teh__GameClient = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 11),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 4),
QT_MOC_LITERAL(4, 34, 15),
QT_MOC_LITERAL(5, 50, 12),
QT_MOC_LITERAL(6, 63, 8),
QT_MOC_LITERAL(7, 72, 9),
QT_MOC_LITERAL(8, 82, 8),
QT_MOC_LITERAL(9, 91, 5),
QT_MOC_LITERAL(10, 97, 11),
QT_MOC_LITERAL(11, 109, 17),
QT_MOC_LITERAL(12, 127, 28),
QT_MOC_LITERAL(13, 156, 5)
    },
    "teh::GameClient\0lineArrived\0\0line\0"
    "connectionClose\0beginPlaying\0sendLine\0"
    "dataReady\0dataSent\0bytes\0socketClose\0"
    "socketStateChange\0QAbstractSocket::SocketState\0"
    "state\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_teh__GameClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06,
       4,    0,   57,    2, 0x06,
       5,    0,   58,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       6,    1,   59,    2, 0x0a,
       7,    0,   62,    2, 0x08,
       8,    1,   63,    2, 0x08,
      10,    0,   66,    2, 0x08,
      11,    1,   67,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void teh::GameClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameClient *_t = static_cast<GameClient *>(_o);
        switch (_id) {
        case 0: _t->lineArrived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->connectionClose(); break;
        case 2: _t->beginPlaying(); break;
        case 3: _t->sendLine((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->dataReady(); break;
        case 5: _t->dataSent((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 6: _t->socketClose(); break;
        case 7: _t->socketStateChange((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GameClient::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameClient::lineArrived)) {
                *result = 0;
            }
        }
        {
            typedef void (GameClient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameClient::connectionClose)) {
                *result = 1;
            }
        }
        {
            typedef void (GameClient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameClient::beginPlaying)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject teh::GameClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_teh__GameClient.data,
      qt_meta_data_teh__GameClient,  qt_static_metacall, 0, 0}
};


const QMetaObject *teh::GameClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *teh::GameClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_teh__GameClient.stringdata))
        return static_cast<void*>(const_cast< GameClient*>(this));
    return QObject::qt_metacast(_clname);
}

int teh::GameClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void teh::GameClient::lineArrived(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void teh::GameClient::connectionClose()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void teh::GameClient::beginPlaying()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
