#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fl_draw=false;
    ui->pushButton_drawIm->setEnabled(0);
    ui->label->hide();
    ui->spinBox->hide();
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::paintEvent(QPaintEvent *)
{
    if(fl_draw)
    {
        QPainter painter(this);//создали художника
        QPen pen;//создали карандаш
        pen.setColor(Qt::green);//цвето
        pen.setWidth(15);//толщина
        pen.setStyle(Qt::DotLine);//стиль
        pen.setCapStyle(Qt::RoundCap);
        painter.setPen(pen);//вручили карандаш художнику
        painter.drawLine(50,50,150,200);//нарисовали линию
    }
}

void MainWindow::on_pushButton_drawIm_clicked()
{
    ui->pushButton_3->click();
    QPainter painter(&ui->widget->im);
    QBrush brush;
    QPalette Pal(palette());
    Pal.setColor(backgroundRole(),QColor(94,74,91));

    // ui->widget->setAutoFillBackground(true);
    ui->widget->setPalette(Pal);
    // ui->widget->setAutoFillBackground(false);24,78,28    60,215,88

    QPen pen;//объявление карандаша
    QColor col;//цвет дома
    QColor colRoof;//цвет крыши
    QColor colWindow;//цвет окна
    QColor colCurtains;//цвет занавесок
    QColor colStars;//цвет звёзд
    QColor colGrass;//цвет травы
    QColor colSky;//цвет неба
    QColor colMoon;//цвет луны
    QColor colMoonHole;//цвет краторов
    QColor colRoad;//цвет дорожки
    QColor colSun;//цвет солнца
    QColor colRay;//цвет луча
    QColor colClouds;//цвет облаков
    //col.setRgb(162,139,139);222,211,211

    col.setRgb(255, 250, 205);//обычный цвет
    colRoof.setRgb(139, 69, 19);//цвет крышы
    colWindow.setRgb(234,245,245);//цвет окна
    colCurtains.setRgb(139, 69, 19);//цвет занавесок
    colStars.setRgb(253,253,58);
    colGrass.setRgb(24,78,28);//цвет травы
    colSky.setRgb(11,11,71);//цвет неба
    colMoon.setRgb(212,216,217);//цвет луны    212, G=216, B=217  189,208,228
    colMoonHole.setRgb(123,130,138);//цвет краторов
    colRoad.setRgb(129,124,95);//цвет дорожки 181,184,177  129,124,95
    colSun.setRgb(255,245,72);
    colRay.setRgb(255,245,72,110);
    colClouds.setRgb(236,240,241);

    //painter.drawLine(30,90,0,300);
    QPoint rect[4];//дом
    rect[0].setX(175);
    rect[0].setY(600);
    rect[1].setX(175);
    rect[1].setY(350);
    rect[2].setX(525);
    rect[2].setY(350);
    rect[3].setX(525);
    rect[3].setY(600);
    //=================================================================================================================
    QPoint roof[3];//крыша
    roof[0].setX(350);
    roof[0].setY(200);
    roof[1].setX(175);
    roof[1].setY(350);
    roof[2].setX(525);
    roof[2].setY(350);
    //=================================================================================================================
    QPoint door[4];//дверь
    door[0].setX(225);
    door[0].setY(598);
    door[1].setX(225);
    door[1].setY(472);
    door[2].setX(325);
    door[2].setY(472);
    door[3].setX(325);
    door[3].setY(598);
    //=================================================================================================================
    QPoint handle[4];//ручка от двери
    handle[0].setX(305);
    handle[0].setY(545);
    handle[1].setX(305);
    handle[1].setY(547);
    handle[2].setX(307);
    handle[2].setY(547);
    handle[3].setX(307);
    handle[3].setY(545);
    //=================================================================================================================
    QPoint window[4];//окно
    window[0].setX(375);
    window[0].setY(525);
    window[1].setX(375);
    window[1].setY(425);
    window[2].setX(475);
    window[2].setY(425);
    window[3].setX(475);
    window[3].setY(525);
    //=================================================================================================================
    QPoint curtains[9];//занавески
    curtains[0].setX(375);
    curtains[0].setY(485);
    curtains[1].setX(400);
    curtains[1].setY(450);
    curtains[2].setX(405);
    curtains[2].setY(455);
    curtains[3].setX(425);
    curtains[3].setY(445);
    curtains[4].setX(445);
    curtains[4].setY(455);
    curtains[5].setX(450);
    curtains[5].setY(450);
    curtains[6].setX(475);
    curtains[6].setY(485);
    curtains[7].setX(475);
    curtains[7].setY(425);
    curtains[8].setX(375);
    curtains[8].setY(425);
    //=================================================================================================================
    QPoint grass[4];//трава
    grass[0].setX(0);
    grass[0].setY(600);
    grass[1].setX(700);
    grass[1].setY(600);
    grass[2].setX(700);
    grass[2].setY(700);
    grass[3].setX(0);
    grass[3].setY(700);
    //=================================================================================================================
    QPoint sky[4];//небо
    sky[0].setX(0);
    sky[0].setY(0);
    sky[1].setX(700);
    sky[1].setY(0);
    sky[2].setX(700);
    sky[2].setY(600);
    sky[3].setX(0);
    sky[3].setY(600);
    //=================================================================================================================
    QPoint road[4];//дорожка
    road[0].setX(225);
    road[0].setY(600);
    road[1].setX(325);
    road[1].setY(600);
    road[2].setX(305);
    road[2].setY(700);
    road[3].setX(200);
    road[3].setY(700);
    //=================================================================================================================
    QPoint ray[4];//луч
    ray[0].setX(615);
    ray[0].setY(40);
    ray[1].setX(635);
    ray[1].setY(70);
    ray[2].setX(80);
    ray[2].setY(800);
    ray[3].setX(-90);
    ray[3].setY(800);
    //=================================================================================================================
    QPoint ray1[4];//луч 2
    ray1[0].setX(605);
    ray1[0].setY(40);
    ray1[1].setX(635);
    ray1[1].setY(70);
    ray1[2].setX(700);
    ray1[2].setY(800);
    ray1[3].setX(600);
    ray1[3].setY(800);
    //=================================================================================================================
    QPoint ray2[4];//луч 3
    ray2[0].setX(605);
    ray2[0].setY(60);
    ray2[1].setX(635);
    ray2[1].setY(90);
    ray2[2].setX(-90);
    ray2[2].setY(120);
    ray2[3].setX(-90);
    ray2[3].setY(40);


    if(!setDay)
    {
        int centerX=0;
        int centerY=0;

        pen.setColor(Qt::black);
        pen.setStyle(Qt::SolidLine);
        pen.setWidth(4);
        painter.setPen(pen);
        brush.setStyle(Qt::SolidPattern);
        //=================================================================================================================
        brush.setColor(colSky);
        painter.setBrush(brush);
        painter.drawPolygon(sky,4,Qt::OddEvenFill);// создание неба
        //=================================================================================================================

        brush.setColor(colStars);
        painter.setBrush(brush);

        //bool status=false;
        value=ui->spinBox->value();

        for(int i=0;i<value;i++)
        {
            bool status=true;
            do
            {
                centerX=rand()%690+5;
                if((centerX>5 && centerX<170)||((centerX>530) && (centerX<670)) )//крайние области
                {
                    centerY=rand()%600+5;
                    status=true;

                }
                else if (centerX>=175 && centerX <=350)//над крышей
                {
                    centerY=rand()%350+5;
                    if (centerY <= (6*centerX)/7 - 500)
                    {
                        status=false;
                    }
                    else
                    {
                        status=true;
                    }

                }
                else if (centerX>350 && centerX<=525)
                {
                    centerY=rand()%350+5;
                    if (centerY <= (-6*centerX)/7 + 100)
                    {
                        status=false;
                    }
                    else
                    {
                        status=true;
                    }
                }
                else
                {
                    status=false;
                }
            }while(!status);

            //centerX=rand()%680+10;
            //centerY=rand()%400+10;
            QPoint star[10];//звездочка
            star[0].setX(centerX);
            star[0].setY(centerY-10);

            star[1].setX(centerX+2);
            star[1].setY(centerY-3);

            star[2].setX(centerX+10);
            star[2].setY(centerY-3);

            star[3].setX(centerX+4);
            star[3].setY(centerY+1);

            star[4].setX(centerX+5);
            star[4].setY(centerY+8);

            star[5].setX(centerX);
            star[5].setY(centerY+4);

            star[6].setX(centerX-5);
            star[6].setY(centerY+8);

            star[7].setX(centerX-4);
            star[7].setY(centerY+1);

            star[8].setX(centerX-10);
            star[8].setY(centerY-3);

            star[9].setX(centerX-2);
            star[9].setY(centerY-3);

            painter.drawPolygon(star,10,Qt::OddEvenFill);

            status=false;

        }
        //=================================================================================================================
        brush.setColor(col);//присваивает брашу цвет дома
        painter.setBrush(brush);//даём пэинтэру браш
        painter.drawPolygon(rect,4,Qt::OddEvenFill);// создание дома
        //=================================================================================================================
        brush.setColor(colRoof);//присваивает брашу цвет крыша
        painter.setBrush(brush);//даём пэинтэру браш
        painter.drawPolygon(roof,3,Qt::OddEvenFill);// создание крыши
        painter.drawPolygon(door,4,Qt::OddEvenFill);// создание двери
        //=================================================================================================================
        brush.setColor(colWindow);//присваивает брашу цвет окна
        painter.setBrush(brush);//даём пэинтэру браш
        painter.drawPolygon(handle,4,Qt::OddEvenFill);// создание ручки от двери
        painter.drawPolygon(window,4,Qt::OddEvenFill);// создание окна
        //=================================================================================================================
        brush.setColor(colCurtains);
        painter.setBrush(brush);
        painter.drawPolygon(curtains,9,Qt::OddEvenFill);// создание занавесок
        //=================================================================================================================
        painter.drawLine(425,425,425,525);// создание вертикальной линии
        painter.drawLine(375,475,475,475);// создание горизонтальной линии
        //=================================================================================================================
        //brush.setStyle(Qt::LinearGradientPattern);
        brush.setColor(colMoon);
        painter.setBrush(brush);
        painter.drawEllipse(570,25,100,100);//создание луны
        //=================================================================================================================
        brush.setColor(colGrass);
        painter.setBrush(brush);
        painter.drawPolygon(grass,4,Qt::OddEvenFill);// создание травы
        //=================================================================================================================
        brush.setColor(colRoad);
        painter.setBrush(brush);
        painter.drawPolygon(road,4,Qt::OddEvenFill);//создание дороги
        //=================================================================================================================
        pen.setWidth(0);
        painter.setPen(pen);
        brush.setColor(colMoonHole);
        painter.setBrush(brush);
        painter.drawEllipse(630,35,20,20);
        painter.drawEllipse(615,55,15,15);
        painter.drawEllipse(625,75,10,10);
        painter.drawEllipse(600,35,10,10);
        painter.drawEllipse(600,100,10,10);
        //=================================================================================================================


        repaint();

    }
    else
    {
        colSky.setRgb(117,187,253);//цвет неба
        colGrass.setRgb(119,253,117);//цвет травы
        colRoad.setRgb(193,189,159);//цвет дорожки
        pen.setColor(Qt::black);
        pen.setStyle(Qt::SolidLine);
        pen.setWidth(4);
        painter.setPen(pen);
        brush.setStyle(Qt::SolidPattern);
        //=================================================================================================================
        brush.setColor(colSky);
        painter.setBrush(brush);
        painter.drawPolygon(sky,4,Qt::OddEvenFill);// создание неба
        //=================================================================================================================
        pen.setWidth(0);
        painter.setPen(pen);
        brush.setColor(colRay);
        painter.setBrush(brush);
        painter.drawPolygon(ray,4,Qt::OddEvenFill);//создание луча
        painter.drawPolygon(ray1,4,Qt::OddEvenFill);//создание луча
        painter.drawPolygon(ray2,4,Qt::OddEvenFill);//создание луча
        //=================================================================================================================
        pen.setWidth(4);
        painter.setPen(pen);
        brush.setColor(col);//присваивает брашу цвет дома
        painter.setBrush(brush);//даём пэинтэру браш
        painter.drawPolygon(rect,4,Qt::OddEvenFill);// создание дома
        //=================================================================================================================
        brush.setColor(colRoof);//присваивает брашу цвет крыша
        painter.setBrush(brush);//даём пэинтэру браш
        painter.drawPolygon(roof,3,Qt::OddEvenFill);// создание крыши
        painter.drawPolygon(door,4,Qt::OddEvenFill);// создание двери
        //=================================================================================================================
        brush.setColor(colWindow);//присваивает брашу цвет окна
        painter.setBrush(brush);//даём пэинтэру браш
        painter.drawPolygon(handle,4,Qt::OddEvenFill);// создание ручки от двери
        painter.drawPolygon(window,4,Qt::OddEvenFill);// создание окна
        //=================================================================================================================
        brush.setColor(colCurtains);
        painter.setBrush(brush);
        painter.drawPolygon(curtains,9,Qt::OddEvenFill);// создание занавесок
        //=================================================================================================================
        painter.drawLine(425,425,425,525);// создание вертикальной линии
        painter.drawLine(375,475,475,475);// создание горизонтальной линии
        //=================================================================================================================
        brush.setColor(colGrass);
        painter.setBrush(brush);
        painter.drawPolygon(grass,4,Qt::OddEvenFill);// создание травы
        //=================================================================================================================
        brush.setColor(colRoad);
        painter.setBrush(brush);
        painter.drawPolygon(road,4,Qt::OddEvenFill);//создание дороги
        //=================================================================================================================
        pen.setWidth(1);
        painter.setPen(pen);
        brush.setColor(colSun);
        painter.setBrush(brush);
        painter.drawEllipse(535,5,140,140);//создание солнца
        //=================================================================================================================
        brush.setColor(colClouds);
        painter.setBrush(brush);
        //painter.drawEllipse(120,110,170,40);//создание облаков
        //painter.drawEllipse(140,105,40,40);//создание облаков


        repaint();

    }
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->widget->im.fill(0);
    repaint();
}



void MainWindow::on_spinBox_valueChanged(int arg1)
{
    value=ui->spinBox->value();
}

void MainWindow::on_pushButton_day_clicked()
{
    ui->label->hide();
    ui->spinBox->hide();
    ui->pushButton_drawIm->setEnabled(1);
    setDay=true;
}

void MainWindow::on_pushButton_night_clicked()
{
    ui->spinBox->show();
    ui->label->show();
    ui->pushButton_drawIm->setEnabled(1);
    ui->spinBox->setValue(0);
    setDay=false;
}
