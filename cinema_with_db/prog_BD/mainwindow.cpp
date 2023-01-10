#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : // конструктор
    QMainWindow(parent),
    DataBase(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    user = new User();//создаем экземпляр класса User для хранения в нем данных о подключаемом пользователе
    connectToBD(); // подключаемся к бд
    this->setWindowTitle("Кинотеатр");
    //=====1 cтраничка=======
    ui->frame_reg->hide();//прячем окно регистрации
    ui->radioButton_user->click();//кликаем на кнопку пользователя
    ui->tabWidget->setTabEnabled(1,false);//отключаем рабочие окна
    ui->tabWidget->setTabEnabled(2,false);//отключаем рабочие окна
    ui->tabWidget->setTabEnabled(3,false);//отключаем рабочие окна
    ui->tabWidget->setTabEnabled(4,false);//отключаем рабочие окна
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);//включаем маскировщик вводимого текста в полях паролей
    ui->lineEdit_regPassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);//включаем маскировщик вводимого текста в полях паролей
    ui->calendarWidget->setMinimumDate(QDate::currentDate());//ставим минимальную дату для выбора в календаре текущую дату

    //======2 страничка======
    ui->frame_movieInfo->hide();//прячем окно информации о фильме
    ui->lineEdit_name->setReadOnly(true);//включаем режим только для чтения в полях вывода информации
    ui->lineEdit_genre->setReadOnly(true);//включаем режим только для чтения в полях вывода информации
    ui->lineEdit_ageLimit->setReadOnly(true);//включаем режим только для чтения в полях вывода информации
    ui->lineEdit_duration->setReadOnly(true);//включаем режим только для чтения в полях вывода информации
    ui->textEdit_acteurs->setReadOnly(true);//включаем режим только для чтения в полях вывода информации
    ui->textEdit_reviews->setReadOnly(true);//включаем режим только для чтения в полях вывода информации
    ui->spinBox_numberRow->setReadOnly(true);//включаем режим только для чтения в полях вывода информации
    ui->spinBox_numberPlace->setReadOnly(true);//включаем режим только для чтения в полях вывода информации
    ui->lineEdit_rating->setReadOnly(true);//включаем режим только для чтения в полях вывода информации

    //===========3 страничка===========
    ui->lineEdit_money->setReadOnly(true);//включаем режим только для чтения в полях вывода информации

}

MainWindow::~MainWindow() //деструктор
{
    delete db;
    delete ui;
}

QString MainWindow::hashPassword(QString str)//функция хеширования вводимого пароля
{
    // Создания объекта хэша и запись данных в него
    QCryptographicHash crypto(QCryptographicHash::Md5);
    crypto.addData(str.toUtf8());
    // Собственно хэширование и превращение результата в строку
    return QString::fromUtf8(crypto.result().toHex());
}

void MainWindow::connectToBD()//функция подключения к БД
{
    //=====================Подключение к бд============================
    db = new QSqlDatabase(QSqlDatabase::addDatabase("QPSQL"));
    QString dbName("Cinema"); // имя БД
    QString host("127.0.0.1");//адрес сервера
    QString usr("postgres"); // логин
    QString pwd("123");//пароль

    db->setDatabaseName(dbName);
    db->setHostName(host);
    db->setUserName(usr);
    db->setPassword(pwd);
    db->setPort(5432);

    db->open();
}


bool MainWindow::checkForLogin(QString login, QString password)//функция для данных входа пользователя
{
    bool status = false;//для возвращения результата
    QSqlQuery query(*db);//создает экземпляр класса QSqlQuery
    auto hash = hashPassword(password);
    if(ui->radioButton_user->isChecked())//если выбран пользователь
    {
        query.prepare(QString("SELECT * from data.viewer"));//подготавливаем запрос для поиска всех данных из таблицы viewer
    }
    else if(ui->radioButton_admin->isChecked())//если выбран админ
    {
        query.prepare(QString("SELECT * from data.admin"));//подготавливаем запрос для поиска всех данных из таблицы admin
    }

    query.exec();//выполняем запрос

    if(query.lastError().type() != QSqlError::NoError)//если возникла ошибка запроса
    {
        QMessageBox::warning(this,"Ошибка",query.lastError().text());//вывод ошибки
    }
    else
    {
        while(query.next())//обрабатываем каждую найденную строку
        {
            //записываем необходимые данные в переменные
            auto idFromDB = query.value(0).toInt();
            auto loginFromDB = query.value(1).toString().trimmed();
            auto passwordFromDB = query.value(2).toString().trimmed();

            if (loginFromDB == login && passwordFromDB == hash)//если нашли совпадение
            {

                user->id = idFromDB;                // Записываем данные пользователя в экземпляр класса для упрощения дальнейших манипуляций
                user->login = loginFromDB;
                user->password = password;

                status = true;
                break;//выходим из цикла
            }
        }
    }
    return status;//возвращаем результат
}

