#include <QCoreApplication>
#include <QDebug>
#include <QTimer>
#include "counter.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Counter a, b;
    QObject::connect(&a, SIGNAL(valueChanged(int)),&b, SLOT(setValue(int)));

    a.setValue(12);     // a.value() == 12, b.value() == 12
    qDebug() << "a=" << a.value()<< " b=" << b.value() << endl;
    b.setValue(48);     // a.value() == 12, b.value() == 48
    qDebug() << "a=" << a.value()<< " b=" << b.value() << endl;

    QTimer::singleShot(3000, &app, SLOT(quit()));
    return app.exec();
}
