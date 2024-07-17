#ifndef CPU_H
#define CPU_H

#include <QProcess>

class cpu
{
    int numCPUs;
    QString CPUname;

    int findCPUCount();
    QString findCPUName();

    public:
        cpu();

        QString getCPUName();
};

#endif // CPU_H
