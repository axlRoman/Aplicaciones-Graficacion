#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
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

private slots:
    void on_pushButton_clicked(); //LINEA DDA

    void on_pushButton_2_clicked(); //COLOR

private:
    Ui::Dialog *ui;

    void paintEvent(QPaintEvent *e);
    QColor color;
    QPainter *Canvas;

    int x1,y1,x2,y2;
};
#endif // DIALOG_H
