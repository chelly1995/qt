/****************************************************************************
** Meta object code from reading C++ file 'clientmanagerform.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CSApp/clientmanagerform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientmanagerform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClientManagerForm_t {
    uint offsetsAndSizes[26];
    char stringdata0[18];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[16];
    char stringdata5[11];
    char stringdata6[25];
    char stringdata7[28];
    char stringdata8[28];
    char stringdata9[16];
    char stringdata10[27];
    char stringdata11[12];
    char stringdata12[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ClientManagerForm_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_ClientManagerForm_t qt_meta_stringdata_ClientManagerForm = {
    {
        QT_MOC_LITERAL(0, 17),  // "ClientManagerForm"
        QT_MOC_LITERAL(18, 14),  // "sendClientInfo"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 16),  // "sendClientInform"
        QT_MOC_LITERAL(51, 15),  // "showContextMenu"
        QT_MOC_LITERAL(67, 10),  // "removeItem"
        QT_MOC_LITERAL(78, 24),  // "on_addPushButton_clicked"
        QT_MOC_LITERAL(103, 27),  // "on_modifyPushButton_clicked"
        QT_MOC_LITERAL(131, 27),  // "on_searchPushButton_clicked"
        QT_MOC_LITERAL(159, 15),  // "clientCIDSended"
        QT_MOC_LITERAL(175, 26),  // "on_clienttableView_clicked"
        QT_MOC_LITERAL(202, 11),  // "QModelIndex"
        QT_MOC_LITERAL(214, 5)   // "index"
    },
    "ClientManagerForm",
    "sendClientInfo",
    "",
    "sendClientInform",
    "showContextMenu",
    "removeItem",
    "on_addPushButton_clicked",
    "on_modifyPushButton_clicked",
    "on_searchPushButton_clicked",
    "clientCIDSended",
    "on_clienttableView_clicked",
    "QModelIndex",
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientManagerForm[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   68,    2, 0x06,    1 /* Public */,
       3,    3,   73,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   80,    2, 0x08,    8 /* Private */,
       5,    0,   83,    2, 0x08,   10 /* Private */,
       6,    0,   84,    2, 0x08,   11 /* Private */,
       7,    0,   85,    2, 0x08,   12 /* Private */,
       8,    0,   86,    2, 0x08,   13 /* Private */,
       9,    1,   87,    2, 0x08,   14 /* Private */,
      10,    1,   90,    2, 0x08,   16 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void ClientManagerForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClientManagerForm *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendClientInfo((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->sendClientInform((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 2: _t->showContextMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 3: _t->removeItem(); break;
        case 4: _t->on_addPushButton_clicked(); break;
        case 5: _t->on_modifyPushButton_clicked(); break;
        case 6: _t->on_searchPushButton_clicked(); break;
        case 7: _t->clientCIDSended((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->on_clienttableView_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ClientManagerForm::*)(int , QString );
            if (_t _q_method = &ClientManagerForm::sendClientInfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ClientManagerForm::*)(QString , QString , QString );
            if (_t _q_method = &ClientManagerForm::sendClientInform; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ClientManagerForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ClientManagerForm.offsetsAndSizes,
    qt_meta_data_ClientManagerForm,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ClientManagerForm_t
, QtPrivate::TypeAndForceComplete<ClientManagerForm, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>


>,
    nullptr
} };


const QMetaObject *ClientManagerForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientManagerForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClientManagerForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ClientManagerForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ClientManagerForm::sendClientInfo(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClientManagerForm::sendClientInform(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
