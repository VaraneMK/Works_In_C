#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : //конструктор
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    client = new user();
    connectToBD();//подключение к БД

    ui->radioButton_user->click();//делаем кнопку Пользователя активной

    ui->frame_reg->hide();//прячем окно регистрации
    ui->frame->hide();
    ui->tabWidget->setTabEnabled(1,false);//блокируем рабочие окна
    ui->tabWidget->setTabEnabled(2,false);//блокируем рабочие окна
    ui->tabWidget->setTabEnabled(3,false);//блокируем рабочие окна
    ui->tabWidget->setTabEnabled(4,false);//блокируем рабочие окна
    ui->tabWidget->setTabEnabled(5,false);//блокируем рабочие окна

    ui->lineEdit_password->setEchoMode(QLineEdit::PasswordEchoOnEdit);//скрываем вводимый пароль точками
    ui->lineEdit_regPassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);

    QSqlQuery qw(*db);
    qw.prepare("SELECT name_genre FROM data.genre");
    qw.exec();

    if(qw.lastError().type() != QSqlError::NoError)
    {
        QMessageBox::warning(this,"Ошибка",qw.lastError().text());
    }
    else
    {
        while (qw.next())
        {
            ui->comboBox_genre->addItem(qw.value(0).toString());
        }
    }


}


MainWindow::~MainWindow() //деструктор
{
    delete db;
    delete ui;

}

void MainWindow::connectToBD()//соединение с базой данных
{
    db = new QSqlDatabase(QSqlDatabase::addDatabase("QPSQL"));

    QString dbName ("music_player");
    QString host ("127.0.0.1");
    QString usr ("postgres");
    QString pwd ("1234");

    db->setDatabaseName(dbName);//устанавливаем имя БД
    db->setHostName(host);//устанавливаем адрес хоста
    db->setUserName(usr);//устанавливаем имя хоста
    db->setPassword(pwd);//устанавливаем пароль от БД
    db->setPort(5432);//устанавливаем порт

    db->open();
}

void MainWindow::on_pushButton_toReg_clicked()// когда нажимаем "зарегестрироваться"
{
    if(ui->radioButton_user->isChecked() || ui->radioButton_admin->isChecked())//если нажато "Пользователь" или "Администратор"
    {
        //Прячем ненужные поля
        ui->lineEdit_regNameGroup->hide();
        ui->lineEdit_participants->hide();
        ui->comboBox_genre->hide();

    }
    else if(ui->radioButton_performer->isChecked())// если выбрали "Исполнитель"
    {
        //Показываем нужные поля
        ui->lineEdit_regNameGroup->show();
        ui->lineEdit_participants->show();
        ui->comboBox_genre->show();
    }
    cleanLineEdit();//очищаем поля
    ui->frame_reg->show();//показываем окно
}

void MainWindow::cleanLineEdit()//очистка от прежних значений
{
    ui->lineEdit_regLogin->clear();
    ui->lineEdit_regPassword->clear();
    ui->lineEdit_regNameGroup->clear();
    ui->lineEdit_participants->clear();
    ui->comboBox_genre->setCurrentIndex(0);
}

void MainWindow::on_pushButton_reg_clicked()//нажали "Зарегистрироваться"
{

    //Считываем вводимые значения без учета пробелов
    auto login = ui->lineEdit_regLogin->text().trimmed();
    auto password = ui->lineEdit_regPassword->text().trimmed();
    auto nameGroup = ui->lineEdit_regNameGroup->text().trimmed();
    auto genre = ui->comboBox_genre->currentText().trimmed();
    auto participants = ui->lineEdit_participants->text().trimmed();

    bool status = true;//для проверки на корректность введенных данных



    ///Проверка на корректность через регулярные выражения
    if(login.length()<4)
    {
        QMessageBox::warning(this,"Ошибка","Логин должен содержать 4 и более символов");//вывод ошибки
        status = false;
    }
    else if(!login.contains(*validation::loginRegex))
    {
        QMessageBox::warning(this,"Ошибка","Логин может содержать только латинские буквы и цифры");//вывод ошибки
        status = false;
    }
    else if (password.length()<6 && password.length()>15)
    {
        QMessageBox::warning(this,"Ошибка","Пароль должен содержать от 6 до 15");//вывод ошибки
        status = false;
    }
    else if (!password.contains(*validation::passwordRegex))
    {
        QMessageBox::warning(this,"Ошибка","Пароль должен содержать cтрочные и прописные латинские буквы, цифры");//вывод ошибки
        status = false;
    }

    if(ui->radioButton_performer->isChecked())//если выбран режим Исполнителя
    {
        if(ui->lineEdit_regNameGroup->text().trimmed() ==nullptr)
        {
            QMessageBox::warning(this,"Ошибка","Введите название группы");//вывод ошибки
            status = false;
        }
        else if (ui->comboBox_genre->currentIndex() == 0)
        {
            QMessageBox::warning(this,"Ошибка","Выберите жанр");//вывод ошибки
            status = false;
        }
        if(ui->lineEdit_participants->text().trimmed()!=nullptr)
        {
            if (!participants.contains(*validation::participantsRegex))
            {
                QMessageBox::warning(this,"Ошибка","Участники должны вводиться через запятую");
                status = false;
            }
        }
    }

    if(status)//если все проверки пройдены
    {
        if(ui->radioButton_user->isChecked() || ui->radioButton_admin->isChecked())//если выбран пользователь или админ
        {
            registerUser(login,password);//вызов функции регистрации

        }
        else if(ui->radioButton_performer->isChecked())//если выбран Исполнитель
        {
            registerUser(login,password,nameGroup,genre,participants);//вызов функции регистрации
        }

    }
}

bool MainWindow::checkForLogin(QString login, QString password)//функция для проверки данных авторизации
{
    bool status = false;//для проверок
    QSqlQuery query(*db);//экземпляр класса запроса
    if(ui->radioButton_user->isChecked())
    {
        query.prepare(QString("SELECT * from data.user"));//подгрузка данных из таблицы "Пользователь"
    }
    else if(ui->radioButton_admin->isChecked())
    {
        query.prepare(QString("SELECT * from data.admin"));//подгрузка данных из таблицы "Администратор"
    }
    else if (ui->radioButton_performer->isChecked())
    {
        query.prepare(QString("SELECT * from data.performer"));//подгрузка данных из таблицы "Исполнитель"
    }

    query.exec();//проверяет соответствие в строке

    if(query.lastError().type() != QSqlError::NoError)//если возникла ошибка запроса
    {
        QMessageBox::warning(this,"Ошибка",query.lastError().text());
    }
    else
    {
        while(query.next())//вызываем каждый следующий полученный объект
        {
            auto idFromDB = query.value(0).toInt();//считываем ID
            auto loginFromDB = query.value(1).toString().trimmed();//считываем Login
            auto passwordFromDB = query.value(2).toString().trimmed();//считываем Password

            if (loginFromDB == login && passwordFromDB == password)//если нашлось совпадение
            {
                //Запись данных пользователя в экземпляр класса Client
                client->id = idFromDB;
                client->login = loginFromDB;
                client->password = passwordFromDB;

                status = true;
                break;//выход из цикла
            }
        }
    }
    return status;//возвращаем результат
}

