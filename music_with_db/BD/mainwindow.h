#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include "user.h"
#include <QDebug>
#include "validation.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    void connectToBD();
    void updateInfo(int index);
    void registerUser(QString login,QString password,QString nameGroup ="",QString genre ="",QString participans = "");
    bool checkLoginForRegister(QString login);
    bool checkForLogin(QString login,QString password);
    void searchTrack(QString name);


    void topMusic();
    void myMusic();
    void myPlaylist();

    void updateCountMinutes(int id_playlist);
    void updateCountAddedTracks(int id_playlist);
    void updateTrackPopularity(int id);
    void updateTrackList(int id_playlist,QString name);

    void updateGenres();
    void updateAlbums();
    void updateCheckingAlbums();

    void deleteFromCheckingTable(int id);

    void cleanLineEdit();



    ~MainWindow();

private slots:
    void addTrack();

    void deleteTrack();
    void deleteTrackFromPlaylist();

    void openPlaylist();
    void addPlaylists(int index);
    void deletePlaylist();
    void changePlaylist();
    void on_pushButton_toReg_clicked();

    void on_pushButton_reg_clicked();

    void on_pushButton_enter_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_search_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_createPlaylist_2_clicked();

    void on_lineEdit_login_textChanged();

    void on_lineEdit_password_textChanged();

    void on_pushButton_sendToCheck_clicked();

    void on_spinBox_count_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_pushButton_open_clicked();

    void on_pushButton_agree_clicked();

    void on_pushButton_reject_clicked();

    void on_pushButton_closeFrame_clicked();

    void on_pushButton_changePlaylist_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase * db;

    user *client;//для хранения данных о пользователе

};

#endif // MAINWINDOW_H
