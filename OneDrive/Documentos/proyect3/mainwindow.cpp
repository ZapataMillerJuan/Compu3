#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPaintBox1 = new QPaintBox(0, 0 ,ui->widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QPainter paint(QPaintBox1->getCanvas());

    QPen pen;

    QBrush brush;

    QPoint mypoints[8];

    pen.setWidth(3);



    pen.setColor(Qt::yellow);

    paint.setPen(pen);

    //paint.drawLine(0,ui->widget->height()/2,ui->widget->width(),ui->widget->height()/2);

    brush.setColor(Qt::blue);

    brush.setStyle(Qt::SolidPattern);

    paint.setBrush(brush);

    paint.drawEllipse(ui->widget->width()/2,ui->widget->height()/2,100,100);
    pen.setColor(Qt::red);

    paint.setPen(pen);

    paint.drawEllipse(10,10,100,100);

    mypoints[0].setX(0);
    mypoints[0].setY(0);
    mypoints[1].setX(10);
    mypoints[1].setY(0);
    mypoints[2].setX(10);
    mypoints[2].setY(50);
    mypoints[3].setX(5);
    mypoints[3].setY(55);
    mypoints[4].setX(0);
    mypoints[4].setY(50);
    mypoints[5].setX(0);
    mypoints[5].setY(0);

    paint.translate(ui->widget->width()/2,ui->widget->height()/2);

    paint.rotate(90);

    paint.drawPolygon(mypoints,6);

    QPaintBox1->update();
}