void MainWindow::on_pushButton_enter_clicked()//обработка нажатия на кнопку входа
{
    auto login = ui->lineEdit_login->text().trimmed();
    auto password = ui->lineEdit_password->text().trimmed();
    if(db->open())//если БД открыта
    {
        if ((ui->lineEdit_login->text()!=nullptr) && (ui->lineEdit_password->text()!=nullptr))
        {
            if(checkForLogin(login,password))//если все данные прошли проверку
            {
                QMessageBox::information(this,"Вход","Вход прошел успешно");
                if(ui->radioButton_user->isChecked())
                {
                    //Разблокируем рабочие окна
                    ui->tabWidget->setTabEnabled(1,true);
                    ui->tabWidget->setTabEnabled(2,true);
                    ui->tabWidget->setTabEnabled(3,true);
                    ui->tabWidget->setTabEnabled(4,false);//блокируем рабочие окна
                    ui->tabWidget->setTabEnabled(5,false);//блокируем рабочие окна
                    ui->tabWidget->setCurrentIndex(1);//переходим на нужное окно
                    ui->tableWidget_TracksFromPlaylist->setRowCount(0);
                }
                else if(ui->radioButton_admin->isChecked())
                {
                    ui->tabWidget->setTabEnabled(1,false);//блокируем рабочие окна
                    ui->tabWidget->setTabEnabled(2,false);//блокируем рабочие окна
                    ui->tabWidget->setTabEnabled(3,false);//блокируем рабочие окна
                    ui->tabWidget->setTabEnabled(4,false);//блокируем рабочие окна
                    ui->tabWidget->setTabEnabled(5,true);//блокируем рабочие окна
                    ui->tabWidget->setCurrentIndex(5);//переходим на нужное окно
                    ui->tableWidget_check->setRowCount(0);
                    updateCheckingAlbums();

                }
                else if(ui->radioButton_performer->isChecked())
                {
                    ui->tabWidget->setTabEnabled(1,false);//блокируем рабочие окна
                    ui->tabWidget->setTabEnabled(2,false);//блокируем рабочие окна
                    ui->tabWidget->setTabEnabled(3,false);//блокируем рабочие окна
                    ui->tabWidget->setTabEnabled(4,true);//блокируем рабочие окна
                    ui->tabWidget->setTabEnabled(5,false);//блокируем рабочие окна
                    ui->tableWidget->setRowCount(2);
                    ui->tabWidget->setCurrentIndex(4);//переходим на нужное окно
                    ui->tableWidget->setRowCount(2);
                    ui->tableWidget_album->setRowCount(0);
                    updateGenres();
                    updateAlbums();

                }
                ui->pushButton_enter->setEnabled(false);
            }
            else
            {
                QMessageBox::warning(this,"Вход","Пользователь с таким логином и паролем не существует");
                ui->tabWidget->setTabEnabled(1,false);//блокируем рабочие окна
                ui->tabWidget->setTabEnabled(2,false);//блокируем рабочие окна
                ui->tabWidget->setTabEnabled(3,false);//блокируем рабочие окна
                ui->tabWidget->setTabEnabled(4,false);//блокируем рабочие окна
                ui->tabWidget->setTabEnabled(5,false);//блокируем рабочие окна
            }
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Введите логин и пароль");
        }
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","База данных не подключена");
    }

}

