#include "actionwithmovie.h"
#include "ui_actionwithmovie.h"
#include <QMessageBox>

ActionWithMovie::ActionWithMovie(QSqlDatabase *db, QWidget *parent) :
    QDialog(parent),
    DataBase(parent, db),
    ui(new Ui::ActionWithMovie)//конструктор
{  
    ui->setupUi(this);
    addComboBoxItems();//вызов функции добавления элементов в комбобоксы
    this->setWindowTitle("Добавить фильм");//меняем название окна
    ui->tabWidget->setCurrentIndex(0);
}

ActionWithMovie::~ActionWithMovie()//дестркутор
{
    delete ui;
}

void ActionWithMovie::addComboBoxItems()//функция добавления элементов в комбобоксы
{
    QSqlQuery qw(*db);
    qw.prepare("SELECT genre_name FROM data.genre");
    qw.exec();

    if(qw.lastError().type() == QSqlError::NoError)//если без ошибок
    {
        while(qw.next())
        {
            ui->comboBox_genre->addItem(qw.value(0).toString());//Добавляем все доступные жанры
        }
    }
    else
    {
        QMessageBox::warning(this,"Ошибка",qw.lastError().text());//если произошла ошибка запроса
    }

}


void ActionWithMovie::on_pushButton_close_clicked()//обработка закрытия окна
{
    reject();//закрываем окно
}

void ActionWithMovie::on_pushButton_add_clicked()//обработка добавления фильма
{
    auto name = ui->lineEdit_name->text().trimmed();
    auto cast = ui->lineEdit_cast->text().trimmed();
    auto genre = ui->comboBox_genre->currentText();
    auto duration = ui->spinBox_duration->value();
    auto ageLimit = ui->spinBox_ageLimit->value();

    bool status = true;

    if(ui->lineEdit_name->text()!= nullptr)//проверка на ввод названия
    {
        if(ui->comboBox_genre->currentIndex() != 0)//проверка на выбор жанра
        {
            QSqlQuery qw(*db);//создание экземпляра запроса
            qw.prepare("SELECT genre_id FROM data.genre WHERE genre_name = :name");///запрос для нахождени id жанра
            qw.bindValue(":name",genre);//присвоение значения
            qw.exec();//отправка запроса
            qw.next();
            auto genre_id =qw.value(0).toInt();///сохраняем найденное значение


            qw.prepare("SELECT movie_name,genre_id FROM data.movie");
            qw.exec();
            while (qw.next())
            {
                if(qw.value(0).toString().toLower() == name.toLower() && qw.value(1).toInt() == genre_id) {status = false; break;}
            }
            if(status)
            {


                qw.prepare("INSERT INTO data.movie (movie_name,genre_id,age_limit,duration,acteurs_list) VALUES (:1,:2,:3,:4,:5)");///запрос для добавление фильма
                qw.bindValue(":1",name);
                qw.bindValue(":2",genre_id);
                qw.bindValue(":3",ageLimit);
                qw.bindValue(":4",duration);
                qw.bindValue(":5",cast);

                qw.exec();
                if(qw.lastError().type() == QSqlError::NoError)//если без ошибок
                {
                    ///Очищаем все поля
                    ui->lineEdit_cast->clear();
                    ui->lineEdit_name->clear();
                    ui->comboBox_genre->setCurrentIndex(0);
                    ui->spinBox_ageLimit->setValue(0);
                    ui->spinBox_duration->setValue(0);
                }
                else
                {
                    QMessageBox::warning(this,"Ошибка",qw.lastError().text());//если произошла ошибка запроса
                }
            }
            else
            {
                QMessageBox::warning(this,"Ошибка","Фильм с таким названием и жанром уже существует");
            }
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Выберите жанр фильма");//если не выбран жанр фильма
        }
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Введите название фильма");//если не введено название фильма
    }
}

void ActionWithMovie::on_tabWidget_currentChanged(int index)//обработка переключений рабочих окон
{
    if(index == 1)
    {
        updateAllMovies();
    }
}

void ActionWithMovie::updateAllMovies()//функция обновления списка фильмов
{
    QSqlQuery qw(*db);
    int currentRow = 0;
    qw.prepare("SELECT * FROM data.movie");
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
            for (int i=0;i<4;i++)
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
            ui->tableWidget->item(currentRow,3)->setText(qw.value(4).toString());
            ui->tableWidget->item(currentRow,2)->setText(qw.value(3).toString());

            QSqlQuery query (*db);
            int genre = qw.value(2).toInt();
            query.prepare("SELECT * FROM data.genre WHERE genre_id = :id");
            query.bindValue(":id",genre);
            query.exec();
            query.next();

            ui->tableWidget->item(currentRow,1)->setText(query.value(1).toString());
            currentRow++;
        }
    }
}