void MainWindow::on_pushButton_enter_clicked()//обработка нажатия кнопки входа
{
    auto login = ui->lineEdit_login->text().trimmed();          //считываем введенный логин
    auto password = ui->lineEdit_password->text().trimmed();    //считываем введенный пароль
    if(db->open())//если БД открыта
    {
        if ((ui->lineEdit_login->text()!=nullptr) && (ui->lineEdit_password->text()!=nullptr))//если хотя бы что то введено
        {
            if(checkForLogin(login,password))//проверяем наличие данного пользователя в БД
            {
                QMessageBox::information(this,"Авторизация","Авторизация прошла успешно");//вывод окна успешной авторизации
                if(ui->radioButton_user->isChecked())
                {
                    //включаем нужные рабочие окна
                    ui->tabWidget->setTabEnabled(1,true);
                    ui->tabWidget->setTabEnabled(2,true);
                    ui->tabWidget->setTabEnabled(3,true);
                    ui->tabWidget->setTabEnabled(4,false);
                    ui->tabWidget->setCurrentIndex(1);
                    ui->pushButton_enter->setEnabled(false);
                }
                if(ui->radioButton_admin->isChecked())
                {
                    //включаем нужные рабочие окна
                    ui->tabWidget->setTabEnabled(1,false);
                    ui->tabWidget->setTabEnabled(2,false);
                    ui->tabWidget->setTabEnabled(3,false);
                    ui->tabWidget->setTabEnabled(4,true);
                    ui->tabWidget->setCurrentIndex(4);
                    ui->pushButton_enter->setEnabled(false);

                }
            }
            else//если пользователь не был найден
            {
                QMessageBox::warning(this,"Авторизация","Пользователь с таким логином и паролем не был найден");//ошибка
                ui->tabWidget->setTabEnabled(1,false);
                ui->tabWidget->setTabEnabled(2,false);
                ui->tabWidget->setTabEnabled(3,false);
                ui->tabWidget->setTabEnabled(4,false);
            }
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Введите логин и пароль");
        }
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","БД не подключена");
    }
}
void MainWindow::on_pushButton_viewReg_clicked() // открытие окна регистрации
{
    if(ui->radioButton_user->isChecked())
    {
        ui->lineEdit_regBD->show();
        ui->lineEdit_regEmail->show();
    }
    else if (ui->radioButton_admin->isChecked())
    {
        ui->lineEdit_regBD->hide();
        ui->lineEdit_regEmail->hide();
    }
    ui->frame_reg->show();
}

void MainWindow::clearRegFrame()//функция очистки окна регистрации
{
    ui->lineEdit_regBD->clear();
    ui->lineEdit_regEmail->clear();
    ui->lineEdit_regLogin->clear();
    ui->lineEdit_regPassword->clear();
}


void MainWindow::on_pushButton_reg_clicked()//обработка нажатия кнопки регистрации
{
    //записываем введенные значения в переменные
    auto login = ui->lineEdit_regLogin->text().trimmed();
    auto password = ui->lineEdit_regPassword->text().trimmed();
    auto bd = ui->lineEdit_regBD->text().trimmed();
    auto email = ui->lineEdit_regEmail->text().trimmed();

    bool check = true;

    if(ui->radioButton_user->isChecked())
    {
        //проводим проверки на условия Логина Пароля Почты Даты Рождения через регулярные выражения
        if(login.length()<4)
        {
            QMessageBox::warning(this,"Ошибка","Логин должен содержать 4 и более символов");
            check = false;
        }
        else if(!login.contains(*patterns::loginRegex))
        {
            QMessageBox::warning(this,"Ошибка","Логин может содержать только латинские буквы и цифры");
            check = false;
        }
        else if (password.length() < 6 && password.length() > 15)
        {
            QMessageBox::warning(this,"Ошибка","Пароль должен содержать от 6 до 15");
            check = false;
        }
        else if (!password.contains(*patterns::passwordRegex))
        {
            QMessageBox::warning(this,"Ошибка","Пароль должен содержать cтрочные и прописные латинские буквы, цифры");
            check = false;
        }
        else if (!bd.contains(*patterns::dateFormat))
        {
            QMessageBox::warning(this,"Ошибка","Введен неверный формат даты. Дата должна быть в формате ДД.ММ.ГГГГ");
            check = false;
        }
        else if(ui->lineEdit_regEmail->text()!=nullptr)
        {
            if(!email.contains(*patterns::emailRegex))
            {
                QMessageBox::warning(this,"Ошибка","Введена некорректная почта");
                check = false;
            }
        }

    }
    else if(ui->radioButton_admin->isChecked())
    {
        if(login.length()<4)
        {
            QMessageBox::warning(this,"Ошибка","Логин должен содержать 4 и более символов");
            check = false;
        }
        else if(!login.contains(*patterns::loginRegex))
        {
            QMessageBox::warning(this,"Ошибка","Логин может содержать только латинские буквы и цифры");
            check = false;
        }
        else if (password.length() < 6 && password.length() > 15)
        {
            QMessageBox::warning(this,"Ошибка","Пароль должен содержать от 6 до 15");
            check = false;
        }
        else if (!password.contains(*patterns::passwordRegex))
        {
            QMessageBox::warning(this,"Ошибка","Пароль должен содержать cтрочные и прописные латинские буквы, цифры");
            check = false;
        }
    }

    if(check)//если все проверки пройдены
    {
        if(ui->radioButton_user->isChecked())
        {
            if ((ui->lineEdit_regLogin->text()!=nullptr) && (ui->lineEdit_regPassword->text()!=nullptr) && (ui->lineEdit_regBD->text()!=nullptr))
            {
                registerData(login,password,bd,email);//вызываем функцию регистрации
                clearRegFrame();//очищаем окно
            }
            else
            {
                QMessageBox::warning(this,"Ошибка","Введите данные во все обязательные поля *");
            }
        }
        else if (ui->radioButton_admin->isChecked())
        {
            if ((ui->lineEdit_regLogin->text()!=nullptr) && (ui->lineEdit_regPassword->text()!=nullptr))
            {
                registerData(login,password);
                clearRegFrame();
            }
            else
            {
                QMessageBox::warning(this,"Ошибка","Введите логин и пароль");
            }
        }
    }
}

