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
    QTimer *timerDragon, *timerArabesco;
    void paintEvent(QPaintEvent *e);
    void dragon();//EN ESTA APP SERIA LA FUNCION MAIN() DE LAS COPIAS

    void dragon(int limite, QPainter *canvas); //REPRESENTA A LA FUNCION MAIN()

    void arabesco(int limite, QPainter *canvas); //REPRESENTA A LA FUNCION MAIN()

    void extranioCodificador();

    void generarDragon(QPainter *canvas);
    void generarArabesco(QPainter *canvas);
    int ejeX[4098], ejeY[4098];
    int paso, signo;

    int li,ls; //limites para controlar la salida del dragon
    bool band;

    Graficos *grafico;
    QColor color;

    //void paintEvent(QPaintEvent *evento);
};
#endif // DIALOG_H
