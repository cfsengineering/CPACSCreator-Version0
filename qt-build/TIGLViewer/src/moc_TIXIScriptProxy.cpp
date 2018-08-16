/****************************************************************************
** Meta object code from reading C++ file 'TIXIScriptProxy.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../home/cfse/Stage_Malo/CPACSCreatorTotal/TIGLViewer/src/TIXIScriptProxy.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TIXIScriptProxy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TIXIScriptProxy_t {
    QByteArrayData data[6];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TIXIScriptProxy_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TIXIScriptProxy_t qt_meta_stringdata_TIXIScriptProxy = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TIXIScriptProxy"
QT_MOC_LITERAL(1, 16, 18), // "getMemberFunctions"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 14), // "tixiGetVersion"
QT_MOC_LITERAL(4, 51, 18), // "tixiGetTextElement"
QT_MOC_LITERAL(5, 70, 11) // "elementPath"

    },
    "TIXIScriptProxy\0getMemberFunctions\0\0"
    "tixiGetVersion\0tixiGetTextElement\0"
    "elementPath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TIXIScriptProxy[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       4,    1,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::QStringList,
    QMetaType::QString,
    QMetaType::QString, QMetaType::QString,    5,

       0        // eod
};

void TIXIScriptProxy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TIXIScriptProxy *_t = static_cast<TIXIScriptProxy *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QStringList _r = _t->getMemberFunctions();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 1: { QString _r = _t->tixiGetVersion();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->tixiGetTextElement((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject TIXIScriptProxy::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TIXIScriptProxy.data,
      qt_meta_data_TIXIScriptProxy,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TIXIScriptProxy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TIXIScriptProxy::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TIXIScriptProxy.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TIXIScriptProxy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
