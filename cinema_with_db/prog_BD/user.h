#ifndef USER_H
#define USER_H
#include <QString>
class User
{
public:
    User(int id = 0,QString login = "", QString password = "");

  int id;//id пользователя
  QString login;//логин пользователя
  QString password;//пароль пользователя

};

#endif // USER_H
