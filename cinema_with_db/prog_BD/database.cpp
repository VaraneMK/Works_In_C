#include "database.h"

DataBase::DataBase(QWidget *parent, QSqlDatabase *newDb)
    : parent(parent), db(newDb) {}
