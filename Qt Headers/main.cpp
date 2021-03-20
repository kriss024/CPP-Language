#include <QCoreApplication>
#include <QTimer>
#include <QDebug>
#include <QTextStream>
#include "biblioteka.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    int t = 3000;
    int b = 2;
    int c = 3;

    QTextStream qout(stdout);
    qout << "Program dodawanie"<<endl;

    qDebug() << b << " + " << c << " = " << dodajLiczby(b,c) << endl;

    QTimer::singleShot(t,&app,SLOT(quit()));
    return app.exec();
}
