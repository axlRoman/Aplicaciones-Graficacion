#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    li =0;
    ls = 12;
    band = 1; // true = 1 // false = 0
    timerDragon = new QTimer();
    connect(timerDragon,SIGNAL(timeout()), this, SLOT(repaint()));

    timerArabesco = new QTimer();
    connect(timerArabesco,SIGNAL(timeout()), this, SLOT(repaint()));

    grafico = new Graficos();

    //Koch
    lik=0;
    lsk=5;
    timerKoch= new QTimer();
    connect(timerKoch,SIGNAL(timeout()), this, SLOT(repaint()));
    //Sierpinski
    ns=0;
    timerSierpinski = new QTimer();
    connect(timerSierpinski,SIGNAL(timeout()), this, SLOT(repaint()));
    //Malthus
    lim=0;
    lsm=15;
    timerMalthus = new QTimer();
    connect(timerMalthus,SIGNAL(timeout()), this, SLOT(repaint()));

    //QColor color;
}

Dialog::~Dialog()
{
    delete ui; 

}

void Dialog::keyPressEvent(QKeyEvent *evento)
{

    if(ui->comboBox->currentIndex() == 0){
        if(evento->key() == Qt::Key_I){
            band = true;
            timerDragon->start(100);
            update();
        }
        if(evento->key() == Qt::Key_D){
            timerDragon->stop();
        }
    }
    if(ui->comboBox->currentIndex() == 1){
        if(evento->key() == Qt::Key_I){
            band = true;
            timerArabesco->start(100);
            update();
        }
        if(evento->key() == Qt::Key_D){
            timerArabesco->stop();
        }
    }
    if(ui->comboBox->currentIndex() == 2){
        if(evento->key() == Qt::Key_I){
            band = true;
            timerKoch->start(100);
            update();
        }
        if(evento->key() == Qt::Key_D){
            timerKoch->stop();
        }
    }
    if(ui->comboBox->currentIndex() == 3){
        if(evento->key() == Qt::Key_I){
            band = true;
            timerSierpinski->start(100);
            update();
        }
        if(evento->key() == Qt::Key_D){
            timerSierpinski->stop();
        }
    }
    if(ui->comboBox->currentIndex() == 4){
        if(evento->key() == Qt::Key_I){
            band = true;
            timerMalthus->start(100);
            update();
        }
        if(evento->key() == Qt::Key_D){
            timerMalthus->stop();
        }
    }

}

void Dialog::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    //dragon(); Este metodo se llamara de acuerdo al valor de band y los limites
    QPainter *canvas = new QPainter(this);

    //Fractal Dragon
    if(ui->comboBox->currentIndex() == 0){
        QFont fuenteTexto = canvas->font();
        fuenteTexto.setPointSize(fuenteTexto.pointSize() * 2);
        canvas->setFont(fuenteTexto);
        canvas->drawText(5,25,"CURVA FRACTAL DEL DRAGON");

        if(band /*==true*/){
            if(li<=ls){
                dragon(li, canvas);
                li++;
            }
            else
                band = false;
        }
        if(!band){
            li--;
            dragon(li, canvas);
            if(li == 0)
                band = true;
        }
    }
    //Fractal Arabesco
    if(ui->comboBox->currentIndex() == 1){
        QFont fuenteTexto = canvas->font();
        fuenteTexto.setPointSize(fuenteTexto.pointSize() * 2);
        canvas->setFont(fuenteTexto);
        canvas->drawText(5,25,"CURVA FRACTAL DEL ARABESCO");
        if(band /*==true*/){
            if(li<=ls){
                arabesco(li, canvas);
                li++;
            }
            else
                band = false;
        }
        if(!band){
            li--;
            arabesco(li, canvas);
            if(li == 0)
                band = true;
        }
    }
    //Fractal Curva de Koch
    int xKoch=20;
    int yKoch=this->height()-200;
    int lKoch=this->width()-50;
    int angleKoch=0;
    if(ui->comboBox->currentIndex() == 2){
        QFont fuenteTexto = canvas->font();
        fuenteTexto.setPointSize(fuenteTexto.pointSize() * 2);
        canvas->setFont(fuenteTexto);
        canvas->drawText(5,25,"Fractal Curva de Koch");
        if(band /*==true*/){
            if(lik<=lsk){
                koch(xKoch,yKoch,lKoch,angleKoch,lik,canvas);
                lik++;
            }
            else
                band = false;
        }
        if(!band){
            lik--;
            koch(xKoch,yKoch,lKoch,angleKoch,lik,canvas);
            if(lik == 0)
                band = true;
        }
    }
    //Fractal Sierpinski
    if(ui->comboBox->currentIndex() == 3){
        QFont fuenteTexto = canvas->font();
        fuenteTexto.setPointSize(fuenteTexto.pointSize() * 2);
        canvas->setFont(fuenteTexto);
        canvas->drawText(5,25,"Fractal Sierpinski");


        if(band){
            if(ns<=7){
                sierpinski(ns,canvas);
                Sleep(200);
                ns++;
            }
            else
                band = false;
        }
        if(!band){
            ns--;
            sierpinski(ns,canvas);
            Sleep(200);
            if(ns == 0)
                band = true;
        }
    }
    //Fractal Malthus
    if(ui->comboBox->currentIndex() == 4){
        QFont fuenteTexto = canvas->font();
        fuenteTexto.setPointSize(fuenteTexto.pointSize() * 2);
        canvas->setFont(fuenteTexto);
        canvas->drawText(5,25,"Fractal Malthus");


        if(band){
            if(lim<=lsm){
                malthus(lim,canvas);
                lim++;
            }
            else
                band = false;
        }
        if(!band){
            lim--;
            malthus(lim,canvas);
            if(lim == 0)
                band = true;
        }
    }



    canvas->end(); //Destruir o finalizar el *canvas
}
QPen pen;

