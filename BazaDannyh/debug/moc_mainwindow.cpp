/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon 16. May 23:29:11 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      19,   11,   11,   11, 0x08,
      29,   11,   11,   11, 0x08,
      38,   11,   11,   11, 0x08,
      49,   11,   11,   11, 0x08,
      58,   11,   11,   11, 0x08,
      65,   11,   11,   11, 0x08,
      72,   11,   11,   11, 0x08,
      81,   11,   11,   11, 0x0a,
     106,   11,   11,   11, 0x0a,
     127,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0Edit()\0Details()\0NewCar()\0"
    "NewOrder()\0Delete()\0Sort()\0Find()\0"
    "Report()\0Otnoshen_change(QString)\0"
    "View_change(QString)\0Procedur_change(QString)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Edit(); break;
        case 1: Details(); break;
        case 2: NewCar(); break;
        case 3: NewOrder(); break;
        case 4: Delete(); break;
        case 5: Sort(); break;
        case 6: Find(); break;
        case 7: Report(); break;
        case 8: Otnoshen_change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: View_change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: Procedur_change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