void MainWindow::registerData(QString login, QString password,QString bd,QString email,QString phoneNumber)//функция регистрации данных
{
    if(db->open())
    {
        if(!checkLoginForRegister(login))//проверяем, используется ли такой логин или нет
        {
            auto hash = hashPassword(password);
            QSqlQuery query(*db);
            if(ui->radioButton_user->isChecked())
            {
                query.prepare("INSERT INTO data.viewer (login,password,birthdate,phone_number,email) "
                              "VALUES (:log,:pass,:bd,:ph,:email);");//запрос для записи данных в таблицу viewer

                bd = QDate::fromString(bd,"dd.MM.yyyy").toString("yyyy-MM-dd");                 //форматируем дату в формат, используемый в БД
                //заменяем значения в запросе
                query.bindValue(":log",login);
                query.bindValue(":pass",hash);
                query.bindValue(":bd",bd);
                query.bindValue(":ph",email);
                query.bindValue(":email",phoneNumber);
            }
            else if(ui->radioButton_admin->isChecked())
            {
                query.prepare("INSERT INTO data.admin (login,password) VALUES (:1,:2);");//запрос для записи данных в таблицу admin
                query.bindValue(":1",login);
                query.bindValue(":2",hash);
            }
            query.exec();
            if(query.lastError().type() == QSqlError::NoError)                                  //проверка на выполнение запрос
            {
                QMessageBox::information(this,"Регистрация","Регистрация прошла успешно.");
                ui->frame_reg->hide();
            }
            else {
                QMessageBox::warning(this,"Ошибка",query.lastError().text());
            }
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Пользователь с таким логином уже существует!");
        }

    }
    else {
        QMessageBox::warning(this,"Ошибка","БД не открыта");
    }
}


bool MainWindow::checkLoginForRegister(QString login)//функция для проверки уникальности введенного логина
{
    QSqlQuery query(*db);

    bool status = false;// для проверки наличия пользователя

    if(ui->radioButton_user->isChecked())
    {
        query.prepare(QString("SELECT * from data.viewer"));
    }
    else if(ui->radioButton_admin->isChecked())
    {
        query.prepare(QString("SELECT * from data.admin"));
    }
    query.exec();
    if(query.lastError().type() == QSqlError::NoError)
    {
        while(query.next())
        {
            auto loginFromDB = query.value(1).toString().trimmed();
            if (loginFromDB == login)//если такой логин существует
            {
                status = true;
                break;
            }
        }
    }
    else
    {
        QMessageBox::warning(this,"Ошибка",query.lastError().text());
    }
    return status;
}

void MainWindow::on_pushButton_closeRegFrame_clicked()//обработка нажатия на кнопку закрытия окна регистрации
{
    clearRegFrame();
    ui->frame_reg->hide();
}

void MainWindow::on_pushButton_echoChange_clicked()//показать вводимый пароль
{
    if(echoMode)
    {
        ui->lineEdit_password->setEchoMode(QLineEdit::Normal);
        echoMode = false;
    }
    else
    {
        ui->lineEdit_password->setEchoMode(QLineEdit::Password);
        echoMode = true;
    }
}


void MainWindow::on_tabWidget_currentChanged(int index)//обработка изменений рабочих окон
{
    updateInfo(index);//Функция для изменений информации в рабочем окне
}


