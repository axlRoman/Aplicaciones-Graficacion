#ifndef MAPEO_H
#define MAPEO_H

#include <iostream>
using namespace std;


class Mapeo
{
    float xWmin, yWmin, xWmax, yWmax;
    int xpVMin, ypVMin, xpVMax, ypVMax;


public:
    //Mapeo();

    void ventana(float wx1, float wy1, float wx2, float wy2);
    void puerto(int pvx1, int pvy1, int pvx2, int pvy2);
    void mapear(int xW, int yW, int &xp, int &yp, int L, int M); //las referecias se trabajan con & /* & Nos da la referencia o la direccion */
};

#endif // MAPEO_H
