#include "dialog.h"
#include "ui_dialog.h"
#include <string>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    timer1 = new QTimer();
    timer2 = new QTimer();
    timer3 = new QTimer();
    timer4 = new QTimer();//mover pez

    connect(timer1,SIGNAL(timeout()),this, SLOT(moverEtiquetaH()));
    connect(timer2,SIGNAL(timeout()),this, SLOT(moverEtiquetaV()));
    connect(timer3,SIGNAL(timeout()),this, SLOT(moverEtiqueta2()));
    connect(timer4,SIGNAL(timeout()),this, SLOT(moverPez()));//mover pez
}

Dialog::~Dialog()
{
    delete ui;
}

//Boton Mover


void Dialog::moverEtiquetaH()
{
    //Las variables static permiten mantener el valor de la variable
    //en suscesivas llamadas del metodo

    QString texto = ui->label->text(); // o usar el texto del lineText

    std::string textoInvertido = texto.toStdString();


    static int x = 0;
    static bool band = true;

    int y = ui->label->geometry().y();

    //if(ui->label->geometry().x() < this->width() - (ui->label->width() - 5) && band){
    //Dibujando dentro del objeto widget
    if(ui->label->geometry().x() < ui->widget->width() - (ui->label->width()) && band){
        ui->label->setGeometry(x,y, ui->label->width(),ui->label->height());
        x+=5;
        //if(ui->label->geometry().x() > this->width() - (ui->label->width() - 5)){
        if(ui->label->geometry().x() >= ui->widget->width() - (ui->label->width())){
            //Inicia el Regreso
            band = false;
            //metodo para invertir una cadena : hola -> aloh

            reverse(textoInvertido.begin(), textoInvertido.end());
            //regresamos a tipo QString el objeto String
            ui->label->setText(QString::fromStdString(textoInvertido));
            //Giramos la imagen


        }

    }
    if(!band){
        x-=5;
        ui->label->setGeometry(x,y, ui->label->width(),ui->label->height());
        if(x == 0){
            //Inicia el Regreso
            band = true;

            reverse(textoInvertido.begin(), textoInvertido.end());
            ui->label->setText(QString::fromStdString(textoInvertido));
        }
    }
}

void Dialog::moverEtiquetaV()
{
    static int y = 0;
    static bool band = true;

    int x = (ui->widget->width() - ui->label->width()) / 2;

    //ui->label->setGeometry(x,y,ui->label->width(), ui->label->height());

    if (ui->label->geometry().y() < (ui->widget->height() - (ui->label->height())) && band){/* ui->pushButton_5->geometry().y()*/
        ui->label->setGeometry(x,y,ui->label->width(),ui->label->height());
        y+=10;
        //Para iniciar el regreso de la etiqueta
        //int pos = ui->label->geometry().y();
        if(ui->label->geometry().y() >= (ui->widget->height())-(ui->label->height()+100))
            band = false;        
    }

    if(!band){
        y-=10;
        ui->label->setGeometry(x,y,ui->label->width(), ui->label->height());
        if(y == 0)
            band = true;
    }
}

void Dialog::moverEtiqueta2()
{
    //Las variables static permiten mantener el valor de la variable
    //en suscesivas llamadas del metodo

    QString texto = ui->label->text(); // o usar el texto del lineText

    std::string textoInvertido = texto.toStdString();


    static int x = 0;
    static bool band = true;

    int y = ui->label->geometry().y();

    //if(ui->label->geometry().x() < this->width() - (ui->label->width() - 5) && band){
    //Dibujando dentro del objeto widget
    if(ui->label_5->geometry().x() < ui->frame->width() - (ui->label_5->width()) && band){
        ui->label_5->setGeometry(x,y, ui->label_5->width(),ui->label_5->height());
        x+=5;
        //if(ui->label->geometry().x() > this->width() - (ui->label->width() - 5)){
        if(ui->label_5->geometry().x() >= (ui->frame->width() - (ui->label_5->width())-5)){
            //Inicia el Regreso
            band = false;
            //metodo para invertir una cadena : hola -> aloh

            reverse(textoInvertido.begin(), textoInvertido.end());
            //regresamos a tipo QString el objeto String
            ui->label_5->setText(QString::fromStdString(textoInvertido));
            //Giramos la imagen

            ui->label_5->setText(QTime::currentTime().toString("hh:mm:ss"));

        }

    }
    if(!band){
        x-=5;
        ui->label_5->setGeometry(x,y, ui->label_5->width(),ui->label_5->height());
        if(x == 0){
            //Inicia el Regreso
            band = true;

            reverse(textoInvertido.begin(), textoInvertido.end());
            //ui->label_5->setText(QString::fromStdString(textoInvertido));
        }
    }
}




