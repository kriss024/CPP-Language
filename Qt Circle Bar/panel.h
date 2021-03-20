#ifndef PANEL_H
#define PANEL_H

#include <QLabel>
#include <QPainter>
#include <QPainterPath>
#include <QWheelEvent>

class Panel : public QLabel
{
    Q_OBJECT

private:
    int m_value =0;

public:
    explicit Panel(QLabel *parent = 0);
    int value() const;

protected:
    void paintEvent(QPaintEvent* );
    void wheelEvent(QWheelEvent* );

signals:
    void valueChanged(int);

public slots:
    void setValue(int);


};

#endif // PANEL_H
