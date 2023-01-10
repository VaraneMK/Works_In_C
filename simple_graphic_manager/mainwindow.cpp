#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "dialog_polylines.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->create_im(ui->widget->width(),ui->widget->height());//создаем изображение определенной ширины и высоты
    ui->label_7->setText(QString::number(ui->widget->width())+"x"+QString::number(ui->widget->height()));

    QPalette p(palette());
    p.setColor(QPalette::Background,QColor(250,238,221));
    this->setAutoFillBackground(true);
    this->setPalette(p);
    p.setColor(QPalette::Background,Qt::white);
    ui->widget->setAutoFillBackground(true);
    ui->widget->setPalette(p);
    ui->comboBox_pen->setCurrentIndex(1);



    ui->label->setText("X");
    ui->label_2->setText("Y");
    ui->label_3->setText("X1");
    ui->label_4->setText("Y1");
    ui->label->show();
    ui->label_2->show();
    ui->lineEdit_PixelX->show();
    ui->lineEdit_PixelY->show();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->lineEdit_PixelX1->hide();
    ui->lineEdit_PixelY1->hide();
    ui->label_an1->hide();
    ui->label_an2->hide();
    ui->lineEdit_spAngle->hide();
    ui->lineEdit_stAngle->hide();

    ui->comboBox_brush->hide();
    ui->label_brush->hide();
}

MainWindow::~MainWindow()
{
    delete ui;//деструктор
}

void MainWindow::ImportTochka(std::vector<tochka> mas)//импорт вектора точек
{
    pol.draw(ui->widget->im, mas);
    update();
}

void MainWindow::ImportTochkaPl(std::vector<tochka> mas)//импорт вектора точек
{
    pl_new.draw(ui->widget->im, mas);
    update();
}



void MainWindow::on_pushButton_clear_clicked()
{
    ui->widget->im.fill(0);//очистка виджета
    ui->widget->setAutoFillBackground(false);
    QPalette p(palette());
    p.setColor(QPalette::Background,Qt::white);//присваиваем стандартного цвета
    ui->widget->setAutoFillBackground(true);
    ui->widget->setPalette(p);
    update();

}