bool MainWindow::checkLoginForRegister(QString login)//функция для проверки данных введенных для регистрации
{
    QSqlQuery query(*db);

    bool status = false;//для проверки наличия пользователя

    if(ui->radioButton_user->isChecked())
    {
        query.prepare(QString("SELECT * from data.user"));//запрос для получения данных из таблицы user
    }
    else if(ui->radioButton_admin->isChecked())
    {
        query.prepare(QString("SELECT * from data.admin"));//запрос для получения данных из таблицы admin
    }
    else if (ui->radioButton_performer->isChecked())
    {
        query.prepare(QString("SELECT * from data.performer"));//запрос для получения данных из таблицы permorfer
    }

    query.exec();//вызов запроса

    if(query.lastError().type() == QSqlError::NoError)//если без ошибок
    {
        while(query.next())
        {
            auto loginFromDB = query.value(1).toString().trimmed();
            if (loginFromDB == login)//если уже есть такой логин
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

void MainWindow::registerUser(QString login, QString password, QString nameGroup, QString genre, QString participans)//функция для регистрации пользователя
{
    if(db->open())
    {
        if(!checkLoginForRegister(login))//если прошло проверку
        {
            QSqlQuery query(*db);
            if(ui->radioButton_user->isChecked())
            {
                query.prepare("INSERT INTO data.user (login_user,password_user,number_tracks) VALUES (:1,:2,:3)");//запрос для записи данных в таблицу user
                //Подставляем значения в запрос
                query.bindValue(":1",login);
                query.bindValue(":2",password);
                query.bindValue(":3",0);
            }
            else if(ui->radioButton_admin->isChecked())
            {
                query.prepare("INSERT INTO data.admin (login,password) VALUES (:1,:2)");//запрос для записи данных в таблицу admin
                //Подставляем значения в запрос
                query.bindValue(":1",login);
                query.bindValue(":2",password);
            }
            else if (ui->radioButton_performer->isChecked())
            {
                query.prepare("SELECT id_genre FROM data.genre WHERE name_genre = :name");
                //Подставляем значения в запрос
                query.bindValue(":name",genre);
                query.exec();
                query.first();
                int id_genre = query.value(0).toInt();

                query.prepare("INSERT INTO data.performer (login_performer,password_performer,name_performer,id_genre,participants) VALUES (:1,:2,:3,:4,:5)");
                //Подставляем значения в запрос
                query.bindValue(":1",login);
                query.bindValue(":2",password);
                query.bindValue(":3",nameGroup);
                query.bindValue(":4",id_genre);
                query.bindValue(":5",participans);
            }

            query.exec();
            if(query.lastError().type() == QSqlError::NoError)//проверка на выполнение запроса
            {
                QMessageBox::information(this,"Регистрация","Регистрация прошла успешно.");
                ui->frame_reg->hide();
            }
            else
            {
                QMessageBox::warning(this,"Ошибка","Запрос не выполнен");
            }
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Пользователь с таким логином уже существует");
        }

    }
    else
    {
        QMessageBox::warning(this,"Ошибка","База данных не открыта");
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)//Обработка переключений рабочих окон
{
    updateInfo(index);
}

void MainWindow::updateInfo(int index)//функция для обновления данных в окнах
{
    switch (index)
    {
    case 1:
        topMusic();
        break;
    case 2:
        myMusic();
        break;
    case 3:
        myPlaylist();
        ui->label_playlistInfo->setText("Плейлист");
        ui->tableWidget_TracksFromPlaylist->setRowCount(0);
        break;
    case 4:
        ui->spinBox_count->setValue(2);
        ui->tableWidget->setRowCount(2);
        for (int j=0;j<2;j++)
        {
            for (int i=0;i<2;i++)
            {
                if(ui->tableWidget->item(j,i) == nullptr)
                {
                    QTableWidgetItem *ti;
                    ti = new QTableWidgetItem;
                    ui->tableWidget->setItem(j,i,ti);
                }
            }
        }
        for (int i =0;i<ui->spinBox_count->value();i++)
        {
            ui->tableWidget->item(i,0)->setText("");
            ui->tableWidget->item(i,1)->setText("");
        }
        break;
    }

}

void MainWindow::topMusic()//функция для вывода самой популярной музыки
{
    QSqlQuery query(*db);

    query.prepare("SELECT * FROM data.track ORDER BY number_plays DESC");//запрос для получения данных из таблицы track с сортировкой по количеству добавлений
    int currentRow = 0;//указывает текущую  строчку
    query.exec();
    ui->tableWidget_top->setRowCount(query.size());//создаем в таблице нужное количество строк
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
                if(ui->tableWidget_top->item(currentRow,i) == nullptr)
                {
                    QTableWidgetItem *ti;
                    ti = new QTableWidgetItem;
                    ti->setFlags(ti->flags() & 0x3d);//устанавливаем флаг только для чтения
                    ui->tableWidget_top->setItem(currentRow,i,ti);
                }
            }

            ///Получаем и вписываем значения из таблиц
            ui->tableWidget_top->item(currentRow,0)->setText(query.value(1).toString());
            ui->tableWidget_top->item(currentRow,3)->setText(query.value(4).toString());

            QSqlQuery qw(*db);
            qw.prepare("SELECT * FROM data.performer WHERE id_performer = :id");
            qw.bindValue(":id",query.value(2));
            qw.exec();
            qw.next();
            ui->tableWidget_top->item(currentRow,1)->setText(qw.value(3).toString());

            qw.prepare("SELECT * FROM data.album WHERE id_album = :id");
            qw.bindValue(":id",query.value(3));
            qw.exec();
            qw.next();
            ui->tableWidget_top->item(currentRow,2)->setText(qw.value(5).toString());

            qw.prepare("SELECT * FROM data.genre WHERE id_genre = :id");
            qw.bindValue(":id",query.value(6));
            qw.exec();
            qw.next();
            ui->tableWidget_top->item(currentRow,4)->setText(qw.value(1).toString());


            qw.prepare("SELECT * FROM data.added_tracks WHERE id_user = :id_user AND id_track = :id_track");
            qw.bindValue(":id_user",client->id);
            qw.bindValue(":id_track",query.value(0).toInt());

            qw.exec();

            QPushButton * pb = new QPushButton;//создаем экземпляр кнопки для добавления в таблицу
            if(qw.size())//если уже добавлено
            {
                pb->setText("Добавлено");
                pb->setEnabled(false);
            }
            else
            {
                pb->setText("Добавить");
                pb->setProperty("id",query.value(0));//устанавливаем id трека как характеристику кнопки
                connect(pb, SIGNAL(clicked()), this, SLOT(addTrack()));//соединяем сигнал со слотом
            }
            ui->tableWidget_top->setCellWidget(currentRow, 5, pb);
            currentRow++;
        }
    }
}

void MainWindow::addTrack()//обработка добавления трека
{
    QPushButton * cbox = qobject_cast<QPushButton *>(sender());//считываем кнопку,которая вызвала функцию
    cbox->setText("Добавлено");
    cbox->setEnabled(false);
    int id = cbox->property("id").toInt();//считываем id трека

    QSqlQuery query(*db);
    query.prepare("INSERT INTO data.added_tracks (id_track,id_user) VALUES (:1,:2);");
    query.bindValue(":1",id);
    query.bindValue(":2",client->id);

    query.exec();
    if(query.lastError().type() != QSqlError::NoError)//проверка на выполнение запрос
    {
        QMessageBox::warning(this,"Ошибка",query.lastError().text());
    }
    else
    {
        updateTrackPopularity(id);
    }
}

void MainWindow::on_pushButton_search_clicked()//обработка нажатия на кнопку поиска
{
    if(ui->lineEdit_search->text()!=nullptr)
    {
        searchTrack(ui->lineEdit_search->text().trimmed());//Вызов функции поиска
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Введите название трека или исполнителя");
    }
}

void MainWindow::searchTrack(QString name)
{
    QSqlQuery query(*db);
    if(name == "*")
    {
        query.prepare("SELECT * FROM data.track ORDER BY number_plays DESC");
    }
    else
    {
        query.prepare("SELECT * FROM data.track WHERE id_performer IN(SELECT id_performer FROM data.performer WHERE name_performer ILIKE :name) OR name_track ILIKE :name ORDER BY number_plays DESC");
        query.bindValue(":name",name);
    }
    int currentRow = 0;
    query.exec();
    ui->tableWidget_results->setRowCount(query.size());

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
                if(ui->tableWidget_results->item(currentRow,i) == nullptr)
                {
                    QTableWidgetItem *ti;
                    ti = new QTableWidgetItem;
                    ti->setFlags(ti->flags() & 0x3d);
                    ui->tableWidget_results->setItem(currentRow,i,ti);
                }
            }
            ui->tableWidget_results->item(currentRow,0)->setText(query.value(1).toString());
            ui->tableWidget_results->item(currentRow,3)->setText(query.value(4).toString());

            QSqlQuery qw(*db);
            qw.prepare("SELECT * FROM data.performer WHERE id_performer = :id");
            qw.bindValue(":id",query.value(2));
            qw.exec();
            qw.next();
            ui->tableWidget_results->item(currentRow,1)->setText(qw.value(3).toString());

            qw.prepare("SELECT * FROM data.album WHERE id_album = :id");
            qw.bindValue(":id",query.value(3));
            qw.exec();
            qw.next();
            ui->tableWidget_results->item(currentRow,2)->setText(qw.value(5).toString());

            qw.prepare("SELECT * FROM data.genre WHERE id_genre = :id");
            qw.bindValue(":id",query.value(6));
            qw.exec();
            qw.next();
            ui->tableWidget_results->item(currentRow,4)->setText(qw.value(1).toString());

            qw.prepare("SELECT * FROM data.added_tracks WHERE id_user = :id_user AND id_track = :id_track");
            qw.bindValue(":id_user",client->id);
            qw.bindValue(":id_track",query.value(0).toInt());

            qw.exec();

            QPushButton * pb = new QPushButton;

            if(qw.size())
            {
                pb->setText("Добавлено");
                pb->setEnabled(false);
            }
            else
            {
                pb->setText("Добавить");
                pb->setProperty("id",query.value(0));
                connect(pb, SIGNAL(clicked()), this, SLOT(addTrack()));
            }
            ui->tableWidget_results->setCellWidget(currentRow, 5, pb);
            currentRow++;
        }
    }
}

