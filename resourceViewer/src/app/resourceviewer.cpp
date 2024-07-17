#include "resourceviewer.h"
#include "./ui_resourceviewer.h"

resourceViewer::resourceViewer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::resourceViewer)
{
    ui->setupUi(this);

    cpu CPU;
    ui->cpuTestName->setText("CPU Name: " + CPU.getCPUName());
    timerID = startTimer(1000);
}

resourceViewer::~resourceViewer()
{
    delete ui;
}

void resourceViewer::timerEvent(QTimerEvent *event) {
}
