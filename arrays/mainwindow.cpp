#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    no_auto_change=true;
    ui->spinBox->setMaximum(MAX_MAS);//установка максимума значений в спинбоксе
    ui->label_max->clear();
    ui->label_min->clear();
    ui->label_sz->clear();
    ui->label_puz->clear();
    ui->label_fast->clear();
    ui->label_gnom->clear();
    ui->label_monkey->clear();
    ui->label_comb->clear();
    ui->label_dubl->clear();
    ui->label_count->clear();
    ui->lineEdit_res->setReadOnly(true);//включаем режим только для чтения
}

MainWindow::~MainWindow()//Деструктор
{
    delete ui;
}


void MainWindow::quick(int *mas,int max_size)//функция для быстрой сортировки
{
    int i = 0;
    int j = max_size - 1;
    int mid = mas[max_size / 2];
    do {
        while(mas[i] < mid)
        {
            i++;
        }
        while(mas[j] > mid)
        {
            j--;
        }
        if (i <= j)
        {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);
    if(j > 0)
    {
        quick(mas, j + 1);
    }
    if (i < max_size)
    {
        quick(&mas[i], max_size - i);
    }
}
bool MainWindow::sort(int *a,int x)//функция для проверки отсортировки массива
{
    while (--x>0)
        if (a[x] < a[x-1])
            return false;
    return true;
}
void MainWindow::shuffle(int *a,int x)//функция для смены мест
{
    for (int i=0;i<x; i++)
    {
        int k=rand()%x;
        int tmp=a[i];
        a[i]=a[k];
        a[k]=tmp;
    }
}

void MainWindow::monkey(int *a,int x)//функция для обезьяньей сортировки
{
    while (!sort(a,x))
        shuffle(a,x);
}
void MainWindow::on_pushButton_rand_clicked()//обработки кнопки рандома
{
    ui->label_max->clear();
    ui->label_min->clear();
    ui->label_sz->clear();
    ui->label_puz->clear();
    ui->label_fast->clear();
    ui->label_gnom->clear();
    ui->label_monkey->clear();
    ui->label_comb->clear();
    ui->label_dubl->clear();
    no_auto_change=false;

    int mas[MAX_MAS];//объявление массива на максимально возмодное кол-во элементов
    int max_size=ui->spinBox->value();//текущий размер массива
    //формирование данных в массиве
    for (int i=0; i<max_size;i++)
    {
        mas[i]=rand()%201-100;
    }
    //запись массива в таблицу
    for (int i=0; i<max_size;i++)
    {
        if(ui->tableWidget->item(i,0)==nullptr)
        {
            QTableWidgetItem * ti;
            ti= new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,ti);
        }
        ui->tableWidget->item(i,0)->setText(QString::number(mas[i]));
        ui->tableWidget->item(i,0)->setBackground(Qt::white);
    }



    no_auto_change=true;
}

void MainWindow::on_spinBox_valueChanged(int arg1)//обработка изменения значения в спинбоксе
{
    ui->tableWidget->setRowCount(arg1);
}

void MainWindow::on_tableWidget_cellChanged(int row, int column)//обработка изменения значения в ячейке таблицы
{
    if(no_auto_change)
    {
        bool fl;
        ui->tableWidget->item(row,column)->text().toInt(&fl);
        if(fl)
            ui->tableWidget->item(row,column)->setBackgroundColor(Qt::white);
        else
            ui->tableWidget->item(row,column)->setBackgroundColor(Qt::red);
    }
}

