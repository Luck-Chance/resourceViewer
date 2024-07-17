#include "cpu.h"

//private

cpu::cpu() {
    numCPUs = findCPUCount();
}

int cpu::findCPUCount() {
    return 0;
}

void cpu::findCPUName() {
    QString program = "bash";
    QStringList arguments;
    arguments << "-c" << " cat /proc/cpuinfo | grep \"model name\" | sort -u | cut -d \":\" -f2-";

    processThread thread;

    thread.setProcess(program, arguments);
    thread.run();

    CPUname = thread.getOutput();;
}

//public

QString cpu::getCPUName() {
    findCPUName();
    return CPUname;
}
