#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>

#include <QtGui>

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
    void on_pushButton_clicked();

    void moverEtiquetaH();

    void moverEtiquetaV();

    void moverEtiqueta2();

    //void moverEtiquetaV2();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_horizontalSlider_valueChanged();

    void on_dial_valueChanged();

    void on_spinBox_valueChanged();

    void on_pushButton_6_clicked();

    void moverPez();

    void on_MoverPez_clicked();

    void on_DetenerPez_clicked();

private:
    Ui::Dialog *ui;
    QTimer *timer1,
    *timer2,
    *timer3,
    *timer4;//mover pez
    int velocidadDial, velocidadSpinner, velocidadSlider;
};
#endif // DIALOG_H
