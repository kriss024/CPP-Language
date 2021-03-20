#include <QCoreApplication>
#include <QFile>
#include <QDataStream>
#include <QString>
#include <QMap>
#include <QDebug>

void Save()
{
    QMap<int, QString> map;
    map.insert(1,"jeden");
    map.insert(2,"dwa");
    map.insert(3,"trzy");
    map.insert(4,"cztery");

    QString filename = "C:/Work/serial.txt";
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Could not open " << filename;
        return;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_1);

    out << map;

    file.flush();
    file.close();
}

void Load()
{
    QMap<int, QString> map;

    QString filename = "C:/Work/serial.txt";
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Could not open " << filename;
        return;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_1);

    in >> map;

    file.close();

    foreach(QString item, map)
        qDebug() << "#" << item;
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Save();
    Load();

    return 0;
}
