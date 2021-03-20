#include "rectangle.h"

void Rectangle::set_values (int x, int y) {
    slot_wh(x,y);
}

int Rectangle::area(){
   return (width*height);
}

void Rectangle::slot_wh(int w, int h)
{
    if ((w!=width)||(h!=height)) {
        width = w;
        height = h;
        emit signal_wh(w,h);
    }

}
