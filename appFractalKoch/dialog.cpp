#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    band=1;
    li=0;
    ls=5;

    timerKoch= new QTimer();

    connect(timerKoch,SIGNAL(timeout()), this, SLOT(repaint()));
}

Dialog::~Dialog()
{
    delete ui;

}

void Dialog::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    int x=20;
    int y=this->height()/2;
    int l=this->width()-50;
    int angle=0;
    canvas = new QPainter(this);

    if(band /*==true*/){
        if(li<=ls){
            koch(x,y,l,angle,li,canvas);
            li++;
        }
        else
            band = false;
    }
    if(!band){
        li--;
        koch(x,y,l,angle,li,canvas);
        if(li == 0)
            band = true;
    }

    canvas->end();
}

void Dialog::k_curve(double x, double y, double lenght, double angle, int n_order, QPainter *canvas)
{

    if(n_order>0){
        lenght/=3;
        k_curve(x,y,lenght,angle,(n_order-1),canvas);
        x+=(lenght*cosl(angle*(M_PI/180)));
        y+=(lenght*sinl(angle*(M_PI/180)));

        k_curve(x,y,lenght,(angle-60),(n_order-1),canvas);
        x+=(lenght*cosl((angle-60)*(M_PI/180)));
        y+=(lenght*sinl((angle-60)*(M_PI/180)));

        k_curve(x,y,lenght,(angle+60),(n_order-1),canvas);
        x+=(lenght*cosl((angle+60)*(M_PI/180)));
        y+=(lenght*sinl((angle+60)*(M_PI/180)));

        k_curve(x,y,lenght,angle,(n_order-1), canvas);
    }
    else
        line1(x,y,(int)(x+lenght*cosl(angle*(M_PI/180))+0.5),(int)(y+lenght*sinl(angle*(M_PI/180))), canvas);
}

void Dialog::line1(int x_1, int y_1, int x_2, int y_2, QPainter *canvas)
{
    int x1=x_1;
    int y1=y_1;
    int x2=x_2;
    int y2=y_2;
    if(x_1>x_2){
        x1=x_2;
        y1=y_2;
        x2=x_1;
        y2=y_1;
    }
    int dx=abs(x2-x1);
    int dy=abs(y2-y1);
    int inc_dec((y2>=y1)?1:-1);
    if(dx>dy){
        int two_dy=(2*dy);
        int two_dy_dx=(2*(dy-dx));
        int p=((2*dy)-dx);
        int x=x1;
        int y=y1;
        canvas->setPen(color);
        canvas->drawPoint(x,y);
        while(x<x2){
            x++;
            if(p<0)
                p+=two_dy;
            else{
                y+=inc_dec;
                p+=two_dy_dx;
            }
            canvas->drawPoint(x,y);
        }
    }
    else{
        int two_dx=(2*dx);
        int two_dx_dy=(2*(dx-dy));
        int p=((2*dx)-dy);
        int x=x1;
        int y=y1;
        canvas->drawPoint(x,y);
        while(y!=y2){
            y+=inc_dec;
            if(p<0)
                p+=two_dx;
            else{
                x++;
                p+=two_dx_dy;
            }
            canvas->drawPoint(x,y);
        }
    }

}

void Dialog::koch(int x, int y, int l, int angle, int n, QPainter *canvas)
{
    k_curve(x,y,l,angle,n, canvas);

}


void Dialog::on_pushButton_3_clicked()
{
    QColor seleccionaColor = QColorDialog::getColor(Qt::white,this,"Selecciona un color");
    if(seleccionaColor.isValid())
        color= seleccionaColor;
}


void Dialog::on_pushButton_2_clicked()
{
    timerKoch->start(100);
}


void Dialog::on_pushButton_clicked()
{
    timerKoch->stop();
}

