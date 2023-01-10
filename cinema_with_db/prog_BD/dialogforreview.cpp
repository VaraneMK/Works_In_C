#include "dialogforreview.h"
#include "ui_dialogforreview.h"
#include <QMessageBox>

DialogForReview::DialogForReview(QSqlDatabase *db, QWidget *parent, int movie_id, int user_id, bool fl) :
    QDialog(parent),
    DataBase(parent, db),
    ui(new Ui::DialogForReview)//конструктор
{
    ui->setupUi(this);
    //Считываем переданные значения
    movie = movie_id;
    user = user_id;
    status = fl;

    if(status)//если это режим изменения отзыва , то ищем и выводим старые значения
    {
        QSqlQuery qw(*db);
        qw.prepare("SELECT * FROM data.reviews WHERE movie_id = :1 AND viewer_id = :2");
        qw.bindValue(":1",movie);
        qw.bindValue(":2",user);
        qw.exec();
        qw.next();

        ui->spinBox_estimation->setValue(qw.value(3).toInt());
        ui->lineEdit_review->setPlaceholderText(qw.value(4).toString());
    }
}

DialogForReview::~DialogForReview()//деструктор
{
    delete ui;
}

void DialogForReview::updateRating()//функция обновления рейтинга фильма
{
    QSqlQuery qw(*db);
    qw.prepare("SELECT AVG(estimation) FROM data.reviews WHERE movie_id = :1");
    qw.bindValue(":1",movie);
    qw.exec();
    qw.next();

    double rating = qw.value(0).toDouble();
    qw.prepare("UPDATE data.movie SET rating = :1 WHERE movie_id = :2");
    qw.bindValue(":1",rating);
    qw.bindValue(":2",movie);
    qw.exec();

}

void DialogForReview::on_pushButton_add_clicked()//обработка добавления отзыва
{
    QSqlQuery qw(*db);

    if(status)
    {
        qw.prepare("UPDATE data.reviews SET estimation =:3,description =:4,date= :5 WHERE movie_id = :1 AND viewer_id = :2");
        qw.bindValue(":1",movie);
        qw.bindValue(":2",user);
        qw.bindValue(":3",ui->spinBox_estimation->value());
        qw.bindValue(":4",ui->lineEdit_review->text().trimmed());
        qw.bindValue(":5",QDate::currentDate().toString("yyyy-MM-dd"));
    }
    else
    {
        qw.prepare("INSERT INTO data.reviews (movie_id,viewer_id,estimation,description,date) VALUES (:1,:2,:3,:4,:5)");
        qw.bindValue(":1",movie);
        qw.bindValue(":2",user);
        qw.bindValue(":3",ui->spinBox_estimation->value());
        qw.bindValue(":4",ui->lineEdit_review->text().trimmed());
        qw.bindValue(":5",QDate::currentDate().toString("yyyy-MM-dd"));
    }
    qw.exec();
    if(qw.lastError().type() == QSqlError::NoError)
    {
        if(status)
        {
            QMessageBox::information(this,"Успешно","Отзыв изменен");
            updateRating();
        }
        else
        {
            QMessageBox::information(this,"Успешно","Отзыв отправлен");
            updateRating();
        }
        reject();//закрытие окна
    }
    else
    {
        QMessageBox::warning(this,"Ошибка",qw.lastError().text());
    }
}

void DialogForReview::on_pushButton_close_clicked()//обработка закрытия окна
{
    reject();//закрытие окна
}