void MainWindow::updateInfo(int index)//Функция для изменений информации в рабочем окне
{
    switch (index)
    {
    case 1:
        ui->frame_movieInfo->hide();
        checkSessions();//вывод сессий
        break;
    case 2:
        basketList();//вывод корзины
        break;
    case 3:
        ticketsHistory();//вывод истории покупок
        moviesHistory();//вывод истории просмотров
        break;
    }
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)//обработка изменений выбранной даты в календаре
{
    currentDate = date.toString("yyyy-MM-dd");
    ui->label_sessionInfo->setText("Сеансы "+date.toString("dd.MM.yyyy"));//обновляем информационное поле
    checkSessions();
}


void MainWindow::checkSessions()//функция для вывода всех доступных сеансов
{
    QSqlQuery query(*db);
    int currentRow = 0;//текущая строчка
    QString movie = ui->lineEdit_search->text().trimmed();

    if(ui->lineEdit_search->text().trimmed()!=nullptr)
    {
        if(currentDate == QDate::currentDate().toString("yyyy-MM-dd"))//если выбран сегодняшний день
        {
            if(movie == "*")//если введен спец знак для поиска любых фильмов
            {
                query.prepare("SELECT * FROM data.session WHERE session_date = date(:date) AND session_time > :time ORDER BY session_time");//запрос для поиска сеанса
                query.bindValue(":date",currentDate);
                query.bindValue(":time",QTime::currentTime().toString());
            }
            else
            {
                query.prepare("SELECT * FROM data.session WHERE movie_id IN(SELECT movie_id FROM data.movie WHERE movie_name ILIKE :movie) "
                              "AND session_date = date(:date) AND session_time > :time ORDER BY session_time");//запрос для поиска сеанса
                query.bindValue(":movie",movie);
                query.bindValue(":date",currentDate);
                query.bindValue(":time",QTime::currentTime().toString());
            }
        }
        else
        {
            if(movie == "*")
            {
                query.prepare("SELECT * FROM data.session  WHERE  session_date = date(:date) ORDER BY session_time");//запрос для поиска сеанса
                query.bindValue(":date",currentDate);
            }
            else
            {
                query.prepare("SELECT * FROM data.session  WHERE movie_id IN(SELECT movie_id FROM data.movie WHERE movie_name ILIKE :movie) "
                              "AND session_date = date(:date)"
                              "ORDER BY session_time");//запрос для поиска сеанса
                query.bindValue(":movie",movie);
                query.bindValue(":date",currentDate);
            }
        }

        //        QPainter painter;
        //        painter.setRenderHint(QPainter::Antialiasing, true);
        //        painter.setPen(QPen(QColor(0,120,215)));
    }
    else
    {
        if(currentDate == QDate::currentDate().toString("yyyy-MM-dd"))
        {
            query.prepare("SELECT * FROM data.session WHERE session_date = date(:date) AND session_time > :time ORDER BY session_time;");
            query.bindValue(":date",currentDate);
            query.bindValue(":time",QTime::currentTime().toString());
        }
        else {
            query.prepare("SELECT * FROM data.session WHERE session_date = date(:date) ORDER BY session_time;");
            query.bindValue(":date",currentDate);
        }

    }

    query.exec();
    ui->tableWidget_sessions->setRowCount(query.size());

    if(query.lastError().type() != QSqlError::NoError)
    {
        QMessageBox::warning(this,"Ошибка",query.lastError().text());
    }
    else
    {
        while (query.next())
        {
            for (int i=0;i<5;i++)
            {
                if(ui->tableWidget_sessions->item(currentRow,i) == nullptr)
                {
                    QTableWidgetItem *ti;
                    ti = new QTableWidgetItem;
                    ti->setFlags(ti->flags() & 0x3d);
                    ui->tableWidget_sessions->setItem(currentRow,i,ti);
                }
            }
            ui->tableWidget_sessions->item(currentRow,0)->setText(query.value(1).toString());

            QSqlQuery qw(*db);
            qw.prepare("SELECT * FROM data.movie WHERE movie_id = :id");
            qw.bindValue(":id",query.value(2));
            qw.exec();
            qw.next();
            ui->tableWidget_sessions->item(currentRow,1)->setText(qw.value(1).toString());

            ui->tableWidget_sessions->item(currentRow,2)->setText(qw.value(4).toString());

            QTime t = QTime::fromString(query.value(4).toString());
            ui->tableWidget_sessions->item(currentRow,3)->setText(t.toString("hh:mm"));

            QPushButton * pb = new QPushButton;
            pb->setText("Подробнее");
            pb->setProperty("id",query.value(0));
            connect(pb, SIGNAL(clicked()), this, SLOT(movieInfo()));
            ui->tableWidget_sessions->setCellWidget(currentRow, 4, pb);

            currentRow++;
        }
    }
}

