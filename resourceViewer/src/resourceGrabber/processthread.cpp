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

#include "processthread.h"

//public

processThread::processThread(QObject *parent) : QThread(parent) {
    process = new QProcess();
}

processThread::~processThread() {
    delete process;
}

void processThread::setProcess(const QString &program, const QStringList &arguments) {
    this->program = program;
    this->arguments = arguments;
}

void processThread::run() {
    process->start(program, arguments);
    process->waitForFinished();
}

QString processThread::getOutput() {
    QString output = process->readAllStandardOutput();
    return output.remove(0,1);
}

