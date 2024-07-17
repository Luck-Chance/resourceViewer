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
}

void cpu::findCPUCount() {
    QString program = "bash";
    QStringList arguments;
    arguments << "-c" << " cat /proc/cpuinfo | grep processor | tail -n 1 | cut -d \":\" -f2-";

    processThread thread;

    thread.setProcess(program, arguments);
    thread.run();

    numCPUs = thread.getOutput().toInt() + 1;

}

void cpu::findCPUName() {
    QString program = "bash";
    QStringList arguments;
    arguments << "-c" << " cat /proc/cpuinfo | grep \"model name\" | sort -u | cut -d \":\" -f2-";

    processThread thread;

    thread.setProcess(program, arguments);
    thread.run();

    CPUname = thread.getOutput();
}

//public

QString cpu::getCPUName() {
    findCPUName();
    return CPUname;
}

int cpu::getNumCPUs() {
    findCPUCount();
    return numCPUs;
}
