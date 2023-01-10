#ifndef ACTIONWITHHALL_H
#define ACTIONWITHHALL_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "database.h"

namespace Ui {
class ActionWithHall;
}

class ActionWithHall : public QDialog,private DataBase
{
    Q_OBJECT

public:
    explicit ActionWithHall(QSqlDatabase *db,QWidget *parent = nullptr);
    ~ActionWithHall();

private:
    Ui::ActionWithHall *ui;
};

#endif // ACTIONWITHHALL_H
