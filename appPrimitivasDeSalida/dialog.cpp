#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    x1 = y1 = x2 = y2 = 0;  
    linea = circuloPitagoras = circuloPolar = espiral1 = espiral2 = false;

    factorEspiral1 = 16;
    thetaEspiral2 = 1.7;
    radioEspiral2 = 0.5;

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

    if(linea)
        graficos->lineaDDA(x1,y1,x2,y2,Canvas, color);
    else if(circuloPitagoras)
        graficos->circuloPitagoras(xc,yc,radio,Canvas);
    else if(circuloPolar)
        graficos->circuloPolar(xc, yc, radio, Canvas);
    else if(espiral1)
        graficos->espiral1(Canvas, color, factorEspiral1);
    else if(espiral2)
        graficos->espiral2(Canvas, color, thetaEspiral2, radioEspiral2);    


    // TAREA: UTILIZAR LA CLASE GRAFICOS PARA PROBAR EL FRACTAL DRAGON
    // ADEMAS DE LAS PRACTICAS ENCARGADAS EN CLASE


    Canvas->end();
}

void Dialog::mousePressEvent(QMouseEvent *event)
{
    ui->lineX1->setText(QString::number(event->pos().x()));
    ui->lineY1->setText(QString::number(event->pos().y()));
}

void Dialog::mouseReleaseEvent(QMouseEvent *event)
{
    ui->lineX2->setText(QString::number(event->pos().x()));
    ui->lineY2->setText(QString::number(event->pos().y()));

    on_pushButton_clicked();

    ui->spinBox->setValue(event->pos().x());
    ui->spinBox_2->setValue(event->pos().y());
    if(ui->lineX2->text().toInt() > ui->lineX1->text().toInt())
        ui->spinBox_3->setValue((ui->lineX2->text().toInt())-(ui->lineX1->text().toInt()));
    else if(ui->lineX1->text().toInt() > ui->lineX2->text().toInt())
        ui->spinBox_3->setValue((ui->lineX1->text().toInt())-(ui->lineX2->text().toInt()));

}

void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    ui->lineX2->setText(QString::number(event->pos().x()));
    ui->lineY2->setText(QString::number(event->pos().y()));

    on_pushButton_clicked();

    ui->spinBox->setValue(event->pos().x());
    ui->spinBox_2->setValue(event->pos().y());
    if(ui->lineX2->text().toInt() > ui->lineX1->text().toInt())
        ui->spinBox_3->setValue((ui->lineX2->text().toInt())-(ui->lineX1->text().toInt()));
    else if(ui->lineX1->text().toInt() > ui->lineX2->text().toInt())
        ui->spinBox_3->setValue((ui->lineX1->text().toInt())-(ui->lineX2->text().toInt()));

}

void Dialog::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
}


void Dialog::on_pushButton_clicked()
{
    x1 = ui->lineX1->text().toInt();
    y1 = ui->lineY1->text().toInt();
    x2 = ui->lineX2->text().toInt();
    y2 = ui->lineY2->text().toInt();

    //update();
    linea = true;
    circuloPitagoras = circuloPolar = espiral1 = espiral2 = false;

    this->repaint();
}


void Dialog::on_pushButton_2_clicked()
{
    QColor seleccionaColor = QColorDialog::getColor(Qt::white,this,"Selecciona un color");
    if(seleccionaColor.isValid())
        color= seleccionaColor;
}



//CIRCULO PITAGORAS
void Dialog::on_pushButton_3_clicked()
{
    xc = ui->spinBox->value();
    yc = ui->spinBox_2->value();
    radio = ui->spinBox_3->value();

    circuloPitagoras = true;
    linea = circuloPolar = espiral1 = espiral2 = false;
    update();
}


void Dialog::on_pushButton_4_clicked()
{
    xc = ui->spinBox->value();
    yc = ui->spinBox_2->value();
    radio = ui->spinBox_3->value();

    circuloPolar = true;
    circuloPitagoras = linea = espiral1 = espiral2 = false;
    update();
}


void Dialog::on_radioButton2_clicked()
{
    xc = ui->spinBox->value();
    yc = ui->spinBox_2->value();
    radio = ui->spinBox_3->value();

    circuloPolar = true;
    circuloPitagoras = linea = espiral1 = espiral2 = false;
    update();
}


void Dialog::on_radioButton1_clicked()
{
    xc = ui->spinBox->value();
    yc = ui->spinBox_2->value();
    radio = ui->spinBox_3->value();

    circuloPitagoras = true;
    linea = circuloPolar = espiral1 = espiral2 = false;
    update();
}

void Dialog::on_pushButton_5_clicked()
{
    espiral1 = true;
    circuloPitagoras = circuloPolar = linea = espiral2 = false;
    update();
}


void Dialog::on_radioButton3_clicked()
{
    espiral1 = true;
    circuloPitagoras = circuloPolar = linea = espiral2 = false;
    update();
}


void Dialog::on_doubleSpinBox_valueChanged(double arg1)
{
    factorEspiral1 = arg1;
    espiral1 = true;
    circuloPitagoras = circuloPolar = linea = espiral2 = false;
    update();
}


void Dialog::on_pushButton_6_clicked()
{
    espiral2 = true;
    circuloPitagoras = circuloPolar = espiral1 = linea = false;
    update();
}


void Dialog::on_doubleSpinBox_2_valueChanged(double arg1)
{
    thetaEspiral2 = arg1;
    espiral2 = true;
    circuloPitagoras = circuloPolar = espiral1 = linea = false;
    update();
}


void Dialog::on_doubleSpinBox_3_valueChanged(double arg1)
{
    radioEspiral2 = arg1;
    espiral2 = true;
    circuloPitagoras = circuloPolar = espiral1 = linea = false;
    update();
}