void MainWindow::myMusic()//функция вывода музыки пользователя
{
    QSqlQuery query(*db);

    query.prepare("SELECT * FROM data.track WHERE id_track IN(SELECT id_track FROM data.added_tracks WHERE id_user = :id) ORDER BY number_plays DESC");//запрос для поиска треков добавленных пользователем
    int currentRow = 0;
    query.bindValue(":id",client->id);
    query.exec();
    ui->tableWidget_myMusic->setRowCount(query.size());
    if(query.lastError().type() != QSqlError::NoError)
    {
        QMessageBox::warning(this,"Ошибка",query.lastError().text());
    }
    else
    {
        while (query.next())
        {
            for (int i=0;i<7;i++)
            {
                if(ui->tableWidget_myMusic->item(currentRow,i) == nullptr)
                {
                    QTableWidgetItem *ti;
                    ti = new QTableWidgetItem;
                    ti->setFlags(ti->flags() & 0x3d);
                    ui->tableWidget_myMusic->setItem(currentRow,i,ti);
                }
            }
            ui->tableWidget_myMusic->item(currentRow,0)->setText(query.value(1).toString());
            ui->tableWidget_myMusic->item(currentRow,3)->setText(query.value(4).toString());

            QSqlQuery qw(*db);
            qw.prepare("SELECT * FROM data.performer WHERE id_performer = :id");
            qw.bindValue(":id",query.value(2));
            qw.exec();
            qw.next();
            ui->tableWidget_myMusic->item(currentRow,1)->setText(qw.value(3).toString());

            qw.prepare("SELECT * FROM data.album WHERE id_album = :id");
            qw.bindValue(":id",query.value(3));
            qw.exec();
            qw.next();
            ui->tableWidget_myMusic->item(currentRow,2)->setText(qw.value(5).toString());

            qw.prepare("SELECT * FROM data.genre WHERE id_genre = :id");
            qw.bindValue(":id",query.value(6));
            qw.exec();
            qw.next();
            ui->tableWidget_myMusic->item(currentRow,4)->setText(qw.value(1).toString());

            QComboBox *cb = new QComboBox;//ComboBox для вывода всех плейлистов
            cb->addItem("Добавить в плейлиcт");

            qw.prepare("SELECT * FROM data.added_playlists WHERE id_user = :id");//запрос для поиска плейлистов пользователя
            qw.bindValue(":id",client->id);
            qw.exec();


            QSqlQuery qwTrack(*db);
            int count = qw.size();

            QVariant v(0);

            for (int i =0 ; i<count ; i++)//выводим все плейлисты
            {
                qw.next();
                cb->addItem(qw.value(1).toString());
                cb->setProperty("id_track",query.value(0).toInt());

                QModelIndex index = cb->model()->index(i+1,0);
                qwTrack.prepare("SELECT * FROM data.added_tracks_playlist WHERE id_track = :id_track AND id_playlist = :id_pl");
                qwTrack.bindValue(":id_track",query.value(0));
                qwTrack.bindValue(":id_pl",qw.value(0));
                qwTrack.exec();
                if (qwTrack.size()>0) cb->model()->setData(index,v,Qt::UserRole-1);
            }
            connect (cb,SIGNAL(currentIndexChanged(int)),this,SLOT(addPlaylists(int)));//соединяем сигнал со слотом
            ui->tableWidget_myMusic->setCellWidget(currentRow, 5, cb);

            QPushButton * pb = new QPushButton;
            pb->setText("Удалить");
            pb->setProperty("id_track",query.value(0).toInt());
            connect(pb, SIGNAL(clicked()), this, SLOT(deleteTrack()));

            ui->tableWidget_myMusic->setCellWidget(currentRow, 6, pb);
            currentRow++;
        }
    }
}

void MainWindow::deleteTrack()//обработка удаления трека
{
    QPushButton * cbox = qobject_cast<QPushButton *>(sender());
    int id_track = cbox->property("id_track").toInt();
    int id_user = client->id;
    QSqlQuery qw(*db);
    qw.prepare("DELETE FROM data.added_tracks WHERE id_track = :1 AND id_user = :2");//Запрос для удаления данных из таблицы
    qw.bindValue(":1",id_track);
    qw.bindValue(":2",id_user);
    qw.exec();
    if(qw.lastError().type() == QSqlError::NoError)
    {
        myMusic();
        updateTrackPopularity(id_track);
    }


}

void MainWindow::addPlaylists(int index)//обработка добавления треков в плейлист
{
    if(index != 0)
    {
        QComboBox * cbox = qobject_cast<QComboBox *>(sender());
        QString namePlaylist =cbox->itemText(index);
        QSqlQuery qw(*db);
        qw.prepare("SELECT id_playlist,number_tracks FROM data.added_playlists WHERE name_playlist = :name AND id_user = :id");

        qw.bindValue(":name",namePlaylist);
        qw.bindValue(":id",client->id);

        qw.exec();
        qw.next();

        int id_playlist = qw.value(0).toInt();
        int id_track = cbox->property("id_track").toInt();

        qw.prepare("INSERT INTO data.added_tracks_playlist (id_track,id_playlist) VALUES (:1,:2)");
        qw.bindValue(":1",id_track);
        qw.bindValue(":2",id_playlist);


        qw.exec();
        if(qw.lastError().type() == QSqlError::NoError)
        {
            QVariant v(0);
            QModelIndex modelIndex = cbox->model()->index(index,0);
            cbox->model()->setData(modelIndex,v,Qt::UserRole-1);
            cbox->setCurrentIndex(0);

            updateCountMinutes(id_playlist);
            updateCountAddedTracks(id_playlist);
        }
        else
        {
            QMessageBox::warning(this,"",qw.lastError().text());
        }
    }
}

