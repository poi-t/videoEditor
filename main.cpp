#include "videoEditor.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    videoEditor editor;
    editor.show();
    return a.exec();
}
