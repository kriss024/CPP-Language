#include <QApplication>
#include <QWidget>
#include <QPushButton>


int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    QWidget *window = new QWidget;

    window->resize(250, 150);
    window->move(300, 300);
    window->setWindowTitle("ToolTip");
    window->setToolTip("QWidget");

    QPushButton *button = new QPushButton("Click Me!", window);
    button->move(100, 100);
    button->show();
    QObject::connect(button, SIGNAL(clicked()),window, SLOT(close()));

    window->show();

    return app.exec();
}
