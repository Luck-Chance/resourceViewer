#include "cpu.h"

#include "processthread.h"

cpu::cpu() {
    numCPUs = findCPUCount();
    QString CPUname = "";
}

int cpu::findCPUCount() {
    return 0;
}

QString cpu::findCPUName() {

    return "";
}
