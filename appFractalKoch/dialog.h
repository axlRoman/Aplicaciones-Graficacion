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

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    QTimer *timerKoch;
    QPainter *canvas;

    void paintEvent(QPaintEvent *e);

    void k_curve(double x, double y, double lenght, double angle, int n_order, QPainter *canvas);
    void line1(int x_1, int y_1, int x_2, int y_2, QPainter *canvas);

    void koch(int x, int y, int l, int angle, int n, QPainter *canvas);
    QColor color;

    bool band;
    int li,ls;
};
#endif // DIALOG_H