void MainWindow::on_pushButton_search_clicked()//обработка нажатия на кнопку поиска
{
    checkSessions();
}

void MainWindow::ticketsHistory()//функция для обновления истории покупок билетов
{
    QSqlQuery query(*db);
    int currentRow = 0;

    query.prepare("SELECT * from data.tickets WHERE viewer_id = :id");//запрос для поиска билетов пользователя
    query.bindValue(":id",user->id);
    query.exec();
    ui->tableWidget_tickets->setRowCount(query.size());

    if(query.lastError().type() != QSqlError::NoError)
    {
        QMessageBox::warning(this,"Ошибка",query.lastError().text());
    }
    else
    {
        while (query.next())
        {
            for (int i=0;i<6;i++)
            {
                if(ui->tableWidget_tickets->item(currentRow,i) == nullptr)
                {
                    QTableWidgetItem *ti;
                    ti = new QTableWidgetItem;
                    ti->setFlags(ti->flags() & 0x3d);
                    ui->tableWidget_tickets->setItem(currentRow,i,ti);
                }
            }
            QSqlQuery qw(*db);

            qw.prepare("SELECT * FROM data.session WHERE session_id = :id");
            qw.bindValue(":id",query.value(2));
            qw.exec();
            qw.next();
            ui->tableWidget_tickets->item(currentRow,0)->setText(qw.value(3).toString());
            ui->tableWidget_tickets->item(currentRow,1)->setText(qw.value(4).toString().remove(4,7));
            ui->tableWidget_tickets->item(currentRow,3)->setText(qw.value(1).toString());

            int movie_id = qw.value(2).toInt();

            qw.prepare("SELECT * FROM data.movie WHERE movie_id = :id");
            qw.bindValue(":id",movie_id);
            qw.exec();
            qw.next();
            ui->tableWidget_tickets->item(currentRow,2)->setText(qw.value(1).toString());

            ui->tableWidget_tickets->item(currentRow,4)->setText(query.value(3).toString());
            ui->tableWidget_tickets->item(currentRow,5)->setText(query.value(4).toString());



            currentRow++;
        }
    }
}


void MainWindow::moviesHistory()//не отвечает ни за что
{
    ui->tableWidget_history->setRowCount(0);
    QSqlQuery query(*db);
    int currentRow = 0;
    QVector<int> movies;// для сохранения всех уникальных фильмов
    query.prepare("SELECT * from data.tickets WHERE viewer_id = :id");//запрос для поиска билетов пользователя
    query.bindValue(":id",user->id);
    query.exec();

    if(query.lastError().type() != QSqlError::NoError)
    {
        QMessageBox::warning(this,"Ошибка",query.lastError().text());
    }
    else
    {
        while (query.next())
        {
            QSqlQuery qw(*db);

            qw.prepare("SELECT * FROM data.session WHERE session_id = :id");
            qw.bindValue(":id",query.value(2));//поиск сеанса через купленный билет
            qw.exec();
            qw.next();

            int movie_id = qw.value(2).toInt();
            bool status = true;
            for(int i = 0;i<movies.size();i++)
            {
                if(movie_id == movies[i]){status = false; break;}
            }
            if(status)
            {
                movies.append(movie_id);
            }
        }
        ui->tableWidget_history->setRowCount(movies.size());
        for(int i = 0;i<movies.size();i++)
        {

            for (int j=0;j<2;j++)
            {
                if(ui->tableWidget_history->item(currentRow,j) == nullptr)
                {
                    QTableWidgetItem *ti;
                    ti = new QTableWidgetItem;
                    ti->setFlags(ti->flags() & 0x3d);
                    ui->tableWidget_history->setItem(currentRow,j,ti);
                }
            }
            query.prepare("SELECT movie_name FROM data.movie WHERE movie_id = :1");
            query.bindValue(":1",movies[i]);
            query.exec();
            query.next();

            ui->tableWidget_history->item(currentRow,0)->setText(query.value(0).toString());

            QPushButton *pb = new QPushButton;

            query.prepare("SELECT * FROM data.reviews WHERE movie_id = :1 AND viewer_id = :2");
            query.bindValue(":1",movies[i]);
            query.bindValue(":2",user->id);
            query.exec();
            if(query.size()>0)
            {
                pb->setText("Изменить отзыв");
                pb->setProperty("user_id",user->id);
                pb->setProperty("movie_id",movies[i]);
                pb->setProperty("bool",true);
            }
            else
            {
                pb->setText("Создать");
                pb->setProperty("user_id",user->id);
                pb->setProperty("movie_id",movies[i]);
                pb->setProperty("bool",false);
            }

            connect(pb, SIGNAL(clicked()), this, SLOT(setReviews()));
            ui->tableWidget_history->setCellWidget(currentRow, 1, pb);
            currentRow++;
        }
    }
}

