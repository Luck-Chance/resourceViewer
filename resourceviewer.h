#ifndef RESOURCEVIEWER_H
#define RESOURCEVIEWER_H

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

private:
    Ui::resourceViewer *ui;
};
#endif // RESOURCEVIEWER_H
