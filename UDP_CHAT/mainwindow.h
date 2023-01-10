#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QUdpSocket> // Библиотека работы с UDP
#include <QFile>
#include <QMessageBox>
#include <QNetworkAddressEntry>
#include <QFontDatabase>
#include <QIcon>
#include <QTextBlockFormat>

#include <QRegExpValidator>
#include <QTime>
#include <QToolButton>
#include <QListWidget>
#include <QDirIterator>
#include <QScrollBar>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool fl_menu=false;

private slots:
    void on_pushButton_create_clicked();
    void read_data(void); // слот для обработки поступивших данных

    void on_pushButton_send_clicked();


    void on_pushButton_clicked();

    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

    void on_pushButton3_clicked();

    void on_pushButton4_clicked();

    void on_pushButton5_clicked();

    void on_pushButton6_clicked();

    void on_pushButton7_clicked();

    void on_pushButton8_clicked();

    void on_pushButton9_clicked();

    void on_pushButton10_clicked();

    void on_pushButton11_clicked();

    void on_pushButton12_clicked();

private:
    Ui::MainWindow *ui;
    QUdpSocket *udpsocket;// сам UDP сокет(указатель на него)
    QHostAddress *adress;//для адреса
    int port, our_port;//порты
    QListWidget *m_emojiListWidget;
    bool fl=false;//проверка на создание соединения
};

#endif // MAINWINDOW_H
