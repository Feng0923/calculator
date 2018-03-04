#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString calculate(QString expression);
void keyPressEvent(QKeyEvent  *event);
void equal();
void input(QString input);
private slots:
    void openFile();

    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_add_clicked();


    void on_btn4_clicked();

    void on_btn5_clicked();

    void on_btn6_clicked();


    void on_reduce_clicked();

    void on_btn7_clicked();

    void on_btn8_clicked();

    void on_btn9_clicked();

    void on_multiply_clicked();


    void on_btn0_clicked();

    void on_equal_clicked();

    void on_divide_clicked();

    void on_left_clicked();

    void on_right_clicked();

    void on_mode_clicked();



    void on_ac_clicked();

    void on_back_clicked();

private:
    Ui::MainWindow *ui;

    bool hasResult = false;
};

#endif // MAINWINDOW_H
