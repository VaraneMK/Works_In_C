#include "dialog_points.h"
#include "ui_dialog_points.h"

Dialog_points::Dialog_points(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_points)
{
    ui->setupUi(this);
    is_ok=false;
}

Dialog_points::~Dialog_points()
{
    delete ui;//деструктор
}

void Dialog_points::on_spinBox_valueChanged(int arg1)
{
    if(count<arg1)
        ui->pushButton_OK->setEnabled(0);
    ui->tableWidget->setRowCount(arg1);//устанавливаем кол во строк в таблице
    count=arg1;

}

void Dialog_points::OpenD(std::vector<tochka> * Points)//переносим значения точек
{
    MainPoints = Points;
    // Ставим в таблицу уже существующие значения
    int count = MainPoints->size();
    ui->spinBox->setValue(count);
    QTableWidgetItem * twi = nullptr;
    for (int i = 0; i < count; i++)
    {
        twi = new QTableWidgetItem;
        twi->setText(QString::number((*MainPoints)[i].GetX()));//X
        ui->tableWidget->setItem(i, 0, twi);
        twi = new QTableWidgetItem;
        twi->setText(QString::number((*MainPoints)[i].GetY()));//Y
        ui->tableWidget->setItem(i, 1, twi);
    }


    // Открываем диалог
    exec();
}

void Dialog_points::on_pushButton_Cancel_clicked()
{
    close();//закрываем
}

void Dialog_points::on_pushButton_OK_clicked()
{
    int size=ui->spinBox->value();
    if ((*MainPoints).size() != size)
        MainPoints->resize(size);

    for (int i = 0; i < size; i++)//переносим новые значения
    {
        int x = ui->tableWidget->item(i, 0)->text().toInt();
        int y = ui->tableWidget->item(i, 1)->text().toInt();
        (*MainPoints)[i].SetX(x);
        (*MainPoints)[i].SetY(y);
    }
    close();
}



void Dialog_points::on_tableWidget_cellChanged(int row, int column)
{
    bool fl;
    bool fl_lc;
    int status=0;//для нахождения не int значений
    int status2=0;//для нахождения пустых строк
    int size_table=ui->spinBox->value();
    ui->tableWidget->item(row,column)->text().toInt(&fl);
    if(fl)
    {
        ui->tableWidget->item(row,column)->setBackground(Qt::white);
        for (int i=0;i<size_table;i++)
        {
            if((ui->tableWidget->item(i,0))!=nullptr)
            {
                ui->tableWidget->item(i,0)->text().toInt(&fl_lc);
                if (!fl_lc)
                {
                    status++;
                }
            }
            else
            {
                status2++;
            }
        }
        for (int i=0;i<size_table;i++)
        {
            if((ui->tableWidget->item(i,1))!=nullptr)
            {
                ui->tableWidget->item(i,1)->text().toInt(&fl_lc);
                if (!fl_lc)
                {
                    status++;
                }
            }
            else
            {
                status2++;
            }
        }
        if(status2==0)
        {
            if(status==0)
            {
                ui->pushButton_OK->setEnabled(1);
                status=0;

            }
            else
            {
                ui->pushButton_OK->setEnabled(0);
                status=0;
            }
        }
        else
        {
            ui->pushButton_OK->setEnabled(0);
            status2=0;
        }
    }
    else
    {
        ui->tableWidget->item(row,column)->setBackground(Qt::red);
        ui->pushButton_OK->setEnabled(0);
        status=0;
    }
}
