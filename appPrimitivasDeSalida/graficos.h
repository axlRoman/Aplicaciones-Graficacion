#ifndef GRAFICOS_H
#define GRAFICOS_H

#include <QtGui>
#include <QtCore>
#include <QPainter>
#include <QColor>

class Graficos
{
    //Todos los atributos o metodos que se declaren antes de
    //alguna etiqueta modificadora por default en C++ son PRIVATE
//private:
public:
    int redondear(float n){
        return int (n + 0.5);
    }
    //Graficos();

    void lineaDDA(int x1, int y1, int x2, int y2, QPainter *canvas);
    void lineaDDA(int x1, int y1, int x2, int y2, QPainter *canvas, QColor color);

    void circuloPitagoras(int xc, int yc, int radio, QPainter *canvas);
    void circuloPolar(int xc, int yc, int rad, QPainter *canvas);

    void espiral1(QPainter *canvas , QColor color, double factor);
    void espiral2(QPainter *canvas , QColor color, double theta, double r);

    void cuadrado(QPainter *canvas , QColor color, int x1, int y, int x2, int y2);
    void triangulo(QPainter *canvas, QColor color, int x1,int x2, int y);
};

#endif // GRAFICOS_H
