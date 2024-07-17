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
    QString output = QString::fromUtf8(process->readAllStandardOutput());
    return output.remove(0,1);
}

