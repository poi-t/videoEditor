/****************************************************************************
** Meta object code from reading C++ file 'videoEditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../videoEditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videoEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_videoEditor_t {
    QByteArrayData data[20];
    char stringdata0[264];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_videoEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_videoEditor_t qt_meta_stringdata_videoEditor = {
    {
QT_MOC_LITERAL(0, 0, 11), // "videoEditor"
QT_MOC_LITERAL(1, 12, 23), // "on_btnLoadVideo_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 18), // "on_btnPlay_clicked"
QT_MOC_LITERAL(4, 56, 18), // "on_btnMute_clicked"
QT_MOC_LITERAL(5, 75, 12), // "on_SetVolume"
QT_MOC_LITERAL(6, 88, 3), // "vol"
QT_MOC_LITERAL(7, 92, 15), // "on_SetVideoTime"
QT_MOC_LITERAL(8, 108, 16), // "on_LeftPointSeek"
QT_MOC_LITERAL(9, 125, 4), // "lPos"
QT_MOC_LITERAL(10, 130, 17), // "on_RightPointSeek"
QT_MOC_LITERAL(11, 148, 4), // "rPos"
QT_MOC_LITERAL(12, 153, 22), // "on_btnStartCut_clicked"
QT_MOC_LITERAL(13, 176, 11), // "on_Finished"
QT_MOC_LITERAL(14, 188, 8), // "exidCode"
QT_MOC_LITERAL(15, 197, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(16, 218, 9), // "exitStaus"
QT_MOC_LITERAL(17, 228, 15), // "on_spinBoxStart"
QT_MOC_LITERAL(18, 244, 5), // "value"
QT_MOC_LITERAL(19, 250, 13) // "on_spinBoxEnd"

    },
    "videoEditor\0on_btnLoadVideo_clicked\0"
    "\0on_btnPlay_clicked\0on_btnMute_clicked\0"
    "on_SetVolume\0vol\0on_SetVideoTime\0"
    "on_LeftPointSeek\0lPos\0on_RightPointSeek\0"
    "rPos\0on_btnStartCut_clicked\0on_Finished\0"
    "exidCode\0QProcess::ExitStatus\0exitStaus\0"
    "on_spinBoxStart\0value\0on_spinBoxEnd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_videoEditor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    1,   72,    2, 0x08 /* Private */,
       7,    0,   75,    2, 0x08 /* Private */,
       8,    1,   76,    2, 0x08 /* Private */,
      10,    1,   79,    2, 0x08 /* Private */,
      12,    0,   82,    2, 0x08 /* Private */,
      13,    2,   83,    2, 0x08 /* Private */,
      17,    1,   88,    2, 0x08 /* Private */,
      19,    1,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 15,   14,   16,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void videoEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<videoEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnLoadVideo_clicked(); break;
        case 1: _t->on_btnPlay_clicked(); break;
        case 2: _t->on_btnMute_clicked(); break;
        case 3: _t->on_SetVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_SetVideoTime(); break;
        case 5: _t->on_LeftPointSeek((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_RightPointSeek((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_btnStartCut_clicked(); break;
        case 8: _t->on_Finished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 9: _t->on_spinBoxStart((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_spinBoxEnd((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject videoEditor::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_videoEditor.data,
    qt_meta_data_videoEditor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *videoEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *videoEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_videoEditor.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int videoEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