void Dialog::dragon(int limite, QPainter *canvas) //REPRESENTA A LA FUNCION MAIN()
{
    //TECLEAR EL CODIGO DE LAS COPIAS, ANALIZANDOLO
    int i;
    //QPainter canvas(this);
    //pen.setWidth(15);
    //pen = (QColor(250,0,255));
    //canvas->setPen(color);

    paso = 4096;
    //signo = 1;
    signo = -1;

    ejeX[1] =  canvas->window().width() / 4;
    ejeX[4097] = 3 * canvas->window().width() / 4;
    ejeY[1] = ejeY[4097] = 2 * canvas->window().height() / 3;


    //Mostrar los datos guardados en los arreglos
    /*
    pen = QColor(QRandomGenerator::global()->bounded(100)+155, 0, QRandomGenerator::global()->bounded(100)+155);
    canvas->setPen(pen);
*/
    //Para utilizar la lineaDDA
    //Graficos *graficos = new Graficos();
    //graficos->lineaDDA(ejeX[1], ejeY[1], ejeX[4097], ejeY[4097], canvas,QColor(255,0,200));

    grafico->lineaDDA(ejeX[1], ejeY[1], ejeX[4097], ejeY[4097], canvas,color);
    //canvas->drawLine(ejeX[1], ejeY[1], ejeX[4097], ejeY[4097]);


    //Sleep(100);
/*
    QString datos = "x1 = "+QString::number(ejeX[1]);
    datos += " y1 = "+QString::number(ejeY[1])+ " x2 = "+QString::number(ejeX[4097]) + " y2 = "+QString::number(ejeY[4097]);
    canvas->drawText(5,50,datos);
*/
    for(i = 1; i<=limite; i++){
        generarDragon(canvas);
        paso /=2;
    }
}

void Dialog::arabesco(int limite, QPainter *canvas)
{
    //TECLEAR EL CODIGO DE LAS COPIAS, ANALIZANDOLO
    int i;
    //QPainter canvas(this);
    pen.setWidth(15);
    pen = (QColor(250,0,255));
    canvas->setPen(pen);

    paso = 4096;
    signo = 1;
    //signo = -1;

    ejeX[1] =  canvas->window().width() / 4;
    ejeX[4097] = 3 * canvas->window().width() / 4;
    ejeY[1] = ejeY[4097] = 2 * canvas->window().height() / 3;
/*

    QFont fuenteTexto = canvas->font();
    fuenteTexto.setPointSize(fuenteTexto.pointSize() * 2);
    canvas->setFont(fuenteTexto);
    canvas->drawText(5,25,"CURVA FRACTAL DEL DRAGON");
    //Mostrar los datos guardados en los arreglos
    pen = QColor(QRandomGenerator::global()->bounded(100)+155, 0, QRandomGenerator::global()->bounded(100)+155);
    canvas->setPen(pen);
*/
    //Para utilizar la lineaDDA
    //Graficos *graficos = new Graficos();
    //graficos->lineaDDA(ejeX[1], ejeY[1], ejeX[4097], ejeY[4097], canvas,QColor(255,0,200));

    grafico->lineaDDA(ejeX[1], ejeY[1], ejeX[4097], ejeY[4097], canvas,color);
    //canvas->drawLine(ejeX[1], ejeY[1], ejeX[4097], ejeY[4097]);


    //Sleep(100);
/*
    QString datos = "x1 = "+QString::number(ejeX[1]);
    datos += " y1 = "+QString::number(ejeY[1])+ " x2 = "+QString::number(ejeX[4097]) + " y2 = "+QString::number(ejeY[4097]);
    canvas->drawText(5,50,datos);
*/
    for(i = 1; i<=limite; i++){
        generarArabesco(canvas);
        paso /=2;
    }
}

