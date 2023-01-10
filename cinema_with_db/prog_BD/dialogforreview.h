#ifndef DIALOGFORREVIEW_H
#define DIALOGFORREVIEW_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "database.h"
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QDebug>

namespace Ui {
class DialogForReview;
}

class DialogForReview : public QDialog,private DataBase
{
    Q_OBJECT

public:
    explicit DialogForReview(QSqlDatabase *db,QWidget *parent = nullptr,int movie_id=0,int user_id=0,bool fl = false);
    void updateRating();//функция обновления рейтинга фильма
    ~DialogForReview();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_close_clicked();

private:
    Ui::DialogForReview *ui;

    int user;
    int movie;
    bool status;
};

#endif // DIALOGFORREVIEW_H