void MainWindow::setReviews()//функция для отправки отзыва
{
    QPushButton * cbox = qobject_cast<QPushButton *>(sender());
    int user = cbox->property("user_id").toInt();
    int movie = cbox->property("movie_id").toInt();
    bool fl = cbox->property("bool").toBool();
    DialogForReview * dialog = new DialogForReview(db,this,movie,user,fl);//создаем диалоговое окно для ввода отзыва
    dialog->setModal(true);//делаем окно модальным
    auto x = dialog->exec();//вызываем окно
    if(x == QDialog::Rejected)
    {
           QTimer::singleShot(100,this,SLOT(timer()));
    }
}

void MainWindow::timer()//функция обработки таймера
{
    moviesHistory();
}

void MainWindow::basketList()//функция для обновления корзины пользователя
{
    QSqlQuery query(*db);
    int currentRow = 0;

    query.prepare("SELECT * FROM data.tickets WHERE ticket_id IN(SELECT id_ticket FROM data.basket WHERE id_user = :id)");
    query.bindValue(":id",user->id);
    query.exec();

    ui->tableWidget_basket->setRowCount(query.size());

    if(query.lastError().type() != QSqlError::NoError)
    {
        QMessageBox::warning(this,"Ошибка",query.lastError().text());
    }
    else
    {
        while (query.next())
        {
            for (int i=0;i<8;i++)
            {
                if(ui->tableWidget_basket->item(currentRow,i) == nullptr)
                {
                    QTableWidgetItem *ti;
                    ti = new QTableWidgetItem;
                    ti->setFlags(ti->flags() & 0x3d);
                    ui->tableWidget_basket->setItem(currentRow,i,ti);
                }
            }
            ui->tableWidget_basket->item(currentRow,4)->setText(query.value(3).toString());
            ui->tableWidget_basket->item(currentRow,5)->setText(query.value(4).toString());

            QSqlQuery qw(*db);
            qw.prepare("SELECT * FROM data.session WHERE session_id = :id");
            qw.bindValue(":id",query.value(2).toInt());
            qw.exec();
            qw.next();
            ui->tableWidget_basket->item(currentRow,3)->setText(qw.value(2).toString());

            ui->tableWidget_basket->item(currentRow,0)->setText(qw.value(3).toString());

            ui->tableWidget_basket->item(currentRow,1)->setText(qw.value(4).toString().remove(4,7));

            QPushButton * pb_buy = new QPushButton;
            pb_buy->setText("Купить");
            pb_buy->setProperty("id_ticket",query.value(0));
            connect(pb_buy, SIGNAL(clicked()), this, SLOT(buyTicket()));
            ui->tableWidget_basket->setCellWidget(currentRow, 6, pb_buy);

            QPushButton * pb_delete = new QPushButton;
            pb_delete->setText("Удалить");
            pb_delete->setProperty("id_ticket",query.value(0));
            connect(pb_delete, SIGNAL(clicked()), this, SLOT(deleteTicket()));
            ui->tableWidget_basket->setCellWidget(currentRow, 7, pb_delete);


            int id_movie = qw.value(2).toInt();

            qw.prepare("SELECT movie_name FROM data.movie WHERE movie_id = :id");
            qw.bindValue(":id",id_movie);
            qw.exec();
            qw.next();

            ui->tableWidget_basket->item(currentRow,2)->setText(qw.value(0).toString());
            currentRow++;
        }
    }
}

