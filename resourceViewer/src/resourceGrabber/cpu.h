#ifndef CPU_H
#define CPU_H

#include <QCoreApplication>
#include "processthread.h"

#include <QProcess>

class cpu
{
    processThread thread;

    int numCPUs;
    int* cpuSum;
    int* cpuLastSum = nullptr;
    int* cpuIdle;
    int* cpuLastIdle = nullptr;
    float* cpuCoreUsage;
    float cpuUsage;

    QString CPUname;
    QString* CPUCoreNames;

    void findCPUCount();
    void findCPUCoreNames();
    void findCPUName();

    void setUsagePtrSize();

    public:
        cpu();

        QString getCPUName();
        QString getCPUCoreName(int core);
        int getNumCPUs();

        void updateCPUUsage();
        float getCPUCoreUsage(int core);
        float getCPUUsage();
};

#endif // CPU_H