void MainWindow::on_pushButton_draw_clicked()
{
    if(ui->comboBox->currentIndex()==0)//pixel
    {
        int x,y=0;

        QString str;
        bool fl;
        pixel pix;

        str.clear();
        str.append(ui->lineEdit_PixelX->text());//считываем X
        x=str.toInt(&fl);
        if(fl)
        {
            str.clear();
            str.append(ui->lineEdit_PixelY->text());//считываем Y
            y=str.toInt(&fl);
        }
        //color
        if(fl)
        {
            int a,r,g,b;
            QColor color;
            if(ui->comboBox_pen->currentIndex()!=0)
            {
                color=QColorDialog::getColor(nullptr,nullptr,"Цвет карандаша");
                color.getRgb(&r,&g,&b,&a);
                pix.SetRGBA(r,g,b,a);//присваиваем цвет RGBA
                ui->horizontalSlider_penW->setEnabled(1);
            }
            else
            {
                ui->horizontalSlider_penW->setEnabled(0);
            }
        }
        if (fl)
        {
            pix.SetX(x);//присваиваем значение X
            pix.SetY(y);//присваиваем значение Y
            pix.draw(ui->widget->im);

            update();
        }
        else
        {
            QMessageBox::information(this,"Ошибка","Введены не корректные данные.");
        }
    }
    //========================================================================================================================
    else if (ui->comboBox->currentIndex()==1)//line
    {
        int x,y = 0,x1,y1 = 0;

        QString str;
        bool fl;
        line line;

        str.clear();
        str.append(ui->lineEdit_PixelX->text());//считываем X
        x=str.toInt(&fl);
        if(fl)
        {
            str.clear();
            str.append(ui->lineEdit_PixelY->text());//считываем Y
            x=str.toInt(&fl);
        }
        if (fl)
        {
            line.start.SetX(x);//присваиваем стартовой точке координату X
            line.start.SetY(y);//присваиваем стартовой точке координату Y
        }


        str.clear();
        str.append(ui->lineEdit_PixelX1->text());//считываем X1
        x1=str.toInt(&fl);
        if(fl)
        {
            str.clear();
            str.append(ui->lineEdit_PixelY1->text());//считываем Y1
            y1=str.toInt(&fl);
        }
        if (fl)
        {
            line.end.SetX(x1);//присваиваем стартовой точке координату X1
            line.end.SetY(y1);//присваиваем стартовой точке координату Y1

        }

        //color
        if(fl)
        {
            int a,r,g,b;
            QColor color;
            if(ui->comboBox_pen->currentIndex()!=0)
            {
                color=QColorDialog::getColor(nullptr,nullptr,"Цвет карандаша");
                color.getRgb(&r,&g,&b,&a);
                line.SetRGBA(r,g,b,a);//присваиваем цвет RGBA
                line.SetStyle(ui->comboBox_pen->currentIndex());
                line.SetWidth(ui->horizontalSlider_penW->value());
                ui->horizontalSlider_penW->setEnabled(1);
            }
            else
            {
                ui->horizontalSlider_penW->setEnabled(0);
            }
        }
        if (fl)
        {
            line.draw(ui->widget->im);
            update();
        }
        else
        {
            QMessageBox::information(this,"Ошибка","Введены не корректные данные.");
        }
    }
    else if(ui->comboBox->currentIndex()==2)//дуга
    {
        int x,y = 0,height=0,weight=0,startAngle,spanAngle = 0;

        QString str;
        bool fl;
        Arc arc1;


        str.clear();
        str.append(ui->lineEdit_PixelX->text());//cчитываем X
        x=str.toInt(&fl);
        if(fl)
        {
            str.clear();
            str.append(ui->lineEdit_PixelY->text());//считываем Y
            y=str.toInt(&fl);
        }
        if (fl)
        {
            arc1.begin.SetX(x);//присваиваем стартовой точке координату X
            arc1.begin.SetY(y);//присваиваем стартовой точке координату Y
        }


        str.clear();
        str.append(ui->lineEdit_PixelX1->text());//считываем радиус1
        weight=str.toInt(&fl);
        if(fl)
        {
            arc1.SetRadius1(weight);//присваем радиус1
            str.clear();
            str.append(ui->lineEdit_PixelY1->text());//считываем радиус2
            height=str.toInt(&fl);
        }
        if (fl)
        {
            arc1.SetRadius2(height);//присваиваем радиус2
        }

        str.clear();
        str.append(ui->lineEdit_stAngle->text());//считываем  начальный угол
        startAngle=str.toInt(&fl);
        if(fl)
        {
            arc1.SetStartAngle(startAngle);//присваиваем начальный угол
            str.clear();
            str.append(ui->lineEdit_spAngle->text());//считываем угол охвата
            spanAngle=str.toInt(&fl);
        }
        if (fl)
        {
            arc1.SetSpanAngle(spanAngle);//присваиваем угол охвата
        }

        //color
        if(fl)
        {
            int a,r,g,b;
            QColor color;
            if(ui->comboBox_pen->currentIndex()!=0)
            {
                color=QColorDialog::getColor(nullptr,nullptr,"Цвет карандаша");
                color.getRgb(&r,&g,&b,&a);
                arc1.SetRGBA(r,g,b,a);//установка цвета RGBA
                arc1.SetStyle(ui->comboBox_pen->currentIndex());
                arc1.SetWidth(ui->horizontalSlider_penW->value());
                ui->horizontalSlider_penW->setEnabled(true);
            }
            else
            {
                ui->horizontalSlider_penW->setEnabled(false);
            }
        }
        if (fl)
        {
            arc1.draw(ui->widget->im);
            update();
        }
        else
        {
            QMessageBox::information(this,"Ошибка","Введены не корректные данные.");
        }
    }

    //========================================================================================================================
    else if(ui->comboBox->currentIndex()==3)//прямоугольник
    {
        int x,y = 0,height=0,weight=0;

        QString str;
        bool fl;
        class rect rect1;


        str.clear();
        str.append(ui->lineEdit_PixelX->text());//считываем X
        x=str.toInt(&fl);
        if(fl)
        {
            str.clear();
            str.append(ui->lineEdit_PixelY->text());
            y=str.toInt(&fl);//считываем Y
        }
        if (fl)
        {
            rect1.point.SetX(x);//присваиваем точке координату X
            rect1.point.SetY(y);//присваиваем точке координату Y
        }


        str.clear();
        str.append(ui->lineEdit_PixelX1->text());//считываем ширину
        weight=str.toInt(&fl);
        if(fl)
        {
            rect1.SetWeight(weight);//присваиваем ширину
            str.clear();
            str.append(ui->lineEdit_PixelY1->text());//считываем высоту
            height=str.toInt(&fl);
        }
        if (fl)
        {
            rect1.SetHeight(height);//присваиваем высоту
        }
        //color
        if(fl)
        {
            int a,r,g,b;
            QColor color;
            if(ui->comboBox_pen->currentIndex()!=0)
            {
                color=QColorDialog::getColor(nullptr,nullptr,"Цвет карандаша");
                color.getRgb(&r,&g,&b,&a);
                rect1.gran.SetRGBA(r,g,b,a);//установка цвета карандаша RGBA
                rect1.gran.SetStyle(ui->comboBox_pen->currentIndex());
                rect1.gran.SetWidth(ui->horizontalSlider_penW->value());
                ui->horizontalSlider_penW->setEnabled(true);
            }
            else
            {
                ui->horizontalSlider_penW->setEnabled(false);
            }

            if(ui->comboBox_brush->currentIndex()!=0)
            {
                color=QColorDialog::getColor(nullptr,nullptr,"Цвет заливки");
                color.getRgb(&r,&g,&b,&a);
                rect1.zal.SetRGBA(r,g,b,a);//установка цвета заливки RGBA
                rect1.zal.SetStyle(ui->comboBox_brush->currentIndex());
            }

        }
        if (fl)
        {
            rect1.draw(ui->widget->im);
            update();
        }
        else
        {
            QMessageBox::information(this,"Ошибка","Введены не корректные данные.");
        }
    }
    //========================================================================================================================
    else if (ui->comboBox->currentIndex()==4)//круг
    {
        int x,y = 0,radius=0;

        QString str;
        bool fl;
        circle circle;


        str.clear();
        str.append(ui->lineEdit_PixelX->text());//считываем значение X
        x=str.toInt(&fl);
        if(fl)
        {
            str.clear();
            str.append(ui->lineEdit_PixelY->text());//считываем значение Y
            y=str.toInt(&fl);
        }
        if (fl)
        {
            circle.center.SetX(x);//присваиваем точке центра координату X
            circle.center.SetY(y);//присваиваем точке центра координату Y
        }


        str.clear();
        str.append(ui->lineEdit_PixelX1->text());//считываем радиус
        radius=str.toInt(&fl);
        if (fl)
        {
            circle.SetRadius(radius);//присваиваем значение радиуса
        }
        //color
        if(fl)
        {
            int a,r,g,b;
            QColor color;
            if(ui->comboBox_pen->currentIndex()!=0)
            {
                color=QColorDialog::getColor(nullptr,nullptr,"Цвет карандаша");
                color.getRgb(&r,&g,&b,&a);
                circle.gran.SetRGBA(r,g,b,a);//присваиваем цвет карандаша RGBA
                circle.gran.SetStyle(ui->comboBox_pen->currentIndex());
                circle.gran.SetWidth(ui->horizontalSlider_penW->value());
                ui->horizontalSlider_penW->setEnabled(true);
            }
            else
            {
                ui->horizontalSlider_penW->setEnabled(false);
            }

            if(ui->comboBox_brush->currentIndex()!=0)
            {
                color=QColorDialog::getColor(nullptr,nullptr,"Цвет заливки");
                color.getRgb(&r,&g,&b,&a);
                circle.zal.SetRGBA(r,g,b,a);//присваиваем цвет заливки RGBA
                circle.zal.SetStyle(ui->comboBox_brush->currentIndex());
            }
        }
        if (fl)
        {
            circle.draw(ui->widget->im);
            update();
        }
        else
        {
            QMessageBox::information(this,"Ошибка","Введены не корректные данные.");
        }
    }
    //========================================================================================================================
    else if (ui->comboBox->currentIndex()==5)//эллипс
    {
        int x,y = 0,radius1=0,radius2=0;

        QString str;
        bool fl;
        ellipse ellipse;


        str.clear();
        str.append(ui->lineEdit_PixelX->text());//считываем значение X
        x=str.toInt(&fl);
        if(fl)
        {
            str.clear();
            str.append(ui->lineEdit_PixelY->text());
            y=str.toInt(&fl);//считываем значение Y
        }
        if (fl)
        {
            ellipse.center.SetX(x);//присваиваем точке центра координату X
            ellipse.center.SetY(y);//присваиваем точке центра координату Y
        }


        str.clear();
        str.append(ui->lineEdit_PixelX1->text());//считываем значение радиуса1
        radius1=str.toInt(&fl);
        if(fl)
        {
            ellipse.SetRadius1(radius1);//присваиваем значение радиуса1
            str.clear();
            str.append(ui->lineEdit_PixelY1->text());//считываем значение радиуса2
            radius2=str.toInt(&fl);
        }
        if (fl)
        {
            ellipse.SetRadius2(radius2);//присваиваем значение радиуса2
        }
        //color
        if(fl)
        {
            int a,r,g,b;
            QColor color;
            if(ui->comboBox_pen->currentIndex()!=0)
            {
                color=QColorDialog::getColor(nullptr,nullptr,"Цвет карандаша");
                color.getRgb(&r,&g,&b,&a);
                ellipse.gran.SetRGBA(r,g,b,a);//присваиваем цвет карандаша RGBA
                ellipse.gran.SetStyle(ui->comboBox_pen->currentIndex());
                ellipse.gran.SetWidth(ui->horizontalSlider_penW->value());
                ui->horizontalSlider_penW->setEnabled(true);
            }
            else
            {
                ui->horizontalSlider_penW->setEnabled(false);
            }

            if(ui->comboBox_brush->currentIndex()!=0)
            {
                color=QColorDialog::getColor(nullptr,nullptr,"Цвет заливки");
                color.getRgb(&r,&g,&b,&a);
                ellipse.zal.SetRGBA(r,g,b,a);//присваиваем цвет заливки RGBA
                ellipse.zal.SetStyle(ui->comboBox_brush->currentIndex());
            }
        }
        if (fl)
        {
            ellipse.draw(ui->widget->im);
            update();
        }
        else
        {
            QMessageBox::information(this,"Ошибка","Введены не корректные данные.");
        }
    }
    else if(ui->comboBox->currentIndex()==6)//многоугольник
    {
        auto window= new Dialog();
        int a,r,g,b;
        QColor color;
        if(ui->comboBox_pen->currentIndex()!=0)
        {
            color=QColorDialog::getColor(nullptr,nullptr,"Цвет карандаша");
            color.getRgb(&r,&g,&b,&a);
            pol.gran.SetRGBA(r,g,b,a);//присваиваем цвет карандаша RGBA
            pol.gran.SetStyle(ui->comboBox_pen->currentIndex());
            pol.gran.SetWidth(ui->horizontalSlider_penW->value());
            ui->horizontalSlider_penW->setEnabled(true);
        }
        else
        {
            ui->horizontalSlider_penW->setEnabled(false);
        }

        if(ui->comboBox_brush->currentIndex()!=0)
        {
            color=QColorDialog::getColor(nullptr,nullptr,"Цвет заливки");
            color.getRgb(&r,&g,&b,&a);
            pol.zal.SetRGBA(r,g,b,a);//присваиваем цвет заливки RGBA
            pol.zal.SetStyle(ui->comboBox_brush->currentIndex());
        }
        connect(window, &Dialog::ExportTochka, this, &MainWindow::ImportTochka);//соединяем сигнал со слотом
        if(window->exec() == QDialog::Accepted)
        {
            disconnect(window, &Dialog::ExportTochka, this, &MainWindow::ImportTochka);//отсоединяем сигнал со слотом
        }
    }
    else if(ui->comboBox->currentIndex()==7)//ломанная линия
    {
        auto window= new Dialog_polylines();
        int a,r,g,b;
        if(ui->comboBox_pen->currentIndex()!=0)
        {
            QColor color;
            color=QColorDialog::getColor(nullptr,nullptr,"Цвет карандаша");
            color.getRgb(&r,&g,&b,&a);
            pl_new.gran.SetRGBA(r,g,b,a);//присваиваем цвет карандаша RGBA
            pl_new.gran.SetStyle(ui->comboBox_pen->currentIndex());
            pl_new.gran.SetWidth(ui->horizontalSlider_penW->value());
            ui->horizontalSlider_penW->setEnabled(true);
        }
        else
        {
            ui->horizontalSlider_penW->setEnabled(false);
        }

        connect(window, &Dialog_polylines::ExportTochkaPl, this, &MainWindow::ImportTochkaPl);//отсоединяем сигнал со слотом
        if(window->exec() == QDialog::Accepted)
        {
            disconnect(window, &Dialog_polylines::ExportTochkaPl, this, &MainWindow::ImportTochkaPl);//отсоединяем сигнал со слотом
        }
    }


}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(ui->comboBox->currentIndex()==0)//Pixel
    {
        ui->label->setText("X1");
        ui->label_2->setText("Y1");
        ui->label_3->setText("X2");
        ui->label_4->setText("Y2");
        ui->label->show();
        ui->label_2->show();
        ui->lineEdit_PixelX->show();
        ui->lineEdit_PixelY->show();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->lineEdit_PixelX1->hide();
        ui->lineEdit_PixelY1->hide();
        ui->label_an1->hide();
        ui->label_an2->hide();
        ui->lineEdit_spAngle->hide();
        ui->lineEdit_stAngle->hide();
        ui->comboBox_brush->hide();
        ui->label_brush->hide();



        ui->lineEdit_PixelX->clear();
        ui->lineEdit_PixelY->clear();
        ui->lineEdit_PixelX1->clear();
        ui->lineEdit_PixelY1->clear();
        ui->lineEdit_spAngle->clear();
        ui->lineEdit_stAngle->clear();
        ui->comboBox_pen->setCurrentIndex(1);
        ui->comboBox_brush->setCurrentIndex(0);
        ui->horizontalSlider_penW->setValue(1);
    }
    else if (ui->comboBox->currentIndex()==1) //Line
    {
        ui->label->setText("X1");
        ui->label_2->setText("Y1");
        ui->label_3->setText("X2");
        ui->label_4->setText("Y2");
        ui->label->show();
        ui->label_2->show();
        ui->label_3->show();
        ui->label_4->show();
        ui->lineEdit_PixelX->show();
        ui->lineEdit_PixelY->show();
        ui->lineEdit_PixelX1->show();
        ui->lineEdit_PixelY1->show();
        ui->label_an1->hide();
        ui->label_an2->hide();
        ui->lineEdit_spAngle->hide();
        ui->lineEdit_stAngle->hide();
        ui->comboBox_brush->hide();
        ui->label_brush->hide();

        ui->lineEdit_PixelX->clear();
        ui->lineEdit_PixelY->clear();
        ui->lineEdit_PixelX1->clear();
        ui->lineEdit_PixelY1->clear();
        ui->lineEdit_spAngle->clear();
        ui->lineEdit_stAngle->clear();
        ui->comboBox_pen->setCurrentIndex(1);
        ui->comboBox_brush->setCurrentIndex(0);
        ui->horizontalSlider_penW->setValue(1);
    }
    else if (ui->comboBox->currentIndex()==2)//Arc
    {
        ui->label->setText("X");
        ui->label_2->setText("Y");
        ui->label_3->setText("Радиус1");
        ui->label_4->setText("Радиус2");
        ui->label->show();
        ui->label_2->show();
        ui->label_3->show();
        ui->label_4->show();
        ui->lineEdit_PixelX->show();
        ui->lineEdit_PixelY->show();
        ui->lineEdit_PixelX1->show();
        ui->lineEdit_PixelY1->show();
        ui->label_an1->show();
        ui->label_an2->show();
        ui->lineEdit_spAngle->show();
        ui->lineEdit_stAngle->show();
        ui->comboBox_brush->hide();
        ui->label_brush->hide();

        ui->lineEdit_PixelX->clear();
        ui->lineEdit_PixelY->clear();
        ui->lineEdit_PixelX1->clear();
        ui->lineEdit_PixelY1->clear();
        ui->lineEdit_spAngle->clear();
        ui->lineEdit_stAngle->clear();
        ui->comboBox_pen->setCurrentIndex(1);
        ui->comboBox_brush->setCurrentIndex(0);
        ui->horizontalSlider_penW->setValue(1);
    }
    else if (ui->comboBox->currentIndex()==3) //Rect
    {
        ui->label->show();
        ui->label_2->show();
        ui->label_3->show();
        ui->label_4->show();
        ui->lineEdit_PixelX->show();
        ui->lineEdit_PixelY->show();
        ui->lineEdit_PixelX1->show();
        ui->lineEdit_PixelY1->show();
        ui->label->setText("X");
        ui->label_2->setText("Y");
        ui->label_3->setText("Ширина");
        ui->label_4->setText("Высота");
        ui->comboBox_brush->show();
        ui->label_brush->show();
        ui->lineEdit_spAngle->hide();
        ui->lineEdit_stAngle->hide();
        ui->label_an1->hide();
        ui->label_an2->hide();

        ui->lineEdit_PixelX->clear();
        ui->lineEdit_PixelY->clear();
        ui->lineEdit_PixelX1->clear();
        ui->lineEdit_PixelY1->clear();
        ui->lineEdit_spAngle->clear();
        ui->lineEdit_stAngle->clear();
        ui->comboBox_pen->setCurrentIndex(1);
        ui->comboBox_brush->setCurrentIndex(0);
        ui->horizontalSlider_penW->setValue(1);
    }
    else if(ui->comboBox->currentIndex()==4) //Circle
    {
        ui->label_4->hide();
        ui->lineEdit_PixelY1->hide();
        ui->label->show();
        ui->label_2->show();
        ui->label_3->show();
        ui->lineEdit_PixelX->show();
        ui->lineEdit_PixelY->show();
        ui->lineEdit_PixelX1->show();
        ui->label->setText("X");
        ui->label_2->setText("Y");
        ui->label_3->setText("Радиус");
        ui->comboBox_brush->show();
        ui->label_brush->show();
        ui->lineEdit_spAngle->hide();
        ui->lineEdit_stAngle->hide();
        ui->label_an1->hide();
        ui->label_an2->hide();

        ui->lineEdit_PixelX->clear();
        ui->lineEdit_PixelY->clear();
        ui->lineEdit_PixelX1->clear();
        ui->lineEdit_PixelY1->clear();
        ui->lineEdit_spAngle->clear();
        ui->lineEdit_stAngle->clear();
        ui->comboBox_pen->setCurrentIndex(1);
        ui->comboBox_brush->setCurrentIndex(0);
        ui->horizontalSlider_penW->setValue(1);
    }
    else if(ui->comboBox->currentIndex()==5) //Ellipse
    {
        ui->label->show();
        ui->label_2->show();
        ui->label_3->show();
        ui->label_4->show();
        ui->lineEdit_PixelX->show();
        ui->lineEdit_PixelY->show();
        ui->lineEdit_PixelX1->show();
        ui->lineEdit_PixelY1->show();
        ui->label->setText("X");
        ui->label_2->setText("Y");
        ui->label_3->setText("РадиусX");
        ui->label_4->setText("РадиусY");
        ui->comboBox_brush->show();
        ui->label_brush->show();
        ui->lineEdit_spAngle->hide();
        ui->lineEdit_stAngle->hide();
        ui->label_an1->hide();
        ui->label_an2->hide();



        ui->lineEdit_PixelX->clear();
        ui->lineEdit_PixelY->clear();
        ui->lineEdit_PixelX1->clear();
        ui->lineEdit_PixelY1->clear();
        ui->lineEdit_spAngle->clear();
        ui->lineEdit_stAngle->clear();
        ui->comboBox_pen->setCurrentIndex(1);
        ui->comboBox_brush->setCurrentIndex(0);
        ui->horizontalSlider_penW->setValue(1);
    }
    else if (ui->comboBox->currentIndex()==6)// Polygon
    {

        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->comboBox_brush->show();
        ui->label_brush->show();
        ui->lineEdit_PixelX->hide();
        ui->lineEdit_PixelX1->hide();
        ui->lineEdit_PixelY->hide();
        ui->lineEdit_PixelY1->hide();
        ui->label_an1->hide();
        ui->label_an2->hide();
        ui->lineEdit_spAngle->hide();
        ui->lineEdit_stAngle->hide();


        ui->lineEdit_PixelX->clear();
        ui->lineEdit_PixelY->clear();
        ui->lineEdit_PixelX1->clear();
        ui->lineEdit_PixelY1->clear();
        ui->lineEdit_spAngle->clear();
        ui->lineEdit_stAngle->clear();
        ui->comboBox_pen->setCurrentIndex(1);
        ui->comboBox_brush->setCurrentIndex(0);
        ui->horizontalSlider_penW->setValue(1);

    }
    else if (ui->comboBox->currentIndex()==7) //Polyline
    {
        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->comboBox_brush->hide();
        ui->label_brush->hide();
        ui->lineEdit_PixelX->hide();
        ui->lineEdit_PixelX1->hide();
        ui->lineEdit_PixelY->hide();
        ui->lineEdit_PixelY1->hide();
        ui->label_an1->hide();
        ui->label_an2->hide();
        ui->lineEdit_spAngle->hide();
        ui->lineEdit_stAngle->hide();

        ui->lineEdit_PixelX->clear();
        ui->lineEdit_PixelY->clear();
        ui->lineEdit_PixelX1->clear();
        ui->lineEdit_PixelY1->clear();
        ui->lineEdit_spAngle->clear();
        ui->lineEdit_stAngle->clear();
        ui->comboBox_pen->setCurrentIndex(1);
        ui->comboBox_brush->setCurrentIndex(0);
        ui->horizontalSlider_penW->setValue(1);
    }
    else if(ui->comboBox->currentIndex()==8)//geo
    {
        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->comboBox_brush->hide();
        ui->label_brush->hide();
        ui->lineEdit_PixelX->hide();
        ui->lineEdit_PixelX1->hide();
        ui->lineEdit_PixelY->hide();
        ui->lineEdit_PixelY1->hide();
        ui->label_an1->hide();
        ui->label_an2->hide();
        ui->lineEdit_spAngle->hide();
        ui->lineEdit_stAngle->hide();

        ui->lineEdit_PixelX->clear();
        ui->lineEdit_PixelY->clear();
        ui->lineEdit_PixelX1->clear();
        ui->lineEdit_PixelY1->clear();
        ui->lineEdit_spAngle->clear();
        ui->lineEdit_stAngle->clear();
        ui->comboBox_pen->setCurrentIndex(1);
        ui->comboBox_brush->setCurrentIndex(0);
        ui->horizontalSlider_penW->setValue(1);
    }
}

void MainWindow::on_horizontalSlider_penW_valueChanged(int value)
{
    ui->label_w->setNum(ui->horizontalSlider_penW->value());//отображение значения ширины карандаша
}

void MainWindow::on_pushButton_clicked()
{
    QColor color;
    color=QColorDialog::getColor(nullptr,nullptr,"Цвет фона");
    QPalette p(palette());
    p.setColor(QPalette::Background,color);//установка цвета фона
    ui->widget->setAutoFillBackground(true);
    ui->widget->setPalette(p);
    //ui->widget->setAutoFillBackground(false);
}

void MainWindow::on_comboBox_pen_currentIndexChanged(int )
{
    if(ui->comboBox_pen->currentIndex()==0)
    {
        ui->horizontalSlider_penW->setEnabled(false);
    }
    else
    {
        ui->horizontalSlider_penW->setEnabled(true);
    }
}
