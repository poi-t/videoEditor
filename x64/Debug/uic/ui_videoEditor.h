/********************************************************************************
** Form generated from reading UI file 'videoEditor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOEDITOR_H
#define UI_VIDEOEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_videoEditorClass
{
public:

    void setupUi(QWidget *videoEditorClass)
    {
        if (videoEditorClass->objectName().isEmpty())
            videoEditorClass->setObjectName(QString::fromUtf8("videoEditorClass"));
        videoEditorClass->resize(600, 400);

        retranslateUi(videoEditorClass);

        QMetaObject::connectSlotsByName(videoEditorClass);
    } // setupUi

    void retranslateUi(QWidget *videoEditorClass)
    {
        videoEditorClass->setWindowTitle(QApplication::translate("videoEditorClass", "videoEditor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class videoEditorClass: public Ui_videoEditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOEDITOR_H