void MainWindow::updateCountAddedTracks(int id_playlist)//функция обновления количества добавлений трека
{
    QSqlQuery qw(*db);
    qw.prepare("SELECT * FROM data.added_tracks_playlist WHERE id_playlist = :playlist");
    qw.bindValue(":playlist",id_playlist);
    qw.exec();
    int count = qw.size();

    qw.prepare("UPDATE data.added_playlists SET number_tracks = :new WHERE id_playlist = :id");//запрос обновления данных
    qw.bindValue(":new",count);
    qw.bindValue(":id",id_playlist);
    qw.exec();
}
void MainWindow::updateCountMinutes(int id_playlist)//функция обновления количества минут в плейлисте
{
    QSqlQuery qw(*db);
    int duration = 0;
    qw.prepare("SELECT duration FROM data.track WHERE id_track IN(SELECT id_track FROM data.added_tracks_playlist WHERE id_playlist = :playlist)");
    qw.bindValue(":playlist",id_playlist);
    qw.exec();

    while(qw.next())
    {
        duration += qw.value(0).toInt();
    }

    qw.prepare("UPDATE data.added_playlists SET number_minutes = :new WHERE id_playlist = :id");
    qw.bindValue(":new",duration);
    qw.bindValue(":id",id_playlist);
    qw.exec();
}

void MainWindow::on_pushButton_back_clicked()//обработка закрытия окна регистрации
{
    ui->frame_reg->hide();
}


void MainWindow::myPlaylist()//функция вывода плейлистов пользователя
{
    QSqlQuery query(*db);
    int currentRow = 0;

    query.prepare("SELECT * FROM data.added_playlists WHERE id_user = :id ORDER BY number_minutes DESC");
    query.bindValue(":id",client->id);
    query.exec();
    ui->tableWidget_playlists->setRowCount(query.size());
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
                if(ui->tableWidget_playlists->item(currentRow,i) == nullptr)
                {
                    QTableWidgetItem *ti;
                    ti = new QTableWidgetItem;
                    ti->setFlags(ti->flags() & 0x3d);
                    ui->tableWidget_playlists->setItem(currentRow,i,ti);
                }
            }
            ui->tableWidget_playlists->item(currentRow,0)->setText(query.value(1).toString());
            ui->tableWidget_playlists->item(currentRow,1)->setText(query.value(4).toString());
            ui->tableWidget_playlists->item(currentRow,2)->setText(query.value(3).toString());

            QPushButton * pb = new QPushButton;

            pb->setText("Открыть");
            pb->setProperty("id_playlist",query.value(0));
            pb->setProperty("name",query.value(1));
            connect(pb, SIGNAL(clicked()), this, SLOT(openPlaylist()));
            ui->tableWidget_playlists->setCellWidget(currentRow, 3, pb);

            QPushButton * pb_delete = new QPushButton;

            pb_delete->setText("Удалить");
            pb_delete->setProperty("id_playlist",query.value(0));
            pb_delete->setProperty("name",query.value(1));
            connect(pb_delete, SIGNAL(clicked()), this, SLOT(deletePlaylist()));
            ui->tableWidget_playlists->setCellWidget(currentRow, 4, pb_delete);

            QPushButton * pb_change = new QPushButton;

            pb_change->setText("Изменить");
            pb_change->setProperty("id_playlist",query.value(0));
            pb_change->setProperty("name",query.value(1));
            connect(pb_change, SIGNAL(clicked()), this, SLOT(changePlaylist()));
            ui->tableWidget_playlists->setCellWidget(currentRow, 5, pb_change);


            currentRow++;
        }
    }
}

void MainWindow::deletePlaylist()
{
    QPushButton * cbox = qobject_cast<QPushButton *>(sender());
    int id_playlist = cbox->property("id_playlist").toInt();

    QSqlQuery query(*db);
    query.prepare("DELETE FROM data.added_tracks_playlist WHERE id_playlist = :1");
    query.bindValue(":1",id_playlist);
    query.exec();

    if(query.lastError().type() == QSqlError::NoError)
    {
        query.prepare("DELETE FROM data.added_playlists WHERE id_playlist = :1");
        query.bindValue(":1",id_playlist);
        query.exec();
        if(query.lastError().type() != QSqlError::NoError)
        {
            QMessageBox::warning(this,"Ошибка",query.lastError().text());
        }

    }
    else
    {
        QMessageBox::warning(this,"Ошибка",query.lastError().text());
    }

    ui->tableWidget_TracksFromPlaylist->setRowCount(0);
    ui->label_playlistInfo->setText("Плейлист");
    myPlaylist();
}

void MainWindow::changePlaylist()
{
    QPushButton * cbox = qobject_cast<QPushButton *>(sender());
    int id_playlist = cbox->property("id_playlist").toInt();
    ui->pushButton_changePlaylist->setProperty("id",id_playlist);
    ui->frame->show();
}

void MainWindow::openPlaylist()//обработка открытия плейлиста
{
    QPushButton * cbox = qobject_cast<QPushButton *>(sender());
    int id_playlist = cbox->property("id_playlist").toInt();
    QString name= cbox->property("name").toString();

    updateTrackList(id_playlist,name);//вызов функции вывода трек-листа

}

