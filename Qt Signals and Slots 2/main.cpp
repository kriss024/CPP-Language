#include <QCoreApplication>
#include <QTextStream>
#include <QTimer>
#include "rectangle.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QTextStream qout(stdout);
    qout << "Begin!" << endl;

    Rectangle *a = new Rectangle(&app);
    Rectangle *b = new Rectangle(&app);

    QObject::connect(a, SIGNAL(signal_wh(int, int)), b, SLOT(slot_wh(int, int)));

    a->set_values(5,5);
    qout << "a="<< a->area() << endl;
    qout << "b="<< b->area() << endl;

    b->set_values(6,6);
    qout << "a="<< a->area() << endl;
    qout << "b="<< b->area() << endl;

    a->set_values(3,3);
    qout << "a="<< a->area() << endl;
    qout << "b="<< b->area() << endl;


    qout.flush();

    QTimer::singleShot(3000, &app, SLOT(quit()));
    return app.exec();
}