void MainWindow::on_pushButton_max_clicked()//обработка кнопки нахождения максимума
{
    no_auto_change=false;

    int mas[MAX_MAS];//объявление массива на максимально возмодное кол-во элементов
    int max_size=ui->spinBox->value();//текущий размер массив
    bool fl_gl;//признак успешной конвертации массива
    bool fl_lc;//признак успешной конвертации ячейки

    //формирование массива
    fl_gl=true;
    for (int i=0; i<max_size;i++)
    {
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i]=ui->tableWidget->item(i,0)->text().toInt(&fl_lc);
        }
        else
        {
            fl_lc=false;
            QTableWidgetItem * ti;
            ti= new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,ti);

        }
        if(fl_lc)
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
        else
        {
            fl_gl=false;
            ui->tableWidget->item(i,0)->setBackgroundColor(Qt::red);
        }
    }
    //работа с массивом
    int max=mas[0];
    if(fl_gl)
    {
        for (int i=0; i<max_size;i++)
        {
            if(mas[i]>max)
                max=mas[i];
        }
    }
    //вывод результата
    if(fl_gl)
    {
        ui->label_min->clear();
        ui->label_sz->clear();
        ui->label_puz->clear();
        ui->label_fast->clear();
        ui->label_gnom->clear();
        ui->label_comb->clear();
        ui->label_monkey->clear();
        ui->label_dubl->clear();
        ui->label_max->setNum(max);
    }
    else
        ui->label_max->setText("Ошибка!");

    no_auto_change=true;
}

void MainWindow::on_pushButton_min_clicked()//обработка кнопки нахождения минимума
{
    no_auto_change=false;

    int mas[MAX_MAS];//объявление массива на максимально возмодное кол-во элементов
    int max_size=ui->spinBox->value();//текущий размер массив
    bool fl_gl;//признак успешной конвертации массива
    bool fl_lc;//признак успешной конвертации ячейки

    //формирование массива
    fl_gl=true;
    for (int i=0; i<max_size;i++)
    {
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i]=ui->tableWidget->item(i,0)->text().toInt(&fl_lc);
        }
        else
        {
            fl_lc=false;
            QTableWidgetItem * ti;
            ti= new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,ti);

        }
        if(fl_lc)
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
        else
        {
            fl_gl=false;
            ui->tableWidget->item(i,0)->setBackgroundColor(Qt::red);
        }
    }
    //работа с массивом
    int min=mas[0];
    if(fl_gl)
    {
        for (int i=0; i<max_size;i++)
        {
            if(mas[i]<min)
                min=mas[i];
        }
    }
    //вывод результата
    if(fl_gl)
    {
        ui->label_min->setNum(min);
        ui->label_max->clear();
        ui->label_sz->clear();
        ui->label_puz->clear();
        ui->label_fast->clear();
        ui->label_gnom->clear();
        ui->label_comb->clear();
        ui->label_monkey->clear();
        ui->label_dubl->clear();
    }
    else
        ui->label_min->setText("Ошибка!");

    no_auto_change=true;
}

void MainWindow::on_pushButton_sz_clicked()//обработка кнопки нахождения ср.значения
{
    no_auto_change=false;

    int mas[MAX_MAS];//объявление массива на максимально возмодное кол-во элементов
    int max_size=ui->spinBox->value();//текущий размер массив
    bool fl_gl;//признак успешной конвертации массива
    bool fl_lc;//признак успешной конвертации ячейки

    //формирование массива
    fl_gl=true;
    for (int i=0; i<max_size;i++)
    {
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i]=ui->tableWidget->item(i,0)->text().toInt(&fl_lc);
        }
        else
        {
            fl_lc=false;
            QTableWidgetItem * ti;
            ti= new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,ti);

        }
        if(fl_lc)
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
        else
        {
            fl_gl=false;
            ui->tableWidget->item(i,0)->setBackgroundColor(Qt::red);
        }
    }
    //работа с массивом
    double sz=0;// переменная для среднего значения
    int x=0;//кол-во чисел
    if(fl_gl)
    {
        for (int i=0; i<max_size;i++)
        {
            sz+=mas[i];
            x++;
        }
    }
    //вывод результата
    if(x!=0)
    {
        sz=sz/x;
        if(fl_gl)
        {
            ui->label_max->clear();
            ui->label_min->clear();
            ui->label_puz->clear();
            ui->label_fast->clear();
            ui->label_gnom->clear();
            ui->label_comb->clear();
            ui->label_monkey->clear();
            ui->label_dubl->clear();
            ui->label_sz->setNum(sz);
        }
        else
            ui->label_sz->setText("Ошибка!");
    }
    else
    {
        ui->label_sz->setText("Ошибка!");
    }

    no_auto_change=true;
}

