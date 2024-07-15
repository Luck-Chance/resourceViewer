/********************************************************************************
** Form generated from reading UI file 'resourceviewer.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESOURCEVIEWER_H
#define UI_RESOURCEVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_resourceViewer
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *resourceViewer)
    {
        if (resourceViewer->objectName().isEmpty())
            resourceViewer->setObjectName("resourceViewer");
        resourceViewer->resize(800, 600);
        centralwidget = new QWidget(resourceViewer);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(220, 190, 88, 25));
        resourceViewer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(resourceViewer);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        resourceViewer->setMenuBar(menubar);
        statusbar = new QStatusBar(resourceViewer);
        statusbar->setObjectName("statusbar");
        resourceViewer->setStatusBar(statusbar);

        retranslateUi(resourceViewer);

        QMetaObject::connectSlotsByName(resourceViewer);
    } // setupUi

    void retranslateUi(QMainWindow *resourceViewer)
    {
        resourceViewer->setWindowTitle(QCoreApplication::translate("resourceViewer", "resourceViewer", nullptr));
        pushButton->setText(QCoreApplication::translate("resourceViewer", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class resourceViewer: public Ui_resourceViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESOURCEVIEWER_H