void MainWindow::updateTrackList(int id_playlist, QString name)//функция открытия плейлиста
{
    QSqlQuery query(*db);
    query.prepare("SELECT * FROM data.track WHERE id_track IN(SELECT id_track FROM data.added_tracks_playlist WHERE id_playlist = :id) ORDER BY number_plays DESC");
    int currentRow = 0;
    query.bindValue(":id",id_playlist);
    query.exec();
    ui->tableWidget_TracksFromPlaylist->setRowCount(query.size());
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
                if(ui->tableWidget_TracksFromPlaylist->item(currentRow,i) == nullptr)
                {
                    QTableWidgetItem *ti;
                    ti = new QTableWidgetItem;
                    ti->setFlags(ti->flags() & 0x3d);
                    ui->tableWidget_TracksFromPlaylist->setItem(currentRow,i,ti);
                }
            }
            ui->tableWidget_TracksFromPlaylist->item(currentRow,0)->setText(query.value(1).toString());
            ui->tableWidget_TracksFromPlaylist->item(currentRow,3)->setText(query.value(4).toString());

            QSqlQuery qw(*db);
            qw.prepare("SELECT * FROM data.performer WHERE id_performer = :id");
            qw.bindValue(":id",query.value(2));
            qw.exec();
            qw.next();
            ui->tableWidget_TracksFromPlaylist->item(currentRow,1)->setText(qw.value(3).toString());

            qw.prepare("SELECT * FROM data.album WHERE id_album = :id");
            qw.bindValue(":id",query.value(3));
            qw.exec();
            qw.next();
            ui->tableWidget_TracksFromPlaylist->item(currentRow,2)->setText(qw.value(5).toString());

            qw.prepare("SELECT * FROM data.genre WHERE id_genre = :id");
            qw.bindValue(":id",query.value(6));
            qw.exec();
            qw.next();
            ui->tableWidget_TracksFromPlaylist->item(currentRow,4)->setText(qw.value(1).toString());

            QPushButton * pb = new QPushButton;
            pb->setText("Удалить");
            pb->setProperty("id_track",query.value(0).toInt());
            pb->setProperty("id_playlist",id_playlist);
            pb->setProperty("name",name);
            connect(pb, SIGNAL(clicked()), this, SLOT(deleteTrackFromPlaylist()));

            ui->tableWidget_TracksFromPlaylist->setCellWidget(currentRow, 5, pb);
            currentRow++;
        }
        ui->label_playlistInfo->setText("Плейлист: " + name);
    }
}
void MainWindow::deleteTrackFromPlaylist()//обработка удаления трека из плейлиста
{
    QPushButton * cbox = qobject_cast<QPushButton *>(sender());
    int id_track = cbox->property("id_track").toInt();
    int id_playlist = cbox->property("id_playlist").toInt();
    QString name = cbox -> property("name").toString();
    QSqlQuery qw(*db);
    qw.prepare("DELETE FROM data.added_tracks_playlist WHERE id_track = :1 AND id_playlist = :2");
    qw.bindValue(":1",id_track);
    qw.bindValue(":2",id_playlist);
    qw.exec();
    if(qw.lastError().type() == QSqlError::NoError)
    {
        updateCountMinutes(id_playlist);
        updateCountAddedTracks(id_playlist);
        updateTrackList(id_playlist,name);
        myPlaylist();
    }
}

void MainWindow::on_pushButton_createPlaylist_2_clicked()//обработка создания плейлиста
{
    auto name = ui->lineEdit_newPlaylist_2->text().trimmed();

    if (ui->lineEdit_newPlaylist_2->text()!=nullptr)
    {
        QSqlQuery qw(*db);
        qw.prepare("INSERT INTO data.added_playlists (name_playlist,id_user,number_minutes,number_tracks) VALUES (:1,:2,:3,:4)");
        qw.bindValue(":1",name);
        qw.bindValue(":2",client->id);
        qw.bindValue(":3",0);
        qw.bindValue(":4",0);

        qw.exec();

        if(qw.lastError().type() == QSqlError::NoError)
        {
            myPlaylist();
            ui->lineEdit_newPlaylist_2->clear();
        }
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Введите название плейлиста");
    }
}

void MainWindow::on_lineEdit_login_textChanged()//обработка изменение в поле ввода
{
    ui->pushButton_enter->setEnabled(true);//разблокируем кнопку
}

void MainWindow::on_lineEdit_password_textChanged()//обработка изменение в поле ввода
{
    ui->pushButton_enter->setEnabled(true);//разблокируем кнопку
}

void MainWindow::on_pushButton_sendToCheck_clicked()//обработка отправки альбома на проверку
{
    if(ui->lineEdit_addAlbum->text() != nullptr)
    {
        if(ui->comboBox_genres->currentIndex() != 0)
        {
            auto name = ui->lineEdit_addAlbum->text().trimmed();
            auto genre = ui->comboBox_genres->currentText();
            auto date = ui->dateEdit->date().toString("yyyy").toInt();
            auto size = ui->spinBox_count->value();

            bool status = true;
            bool fl;
            for (int i = 0;i<size;i++)
            {
                if(ui->tableWidget->item(i,0)->text() != nullptr)
                {
                    ui->tableWidget->item(i,0)->setBackground(Qt::white);

                }
                else
                {
                    ui->tableWidget->item(i,0)->setBackground(Qt::red);
                    status = false;
                }
            }


            for (int i = 0;i<size;i++)
            {
                if(ui->tableWidget->item(i,1)->text() != nullptr)
                {
                    ui->tableWidget->item(i,1)->text().toInt(&fl);
                    if(!fl)
                    {
                        status = false;
                        ui->tableWidget->item(i,1)->setBackground(Qt::red);
                    }
                    else
                    {
                        ui->tableWidget->item(i,1)->setBackground(Qt::white);
                    }

                }
                else
                {
                    ui->tableWidget->item(i,1)->setBackground(Qt::red);
                    status = false;
                }
            }

            if(status)
            {
                QSqlQuery query(*db);
                query.prepare("SELECT name_album FROM data.album WHERE id_performer = :1 AND name_album = :2");
                query.bindValue(":1",client->id);
                query.bindValue(":2",name);
                query.exec();

                if (query.size() > 0)
                {
                    QMessageBox::warning(this,"Ошибка","У вас уже есть альбом с таким названием");
                }

                else
                {
                    QSqlQuery query(*db);
                    query.prepare("SELECT name_album FROM data.checking_album WHERE id_performer = :1 AND name_album = :2");
                    query.bindValue(":1",client->id);
                    query.bindValue(":2",name);
                    query.exec();

                    if (query.size() > 0)
                    {
                        QMessageBox::warning(this,"Ошибка","Вы уже отправляли на проверку альбом с таким названием");
                    }
                    else
                    {
                        query.prepare("SELECT id_genre FROM data.genre WHERE name_genre = :1");
                        query.bindValue(":1",genre);
                        query.exec();
                        query.next();
                        int id_genre = query.value(0).toInt();

                        ///Добавляем альбом на проверку
                        query.prepare("INSERT INTO data.checking_album (id_performer,id_genre,name_album,year) VALUES (:1,:2,:3,:4)");
                        query.bindValue(":1",client->id);
                        query.bindValue(":2",id_genre);
                        query.bindValue(":3",name);
                        query.bindValue(":4",date);

                        query.exec();

                        if(query.lastError().type() == QSqlError::NoError)
                        {
                            query.prepare("SELECT id_operation FROM data.checking_album ORDER BY id_operation DESC LIMIT 1");
                            query.exec();
                            query.next();
                            int id_album = query.value(0).toInt();
                            if(query.lastError().type() == QSqlError::NoError)
                            {
                                for (int i =0;i<size;i++)
                                {
                                    query.prepare("INSERT INTO data.checking_tracks (id_album,name_track,duration) VALUES (:1,:2,:3)");
                                    query.bindValue(":1",id_album);
                                    query.bindValue(":2",ui->tableWidget->item(i,0)->text());
                                    query.bindValue(":3",ui->tableWidget->item(i,1)->text().toInt());
                                    query.exec();
                                    if(query.lastError().type() != QSqlError::NoError)
                                    {
                                        QMessageBox::warning(this,"Ошибка",query.lastError().text());
                                    }
                                }
                                QMessageBox::information(this,"Отправка","Отправка прошла успешно");
                                ui->lineEdit_addAlbum->clear();
                                ui->spinBox_count->setValue(2);
                                for (int i =0;i<ui->spinBox_count->value();i++)
                                {
                                    ui->tableWidget->item(i,0)->setText("");
                                    ui->tableWidget->item(i,1)->setText("");
                                }
                                ui->dateEdit->setDate(QDate::currentDate());
                                ui->comboBox_genres->setCurrentIndex(0);
                            }

                        }
                        else
                        {
                            QMessageBox::warning(this,"Ошибка",query.lastError().text());
                        }
                    }

                }


            }
            else
            {
                QMessageBox::warning(this,"Ошибка","Введите корректные значения");
            }
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Выберите жанр");
        }
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Введите название альбома");
    }
}

