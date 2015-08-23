/****************************************************************************
** Meta object code from reading C++ file 'mainwin.h'
**
** Created: Wed Apr 30 15:16:53 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      26,    8,    8,    8, 0x08,
      49,   41,    8,    8, 0x08,
      89,    8,    8,    8, 0x08,
     101,    8,    8,    8, 0x08,
     119,  114,    8,    8, 0x08,
     167,  158,  154,    8, 0x08,
     203,  194,    8,    8, 0x08,
     236,    8,    8,    8, 0x08,
     250,  244,    8,    8, 0x08,
     272,  267,    8,    8, 0x08,
     297,  292,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWin[] = {
    "MainWin\0\0readInWebsites()\0doLookupWord()\0"
    "results\0populateResults(std::vector<WebPage*>*)\0"
    "showAbout()\0quitButton()\0site\0"
    "generatePageWindow(const WebPage*)\0"
    "int\0filename\0getIDfromName(std::string)\0"
    "pageList\0calcPageRanks(vector<WebPage*>*)\0"
    "clear()\0alpha\0usingAlpha(bool)\0rank\0"
    "usingPagerank(bool)\0item\0"
    "lookupPageListItem(QListWidgetItem*)\0"
};

void MainWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWin *_t = static_cast<MainWin *>(_o);
        switch (_id) {
        case 0: _t->readInWebsites(); break;
        case 1: _t->doLookupWord(); break;
        case 2: _t->populateResults((*reinterpret_cast< std::vector<WebPage*>*(*)>(_a[1]))); break;
        case 3: _t->showAbout(); break;
        case 4: _t->quitButton(); break;
        case 5: _t->generatePageWindow((*reinterpret_cast< const WebPage*(*)>(_a[1]))); break;
        case 6: { int _r = _t->getIDfromName((*reinterpret_cast< std::string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 7: _t->calcPageRanks((*reinterpret_cast< vector<WebPage*>*(*)>(_a[1]))); break;
        case 8: _t->clear(); break;
        case 9: _t->usingAlpha((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->usingPagerank((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->lookupPageListItem((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWin::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWin,
      qt_meta_data_MainWin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWin))
        return static_cast<void*>(const_cast< MainWin*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
