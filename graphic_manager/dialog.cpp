#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->comboBox->setCurrentIndex(1);//установка значения спинбокса
}

Dialog::~Dialog()
{
    delete ui;//Деструктор
}

void Dialog::setValue(my_pen n_pen)//переносим старые значения
{
    my_style=n_pen.GetStyle();
    n_pen.GetColor(red,green,blue,alpha);//считываем цвет
    w=n_pen.GetW();//считываем ширину

    color.setRgb(red,green,blue,alpha);//установка цвета
    ui->horizontalSlider->setValue(w);//установка ширины
    ui->label_w->setNum(w);

    ui->comboBox->setVisible(styleVisible);//Установка видимости
    ui->label_st->setVisible(styleVisible);//установка видимости
    ui->comboBox->setCurrentIndex(my_style);//установка значения стиля

}

void Dialog::setStyleVisible(bool fl)
{
    styleVisible=fl;//если выбрана точка
}

void Dialog::on_buttonBox_accepted()
{
    color.getRgb(&red,&green,&blue,&alpha);
    my_style=ui->comboBox->currentIndex();//считываем стиль
    w=ui->horizontalSlider->value();//считываем ширину
}

void Dialog::on_horizontalSlider_valueChanged(int value)
{
   ui->label_w->setText(QString::number(value));//передаем значение в label
}

void Dialog::on_pushbutton_color_clicked()
{
    QColor new_color=QColorDialog::getColor(color,nullptr,"Цвет карандаша");
    if (new_color.isValid())//если цвет валидный
    {
        color=new_color;
    }
}
