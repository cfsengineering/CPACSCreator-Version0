/****************************************************************************
** Meta object code from reading C++ file 'ModificatorManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../home/cfse/Stage_Malo/CPACSCreatorTotal/TIGLViewer/src/ModificatorManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModificatorManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModificatorManager_t {
    QByteArrayData data[7];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModificatorManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModificatorManager_t qt_meta_stringdata_ModificatorManager = {
    {
QT_MOC_LITERAL(0, 0, 18), // "ModificatorManager"
QT_MOC_LITERAL(1, 19, 8), // "dispatch"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 20), // "cpcr::CPACSTreeItem*"
QT_MOC_LITERAL(4, 50, 4), // "item"
QT_MOC_LITERAL(5, 55, 25), // "applyCurrentModifications"
QT_MOC_LITERAL(6, 81, 24) // "applyCurrentCancellation"

    },
    "ModificatorManager\0dispatch\0\0"
    "cpcr::CPACSTreeItem*\0item\0"
    "applyCurrentModifications\0"
    "applyCurrentCancellation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModificatorManager[] = {

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
       1,    1,   29,    2, 0x0a /* Public */,
       5,    0,   32,    2, 0x0a /* Public */,
       6,    0,   33,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ModificatorManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModificatorManager *_t = static_cast<ModificatorManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dispatch((*reinterpret_cast< cpcr::CPACSTreeItem*(*)>(_a[1]))); break;
        case 1: _t->applyCurrentModifications(); break;
        case 2: _t->applyCurrentCancellation(); break;
        default: ;
        }
    }
}

const QMetaObject ModificatorManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ModificatorManager.data,
      qt_meta_data_ModificatorManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ModificatorManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModificatorManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModificatorManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ModificatorManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
