#ifndef USER_H
#define USER_H
#include <QString>
class user
{
public:
    user(int id = 0,QString login = "", QString password = "");

  int id;
  QString login;
  QString password;

};

#endif // USER_H
