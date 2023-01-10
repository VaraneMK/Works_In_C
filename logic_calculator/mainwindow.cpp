#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette pal;
    pal.setColor(QPalette::Window,Qt::red);
    ui->centralWidget->setAutoFillBackground(true);//разрешаем автозаливку
    ui->centralWidget->setPalette(pal);//присваиваем измененную палитру

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::my_func()
{
    bool op1,op2,res;
    res=false;
    QPalette pal;//палитра
    op1=ui->comboBoxOP1->currentIndex()==1;//Присваиваем номер индекса 1
    op2=ui->comboBoxOP2->currentIndex()==1;//Присваиваем номер индекса 2
    pal=ui->centralWidget->palette();//считываем палитру


    switch (ui->comboBox_LongOp->currentIndex())
    {
    case 0://дизъюнкция
        res=(op1||op2);//вычисляем результат
        ui->comboBoxOP2->show();
        break;
    case 1://коньюкция
        res=(op1&&op2);//вычисляем результат
        ui->comboBoxOP2->show();
        break;
    case 2://инверсия
        res=(!op1);//вычисляем результат
        ui->comboBoxOP2->hide();
        break;
    case 3://импликация
        res=(!op1||op2);//вычисляем результат
        ui->comboBoxOP2->show();
        break;
    case 4://эквивалентность
        res=(op1==op2);//вычисляем результат
        ui->comboBoxOP2->show();
        break;
    case 5://исключающее или
        res=(op1!=op2);//вычисляем результат
        ui->comboBoxOP2->show();
        break;
    }
        if(res)
        {
            pal.setColor(QPalette::Window,Qt::green);
        }
        else
        {
            pal.setColor(QPalette::Window,Qt::red);
        }
        ui->centralWidget->setAutoFillBackground(true);//разрешаем автозаливку
        ui->centralWidget->setPalette(pal);//присваиваем измененную палитру
}


void MainWindow::on_comboBoxOP1_currentIndexChanged(int)
{
    my_func();//вызов функции
}


void MainWindow::on_comboBoxOP2_currentIndexChanged(int)
{
    my_func();//вызов функции
}


void MainWindow::on_comboBox_LongOp_currentIndexChanged(int)
{
    my_func();//вызов функции
}
