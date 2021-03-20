#ifndef FIGURA_H
#define FIGURA_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QSlider>
#include <QSlider>
#include <QMessageBox>
#include "panel.h"

class Figura: public QMainWindow
{
    Q_OBJECT
public:
    explicit Figura(QWidget *parent = 0);

private:
    void createUserInterface();
    QWidget *window;
    QVBoxLayout *layout;
    Panel *panel;
    QSlider *slider;

protected:
    void closeEvent(QCloseEvent *event) override;
    void resizeEvent(QResizeEvent* event) override;

public slots:

};

#endif // FIGURA_H
