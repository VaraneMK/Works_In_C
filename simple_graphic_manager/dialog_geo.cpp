#include "dialog_geo.h"
#include "ui_dialog_geo.h"

Dialog_geo::Dialog_geo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_geo)
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
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);

}

Dialog_geo::~Dialog_geo()
{
    delete ui;//деструктор
}


void Dialog_geo::on_spinBox_valueChanged(int arg1)
{
    ui->tableWidget->setRowCount(arg1);
    ui->tableWidget_2->setRowCount(arg1-1);

}

void Dialog_geo::on_tableWidget_cellChanged(int row, int column)
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
        for (int i=0;i<size_table-1;i++)
        {
            if((ui->tableWidget_2->item(i,0))!=nullptr)
            {
                ui->tableWidget_2->item(i,0)->text().toInt(&fl_lc);
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

void Dialog_geo::on_tableWidget_2_cellChanged(int row, int column)
{
    bool fl;
    bool fl_lc;
    int status=0;//для нахождения не int значений
    int status2=0;//для нахождения пустых строк
    int size_table=ui->spinBox->value()-1;
    ui->tableWidget_2->item(row,column)->text().toInt(&fl);
    if(fl)
    {
        ui->tableWidget_2->item(row,column)->setBackground(Qt::white);
        for (int i=0;i<size_table;i++)
        {
            if((ui->tableWidget_2->item(i,0))!=nullptr)
            {
                ui->tableWidget_2->item(i,0)->text().toInt(&fl_lc);
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
        ui->tableWidget_2->item(row,column)->setBackground(Qt::red);
        ui->pushButton_add->setEnabled(0);
        status=0;
    }
}


void Dialog_geo::on_pushButton_clicked()
{
    close();//закрытие окна
}

void Dialog_geo::on_pushButton_add_clicked()
{
    arrayForSending();
}
void Dialog_geo::arrayForSending()
{
    int size=ui->spinBox->value();
    std::vector<tochka> toPoints(size);
    int old_x;

    for (int i=0;i<size;i++)
    {
        if (ui->tableWidget->item(i,0)==nullptr)
        {
            QTableWidgetItem * ti;
            ti = new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,ti);
        }
         toPoints[i].SetY(ui->tableWidget->item(i,0)->text().toInt());
    }

    for (int i=0;i<size;i++)
    {
        if (ui->tableWidget_2->item(i,0)==nullptr)
        {
            QTableWidgetItem * ti;
            ti = new QTableWidgetItem;
            ui->tableWidget_2->setItem(i,0,ti);
        }
        if(i==0)
        {
            toPoints[i].SetX(0);
        }
        else
        {
            toPoints[i].SetX(ui->tableWidget_2->item(i-1,0)->text().toInt()+old_x);
            old_x=old_x+ui->tableWidget_2->item(i-1,0)->text().toInt();
        }
    }

    emit ExportTochkaGeog(toPoints);//вызов сигнала экспорта вектора точек

    close();//закрытие окна


}
