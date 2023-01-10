#include "dialog_polylines.h"
#include "ui_dialog_polylines.h"

Dialog_polylines::Dialog_polylines(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_polylines)
{
    ui->setupUi(this);
    ui->pushButton_add->setEnabled(0);
    QPalette p(palette());
    p.setColor(QPalette::Background,QColor(250,238,221));
    this->setAutoFillBackground(true);
    this->setPalette(p);
    p.setColor(QPalette::Background,Qt::white);
    ui->tableWidget->setAutoFillBackground(true);
    ui->tableWidget->setPalette(p);
}

Dialog_polylines::~Dialog_polylines()
{
    delete ui;//деструктор
}


void Dialog_polylines::on_spinBox_valueChanged(int arg1)
{
    ui->tableWidget->setRowCount(arg1);
}

void Dialog_polylines::on_tableWidget_cellChanged(int row, int column)
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
        if(status2++==0)
        {
            if(status==0)
            {
                ui->pushButton_add->setEnabled(1);
                status=0;

            }
            else
            {
                ui->pushButton_add->setEnabled(0);
                status=0;
            }
        }
        else
        {
            ui->pushButton_add->setEnabled(0);
            status2=0;
        }
    }
    else
    {
        ui->tableWidget->item(row,column)->setBackground(Qt::red);
        ui->pushButton_add->setEnabled(0);
        status=0;
    }
}


void Dialog_polylines::on_pushButton_clicked()
{
    close();//закрытие окна
}

void Dialog_polylines::on_pushButton_add_clicked()
{
    int size=ui->spinBox->value();
    if((ui->tableWidget->item(0,0)->text()==ui->tableWidget->item(size-1,0)->text())&&(ui->tableWidget->item(0,1)->text()==ui->tableWidget->item(size-1,1)->text()))
    {
        QMessageBox::information(this,"Ошибка","Начальная и конечная точки не должны совпадать.");
    }
    else
    {
        arrayForSending();
    }
}
void Dialog_polylines::arrayForSending()
{
    int size=ui->spinBox->value();

    //tochka *toPoints=new tochka[size];
    std::vector<tochka> toPoints(size);


    for (int i=0;i<size;i++)
    {
        if (ui->tableWidget->item(i,0)==nullptr)
        {
            QTableWidgetItem * ti;
            ti = new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,ti);
        }
        toPoints[i].SetX(ui->tableWidget->item(i,0)->text().toInt());
        toPoints[i].SetY(ui->tableWidget->item(i,1)->text().toInt());
    }

    emit ExportTochkaPl(toPoints);//вызов сигнала экспорта вектора точек

    close();//закрытие окна


}
