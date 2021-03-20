#pragma once

#include <QObject>
#include <QTextStream>

class Rectangle : public QObject
{
    Q_OBJECT
public:
    Rectangle(QObject *parent = 0) : QObject(parent) {
           QTextStream qout(stdout);
           qout << "a. Constructor...\n";
           qout.flush();
           width = 0;
           height = 0;
    }
    ~Rectangle(){
        QTextStream qout(stdout);
           qout << "d. Destructor...\n";
           qout.flush();
    }

    void set_values (int,int);
    int area();

public slots:
    void slot_wh(int, int);

signals:
    void signal_wh(int,int);

private:
    int width, height;

};
