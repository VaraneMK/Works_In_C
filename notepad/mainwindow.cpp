#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <qfiledialog.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Блокнот-Новый файл"); // вывод названия
    //decoder= new QTextDecoder(codec);
    ui->statusBar->showMessage("Добро пожаловать!"); //вывод статуса
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Menu_Opem_triggered()
{
    QString fileName;//строка для имени файла
    if(Status==0)
    {
        fileName=QFileDialog::getOpenFileName(this,tr("Открыть файл"),"Z:\\Files",filter);// экранируем слеши (/ в //)
        WindowName=fileName; //сохранения адреса файла
        if(fileName.isEmpty())//файл не выбран
        {
            QMessageBox::information(this,"Ошибка","Файл не выбран");
        }
        else
        {
            FuncOpen(fileName); //вызов функции открытия
        }

    }
    else
    {
        QMessageBox::StandardButton reply;
        reply=QMessageBox::question(this,"Блокнот","Сохраняем изменения?",QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel,QMessageBox::Yes);
        if(reply==QMessageBox::Yes)
        {
            ui->Menu_Save->activate(QAction::Trigger);

            fileName=QFileDialog::getOpenFileName(this,tr("Открыть файл"),"Z:\\Files",filter);// экранируем слеши (/ в //)
            WindowName=fileName;//сохранения адреса файла
            if(fileName.isEmpty())//файл не выбран
            {
                QMessageBox::information(this,"Ошибка","Файл не выбран");
            }
            else
            {
                FuncOpen(fileName); //вызов функции открытия
            }
        }
        else if (reply == QMessageBox::No)
        {
            fileName=QFileDialog::getOpenFileName(this,tr("Открыть файл"),"Z:\\Files",filter);// экранируем слеши (/ в //)
            WindowName=fileName;//сохранения адреса файла
            if(fileName.isEmpty())//файл не выбран
            {
                QMessageBox::information(this,"Ошибка","Файл не выбран");
            }
            else
            {
                FuncOpen(fileName); //вызов функции открытия
            }
        }
    }

}

