#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qgridlayout.h>
#include<calculator.h>
#include <qfiledialog.h>
#include <QTextStream>
#include <QKeyEvent>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(openFile()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Enter){
        equal();
    }
}

void MainWindow::equal()
{
    QString text = ui->show->text();
    if(hasResult == true){
        ui->result->clear();
        hasResult =false;
    }
    calculator *c = new calculator(text);
    try{
        hasResult = true;
        QString result = c->calculate();
        ui->result->setText(result);
    }catch(const char *str){
        ui->result->setText(QString::fromLocal8Bit(str));
    }
}

void MainWindow::input(QString input)
{
    if(hasResult == true){
        ui->show->clear();
        ui->result->clear();
        hasResult =false;
    }
    ui->show->setText(ui->show->text()+input);
}



void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,"选择表达式文件",".",tr("txt file(*.txt);;all files(*./*)"));
    QFile file(fileName);
    if(!file.open(QIODevice::ReadWrite)){
       ui->result->setText(QString::fromLocal8Bit("文件出错"));
       hasResult = true;
    }
    QTextStream in(&file);
    QString expression = "";
    QString data = "";
    calculator *c = new calculator(expression);
    while(!in.atEnd()){
         expression = in.readLine();
         if(expression.contains("=")){
             int index = expression.indexOf("=");
               expression = expression.left(index);
         }
         c->setExpression(expression);
         try{
            data+=expression+"="+c->calculate()+"\r\n";
            ui->result->setText("success");
         }catch(const char *s){
             data+=expression+"//"+QString::fromLocal8Bit(s)+"\r\n";
            ui->result->setText(QString::fromLocal8Bit(s));
            continue;
         }
    }
    in.seek(0);
    in<<data;
    file.close();
}



void MainWindow::on_btn1_clicked()
{
    input(ui->btn1->text());

}

void MainWindow::on_btn2_clicked()
{
    input(ui->btn2->text());
}

void MainWindow::on_btn3_clicked()
{
     input(ui->btn3->text());
}



void MainWindow::on_add_clicked()
{
    input(ui->add->text());
}

void MainWindow::on_btn4_clicked()
{
   input(ui->btn4->text());
}

void MainWindow::on_btn5_clicked()
{
 input(ui->btn5->text());
}

void MainWindow::on_btn6_clicked()
{
 input(ui->btn6->text());
}

void MainWindow::on_reduce_clicked()
{
  input(ui->reduce->text());
}

void MainWindow::on_btn7_clicked()
{
    input(ui->btn7->text());
}

void MainWindow::on_btn8_clicked()
{
   input(ui->btn8->text());
}

void MainWindow::on_btn9_clicked()
{
 input(ui->btn9->text());
}

void MainWindow::on_multiply_clicked()
{
   input(ui->multiply->text());
}


void MainWindow::on_btn0_clicked()
{
 input(ui->btn0->text());
}

void MainWindow::on_equal_clicked()
{
    equal();
}

void MainWindow::on_divide_clicked()
{
 input(ui->divide->text());
}

void MainWindow::on_left_clicked()
{
     input(ui->left->text());
}

void MainWindow::on_right_clicked()
{
 input(ui->right->text());
}

void MainWindow::on_mode_clicked()
{
 input(ui->mode->text());
}

void MainWindow::on_ac_clicked()
{
    input(ui->ac->text());
}

void MainWindow::on_back_clicked()
{
   QString text = ui->show->text();
   int length = text.length();
   text = text.mid(0,length-1);
   ui->show->setText(text);
}

