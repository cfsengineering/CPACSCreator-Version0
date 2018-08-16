/****************************************************************************
** Meta object code from reading C++ file 'TIGLScriptEngine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../home/cfse/Stage_Malo/CPACSCreatorTotal/TIGLViewer/src/TIGLScriptEngine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TIGLScriptEngine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TIGLScriptEngine_t {
    QByteArrayData data[11];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TIGLScriptEngine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TIGLScriptEngine_t qt_meta_stringdata_TIGLScriptEngine = {
    {
QT_MOC_LITERAL(0, 0, 16), // "TIGLScriptEngine"
QT_MOC_LITERAL(1, 17, 12), // "scriptResult"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 4), // "text"
QT_MOC_LITERAL(4, 36, 11), // "scriptError"
QT_MOC_LITERAL(5, 48, 8), // "evalDone"
QT_MOC_LITERAL(6, 57, 11), // "textChanged"
QT_MOC_LITERAL(7, 69, 4), // "line"
QT_MOC_LITERAL(8, 74, 4), // "eval"
QT_MOC_LITERAL(9, 79, 11), // "commandLine"
QT_MOC_LITERAL(10, 91, 9) // "printText"

    },
    "TIGLScriptEngine\0scriptResult\0\0text\0"
    "scriptError\0evalDone\0textChanged\0line\0"
    "eval\0commandLine\0printText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TIGLScriptEngine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       5,    0,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   51,    2, 0x0a /* Public */,
       8,    1,   54,    2, 0x0a /* Public */,
      10,    1,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void TIGLScriptEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TIGLScriptEngine *_t = static_cast<TIGLScriptEngine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->scriptResult((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->scriptError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->evalDone(); break;
        case 3: _t->textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->eval((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->printText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TIGLScriptEngine::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TIGLScriptEngine::scriptResult)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TIGLScriptEngine::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TIGLScriptEngine::scriptError)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TIGLScriptEngine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TIGLScriptEngine::evalDone)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject TIGLScriptEngine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TIGLScriptEngine.data,
      qt_meta_data_TIGLScriptEngine,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TIGLScriptEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TIGLScriptEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TIGLScriptEngine.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TIGLScriptEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void TIGLScriptEngine::scriptResult(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TIGLScriptEngine::scriptError(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TIGLScriptEngine::evalDone()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
