/****************************************************************************
** Meta object code from reading C++ file 'centrwgt.h'
**
** Created: Sat 23. Apr 00:50:16 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../centrwgt.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'centrwgt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CentralWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      28,   14,   14,   14, 0x0a,
      45,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CentralWidget[] = {
    "CentralWidget\0\0addContact()\0"
    "detailsContact()\0removeContact()\0"
};

const QMetaObject CentralWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CentralWidget,
      qt_meta_data_CentralWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CentralWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CentralWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CentralWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CentralWidget))
        return static_cast<void*>(const_cast< CentralWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CentralWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addContact(); break;
        case 1: detailsContact(); break;
        case 2: removeContact(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
