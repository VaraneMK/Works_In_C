#include "actionwithsession.h"
#include "ui_actionwithsession.h"
#include <QMessageBox>

ActionWithSession::ActionWithSession(QSqlDatabase *db, QWidget *parent) :
    QDialog(parent),
    DataBase(parent, db),
    ui(new Ui::ActionWithSession)//конструктор
{
    ui->setupUi(this);
    ui->dateEdit->setMinimumDate(QDate::currentDate());//устанавливаем минимальную дату
    ui->timeEdit->setMinimumTime(QTime::currentTime());//устанавливаем минимальное время
    addComboBoxItems();
    this->setWindowTitle("Добавить сеанс");
    ui->tabWidget->setCurrentIndex(0);

}

ActionWithSession::~ActionWithSession()//деструктор
{
    delete ui;
}

void ActionWithSession::addComboBoxItems()//функция добавления элементов в комбобоксы
{
    QSqlQuery qw(*db);
    qw.prepare("SELECT movie_name FROM data.movie");///запрос для поиска фильмов
    qw.exec();

    if(qw.lastError().type() == QSqlError::NoError)//если без ошибок
    {
        while(qw.next())
        {
            ui->comboBox_movie->addItem(qw.value(0).toString());//Добавляем все доступные жанры
        }
    }
    else
    {
        QMessageBox::warning(this,"Ошибка",qw.lastError().text());//если произошла ошибка запроса
    }



    qw.prepare("SELECT hall_id FROM data.hall");///запрос для поиска залов
    qw.exec();

    if(qw.lastError().type() == QSqlError::NoError)//если без ошибок
    {
        while(qw.next())
        {
            ui->comboBox_hall->addItem(qw.value(0).toString());//Добавляем все доступные жанры
        }
    }
    else
    {
        QMessageBox::warning(this,"Ошибка",qw.lastError().text());//если произошла ошибка запроса
    }

}

void ActionWithSession::on_pushButton_close_clicked()//обработка закрытия окна
{
    reject();///закрываем окно
}

void ActionWithSession::on_pushButton_add_clicked()//обработка добавления сеанса
{
    auto date = ui->dateEdit->date().toString("yyyy-MM-dd");
    auto time = ui->timeEdit->time().toString("hh:mm");
    auto name_movie = ui->comboBox_movie->currentText();
    auto id_hall = ui->comboBox_hall->currentIndex();


    bool status = true;
    if(ui->comboBox_movie->currentIndex()!=0)
    {
        if(ui->comboBox_hall->currentIndex()!=0)
        {
            QSqlQuery qw(*db);
            qw.prepare("SELECT movie_id FROM data.movie WHERE movie_name = :name");///запрос для нахождени id фильма
            qw.bindValue(":name",name_movie);//присвоение значения
            qw.exec();//отправка запроса
            qw.next();
            auto id_movie =qw.value(0).toInt();///сохраняем найденное значение

            qw.prepare("SELECT * FROM data.session WHERE hall_id = :hall AND movie_id = :movie AND session_date = date(:date) AND session_time = :time");
            qw.bindValue(":hall",id_hall);
            qw.bindValue(":movie",id_movie);
            qw.bindValue(":date",date);
            qw.bindValue(":time",time);
            qw.exec();

            if(qw.size()>0) {status = false;}
            if(status)
            {
                qw.prepare("INSERT INTO data.session (hall_id,movie_id,session_date,session_time) VALUES (:1,:2,:3,:4)");///запрос для добавление фильма
                qw.bindValue(":1",id_hall);
                qw.bindValue(":2",id_movie);
                qw.bindValue(":3",date);
                qw.bindValue(":4",time);

                qw.exec();
                if(qw.lastError().type() == QSqlError::NoError)//если без ошибок
                {
                    ///Очищаем все поля
                    ui->dateEdit->setDate(QDate::currentDate());
                    ui->timeEdit->setTime(QTime::currentTime());
                    ui->comboBox_hall->setCurrentIndex(0);
                    ui->comboBox_movie->setCurrentIndex(0);

                    addTickets(date,time);///создаем билеты для этого сеанса
                }
                else
                {
                    QMessageBox::warning(this,"Ошибка",qw.lastError().text());//если произошла ошибка запроса
                }
            }
            else
            {
                QMessageBox::warning(this,"Ошибка","Данный сеанс уже существует");//если данный сеанс уже существует
            }

        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Выберите зал");
        }
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Выберите фильм");
    }
}

