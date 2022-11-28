#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    dibujoOrientacionNormal = dibujoMapeado = false;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    canvas = new QPainter(this);
    if(dibujoOrientacionNormal)
        dibujarFiguraOriginal();
    else if(dibujoMapeado)
        dibujarFiguraMapeada();

    canvas->end();
}

void Widget::asignarFigura()
{
                //USAR COORDENADAS HOMOGENEAS
/*
    Fig[0][0] = 10; Fig[0][1] = 10; Fig[0][2] = 1;
    Fig[1][0] = 30; Fig[1][1] = 10; Fig[1][2] = 1;
    Fig[2][0] = 10; Fig[2][1] = 30; Fig[2][2] = 1;
    Fig[3][0] = 10; Fig[3][1] = 10; Fig[3][2] = 1;
    //COMPLETAR EL DIBUJO DEL TRIANGULO
*/

/*
    //Estrella
    FigTrian[0][0] = 30; FigTrian[0][1] = 10; FigTrian[0][2] = 1;
    FigTrian[1][0] = 60; FigTrian[1][1] = 35; FigTrian[1][2] = 1;
    FigTrian[2][0] = 90; FigTrian[2][1] = 10; FigTrian[2][2] = 1;
    FigTrian[3][0] = 80; FigTrian[3][1] = 50; FigTrian[3][2] = 1;
    FigTrian[4][0] = 110; FigTrian[4][1] = 70; FigTrian[4][2] = 1;
    FigTrian[5][0] = 70; FigTrian[5][1] = 70; FigTrian[5][2] = 1;
    FigTrian[6][0] = 60; FigTrian[6][1] = 110; FigTrian[6][2] = 1;
    FigTrian[7][0] = 50; FigTrian[7][1] = 70; FigTrian[7][2] = 1;
    FigTrian[8][0] = 10; FigTrian[8][1] = 70; FigTrian[8][2] = 1;
    FigTrian[9][0] = 40; FigTrian[9][1] = 50; FigTrian[9][2] = 1;
    FigTrian[10][0] = 30; FigTrian[10][1] = 10; FigTrian[10][2] = 1;
*/
/*
    //Estrella en una hoja de maquina
    FigTrian[0][0] = 4; FigTrian[0][1] = 0; FigTrian[0][2] = 1;
    FigTrian[1][0] = 11; FigTrian[1][1] = 6.5; FigTrian[1][2] = 1;
    FigTrian[2][0] = 18; FigTrian[2][1] = 0; FigTrian[2][2] = 1;
    FigTrian[3][0] = 15; FigTrian[3][1] = 10.5; FigTrian[3][2] = 1;
    FigTrian[4][0] = 22; FigTrian[4][1] = 17; FigTrian[4][2] = 1;
    FigTrian[5][0] = 13.5; FigTrian[5][1] = 17; FigTrian[5][2] = 1;
    FigTrian[6][0] = 11; FigTrian[6][1] = 28; FigTrian[6][2] = 1;
    FigTrian[7][0] = 8; FigTrian[7][1] = 17; FigTrian[7][2] = 1;
    FigTrian[8][0] = 0; FigTrian[8][1] = 17; FigTrian[8][2] = 1;
    FigTrian[9][0] = 6.5; FigTrian[9][1] = 10.5; FigTrian[9][2] = 1;
    FigTrian[10][0] = 4; FigTrian[10][1] = 0; FigTrian[10][2] = 1;
*/
    //Pichachu
    Picachu[0][0] = 8; Picachu[0][1] = 0; Picachu[0][2] = 1;
    Picachu[1][0] = 14; Picachu[1][1] = 0; Picachu[1][2] = 1;
    Picachu[2][0] = 20; Picachu[2][1] = 4; Picachu[2][2] = 1;
    Picachu[3][0] = 19; Picachu[3][1] = 13.5; Picachu[3][2] = 1;
    Picachu[4][0] = 22; Picachu[4][1] = 17; Picachu[4][2] = 1;
    Picachu[5][0] = 22; Picachu[5][1] = 20.5; Picachu[5][2] = 1;
    Picachu[6][0] = 20; Picachu[6][1] = 20.5; Picachu[6][2] = 1;
    Picachu[7][0] = 15; Picachu[7][1] = 17; Picachu[7][2] = 1;
    Picachu[8][0] = 7; Picachu[8][1] = 17; Picachu[8][2] = 1;
    Picachu[9][0] = 2; Picachu[9][1] = 20.5; Picachu[9][2] = 1;
    Picachu[10][0] = 0; Picachu[10][1] = 20.5; Picachu[10][2] = 1;

    Picachu[11][0] = 0; Picachu[11][1] = 17; Picachu[11][2] = 1;
    Picachu[12][0] = 3; Picachu[12][1] = 13.5; Picachu[12][2] = 1;
    Picachu[13][0] = 2; Picachu[13][1] = 4; Picachu[13][2] = 1;
    Picachu[14][0] = 8; Picachu[14][1] = 0; Picachu[14][2] = 1;






/*
    //PARA UN ESPACIO DE 10000, 10000
    Fig[0][0] = 0; Fig[0][1] = 0; Fig[0][2] = 1;
    Fig[1][0] = 10000; Fig[1][1] = 0; Fig[1][2] = 1;
    Fig[2][0] = 0; Fig[2][1] = 10000; Fig[2][2] = 1;
    Fig[3][0] = 0; Fig[3][1] = 0; Fig[3][2] = 1;
*/
/*
    //PARA UN ESPACIO DE 10, 10
    Fig[0][0] = -3.2; Fig[0][1] = -4.1; Fig[0][2] = 1;
    Fig[1][0] = -6.7; Fig[1][1] = -4.1; Fig[1][2] = 1;
    Fig[2][0] = -3.2; Fig[2][1] = -7.7; Fig[2][2] = 1;
    Fig[3][0] = -3.2; Fig[3][1] = -4.1; Fig[3][2] = 1;
*/
/*
    //PARA UN ESPACIO DE 22, 28
    Fig[0][0] = 4; Fig[0][1] = 8; Fig[0][2] = 1;
    Fig[1][0] = 4; Fig[1][1] = 22; Fig[1][2] = 1;
    Fig[2][0] = 18; Fig[2][1] = 8; Fig[2][2] = 1;
    Fig[3][0] = 4; Fig[3][1] = 8; Fig[3][2] = 1;
*/
/*
    //Respaldar LOS VALORES DEL ARREGLO ORIGINAL EN EL ARREGLO AUXILIAR
    for (int r = 0; r < 4; r++) {
        for(int c = 0; c<3; c++)
            FigAux[r][c] = Fig[r][c];
    }
*/
/*
    //Respaldar LOS VALORES DEL ARREGLO ORIGINAL Estrella EN EL ARREGLO AUXILIAR
        for (int r = 0; r < 11; r++) {
            for(int c = 0; c < 3; c++)
                FigTrianAux[r][c] = FigTrian[r][c];
        }
*/
    //Respaldar LOS VALORES DEL ARREGLO ORIGINAL Picachu EN EL ARREGLO AUXILIAR
    for (int r = 0; r < 15; r++) {
        for(int c = 0; c < 3; c++)
            PicachuAux[r][c] = Picachu[r][c];
        }


    //ESTABLECEMOS EL ANCHO
    ancho = this->size().width() - ui->widget->size().width();

    //CENTRO DEL AREA DEL DIBUJO
    centroX = ancho / 2;
    centroY = this->size().height()/2;

}

