#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

#include <QTimer>
#include <QKeyEvent>
#include <QRandomGenerator>

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

private:
    Ui::Dialog *ui;

    QTimer *timerSierpinski;
    void paintEvent(QPaintEvent *e);
    void dibujaTriangulo(float x1, float y1, float x2, float y2, float x3, float y3);
    void subTriangulo(int n, float x1, float y1, float x2, float y2, float x3, float y3);

    void sierpinski();

    bool band;
};
#endif // DIALOG_H
