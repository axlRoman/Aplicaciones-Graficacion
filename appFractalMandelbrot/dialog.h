#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

#include <QTimer>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QColorDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;

    void paintEvent(QPaintEvent *e);

    void mandelbrot();

    int maxX, maxY, limite, i, j, pasos, terminar;
    double pasoX, pasoY, posX, posY, origX, origY, dimX, dimY, interX, interY, TempX;
};
#endif // DIALOG_H