/*void Dialog::dragon() //REPRESENTA A LA FUNCION MAIN()
{
    //TECLEAR EL CODIGO DE LAS COPIAS, ANALIZANDOLO
    int i;
    QPainter canvas(this);
    pen.setWidth(15);
    pen = (QColor(250,0,255));
    canvas.setPen(pen);

    paso = 4096;
    //signo = 1;
    signo = -1;
    ejeX[1] =  this->width() / 4;
    ejeX[4097] = 3 * this->width() / 4;
    ejeY[1] = ejeY[4097] = 2 * this->height() / 3;
*/
/*
      ejeX[1] =  canvas.window().width() / 4;
      ejeX[4097] = 3 * canvas.window().width() / 4;
      ejeY[1] = ejeY[4097] = 2 * canvas.window().height() / 3;


    QFont fuenteTexto = canvas.font();
    fuenteTexto.setPointSize(fuenteTexto.pointSize() * 2);
    canvas.setFont(fuenteTexto);
    //canvas.setFont(QFont("ROCKWELL",22));
    canvas.drawText(5,25,"CURVA FRACTAL DEL DRAGON");
    //Mostrar los datos guardados en los arreglos
    pen = QColor(0, QRandomGenerator::global()->bounded(100)+155, QRandomGenerator::global()->bounded(100)+155);
    canvas.setPen(pen);
    canvas.setFont(QFont("ARIAL",12));
    QString datos = "x1 = "+QString::number(ejeX[1]);
    datos += " y1 = "+QString::number(ejeY[1])+ " x2 = "+QString::number(ejeX[4097]) + " y2 = "+QString::number(ejeY[4097]);
    canvas.drawText(5,50,datos);

    canvas.drawLine(ejeX[1], ejeY[1], ejeX[4097], ejeY[4097]);
    //Sleep(100);
    for(i = 1; i<=13; i++){
        //pen = QColor(240,240,240);
        generarDragon(&canvas);
        paso /=2;
        if(i==11){
            pen = QColor(QRandomGenerator::global()->bounded(100)+155, 0, QRandomGenerator::global()->bounded(100)+155);
            generarDragon(&canvas);
            paso /=2;
        }

      //  Sleep(100);
    }
}*/

void Dialog::generarDragon(QPainter *canvas)
{
    int i, j, dx, dy;
    j = paso / 2;
    //Graficos *graficos = new Graficos();
    //QColor color = QColor(QRandomGenerator::global()->bounded(255), 0 , QRandomGenerator::global()->bounded(255));
    canvas->setPen(pen);
    for(i = 1; i<= 4096; i+=paso){
        dx = ejeX[paso + i] - ejeX[i];
        dy = ejeY[paso + i] - ejeY[i];
        signo *= -1; //SE GENERA EL FRACTAL DRAGON
        //signo *= 1; //SE GENERA EL FRACTAL ARABESCO
        ejeX[i + j] = ejeX[i] + (dx + (dy * signo)) / 2;
        ejeY[i + j] = ejeY[i] + (dy - (dx * signo)) / 2;       

        //Utilizando lineaDDA
        //graficos->lineaDDA(ejeX[i], ejeY[i], ejeX[i + j], ejeY[i + j],canvas,color);

        grafico->lineaDDA(ejeX[i], ejeY[i], ejeX[i + j], ejeY[i + j],canvas,color);
        //canvas->drawLine(ejeX[i], ejeY[i], ejeX[i + j], ejeY[i + j]);

/*      int posy = 70;
        QString datos = "x1 = "+QString::number(ejeX[i]);
        datos += " y1 = "+QString::number(ejeY[i])+ " x2 = "+QString::number(ejeX[i + j]) + " y2 = "+QString::number(ejeY[i+ j]);
        canvas->drawText(5,posy,datos);
*/
        //Utilizando LineaDDA
        //graficos->lineaDDA(ejeX[i + j], ejeY[i + j], ejeX[i + paso], ejeY[i + paso],canvas,color);

        grafico->lineaDDA(ejeX[i + j], ejeY[i + j], ejeX[i + paso], ejeY[i + paso],canvas,color);
        //canvas->drawLine(ejeX[i + j], ejeY[i + j], ejeX[i + paso], ejeY[i + paso]);
/*        posy = 90;
        QString datos3 = "x1 = "+QString::number(ejeX[i+j]);
        datos3 += " y1 = "+QString::number(ejeY[i+j])+ " x2 = "+QString::number(ejeX[i + paso]) + " y2 = "+QString::number(ejeY[i+ paso]);
        canvas->drawText(5,posy,datos3);
*/
    }
}

