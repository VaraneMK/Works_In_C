#include "actionwithhall.h"
#include "ui_actionwithhall.h"

ActionWithHall::ActionWithHall(QSqlDatabase *db, QWidget *parent) :
    QDialog(parent),
    DataBase(parent, db),
    ui(new Ui::ActionWithHall)
{
    ui->setupUi(this);
}

ActionWithHall::~ActionWithHall()
{
    delete ui;
}
