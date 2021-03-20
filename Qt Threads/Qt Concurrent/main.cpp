#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include <QString>
#include <qtconcurrentrun.h>

void myRunFunction(QString name)
{
    for(int i = 0; i <= 5; i++)
    {
        qDebug() << name << " " << i;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QFuture<void> t1 = QtConcurrent::run(myRunFunction, QString("A"));
    QFuture<void> t2 = QtConcurrent::run(myRunFunction, QString("B"));
    QFuture<void> t3 = QtConcurrent::run(myRunFunction, QString("C"));

    t1.waitForFinished();
    t2.waitForFinished();
    t3.waitForFinished();

    return 0;
}
