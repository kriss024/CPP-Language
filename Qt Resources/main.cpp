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
    resize(900,600);
    setMinimumSize(300,200);
    setStyleSheet("background-color:black;");
}

void MyWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);
    int x = painter.device()->width();
    int y = painter.device()->height();
    QPixmap pixmap = QPixmap(":/images/Sylwester_studencki.jpg");
    painter.drawPixmap(0,0,x,y,pixmap);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWidget widget;
    widget.show();
    return app.exec();
}

