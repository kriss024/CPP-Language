#include "figura.h"

Figura::Figura(QWidget *parent)
{
    createUserInterface();
}
void Figura::createUserInterface(){
    setWindowTitle(tr("The CircleBar"));

    resize(300,300);

    layout = new QVBoxLayout();

    window = new QWidget();
    window->setLayout(layout);

    panel = new Panel();
    layout->addWidget(panel);

    slider = new QSlider(Qt::Horizontal);
    layout->addWidget(slider);

    setCentralWidget(window);
    connect(slider, SIGNAL(valueChanged(int)), panel, SLOT(setValue(int)));

    slider->setValue(50);
}



void Figura::resizeEvent(QResizeEvent* event)
{

}


void Figura::closeEvent(QCloseEvent *event)
{
    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");
    msgBox.setInformativeText("Do you want to close application?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int ret = msgBox.exec();

    switch (ret) {
      case QMessageBox::Yes:
          event->accept();
          break;
      case QMessageBox::Discard:
          event->ignore();
          break;
      case QMessageBox::Cancel:
          event->ignore();
          break;
      default:
          // should never be reached
          break;
    }

}
