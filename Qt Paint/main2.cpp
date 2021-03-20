#include <QApplication>
#include <QWidget>
#include <QtGui>

class MyWidget : public QWidget
{
public:
    MyWidget();

protected:
    void paintEvent(QPaintEvent *);
};

MyWidget::MyWidget()
{
    QPalette palette(MyWidget::palette());
    palette.setColor(backgroundRole(), Qt::white);
    setPalette(palette);
}

void MyWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::darkGreen);
    painter.drawRect(100, 60, 260, 240);

    painter.setPen(Qt::darkGray);
    painter.drawRect(103, 63, 260, 240);

    painter.setPen(Qt::darkRed);
    painter.drawText(170,150,"Hello world Qt!");
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWidget widget;
    widget.show();
    return app.exec();
}
