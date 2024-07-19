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

#include "resourceviewer.h"
#include "./ui_resourceviewer.h"

resourceViewer::resourceViewer(QWidget *parent) : QMainWindow(parent), ui(new Ui::resourceViewer)
{
    ui->setupUi(this);

    cpu CPU;
    ui->cpuTestName->setText("CPU Name: " + CPU.getCPUName());
    ui->cpuTestNum->setText("Number of CPUs: " + QString().setNum(CPU.getNumCPUs()));
    ui->cpuTestCoreName->setText("CPU 1 Name: " + CPU.getCPUCoreName(0));
    timerID = startTimer(1000);
}

resourceViewer::~resourceViewer()
{
    delete ui;
}

void resourceViewer::timerEvent(QTimerEvent *event) {
}