void MainWindow::on_Menu_SaveAs_triggered()
{
    QString fileName;//строка для имени файла
    fileName=QFileDialog::getSaveFileName(this,tr("Сохранение"),defaultDirectory,filter);// экранируем слеши (/ в //)

    if(fileName.isEmpty())//файл не выбран
    {
        QMessageBox::information(this,"Ошибка","Файл не выбран");
    }
    else
    {
        QFile File;//класс файлов
        File.setFileName(fileName);//связываем с файлом
        File.open(QIODevice::WriteOnly);

        File.write(ui->textEdit->toPlainText().toUtf8());//запись в файл

        File.close();//закрываем файл
        WindowName=fileName; //сохранения адреса файла
        //ui->textEdit->clear();
        ui->statusBar->showMessage("Cохранён файл: " + fileName);
        this->setWindowTitle("Блокнот");
        openfile=false;
        Status=false;
    }
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    QString data=ui->textEdit->toPlainText();
    if(Status==false)
    {
        QMessageBox::StandardButton reply;
        reply=QMessageBox::question(this,"Выход","Точно выходим?",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
        if (reply==QMessageBox::Yes)
        {
            event->accept(); //Принимаем сигнал
        }
        else if(reply==QMessageBox::No)
        {
            event->ignore(); //Игнорируем сигнал
        }

    }
    else
    {
        QMessageBox::StandardButton replySave;
        replySave=QMessageBox::question(this,"Блокнот","Сохраняем изменения?",QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel,QMessageBox::Yes);

        if( replySave==QMessageBox::Yes)
        {
            ui->Menu_Save->activate(QAction::Trigger);


            if (QMessageBox::question(this,"Выход","Точно выходим?",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes)==QMessageBox::Yes)
            {
                event->accept(); //Принимаем сигнал
            }
            else
            {
                event->ignore(); //Игнорируем сигнал
            }

        }
        else if(replySave==QMessageBox::No)
        {
            if (QMessageBox::question(this,"Выход","Точно выходим?",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes)==QMessageBox::Yes)
            {
                event->accept(); //Принимаем сигнал
            }
            else
            {
                event->ignore(); //Игнорируем сигнал
            }
        }
        Status = false;
    }

}

void MainWindow::on_Menu_Create_triggered()
{
    //QString data=ui->textEdit->toPlainText();
    //QFile FileNew("E:\\build-notepad3-Desktop_Qt_6_0_1_MSVC2019_64bit-Debug\\Unnamed.txt");
    QFile File;//класс файлов
    File.setFileName(WindowName); //связываем с файлом

    if (Status==true) //если были произведены изменения
    {
        QMessageBox::StandardButton reply;
        reply=QMessageBox::question(this,"Блокнот","Сохраняем изменения?",QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel,QMessageBox::Yes);
        if(reply==QMessageBox::Yes)
        {
            ui->Menu_Save->activate(QAction::Trigger);
            if(fl)
            {
                ui->textEdit->clear();
                openfile=false;
                Status=false;
                this->setWindowTitle("Блокнот-Новый файл");
            }
        }
        else if (reply == QMessageBox::No)
        {
            ui->textEdit->clear();
            this->setWindowTitle("Блокнот-Новый файл");
            openfile=false;
            Status=false;
        }
    }
    else
    {
        ui->textEdit->clear();
        this->setWindowTitle("Блокнот-Новый файл");
        openfile=false;
        Status=false;
    }

}
void MainWindow::on_Menu_Save_triggered()
{
    QString fileName; //строка для имени файла
    if(openfile==false)
    {
        fileName=QFileDialog::getSaveFileName(this,tr("Сохранить файл"),defaultDirectory,filter);    // экранируем слеши (/ в //)
        if(fileName.isEmpty()) //файл не выбран
        {
            QMessageBox::information(this,"Ошибка","Файл не выбран");
            fl=false;
        }
        else
        {
            QFile File; //класс файлов
            File.setFileName(fileName); //связываем с файлом
            File.open(QIODevice::WriteOnly);

            File.write(ui->textEdit->toPlainText().toUtf8());//запись в файл

            File.close(); //закрываем файл
            WindowName=fileName; //сохранения адреса файла
            ui->statusBar->showMessage("Cохранён файл: " + fileName);
            this->setWindowTitle("Блокнот");
            fl=true;
            openfile=false;
            Status=false;
        }
    }

    else
    {
        QFile File; //класс файлов
        File.setFileName(WindowName); //связываем с файлом
        File.open(QIODevice::WriteOnly);
        File.write(ui->textEdit->toPlainText().toUtf8()); //запись в файл
        ui->statusBar->showMessage("Cохранён файл: " + WindowName);
        this->setWindowTitle("Блокнот");
        File.close(); //закрываем файл
        //openfile=false;
        fl=true;
        Status=false;
    }
}

void MainWindow::on_Menu_Exit_triggered()
{
    QMainWindow::close(); //эффект закрытия окна программы
}

void MainWindow::on_textEdit_textChanged()
{
    Status=true;
    this->setWindowTitle("*Блокнот");
}


void MainWindow::FuncOpen(QString &fileName)
{
    ui->textEdit->clear();
    QFile File; //класс файлов

    File.setFileName(fileName); //связываем с файлом
    File.open(QIODevice::ReadOnly); //Открываем только для чтения

    QByteArray x; //массив для передачи данных
    x.clear();

    qint64 size; //для размера файла
    size=File.size(); //размер файла

    x=File.read(size); //чтение из файла в массив
    ui->textEdit->append(QString(x)); //добавляем массив в текстовое поле



    File.close(); //закрываем файл
    this->setWindowTitle("Блокнот");
    ui->statusBar->showMessage("Открыт файл: " + fileName);
    openfile=true;
    Status=false;
}
