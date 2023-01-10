#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pixel.h"
#include "line.h"
#include "rect.h"
#include "circle.h"
#include "arc.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(KOL_COL);
    ui->tableWidget->setRowCount(0);
    ui->widget->create_im(ui->widget->width(),ui->widget->height());//создание изображения
    ui->widget->im.fill(0);//очистка виджета
    ui->tableWidget->setColumnWidth(0,150);//настройки ширины 1 колонки
}

MainWindow::~MainWindow()
{
    delete ui;//деструктор
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    int need_rows = arg1*2;
    // на графический элемент по 2 строки
    int cur_rows=ui->tableWidget->rowCount();//считываем значение строчек
    int old_value=primitives.size();//старое значение
    int old_val=cur_rows/2;
    if (cur_rows<0)
        cur_rows=0;
    if(old_value!=arg1)
    {
        if (need_rows>cur_rows) //добавляем строки
        {
            ui->tableWidget->setRowCount(need_rows);
            int i =cur_rows;
            QTableWidgetItem * twi=nullptr;
            QComboBox * cb=nullptr;
            no_auto_change=true;//=======================================================================================
            while (i<need_rows)
            {
                twi = new QTableWidgetItem;
                twi->setText("Объект");
                twi->setFlags(twi->flags()&0xfffffffd);
                ui->tableWidget->setItem(i,0,twi);

                twi = new QTableWidgetItem;
                twi->setText("X");
                twi->setFlags(twi->flags()&0xfffffffd);
                ui->tableWidget->setItem(i,1,twi);

                twi = new QTableWidgetItem;
                twi->setText("Y");
                twi->setFlags(twi->flags()&0xfffffffd);
                ui->tableWidget->setItem(i,2,twi);

                twi = new QTableWidgetItem;
                twi->setText("Цвет точки");
                twi->setFlags(twi->flags()&0x3d);
                ui->tableWidget->setItem(i,3,twi);

                for (int j=4; j<KOL_COL;j++)
                {
                    twi = new QTableWidgetItem;
                    twi->setText("---");
                    twi->setFlags(twi->flags()&0x1d);
                    ui->tableWidget->setItem(i,j,twi);
                }

                i++;//переход на новую строчку

                cb =  new QComboBox;
                cb->addItem("Точка");
                cb->addItem("Линия");
                cb->addItem("Прямоугольник");
                cb->addItem("Эллипс");
                cb->addItem("Круг");
                cb->addItem("Дуга");
                cb->addItem("Ломанная");
                cb->addItem("Многоугольник");

                cb->setProperty("row",i);

                connect(cb,SIGNAL(activated(int)),this,SLOT(Combo_click(int)));
                connect(cb,SIGNAL(currentIndexChanged(int)),this,SLOT(Combo_click(int)));

                ui->tableWidget->setCellWidget(i,0,cb);

                //потому что по умолчанию выбирается режим точка
                twi = new QTableWidgetItem;
                twi->setText("0"); //или убираем
                ui->tableWidget->setItem(i,1,twi);

                twi = new QTableWidgetItem;
                twi->setText("0"); //или убираем
                ui->tableWidget->setItem(i,2,twi);

                QPushButton * pb = new QPushButton(this);
                pb->setText("Задать");
                pb->setProperty("row",i);
                connect(pb,SIGNAL(clicked()),this,SLOT(color_click()));

                ui->tableWidget->removeCellWidget(i,3);
                ui->tableWidget->setCellWidget(i,3,pb);

                for (int j=4; j<KOL_COL;j++)
                {
                    twi = new QTableWidgetItem;
                    twi->setText("---");
                    twi->setFlags(twi->flags()&0xffffffdd);
                    ui->tableWidget->setItem(i,j,twi);
                }


                i++;
            }
            no_auto_change=false;//=======================================================================================
            for (int i=old_value;i<arg1;i++)//добавляем строки по умолчанию пиксель
            {
                primitives.push_back(new pixel);
                primitives[i]->setType(Pixel);//устанавливаем тип
            }

        }
        else //удаляем строки
        {
            ui->tableWidget->setRowCount(need_rows);
            for(int i=arg1;i<old_value;i++)//удаляем последние стоки
            {
                primitives.erase(primitives.end() - 1);
                //drawAll();
            }
        }
    }


}


