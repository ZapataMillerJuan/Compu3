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

    brush.setColor(Qt::blue);

    brush.setStyle(Qt::SolidPattern);

    paint.setBrush(brush);

    paint.drawEllipse(5,5,430,430);

    paint.setPen(pen);

    pen.setColor(Qt::red);

    paint.drawEllipse(5,5,430,430);



    QPaintBox1->update();

}

