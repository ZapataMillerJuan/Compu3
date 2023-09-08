#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSerialPort1 = new QSerialPort(this);
    connect(QSerialPort1, &QSerialPort::readyRead, this, &MainWindow::onRxQSerialPort1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->plainTextEdit->clear();
}

void MainWindow::onRxQSerialPort1(){
    char *buf;
    int count;
    QString str;

    count = QSerialPort1->bytesAvailable();

    if(count <= 0)
        return;

    buf = new char[count];

    QSerialPort1->read(buf,count);

    str = "";

    for(int i=0;i<count;i++){
        str = str + QString(buf[i]);
    }

    ui->plainTextEdit->appendPlainText(str);

    delete[] buf;
}

void MainWindow::on_pushButton_clicked()
{
    if(QSerialPort1->isOpen()){
        QSerialPort1->close();
        ui->pushButton->setText("OPEN");
    }
    else{
        QSerialPort1->setPortName(ui->lineEdit_2->text());
        QSerialPort1->setBaudRate(QSerialPort::Baud115200);
        if(QSerialPort1->open(QSerialPort::ReadWrite)){
            ui->pushButton->setText("CLOSE");
        }
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    char bufTx[256];
    if(QSerialPort1->isOpen()){
        if(ui->lineEdit->text() != ""){
            for(int i=0;i<ui->lineEdit->text().length();i++){
                bufTx[i] = ui->lineEdit->text().toUtf8().data()[i];
            }
            QSerialPort1->write(bufTx,ui->lineEdit->text().length());
        }
    }
}

