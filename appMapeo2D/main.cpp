#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setFixedSize(700,500);//para tener un tamaño en especifico de la ventana
    w.show();
    return a.exec();
}
