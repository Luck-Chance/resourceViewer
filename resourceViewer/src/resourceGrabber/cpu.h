#ifndef CPU_H
#define CPU_H

#include <QCoreApplication>
#include "processthread.h"

#include <QProcess>

class cpu
{
    int numCPUs;
    QString CPUname;

    void findCPUCount();
    void findCPUName();

    public:
        cpu();

        QString getCPUName();
        int getNumCPUs();
};

#endif // CPU_H
