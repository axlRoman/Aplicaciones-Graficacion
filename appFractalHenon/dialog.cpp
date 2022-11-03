#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    band=1;
    li=0;
    ls=20000;
    timerHenon = new QTimer();
    connect(timerHenon,SIGNAL(timeout()), this, SLOT(repaint()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *e)
{
    QPainter *canvas = new QPainter(this);
    Q_UNUSED(e);

            henon(canvas);


    canvas->end();
}

void Dialog::henon(QPainter *canvas)
{
    escalaX =1;
    escalaY =1;
    despX=0;
    despY=0;
    int i, posX, posY;
    double xAnt, xNuevo, yAnt, yNuevo;

    xAnt = xNuevo = yAnt = yNuevo = 0;
    for(i=1; i<= 20000; i++){
        xNuevo = yAnt + 1 - (1.4 * xAnt * xAnt);
        yNuevo = 0.3 * xAnt;
        posX = (xNuevo * this->width()/3 * escalaX) + this->width()/2 + despX;
        posY = (yNuevo * this->height() * escalaY) + this->height()/2 + despY;

        if((posX >= 0) && (posX <= this->width()) &&
                (posY >= 0) && (posY <= this->height()))
            canvas->drawPoint(posX,posY);
        yAnt = yNuevo;
        xAnt = xNuevo;
    }

}


