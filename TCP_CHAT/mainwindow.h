#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

#include <QFile>
#include <QFileDialog>
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
#include <windows.h>
#include <dos.h>
#include <QTimer>
#include <QVector>

#define BUF_SIZE 1024*4
#define SIZE_BLOCK_FOR_SEND_FILE 1024*4


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void MessageToAllClients(QString message,int number);

    void textRight();
    void textLeft();
    void textCenter();

    void deleteServer();
    void deleteClients();




private slots:
    void on_radioButton_client_clicked();

    void on_radioButton_server_clicked();

    void read_data(void);
    void socket_read_data(void);
    void on_timer();//слот обработки события таймера

    void new_connection(void);

    void socketDisconnected();
    //void socketStateChanged(QAbstractSocket::SocketState state);

    void Connected();
    void Disconnected();
    void socketErrors(QAbstractSocket::SocketError error);

    void on_pushButton_work_clicked();

    void on_pushButton_send_2_clicked();

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

    void on_pushButton_settings_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_close_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_theme_clicked();

    void on_pushButton_spam_clicked();

    void on_pushButton_file_clicked();

private:
    Ui::MainWindow *ui;
    QTcpServer *TCP_SERVER=nullptr;
    QTcpSocket *TCP_SOCKET=nullptr;

    QTimer *timer; //указатель на класс Таймер
    int counter;//счетчик

    QString random[5]={"Абубубуу","Кис кис","Я котик ты котик","Хочу шашлычка","Давай по новой"};

    QPalette st=style()->standardPalette();

    QVector<QTcpSocket*>* clients=nullptr;//вектор пользователей

    QString our_adr;//наш айпи

    QString text_port,text_adress,text_name;


    int port;
    QHostAddress *adress;

    bool station;//для выбора режима сервера или клиента

    bool fl=false;//для ситуации подключения и отключения

    bool fl_menu=false;//Для окна со смайлами

    bool fl_server=false;//Для создание и отключения сервера

    bool fl_settings=false;

    bool fl_theme;

    bool fl_user=false;

    bool fl_talk=false;

    bool fl_File=false;

    QFile * m_localFile; // Указатель файла
    qint64 m_totalBytes; // Общий размер отправленного файла
    qint64 m_bytesToWrite; // Оставшийся непереданный размер
    qint64 m_bytesWritten; // Размер файла, который был отправлен
    qint64 m_payloadSize; // Каждый раз, когда значение передается
   // Progress * m_pgs; // Диалоговое окно, в котором находится индикатор выполнения


};

#endif // MAINWINDOW_H
