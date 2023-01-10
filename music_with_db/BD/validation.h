#ifndef VALIDATION_H
#define VALIDATION_H
#include <QRegExp>
namespace validation {

/// Регулярное выражение для проверки логина
Q_GLOBAL_STATIC_WITH_ARGS(QRegExp, loginRegex, ("^[a-zA-Z0-9]+$"));

/// Регулярное выражение для проверки пароля
Q_GLOBAL_STATIC_WITH_ARGS(QRegExp,passwordRegex,("((?=.*\\d)(?=.*[A-Z]).{6,15})"));

Q_GLOBAL_STATIC_WITH_ARGS(QRegExp,participantsRegex,("[^,\\s][^\\,]*[^,\\s]*"));
}
#endif // VALIDATION_H
