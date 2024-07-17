#ifndef CPU_H
#define CPU_H

#include <QCoreApplication>
#include "processthread.h"

#include <QProcess>

class cpu
{
    int numCPUs;
    QString CPUname;

    int findCPUCount();
    void findCPUName();

    public:
        cpu();

        QString getCPUName();
};

#endif // CPU_H
