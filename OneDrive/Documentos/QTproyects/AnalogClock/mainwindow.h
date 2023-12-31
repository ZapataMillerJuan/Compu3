#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qpaintbox.h>
#include <QPainter>
#include <QTime>
#include <QDateTime>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:


    void OnQTimer1();

private:
    Ui::MainWindow *ui;

    QPaintBox *QPaintBox1;

    QTimer *QTimer1;
    QTime *Time;

    int count;
    int seg;
};
#endif // MAINWINDOW_H
