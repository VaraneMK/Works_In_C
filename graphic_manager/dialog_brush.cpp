#include "dialog_brush.h"
#include "ui_dialog_brush.h"

Dialog_brush::Dialog_brush(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_brush)
{
    ui->setupUi(this);
    ui->comboBox->setCurrentIndex(1);//установка значение спинбокса
    ui->pushButton->setStyleSheet(
    "QPushButton: {background-color: rgb(60, 60, 60)};"
    "QPushButton: {border-radius: 6px transparent};"
    "QPushButton: {border-bottom: 3px transparent};"
    "QPushButton {border-right: 2px transparent};"
    "QPushButton: {border-left: 2px transparent};"
    "QPushButton: active{ background-color: rgb(232,95,76); }"
    "QPushButton: hover{ background-color: rgb(232,95,76);} "
    );//установка стиля
}

Dialog_brush::~Dialog_brush()
{
    delete ui;//Деструктор
}


void Dialog_brush::setValue(my_brush n_brush)//переносим старые значения
{
    my_style=n_brush.GetStyle();//cчитываем стиль
    n_brush.GetColor(red,green,blue,alpha);//считываем цвет

    color.setRgb(red,green,blue,alpha);
    ui->comboBox->setCurrentIndex(my_style);
}

void Dialog_brush::on_pushButton_ok_clicked()
{
    color.getRgb(&red,&green,&blue,&alpha);
    my_style=ui->comboBox->currentIndex();
    close();
}

void Dialog_brush::on_pushButton_clicked()
{
    QColor new_color=QColorDialog::getColor(color,nullptr,"Цвет заливки");
    if (new_color.isValid())//если цвет валидный
    {
        color=new_color;
    }
}

void Dialog_brush::on_pushbutton_cancel_clicked()
{
    close();
}