void MainWindow::Combo_click(int arg1)
{

    int row;
    QComboBox *cbox = qobject_cast<QComboBox*>(sender());//считываем положение активируемого комбобокса


    int index = cbox->property("row").toInt();
    int index1 = (cbox->property("row").toInt() - 1) / 2;
    auto k = 0;
    if (arg1 != primitives[index1]->getType())
    {
        switch (arg1) {
        // пиксель
        case 0: {
            primitives[index1] = new pixel();//создаём объект примитива - пиксель
            primitives[index1]->setType(Pixel);//установка типа

            break;
        }
            // линия
        case 1: {
            primitives[index1] = new line();//создаём объект примитива - линия
            primitives[index1]->setType(Line);

            break;
        }
            // прямоугольник
        case 2: {
            primitives[index1] = new class rect();//создаём объект примитива - прямоугольник
            primitives[index1]->setType(Rectangle);

            break;
        }
            // эллипс
        case 3: {
            primitives[index1] = new ellipse();//создаём объект примитива - эллипс
            primitives[index1]->setType(Ellipse);

            break;
        }
            // круг
        case 4: {
            primitives[index1] = new circle();//создаём объект примитива - круг
            primitives[index1]->setType(Circle);
            break;
        }
            // дуга
        case 5: {
            primitives[index1] = new class Arc();//создаём объект примитива - дуга
            primitives[index1]->setType(Arc);

            break;
        }
            // ломанная
        case 6: {
            primitives[index1] = new polyline();//создаём объект примитива - ломанная
            primitives[index1]->setType(Curve);

            break;
        }
        case 7:
        {
            primitives[index1]=new polygon();//создаём объект примитива - многоугольник
            primitives[index1]->setType(Polygon);
        }
        }

    }



    if (cbox!=NULL)
    {
        row = cbox->property("row").toInt();//проверка значения
        QTableWidgetItem * twi;

        //int indx = (row-1)/2;
        no_auto_change=true;
        switch (arg1)
        {

        case 0: //точка
        {
            int rowm=row-1;

            //строка подписей
            twi = new QTableWidgetItem;
            twi->setText("X");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,1);
            ui->tableWidget->setItem(rowm,1,twi);

            twi = new QTableWidgetItem;
            twi->setText("Y");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,2);
            ui->tableWidget->setItem(rowm,2,twi);

            twi = new QTableWidgetItem;
            twi->setText("Цвет точки");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,3);
            ui->tableWidget->setItem(rowm,3,twi);

            for (int j=4; j<KOL_COL;j++)
            {
                twi = new QTableWidgetItem;
                twi->setText("---");
                twi->setFlags(twi->flags()&0xffffffdd);
                ui->tableWidget->removeCellWidget(rowm,j);
                ui->tableWidget->setItem(rowm,j,twi);
            }


            //строка значений
            twi = new QTableWidgetItem;
            twi->setText("0"); //или убираем
            ui->tableWidget->removeCellWidget(row,1);
            ui->tableWidget->setItem(row,1,twi);

            twi = new QTableWidgetItem;
            twi->setText("0"); //или убираем
            ui->tableWidget->removeCellWidget(row,2);
            ui->tableWidget->setItem(row,2,twi);

            QPushButton * pb = new QPushButton(this);
            pb->setText("Задать");
            pb->setProperty("row",row);
            connect(pb,SIGNAL(clicked()),this,SLOT(color_click()));

            ui->tableWidget->removeCellWidget(row,3);
            ui->tableWidget->setCellWidget(row,3,pb);

            for (int j=4; j<KOL_COL;j++)
            {
                twi = new QTableWidgetItem;
                twi->setText("---");
                twi->setFlags(twi->flags()&0xffffffdd);
                ui->tableWidget->removeCellWidget(row,j);
                ui->tableWidget->setItem(row,j,twi);
            }

            break;
        }
        case 1: //линия
        {
            int rowm=row-1;

            //строка подписей
            twi = new QTableWidgetItem;
            twi->setText("X1");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,1);
            ui->tableWidget->setItem(rowm,1,twi);

            twi = new QTableWidgetItem;
            twi->setText("Y1");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,2);
            ui->tableWidget->setItem(rowm,2,twi);

            twi = new QTableWidgetItem;
            twi->setText("X2");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,3);
            ui->tableWidget->setItem(rowm,3,twi);

            twi = new QTableWidgetItem;
            twi->setText("Y2");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,4);
            ui->tableWidget->setItem(rowm,4,twi);

            twi = new QTableWidgetItem;
            twi->setText("Цвет линии");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,5);
            ui->tableWidget->setItem(rowm,5,twi);


            for (int j=6; j<KOL_COL;j++)
            {
                twi = new QTableWidgetItem;
                twi->setText("---");
                twi->setFlags(twi->flags()&0xffffffdd);
                ui->tableWidget->removeCellWidget(rowm,j);
                ui->tableWidget->setItem(rowm,j,twi);
            }


            //строка значений
            twi = new QTableWidgetItem;
            twi->setText("0"); //или убираем
            ui->tableWidget->removeCellWidget(row,1);
            ui->tableWidget->setItem(row,1,twi);

            twi = new QTableWidgetItem;
            twi->setText("0"); //или убираем
            ui->tableWidget->removeCellWidget(row,2);
            ui->tableWidget->setItem(row,2,twi);

            twi = new QTableWidgetItem;
            twi->setText("0"); //или убираем
            ui->tableWidget->removeCellWidget(row,3);
            ui->tableWidget->setItem(row,3,twi);

            twi = new QTableWidgetItem;
            twi->setText("0"); //или убираем
            ui->tableWidget->removeCellWidget(row,4);
            ui->tableWidget->setItem(row,4,twi);

            QPushButton * pb = new QPushButton(this);
            pb->setText("Задать");
            pb->setProperty("row",row);
            connect(pb,SIGNAL(clicked()),this,SLOT(color_click()));

            ui->tableWidget->removeCellWidget(row,5);
            ui->tableWidget->setCellWidget(row,5,pb);

            for (int j=6; j<KOL_COL;j++)
            {
                twi = new QTableWidgetItem;
                twi->setText("---");
                twi->setFlags(twi->flags()&0xffffffdd);
                ui->tableWidget->removeCellWidget(row,j);
                ui->tableWidget->setItem(row,j,twi);
            }

            break;
        }
        case 2: //прямоугольник
        {
            int rowm=row-1;

            //строка подписей
            twi = new QTableWidgetItem;
            twi->setText("X1");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,1);
            ui->tableWidget->setItem(rowm,1,twi);

            twi = new QTableWidgetItem;
            twi->setText("Y1");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,2);
            ui->tableWidget->setItem(rowm,2,twi);

            twi = new QTableWidgetItem;
            twi->setText("Ширина");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,3);
            ui->tableWidget->setItem(rowm,3,twi);

            twi = new QTableWidgetItem;
            twi->setText("Высота");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,4);
            ui->tableWidget->setItem(rowm,4,twi);


            twi = new QTableWidgetItem;
            twi->setText("Цвет линии");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,5);
            ui->tableWidget->setItem(rowm,5,twi);

            twi = new QTableWidgetItem;
            twi->setText("Цвет заливки");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,6);
            ui->tableWidget->setItem(rowm,6,twi);




            twi = new QTableWidgetItem;
            twi->setText("---");
            twi->setFlags(twi->flags()&0xffffffdd);
            ui->tableWidget->removeCellWidget(rowm,7);
            ui->tableWidget->setItem(rowm,7,twi);



            //строка значений
            twi = new QTableWidgetItem;
            twi->setText("0"); //или убираем
            ui->tableWidget->removeCellWidget(row,1);
            ui->tableWidget->setItem(row,1,twi);

            twi = new QTableWidgetItem;
            twi->setText("0"); //или убираем
            ui->tableWidget->removeCellWidget(row,2);
            ui->tableWidget->setItem(row,2,twi);

            twi = new QTableWidgetItem;
            twi->setText("0"); //или убираем
            ui->tableWidget->removeCellWidget(row,3);
            ui->tableWidget->setItem(row,3,twi);

            twi = new QTableWidgetItem;
            twi->setText("0"); //или убираем
            ui->tableWidget->removeCellWidget(row,4);
            ui->tableWidget->setItem(row,4,twi);

            QPushButton * pb = new QPushButton(this);
            pb->setText("Задать");
            pb->setProperty("row",row);
            connect(pb,SIGNAL(clicked()),this,SLOT(color_click()));
            ui->tableWidget->removeCellWidget(row,5);
            ui->tableWidget->setCellWidget(row,5,pb);

            pb= new QPushButton(this);
            pb->setText("Задать");
            pb->setProperty("row",row);
            connect(pb,SIGNAL(clicked()),this,SLOT(color_click_br())); //отдельный слот под заливку
            ui->tableWidget->removeCellWidget(row,6);
            ui->tableWidget->setCellWidget(row,6,pb);



            twi = new QTableWidgetItem;
            twi->setText("---");
            twi->setFlags(twi->flags()&0xffffffdd);
            ui->tableWidget->removeCellWidget(row,7);
            ui->tableWidget->setItem(row,7,twi);
            break;
        }
        case 6: //ломанная
        {
            int rowm=row-1;


            twi = new QTableWidgetItem;
            twi->setText("Цвет линии");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,2);
            ui->tableWidget->setItem(rowm,2,twi);

            twi = new QTableWidgetItem;
            twi->setText("Задать точки");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,1);
            ui->tableWidget->setItem(rowm,1,twi);

            for (int j=3; j<KOL_COL;j++)
            {
                twi = new QTableWidgetItem;
                twi->setText("---");
                twi->setFlags(twi->flags()&0xffffffdd);
                ui->tableWidget->removeCellWidget(rowm,j);
                ui->tableWidget->setItem(rowm,j,twi);
            }

            QPushButton * pb = new QPushButton(this);
            pb->setText("Задать");
            pb->setProperty("row",row);
            connect(pb,SIGNAL(clicked()),this,SLOT(color_click()));

            ui->tableWidget->removeCellWidget(row,2);
            ui->tableWidget->setCellWidget(row,2,pb);

            pb = new QPushButton(this);
            pb->setText("Точки");
            pb->setProperty("row",row);
            connect(pb,SIGNAL(clicked()),this,SLOT(points_click()));

            ui->tableWidget->removeCellWidget(row,1);
            ui->tableWidget->setCellWidget(row,1,pb);

            for (int j=3; j<KOL_COL;j++)
            {
                twi = new QTableWidgetItem;
                twi->setText("---");
                twi->setFlags(twi->flags()&0xffffffdd);
                ui->tableWidget->removeCellWidget(row,j);
                ui->tableWidget->setItem(row,j,twi);
            }

            break;
        }
        case 3://эллипс
        {
            int rowm=row-1;

            //строка подписей
            twi = new QTableWidgetItem;
            twi->setText("X");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,1);
            ui->tableWidget->setItem(rowm,1,twi);

            twi = new QTableWidgetItem;
            twi->setText("Y");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,2);
            ui->tableWidget->setItem(rowm,2,twi);

            twi = new QTableWidgetItem;
            twi->setText("Радиус 1");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,3);
            ui->tableWidget->setItem(rowm,3,twi);

            twi = new QTableWidgetItem;
            twi->setText("Радиус 2");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,4);
            ui->tableWidget->setItem(rowm,4,twi);


            twi = new QTableWidgetItem;
            twi->setText("Цвет линии");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,5);
            ui->tableWidget->setItem(rowm,5,twi);

            twi = new QTableWidgetItem;
            twi->setText("Цвет заливки");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,6);
            ui->tableWidget->setItem(rowm,6,twi);




            twi = new QTableWidgetItem;
            twi->setText("---");
            twi->setFlags(twi->flags()&0xffffffdd);
            ui->tableWidget->removeCellWidget(rowm,7);
            ui->tableWidget->setItem(rowm,7,twi);



            //строка значений
            twi = new QTableWidgetItem;
            twi->setText("0"); //или убираем
            ui->tableWidget->removeCellWidget(row,1);
            ui->tableWidget->setItem(row,1,twi);

            twi = new QTableWidgetItem;
            twi->setText("0"); //или убираем
            ui->tableWidget->removeCellWidget(row,2);
            ui->tableWidget->setItem(row,2,twi);

            twi = new QTableWidgetItem;
            twi->setText("0"); //или убираем
            ui->tableWidget->removeCellWidget(row,3);
            ui->tableWidget->setItem(row,3,twi);

            twi = new QTableWidgetItem;
            twi->setText("0"); //или убираем
            ui->tableWidget->removeCellWidget(row,4);
            ui->tableWidget->setItem(row,4,twi);

            QPushButton * pb = new QPushButton(this);
            pb->setText("Задать");
            pb->setProperty("row",row);
            connect(pb,SIGNAL(clicked()),this,SLOT(color_click()));
            ui->tableWidget->removeCellWidget(row,5);
            ui->tableWidget->setCellWidget(row,5,pb);

            pb= new QPushButton(this);
            pb->setText("Задать");
            pb->setProperty("row",row);
            connect(pb,SIGNAL(clicked()),this,SLOT(color_click_br())); //отдельный слот под заливку
            ui->tableWidget->removeCellWidget(row,6);
            ui->tableWidget->setCellWidget(row,6,pb);



            twi = new QTableWidgetItem;
            twi->setText("---");
            twi->setFlags(twi->flags()&0xffffffdd);
            ui->tableWidget->removeCellWidget(row,7);
            ui->tableWidget->setItem(row,7,twi);
            break;
        }
        case 4://круг
        {
            int rowm=row-1;

            //строка подписей
            twi = new QTableWidgetItem;
            twi->setText("X");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,1);
            ui->tableWidget->setItem(rowm,1,twi);

            twi = new QTableWidgetItem;
            twi->setText("Y");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,2);
            ui->tableWidget->setItem(rowm,2,twi);

            twi = new QTableWidgetItem;
            twi->setText("Радиус ");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,3);
            ui->tableWidget->setItem(rowm,3,twi);



            twi = new QTableWidgetItem;
            twi->setText("Цвет линии");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,4);
            ui->tableWidget->setItem(rowm,4,twi);

            twi = new QTableWidgetItem;
            twi->setText("Цвет заливки");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,5);
            ui->tableWidget->setItem(rowm,5,twi);



            for (int i=6;i<KOL_COL;i++)
            {
                twi = new QTableWidgetItem;
                twi->setText("---");
                twi->setFlags(twi->flags()&0xffffffdd);
                ui->tableWidget->removeCellWidget(rowm,i);
                ui->tableWidget->setItem(rowm,i,twi);
            }




            //строка значений
            twi = new QTableWidgetItem;
            twi->setText("0"); //или убираем
            ui->tableWidget->removeCellWidget(row,1);
            ui->tableWidget->setItem(row,1,twi);

            twi = new QTableWidgetItem;
            twi->setText("0"); //или убираем
            ui->tableWidget->removeCellWidget(row,2);
            ui->tableWidget->setItem(row,2,twi);

            twi = new QTableWidgetItem;
            twi->setText("0"); //или убираем
            ui->tableWidget->removeCellWidget(row,3);
            ui->tableWidget->setItem(row,3,twi);


            QPushButton * pb = new QPushButton(this);
            pb->setText("Задать");
            pb->setProperty("row",row);
            connect(pb,SIGNAL(clicked()),this,SLOT(color_click()));
            ui->tableWidget->removeCellWidget(row,4);
            ui->tableWidget->setCellWidget(row,4,pb);

            pb= new QPushButton(this);
            pb->setText("Задать");
            pb->setProperty("row",row);
            connect(pb,SIGNAL(clicked()),this,SLOT(color_click_br())); //отдельный слот под заливку
            ui->tableWidget->removeCellWidget(row,5);
            ui->tableWidget->setCellWidget(row,5,pb);


            for (int i=6;i<KOL_COL;i++)
            {
                twi = new QTableWidgetItem;
                twi->setText("---");
                twi->setFlags(twi->flags()&0xffffffdd);
                ui->tableWidget->removeCellWidget(row,i);
                ui->tableWidget->setItem(row,i,twi);
            }

            break;
        }
        case 5://дуга
        {
            int rowm=row-1;

            //строка подписей
            twi = new QTableWidgetItem;
            twi->setText("X");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,1);
            ui->tableWidget->setItem(rowm,1,twi);

            twi = new QTableWidgetItem;
            twi->setText("Y");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,2);
            ui->tableWidget->setItem(rowm,2,twi);

            twi = new QTableWidgetItem;
            twi->setText("Радиус 1");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,3);
            ui->tableWidget->setItem(rowm,3,twi);

            twi = new QTableWidgetItem;
            twi->setText("Радиус 2");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,4);
            ui->tableWidget->setItem(rowm,4,twi);


            twi = new QTableWidgetItem;
            twi->setText("Нач.угол");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,5);
            ui->tableWidget->setItem(rowm,5,twi);

            twi = new QTableWidgetItem;
            twi->setText("Угол охвата");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,6);
            ui->tableWidget->setItem(rowm,6,twi);




            twi = new QTableWidgetItem;
            twi->setText("Цвет линии");
            twi->setFlags(twi->flags()&0x3d);
            ui->tableWidget->removeCellWidget(rowm,7);
            ui->tableWidget->setItem(rowm,7,twi);



            //строка значений
            twi = new QTableWidgetItem;
            twi->setText("0"); //или убираем
            ui->tableWidget->removeCellWidget(row,1);
            ui->tableWidget->setItem(row,1,twi);

            twi = new QTableWidgetItem;
            twi->setText("0"); //или убираем
            ui->tableWidget->removeCellWidget(row,2);
            ui->tableWidget->setItem(row,2,twi);

            twi = new QTableWidgetItem;
            twi->setText("0"); //или убираем
            ui->tableWidget->removeCellWidget(row,3);
            ui->tableWidget->setItem(row,3,twi);

            twi = new QTableWidgetItem;
            twi->setText("0"); //или убираем
            ui->tableWidget->removeCellWidget(row,4);
            ui->tableWidget->setItem(row,4,twi);

            twi = new QTableWidgetItem;
            twi->setText("0"); //или убираем
            ui->tableWidget->removeCellWidget(row,5);
            ui->tableWidget->setItem(row,5,twi);

            twi = new QTableWidgetItem;
            twi->setText("0"); //или убираем
            ui->tableWidget->removeCellWidget(row,6);
            ui->tableWidget->setItem(row,6,twi);

            QPushButton * pb = new QPushButton(this);
            pb->setText("Задать");
            pb->setProperty("row",row);
            connect(pb,SIGNAL(clicked()),this,SLOT(color_click()));
            ui->tableWidget->removeCellWidget(row,7);
            ui->tableWidget->setCellWidget(row,7,pb);

            break;
        }
        case 7://многоугольник
        {
            int rowm=row-1;


            twi = new QTableWidgetItem;
            twi->setText("Задать точки");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,1);
            ui->tableWidget->setItem(rowm,1,twi);

            twi = new QTableWidgetItem;
            twi->setText("Цвет линии");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,2);
            ui->tableWidget->setItem(rowm,2,twi);

            twi = new QTableWidgetItem;
            twi->setText("Цвет заливки");
            twi->setFlags(twi->flags()&0xfffffffd);
            ui->tableWidget->removeCellWidget(rowm,2);
            ui->tableWidget->setItem(rowm,3,twi);

            for (int j=4; j<KOL_COL;j++)
            {
                twi = new QTableWidgetItem;
                twi->setText("---");
                twi->setFlags(twi->flags()&0xffffffdd);
                ui->tableWidget->removeCellWidget(rowm,j);
                ui->tableWidget->setItem(rowm,j,twi);
            }

            QPushButton * pb = new QPushButton(this);
            pb->setText("Задать");
            pb->setProperty("row",row);
            connect(pb,SIGNAL(clicked()),this,SLOT(color_click()));

            ui->tableWidget->removeCellWidget(row,2);
            ui->tableWidget->setCellWidget(row,2,pb);

            pb = new QPushButton(this);
            pb->setText("Точки");
            pb->setProperty("row",row);
            connect(pb,SIGNAL(clicked()),this,SLOT(points_click()));

            ui->tableWidget->removeCellWidget(row,1);
            ui->tableWidget->setCellWidget(row,1,pb);

            pb = new QPushButton(this);
            pb->setText("Задать");
            pb->setProperty("row",row);
            connect(pb,SIGNAL(clicked()),this,SLOT(color_click_br()));

            ui->tableWidget->removeCellWidget(row,3);
            ui->tableWidget->setCellWidget(row,3,pb);

            for (int j=4; j<KOL_COL;j++)
            {
                twi = new QTableWidgetItem;
                twi->setText("---");
                twi->setFlags(twi->flags()&0xffffffdd);
                ui->tableWidget->removeCellWidget(row,j);
                ui->tableWidget->setItem(row,j,twi);
            }

            break;
        }
        }
        no_auto_change=false;
    }
    //drawAll();//рисуем
}


