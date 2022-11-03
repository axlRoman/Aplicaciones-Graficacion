#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    mandelbrot();
}

void Dialog::mandelbrot()
{
    QPainter canvas(this);
    maxX = this->width();
        maxY = this->height();
        limite = 100;

        origX = -2.0;
        origY = -1.25;
        dimX = 0.5;
        dimY = 1.25;

        pasoX = (dimX - origX) / maxX;
        pasoY = (dimY - origY) / maxY;
        for(i=0; i<=maxX; i++){
            for(j=0; j<=maxY; j++){
                posX = origX + i * pasoX;
                posY = origY + j * pasoY;
                interX=0.0;
                interY=0.0;
                terminar = pasos=0;

                while(!terminar){
                    TempX = (interX * interX) - (interY * interY) + posX;
                    interY = 2 * (interX * interY) +posY;
                    interX = TempX;
                    pasos++;
                    if(hypot(fabs(interX),fabs(interY))>=2.0)
                        terminar++;
                    if(pasos>=limite)
                        terminar++;
                }
                if(pasos<limite)
                    canvas.drawPoint(i,j);
            }
        }
}


























