#include "mapeo.h"
#include <math.h>

/*
Mapeo::Mapeo()
{

}
*/

void Mapeo::ventana(float wx1, float wy1, float wx2, float wy2)
{
    xWmin = wx1;
    yWmin = wy1;
    xWmax = wx2;
    yWmax = wy2;

}

void Mapeo::puerto(int pvx1, int pvy1, int pvx2, int pvy2)
{
    xpVMin = pvx1;
    ypVMin = pvy1;
    xpVMax = pvx2;
    ypVMax = pvy2;
}

void Mapeo::mapear(int xW, int yW, int &xp, int &yp, int L, int M)
{
    float sX, sY;
    sX = (xpVMax - xpVMin)/(xWmax - xWmin); //ESCALACION EN X
    cout<<"Escalacion en x = "<<sX<<endl;
    sY = (ypVMax - ypVMin)/(yWmax - yWmin); //ESCALACION EN Y
    cout<<"Escalacion en y = "<<sY<<endl;

    //NOTA: L Y M REPRESENTAN EL ORIGEN APARTIR DEL CUAL VAMOS A DIBUJAR
    xp = int (round(sX * (xW - xWmin) + xpVMin + L));
    yp = int (round(sY * (yWmin - yW) - xpVMin + M));
}
