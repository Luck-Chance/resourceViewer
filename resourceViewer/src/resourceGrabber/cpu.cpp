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

#include <QDebug>

//private

cpu::cpu() {
    findCPUCount();
    findCPUName();
    findCPUCoreNames();
}

void cpu::findCPUCount() {
    QString program = "bash";
    QStringList arguments;
    arguments << "-c" << " cat /proc/cpuinfo | grep processor -c";

    processThread thread;

    thread.setProcess(program, arguments);
    thread.run();

    numCPUs = thread.getOutput().toInt();

}

void cpu::findCPUName() {
    QString program = "bash";
    QStringList arguments;
    arguments << "-c" << " cat /proc/cpuinfo | grep \"model name\" | sort -u | cut -d \":\" -f2-";

    processThread thread;

    thread.setProcess(program, arguments);
    thread.run();

    CPUname = thread.getOutput().remove(0,1);
}

void cpu::findCPUCoreNames() {
    CPUCoreNames = new QString[numCPUs];

    QString program = "bash";
    QStringList arguments;
    arguments << "-c" << " cat /proc/stat | grep cpu |tail -n +2 | cut -d \" \" -f1";

    processThread thread;

    thread.setProcess(program, arguments);
    thread.run();

    QString temp = thread.getOutput();

    int i = 0;
    foreach(const QString& line, temp.split('\n')) {
        if (i < numCPUs) {
            CPUCoreNames[i] = line;
            i++;
        }
    }
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


















