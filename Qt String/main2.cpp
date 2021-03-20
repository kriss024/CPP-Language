#include <QCoreApplication>
#include <QTimer>
#include <QStringList>
#include <QDebug>

int main(int argc, char *argv[])
{
  QCoreApplication app(argc, argv);
  QStringList names;
  names << "Patricia" << "Markus" << "Uli";

  foreach(QString name, names)
    qDebug() << name;

  QTimer::singleShot(3000, &app, SLOT(quit()));
  return app.exec();
}
