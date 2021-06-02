#include "videoEditor.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    videoEditor w;
    w.show();
    return a.exec();
}