void ActionWithSession::addTickets(QString date, QString time)//функция создания билетов для сеанса
{
    ///Добавляем билеты сеанса определяемого по дате и времени
    QSqlQuery qw(*db);
    qw.prepare("SELECT session_id FROM data.session WHERE session_date = date(:date) AND session_time = :time");///запрос для нахождени id сессии
    qw.bindValue(":date",date);//присвоение значения
    qw.bindValue(":time",time);//присвоение значения
    qw.exec();//отправка запроса
    if(qw.lastError().type() == QSqlError::NoError)//если без ошибок
    {
        qw.next();

        auto id_session =qw.value(0).toInt();///сохраняем найденное значение

        for (int i=1 ; i < 11;i++)
        {
            for (int j = 1; j< 8 ; j++)
            {
                qw.prepare("INSERT INTO data.tickets (session_id,row_number,place_number,price) VALUES (:1,:2,:3,:4)");
                qw.bindValue(":1",id_session);
                qw.bindValue(":2",j);
                qw.bindValue(":3",i);
                qw.bindValue(":4",500);

                qw.exec();
                if(qw.lastError().type() != QSqlError::NoError)//если без ошибок
                {
                    QMessageBox::warning(this,"Ошибка",qw.lastError().text());//если произошла ошибка запрос
                }
            }
        }
    }
    else
    {
        QMessageBox::warning(this,"Ошибка",qw.lastError().text());//если произошла ошибка запроса
    }



}

void ActionWithSession::on_dateEdit_dateChanged(const QDate &date)//обработка изменения даты (если выбран сегодняшний день,то минимальное время ставится текущее)
{
    if(date == QDate::currentDate()) {ui->timeEdit->setMinimumTime(QTime::currentTime());}
    else{ui->timeEdit->setMinimumTime(QTime::fromString("00:00","hh:mm")); ui->timeEdit->setTime(QTime::fromString("00:00","hh:mm"));}
}

void ActionWithSession::on_tabWidget_currentChanged(int index)//обработка изменений рабочих окон
{
    if(index == 1)
    {
        updateAllSessions();
    }
}

void ActionWithSession::updateAllSessions()//функция обновления сеансов
{
    QSqlQuery query(*db);
    int currentRow = 0;//текущая строчка

    query.prepare("SELECT * FROM data.session ORDER BY session_date DESC");
    query.exec();
    ui->tableWidget_sessions->setRowCount(query.size());

    if(query.lastError().type() != QSqlError::NoError)
    {
        QMessageBox::warning(this,"Ошибка",query.lastError().text());
    }
    else
    {
        while (query.next())
        {
            for (int i=0;i<5;i++)
            {
                if(ui->tableWidget_sessions->item(currentRow,i) == nullptr)
                {
                    QTableWidgetItem *ti;
                    ti = new QTableWidgetItem;
                    ti->setFlags(ti->flags() & 0x3d);
                    ui->tableWidget_sessions->setItem(currentRow,i,ti);
                }
            }
            ui->tableWidget_sessions->item(currentRow,0)->setText(query.value(1).toString());

            QSqlQuery qw(*db);
            qw.prepare("SELECT * FROM data.movie WHERE movie_id = :id");
            qw.bindValue(":id",query.value(2));
            qw.exec();
            qw.next();
            ui->tableWidget_sessions->item(currentRow,1)->setText(qw.value(1).toString());
            ui->tableWidget_sessions->item(currentRow,3)->setText(query.value(3).toString());
            ui->tableWidget_sessions->item(currentRow,2)->setText(qw.value(4).toString());

            QTime t = QTime::fromString(query.value(4).toString());
            ui->tableWidget_sessions->item(currentRow,4)->setText(t.toString("hh:mm"));

            currentRow++;
        }
    }
}
