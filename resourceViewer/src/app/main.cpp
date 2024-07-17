#include "resourceviewer.h"
#include "cpu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    resourceViewer w;
    w.show();
    return a.exec();
}