void MainWindow::on_pushButton_puz_clicked()//сортировка пузырьком
{
    no_auto_change=false;

    int mas[MAX_MAS];//объявление массива на максимально возмодное кол-во элементов
    int max_size=ui->spinBox->value();//текущий размер массив
    bool fl_gl;//признак успешной конвертации массива
    bool fl_lc;//признак успешной конвертации ячейки

    //формирование массива
    fl_gl=true;
    for (int i=0; i<max_size;i++)
    {
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i]=ui->tableWidget->item(i,0)->text().toInt(&fl_lc);
        }
        else
        {
            fl_lc=false;
            QTableWidgetItem * ti;
            ti= new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,ti);

        }
        if(fl_lc)
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
        else
        {
            fl_gl=false;
            ui->tableWidget->item(i,0)->setBackgroundColor(Qt::red);
        }
    }
    //работа с массивом
    if(fl_gl)//сортировка пузырёк
    {
        for (int i=0;i<max_size;i++)
        {
            for (int j=0;j<(max_size-1);j++)
            {
                if (mas[j] > mas[j+1])
                {
                    int x=mas[j]; //создаём переменную для хранения значения
                    mas[j]=mas[j+1];//смена значений местами
                    mas[j+1]=x;//присваиваем новое значение
                }
            }
        }
    }
    //запись в таблицу
    if(fl_gl)
    {
        ui->label_max->clear();
        ui->label_min->clear();
        ui->label_sz->clear();
        ui->label_puz->clear();
        ui->label_fast->clear();
        ui->label_gnom->clear();
        ui->label_comb->clear();
        ui->label_dubl->clear();
        ui->label_monkey->clear();
        for (int i=0; i<max_size;i++)
        {
            if(ui->tableWidget->item(i,0)==nullptr)
            {
                QTableWidgetItem * ti;
                ti= new QTableWidgetItem;
                ui->tableWidget->setItem(i,0,ti);
            }
            ui->tableWidget->item(i,0)->setText(QString::number(mas[i]));
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
        }
    }
    else
        ui->label_puz->setText("Ошибка!");
    no_auto_change=true;
}



void MainWindow::on_pushButton_gnom_clicked()//гномья сортировка
{
    no_auto_change=false;

    int mas[MAX_MAS];//объявление массива на максимально возмодное кол-во элементов
    int max_size=ui->spinBox->value();//текущий размер массив
    bool fl_gl;//признак успешной конвертации массива
    bool fl_lc;//признак успешной конвертации ячейки

    //формирование массива
    fl_gl=true;
    for (int i=0; i<max_size;i++)
    {
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i]=ui->tableWidget->item(i,0)->text().toInt(&fl_lc);
        }
        else
        {
            fl_lc=false;
            QTableWidgetItem * ti;
            ti= new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,ti);

        }
        if(fl_lc)
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
        else
        {
            fl_gl=false;
            ui->tableWidget->item(i,0)->setBackgroundColor(Qt::red);
        }
    }
    //работа с массивом
    if(fl_gl)//гномья сортировка
    {
        int i=0;
        int x;
        while (i<max_size)
        {
            if((i==0)||(mas[i-1]<=mas[i]))
                i++;
            else
            {
                x=mas[i-1];
                mas[i-1]=mas[i];
                mas[i]=x;
                i=i-1;
            }
        }
    }
    //запись в таблицу
    if(fl_gl)
    {
        ui->label_max->clear();
        ui->label_min->clear();
        ui->label_sz->clear();
        ui->label_puz->clear();
        ui->label_fast->clear();
        ui->label_gnom->clear();
        ui->label_comb->clear();
        ui->label_monkey->clear();
        ui->label_dubl->clear();
        for (int i=0; i<max_size;i++)
        {
            if(ui->tableWidget->item(i,0)==nullptr)
            {
                QTableWidgetItem * ti;
                ti= new QTableWidgetItem;
                ui->tableWidget->setItem(i,0,ti);
            }
            ui->tableWidget->item(i,0)->setText(QString::number(mas[i]));
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
        }
    }
    else
        ui->label_gnom->setText("Ошибка!");
    no_auto_change=true;
}

