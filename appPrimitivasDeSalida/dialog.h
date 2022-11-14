#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QColorDialog>
#include <QMouseEvent>

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

private slots:
    void on_pushButton_clicked(); //LINEA DDA

    void on_pushButton_2_clicked(); //COLOR

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_radioButton2_clicked();

    void on_radioButton1_clicked();

    void on_pushButton_5_clicked();

    void on_radioButton3_clicked();

    void on_pushButton_6_clicked();

    void on_sbFactorEspiral1_valueChanged(double arg1);

    void on_sbTetaEspiral2_valueChanged(double arg1);

    void on_sbRadioEspiral2_valueChanged(double arg1);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::Dialog *ui;

    void paintEvent(QPaintEvent *e);
    QColor color;
    QPainter *Canvas;

    int x1,y1,x2,y2, xc, yc, radio;

    bool linea;
    bool circuloPitagoras;
    bool circuloPolar;
    bool espiral1;
    bool espiral2;
    bool cuadrado;
    bool triangulo;

    double factorEspiral1;
    double thetaEspiral2, radioEspiral2;

    QTimer *timerEspiral;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
};
#endif // DIALOG_H
