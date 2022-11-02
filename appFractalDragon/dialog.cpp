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
            timerDragon->start(50);
            update();
        }
        if(evento->key() == Qt::Key_D){
            timerDragon->stop();
        }
    }
    if(ui->comboBox->currentIndex() == 1){
        if(evento->key() == Qt::Key_I){
            band = true;
            timerArabesco->start(50);
            update();
        }
        if(evento->key() == Qt::Key_D){
            timerArabesco->stop();
        }
    }

}

void Dialog::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    //dragon(); Este metodo se llamara de acuerdo al valor de band y los limites
    QPainter *canvas = new QPainter(this);

    if(ui->comboBox->currentIndex() == 0){
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
    else{
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


    QFont fuenteTexto = canvas->font();
    fuenteTexto.setPointSize(fuenteTexto.pointSize() * 2);
    canvas->setFont(fuenteTexto);
    canvas->drawText(5,25,"CURVA FRACTAL DEL DRAGON");
    //Mostrar los datos guardados en los arreglos
    pen = QColor(QRandomGenerator::global()->bounded(100)+155, 0, QRandomGenerator::global()->bounded(100)+155);
    canvas->setPen(pen);

    //Para utilizar la lineaDDA
    //Graficos *graficos = new Graficos();
    //graficos->lineaDDA(ejeX[1], ejeY[1], ejeX[4097], ejeY[4097], canvas,QColor(255,0,200));

    grafico->lineaDDA(ejeX[1], ejeY[1], ejeX[4097], ejeY[4097], canvas,color);
    //canvas->drawLine(ejeX[1], ejeY[1], ejeX[4097], ejeY[4097]);


    //Sleep(100);

    QString datos = "x1 = "+QString::number(ejeX[1]);
    datos += " y1 = "+QString::number(ejeY[1])+ " x2 = "+QString::number(ejeX[4097]) + " y2 = "+QString::number(ejeY[4097]);
    canvas->drawText(5,50,datos);

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


    QFont fuenteTexto = canvas->font();
    fuenteTexto.setPointSize(fuenteTexto.pointSize() * 2);
    canvas->setFont(fuenteTexto);
    canvas->drawText(5,25,"CURVA FRACTAL DEL DRAGON");
    //Mostrar los datos guardados en los arreglos
    pen = QColor(QRandomGenerator::global()->bounded(100)+155, 0, QRandomGenerator::global()->bounded(100)+155);
    canvas->setPen(pen);

    //Para utilizar la lineaDDA
    //Graficos *graficos = new Graficos();
    //graficos->lineaDDA(ejeX[1], ejeY[1], ejeX[4097], ejeY[4097], canvas,QColor(255,0,200));

    grafico->lineaDDA(ejeX[1], ejeY[1], ejeX[4097], ejeY[4097], canvas,color);
    //canvas->drawLine(ejeX[1], ejeY[1], ejeX[4097], ejeY[4097]);


    //Sleep(100);

    QString datos = "x1 = "+QString::number(ejeX[1]);
    datos += " y1 = "+QString::number(ejeY[1])+ " x2 = "+QString::number(ejeX[4097]) + " y2 = "+QString::number(ejeY[4097]);
    canvas->drawText(5,50,datos);

    for(i = 1; i<=limite; i++){
        generarArabesco(canvas);
        paso /=2;
    }
}
/*
void Dialog::extranioCodificador()
{
    int i, j, k, l, contador, x, y;
    double pobAnt, pobNueva, razon;
    pobNueva = 0.0;
    razon = 2.3;
    pen = QColor(240,0,240);
    QPainter *can = new QPainter(this);
    can->setPen(pen);

    for(j=1; j<=151; j++){
        contador = 0;
        razon +=0.01;
        pobAnt = 0.01;
        for(i=1; i<=this->width(); i++){
            pobNueva = razon * (pobAnt * (1-pobAnt));
            x= pobAnt * this->width();
            y= this->height() - (pobNueva * this->height());
            can->drawPoint(this->width(),this->height());

            if(pobAnt == pobNueva)
                contador++;
            else
                contador=0;
            if(contador>10)
                i=this->width();
            pobAnt = pobNueva;

        }

    }
}*/

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



void Dialog::on_pushButton_2_clicked()
{
    /*
    timerDragon->start(50);
    this->repaint();
    */
    if(ui->comboBox->currentIndex() == 0){
        timerDragon->start(50);
        this->repaint();
    }
    if(ui->comboBox->currentIndex() == 1){
        timerArabesco->start(50);
        this->repaint();
    }
}

void Dialog::on_pushButton_clicked()
{
    timerDragon->stop();
    timerArabesco->stop();

}


void Dialog::on_pushButton_3_clicked()
{
    QColor seleccionaColor = QColorDialog::getColor(Qt::white,this,"Selecciona un color");
    if(seleccionaColor.isValid())
        color= seleccionaColor;
}



