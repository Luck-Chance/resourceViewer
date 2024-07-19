/*
 * Copyright 2024 Nathan Roehrig
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "cpu.h"

//private

cpu::cpu() {
    findCPUCount();
    findCPUName();
    findCPUCoreNames();
    setUsagePtrSize();
}

void cpu::findCPUCount() {
    QString program = "bash";
    QStringList arguments;
    arguments << "-c" << " cat /proc/cpuinfo | grep processor -c";

    thread.setProcess(program, arguments);
    thread.run();

    numCPUs = thread.getOutput().toInt();

}

void cpu::findCPUName() {
    QString program = "bash";
    QStringList arguments;
    arguments << "-c" << " cat /proc/cpuinfo | grep \"model name\" | sort -u | cut -d \":\" -f2-";

    thread.setProcess(program, arguments);
    thread.run();

    CPUname = thread.getOutput().remove(0,1);
}

void cpu::findCPUCoreNames() {
    CPUCoreNames = new QString[numCPUs];

    QString program = "bash";
    QStringList arguments;
    arguments << "-c" << " cat /proc/stat | grep cpu | tail -n +2 | cut -d \" \" -f1";

    thread.setProcess(program, arguments);
    thread.run();

    QString temp = thread.getOutput();

    int i = 0;
    for(const QString& line : temp.split('\n')) {
        if (i < numCPUs) {
            CPUCoreNames[i] = line;
            i++;
        }
    }
}

void cpu::setUsagePtrSize() {
    cpuSum = new int[numCPUs];
    cpuIdle = new int[numCPUs];
    cpuCoreUsage = new float[numCPUs];
}

//public

QString cpu::getCPUName() {
    return CPUname;
}

int cpu::getNumCPUs() {
    return numCPUs;
}

QString cpu::getCPUCoreName(int core) {
    return CPUCoreNames[core];
}

void cpu::updateCPUUsage() {
    QString program = "bash";
    QStringList arguments;
    arguments << "-c" << " cat /proc/stat | grep cpu | tail -n +2 | cut -d \" \" -f2-";

    thread.setProcess(program, arguments);
    thread.run();

    QString temp = thread.getOutput();

    bool first = true;

    if(cpuLastSum == nullptr){
        cpuLastSum = new int[numCPUs];
        cpuLastIdle = new int[numCPUs];
    }
    else {
        first = false;
        for (int i = 0; i < numCPUs; i++) {
            cpuLastSum[i] = cpuSum[i];
            cpuLastIdle[i] = cpuIdle[i];
        }
    }

    int i = 0;
    cpuUsage = 0;
    for(const QString& core : temp.split('\n')) {
        if (i >= numCPUs)
            break;

        int j = 0;
        cpuSum[i] = 0;
        for(const QString& proc : core.split(' ')) {
            if (j == 3)
                cpuIdle[i] = proc.toInt();
            else if (j == 4)
                cpuIdle[i] += proc.toInt();
            cpuSum[i] += proc.toInt();
            j++;
        }
        if (!first) {
            int cpuDelta = cpuSum[i] - cpuLastSum[i];
            int cpuIdleDelta = cpuIdle[i] - cpuLastIdle[i];
            cpuCoreUsage[i] = 100 * ((cpuDelta - cpuIdleDelta) / float(cpuDelta));

            //cpuCoreUsage[i] = 100 * ((cpuSum[i] - cpuIdle[i]) / float(cpuSum[i]));
        }
        else {
            cpuCoreUsage[i] = 0;
        }
        cpuUsage += cpuCoreUsage[i];
        i++;
    }
    cpuUsage /= numCPUs;
}

float cpu::getCPUCoreUsage(int core) {
    return cpuCoreUsage[core];
}

float cpu::getCPUUsage() {
    return cpuUsage;
}

