/*
void Dialog::moverEtiquetaV2()
{

        static int y = 0;
        static bool band = true;
        int x = (this->width() - ui->label->width())/2;
    // SE MUEVE HACIA ABAJO  V
        //if(ui->label->geometry().y() < this->height() - (ui->label->height()) && band)
        if(ui->label->geometry().y() < (this->height() -(ui->label->height()+100))  && band)
        {
            ui->label->setGeometry(x,y,ui->label->width(),ui->label->height());
            y+= 10;
            if(ui->label->geometry().y() >= (this->height() - (ui->label->height()+100)) )
                band = false;
        }
        if(!band)
        {
            y-= 10;
            ui->label->setGeometry(x,y,ui->label->width(),ui->label->height());
            if (y == 0)
                band = true;

        }

}

*/

void Dialog::on_pushButton_2_clicked()
{
    timer1->stop();
    timer2->stop();
    timer3->stop();
}


void Dialog::on_pushButton_3_clicked()
{
    this->close();
}


void Dialog::on_pushButton_4_clicked()
{
    ui->label->setText(ui->lineEdit->text());
    ui->label->adjustSize();
}

int velocidad;

void Dialog::on_horizontalSlider_valueChanged()
{
    velocidad = ui->horizontalSlider->value();

    //on_pushButton_clicked();
    //on_pushButton_5_clicked();
    //timer1->start(ui->horizontalSlider->value());
    //ui->label_3->setText(QString::number(ui->horizontalSlider->value()));
    ui->label_3->setText(QString::number(velocidad));
    ui->label_3->adjustSize();
}


void Dialog::on_dial_valueChanged()
{
    velocidad = ui->dial->value();
    //on_pushButton_clicked();
    //timer1->start(ui->horizontalSlider->value());
    //ui->label_3->setText(QString::number(ui->horizontalSlider->value()));
    ui->label_4->setText(QString::number(velocidad));
    ui->label_4->adjustSize();
}


void Dialog::on_spinBox_valueChanged()
{
    velocidad = ui->spinBox->value();
    //on_pushButton_clicked();
    //timer1->start(ui->horizontalSlider->value());
    //ui->label_3->setText(QString::number(ui->horizontalSlider->value()));
}

void Dialog::on_pushButton_clicked()
{
    timer1->start(velocidad);
    timer3->start(velocidad);
    //timer2->stop();
}


void Dialog::on_pushButton_5_clicked()
{
    timer2->start(velocidad);
    //timer1->stop();
}


void Dialog::on_pushButton_6_clicked()
{
    timer1->stop();
    timer2->stop();
    on_pushButton_clicked();
    on_pushButton_5_clicked();
}

void Dialog::moverPez()
{
    static int x = 0;
    int y = 0;
    static bool band = true;

    //background-image: url(:/imgs/pecera.png);

    ui->label_Pez->setStyleSheet("background-image: url(:/imgs/pez3.png)");
    //ui.label_Pez.ajustSize();

    //if(ui->label->geometry().x() < this->width() - (ui->label->width() - 5) && band){
    //Dibujando dentro del objeto widget
    if(ui->label_Pez->geometry().x() < ui->widget_2->geometry().width() - (ui->label_Pez->geometry().width()) && band){
        ui->label_Pez->setGeometry(x,y, ui->label_Pez->width(),ui->label_Pez->height());
        x+=5;
        //if(ui->label->geometry().x() > this->width() - (ui->label->width() - 5)){
        if(ui->label_Pez->geometry().x() >= ui->widget_2->geometry().width()- (ui->label_Pez->width())){
            //Inicia el Regreso
            ui->label_Pez->setStyleSheet("background-image: url(:/imgs/pez4.png)");
            band = false;
            //metodo para invertir una cadena : hola -> aloh
        }

    }
    if(!band){
        ui->label_Pez->setStyleSheet("background-image: url(:/imgs/pez4.png)");
        x-=5;
        ui->label_Pez->setGeometry(x,y, ui->label_Pez->width(),ui->label_Pez->height());
        if(x == 0){
            //Inicia el Regreso
            band = true;
            ui->label_Pez->setStyleSheet("background-image: url(:/imgs/pez3.png)");
        }
    }
}


void Dialog::on_MoverPez_clicked()
{
    timer4->start(30);
}


void Dialog::on_DetenerPez_clicked()
{
    timer4->stop();
}

