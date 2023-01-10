#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDate>
#include <QDebug>
#include "user.h"
#include "patterns.h"
#include "database.h"
#include "actionwithgenre.h"
#include "actionwithhall.h"
#include "actionwithmovie.h"
#include "actionwithsession.h"
#include "dialogforreview.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QInputDialog>
#include <QCryptographicHash>
#include <QTimer>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow,private DataBase
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void connectToBD();//функция подключения к БД
    bool checkForLogin(QString login,QString password);//функция для авторизации пользователя
    void updateInfo(int index);//функция обновления информации в рабочих окнах

    void registerData(QString login, QString password, QString bd="", QString email="", QString phoneNumber="");//функция регистрации данных о пользователе
    bool checkLoginForRegister(QString login);//функция проверки уникальности вводимого для регистрации логина
    void clearRegFrame();//функция очистки окна регистрации

    void checkSessions();//функция вывода доступных сеансов
    void ticketsHistory();//функция вывода истории покупок
    void moviesHistory();//функция вывода истории просмотров
    void basketList();//функция вывода корзины покупок
    void deleteFromBasket(int ticket_id);//функция удаления товара из корзины

    void loadPlaces(int session_id);//функция отображения мест в зале
    QString hashPassword(QString str);//функция хеширования пароля
    ~MainWindow();

private slots:
    void on_pushButton_viewReg_clicked();

    void on_pushButton_enter_clicked();

    void on_pushButton_reg_clicked();

    void on_pushButton_closeRegFrame_clicked();

    void on_pushButton_echoChange_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_calendarWidget_clicked(const QDate &date);

    void on_pushButton_search_clicked();

    void movieInfo();//обработка запроса получения данных о фильма
    void choicePlace();//обработка выбора мест
    void buyTicket();//обработка покупки билета
    void deleteTicket();//обработка удаления билета из корзины
    void setReviews();//обработка вызова окна отправки отзыва

    void on_pushButton_addToBasket_clicked();

    void on_pushButton_closeMovieInfo_clicked();

    void on_pushButton_ActionWithMovie_clicked();

    void on_pushButton_ActionWithGenre_clicked();

    void on_pushButton_ActionWithSession_clicked();

    void on_lineEdit_login_textChanged();

    void on_lineEdit_password_textChanged();
    void timer();//обработка таймера

    void on_radioButton_user_clicked();

    void on_radioButton_admin_clicked();

private:
    Ui::MainWindow *ui;

    User *user;//объект класса пользователя для хранения данных о нем
    QString currentDate=QDate::currentDate().toString("yyyy-MM-dd");//текущая дата
    QVector<QVector<QPushButton*>> buttons();//вектор мест в зале
    //Булевые значения для обработки режима работ
    bool echoMode = true;
    bool fl_enter = false;
};

#endif // MAINWINDOW_H
