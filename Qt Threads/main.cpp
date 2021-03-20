#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include <QMutexLocker>
#include <QMutex>
#include <QTimer>
#include <QString>

double element1, element2, foo;

class ThreadCalc : public QThread
{

public:
    void run()
    {
         for( int a = 1; a < 30; a++ ) {

           qDebug() << "Calculate Fibonacci";
           this->doWork();
         }

    }
 private:
    QMutex mutex;
    double sum;
    void doWork(){
        mutex.lock();
        sum = element2 + element1;
        element1 = element2;
        element2 = sum;
        mutex.unlock();
        this->sleep(1);
    }

};

class ThreadPrint : public QThread
{

public:
    void run()
    {
       for( int a = 1; a < 30; a++ ) {
          this->doWork();
          qDebug().noquote() << "Print Fibonacci: " << QString::number(this->foo, 'f', 12);
      }

    }

private:
   QMutex mutex;
   double foo;
   void doWork(){
       QMutexLocker locker(&mutex);
       foo = element2/element1;
       this->foo = foo;
       this->sleep(1);
   }

};


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qDebug() << "Start Application!";
    element1 = 1;
    element2 = 2;

    ThreadCalc *tc = new ThreadCalc();
    ThreadPrint *tp = new ThreadPrint();
    tc->start();
    tp->start();

    tc->wait();
    tp->wait();

    qDebug() << "End of Application";
    delete tc;
    delete tp;
    QTimer::singleShot(3000, &app, SLOT(quit()));
    return app.exec();
}