void MainWindow::color_click()
{
    QPushButton * pb = qobject_cast<QPushButton *>(sender());//считываем положение активируемого пушбатона
    int row=pb->property("row").toInt();

    int indx=(row-1)/2;
    Dialog dial;

    QComboBox * cb = qobject_cast<QComboBox *>(ui->tableWidget->cellWidget(row,0));

    dial.setStyleVisible(cb->currentIndex()!=0);

    my_pen pen;
    //получить предыдущие значения стиля

    int a,r,g,b,w;
    Primitive * prim = primitives[indx];
    switch (prim->getType())
    {
    case Pixel:
    {
        pixel *obj=static_cast<pixel *>(prim);
        obj->GetColor(r,g,b,a);
        pen.SetColor(r,g,b,a);
        pen.SetW(obj->GetW());
        dial.setValue(pen);
        dial.exec();
        dial.GetColor(r,g,b,a);
        obj->SetW(dial.GetW());
        obj->SetColor(r,g,b,a);
        break;
    }
    case Line:
    {
        line *obj=static_cast<line *>(prim);
        obj->GetColor(r,g,b,a);
        pen.SetColor(r,g,b,a);
        pen.SetStyle(obj->GetStyle());
        pen.SetW(obj->GetW());
        dial.setValue(pen);
        dial.exec();
        dial.GetColor(r,g,b,a);
        obj->SetColor(r,g,b,a);
        obj->SetStyle(dial.GetStyle());
        obj->SetW(dial.GetW());
        break;
    }
    case Rectangle: {
        class rect * obj = static_cast<class rect *>(prim);
        obj->gran.GetColor(r,g,b,a);
        pen.SetColor(r,g,b,a);
        pen.SetStyle(obj->gran.GetStyle());
        pen.SetW(obj->gran.GetW());
        dial.setValue(pen);
        dial.exec();
        dial.GetColor(r,g,b,a);
        obj->gran.SetColor(r,g,b,a);
        obj->gran.SetStyle(dial.GetStyle());
        obj->gran.SetW(dial.GetW());

        break;
    }
    case Ellipse: {
        ellipse * obj = static_cast<ellipse *>(prim);
        obj->gran.GetColor(r,g,b,a);
        pen.SetColor(r,g,b,a);
        pen.SetStyle(obj->gran.GetStyle());
        pen.SetW(obj->gran.GetW());
        dial.setValue(pen);
        dial.exec();
        dial.GetColor(r,g,b,a);
        obj->gran.SetColor(r,g,b,a);
        obj->gran.SetStyle(dial.GetStyle());
        obj->gran.SetW(dial.GetW());

        break;
    }
    case Circle:
    {
        circle *obj=static_cast<circle *>(prim);
        obj->gran.GetColor(r,g,b,a);
        pen.SetColor(r,g,b,a);
        pen.SetStyle(obj->gran.GetStyle());
        pen.SetW(obj->gran.GetW());
        dial.setValue(pen);
        dial.exec();
        dial.GetColor(r,g,b,a);
        obj->gran.SetColor(r,g,b,a);
        obj->gran.SetStyle(dial.GetStyle());
        obj->gran.SetW(dial.GetW());

        break;

    }
    case Arc:
    {
        class Arc *obj=static_cast<class Arc *>(prim);
        obj->GetColor(r,g,b,a);
        pen.SetColor(r,g,b,a);
        pen.SetStyle(obj->GetStyle());
        pen.SetW(obj->GetW());
        dial.setValue(pen);
        dial.exec();
        dial.GetColor(r,g,b,a);
        obj->SetColor(r,g,b,a);
        obj->SetStyle(dial.GetStyle());
        obj->SetW(dial.GetW());
        break;
    }
    case Curve:
    {
        polyline *obj =static_cast<polyline *>(prim);
        obj->gran.GetColor(r,g,b,a);
        pen.SetColor(r,g,b,a);
        pen.SetStyle(obj->gran.GetStyle());
        pen.SetW(obj->gran.GetW());
        dial.setValue(pen);
        dial.exec();
        dial.GetColor(r,g,b,a);
        obj->gran.SetColor(r,g,b,a);
        obj->gran.SetStyle(dial.GetStyle());
        obj->gran.SetW(dial.GetW());
        break;
    }
    case Polygon:
    {
        polygon *obj =static_cast<polygon *>(prim);
        obj->gran.GetColor(r,g,b,a);
        pen.SetColor(r,g,b,a);
        pen.SetStyle(obj->gran.GetStyle());
        pen.SetW(obj->gran.GetW());
        dial.setValue(pen);
        dial.exec();
        dial.GetColor(r,g,b,a);
        obj->gran.SetColor(r,g,b,a);
        obj->gran.SetStyle(dial.GetStyle());
        obj->gran.SetW(dial.GetW());
        break;
    }
    }
    //drawAll();//рисуем всё

}
void MainWindow::color_click_br(void)
{
    QPushButton * pb = qobject_cast<QPushButton *>(sender());//считываем положение активируемого пушбатона
    int row=pb->property("row").toInt();
    int a,r,b,g;

    int indx=(row-1)/2;
    Dialog_brush dial;

    QComboBox * cb = qobject_cast<QComboBox *>(ui->tableWidget->cellWidget(row,0));

    my_brush brush;
    Primitive * prim = primitives[indx];
    auto f = prim->getType();
    switch (prim->getType())
    {
    case Rectangle: {
        class rect * obj = static_cast<class rect *>(prim);
        obj->zal.GetColor(r,g,b,a);
        brush.SetColor(r,g,b,a);
        brush.SetStyle(obj->zal.GetStyle());
        dial.setValue(brush);
        dial.exec();
        dial.GetColor(r,g,b,a);
        obj->zal.SetColor(r,g,b,a);
        obj->zal.SetStyle(dial.GetStyle());

        break;
    }
    case Ellipse: {
        ellipse * obj = static_cast<ellipse *>(prim);
        obj->zal.GetColor(r,g,b,a);
        brush.SetColor(r,g,b,a);
        brush.SetStyle(obj->zal.GetStyle());
        dial.setValue(brush);
        dial.exec();
        dial.GetColor(r,g,b,a);
        obj->zal.SetColor(r,g,b,a);
        obj->zal.SetStyle(dial.GetStyle());

        break;
    }
    case Circle:
    {
        circle *obj=static_cast<circle *>(prim);
        obj->zal.GetColor(r,g,b,a);
        brush.SetColor(r,g,b,a);
        brush.SetStyle(obj->zal.GetStyle());
        dial.setValue(brush);
        dial.exec();
        dial.GetColor(r,g,b,a);
        obj->zal.SetColor(r,g,b,a);
        obj->zal.SetStyle(dial.GetStyle());

        break;

    }
    case Polygon:
    {
        polygon *obj=static_cast<polygon *>(prim);
        obj->zal.GetColor(r,g,b,a);
        brush.SetColor(r,g,b,a);
        brush.SetStyle(obj->zal.GetStyle());
        dial.setValue(brush);
        dial.exec();
        dial.GetColor(r,g,b,a);
        obj->zal.SetColor(r,g,b,a);
        obj->zal.SetStyle(dial.GetStyle());
        break;
    }
    default:
    {};
    }

    //drawAll();//рисуем всё
}