void Widget::dibujarFiguraOriginal()
{
    QPen color (QColor(0,0,240));
    canvas->setPen(color);
    //Esquina Superior Izquierda
    //linea horizontal
    /*canvas->drawLine(0,0, ancho, 0);
    //linea vertical
    canvas->drawLine(0,0,0,this->size().height());
*/

    //Para el centro
    //linea horizontal
    canvas->drawLine(0,this->size().height()/2, ancho, this->size().height()/2);
    //linea vertical
    canvas->drawLine(ancho/2,0,ancho/2,this->size().height());

    canvas->setPen(QColor(255,0,0));
/*
    for(int i = 0; i < 3; i++){
        //Dibujar en la esquina superior izquierda
        //canvas->drawLine(Fig[i][0],Fig[i][1],Fig[i+1][0],Fig[i+1][1]);

        //Dibujar en el centro del canvas o forma
        //canvas->drawLine(centroX + Fig[i][0], centroY + Fig[i][1], centroX + Fig[i+1][0], centroY + Fig[i+1][1]);

        //ajuste para visualizar las 10000 unidades
        //canvas->drawLine(centroX + Fig[i][0]/100 , centroY + Fig[i][1]/100, centroX + Fig[i+1][0]/100, centroY + Fig[i+1][1]/100);
        canvas->drawLine(centroX + Fig[i][0] , centroY + Fig[i][1], centroX + Fig[i+1][0], centroY + Fig[i+1][1]);
    }
*/

    /*
    for(int i = 0; i < 11; i++){
            //Dibujar en la esquina superior izquierda
            //canvas->drawLine(Fig[i][0],Fig[i][1],Fig[i+1][0],Fig[i+1][1]);

            //Dibujar en el centro del canvas o forma
            canvas->drawLine(centroX + FigTrian[i][0], centroY + FigTrian[i][1], centroX + FigTrian[i+1][0], centroY + FigTrian[i+1][1]);
        }
*/

    //Picachu
    for(int i = 0; i < 15; i++){
            //Dibujar en la esquina superior izquierda
            //canvas->drawLine(Fig[i][0],Fig[i][1],Fig[i+1][0],Fig[i+1][1]);

            //Dibujar en el centro del canvas o forma
            canvas->drawLine(centroX + Picachu[i][0], centroY + Picachu[i][1], centroX + Picachu[i+1][0], centroY + Picachu[i+1][1]);
        }
}

