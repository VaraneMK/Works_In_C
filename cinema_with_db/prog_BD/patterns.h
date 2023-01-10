#ifndef PATTERNS_H
#define PATTERNS_H
#include <QRegExp>

namespace patterns {

/// Регулярное выражение для проверки логина
Q_GLOBAL_STATIC_WITH_ARGS(QRegExp, loginRegex, ("^[a-zA-Z0-9]+$"));

/// Регулярное выражение для проверки почты
Q_GLOBAL_STATIC_WITH_ARGS(QRegExp, emailRegex, ("^.+@.+\\..+$"));

/// Регулярное выражение для проверки пароля
Q_GLOBAL_STATIC_WITH_ARGS(QRegExp,passwordRegex,("((?=.*\\d)(?=.*[a-z])(?=.*[A-Z]).{6,20})"));

/// Типичный формат отображения даты
Q_GLOBAL_STATIC_WITH_ARGS(QRegExp, dateFormat, (R"((0[1-9]|[12][0-9]|3[01])[- /.](0[1-9]|1[012])[- /.](19|20\d\d))"));
}

#endif // PATTERNS_H
