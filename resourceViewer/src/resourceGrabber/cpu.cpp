#include "cpu.h"

cpu::cpu()
{
    numCPUs = getCPUCount();
}

int cpu::getCPUCount() {
    return 0;
}
