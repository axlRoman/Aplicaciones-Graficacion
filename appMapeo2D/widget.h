#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <qpainter.h>
#include <QtGui>

#include "mapeo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void paintEvent(QPaintEvent * event);
    void asignarFigura();
    void dibujarFiguraOriginal();
    void dibujarFiguraMapeada();


private slots:
    void on_pushButton_clicked();

    void on_pB_DibujoNormal_clicked();

    void on_pB_Mapeo_clicked();

    void on_pushButton_2_clicked();

    void on_ZoomMas_clicked();

    void on_ZoomMenos_clicked();

    void on_sbZoomMas_valueChanged(int arg1);

    void on_sbZoomMenos_valueChanged(int arg1);

private:
    Ui::Widget *ui;

    QPainter *canvas;
    float Fig[4][3]; // int **Fig
    float FigAux[4][3];

    float FigTrian[11][3];
    float FigTrianAux[11][3];

    float Picachu[15][3];
    float PicachuAux[15][3];

    int ancho;
    int centroX, centroY;
    bool dibujoOrientacionNormal;
    bool dibujoMapeado;

    int zoom;
};
#endif // WIDGET_H
