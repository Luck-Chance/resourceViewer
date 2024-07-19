#ifndef CPU_H
#define CPU_H

#include <QCoreApplication>
#include "processthread.h"

#include <QProcess>

class cpu
{
    int numCPUs;
    int* cpuSum;
    int* cpuLastSum;
    int* cpuIdle;
    int* cpuLastIdle;
    int* cpuDelta;
    int* cpuUsage;

    QString CPUname;
    QString* CPUCoreNames;

    void findCPUCount();
    void findCPUCoreNames();
    void findCPUName();

    void updateCPUUsage();

    public:
        cpu();

        QString getCPUName();
        QString getCPUCoreName(int core);
        int getNumCPUs();
        float getCPUCoreUsage(int core);
        float getCPUTotalUsage();
};

#endif // CPU_H
