#include <QCoreApplication>
#include <QTextStream>
#include <QTimer>
#include <QString>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QString str;

    QTextStream strbuf(&str);

    int firstNumber, secondNumber;

    strbuf << "Thomas M. Disch: " << 334 << endl;

    qDebug().noquote() << str;

    str.clear();

    firstNumber = 15;
    secondNumber = 255;

    strbuf << bin << firstNumber << endl;
    strbuf << hex << secondNumber << endl;

    qDebug().noquote() << str;

    str.clear();

    QTimer::singleShot(3000, &app, SLOT(quit()));
    return app.exec();
}
