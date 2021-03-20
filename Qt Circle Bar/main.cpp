#include <QApplication>
#include "figura.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Figura f;
    f.show();
    return a.exec();
}
