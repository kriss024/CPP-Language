#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QGraphicsEllipseItem>
#include <QTransform>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *window = new QWidget;
    window->resize(300, 200);
    QVBoxLayout *layout = new QVBoxLayout(window);
    QGraphicsScene *scene = new QGraphicsScene(window);
    QGraphicsView *view = new QGraphicsView(scene);
    QGraphicsTextItem *text =  scene->addText("Hello World");
    QGraphicsEllipseItem  *ellipse  = scene->addEllipse(-30,  -15,  120,  50);
    layout->addWidget(view);
    window->show();
    return a.exec();
}
