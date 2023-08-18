#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer1 = new QTimer(this);
    connect(QTimer1, &QTimer::timeout, this, &MainWindow::OnQTimer1);

    QPaintBox1 = new QPaintBox(0, 0 ,ui->widget);
    QTimer1->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::OnQTimer1(){
    QTime Time;
    Time = QTime::currentTime();
    count++;
    seg++;
    QPainter paint(QPaintBox1->getCanvas());

    QPen pen;

    QBrush brush;

    QPoint mypoints[3][8];

    QLine lines[12];

    pen.setWidth(3);



    pen.setColor(Qt::red);

    paint.setPen(pen);

    brush.setColor(Qt::darkCyan);

    brush.setStyle(Qt::SolidPattern);

    paint.setBrush(brush);

    paint.drawEllipse(5,5,490,490);

    paint.save();
    pen.setColor(Qt::darkBlue);
    paint.setPen(pen);
    paint.translate(ui->widget->width()/2,ui->widget->height()/2);
    for(int i=0;i<12;i++){
        lines[i].setLine(0,-240,0,-230);
        paint.rotate(30);
        paint.drawLine(lines[i]);
    }

    paint.restore();
    pen.setColor(Qt::gray);
    paint.setPen(pen);
    paint.setBrush(brush);

    pen.setColor(Qt::lightGray);
    paint.setPen(pen);
    brush.setColor(Qt::lightGray);

    brush.setStyle(Qt::SolidPattern);

    paint.setBrush(brush);

    paint.translate((ui->widget->width()/2),ui->widget->height()/2);
    mypoints[0][0].setX(0);
    mypoints[0][0].setY(0);
    mypoints[0][1].setX(4);
    mypoints[0][1].setY(0);
    mypoints[0][2].setX(4);
    mypoints[0][2].setY(200);
    mypoints[0][3].setX(0);
    mypoints[0][3].setY(215);
    mypoints[0][4].setX(-4);
    mypoints[0][4].setY(200);
    mypoints[0][5].setX(-4);
    mypoints[0][5].setY(0);

    paint.save();

    paint.rotate(180+(Time.second()*6)+(Time.msec()/100)*0.6);

    paint.drawPolygon(mypoints[0],6);

    paint.restore();

    paint.translate(-(ui->widget->width()/2),-ui->widget->height()/2);

    if(Time.second()<59){
        paint.translate((ui->widget->width()/2),ui->widget->height()/2);
        mypoints[1][0].setX(0);
        mypoints[1][0].setY(0);
        mypoints[1][1].setX(4);
        mypoints[1][1].setY(0);
        mypoints[1][2].setX(4);
            mypoints[1][2].setY(150);
            mypoints[1][3].setX(0);
            mypoints[1][3].setY(165);
            mypoints[1][4].setX(-4);
            mypoints[1][4].setY(150);
            mypoints[1][5].setX(-4);
            mypoints[1][5].setY(0);

            paint.save();

            paint.rotate(180+(Time.minute()*6.0));

            paint.drawPolygon(mypoints[1],6);

            paint.restore();
            //paint.rotate(-180-(Time.minute()*6.0));

            paint.translate(-(ui->widget->width()/2),-ui->widget->height()/2);
        }else{
                pen.setColor(Qt::lightGray);
                paint.setPen(pen);
                brush.setColor(Qt::lightGray);
                paint.setBrush(brush);
               // ui->statusbar->showMessage(QString("ENTRO"));
                paint.translate((ui->widget->width()/2),ui->widget->height()/2);
                mypoints[1][0].setX(0);
                mypoints[1][0].setY(0);
                mypoints[1][1].setX(4);
                mypoints[1][1].setY(0);
                mypoints[1][2].setX(4);
                mypoints[1][2].setY(150);
                mypoints[1][3].setX(0);
                mypoints[1][3].setY(165);
                mypoints[1][4].setX(-4);
                mypoints[1][4].setY(150);
                mypoints[1][5].setX(-4);
                mypoints[1][5].setY(0);

                paint.save();

                paint.rotate(180+Time.minute()*6+(Time.msec()/100)*0.6);

                paint.drawPolygon(mypoints[1],6);

                paint.restore();

                paint.translate(-(ui->widget->width()/2),-ui->widget->height()/2);
        }

        brush.setColor(Qt::gray);

        brush.setStyle(Qt::SolidPattern);

        paint.setBrush(brush);

        pen.setColor(Qt::gray);
        paint.setPen(pen);

        paint.drawEllipse((ui->widget->width()/2)-10,(ui->widget->height()/2)-10,20,20);
        //QPaintBox1->update();



    if(count == 60000)
        count = 0;

    QPaintBox1->update();
}





