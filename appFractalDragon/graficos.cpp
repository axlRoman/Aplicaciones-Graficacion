#include "graficos.h"

/*Graficos::Graficos()
{

}*/

void Graficos::lineaDDA(int x1, int y1, int x2, int y2, QPainter *canvas)
{
    int dx, dy, steps, k;
    float x_inc, y_inc, x, y;
    dx = x2 - x1;
    dy= y2 - y1;

    if(redondear(dx) > redondear(dy))
        steps = redondear(dx);
    else
        steps = redondear(dy);
    x_inc = (float)dx/steps;
    y_inc = (float)dy/steps;
    x= x1;
    y= y1;
    //putpixel(floor(x),floor(y),1);
    QPen pen (QColor(150,0,255),3);
    canvas->setPen(pen);
    canvas->drawPoint(qRound(x),redondear(y));
    for(k=1; k < steps+1; k++){
        x= x+x_inc;
        y= y+y_inc;
        //putpixel(floor(x), floor(y), 1);
        canvas->drawPoint(round(x),redondear(y));
    }
}

void Graficos::lineaDDA(int x1, int y1, int x2, int y2, QPainter *canvas, QColor color)
{
    int dx, dy, steps, k;
    float x_inc, y_inc, x, y;
    dx = x2 - x1;
    dy= y2 - y1;

    if(redondear(dx) > redondear(dy))
        steps = redondear(dx);
    else
        steps = redondear(dy);
    x_inc = (float) dx/steps;
    y_inc = (float) dy/steps;
    x= x1;
    y= y1;
    //putpixel(floor(x),floor(y),1);
    QPen pen (color,3);
    canvas->setPen(pen);

    canvas->setPen(color);

    canvas->drawPoint(qRound(x),redondear(y));
    for(k=1; k<steps+1; k++){
        x= x+x_inc;
        y= y+y_inc;
        //putpixel(floor(x), floor(y), 1);
        canvas->drawPoint(round(x),redondear(y));
    }
}
