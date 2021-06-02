#pragma once

#include <QtWidgets/QWidget>
#include "ui_videoEditor.h"

class videoEditor : public QWidget
{
    Q_OBJECT

public:
    videoEditor(QWidget *parent = Q_NULLPTR);

private:
    Ui::videoEditorClass ui;
};
