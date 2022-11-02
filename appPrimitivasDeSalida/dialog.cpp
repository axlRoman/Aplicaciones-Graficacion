#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    x1 = y1 = x2 = y2 = 0;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    Canvas = new QPainter(this);

    //Graficos graficos;
    Graficos *graficos = new Graficos();

    graficos->lineaDDA(x1,y1,x2,y2,Canvas, color);

    // TAREA: UTILIZAR LA CLASE GRAFICOS PARA PROBAR EL FRACTAL DRAGON
    // ADEMAS DE LAS PRACTICAS ENCARGADAS EN CLASE

    Canvas->end();
}


void Dialog::on_pushButton_clicked()
{
    x1 = ui->lineX1->text().toInt();
    y1 = ui->lineY1->text().toInt();
    x2 = ui->lineX2->text().toInt();
    y2 = ui->lineY2->text().toInt();

    //update();
    this->repaint();
}


void Dialog::on_pushButton_2_clicked()
{
    QColor seleccionaColor = QColorDialog::getColor(Qt::white,this,"Selecciona un color");
    if(seleccionaColor.isValid())
        color= seleccionaColor;
}



