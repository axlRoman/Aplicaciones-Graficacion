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
};

#endif // GRAFICOS_H
