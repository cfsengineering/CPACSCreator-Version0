/****************************************************************************
** Meta object code from reading C++ file 'CPACSAbstractModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../home/cfse/Stage_Malo/CPACSCreatorTotal/TIGLViewer/src/CPACSAbstractModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CPACSAbstractModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CPACSAbstractModel_t {
    QByteArrayData data[7];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CPACSAbstractModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CPACSAbstractModel_t qt_meta_stringdata_CPACSAbstractModel = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CPACSAbstractModel"
QT_MOC_LITERAL(1, 19, 19), // "selectionAsTreeItem"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 20), // "cpcr::CPACSTreeItem*"
QT_MOC_LITERAL(4, 61, 8), // "treeItem"
QT_MOC_LITERAL(5, 70, 22), // "onItemSelectionChanged"
QT_MOC_LITERAL(6, 93, 14) // "QItemSelection"

    },
    "CPACSAbstractModel\0selectionAsTreeItem\0"
    "\0cpcr::CPACSTreeItem*\0treeItem\0"
    "onItemSelectionChanged\0QItemSelection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CPACSAbstractModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    2,    2,

       0        // eod
};

void CPACSAbstractModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CPACSAbstractModel *_t = static_cast<CPACSAbstractModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectionAsTreeItem((*reinterpret_cast< cpcr::CPACSTreeItem*(*)>(_a[1]))); break;
        case 1: _t->onItemSelectionChanged((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QItemSelection >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CPACSAbstractModel::*_t)(cpcr::CPACSTreeItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CPACSAbstractModel::selectionAsTreeItem)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CPACSAbstractModel::staticMetaObject = {
    { &QAbstractItemModel::staticMetaObject, qt_meta_stringdata_CPACSAbstractModel.data,
      qt_meta_data_CPACSAbstractModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CPACSAbstractModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CPACSAbstractModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CPACSAbstractModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractItemModel::qt_metacast(_clname);
}

int CPACSAbstractModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CPACSAbstractModel::selectionAsTreeItem(cpcr::CPACSTreeItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