void MainWindow::on_spinBox_count_valueChanged(int arg1)//если изменяется количество песен
{
    ui->tableWidget->setRowCount(arg1);//меняем кол-во строк в таблице
    for (int j=0;j<arg1;j++)
    {
        for (int i=0;i<2;i++)
        {
            if(ui->tableWidget->item(j,i) == nullptr)
            {
                QTableWidgetItem *ti;
                ti = new QTableWidgetItem;
                ui->tableWidget->setItem(j,i,ti);
            }
        }
    }
}

void MainWindow::updateGenres()//функця обновления жанров
{
    QSqlQuery qw(*db);
    qw.prepare("SELECT name_genre FROM data.genre");
    qw.exec();

    if(qw.lastError().type() != QSqlError::NoError)
    {
        QMessageBox::warning(this,"Ошибка",qw.lastError().text());
    }
    else
    {
        while (qw.next())
        {
            ui->comboBox_genres->addItem(qw.value(0).toString());
        }
    }
}


void MainWindow::updateAlbums()//функция обновления списка альбомов
{
    int count = ui->comboBox_albums->count();
    for (int i = count;i>0;i--)
    {
        ui->comboBox_albums->removeItem(i);
    }

    QSqlQuery qw(*db);
    qw.prepare("SELECT name_album FROM data.album WHERE id_performer = :1");
    qw.bindValue(":1",client->id);
    qw.exec();

    if(qw.lastError().type() != QSqlError::NoError)
    {
        QMessageBox::warning(this,"Ошибка",qw.lastError().text());
    }
    else
    {
        while (qw.next())
        {
            ui->comboBox_albums->addItem(qw.value(0).toString());
        }
    }
}

void MainWindow::on_pushButton_clicked()//обработка открытия альбома исполнителя
{
    if(ui->comboBox_albums->currentIndex()!=0)
    {
        auto name = ui->comboBox_albums->currentText();
        int currentRow = 0;//указывает текущую  строчку
        QSqlQuery query(*db);
        query.prepare("SELECT id_album FROM data.album WHERE name_album = :1");
        query.bindValue(":1",name);
        query.exec();
        query.next();

        int id_album = query.value(0).toInt();

        query.prepare("SELECT * FROM data.track WHERE id_album = :1 ORDER BY number_plays DESC");
        query.bindValue(":1",id_album);
        query.exec();
        ui->tableWidget_album->setRowCount(query.size());//создаем в таблице нужное количество строк
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
                    if(ui->tableWidget_album->item(currentRow,i) == nullptr)
                    {
                        QTableWidgetItem *ti;
                        ti = new QTableWidgetItem;
                        ti->setFlags(ti->flags() & 0x3d);//устанавливаем флаг только для чтения
                        ui->tableWidget_album->setItem(currentRow,i,ti);
                    }
                }

                ///Получаем и вписываем значения из таблиц
                ui->tableWidget_album->item(currentRow,0)->setText(query.value(1).toString());
                ui->tableWidget_album->item(currentRow,3)->setText(query.value(4).toString());

                QSqlQuery qw(*db);
                qw.prepare("SELECT * FROM data.performer WHERE id_performer = :id");
                qw.bindValue(":id",query.value(2));
                qw.exec();
                qw.next();
                ui->tableWidget_album->item(currentRow,1)->setText(qw.value(3).toString());

                qw.prepare("SELECT * FROM data.album WHERE id_album = :id");
                qw.bindValue(":id",query.value(3));
                qw.exec();
                qw.next();
                ui->tableWidget_album->item(currentRow,2)->setText(qw.value(5).toString());

                qw.prepare("SELECT * FROM data.genre WHERE id_genre = :id");
                qw.bindValue(":id",query.value(6));
                qw.exec();
                qw.next();
                ui->tableWidget_album->item(currentRow,4)->setText(qw.value(1).toString());
                currentRow++;
            }
        }
    }
    else
    {
        ui->tableWidget_album->setRowCount(0);
        QMessageBox::warning(this,"Ошибка","Выберите альбом");
    }
}

void MainWindow::updateCheckingAlbums()//обновление списка альбомов,отправленных на проверку
{
    int count = ui->comboBox_check->count();
    for (int i = count;i>0;i--)
    {
        ui->comboBox_check->removeItem(i);
    }

    QSqlQuery qw(*db);
    qw.prepare("SELECT name_album FROM data.checking_album");
    qw.exec();

    if(qw.lastError().type() != QSqlError::NoError)
    {
        QMessageBox::warning(this,"Ошибка",qw.lastError().text());
    }
    else
    {
        while (qw.next())
        {
            ui->comboBox_check->addItem(qw.value(0).toString());
        }
    }
}

