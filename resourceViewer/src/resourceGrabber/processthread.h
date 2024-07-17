#ifndef PROCESSTHREAD_H
#define PROCESSTHREAD_H

#include <QThread>
#include <QProcess>

class processThread : public QThread
{
    QProcess *process;
    QString program;
    QStringList arguments;

    public:
        explicit processThread(QObject *parent = nullptr);
        ~processThread();
        void setProcess(const QString &program, const QStringList &arguments);
        void run() override;
        QString getOutput();
};

#endif // PROCESSTHREAD_H