void MainWindow::on_pushButton_fast_clicked()//быстрая сортировка
{
    no_auto_change=false;

    int mas[MAX_MAS];//объявление массива на максимально возмодное кол-во элементов
    int max_size=ui->spinBox->value();//текущий размер массив
    bool fl_gl;//признак успешной конвертации массива
    bool fl_lc;//признак успешной конвертации ячейки

    //формирование массива
    fl_gl=true;
    for (int i=0; i<max_size;i++)
    {
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i]=ui->tableWidget->item(i,0)->text().toInt(&fl_lc);
        }
        else
        {
            fl_lc=false;
            QTableWidgetItem * ti;
            ti= new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,ti);

        }
        if(fl_lc)
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
        else
        {
            fl_gl=false;
            ui->tableWidget->item(i,0)->setBackgroundColor(Qt::red);
        }
    }
    //работа с массивом
    if(fl_gl)//быстрая сортировка
    {
        quick(mas, max_size);
    }
    if(fl_gl)
    {
        //запись в таблицу
        for (int i=0; i<max_size;i++)
        {
            ui->label_max->clear();
            ui->label_min->clear();
            ui->label_sz->clear();
            ui->label_puz->clear();
            ui->label_fast->clear();
            ui->label_gnom->clear();
            ui->label_comb->clear();
            ui->label_dubl->clear();
            ui->label_monkey->clear();
            if(ui->tableWidget->item(i,0)==nullptr)
            {
                QTableWidgetItem * ti;
                ti= new QTableWidgetItem;
                ui->tableWidget->setItem(i,0,ti);
            }
            ui->tableWidget->item(i,0)->setText(QString::number(mas[i]));
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
        }
    }
    else
        ui->label_fast->setText("Ошибка!");
    no_auto_change=true;
}

void MainWindow::on_pushButton_comb_clicked()//сортировка расчестка
{
    no_auto_change=false;

    int mas[MAX_MAS];//объявление массива на максимально возмодное кол-во элементов
    int max_size=ui->spinBox->value();//текущий размер массив
    bool fl_gl;//признак успешной конвертации массива
    bool fl_lc;//признак успешной конвертации ячейки
    double goldzn=1.247;

    //формирование массива
    fl_gl=true;
    for (int i=0; i<max_size;i++)
    {
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i]=ui->tableWidget->item(i,0)->text().toInt(&fl_lc);
        }
        else
        {
            fl_lc=false;
            QTableWidgetItem * ti;
            ti= new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,ti);

        }
        if(fl_lc)
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
        else
        {
            fl_gl=false;
            ui->tableWidget->item(i,0)->setBackgroundColor(Qt::red);
        }
    }
    //работа с массивом
    if(fl_gl)//сортировка расчёстка
    {
        int n=max_size-1;
        while(n>=1)
        {
            for(int i=0; i+n<max_size; i++)
            {
                if(mas[i]>mas[i+n])
                {
                    int vrem=mas[i];
                    mas[i]=mas[i+n];
                    mas[i+n]=vrem;
                }
            }
            n/=goldzn;
        }
    }
    if(fl_gl)
    {
        //запись в таблицу
        for (int i=0; i<max_size;i++)
        {
            ui->label_max->clear();
            ui->label_min->clear();
            ui->label_sz->clear();
            ui->label_puz->clear();
            ui->label_fast->clear();
            ui->label_gnom->clear();
            ui->label_monkey->clear();
            ui->label_dubl->clear();
            ui->label_comb->clear();
            if(ui->tableWidget->item(i,0)==nullptr)
            {
                QTableWidgetItem * ti;
                ti= new QTableWidgetItem;
                ui->tableWidget->setItem(i,0,ti);
            }
            ui->tableWidget->item(i,0)->setText(QString::number(mas[i]));
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
        }
    }
    else
        ui->label_comb->setText("Ошибка!");
    no_auto_change=true;
}