void Dialog::generarArabesco(QPainter *canvas)
{
    int i, j, dx, dy;
    j = paso / 2;
    //Graficos *graficos = new Graficos();
    //QColor color = QColor(QRandomGenerator::global()->bounded(255), 0 , QRandomGenerator::global()->bounded(255));
    canvas->setPen(pen);
    for(i = 1; i<= 4096; i+=paso){
        dx = ejeX[paso + i] - ejeX[i];
        dy = ejeY[paso + i] - ejeY[i];
        //signo *= -1; //SE GENERA EL FRACTAL DRAGON
        signo *= 1; //SE GENERA EL FRACTAL ARABESCO
        ejeX[i + j] = ejeX[i] + (dx + (dy * signo)) / 2;
        ejeY[i + j] = ejeY[i] + (dy - (dx * signo)) / 2;

        //Utilizando lineaDDA
        //graficos->lineaDDA(ejeX[i], ejeY[i], ejeX[i + j], ejeY[i + j],canvas,color);

        grafico->lineaDDA(ejeX[i], ejeY[i], ejeX[i + j], ejeY[i + j],canvas,color);
        //canvas->drawLine(ejeX[i], ejeY[i], ejeX[i + j], ejeY[i + j]);

/*      int posy = 70;
        QString datos = "x1 = "+QString::number(ejeX[i]);
        datos += " y1 = "+QString::number(ejeY[i])+ " x2 = "+QString::number(ejeX[i + j]) + " y2 = "+QString::number(ejeY[i+ j]);
        canvas->drawText(5,posy,datos);
*/
        //Utilizando LineaDDA
        //graficos->lineaDDA(ejeX[i + j], ejeY[i + j], ejeX[i + paso], ejeY[i + paso],canvas,color);

        grafico->lineaDDA(ejeX[i + j], ejeY[i + j], ejeX[i + paso], ejeY[i + paso],canvas,color);
        //canvas->drawLine(ejeX[i + j], ejeY[i + j], ejeX[i + paso], ejeY[i + paso]);
/*        posy = 90;
        QString datos3 = "x1 = "+QString::number(ejeX[i+j]);
        datos3 += " y1 = "+QString::number(ejeY[i+j])+ " x2 = "+QString::number(ejeX[i + paso]) + " y2 = "+QString::number(ejeY[i+ paso]);
        canvas->drawText(5,posy,datos3);
*/
    }
}

//NOTA: ANALIZAR EL CODIGO Y SUBIR CAPTURA DE QUE YA SE REALIZO
// DE SER POSIBLE ENCONTRAR EL ERROR QUE PRESENTA EN EL CÓDIGO



/*
void Dialog::paintEvent(QPaintEvent *evento)
{
        Q_UNUSED(evento)

    ejeX[1] =  this->width() / 4;
    ejeX[497] = 3 * this->width() / 4;
    ejeY[1] = ejeY[497] = 2 * this->height() / 3;

        QPainter canvas(this);
        //QPen pen1=(QColor(255,0,0));//((rand() % 155 + 100),0,0));
        for(int i = 0; i < 200; i++){
            QPen pen1=(QColor(0,0,0));
            pen1.setWidth(3);
            canvas.setPen(pen1);
            canvas.drawLine(ejeX[1], ejeY[1], ejeX[497], ejeY[497]);
        }
}
*/

//Funciones para generar la curva de Koch
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
//Fin de las funciones de Koch

//Funciones para el fractal de sierpinski
void Dialog::sierpinski(int n, QPainter *canvas)
{
    canvas->setPen(color);
    dibujaTriangulo(10, this->height() - 150, this->width() - 10, this->height() - 150, this->width() / 2, 10, canvas, n);
}