void Widget::dibujarFiguraMapeada()
{
    QPen color(QColor(255,0,0));

    canvas->setPen(color);

    /*
    //LINEA HORIZONTAL PARA DIBUJAR EL PRIMER CUADRANTE
    canvas->drawLine(0,size().height(), ancho, size().height());
    //LINEA VERTICAL
    canvas->drawLine(0,0,0, size().height());
*/
    //Para 4 Cuadrantes
    //Para el centro
    //linea horizontal
    //canvas->drawLine(0,this->size().height()/2, ancho, this->size().height()/2);
    //linea vertical
    //canvas->drawLine(ancho/2,0,ancho/2,this->size().height());

    Mapeo dibujo;
    /*
    //ESCALACION 1 : 1
    dibujo.ventana(0, 0 ,ancho, size().height());
    dibujo.puerto(0, 0, ancho, size().height());

    //ESCALACION 1 : 0.5
    dibujo.puerto(0, 0, ancho/2, size().height()/2);

    //ESTO ES PARA HACERLO CON MEDIDAS DEL MUNDO REAL, HACIENDO EL AJUSTE NECESARIO
    //ESCALACION 10000 : 0.025
    dibujo.ventana(0, 0 ,10000, 10000);
    dibujo.puerto(0, 0, ancho/2, size().height()/2);

    //Con escalacion 1 : 25
    dibujo.ventana(0, 0 ,10, 10);
    dibujo.puerto(0, 0, ancho/2, size().height()/2);

    //DISEMSIONES PARA UNA HOJA DEL CUADERNO
    //CON ESCALACION EN X 1 : 11.3636 Y EN Y 1: 8.92857
    dibujo.ventana(0, 0 ,22, 28);
    dibujo.puerto(0, 0, ancho/2, size().height()/2);
*/
    dibujo.ventana(0, 0 ,22, 28);
    //dibujo.puerto(150, 100, 200, 300); //REpresentan al rect
    dibujo.puerto(150-zoom, 100-zoom, 370+zoom, 380+zoom);
                //150 + 220  //100+ 280

    //EL VALOR DE M SE OBTINES SUMANDO EL YPVMIN + YPVMAX

    //DIBUJAR EL RECTANGULO QUE SIMILARA LA HOJA DE MAQUINA
    //canvas->drawRect(150-3,100-3,200+7,300+7);

    //PARA UNA ESCALA DE 1:10
    canvas->drawRect(150-3,100-3,220+7,280+7);

    canvas->setPen(QColor(0,60,255));
    //ORIGEN EN LA ESQUINA INFERIOR IZQUIERDA

//    int L = 0;
//    int M = this->size().height();


    //DIBUJAR EN EL CENTRO DE LA FORMA O CANVAS
    int L = 0; //centroX;

    //int M = 500; //100x100

    //int M = 550;//100 + 300; //centroY;
    int M = 530;

    //VARIABLES PARA MANEJAR LOS VERTICES DE LA FIGURA
    int x1, y1, x2, y2;

/*
    for(int i = 0; i < 3; i++){
        dibujo.mapear(Fig[i][0], Fig[i][1], x1, y1, L, M);
        dibujo.mapear(Fig[i+1][0], Fig[i+1][1], x2, y2, L, M);
        canvas->drawLine(x1, y1, x2, y2);
    }
*/
/*

    for(int i = 0; i < 11; i++){
            dibujo.mapear(FigTrian[i][0], FigTrian[i][1], x1, y1, L, M);
            dibujo.mapear(FigTrian[i+1][0], FigTrian[i+1][1], x2, y2, L, M);
            canvas->drawLine(x1, y1, x2, y2);
        }
*/

    //Pichachu

    for(int i = 0; i < 15; i++){
            dibujo.mapear(Picachu[i][0], Picachu[i][1], x1, y1, L, M);
            dibujo.mapear(Picachu[i+1][0], Picachu[i+1][1], x2, y2, L, M);
            canvas->drawLine(x1, y1, x2, y2);
        }


}

void Widget::on_pB_DibujoNormal_clicked()
{
    asignarFigura();
    dibujoOrientacionNormal = true;
    dibujoMapeado = false;
    repaint();
}

void Widget::on_pB_Mapeo_clicked()
{
    asignarFigura();
    dibujoOrientacionNormal = false;
    dibujoMapeado = true;
    repaint();
}

void Widget::on_ZoomMas_clicked()
{
    zoom +=10;
    on_pB_Mapeo_clicked();
}


void Widget::on_ZoomMenos_clicked()
{
    zoom -=10;
    on_pB_Mapeo_clicked();
}