void MainWindow::buyTicket()//функция для обработки покупки билета пользователем
{
    QPushButton * cbox = qobject_cast<QPushButton *>(sender());
    int id_ticket = cbox->property("id_ticket").toInt();
    QSqlQuery qw(*db);
    qw.prepare("SELECT viewer_id FROM data.tickets WHERE ticket_id = :ticket");
    qw.bindValue(":ticket",id_ticket);
    qw.exec();
    qw.next();
    if(qw.value(0).isNull())
    {
        qw.prepare("UPDATE data.tickets SET viewer_id = :id WHERE ticket_id = :ticket");
        qw.bindValue(":id",user->id);
        qw.bindValue(":ticket",id_ticket);
        qw.exec();

        if(qw.lastError().type() == QSqlError::NoError)
        {
            QMessageBox::information(this,"Успешно","Билет куплен");
            deleteFromBasket(id_ticket);
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Нефтяной запас иссяк :(");
        }
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Этот билет уже купили :(");
        deleteFromBasket(id_ticket);
    }


}
void MainWindow::deleteFromBasket(int ticket_id)//функция для обработки удаления билета из корзины пользователя
{
    QSqlQuery qw(*db);
    qw.prepare("DELETE FROM data.basket WHERE id_ticket = :ticket AND id_user = :user");
    qw.bindValue(":user",user->id);
    qw.bindValue(":ticket",ticket_id);
    qw.exec();

    if(qw.lastError().type() == QSqlError::NoError)
    {
        basketList();
    }
    else
    {
        QMessageBox::warning(this,"Ошибка",qw.lastError().text());
    }
}

void MainWindow::deleteTicket()//удаление билете
{
    QPushButton * cbox = qobject_cast<QPushButton *>(sender());
    int id_ticket = cbox->property("id_ticket").toInt();
    deleteFromBasket(id_ticket);
}

void MainWindow::movieInfo()//функция для обновление информации о фильме
{
    QPushButton * cbox = qobject_cast<QPushButton *>(sender());
    int id = cbox->property("id").toInt();
    QSqlQuery query(*db);
    query.prepare("SELECT * FROM data.session WHERE session_id = :1");
    query.bindValue(":1",id);
    ui->textEdit_reviews->clear();
    ui->textEdit_acteurs->clear();

    query.exec();
    query.first();
    if(query.lastError().type() != QSqlError::NoError)                                  //проверка на выполнение запрос
    {
        QMessageBox::warning(this,"Ошибка",query.lastError().text());
    }
    else
    {
        QSqlQuery qw(*db);
        qw.prepare("SELECT * FROM data.movie WHERE movie_id = :id");
        qw.bindValue(":id",query.value(2));
        qw.exec();
        qw.next();

        int movie = query.value(2).toInt();

        ui->lineEdit_name->setText(qw.value(1).toString());
        ui->lineEdit_duration->setText(qw.value(4).toString());
        ui->lineEdit_ageLimit->setText(qw.value(3).toString());
        ui->textEdit_acteurs->append(qw.value(5).toString());
        if(qw.value(6).toInt() != 0)
        {
            ui->lineEdit_rating->setText(qw.value(6).toString());
        }
        else
        {
            ui->lineEdit_rating->setText("Пока нет оценок");
        }

        int genre = qw.value(2).toInt();
        qw.prepare("SELECT * FROM data.genre WHERE genre_id = :id");
        qw.bindValue(":id",genre);
        qw.exec();
        qw.next();

        ui->lineEdit_genre->setText(qw.value(1).toString());

        qw.prepare("SELECT * FROM data.reviews WHERE movie_id = :id");
        qw.bindValue(":id",movie);
        qw.exec();

        while (qw.next())
        {
            int estimation = qw.value(3).toInt();
            QString desc = qw.value(4).toString();
            QString date = qw.value(5).toString();

            QSqlQuery qw1(*db);
            qw1.prepare("SELECT login FROM data.viewer WHERE id = :user");
            qw1.bindValue(":user",qw.value(2).toInt());
            qw1.exec();
            qw1.next();

            QString name = qw1.value(0).toString();

            QString review = "Пользователь "+name+"("+date+"). "+ desc +".Оценка: "+QString::number(estimation)+".";
            ui->textEdit_reviews->append(review);
        }

        loadPlaces(id);// показ свободных мест


    }
    ui->frame_movieInfo->show();
}

void MainWindow::loadPlaces(int session_id)//функция для загрузки мест в зале
{
    int startX = 60;//начальная позиция по X
    int startY = 60;//начальная позиция по Y
    int width  = 40;//ширина и высота мест

    QVector<QVector<QPushButton*>> buttons(10);//двумерный вектор для хранения данных о местах


    for (int i = 0 ;i<10;i++)
    {
        buttons[i].resize(7);
        for (int j= 0;j<7;j++)
        {

            QPushButton * pb = new QPushButton(ui->frame);//создаем кнопку места
            //придаем ему нужные характеристики
            pb->setGeometry(startX+i*width,startY+j*width,width,width);
            pb->setText(QString::number(i+1));
            pb->setProperty("row",j+1);
            pb->setProperty("place",i+1);
            pb->setProperty("session_id",session_id);
            connect(pb,SIGNAL(clicked()),this,SLOT(choicePlace()));//соединяем сигнал со слотом обработки
            buttons[i][j] = pb;
        }
    }

    QSqlQuery qw(*db);
    qw.prepare("SELECT * FROM data.tickets WHERE session_id = :id");
    qw.bindValue(":id",session_id);
    qw.exec();
    while(qw.next())
    {
        auto btn = buttons[qw.value(4).toInt()-1][qw.value(3).toInt()-1];
        if(qw.value(1).toInt() == user->id)//если место уже куплено пользователем
        {
            btn->setStyleSheet("background-color:rgb(0,170,0);color:rgb(0,0,0);");
            btn->setEnabled(false);
        }
        else if(qw.value(1).toInt() != NULL)//если место занято другим пользователем
        {
            btn->setStyleSheet("background-color:rgb(255,0,0);color:rgb(0,0,0);");
            btn->setEnabled(false);
        }

        QSqlQuery qw1(*db);
        qw1.prepare("SELECT id_user FROM data.basket WHERE id_ticket = :id");
        qw1.bindValue(":id",qw.value(0).toInt());
        qw1.exec();

        if(qw1.lastError().type() == QSqlError::NoError)
        {
            if(qw1.size()>0)
            {
                qw1.next();
                if(user->id == qw1.value(0).toInt())//если место находится в корзине у пользователя
                {
                    btn->setStyleSheet("background-color:rgb(181,181,181);color:rgb(0,0,0);");
                    btn->setEnabled(false);
                }
            }

        }
        else
        {
            QMessageBox::warning(this,"Ошибка",qw1.lastError().text());
        }

    }
}

void MainWindow::choicePlace()//функция выбора места
{
    QPushButton * cbox = qobject_cast<QPushButton *>(sender());
    int row = cbox->property("row").toInt();
    int place = cbox->property("place").toInt();
    int session_id = cbox->property("session_id").toInt();
    ui->pushButton_addToBasket->setProperty("session_id",session_id);
    ui->spinBox_numberRow->setValue(row);
    ui->spinBox_numberPlace->setValue(place);
}

void MainWindow::on_pushButton_addToBasket_clicked()//обработка добавления билета в корзину
{
    int row = ui->spinBox_numberRow->value();
    int place = ui->spinBox_numberPlace->value();
    int session_id = ui->pushButton_addToBasket->property("session_id").toInt();
    if(row == 0 && place == 0 )
    {
        QMessageBox::warning(this,"Ошибка","Выберите место");
    }
    else
    {
        QSqlQuery qw(*db);
        qw.prepare("SELECT ticket_id FROM data.tickets WHERE session_id = :session_id AND row_number = :row AND place_number = :place");
        qw.bindValue(":session_id",session_id);
        qw.bindValue(":row",row);
        qw.bindValue(":place",place);
        qw.exec();
        if(qw.lastError().type() == QSqlError::NoError)
        {
            qw.next();

            int id_ticket = qw.value(0).toInt();
            qw.prepare("INSERT INTO data.basket (id_ticket,id_user) VALUES (:1,:2)");

            qw.bindValue(":1",id_ticket);
            qw.bindValue(":2",user->id);
            qw.exec();

            if(qw.lastError().type() == QSqlError::NoError)
            {
                ui->frame_movieInfo->hide();
                loadPlaces(session_id);
                ui->frame_movieInfo->show();
                QMessageBox::information(this,"Билет","Добавлено в корзину");
                ui->spinBox_numberRow->setValue(0);
                ui->spinBox_numberPlace->setValue(0);
            }
            else
            {
                QMessageBox::warning(this,"Ошибка",qw.lastError().text());
            }
        }
        else
        {
            QMessageBox::warning(this,"Ошибка",qw.lastError().text());
        }

    }
}

void MainWindow::on_pushButton_closeMovieInfo_clicked()//обработка закрытия окна информации о сеансе
{
    //Очистка всех полей
    ui->frame_movieInfo->hide();
    ui->frame_movieInfo->hide();
    ui->lineEdit_name->clear();
    ui->lineEdit_genre->clear();
    ui->lineEdit_ageLimit->clear();
    ui->lineEdit_duration->clear();
    ui->textEdit_acteurs->clear();
    ui->spinBox_numberRow->setValue(0);
    ui->spinBox_numberPlace->setValue(0);
}



///Часть админа
///
///
void MainWindow::on_pushButton_ActionWithMovie_clicked()//обработка нажатия кнопки добавления фильма
{
    ActionWithMovie * dialog = new ActionWithMovie(db,this);//создание окна
    dialog->setModal(true);
    dialog->show();//показ окна
}

void MainWindow::on_pushButton_ActionWithGenre_clicked()//обработка нажатия кнопки добавления жанра
{
    ActionWithGenre * dialog = new ActionWithGenre(db,this);//создание окна
    dialog->setModal(true);
    dialog->show();//показ окна
}

void MainWindow::on_pushButton_ActionWithSession_clicked()//обработка нажатия кнопки добавления сеанса
{
    ActionWithSession * dialog = new ActionWithSession(db,this);//создание окна
    dialog->setModal(true);
    dialog->show();//показ окна
}

void MainWindow::on_lineEdit_login_textChanged()//обработка изменений в поле ввода
{
    ui->pushButton_enter->setEnabled(true);
}

void MainWindow::on_lineEdit_password_textChanged()//обработка изменений в поле ввода
{
    ui->pushButton_enter->setEnabled(true);
}


void MainWindow::on_radioButton_user_clicked()//обработка включения режима пользователя
{
    ui->pushButton_viewReg->show();
}

void MainWindow::on_radioButton_admin_clicked()//обработка включения режима пользователя
{
    ui->pushButton_viewReg->hide();
}
