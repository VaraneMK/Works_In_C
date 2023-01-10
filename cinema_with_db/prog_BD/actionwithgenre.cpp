#include "actionwithgenre.h"
#include "ui_actionwithgenre.h"
#include<QMessageBox>

ActionWithGenre::ActionWithGenre(QSqlDatabase *db,QWidget *parent) :
    QDialog(parent),
    DataBase(parent, db),
    ui(new Ui::ActionWithGenre) //конструктор
{
    ui->setupUi(this);
    this->setWindowTitle("Добавить жанр");//изменяем имя страницы
    ui->tabWidget->setCurrentIndex(0);
}

ActionWithGenre::~ActionWithGenre()//деструктор
{
    delete ui;
}

void ActionWithGenre::on_pushButton_add_clicked()//обработка добавления жанра
{
    auto name = ui->lineEdit_name->text().trimmed(); // название жанра
    auto description = ui->lineEdit_description->text().trimmed();//описание жанра (необязательное поле)

    if(ui->lineEdit_name->text()!=nullptr)//если введено какое то значение
    {
        QSqlQuery qw(*db);//создаем SQL запрос

        ///проверяем нет ли такого же жанра
        bool status = true;
        qw.prepare("SELECT genre_name FROM data.genre");
        qw.exec();
        while(qw.next())
        {
            if(name.toLower() == qw.value(0).toString().toLower()) {status = false; break;}///проверка на совпадение
        }
        if(status)
        {
            qw.prepare("INSERT INTO data.genre (genre_name,genre_description) VALUES (:1,:2)");
            qw.bindValue(":1",name);//присваиваем значения
            qw.bindValue(":2",description);//присваиваем значения

            qw.exec();//отправляем запрос

            if(qw.lastError().type() != QSqlError::NoError)//если ошибка
            {
                QMessageBox::warning(this,"Ошибка",qw.lastError().text());//вывод ошибки
            }
            else
            {
                ui->lineEdit_name->clear();//очищаем поля
                ui->lineEdit_description->clear();
            }
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Данный жанр уже существует");//вывод ошибки
        }
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Введите название жанра");
    }
}

void ActionWithGenre::on_pushButton_close_clicked()//обработка закрытия окна
{
    reject();//закрываем окно
}

void ActionWithGenre::on_tabWidget_currentChanged(int index)//обработка переключений рабочих окно
{
    if(index == 1)
    {
        updateAllGenres();
    }
}


void ActionWithGenre::updateAllGenres()//функция обновления списка жанров
{
    QSqlQuery qw(*db);
    int currentRow = 0;
    qw.prepare("SELECT * FROM data.genre");
    qw.exec();
    ui->tableWidget->setRowCount(qw.size());

    if(qw.lastError().type() != QSqlError::NoError)
    {
        QMessageBox::warning(this,"Ошибка",qw.lastError().text());
    }
    else
    {
        while (qw.next())
        {
            for (int i=0;i<2;i++)
            {
                if(ui->tableWidget->item(currentRow,i) == nullptr)
                {
                    QTableWidgetItem *ti;
                    ti = new QTableWidgetItem;
                    ti->setFlags(ti->flags() & 0x3d);
                    ui->tableWidget->setItem(currentRow,i,ti);
                }
            }

            ui->tableWidget->item(currentRow,0)->setText(qw.value(1).toString());
            ui->tableWidget->item(currentRow,1)->setText(qw.value(2).toString());
            currentRow++;
        }
    }
}
