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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "qxtspanslider.h"

QT_BEGIN_NAMESPACE

class Ui_videoEditorClass
{
public:
    QWidget *widget;
    QWidget *widget_2;
    QLabel *label_time;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *btnPlay;
    QPushButton *btnLoadVideo;
    QPushButton *btnMute;
    QPushButton *btnStartCut;
    QSlider *volumeSlider;
    QSpinBox *spinBox_start;
    QSpinBox *spinBox_end;
    QxtSpanSlider *timeSlider;

    void setupUi(QWidget *videoEditorClass)
    {
        if (videoEditorClass->objectName().isEmpty())
            videoEditorClass->setObjectName(QString::fromUtf8("videoEditorClass"));
        videoEditorClass->resize(586, 432);
        widget = new QWidget(videoEditorClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 580, 300));
        widget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color:black;\n"
"}"));
        widget_2 = new QWidget(videoEditorClass);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 320, 581, 111));
        widget_2->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color: rgb(53, 53, 53);\n"
"}\n"
" \n"
"QPushButton\n"
"{\n"
"	background-color:rgb(128, 138, 135);\n"
"	color:white;\n"
"    font:16px;\n"
"    border-radius:6px; \n"
"}\n"
" \n"
"QPushButton:hover\n"
"{\n"
"    color:#0000ff;\n"
"    background-color:rgb(210, 205, 205); /*\346\224\271\345\217\230\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:inset;/*\346\224\271\345\217\230\350\276\271\346\241\206\351\243\216\346\240\274*/\n"
"    padding-left:1px;\n"
"    padding-top:1px;\n"
"}\n"
" \n"
"\n"
"\n"
"QLabel,QSpinBox\n"
"{\n"
"	color:white;\n"
"}\n"
" \n"
" \n"
"\n"
"\n"
"QSlider::groove:horizontal {\n"
"	border: 1px solid #4A708B;\n"
"	background: #C0C0C0;\n"
"	height: 5px;\n"
"	border-radius: 1px;\n"
"	padding-left:-1px;\n"
"	padding-right:-1px;\n"
"}\n"
" \n"
" \n"
"QSlider::sub-page:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1, \n"
"    stop:0 #B1B1B1, stop:1 #c4c4c4);\n"
"background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,\n"
"    stop"
                        ": 0 #5DCCFF, stop: 1 #1874CD);\n"
"border: 1px solid #4A708B;\n"
"height: 10px;\n"
"border-radius: 2px;\n"
"}\n"
" \n"
"QSlider::add-page:horizontal {\n"
"background: #575757;\n"
"border: 0px solid #777;\n"
"height: 10px;\n"
"border-radius: 2px;\n"
"}\n"
" \n"
"QSlider::handle:horizontal \n"
"{\n"
"    background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, \n"
"    stop:0.6 #45ADED, stop:0.778409 rgba(255, 255, 255, 255));\n"
" \n"
"    width: 11px;\n"
"    margin-top: -5px;\n"
"    margin-bottom: -5px;\n"
"    border-radius: 5px;\n"
"}\n"
" \n"
"QSlider::handle:horizontal:hover \n"
"{\n"
"    background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.6 #2A8BDA, \n"
"    stop:0.778409 rgba(255, 255, 255, 255));\n"
" \n"
"    width: 11px;\n"
"    margin-top: -5px;\n"
"    margin-bottom: -5px;\n"
"    border-radius: 5px;\n"
"}"));
        label_time = new QLabel(widget_2);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setGeometry(QRect(20, 30, 110, 16));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 70, 54, 12));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(210, 70, 54, 12));
        btnPlay = new QPushButton(widget_2);
        btnPlay->setObjectName(QString::fromUtf8("btnPlay"));
        btnPlay->setGeometry(QRect(180, 20, 30, 30));
        btnLoadVideo = new QPushButton(widget_2);
        btnLoadVideo->setObjectName(QString::fromUtf8("btnLoadVideo"));
        btnLoadVideo->setGeometry(QRect(270, 20, 75, 23));
        btnMute = new QPushButton(widget_2);
        btnMute->setObjectName(QString::fromUtf8("btnMute"));
        btnMute->setGeometry(QRect(380, 20, 30, 30));
        btnStartCut = new QPushButton(widget_2);
        btnStartCut->setObjectName(QString::fromUtf8("btnStartCut"));
        btnStartCut->setGeometry(QRect(430, 60, 75, 23));
        volumeSlider = new QSlider(widget_2);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
        volumeSlider->setGeometry(QRect(440, 20, 90, 22));
        volumeSlider->setOrientation(Qt::Horizontal);
        spinBox_start = new QSpinBox(widget_2);
        spinBox_start->setObjectName(QString::fromUtf8("spinBox_start"));
        spinBox_start->setGeometry(QRect(100, 65, 42, 22));
        spinBox_end = new QSpinBox(widget_2);
        spinBox_end->setObjectName(QString::fromUtf8("spinBox_end"));
        spinBox_end->setGeometry(QRect(270, 65, 42, 22));
        timeSlider = new QxtSpanSlider(videoEditorClass);
        timeSlider->setObjectName(QString::fromUtf8("timeSlider"));
        timeSlider->setGeometry(QRect(20, 300, 540, 22));
        timeSlider->setOrientation(Qt::Horizontal);

        retranslateUi(videoEditorClass);

        QMetaObject::connectSlotsByName(videoEditorClass);
    } // setupUi

    void retranslateUi(QWidget *videoEditorClass)
    {
        videoEditorClass->setWindowTitle(QApplication::translate("videoEditorClass", "videoEditor", nullptr));
        label_time->setText(QString());
        label_2->setText(QApplication::translate("videoEditorClass", "\350\265\267\345\247\213\344\275\215\347\275\256", nullptr));
        label_3->setText(QApplication::translate("videoEditorClass", "\347\273\223\346\235\237\344\275\215\347\275\256", nullptr));
        btnPlay->setText(QString());
        btnLoadVideo->setText(QApplication::translate("videoEditorClass", "\345\257\274\345\205\245\350\247\206\351\242\221", nullptr));
        btnMute->setText(QString());
        btnStartCut->setText(QApplication::translate("videoEditorClass", "\345\274\200\345\247\213\345\211\252\350\276\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class videoEditorClass: public Ui_videoEditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOEDITOR_H
