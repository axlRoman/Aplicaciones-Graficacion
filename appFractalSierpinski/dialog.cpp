#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    timerSierpinski = new QTimer();
    connect(timerSierpinski,SIGNAL(timeout()), this, SLOT(repaint()));
}

Dialog::~Dialog()
{
    delete ui;

}

void Dialog::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    sierpinski();
}

void Dialog::sierpinski()
{
    QPainter canvas(this);
    QColor color = QColor(0,0,0);
    canvas.setPen(color);
    dibujaTriangulo(10, this->height() - 10, this->width() - 10, this->height() - 10, this->width() / 2, 10);
}

void Dialog::dibujaTriangulo(float x1, float y1, float x2, float y2, float x3, float y3)
{
    QPainter canvas(this);
    QColor color = QColor(0,0,0);
    canvas.setPen(color);
    canvas.drawLine(int(x1), int(y1), int(x2), int(y2));
    canvas.drawLine(int(x1), int(y1), int(x3), int(y3));
    canvas.drawLine(int(x2), int(y2), int(x3), int(y3));

    subTriangulo(
          1, //This represents the first recursion
          (x1 + x2) / 2, //x coordinate of first corner
          (y1 + y2) / 2, //y coordinate of first corner
          (x1 + x3) / 2, //x coordinate of second corner
          (y1 + y3) / 2, //y coordinate of second corner
          (x2 + x3) / 2, //x coordinate of third corner
          (y2 + y3) / 2  //y coordinate of third corner
        );


}

void Dialog::subTriangulo(int n, float x1, float y1, float x2, float y2, float x3, float y3)
{
    QPainter canvas(this);
    //QColor color = QColor(0,0,0);
    canvas.drawLine(int(x1), int(y1), int(x2), int(y2));
    canvas.drawLine(int(x1), int(y1), int(x3), int(y3));
    canvas.drawLine(int(x2), int(y2), int(x3), int(y3));

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
          (y1 + y2) / 2
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
          (y3 + y2) / 2
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
          (y1 + y3) / 2
        );
      }
}

