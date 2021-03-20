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

MyWidget::MyWidget() {
    resize(600,300);
    setStyleSheet("background-color:black;");
}

void MyWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    int x = painter.device()->width();
    int y = painter.device()->height();

    int xh = int(x*0.4);
    int yh = int(y*0.4);

    painter.setRenderHint(QPainter::Antialiasing);

    QPixmap pixmap(x, y);
    pixmap.fill( Qt::white );

    QPainterPath path;

    path.addEllipse(80, 80, 80, 80);

    path.moveTo(120, 120);
    path.lineTo(120, 40);
    path.arcTo(40, 40, 160, 160, 90, 90);
    path.lineTo(120, 120);

    QFont font = QApplication::font();
    font.setPixelSize(40);
    QString str;
    str.append(QString("x = %1").arg(x));
    str.append(QString("y = %1").arg(y));

    path.addText(xh, yh, font, str);

    painter.setPen(Qt::black);
    painter.setBrush(Qt::gray);

    painter.drawPath(path);

}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWidget widget;
    widget.show();
    return app.exec();
}