void MainWindow::points_click()
{
    QPushButton * cbox = qobject_cast<QPushButton *>(sender());//считываем положение активируемого пушбатона
    if (cbox != nullptr)
    {
        int row = cbox->property("row").toInt();
        int indx=(row-1)/2;
        // Вызов диалога
        Dialog_points dialog(this);
        dialog.OpenD(primitives[indx]->getPoints());

        // Рисуем всё
        //drawAll();
    }
}

void MainWindow::on_pushButtonSave_clicked()
{
    int rown,column;
    bool fl;
    rown=ui->tableWidget->rowCount();
    column=ui->tableWidget->columnCount();
    QFile file;
    QString fileName;
    fileName=QFileDialog::getSaveFileName(this,tr("Сохранить как bin"),"","Binary files (*.bin)");
    if (fileName.isEmpty())
    {
        QMessageBox::information(this,"Ошибка","Файл не выбран");
    }
    else
    {
        file.setFileName(fileName);
        char * mas = new char[sizeof(int)];
        file.open(QIODevice::WriteOnly);
        int x=0,y=0,r1=0,r2=0,st=0,sp=0;

        int size_new=primitives.size();
        int type;
        memcpy(mas,&size_new,sizeof(int));
        file.write(mas,sizeof(int));
        for (int i=0;i<size_new;i++)
        {
            // Сохранение каждого отдельного примитива
            Primitive * prim = primitives[i];
            type=primitives[i]->getType();//считываем тип
            memcpy(mas,&type,sizeof(int));
            file.write(mas,sizeof(int));
            switch (type)
            {
            case Pixel:
            {
                pixel *obj=static_cast<pixel *>(prim);
                x=obj->GetX();
                memcpy(mas,&x,sizeof(int)); //X
                file.write(mas,sizeof(int));

                y=obj->GetY();
                memcpy(mas,&y,sizeof(int)); //Y
                file.write(mas,sizeof(int));

                int a,r,g,b,w;
                obj->GetColor(r,g,b,a);
                memcpy(mas,&r,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&g,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&b,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&a,sizeof(int));
                file.write(mas,sizeof(int));
                w=obj->GetW();
                memcpy(mas,&w,sizeof(int));
                file.write(mas,sizeof(int));

                break;
            }
            case Line:
            {
                line *obj=static_cast<line *>(prim);
                x=obj->start.GetX();
                memcpy(mas,&x,sizeof(int)); //X1
                file.write(mas,sizeof(int));

                y=obj->start.GetY();
                memcpy(mas,&y,sizeof(int)); //Y1
                file.write(mas,sizeof(int));

                x=obj->end.GetX();
                memcpy(mas,&x,sizeof(int)); //X2
                file.write(mas,sizeof(int));

                y=obj->end.GetY();
                memcpy(mas,&y,sizeof(int)); //Y2
                file.write(mas,sizeof(int));

                int a,r,g,b,st,w;
                obj->GetColor(r,g,b,a);
                memcpy(mas,&r,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&g,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&b,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&a,sizeof(int));
                file.write(mas,sizeof(int));

                st=obj->GetStyle();
                memcpy(mas,&st,sizeof(int));
                file.write(mas,sizeof(int));

                w=obj->GetW();
                memcpy(mas,&w,sizeof(int));
                file.write(mas,sizeof(int));

                break;
            }
            case Rectangle: {
                class rect * obj = static_cast<class rect *>(prim);
                x=obj->point.GetX();
                memcpy(mas,&x,sizeof(int)); //X1
                file.write(mas,sizeof(int));

                y=obj->point.GetY();
                memcpy(mas,&y,sizeof(int)); //Y1
                file.write(mas,sizeof(int));

                y=obj->GetWeight();
                memcpy(mas,&y,sizeof(int)); //Ширина
                file.write(mas,sizeof(int));

                x=obj->GetHeight();
                memcpy(mas,&x,sizeof(int)); //Высота
                file.write(mas,sizeof(int));


                int a,r,g,b,st,w;
                //карандаш==============================
                obj->gran.GetColor(r,g,b,a);
                memcpy(mas,&r,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&g,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&b,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&a,sizeof(int));
                file.write(mas,sizeof(int));

                st=obj->gran.GetStyle();
                memcpy(mas,&st,sizeof(int));
                file.write(mas,sizeof(int));
                w=obj->gran.GetW();
                memcpy(mas,&w,sizeof(int));
                file.write(mas,sizeof(int));
                //заливка===============================
                obj->zal.GetColor(r,g,b,a);
                memcpy(mas,&r,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&g,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&b,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&a,sizeof(int));
                file.write(mas,sizeof(int));

                st=obj->zal.GetStyle();
                memcpy(mas,&st,sizeof(int));
                file.write(mas,sizeof(int));

                break;
            }
            case Ellipse: {
                ellipse * obj = static_cast<ellipse *>(prim);
                x=obj->center.GetX();
                memcpy(mas,&x,sizeof(int)); //X1
                file.write(mas,sizeof(int));

                y=obj->center.GetY();
                memcpy(mas,&y,sizeof(int)); //Y1
                file.write(mas,sizeof(int));

                y=obj->GetRadius1();
                memcpy(mas,&y,sizeof(int)); //Ширина
                file.write(mas,sizeof(int));

                x=obj->GetRadius2();
                memcpy(mas,&x,sizeof(int)); //Высота
                file.write(mas,sizeof(int));


                int a,r,g,b,st,w;
                //карандаш==============================
                obj->gran.GetColor(r,g,b,a);
                memcpy(mas,&r,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&g,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&b,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&a,sizeof(int));
                file.write(mas,sizeof(int));

                st=obj->gran.GetStyle();
                memcpy(mas,&st,sizeof(int));
                file.write(mas,sizeof(int));
                w=obj->gran.GetW();
                memcpy(mas,&w,sizeof(int));
                file.write(mas,sizeof(int));
                //заливка===============================
                obj->zal.GetColor(r,g,b,a);
                memcpy(mas,&r,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&g,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&b,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&a,sizeof(int));
                file.write(mas,sizeof(int));

                st=obj->zal.GetStyle();
                memcpy(mas,&st,sizeof(int));
                file.write(mas,sizeof(int));

                break;
            }
            case Circle:
            {
                circle *obj=static_cast<circle *>(prim);
                x=obj->center.GetX();
                memcpy(mas,&x,sizeof(int)); //X1
                file.write(mas,sizeof(int));

                y=obj->center.GetY();
                memcpy(mas,&y,sizeof(int)); //Y1
                file.write(mas,sizeof(int));

                y=obj->GetRadius();
                memcpy(mas,&y,sizeof(int)); //Ширина
                file.write(mas,sizeof(int));

                int a,r,g,b,st,w;
                //карандаш==============================
                obj->gran.GetColor(r,g,b,a);
                memcpy(mas,&r,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&g,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&b,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&a,sizeof(int));
                file.write(mas,sizeof(int));

                st=obj->gran.GetStyle();
                memcpy(mas,&st,sizeof(int));
                file.write(mas,sizeof(int));
                w=obj->gran.GetW();
                memcpy(mas,&w,sizeof(int));
                file.write(mas,sizeof(int));
                //заливка===============================
                obj->zal.GetColor(r,g,b,a);
                memcpy(mas,&r,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&g,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&b,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&a,sizeof(int));
                file.write(mas,sizeof(int));

                st=obj->zal.GetStyle();
                memcpy(mas,&st,sizeof(int));
                file.write(mas,sizeof(int));

                break;

            }
            case Arc:
            {
                class Arc *obj=static_cast<class Arc *>(prim);
                x=obj->begin.GetX();
                memcpy(mas,&x,sizeof(int)); //X1
                file.write(mas,sizeof(int));

                y=obj->begin.GetY();
                memcpy(mas,&y,sizeof(int)); //Y1
                file.write(mas,sizeof(int));

                y=obj->GetRadius1();
                memcpy(mas,&y,sizeof(int)); //Радиус1
                file.write(mas,sizeof(int));

                y=obj->GetRadius2();
                memcpy(mas,&y,sizeof(int)); //Радиус2
                file.write(mas,sizeof(int));

                y=obj->GetStartAngle();
                memcpy(mas,&y,sizeof(int)); //Начальный угол
                file.write(mas,sizeof(int));

                y=obj->GetSpanAngle();
                memcpy(mas,&y,sizeof(int)); //Угол охвата
                file.write(mas,sizeof(int));

                int a,r,g,b,st,w;
                //карандаш==============================
                obj->GetColor(r,g,b,a);
                memcpy(mas,&r,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&g,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&b,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&a,sizeof(int));
                file.write(mas,sizeof(int));

                st=obj->GetStyle();
                memcpy(mas,&st,sizeof(int));
                file.write(mas,sizeof(int));
                w=obj->GetW();
                memcpy(mas,&w,sizeof(int));
                file.write(mas,sizeof(int));
                break;
            }
            case Curve:
            {
                polyline *obj =static_cast<polyline *>(prim);
                int size;
                MainPoints = obj->getPoints();
                size=MainPoints->size();
                memcpy(mas,&size,sizeof(int)); //кол во точек
                file.write(mas,sizeof(int));
                for (int i=0;i<size;i++)
                {
                    x=(*MainPoints)[i].GetX();
                    y=(*MainPoints)[i].GetY();
                    memcpy(mas,&x,sizeof(int)); //X
                    file.write(mas,sizeof(int));
                    memcpy(mas,&y,sizeof(int)); //Y
                    file.write(mas,sizeof(int));
                }
                int a,r,g,b,st,w;
                //карандаш==============================
                obj->GetColor(r,g,b,a);
                memcpy(mas,&r,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&g,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&b,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&a,sizeof(int));
                file.write(mas,sizeof(int));

                st=obj->gran.GetStyle();
                memcpy(mas,&st,sizeof(int));
                file.write(mas,sizeof(int));
                w=obj->gran.GetW();
                memcpy(mas,&w,sizeof(int));
                file.write(mas,sizeof(int));

                break;
            }
            case Polygon:
            {
                polygon *obj =static_cast<polygon *>(prim);
                int size;
                MainPointsPl = obj->getPoints();
                size=MainPointsPl->size();
                memcpy(mas,&size,sizeof(int)); //кол во точек
                file.write(mas,sizeof(int));
                for (int i=0;i<size;i++)
                {
                    x=(*MainPointsPl)[i].GetX();
                    y=(*MainPointsPl)[i].GetY();
                    memcpy(mas,&x,sizeof(int)); //X
                    file.write(mas,sizeof(int));
                    memcpy(mas,&y,sizeof(int)); //Y
                    file.write(mas,sizeof(int));
                }
                int a,r,g,b,st,w;
                //карандаш==============================
                obj->GetColor(r,g,b,a);
                memcpy(mas,&r,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&g,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&b,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&a,sizeof(int));
                file.write(mas,sizeof(int));

                st=obj->gran.GetStyle();
                memcpy(mas,&st,sizeof(int));
                file.write(mas,sizeof(int));
                w=obj->gran.GetW();
                memcpy(mas,&w,sizeof(int));
                file.write(mas,sizeof(int));
                //заливка===============================
                obj->zal.GetColor(r,g,b,a);
                memcpy(mas,&r,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&g,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&b,sizeof(int));
                file.write(mas,sizeof(int));
                memcpy(mas,&a,sizeof(int));
                file.write(mas,sizeof(int));

                st=obj->zal.GetStyle();
                memcpy(mas,&st,sizeof(int));
                file.write(mas,sizeof(int));
                break;
            }
            }
        }


        delete [] mas;
    }
    file.close();//закрываем файл

}

