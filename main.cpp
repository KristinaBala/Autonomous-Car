#include "mainwindow.h"
#include "mainwindow.h"
#include <QApplication>
#include "camera.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Camera camera;
    camera.show();

   return a.exec();
}
