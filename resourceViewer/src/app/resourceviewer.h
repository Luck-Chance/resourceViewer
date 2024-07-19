#ifndef RESOURCEVIEWER_H
#define RESOURCEVIEWER_H

#include "cpu.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class resourceViewer;
}
QT_END_NAMESPACE

class resourceViewer : public QMainWindow
{
    Q_OBJECT

    cpu CPU;
    int timerID;

    Ui::resourceViewer *ui;

    void getCPUInfo();

    protected:
        void timerEvent(QTimerEvent *event);

    public:
        resourceViewer(QWidget *parent = nullptr);
        ~resourceViewer();
};
#endif // RESOURCEVIEWER_H