void MainWindow::on_pushButton_monkey_clicked()//обезьянья сортировка
{
    no_auto_change=false;

    int mas[MAX_MAS];//объявление массива на максимально возмодное кол-во элементов
    int max_size=ui->spinBox->value();//текущий размер массив
    bool fl_gl;//признак успешной конвертации массива
    bool fl_lc;//признак успешной конвертации ячейки

    //формирование массива
    fl_gl=true;
    for (int i=0; i<max_size;i++)
    {
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i]=ui->tableWidget->item(i,0)->text().toInt(&fl_lc);
        }
        else
        {
            fl_lc=false;
            QTableWidgetItem * ti;
            ti= new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,ti);

        }
        if(fl_lc)
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
        else
        {
            fl_gl=false;
            ui->tableWidget->item(i,0)->setBackgroundColor(Qt::red);
        }
    }
    //работа с массивом
    if(fl_gl)//обезьянья сортировка
    {
        if(max_size>5)
            fl_gl=false;
        else
            monkey(mas,max_size);
    }
    if(fl_gl)
    {
        //запись в таблицу
        for (int i=0; i<max_size;i++)
        {
            ui->label_max->clear();
            ui->label_min->clear();
            ui->label_sz->clear();
            ui->label_puz->clear();
            ui->label_fast->clear();
            ui->label_gnom->clear();
            ui->label_comb->clear();
            ui->label_monkey->clear();
            ui->label_dubl->clear();
            if(ui->tableWidget->item(i,0)==nullptr)
            {
                QTableWidgetItem * ti;
                ti= new QTableWidgetItem;
                ui->tableWidget->setItem(i,0,ti);
            }
            ui->tableWidget->item(i,0)->setText(QString::number(mas[i]));
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
        }
    }
    else
        ui->label_monkey->setText("Ошибка!Нельзя применить обезьянью сортировку.");
    no_auto_change=true;
}



void MainWindow::on_pushButton_duble_clicked()//обработка кнопки удаления дубликатов
{
    no_auto_change=false;

    int max_size=ui->spinBox->value();//текущий размер массив
    int mas[MAX_MAS];//объявляем массив
    bool fl_gl;//признак успешной конвертации массива
    bool fl_lc;//признак успешной конвертации ячейки

    //формирование массива

    fl_gl=true;
    for (int i=0; i<max_size;i++)
    {
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i]=ui->tableWidget->item(i,0)->text().toInt(&fl_lc);
        }
        else
        {
            fl_lc=false;
            QTableWidgetItem * ti;
            ti= new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,ti);

        }
        if(fl_lc)
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
        else
        {
            fl_gl=false;
            ui->tableWidget->item(i,0)->setBackgroundColor(Qt::red);
        }
    }
    //работа с массивом
    //проверяем массив на отсортированость
    if(fl_gl)
    {
        int sort=0;
        int length=max_size;
        for(int i=0;i<length-1;i++)//Считаем сколько элементов упорядочено по возрастанию, по парная проверка.
        {
            if(mas[i]<=mas[i+1])
                sort++;
        }

        if(sort!=length-1)
        {
            ui->label_dubl->setText("Массив не отсортирован.\nВоспользуйтесь сортировкой массива");
            fl_gl=false;
        }
        else
        {
            ui->label_dubl->clear();
            //удаляем дубликаты
            for (int i = 0; i < length - 1; i++)
               for (int j = i + 1; j < length; j++)
               if (mas[i]==mas[j])
                   {
                   for (int k = j; k < length; k++)
                   mas[k]=mas[k + 1];
                   length--;
                   j--;
                   }
            fl_gl=true;
        }

        if(fl_gl)
        {
            //запись в таблицу
            ui->spinBox->setValue(length);//изменение значение в спинбоксе
            for (int i=0; i<length;i++)
            {
                ui->label_max->clear();
                ui->label_min->clear();
                ui->label_sz->clear();
                ui->label_puz->clear();
                ui->label_fast->clear();
                ui->label_gnom->clear();
                ui->label_comb->clear();
                ui->label_monkey->clear();
                ui->label_dubl->clear();
                if(ui->tableWidget->item(i,0)==nullptr)
                {
                    QTableWidgetItem * ti;
                    ti= new QTableWidgetItem;
                    ui->tableWidget->setItem(i,0,ti);
                }
                    ui->tableWidget->item(i,0)->setText(QString::number(mas[i]));
                    ui->tableWidget->item(i,0)->setBackground(Qt::white);
            }
            ui->pushButton_fast->click();// проводим сортировку в массиве без дубликатов
        }
    }
    else
        ui->label_dubl->setText("Ошибка!");

    no_auto_change=true;
}




