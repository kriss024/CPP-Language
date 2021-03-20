#include <QLayout>
#include <QPushButton>
#include <QDebug>
#include "mainwindow.h"

MainWindow::MainWindow(QMainWindow *parent): QMainWindow(parent) {
    qDebug() << "Tworzenie okna";
    InitUi();
}

void MainWindow::InitUi() {
    this->setWindowTitle("Basic Layouts");
    QWidget *window = new QWidget(this);
    QPushButton *button1 = new QPushButton("Click Me!");
    connect(button1, SIGNAL (released()), this, SLOT (handleButton()));
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button1);
    window->setLayout(layout);
    setCentralWidget(window);

}

void MainWindow::handleButton(){
    qDebug() << "Click...";

}


void MainWindow::closeEvent(QCloseEvent *event){
    qDebug() << "Zamykanie okna";
}
