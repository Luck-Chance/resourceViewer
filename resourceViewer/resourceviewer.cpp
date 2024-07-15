#include "resourceviewer.h"
#include "./ui_resourceviewer.h"

resourceViewer::resourceViewer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::resourceViewer)
{
    ui->setupUi(this);
}

resourceViewer::~resourceViewer()
{
    delete ui;
}
