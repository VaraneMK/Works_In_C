#ifndef ACTIONWITHGENRE_H
#define ACTIONWITHGENRE_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "database.h"

namespace Ui {
class ActionWithGenre;
}

class ActionWithGenre : public QDialog, private DataBase
{
    Q_OBJECT

public:
    explicit ActionWithGenre(QSqlDatabase *db,QWidget *parent = nullptr);
    void updateAllGenres();//функция обновления жанров
    ~ActionWithGenre();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_close_clicked();

    void on_tabWidget_currentChanged(int index);

private:
    Ui::ActionWithGenre *ui;
};

#endif // ACTIONWITHGENRE_H
