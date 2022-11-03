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
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    QPainter *canvas;
    QTimer *timerMalthus;

    void paintEvent(QPaintEvent *e);

    void extranioCodificador(int li,QPainter *canvas);

    void malthus();

    int i, j, k, l, contador, li, ls;
    double pobAnt, pobNueva, x, y, razon;

    bool band;
};
#endif // DIALOG_H