void Dialog::dibujaTriangulo(float x1, float y1, float x2, float y2, float x3, float y3, QPainter *canvas, int n)
{
    canvas->drawLine(int(x1), int(y1), int(x2), int(y2));
    canvas->drawLine(int(x1), int(y1), int(x3), int(y3));
    canvas->drawLine(int(x2), int(y2), int(x3), int(y3));

    subTriangulo(
          n , //This represents the first recursion
          (x1 + x2) / 2, //x coordinate of first corner
          (y1 + y2) / 2, //y coordinate of first corner
          (x1 + x3) / 2, //x coordinate of second corner
          (y1 + y3) / 2, //y coordinate of second corner
          (x2 + x3) / 2, //x coordinate of third corner
          (y2 + y3) / 2,  //y coordinate of third corner
          canvas
        );


}

void Dialog::subTriangulo(int n, float x1, float y1, float x2, float y2, float x3, float y3, QPainter *canvas)
{
    //QColor color = QColor(0,0,0);


      if(n < 7)
      {
        subTriangulo
        (
          n+1,
          (x1 + x2) / 2 + (x2 - x3) / 2,
          (y1 + y2) / 2 + (y2 - y3) / 2,
          (x1 + x2) / 2 + (x1 - x3) / 2,
          (y1 + y2) / 2 + (y1 - y3) / 2,
          (x1 + x2) / 2,
          (y1 + y2) / 2, canvas
        );
        //Smaller triangle 2
        subTriangulo
        (
          n+1,
          (x3 + x2) / 2 + (x2 - x1) / 2,
          (y3 + y2) / 2 + (y2 - y1) / 2,
          (x3 + x2) / 2 + (x3 - x1) / 2,
          (y3 + y2) / 2 + (y3 - y1) / 2,
          (x3 + x2) / 2,
          (y3 + y2) / 2, canvas
        );
        //Smaller triangle 3
        subTriangulo
        (
          n+1,
          (x1 + x3) / 2 + (x3 - x2) / 2,
          (y1 + y3) / 2 + (y3 - y2) / 2,
          (x1 + x3) / 2 + (x1 - x2) / 2,
          (y1 + y3) / 2 + (y1 - y2) / 2,
          (x1 + x3) / 2,
          (y1 + y3) / 2, canvas
        );
        canvas->drawLine(int(x1), int(y1), int(x2), int(y2));
        canvas->drawLine(int(x1), int(y1), int(x3), int(y3));
        canvas->drawLine(int(x2), int(y2), int(x3), int(y3));
      }
}
//Fin de las funciones de sierpinski
//Funcion para el fractal de Malthus
void Dialog::malthus(int li, QPainter *canvas)
{
    pobAnt = pobNueva = 0.0;
    razon = 2.3;
    y=0;

    for(j = 1; j <= li; j++){
        for(k = 1; k <=li; k++){
            contador = 0;
            razon = razon + 0.01;
            pobAnt = 0.01;
            for(i = 1; i <= 1000; i++){
                pobNueva = razon * (pobAnt *(1-pobAnt));
                x = pobNueva - pobAnt;
                canvas->drawPoint((x * this->width() / 2) + (this->width()/2)+50, (this->height()/2) - (y*this->height()/2)-100);
                if(pobAnt == pobNueva)
                    contador++;
                else
                    contador = 0;
                if(contador>100)
                    i=1000;
                pobAnt = pobNueva;
                y=x;
            }
        }
    }
}
//Fin de Fractal de Malthus

void Dialog::on_pushButton_2_clicked()
{
    /*
    timerDragon->start(50);
    this->repaint();
    */
    if(ui->comboBox->currentIndex() == 0){
        timerDragon->start(100);
        this->repaint();
    }
    if(ui->comboBox->currentIndex() == 1){
        timerArabesco->start(100);
        this->repaint();
    }
    if(ui->comboBox->currentIndex() == 2){
        timerKoch->start(100);
        this->repaint();
    }
    if(ui->comboBox->currentIndex() == 3){
        timerSierpinski->start(100);
        this->repaint();
    }
    if(ui->comboBox->currentIndex() == 4){
        timerMalthus->start(100);
        this->repaint();
    }
}




void Dialog::on_pushButton_clicked()
{
    timerDragon->stop();
    timerArabesco->stop();
    timerKoch->stop();
    timerSierpinski->stop();
    timerMalthus->stop();
}


void Dialog::on_pushButton_3_clicked()
{
    QColor seleccionaColor = QColorDialog::getColor(Qt::white,this,"Selecciona un color");
    if(seleccionaColor.isValid())
        color= seleccionaColor;
}



