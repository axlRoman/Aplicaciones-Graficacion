#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    li=0;
    ls=15;
    band=1;

    timerMalthus = new QTimer();
    connect(timerMalthus,SIGNAL(timeout()), this, SLOT(repaint()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    QPainter *canvas = new QPainter(this);



        if(band){
            if(li<=ls){
                extranioCodificador(li,canvas);
                li++;
            }
            else
                band = false;
        }
        if(!band){
            li--;
            extranioCodificador(li,canvas);
            if(li == 0)
                band = true;
        }

    canvas->end();
}


void Dialog::extranioCodificador(int li, QPainter *canvas)
{
    pobAnt = pobNueva = 0.0;
    razon = 2.3;
    y=0;

    for(j = 1; j <= li; j++){
        for(k = 1; k <=li; k++){
            contador = 0;
            razon = razon + 0.01;
            pobAnt = 0.01;
            for(i = 1; i <= 1000; i++){
                pobNueva = razon * (pobAnt *(1-pobAnt));
                x = pobNueva - pobAnt;
                canvas->drawPoint((x * this->width() / 2) + (this->width()/2)+50, (this->height()/2) - (y*this->height()/2)-100);
                if(pobAnt == pobNueva)
                    contador++;
                else
                    contador = 0;
                if(contador>100)
                    i=1000;
                pobAnt = pobNueva;
                y=x;
            }
        }
    }
}











/*
contador = 0;
razon +=0.01;
pobAnt = 0.01;
for(i=1; i<=this->width(); i++){
    pobNueva = razon * (pobAnt * (1-pobAnt));
    x= pobAnt * this->width();
    y= this->height() - (pobNueva * this->height());
    can->drawPoint(this->width(),this->height());

    if(pobAnt == pobNueva)
        contador++;
    else
        contador=0;
    if(contador>10)
        i=this->width();
    pobAnt = pobNueva;

}*/














void Dialog::on_pushButton_clicked()
{
    timerMalthus->start(100);
    this->repaint();
}