void MainWindow::on_pushButton_open_clicked()//обработка открытия альбома,отправленного на проверку
{
    if(ui->comboBox_check->currentIndex() != 0)
    {
        auto name = ui->comboBox_check->currentText();
        int currentRow = 0;//указывает текущую  строчку
        QSqlQuery query(*db);
        query.prepare("SELECT * FROM data.checking_album WHERE name_album = :1");
        query.bindValue(":1",name);
        query.exec();
        query.next();

        int id_album = query.value(0).toInt();
        int id_performer = query.value(1).toInt();
        int id_genre = query.value(2).toInt();
        int year = query.value(4).toInt();

        ui->pushButton_agree->setProperty("id_album",id_album);
        ui->pushButton_agree->setProperty("name",name);
        ui->pushButton_agree->setProperty("id_performer",id_performer);
        ui->pushButton_agree->setProperty("id_genre",id_genre);
        ui->pushButton_agree->setProperty("year",year);

        ui->pushButton_reject->setProperty("id_album",id_album);


        query.prepare("SELECT * FROM data.checking_tracks WHERE id_album = :1");
        query.bindValue(":1",id_album);
        query.exec();
        ui->tableWidget_check->setRowCount(query.size());//создаем в таблице нужное количество строк
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
                    if(ui->tableWidget_check->item(currentRow,i) == nullptr)
                    {
                        QTableWidgetItem *ti;
                        ti = new QTableWidgetItem;
                        ti->setFlags(ti->flags() & 0x3d);//устанавливаем флаг только для чтения
                        ui->tableWidget_check->setItem(currentRow,i,ti);
                    }
                }

                ///Получаем и вписываем значения из таблиц
                ui->tableWidget_check->item(currentRow,0)->setText(query.value(2).toString());
                ui->tableWidget_check->item(currentRow,3)->setText(query.value(3).toString());

                QSqlQuery qw(*db);
                qw.prepare("SELECT * FROM data.performer WHERE id_performer = :id");
                qw.bindValue(":id",id_performer);
                qw.exec();
                qw.next();
                ui->tableWidget_check->item(currentRow,1)->setText(qw.value(3).toString());

                ui->tableWidget_check->item(currentRow,2)->setText(name);

                qw.prepare("SELECT * FROM data.genre WHERE id_genre = :id");
                qw.bindValue(":id",id_genre);
                qw.exec();
                qw.next();
                ui->tableWidget_check->item(currentRow,4)->setText(qw.value(1).toString());
                currentRow++;
            }
        }
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Выберите альбом");
    }
}

void MainWindow::on_pushButton_agree_clicked()//обработка одобрения альбома
{
    int id = ui->pushButton_agree->property("id_album").toInt();
    int id_performer = ui->pushButton_agree->property("id_performer").toInt();
    int id_genre = ui->pushButton_agree->property("id_genre").toInt();
    int year = ui->pushButton_agree->property("year").toInt();
    QString name = ui->pushButton_agree->property("name").toString();

    QSqlQuery query(*db);

    query.prepare("INSERT INTO data.album (year,id_performer,number_minute,id_genre,name_album) VALUES (:1,:2,:3,:4,:5)");
    query.bindValue(":1",year);
    query.bindValue(":2",id_performer);
    query.bindValue(":3",0);
    query.bindValue(":4",id_genre);
    query.bindValue(":5",name);

    query.exec();

    if(query.lastError().type() == QSqlError::NoError)
    {
        query.prepare("SELECT id_album FROM data.album ORDER BY id_album DESC LIMIT 1");
        query.exec();
        query.next();
        int id_album = query.value(0).toInt();

        if(query.lastError().type() == QSqlError::NoError)
        {
            for (int i =0;i<ui->tableWidget_check->rowCount();i++)
            {
                query.prepare("INSERT INTO data.track (name_track,duration,id_performer,id_album,number_plays,id_genre) VALUES (:1,:2,:3,:4,:5,:6)");
                query.bindValue(":1",ui->tableWidget_check->item(i,0)->text());
                query.bindValue(":2",ui->tableWidget_check->item(i,3)->text().toInt());
                query.bindValue(":3",id_performer);
                query.bindValue(":4",id_album);
                query.bindValue(":5",0);
                query.bindValue(":6",id_genre);
                query.exec();

            }
            if(query.lastError().type() != QSqlError::NoError)
            {
                QMessageBox::warning(this,"Ошибка",query.lastError().text());
            }
            else
            {
                QMessageBox::information(this,"Запрос","Альбом добавлен");
                ui->comboBox_check->setCurrentIndex(0);
                ui->tableWidget_check->setRowCount(0);
                updateCheckingAlbums();
                deleteFromCheckingTable(id);
            }
        }
    }
    else
    {
        QMessageBox::warning(this,"Ошибка",query.lastError().text());
    }
}

void MainWindow::deleteFromCheckingTable(int id)//удаление альбома из таблицы запросов
{
    QSqlQuery query(*db);

    query.prepare("DELETE FROM data.checking_tracks WHERE id_album = :1");
    query.bindValue(":1",id);
    query.exec();

    if(query.lastError().type() == QSqlError::NoError)
    {
        query.prepare("DELETE FROM data.checking_album WHERE id_operation = :1");
        query.bindValue(":1",id);
        query.exec();
        if(query.lastError().type() != QSqlError::NoError)
        {
            QMessageBox::warning(this,"Ошибка",query.lastError().text());
        }

    }
    else
    {
        QMessageBox::warning(this,"Ошибка",query.lastError().text());
    }
}

void MainWindow::on_pushButton_reject_clicked()//обработка отказа альбома
{
    int id_album = ui->pushButton_reject->property("id_album").toInt();
    deleteFromCheckingTable(id_album);
    QMessageBox::information(this,"Запрос","Запрос отклонен");
    ui->comboBox_check->setCurrentIndex(0);
    updateCheckingAlbums();
    ui->tableWidget_check->setRowCount(0);

}

void MainWindow::on_pushButton_closeFrame_clicked()//обработка закрытия окна
{
    ui->frame->hide();
    ui->lineEdit_changePlaylist->clear();
}

void MainWindow::on_pushButton_changePlaylist_clicked()//обработка изменения названия плейлиста
{
    int id_playlist = ui->pushButton_changePlaylist->property("id").toInt();
    auto name = ui->lineEdit_changePlaylist->text().trimmed();
    if(ui->lineEdit_changePlaylist->text() != nullptr)
    {
        QSqlQuery query(*db);
        query.prepare("UPDATE data.added_playlists SET name_playlist = :2 WHERE id_playlist = :1");
        query.bindValue(":1",id_playlist);
        query.bindValue(":2",name);
        query.exec();

        if(query.lastError().type() == QSqlError::NoError)
        {
            QMessageBox::information(this,"Название","Название изменено");
            myPlaylist();
        }
        else
        {
            QMessageBox::warning(this,"Ошибка",query.lastError().text());
        }
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Введите новое название");
    }
}


void MainWindow::updateTrackPopularity(int id)//функция обновления популярности треков
{
    QSqlQuery qw(*db);
    qw.prepare("SELECT * FROM data.added_tracks WHERE id_track = :1");
    qw.bindValue(":1",id);
    qw.exec();
    int count = qw.size();

    qw.prepare("UPDATE data.track SET number_plays = :new WHERE id_track = :id");//запрос обновления данных
    qw.bindValue(":new",count);
    qw.bindValue(":id",id);
    qw.exec();
}
