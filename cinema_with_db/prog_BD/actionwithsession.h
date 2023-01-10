#ifndef ACTIONWITHSESSION_H
#define ACTIONWITHSESSION_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "database.h"
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QDebug>
#include <QSqlQueryModel>

namespace Ui {
class ActionWithSession;
}

class ActionWithSession : public QDialog,private DataBase
{
    Q_OBJECT

public:
    explicit ActionWithSession(QSqlDatabase *db,QWidget *parent = nullptr);

    void addTickets(QString date,QString time);//функция создания билетов на сеанса

    void addComboBoxItems();//функция добавления элементов в комбобоксы
    void updateAllSessions();//функция обновления всех сеансов

    ~ActionWithSession();

private slots:
    void on_pushButton_close_clicked();

    void on_pushButton_add_clicked();

    void on_dateEdit_dateChanged(const QDate &date);

    void on_tabWidget_currentChanged(int index);

private:
    Ui::ActionWithSession *ui;
    QSqlQueryModel *model;

};

#endif // ACTIONWITHSESSION_H
