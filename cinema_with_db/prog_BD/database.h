#ifndef DATABASE_H
#define DATABASE_H

#include <QWidget>
#include <QtSql/QSqlDatabase> //БД
#include <QtSql/QSqlError>    //Ошибки
#include <QtSql/QSqlQuery>    //Запросы


class DataBase
{
public:
    DataBase(QWidget *parent, QSqlDatabase *newDb = nullptr);

protected:
    QWidget *parent;
    /// База данных для работы с этим приложением
    QSqlDatabase *db;
};

#endif // DATABASE_H