void MainWindow::on_pushButton_search_clicked()//обработка кнопки поиска
{
    no_auto_change=false;

    int mas[MAX_MAS];//объявление массива на максимально возмодное кол-во элементов
    int max_size=ui->spinBox->value();//текущий размер массив
    bool fl_gl;//признак успешной конвертации массива
    bool fl_lc;//признак успешной конвертации ячейки
    int count=0;//колo-во совпадений в массиве
    QString linesNumbers = "";
    bool fl=false;//проверка на число
    //int c=0;//переменная для найденной ячейки

    //формирование массива
    fl_gl=true;
    for (int i=0; i<max_size;i++)
    {
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i]=ui->tableWidget->item(i,0)->text().toInt(&fl_lc);
        }
        else
        {
            fl_lc=false;
            QTableWidgetItem * ti;
            ti= new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,ti);

        }
        if(fl_lc)
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
        else
        {
            fl_gl=false;
            ui->tableWidget->item(i,0)->setBackgroundColor(Qt::red);
        }
    }
    //поиск значения
    int x=ui->lineEdit_search->text().toInt(&fl);
    if(!fl)
    {
        QMessageBox::warning(this,"Ошибка","Неверное значение.");
    }
    else
    {
        if(fl_gl)
        {
            for (int i=0; i<max_size;i++)
            {
                if(mas[i]==x)
                {

                    count++;
                    linesNumbers.append(QString::number(i+1));//номер строчки
                    linesNumbers.append(",");// добавления запятой в строчку
                    ui->tableWidget->item(i,0)->setBackground(Qt::green);
                }
            }
        }
        //вывод результата
        if(fl_gl)
        {
            int pos = linesNumbers.lastIndexOf(QChar(','));//находим последнюю запятую
            if(count!=0)
            {
                ui->lineEdit_res->setText(linesNumbers.left(pos));
                ui->label_count->show();
                ui->label_count->setText(QString::number(count));

            }
            else
            {
                ui->lineEdit_search->setText("Число не найдено");
                ui->lineEdit_res->clear();
            }
            ui->label_count->clear();
            ui->label_max->clear();
            ui->label_sz->clear();
            ui->label_puz->clear();
            ui->label_fast->clear();
            ui->label_gnom->clear();
            ui->label_comb->clear();
            ui->label_monkey->clear();
            ui->label_dubl->clear();
        }
    }

    no_auto_change=true;
}

void MainWindow::on_pushButton_const_clicked()//обработка заполнения константой
{
    no_auto_change=false;
    int row=ui->tableWidget->rowCount();
    int constant; //временная переменная
    QString constNum;

    constNum=ui->spinBox_const->text(); //cчитать значение из строки
    constant=constNum.toInt();
    for (int i=0; i<row; i++) //проходим по строкам
    {
        if (ui->tableWidget->item(i, 0)==nullptr) //проверка ячейки
        {
            QTableWidgetItem * ti; //создали указатель
            ti =  new QTableWidgetItem(); //выделяем память
            ui->tableWidget->setItem(i, 0, ti); //помещаем ячейку в таблицу
        }
        ui->tableWidget->item(i, 0)->setBackgroundColor(Qt::white);
        ui->tableWidget->item(i, 0)->setText(QString::number(constant)); //заполнение таблицы константами
    }
    ui->label_count->clear();
    ui->label_max->clear();
    ui->label_sz->clear();
    ui->label_puz->clear();
    ui->label_fast->clear();
    ui->label_gnom->clear();
    ui->label_comb->clear();
    ui->label_monkey->clear();
    ui->label_dubl->clear();
    no_auto_change=true;
}
