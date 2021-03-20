#include <QApplication>
#include <QWidget>
#include <QtGui>


class MyWidget : public QWidget
{
public:
    MyWidget();
    int mouseX, mouseY;

protected:
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *ev);
};

MyWidget::MyWidget() {
    resize(600,300);
    setMouseTracking(true);
    setMinimumSize(100, 100);
    setStyleSheet("background-color:black;");
}

void MyWidget::mouseMoveEvent(QMouseEvent *ev)
{
    QPoint pos = ev->pos();
    mouseX = pos.x();
    mouseY = pos.y();
    update();
 }

void MyWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    int x = painter.device()->width();
    int y = painter.device()->height();

    painter.setRenderHint(QPainter::Antialiasing);

    QPixmap pixmap(x, y);
    QPainterPath path;

    QFont font = QApplication::font();
    font.setPixelSize(40);
    QString tekst = QString("x = %1, y = %2").arg(mouseX).arg(mouseY);
    path.addText(mouseX, mouseY, font, tekst);

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

