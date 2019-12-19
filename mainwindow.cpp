#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "joypad.h"
#include <QApplication>
#include "camera.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QDesktopWidget>
#include <QtCore/QCommandLineParser>
#include <QtCore/QCommandLineOption>
#include <QtCore/QDir>

#include<QMediaPlayer>
#include<QVideoWidget>





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    connect(ui->widget, &JoyPad::xChanged, this, [this](float x){
        qDebug() << "x: " << x << " y: " << ui->widget->y();
    });


    connect(ui->widget, &JoyPad::yChanged, this, [this](float y){
        qDebug() << "x: " << ui->widget->x() << " y: " << y;
    });


}







MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_Lights_triggered()
{

}

void MainWindow::on_Lights_clicked()
{

}
