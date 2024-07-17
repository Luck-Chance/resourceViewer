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

    public:
        resourceViewer(QWidget *parent = nullptr);
        ~resourceViewer();

    protected:
        void timerEvent(QTimerEvent *evnet);

    private:
        Ui::resourceViewer *ui;
        int timerID;
};
#endif // RESOURCEVIEWER_H
