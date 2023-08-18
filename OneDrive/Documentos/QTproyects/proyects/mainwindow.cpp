#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer1 = new QTimer(this);
    connect(QTimer1, &QTimer::timeout, this, &MainWindow::OnQTimer1);
    count = 0;
    ui->lcdNumber->display("00:00:00");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::OnQTimer1(){
    if(ui->checkBox->isChecked()){
        count--;
        if(count == 0){
            seg--;
            count=99;
        }
        if(seg == 0){
            min--;
            seg=60;
        }
       if(min < 0){
           QTimer1->stop();
           count=0;
           min=0;
           seg=0;
           ui->pushButton->setText("Start");
       }
    }else{
    count++;
    if(count == 100){
            count = 0;
            seg++;
           }
    if(seg == 60){
        seg = 0;
        min++;
    }
    }
    if(ui->checkBox_Pause->isChecked()){

    }else{
    ui->lcdNumber->display(QString("%1:%2:%3").arg(min, 2 ,10 , QChar('0')).arg(seg,2,10,QChar('0')).arg(count, 2 ,10,QChar('0')));
    }
}

void MainWindow::on_toolButton_clicked()
{
    QString str;

    str = ui->lineEdit->text();


    if(str == "close")
        close();
      else{
        count++;
        if(count == 100)
            count = 0;
        //ui->lineEdit->setText(QString().number(count));
       // str = QString().asprintf("Numero: %d",count);
        str = QString("%1").arg(count, 2, 10, QChar('0'));
    }
    ui->lineEdit->setText(str);
}


void MainWindow::on_pushButton_clicked()
{
    if(QTimer1->isActive()){
        QTimer1->stop();
        ui->pushButton->setText("START");
    }
    else{
        QTimer1->start(5);
        ui->pushButton->setText("STOP");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    if(QTimer1->isActive()){
        QTimer1->stop();
        ui->pushButton->setText("START");
        count = 0;
        min = 0;
        seg = 0;
    }else{
        min = 0;
        seg = 0;
        count = 0;
    }
    ui->lcdNumber->display(QString("%1:%2:%3").arg(min, 2 ,10 , QChar('0')).arg(seg,2,10,QChar('0')).arg(count,2,10,QChar('0')));
}