void MainWindow::on_pushButtonLoad_clicked()
{
    QFile file;
    QString fileName;
    char * mas = new char[sizeof(int)];
    fileName=QFileDialog::getOpenFileName(this,tr("Открыть bin"),"C:/Users/teacher/Desktop",tr("Binary files (*.bin)"));
    if (fileName.isEmpty())
    {
        QMessageBox::information(this,"Ошибка","Файл не выбран");
    }
    else
    {
        file.setFileName(fileName);
        ui->widget->im.fill(0);
        file.open(QIODevice::ReadOnly);//открываем файл
        int val;
        int indx=0;
        int row=0;
        int number=0;
        bool fl = false;
        if(file.bytesAvailable() % 4 == 0)
        {
            int x,y,rown;
            QComboBox * cb;
            //======================================================================================
            try//попробуем открыть
            {
                file.read(mas,sizeof(int));
                memcpy(&row,mas,sizeof(int));
                rown=row;
                while (!file.atEnd())
                {
                    file.read(mas,sizeof(int));
                    memcpy(&val,mas,sizeof(int));
                    switch (val)
                    {
                    case 0: //точка
                    {
                        file.read(mas,sizeof(int));

                        file.read(mas,sizeof(int));
                        //цвет границы=============================
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        break;
                    }
                    case 1: //Линия
                    {
                        file.read(mas,sizeof(int));

                        file.read(mas,sizeof(int));

                        file.read(mas,sizeof(int));

                        file.read(mas,sizeof(int));
                        //цвет границы=============================
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        break;
                    }
                    case 2: //прямоугольник
                    {
                        file.read(mas,sizeof(int));

                        file.read(mas,sizeof(int));

                        file.read(mas,sizeof(int));

                        file.read(mas,sizeof(int));
                        //цвет границы=============================
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        //цвет заливки=============================
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));


                        break;
                    }
                    case 3://эллипс
                    {
                        file.read(mas,sizeof(int));

                        file.read(mas,sizeof(int));

                        file.read(mas,sizeof(int));

                        file.read(mas,sizeof(int));
                        //цвет границы=============================
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        //цвет заливки=============================
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));

                        break;
                    }
                    case 4://круг
                    {
                        file.read(mas,sizeof(int));

                        file.read(mas,sizeof(int));

                        file.read(mas,sizeof(int));
                        //цвет границы=============================
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        //цвет заливки=============================
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        break;
                    }
                    case 5://дуга
                    {
                        file.read(mas,sizeof(int));

                        file.read(mas,sizeof(int));

                        file.read(mas,sizeof(int));

                        file.read(mas,sizeof(int));

                        file.read(mas,sizeof(int));

                        file.read(mas,sizeof(int));
                        //цвет границы=============================
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        break;
                    }
                    case 6://ломанная
                    {
                        int size;
                        file.read(mas,sizeof(int));
                        memcpy(&size,mas,sizeof(int)); //кол во точек
                        for(int i=0;i<size;i++)
                        {
                            file.read(mas,sizeof(int));
                            file.read(mas,sizeof(int));
                        }
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        break;
                    }
                    case 7://многоугольник
                    {
                        Primitive *prim=primitives[number];
                        polygon *obj=static_cast<polygon *>(prim);
                        int size;
                        MainPointsPl=obj->getPoints();
                        file.read(mas,sizeof(int));
                        memcpy(&size,mas,sizeof(int)); //кол во точек
                        MainPointsPl->resize(size);
                        for(int i=0;i<size;i++)
                        {
                            file.read(mas,sizeof(int));
                            file.read(mas,sizeof(int));
                        }
                        int a,r,g,b,st,w;
                        //цвет границы=============================
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        //цвет заливки=============================
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        file.read(mas,sizeof(int));
                        break;
                    }
                    }
                    number++;
                }
                if(number!=rown)
                {
                    QMessageBox msgBox;
                    msgBox.setWindowTitle("Предупреждение");
                    msgBox.setText("В файле указаны неверные значения размера. Будут загружены только корректное фактическое количество элементов.\nПри нажатии \"Отмена\", открытие будет отменено");
                    msgBox.setIcon(QMessageBox::Warning);
                    QAbstractButton * yesButton = msgBox.addButton("Открыть", QMessageBox::YesRole);
                    msgBox.exec();//открытие окна
                    if (msgBox.clickedButton() == yesButton) {ui->spinBox->setValue(number); fl=false;file.close();}
                    else
                    {
                        throw false;
                    }
                }
                else
                {
                    fl=false;
                }
            }
            catch(bool fl)//обработчик ошибки
            {
                QMessageBox::information(this,"Предупреждение","Открытие отменено!");
                file.close();
                fl=true;
            }
            //======================================================================================
            if(!fl)
            {
                file.close();//закрываем файл
                rown=0;
                row=0;
                file.open(QIODevice::ReadOnly);//открываем файл
                file.seek(0);
                file.read(mas,sizeof(int));
                memcpy(&row,mas,sizeof(int));
                rown=row;
                if(row<=20)
                {
                    ui->spinBox->setValue(number);
                    number=0;
                    while (!file.atEnd())//пока не дойдём до конца файла
                    {
                        file.read(mas,sizeof(int));
                        memcpy(&val,mas,sizeof(int));
                        row=indx+1;
                        cb = qobject_cast<QComboBox *>(ui->tableWidget->cellWidget(row,0));

                        cb->setCurrentIndex(val);

                        switch (val)
                        {
                        case 0: //точка
                        {
                            file.read(mas,sizeof(int));
                            memcpy(&x,mas,sizeof(int)); //X
                            ui->tableWidget->item(row,1)->setText(QString::number(x));

                            file.read(mas,sizeof(int));
                            memcpy(&y,mas,sizeof(int)); //Y
                            ui->tableWidget->item(row,2)->setText(QString::number(y));


                            int a,r,g,b,w;
                            file.read(mas,sizeof(int));
                            memcpy(&r,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&g,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&b,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&a,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&w,mas,sizeof(int));
                            Primitive *prim=primitives[number];
                            pixel *obj=static_cast<pixel *>(prim);
                            obj->SetW(w);
                            obj->SetColor(r,g,b,a);
                            //Доделать цвета
                            break;
                        }
                        case 1: //Линия
                        {
                            file.read(mas,sizeof(int));
                            memcpy(&x,mas,sizeof(int)); //X
                            ui->tableWidget->item(row,1)->setText(QString::number(x));

                            file.read(mas,sizeof(int));
                            memcpy(&y,mas,sizeof(int)); //Y
                            ui->tableWidget->item(row,2)->setText(QString::number(y));

                            file.read(mas,sizeof(int));
                            memcpy(&x,mas,sizeof(int)); //X1
                            ui->tableWidget->item(row,3)->setText(QString::number(x));

                            file.read(mas,sizeof(int));
                            memcpy(&y,mas,sizeof(int)); //Y1
                            ui->tableWidget->item(row,4)->setText(QString::number(y));


                            int a,r,g,b,st,w;
                            file.read(mas,sizeof(int));
                            memcpy(&r,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&g,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&b,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&a,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&st,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&w,mas,sizeof(int));
                            Primitive *prim=primitives[number];
                            line *obj=static_cast<line *>(prim);
                            obj->SetColor(r,g,b,a);
                            obj->SetStyle(st);
                            obj->SetW(w);
                            break;
                        }
                        case 2: //прямоугольник
                        {
                            file.read(mas,sizeof(int));
                            memcpy(&x,mas,sizeof(int)); //X
                            ui->tableWidget->item(row,1)->setText(QString::number(x));

                            file.read(mas,sizeof(int));
                            memcpy(&y,mas,sizeof(int)); //Y
                            ui->tableWidget->item(row,2)->setText(QString::number(y));

                            file.read(mas,sizeof(int));
                            memcpy(&x,mas,sizeof(int)); //ширина
                            ui->tableWidget->item(row,3)->setText(QString::number(x));

                            file.read(mas,sizeof(int));
                            memcpy(&y,mas,sizeof(int)); //высота
                            ui->tableWidget->item(row,4)->setText(QString::number(y));


                            int a,r,g,b,st,w;
                            //цвет границы=============================
                            file.read(mas,sizeof(int));
                            memcpy(&r,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&g,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&b,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&a,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&st,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&w,mas,sizeof(int));
                            Primitive *prim=primitives[number];
                            class rect *obj=static_cast<class rect *>(prim);
                            obj->gran.SetColor(r,g,b,a);
                            obj->gran.SetStyle(st);
                            obj->gran.SetW(w);
                            //цвет заливки=============================
                            file.read(mas,sizeof(int));
                            memcpy(&r,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&g,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&b,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&a,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&st,mas,sizeof(int));
                            obj->zal.SetColor(r,g,b,a);
                            obj->zal.SetStyle(st);


                            break;
                        }
                        case 3://эллипс
                        {
                            file.read(mas,sizeof(int));
                            memcpy(&x,mas,sizeof(int)); //X
                            ui->tableWidget->item(row,1)->setText(QString::number(x));

                            file.read(mas,sizeof(int));
                            memcpy(&y,mas,sizeof(int)); //Y
                            ui->tableWidget->item(row,2)->setText(QString::number(y));

                            file.read(mas,sizeof(int));
                            memcpy(&x,mas,sizeof(int)); //радиус 1
                            ui->tableWidget->item(row,3)->setText(QString::number(x));

                            file.read(mas,sizeof(int));
                            memcpy(&y,mas,sizeof(int)); //радиус 2
                            ui->tableWidget->item(row,4)->setText(QString::number(y));


                            int a,r,g,b,st,w;
                            //цвет границы=============================
                            file.read(mas,sizeof(int));
                            memcpy(&r,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&g,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&b,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&a,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&st,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&w,mas,sizeof(int));
                            Primitive *prim=primitives[number];
                            ellipse *obj=static_cast<ellipse *>(prim);
                            obj->gran.SetColor(r,g,b,a);
                            obj->gran.SetStyle(st);
                            obj->gran.SetW(w);
                            //цвет заливки=============================
                            file.read(mas,sizeof(int));
                            memcpy(&r,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&g,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&b,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&a,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&st,mas,sizeof(int));
                            obj->zal.SetColor(r,g,b,a);
                            obj->zal.SetStyle(st);

                            break;
                        }
                        case 4://круг
                        {
                            file.read(mas,sizeof(int));
                            memcpy(&x,mas,sizeof(int)); //X
                            ui->tableWidget->item(row,1)->setText(QString::number(x));

                            file.read(mas,sizeof(int));
                            memcpy(&y,mas,sizeof(int)); //Y
                            ui->tableWidget->item(row,2)->setText(QString::number(y));

                            file.read(mas,sizeof(int));
                            memcpy(&x,mas,sizeof(int)); //радиус
                            ui->tableWidget->item(row,3)->setText(QString::number(x));

                            int a,r,g,b,st,w;
                            //цвет границы=============================
                            file.read(mas,sizeof(int));
                            memcpy(&r,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&g,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&b,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&a,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&st,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&w,mas,sizeof(int));
                            Primitive *prim=primitives[number];
                            circle *obj=static_cast<circle *>(prim);
                            obj->gran.SetColor(r,g,b,a);
                            obj->gran.SetStyle(st);
                            obj->gran.SetW(w);
                            //цвет заливки=============================
                            file.read(mas,sizeof(int));
                            memcpy(&r,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&g,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&b,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&a,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&st,mas,sizeof(int));
                            obj->zal.SetColor(r,g,b,a);
                            obj->zal.SetStyle(st);
                            break;
                        }
                        case 5://дуга
                        {
                            file.read(mas,sizeof(int));
                            memcpy(&x,mas,sizeof(int)); //X
                            ui->tableWidget->item(row,1)->setText(QString::number(x));

                            file.read(mas,sizeof(int));
                            memcpy(&y,mas,sizeof(int)); //Y
                            ui->tableWidget->item(row,2)->setText(QString::number(y));

                            file.read(mas,sizeof(int));
                            memcpy(&x,mas,sizeof(int)); //радиус1
                            ui->tableWidget->item(row,3)->setText(QString::number(x));

                            file.read(mas,sizeof(int));
                            memcpy(&x,mas,sizeof(int)); //радиус2
                            ui->tableWidget->item(row,4)->setText(QString::number(x));

                            file.read(mas,sizeof(int));
                            memcpy(&x,mas,sizeof(int)); //начальный угол
                            ui->tableWidget->item(row,5)->setText(QString::number(x));

                            file.read(mas,sizeof(int));
                            memcpy(&x,mas,sizeof(int)); //угол охвата
                            ui->tableWidget->item(row,6)->setText(QString::number(x));

                            int a,r,g,b,st,w;
                            //цвет границы=============================
                            file.read(mas,sizeof(int));
                            memcpy(&r,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&g,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&b,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&a,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&st,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&w,mas,sizeof(int));
                            Primitive *prim=primitives[number];
                            class Arc *obj=static_cast<class Arc *>(prim);
                            obj->SetColor(r,g,b,a);
                            obj->SetStyle(st);
                            obj->SetW(w);
                            break;
                        }
                        case 6://ломанная
                        {
                            Primitive *prim=primitives[number];
                            polyline *obj=static_cast<polyline *>(prim);
                            int size;
                            MainPoints=obj->getPoints();
                            file.read(mas,sizeof(int));
                            memcpy(&size,mas,sizeof(int)); //кол во точек
                            MainPoints->resize(size);
                            for(int i=0;i<size;i++)
                            {
                                file.read(mas,sizeof(int));
                                memcpy(&x,mas,sizeof(int)); //X

                                (*MainPoints)[i].SetX(x);

                                file.read(mas,sizeof(int));
                                memcpy(&y,mas,sizeof(int)); //Y

                                (*MainPoints)[i].SetY(y);
                            }
                            int a,r,g,b,st,w;
                            //цвет границы=============================
                            file.read(mas,sizeof(int));
                            memcpy(&r,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&g,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&b,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&a,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&st,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&w,mas,sizeof(int));
                            obj->gran.SetColor(r,g,b,a);
                            obj->gran.SetStyle(st);
                            obj->gran.SetW(w);
                            break;
                        }
                        case 7://многоугольник
                        {
                            Primitive *prim=primitives[number];
                            polygon *obj=static_cast<polygon *>(prim);
                            int size;
                            MainPointsPl=obj->getPoints();
                            file.read(mas,sizeof(int));
                            memcpy(&size,mas,sizeof(int)); //кол во точек
                            MainPointsPl->resize(size);
                            for(int i=0;i<size;i++)
                            {
                                file.read(mas,sizeof(int));
                                memcpy(&x,mas,sizeof(int)); //X

                                (*MainPointsPl)[i].SetX(x);

                                file.read(mas,sizeof(int));
                                memcpy(&y,mas,sizeof(int)); //Y

                                (*MainPointsPl)[i].SetY(y);
                            }
                            int a,r,g,b,st,w;
                            //цвет границы=============================
                            file.read(mas,sizeof(int));
                            memcpy(&r,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&g,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&b,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&a,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&st,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&w,mas,sizeof(int));
                            obj->gran.SetColor(r,g,b,a);
                            obj->gran.SetStyle(st);
                            obj->gran.SetW(w);
                            //цвет заливки=============================
                            file.read(mas,sizeof(int));
                            memcpy(&r,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&g,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&b,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&a,mas,sizeof(int));
                            file.read(mas,sizeof(int));
                            memcpy(&st,mas,sizeof(int));
                            obj->zal.SetColor(r,g,b,a);
                            obj->zal.SetStyle(st);
                            break;
                        }
                        }
                        indx+=2;
                        number++;
                    }
                }
                else
                {
                    QMessageBox::information(this, "Ошибка", "Неверное значение размера");//сообщение об ошибке
                    fl=true;
                }
            }
        }
        else
        {
            QMessageBox::information(this, "Ошибка", "Файл имеет неверные данные.");
            fl=true;
        }
        if(!fl)
        {
            //drawAll();
        }

    }
    delete [] mas;//чистим массив
    file.close();
}

