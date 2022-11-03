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

    QPainter *canvas;
    QTimer *timerHenon;

    void paintEvent(QPaintEvent *e);

    void henon(QPainter *canvas);

    int maxX, maxY;
    double escalaX, escalaY, despX, despY;

    int li,ls;
    bool band;
};
#endif // DIALOG_H
