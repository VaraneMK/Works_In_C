#ifndef ACTIONWITHMOVIE_H
#define ACTIONWITHMOVIE_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "database.h"

namespace Ui {
class ActionWithMovie;
}

class ActionWithMovie : public QDialog,private DataBase
{
    Q_OBJECT

public:
    explicit ActionWithMovie(QSqlDatabase *db,QWidget *parent = nullptr);
    void addComboBoxItems();//функция добавления элементов в комбобоксы
    void updateAllMovies();//фукнция обновления всех фильмов

    ~ActionWithMovie();

private slots:
    void on_pushButton_close_clicked();

    void on_pushButton_add_clicked();

    void on_tabWidget_currentChanged(int index);

private:
    Ui::ActionWithMovie *ui;
};

#endif // ACTIONWITHMOVIE_H
