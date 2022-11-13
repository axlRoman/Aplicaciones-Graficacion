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

    if(abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    x_inc = (float)dx/steps;
    y_inc = dy/float(steps);
    x= x1;
    y= y1;
    //putpixel(floor(x),floor(y),1);
    QPen pen (QColor(150,0,255),3);
    canvas->setPen(pen);
    canvas->drawPoint(qRound(x),redondear(y));
    for(k=1; k < steps+1; k++){
        x= x + x_inc;
        y= y + y_inc;
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

    if(abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    x_inc = (float) dx/steps;
    y_inc = (float) dy/steps;
    x= x1;
    y= y1;
    //putpixel(floor(x),floor(y),1);
    QPen pen (color,3);    
    canvas->setPen(color);
    canvas->drawPoint(qRound(x),redondear(y));
    for(k=1; k<steps+1; k++){
        x= x + x_inc;
        y= y + y_inc;
        //putpixel(floor(x), floor(y), 1);
        canvas->drawPoint(round(x),redondear(y));
    }
}

void Graficos::circuloPitagoras(int xc, int yc, int radio, QPainter *canvas)
{
    float y;
    for(int x = xc - radio; x<=xc+radio; x++){
        y = yc + sqrt((radio*radio) - pow((x-xc),2.0));
        canvas->drawPoint(x,y);
        y = yc - sqrt((radio*radio) - pow((x-xc),2.0));
        canvas->drawPoint(x,y);
    }
}

void Graficos::circuloPolar(int xc, int yc, int rad, QPainter *canvas)
{
    canvas->setPen(QColor(0,0,200));
    float dt, ct, st, x, y, xtemp;
    dt = 1.0 /rad;
    ct = cos(dt);
    st = sin(dt);

    x = 0;
    y = rad;
    while(y >= x){
        canvas->drawPoint(round(xc + x) + 0.5, round(yc + y) + 0.5);
        canvas->drawPoint(round(xc - x) + 0.5, round(yc + y) + 0.5);
        canvas->drawPoint(round(xc + x) + 0.5, round(yc - y) + 0.5);
        canvas->drawPoint(round(xc - x) + 0.5, round(yc - y) + 0.5);

        xtemp = x;
        x = x * ct - y * st;
        y = y * ct + xtemp * st;
    }
}

void Graficos::espiral1(QPainter *canvas, QColor color, double factor)
{
    int xc = canvas->window().width()/2;
    int yc = canvas->window().height()/2-100;
    int radio = 5;
    const double dosPi = M_PI * 2;
    //cont double dos_pi = 3.14159 * 2;
    canvas->setPen(color);

    double dth, cdth, sdth, x, y, xtemp, xt, yt;

    //dth = dosPi / (16 * radio);  base
    dth = dosPi / (factor * radio);
    cdth = cos(dth);
    sdth = sin(dth);
    int cont = 0;

    x = 0.0;
    y = radio;
    xt = xc + x;
    yt = yc + y;

    do{
        xtemp = x;
        x = (x * cdth - y * sdth);
        y = (y * cdth + xtemp *sdth);
        if(x > 0)
            x += 0.5;
        else
            x -= 0.5;

        if(y > 0)
            y += 0.5;
        else
            y -= 0.5;

        //canvas->drawPoint(round(xt), round(yt));
        //canvas->drawPoint(round(xtemp), round(ytemp), round(xc + x), round(yc + y));
        canvas->drawLine(round(xt), round(yt), round(xc + x), round(yc + y));
        //lineaDDA(round(xt), round(yt), round(xc + x), round(yc + y), canvas, color);
        xt = xc + x;
        yt = yc + y;
        cont++;
    }while(cont <= 250);
}

void Graficos::espiral2(QPainter *canvas, QColor color, double theta, double r)
{
    int xc = canvas->window().width()/2;
    int yc =  canvas->window().height()/2 - 100;
    float radio = r;
    canvas->setPen(color);
    double th, x, y, xt, yt;
    th = 0.0;
    x = radio * cos(th);
    y = radio * sin(th);
    xt = xc + x;
    yt = yc + y;

    while(radio < 200){
        th += theta;
        radio += r;
        x = radio * cos(th);
        y = radio * sin(th);        
        lineaDDA(round(xt), round(yt), round(xc + x), round(yc + y), canvas, color);
        xt = xc + x;
        yt = yc + y;
    }
}//FIN DEL ESPIRAL2








