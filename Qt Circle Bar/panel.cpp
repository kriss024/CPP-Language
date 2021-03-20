#include "panel.h"

Panel::Panel(QLabel *parent){

    setBackgroundRole(QPalette::Base);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

int Panel::value() const
{
    return m_value;
}

void Panel::setValue(int value)
{
    if(value < 0)
        value = 0;
    if(value > 100)
        value = 100;
    if(m_value == value)
        return;

    m_value = value;
    update();
    emit valueChanged(m_value);

}

void Panel::wheelEvent(QWheelEvent *event)
{
    event->accept();
    setValue(value() + event->delta()/20);
}

void Panel::paintEvent(QPaintEvent* )
{

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.translate(width() / 2, height() / 2);

    for (int diameter = 0; diameter < 256; diameter += 9) {
           int alpha = 255 - diameter - value();
           if (alpha > 0) {
                       painter.setPen(QPen(QColor(0, diameter / 2, 127, alpha), 3));
                       painter.drawEllipse(QRectF(-(diameter+value()) / 2.0, -(diameter+value()) / 2.0, diameter+value(), diameter+value()));

                   }
    }

}
