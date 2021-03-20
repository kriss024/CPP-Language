#pragma once

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QMainWindow *parent = 0);

private:
    void InitUi();

private slots:
    void handleButton();

protected:
    void closeEvent(QCloseEvent *event);

};
