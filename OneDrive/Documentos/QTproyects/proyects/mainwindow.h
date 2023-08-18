#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void on_toolButton_clicked();
    void OnQTimer1();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::MainWindow *ui;
    int count=0;
    int seg=0;
    int min=0;

    QTimer *QTimer1;
};
#endif // MAINWINDOW_H