void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    if(!no_auto_change)
    {

        int value;
        bool fl;
        int size=0;
        value=ui->tableWidget->item(row,column)->text().toInt(&fl);
        if(fl)
        {
            //ui->pushButtonSave->setEnabled(1);
            ui->tableWidget->item(row,column)->setBackgroundColor(Qt::white);//подсветка белым
            int index = (row - (row % 2)) / 2;
            Primitive * prim = primitives[index];
            switch (prim->getType())
            {
            case Pixel: {
                pixel * obj = static_cast<pixel *>(prim);
                if (column == 1) obj->SetX(value);
                else if (column == 2) obj->SetY(value);
                break;
            }
            case Line: {
                line * obj = static_cast<line *>(prim);
                if (column == 1) obj->start.SetX(value);
                else if (column == 2) obj->start.SetY(value);
                if (column == 3) obj->end.SetX(value);
                else if (column == 4) obj->end.SetY(value);
                break;
            }
            case Rectangle: {
                class rect * obj = static_cast<class rect *>(prim);
                if (column == 1) obj->point.SetX(value);
                else if (column == 2) obj->point.SetY(value);
                if (column == 3) obj->SetWeight(value);
                else if (column == 4) obj->SetHeight(value);
                break;
            }
            case Ellipse: {
                ellipse * obj = static_cast<ellipse *>(prim);
                if (column == 1) obj->center.SetX(value);
                else if (column == 2) obj->center.SetY(value);
                if (column == 3) obj->SetRadius1(value);
                else if (column == 4) obj->SetRadius2(value);
                break;
            }
            case Circle:
            {
                circle *obj=static_cast<circle *>(prim);
                if (column == 1) obj->center.SetX(value);
                else if (column == 2) obj->center.SetY(value);
                if (column == 3) obj->SetRadius(value);
                break;

            }
            case Arc: {
                class Arc * obj = static_cast<class Arc *>(prim);
                if (column == 1) obj->begin.SetX(value);
                else if (column == 2) obj->begin.SetY(value);
                if (column == 3) obj->SetRadius1(value);
                else if (column == 4) obj->SetRadius2(value);
                if (column == 5) obj->SetStartAngle(value);
                else if (column == 6) obj->SetSpanAngle(value);
                break;
            }
            }
            //drawAll();

        }
        else
        {

            ui->tableWidget->item(row,column)->setBackgroundColor(Qt::red);//подсветка красныем
        }

    }

}

void MainWindow::drawAll()
{
    QImage * im = &ui->widget->im;
    (*im).fill(0);//чистим окно
    for (Primitive * prim :primitives)//рисуем все заданные примитивы
    {
        prim->draw(im);//рисуем каждый отдельный примитив
    }
    ui->widget->repaint();//рисуем
}

void MainWindow::on_pushButton_clicked()
{
    drawAll();
}
