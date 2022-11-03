#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

#include <QTimer>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QColorDialog>

#include "graficos.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void keyPressEvent(QKeyEvent *evento);

private slots:
    void on_pushButton_clicked();    

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Dialog *ui;
    QTimer *timerDragon, *timerArabesco, *timerKoch,
            *timerSierpinski, *timerMalthus, *timerHenon,
            *timerMandelbrot;
    void paintEvent(QPaintEvent *e);
    //Fractal Dragon
    void dragon();//EN ESTA APP SERIA LA FUNCION MAIN() DE LAS COPIAS

    void dragon(int limite, QPainter *canvas); //REPRESENTA A LA FUNCION MAIN()
    void generarDragon(QPainter *canvas);

    //Fractal Arabesco
    void arabesco(int limite, QPainter *canvas);
    void generarArabesco(QPainter *canvas);

    int ejeX[4098], ejeY[4098];
    int paso, signo;

    int li,ls; //limites para controlar la salida del dragon
    bool band;

    Graficos *grafico;
    QColor color;

    //Fractal curva de Koch
    void k_curve(double x, double y, double lenght, double angle, int n_order, QPainter *canvas);
    void line1(int x_1, int y_1, int x_2, int y_2, QPainter *canvas);

    void koch(int x, int y, int l, int angle, int n, QPainter *canvas);

    int lik, lsk; //limites para controlar la salida de la curva de koch


    //Fractal Sierpinski
    void dibujaTriangulo(float x1, float y1, float x2, float y2, float x3, float y3, QPainter *canvas, int n);
    void subTriangulo(int n, float x1, float y1, float x2, float y2, float x3, float y3, QPainter *canvas);

    void sierpinski(int n, QPainter *canvas);
    int ns;

    //Fractal de Malthus
    void malthus(int li,QPainter *canvas);
    int i, j, k, l, contador, lim, lsm;
    double pobAnt, pobNueva, x, y, razon;

    //Curva de Henon
    void henon(QPainter *canvas);
    double escalaX, escalaY, despX, despY;

    //Mandelbrot
    void mandelbrot(QPainter *canvas);

    int maxX, maxY, limite, imb, jmb, pasos, terminar;
    double pasoX, pasoY, posX, posY, origX, origY, dimX, dimY, interX, interY, TempX;

    //void paintEvent(QPaintEvent *evento);
};
#endif // DIALOG_H
