#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    timer= new QTimer(this);//Создание экземпляра таймера
    connect(timer,SIGNAL(timeout()),this,SLOT(on_timer()));//соединение события с таймером
    counter=0;



    // Создаём палитру для тёмной темы оформления
    QPalette darkPalette;

    // Настраиваем палитру для цветовых ролей элементов интерфейса
    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
    //darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    //darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    qApp->setPalette(darkPalette);//Присваиваем приложению темную тему


    ui->setupUi(this);
    ui->label_seans->hide();
    //=============Закрываем доступ к виджетам для пользователя=========================
    ui->label_port->setEnabled(false);
    ui->label_adress->setEnabled(false);

    ui->lineEdit_adress->setEnabled(false);
    ui->lineEdit_port->setEnabled(false);

    ui->lineEdit_message_2->setEnabled(false);
    ui->pushButton_send_2->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_work->setEnabled(false);
    ui->pushButton_spam->setEnabled(false);
    ui->pushButton_file->setEnabled(false);
    ui->lineEdit_name->setEnabled(false);
    ui->frame_2->hide();

    //====================================================================================


    //==============================Выводим наш айпи======================================================
    auto adr=QNetworkInterface::allAddresses();
    our_adr=adr[2].toString();//записываем наш адрес
    ui->textEdit_input_2->setReadOnly(true);
    //====================================================================================
    //=================================Коннектим кнопку ENTER к QlineEdit===================================================
    connect(ui->lineEdit_message_2, &QLineEdit::returnPressed, this, &MainWindow::on_pushButton_send_2_clicked);

    //Создание IP валидатора для QLineEdit

    QString ipRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
    /* Создаем регулярное выражение с применением строки, как
         * повторяющегося элемента
         */
    QRegExp ipRegex ("^" + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange + "$");
    /* Создаем Валидатор регулярного выражения с применением
         * созданного регулярного выражения
         */
    QRegExpValidator *ipValidator = new QRegExpValidator(ipRegex, this);
    /* Устанавливаем Валидатор на QLineEdit */
    ui->lineEdit_adress->setValidator(ipValidator);
    ui->lineEdit_port->setValidator(new QIntValidator(1,65535,this));

    //==================Задаем шрифт для корректного отображения смайликов============================================
    QFontDatabase fontDB;
    fontDB.addApplicationFont(":/A Font Supporting Emoji.ttf");
    qApp->setFont(QFont(QStringLiteral("A Font Supporting Emoji")));
    //==================================================================================
    ui->lineEdit_message_2->setClearButtonEnabled(true);
    ui->lineEdit_port->setClearButtonEnabled(true);
    ui->lineEdit_adress->setClearButtonEnabled(true);
    //==================Задаем иконку===========================================
    QIcon message(":new/send_121758(1).ico");
    ui->lineEdit_message_2->addAction(message, QLineEdit::LeadingPosition);

    QIcon theme(":new/night-shift-1_110443.ico");
    ui->pushButton_theme->setIcon(theme);

    QIcon file(":new/file.ico");
    ui->pushButton_file->setIcon(file);


    //    ui->lineEdit_message_2->addAction(emoji, QLineEdit::TrailingPosition);
    //==================================================================================

    //========Открываем файл со стилями и передаем виджетам==============


    ui->lineEdit_port->setPlaceholderText("Введите порт сервера");
    ui->lineEdit_adress->setPlaceholderText("Введите адрес сервера");
    ui->lineEdit_message_2->setPlaceholderText("Напишите сообщение...");


    QFile style_dark(":new/style_dark.css");
    style_dark.open(QFile::ReadOnly);

    auto styleDark = QString::fromUtf8(style_dark.readAll());
    //===============================Присваиваем стили====================================================
    ui->pushButton_work->setStyleSheet(styleDark);
    ui->pushButton_spam->setStyleSheet(styleDark);
    ui->pushButton_send_2->setStyleSheet(styleDark);
    ui->pushButton_save->setStyleSheet(styleDark);
    ui->pushButton_settings->setStyleSheet(styleDark);
    ui->pushButton_clear->setStyleSheet(styleDark);
    ui->pushButton_close->setStyleSheet(styleDark);
    ui->pushButton_theme->setStyleSheet(styleDark);
    ui->lineEdit_port->setStyleSheet(styleDark);
    ui->lineEdit_name->setStyleSheet(styleDark);

    ui->lineEdit_adress->setStyleSheet(styleDark);
    ui->lineEdit_message_2->setStyleSheet(styleDark);
    ui->textEdit_input_2->setStyleSheet(styleDark);

    ui->label_seans->setStyleSheet("color:#d60096;");

    //=========================================================================

    //========================Отображение смайликов на кнопках===================================================
    ui->pushButton1->setText("\U0001F600");
    ui->pushButton2->setText("\U0001F601");
    ui->pushButton3->setText("\U0001F602");
    ui->pushButton4->setText("\U0001F603");
    ui->pushButton5->setText("\U0001F604");
    ui->pushButton6->setText("\U0001F605");
    ui->pushButton7->setText("\U0001F606");
    ui->pushButton8->setText("\U0001F607");
    ui->pushButton9->setText("\U0001F608");
    ui->pushButton10->setText("\U0001F62D");
    ui->pushButton11->setText("\U0001F60D");
    ui->pushButton12->setText("\U0001F499");
    ui->frame->hide();

    QIcon emoji(":new/bubblesmiley_102154.ico");
    ui->pushButton->setIcon(emoji);

    QFile style_Emoji(":new/styleSmile_dark.css");
    style_Emoji.open(QFile::ReadOnly);
    auto styleEmoji = QString::fromUtf8(style_Emoji.readAll());
    ui->pushButton->setStyleSheet(styleEmoji);

    QFile style_file(":new/styleFile_dark.css");
    style_file.open(QFile::ReadOnly);
    auto styleFile = QString::fromUtf8(style_file.readAll());
    ui->pushButton_file->setStyleSheet(styleFile);

    auto adres=QNetworkInterface::allAddresses();
    ui->label_our_adress->setText("Наш IP-адрес: <b>"+adres[2].toString()+"</b>");
    ui->radioButton_server->click();
}

MainWindow::~MainWindow()//деструктор
{
    disconnect(timer,SIGNAL(timeout()),this,SLOT(on_timer()));
    timer=nullptr;
    deleteServer();
    deleteClients();
    delete ui;
}

void MainWindow::deleteServer()//удаление сервера
{
    if(TCP_SERVER!=nullptr)
    {
        if(TCP_SERVER->isListening()) TCP_SERVER->close();
        TCP_SERVER->deleteLater();
        TCP_SERVER=nullptr;
    }
}
void MainWindow::deleteClients()//удаление клиентов
{

    if(clients!=nullptr)
    {
        int size=clients->length();
        if(size>0)
        {
            for (int i = size-1; i >= 0; i--)
            {
                auto client=clients->at(i);
                if(client->isOpen())
                {
                    client->close();
                    client->disconnect();
                }
                client->deleteLater();
            }
            clients->clear();
        }

    }
}


void MainWindow::on_radioButton_client_clicked()//Режим клиента
{
    ui->lineEdit_port->setEnabled(true);
    ui->lineEdit_adress->setEnabled(true);

    ui->label_adress->setEnabled(true);
    ui->label_port->setEnabled(true);
    ui->lineEdit_name->setEnabled(true);
    station=false;
}

void MainWindow::on_radioButton_server_clicked()//Режим сервера
{
    ui->lineEdit_port->setEnabled(true);
    ui->lineEdit_adress->setEnabled(false);
    ui->label_adress->setEnabled(false);
    ui->label_port->setEnabled(true);
    ui->lineEdit_name->setEnabled(false);

    station=true;
}

void MainWindow::on_pushButton_work_clicked()//Кнопка работы
{
    if(station)//если мы в режиме сервера
    {
        if(!fl_server)//если запуск сервера
        {
            port=ui->lineEdit_port->text().toInt();//считываем порт
            ui->textEdit_input_2->clear();
            TCP_SERVER=new QTcpServer(this);//инициализируем сервер
            TCP_SERVER->setMaxPendingConnections(15);//максимум пользователей
            clients = new QVector<QTcpSocket*>;//инициализируем клиентов


            if(TCP_SERVER->listen(QHostAddress::Any,port))
            {
                connect(TCP_SERVER,SIGNAL(newConnection()),this,SLOT(new_connection()));//cоединяем сигналы со слотами лоя обработки
                m_payloadSize  = 4*1024;
                m_totalBytes   = 0;
                m_bytesWritten = 0;
                m_bytesToWrite = 0;
                m_localFile = nullptr;
                connect(TCP_SERVER,SIGNAL(bytesWritten(qint64)),this,SLOT(continueSendData(qint64)));

                ui->label_seans->show();
                ui->label_seans->setText("<font>Участников 0/15</font>");
                ui->pushButton_spam->setEnabled(true);
                ui->lineEdit_message_2->setEnabled(true);
                ui->pushButton_send_2->setEnabled(true);
                ui->pushButton->setEnabled(true);
                ui->pushButton_file->setEnabled(true);

                ui->textEdit_input_2->append("<font color=#353535>------------------<b>Сервер запущен</b>------------------</font>");
                textCenter();//вывод текста по центру
                fl_server=true;
                ui->pushButton_work->setText("Прервать");
            }
            else
            {
                QMessageBox::information(this,"Ошибка","Сервер не удалось запустить");
            }
        }
        else//если закрытие сервера
        {
            for (int i = 0; i < clients->size(); i++)
            {
                clients->at(i)->disconnectFromHost();//отключаем от сервера
            }
            TCP_SERVER->close();
            fl_server=false;

            ui->pushButton_work->setText("Создать");
            ui->textEdit_input_2->clear();

            ui->label_seans->hide();
            ui->lineEdit_message_2->setEnabled(false);
            ui->pushButton_send_2->setEnabled(false);
            ui->pushButton_spam->setEnabled(false);
            ui->pushButton->setEnabled(false);
            ui->pushButton_file->setEnabled(false);
            ui->frame->hide();
            timer->stop();//останавливаем
            fl_talk=false;
            ui->pushButton_spam->setText("Включить спам");
        }


    }

    else//если мы в режиме клиента
    {
        if(!fl)//если подключение
        {
            TCP_SOCKET=new QTcpSocket(this);

            adress= new QHostAddress;
            adress->setAddress(ui->lineEdit_adress->text());

            port=ui->lineEdit_port->text().toInt();
            ui->label_seans->hide();
            TCP_SOCKET->connectToHost(*adress,port);
            //=============================Соединяем сигналы со слотами для обработки=======================================================
            connect(TCP_SOCKET, SIGNAL(connected()), this, SLOT(Connected()));
            connect(TCP_SOCKET, SIGNAL(disconnected()), this, SLOT(Disconnected()));
            connect(TCP_SOCKET,SIGNAL(readyRead()),this,SLOT(socket_read_data()));
            connect(TCP_SOCKET, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &MainWindow::socketErrors);

            m_payloadSize  = 4*1024;
            m_totalBytes   = 0;
            m_bytesWritten = 0;
            m_bytesToWrite = 0;
            m_localFile = nullptr;

            connect(TCP_SOCKET,SIGNAL(bytesWritten(qint64)),this,SLOT(continueSendData(qint64)));
            //====================================================================================

            ui->textEdit_input_2->clear();
            fl_user=true;

        }
        else//если откоючение
        {
            TCP_SOCKET->disconnectFromHost();
            ui->textEdit_input_2->clear();
            ui->lineEdit_message_2->setEnabled(false);
            ui->pushButton_send_2->setEnabled(false);
            ui->pushButton->setEnabled(false);
            ui->pushButton_spam->setEnabled(false);
            ui->pushButton_file->setEnabled(false);
            ui->frame->hide();
            timer->stop();//останавливаем
            fl_talk=false;
            ui->pushButton_spam->setText("Включить спам");
            fl_user=false;
        }

    }
}

void MainWindow::new_connection()//к нам подключились
{
    //    TCP_SOCKET=TCP_SERVER->nextPendingConnection();
    QTcpSocket* client = TCP_SERVER->nextPendingConnection();
    //Считываем айпи и порт подключившегося
    QString ipAddress = client->peerAddress().toString().split(":").last();
    int port = client->peerPort();

    ui->textEdit_input_2->show();
    ui->lineEdit_message_2->show();
    ui->pushButton_send_2->show();
    ui->pushButton->show();
    ui->label_seans->show();

    connect(client,&QTcpSocket::readyRead, this, &MainWindow::read_data);
    connect(client, &QTcpSocket::disconnected, this, &MainWindow::socketDisconnected);
    //connect(TCP_SOCKET, &QTcpSocket::stateChanged, this, &MainWindow::socketStateChanged);

    clients->push_back(client);//добавляем пользователь в массив
    int number = 0;
    for (int i = 0; i < clients->size(); i++)
    {
        if (client==clients->at(i))//если клиент В СЕТИ и ДОСТУПЕН
        {
            number=i;
        }
    }


    ui->label_seans->setText("<font>Участников "+QString::number(clients->size())+"/15</font>");
    ui->textEdit_input_2->append("<font size=2 color=\"Green\">" + ipAddress.toUtf8() +":"+ QString::number(port).toUtf8() + " подключился к чату.</font>");
    textCenter();

    MessageToAllClients("<font color=\"Blue\">" + ipAddress.toUtf8() +":"+ QString::number(port).toUtf8() + " подключился к чату.</font>",number);
}


void MainWindow::socketDisconnected()//при выходе одного из пользователей
{
    QTcpSocket* client = qobject_cast<QTcpSocket*>(QObject::sender());
    QString client_IpAddress = client->peerAddress().toString().split(":").last();
    int port = client->peerPort();

    client->deleteLater();
    clients->removeOne(client);

    ui->label_seans->setText("<font>Участников "+QString::number(clients->size())+"/15</font>");
    ui->textEdit_input_2->append("<font size=2 color=\"Red\"Пользователь >" + client_IpAddress.toUtf8() +":"+ QString::number(port).toUtf8() + " отключился от чата.</font>");
    textCenter();
    MessageToAllClients("<font color=\"Red\"Пользователь >" + client_IpAddress.toUtf8() +":"+ QString::number(port).toUtf8() + " отключился от чата.</font>",5000);
}



void MainWindow::read_data()//чтение сообщения
{

    QTcpSocket* client = qobject_cast<QTcpSocket*>(QObject::sender());
    QString client_IpAddress = client->peerAddress().toString().split(":").last();

    int port = client->peerPort();
    QString data = QString(client->readAll());

    int number=0;
    for (int i = 0; i < clients->size(); i++)
    {
        if (client==clients->at(i))//если клиент В СЕТИ и ДОСТУПЕН
        {
            number=i;
        }
    }


    if(fl_File)
    {
        ui->textEdit_input_2->append("<embed src="+data+">");//выводим полученное сообщение
        MessageToAllClients(data,number);//передаём сообщение всем
    }
    else {
        auto Time=QTime::currentTime().toString("HH:mm");//узнаём время получения сообщения
        ui->textEdit_input_2->append("<font color=#b300b3>" + data +"</font>"+ "<font size=2><i> ("+client_IpAddress + ":" + QString::number(port)+")</font></i><font size=1> "+" "+Time+"</font>");//выводим полученное сообщение
        MessageToAllClients(data,number);//передаём сообщение всем

        //========================Делаем отображние сообщения с правой стороны QTextEdit===================================================
        textRight();
    }

    //    auto Time=QTime::currentTime().toString("HH:mm");//узнаём время получения сообщения
    //    ui->textEdit_input_2->append("<font color=#b300b3>" + data +"</font>"+ "<font size=2><i> ("+client_IpAddress + ":" + QString::number(port)+")</font></i><font size=1> "+" "+Time+"</font>");//выводим полученное сообщение
    //    MessageToAllClients(data,number);//передаём сообщение всем

    //    //========================Делаем отображние сообщения с правой стороны QTextEdit===================================================
    //    textRight();

}

void MainWindow::MessageToAllClients(QString message,int number)//отправка сообщений всем пользователям
{
    if (clients->size() > 0)// если есть хоть один клиент
    {
        for (int i = 0; i < clients->size(); i++)
        {
            if(number!=i)
            {
                if (clients->at(i)->isOpen() && clients->at(i)->isWritable())//если клиент В СЕТИ и ДОСТУПЕН
                {
                    clients->at(i)->write(message.toUtf8());// отправляем сообщение
                }
            }
        }
    }

}

void MainWindow::socketErrors(QAbstractSocket::SocketError error)//обработчик ошибок для клиента
{
    if(error==QAbstractSocket::ConnectionRefusedError)
    {
        ui->lineEdit_message_2->setEnabled(false);
        ui->pushButton_send_2->setEnabled(false);
        ui->pushButton->setEnabled(false);
        ui->pushButton_spam->setEnabled(false);
        ui->pushButton_file->setEnabled(false);
        QMessageBox::information(this,"Ошибка","Истекло время ожидания.");

    }
    else if(error==QAbstractSocket::RemoteHostClosedError)
    {
        ui->lineEdit_message_2->setEnabled(false);
        ui->pushButton_send_2->setEnabled(false);
        ui->pushButton->setEnabled(false);
        ui->pushButton_spam->setEnabled(false);
        ui->pushButton_file->setEnabled(false);

        timer->stop();//останавливаем
        ui->pushButton_spam->setText("Запустить спам");
        fl_talk=false;
        QMessageBox::information(this,"Ошибка","Удаленный хост закрыл соединение.");
    }
    else if(error==QAbstractSocket::HostNotFoundError)
    {

        ui->lineEdit_message_2->setEnabled(false);
        ui->pushButton_send_2->setEnabled(false);
        ui->pushButton->setEnabled(false);
        ui->pushButton_spam->setEnabled(false);
        ui->pushButton_file->setEnabled(false);
        QMessageBox::information(this,"Ошибка","Адрес хоста не был найден.");
    }
    else if(error==QAbstractSocket::SocketAccessError)
    {
        QMessageBox::information(this,"Ошибка","Операция сокета завершилась неудачно, поскольку приложению не хватало необходимых привилегий.");
    }
    else if(error==QAbstractSocket::SocketResourceError)
    {
        QMessageBox::information(this,"Ошибка","В локальной системе закончились ресурсы (например, слишком много сокетов).");
    }
    else if(error==QAbstractSocket::SocketTimeoutError)
    {

        ui->lineEdit_message_2->setEnabled(false);
        ui->pushButton_send_2->setEnabled(false);
        ui->pushButton->setEnabled(false);
        ui->pushButton->setEnabled(false);
        ui->pushButton_file->setEnabled(false);
        timer->stop();//останавливаем
        ui->pushButton_spam->setText("Запустить спам");
        fl_talk=false;
        QMessageBox::information(this,"Ошибка","Время ожидания работы сокета истекло.");
    }
    else if(error==QAbstractSocket::DatagramTooLargeError)
    {
        QMessageBox::information(this,"Ошибка","Размер дейтаграммы превышал предельный размер операционной системы ");
    }
    else if(error==QAbstractSocket::NetworkError)
    {
        QMessageBox::information(this,"Ошибка","Произошла ошибка в сети.");
    }

}

void MainWindow::Connected()//слот для обработки подключения
{
    ui->textEdit_input_2->append("<font color=\"Green\">Присоединились к серверу.</font>");
    //TCP_SOCKET->write("<font color=\"Blue\">" + our_adr.toUtf8() +":"+ QString::number(port).toUtf8() + " подключился к чату.</font>");
    textCenter();
    ui->pushButton_work->setText("Отключиться");
    ui->lineEdit_message_2->setEnabled(true);
    ui->pushButton_send_2->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->pushButton_spam->setEnabled(true);
    ui->pushButton_file->setEnabled(true);
    fl = true;
}

void MainWindow::Disconnected()//слот для обработки отключения
{
    ui->textEdit_input_2->append("<font color=\"Red\">Отключение от сервера.</font>");
    textCenter();
    ui->pushButton_work->setText("Подключиться");

    timer->stop();//останавливаем
    ui->pushButton_spam->setText("Запустить спам");
    fl_talk=false;

    fl = false;
}


void MainWindow::socket_read_data()//Обработка приходящих данных для клиента
{
    auto Time=QTime::currentTime().toString("HH:mm");
    ui->textEdit_input_2->append("<font color=#b300b3>"+ TCP_SOCKET->readAll() + " "+"</font>" +"<font size=1>"+Time+"</font>");
    textRight();
}

void MainWindow::on_pushButton_send_2_clicked()//отправка сообщений
{
    if(fl_File)
    {

    }
    else
    {
        auto x=ui->lineEdit_message_2->text();
        if(x!=nullptr)
        {
            QString message = ui->lineEdit_message_2->text();
            if(!station)//если мы клиент
            {
                TCP_SOCKET->write("["+ui->lineEdit_name->text().toUtf8()+"]"+message.toUtf8());
                auto Time=QTime::currentTime().toString("HH:mm");
                ui->textEdit_input_2->append("<font color=#235AF0>"+ message + " "+"</font>" + "<font size=1>"+Time+"</font>");
                textLeft();
                ui->lineEdit_message_2->clear();
            }
            else//если сервер
            {
                MessageToAllClients("Сервер: "+message,5000);
                auto Time=QTime::currentTime().toString("HH:mm");
                ui->textEdit_input_2->append("<font color=#d60096>"+ message + " "+"</font>" + "<font size=1>"+Time+"</font>");
                textLeft();
                ui->lineEdit_message_2->clear();
            }
        }
    }
}

void MainWindow::textLeft()//функция для вывода текста слева
{
    QTextCursor newCursor = ui->textEdit_input_2->textCursor();
    newCursor.movePosition(QTextCursor::End);
    ui->textEdit_input_2->setTextCursor(newCursor);
    QTextBlockFormat textBlockFormat = newCursor.blockFormat();
    textBlockFormat.setAlignment(Qt::AlignLeft);
    newCursor.mergeBlockFormat(textBlockFormat);
    ui->textEdit_input_2->setTextCursor(newCursor);
}

void MainWindow::textRight()//функция для вывода текста справа
{
    QTextCursor newCursor = ui->textEdit_input_2->textCursor();
    newCursor.movePosition(QTextCursor::End);
    ui->textEdit_input_2->setTextCursor(newCursor);
    QTextBlockFormat textBlockFormat = newCursor.blockFormat();
    textBlockFormat.setAlignment(Qt::AlignRight);
    newCursor.mergeBlockFormat(textBlockFormat);
    ui->textEdit_input_2->setTextCursor(newCursor);
}

void MainWindow::textCenter()//функция для вывода текста по центру
{
    QTextCursor newCursor = ui->textEdit_input_2->textCursor();
    newCursor.movePosition(QTextCursor::End);
    ui->textEdit_input_2->setTextCursor(newCursor);
    QTextBlockFormat textBlockFormat = newCursor.blockFormat();
    textBlockFormat.setAlignment(Qt::AlignCenter);
    newCursor.mergeBlockFormat(textBlockFormat);
    ui->textEdit_input_2->setTextCursor(newCursor);
}


void MainWindow::on_pushButton_clicked()//открытие меню со смайлами
{
    if(!fl_menu){
        ui->frame->show();
        fl_menu=true;
    }
    else {
        ui->frame->hide();
        fl_menu=false;
    }
}


void MainWindow::on_pushButton1_clicked()//кнопка смайлика
{
    QString str=ui->lineEdit_message_2->text()+"\U0001F600";
    ui->lineEdit_message_2->setText(str);
    ui->lineEdit_message_2->setFocus();
}

void MainWindow::on_pushButton2_clicked()//кнопка смайлика
{
    QString str=ui->lineEdit_message_2->text()+"\U0001F601";
    ui->lineEdit_message_2->setText(str);
    ui->lineEdit_message_2->setFocus();
}

void MainWindow::on_pushButton3_clicked()//кнопка смайлика
{
    QString str=ui->lineEdit_message_2->text()+"\U0001F602";
    ui->lineEdit_message_2->setText(str);
    ui->lineEdit_message_2->setFocus();
}

void MainWindow::on_pushButton4_clicked()//кнопка смайлика
{
    QString str=ui->lineEdit_message_2->text()+"\U0001F603";
    ui->lineEdit_message_2->setText(str);
    ui->lineEdit_message_2->setFocus();
}

void MainWindow::on_pushButton5_clicked()//кнопка смайлика
{
    QString str=ui->lineEdit_message_2->text()+"\U0001F604";
    ui->lineEdit_message_2->setText(str);
    ui->lineEdit_message_2->setFocus();
}

void MainWindow::on_pushButton6_clicked()//кнопка смайлика
{
    QString str=ui->lineEdit_message_2->text()+"\U0001F605";
    ui->lineEdit_message_2->setText(str);
    ui->lineEdit_message_2->setFocus();
}

void MainWindow::on_pushButton7_clicked()//кнопка смайлика
{
    QString str=ui->lineEdit_message_2->text()+"\U0001F606";
    ui->lineEdit_message_2->setText(str);
    ui->lineEdit_message_2->setFocus();
}

void MainWindow::on_pushButton8_clicked()//кнопка смайлика
{
    QString str=ui->lineEdit_message_2->text()+"\U0001F607";
    ui->lineEdit_message_2->setText(str);
    ui->lineEdit_message_2->setFocus();
}

void MainWindow::on_pushButton9_clicked()//кнопка смайлика
{
    QString str=ui->lineEdit_message_2->text()+"\U0001F608";
    ui->lineEdit_message_2->setText(str);
    ui->lineEdit_message_2->setFocus();
}

void MainWindow::on_pushButton10_clicked()//кнопка смайлика
{
    QString str=ui->lineEdit_message_2->text()+"\U0001F62D";
    ui->lineEdit_message_2->setText(str);
    ui->lineEdit_message_2->setFocus();
}

void MainWindow::on_pushButton11_clicked()//кнопка смайлика
{
    QString str=ui->lineEdit_message_2->text()+"\U0001F60D";
    ui->lineEdit_message_2->setText(str);
    ui->lineEdit_message_2->setFocus();
}

void MainWindow::on_pushButton12_clicked()//кнопка смайлика
{
    QString str=ui->lineEdit_message_2->text()+"\U0001F499";
    ui->lineEdit_message_2->setText(str);
    ui->lineEdit_message_2->setFocus();
}

void MainWindow::on_pushButton_settings_clicked()//кнопка меню настроек
{
    if(!fl_settings){
        ui->frame_2->show();
        fl_settings=true;
    }
    else {
        ui->frame_2->hide();
        fl_settings=false;
    }
}

void MainWindow::on_pushButton_save_clicked()//обработки кнопки сохранения
{
    if(station)//узнаём режим
    {
        if(!fl)
        {
            if(!fl_server)
            {
                if(ui->lineEdit_port->text()!=nullptr)
                {
                    if(ui->lineEdit_port->text().toInt()>0&&ui->lineEdit_port->text().toInt()<=65535)
                    {
                        if(ui->radioButton_server->isChecked()) ui->pushButton_work->setText("Создать");
                        ui->pushButton_work->setEnabled(true);
                        fl_settings=false;
                        text_port=ui->lineEdit_port->text();
                        text_adress=ui->lineEdit_adress->text();
                        text_name=ui->lineEdit_name->text();

                        ui->frame_2->hide();
                    }
                    else
                    {
                        QMessageBox::information(this,"Ошибка","Вы используете недопустимый порт!");
                    }
                }
                else
                {
                    QMessageBox::information(this,"Ошибка","Вы ввели не порт!");
                }
            }
            else
            {
                QMessageBox::information(this,"Внимание","Прервите предыдущий сервер для создания нового!");
            }
        }
        else
        {
            QMessageBox::information(this,"Ошибка","Отключитесь от сервера,прежде чем создавать свой!");
        }

    }
    else
    {
        if(!fl)
        {
            if(!fl_server)
            {
                if(ui->lineEdit_port->text()!=nullptr && ui->lineEdit_adress->text()!=nullptr && ui->lineEdit_name->text()!=nullptr)
                {
                    if(ui->radioButton_client->isChecked()) ui->pushButton_work->setText("Подключиться");
                    ui->pushButton_work->setEnabled(true);
                    fl_settings=false;
                    text_port=ui->lineEdit_port->text();
                    text_adress=ui->lineEdit_adress->text();
                    text_name=ui->lineEdit_name->text();
                    ui->frame_2->hide();
                }
                else
                {
                    QMessageBox::information(this,"Ошибка","Вы ввели не все данные");
                }
            }
            else
            {
                QMessageBox::information(this,"Внимание","Отключите свой сервер для подключения к чужому");
                station=true;
                ui->radioButton_server->click();
                ui->lineEdit_adress->clear();
            }
        }
        else
        {
            QMessageBox::information(this,"Ошибка","Отключитесь от предыдущего сервера,прежде чем подключаться к новому!");
        }

    }


}

void MainWindow::on_pushButton_close_clicked()//кнопка закрытия меню настроек
{
    ui->frame_2->hide();
    ui->lineEdit_port->setText(text_port);
    ui->lineEdit_adress->setText(text_adress);
    ui->lineEdit_name->setText(text_name);
    fl_settings=false;
}

void MainWindow::on_pushButton_clear_clicked()//кнопка очистки
{
    ui->textEdit_input_2->clear();

    if(fl_server) {ui->textEdit_input_2->append("<font color=#353535>------------------<b>Сервер запущен</b>------------------</font>");
        textCenter();}
}

void MainWindow::on_pushButton_theme_clicked()//кнопка для смены темы
{
    if(!fl_theme)//светлая тема
    {
        QFile style_file(":new/style.css");
        style_file.open(QFile::ReadOnly);

        auto style = QString::fromUtf8(style_file.readAll());

        ui->pushButton_work->setStyleSheet(style);
        ui->pushButton_spam->setStyleSheet(style);
        ui->pushButton_send_2->setStyleSheet(style);
        ui->pushButton_save->setStyleSheet(style);
        ui->pushButton_settings->setStyleSheet(style);
        ui->pushButton_clear->setStyleSheet(style);
        ui->pushButton_close->setStyleSheet(style);
        ui->pushButton_theme->setStyleSheet(style);
        ui->lineEdit_port->setStyleSheet(style);
        ui->pushButton->setStyleSheet(style);

        ui->lineEdit_adress->setStyleSheet(style);
        ui->lineEdit_message_2->setStyleSheet(style);
        ui->textEdit_input_2->setStyleSheet(style);
        ui->lineEdit_name->setStyleSheet(style);

        QFile style_Emoji(":new/styleeSmile.css");
        style_Emoji.open(QFile::ReadOnly);

        auto styleEmoji = QString::fromUtf8(style_Emoji.readAll());
        ui->pushButton->setStyleSheet(styleEmoji);

        QFile style_File(":new/styleFile.css");
        style_File.open(QFile::ReadOnly);

        auto styleFile = QString::fromUtf8(style_File.readAll());
        ui->pushButton_file->setStyleSheet(styleFile);

        ui->frame_2->setStyleSheet("color:white;\nbackground-color:#F7F6F6;\nborder-radius:10px;");

        ui->pushButton1->setStyleSheet("background-color:white;\nborder:1px solid blue;\nborder-radius:10px;");
        ui->pushButton2->setStyleSheet("background-color:white;\nborder:1px solid blue;\nborder-radius:10px;");
        ui->pushButton3->setStyleSheet("background-color:white;\nborder:1px solid blue;\nborder-radius:10px;");
        ui->pushButton4->setStyleSheet("background-color:white;\nborder:1px solid blue;\nborder-radius:10px;");
        ui->pushButton5->setStyleSheet("background-color:white;\nborder:1px solid blue;\nborder-radius:10px;");
        ui->pushButton6->setStyleSheet("background-color:white;\nborder:1px solid blue;\nborder-radius:10px;");
        ui->pushButton7->setStyleSheet("background-color:white;\nborder:1px solid blue;\nborder-radius:10px;");
        ui->pushButton8->setStyleSheet("background-color:white;\nborder:1px solid blue;\nborder-radius:10px;");
        ui->pushButton9->setStyleSheet("background-color:white;\nborder:1px solid blue;\nborder-radius:10px;");
        ui->pushButton10->setStyleSheet("background-color:white;\nborder:1px solid blue;\nborder-radius:10px;");
        ui->pushButton11->setStyleSheet("background-color:white;\nborder:1px solid blue;\nborder-radius:10px;");
        ui->pushButton12->setStyleSheet("background-color:white;\nborder:1px solid blue;\nborder-radius:10px;");

        ui->radioButton_client->setStyleSheet("color:black;");
        ui->radioButton_server->setStyleSheet("color:black;");


        ui->label->setStyleSheet("color:black;");
        ui->label_port->setStyleSheet("color:black;");
        ui->label_adress->setStyleSheet("color:black;");
        ui->label_our_adress->setStyleSheet("color:black;");
        ui->label_name->setStyleSheet("color:black;");
        ui->label_seans->setStyleSheet("color:blue;");

        qApp->setPalette(st);
        fl_theme=true;
    }
    else //тёмная тема
    {
        QFile style_dark(":new/style_dark.css");
        style_dark.open(QFile::ReadOnly);

        auto styleDark = QString::fromUtf8(style_dark.readAll());

        ui->pushButton_work->setStyleSheet(styleDark);
        ui->pushButton_spam->setStyleSheet(styleDark);
        ui->pushButton_send_2->setStyleSheet(styleDark);
        ui->pushButton_save->setStyleSheet(styleDark);
        ui->pushButton_settings->setStyleSheet(styleDark);
        ui->pushButton_clear->setStyleSheet(styleDark);
        ui->pushButton_close->setStyleSheet(styleDark);
        ui->pushButton_theme->setStyleSheet(styleDark);
        ui->lineEdit_port->setStyleSheet(styleDark);
        ui->lineEdit_name->setStyleSheet(styleDark);


        ui->lineEdit_adress->setStyleSheet(styleDark);
        ui->lineEdit_message_2->setStyleSheet(styleDark);
        ui->textEdit_input_2->setStyleSheet(styleDark);

        ui->label_seans->setStyleSheet("color:#d60096;");
        ui->label->setStyleSheet("color:white;");
        ui->label_port->setStyleSheet("color:white;");
        ui->label_adress->setStyleSheet("color:white;");
        ui->label_our_adress->setStyleSheet("color:white;");
        ui->label_name->setStyleSheet("color:white;");

        ui->frame_2->setStyleSheet("color:white;\nbackground-color:rgb(53, 53, 53);\nborder-radius:10px;");

        QFile style_Emoji(":new/styleSmile_dark.css");
        style_Emoji.open(QFile::ReadOnly);

        auto styleEmoji = QString::fromUtf8(style_Emoji.readAll());
        ui->pushButton->setStyleSheet(styleEmoji);

        QFile style_file(":new/styleFile_dark.css");
        style_file.open(QFile::ReadOnly);

        auto styleFile = QString::fromUtf8(style_file.readAll());
        ui->pushButton_file->setStyleSheet(styleFile);

        QPalette darkPalette;

        // Настраиваем палитру для цветовых ролей элементов интерфейса
        darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
        darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
        darkPalette.setColor(QPalette::ToolTipText, Qt::white);
        darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::BrightText, Qt::red);
        darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
        darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
        darkPalette.setColor(QPalette::HighlightedText, Qt::black);


        ui->pushButton1->setStyleSheet("background-color:white;\nborder:1px solid rgb(214, 0, 150);\nborder-radius:10px;");
        ui->pushButton2->setStyleSheet("background-color:white;\nborder:1px solid rgb(214, 0, 150);\nborder-radius:10px;");
        ui->pushButton3->setStyleSheet("background-color:white;\nborder:1px solid rgb(214, 0, 150);\nborder-radius:10px;");
        ui->pushButton4->setStyleSheet("background-color:white;\nborder:1px solid rgb(214, 0, 150);\nborder-radius:10px;");
        ui->pushButton5->setStyleSheet("background-color:white;\nborder:1px solid rgb(214, 0, 150);\nborder-radius:10px;");
        ui->pushButton6->setStyleSheet("background-color:white;\nborder:1px solid rgb(214, 0, 150);\nborder-radius:10px;");
        ui->pushButton7->setStyleSheet("background-color:white;\nborder:1px solid rgb(214, 0, 150);\nborder-radius:10px;");
        ui->pushButton8->setStyleSheet("background-color:white;\nborder:1px solid rgb(214, 0, 150);\nborder-radius:10px;");
        ui->pushButton9->setStyleSheet("background-color:white;\nborder:1px solid rgb(214, 0, 150);\nborder-radius:10px;");
        ui->pushButton10->setStyleSheet("background-color:white;\nborder:1px solid rgb(214, 0, 150);\nborder-radius:10px;");
        ui->pushButton11->setStyleSheet("background-color:white;\nborder:1px solid rgb(214, 0, 150);\nborder-radius:10px;");
        ui->pushButton12->setStyleSheet("background-color:white;\nborder:1px solid rgb(214, 0, 150);\nborder-radius:10px;");

        ui->radioButton_client->setStyleSheet("color:white;");
        ui->radioButton_server->setStyleSheet("color:white;");

        qApp->setPalette(darkPalette);
        fl_theme=false;
    }
}

void MainWindow::on_pushButton_spam_clicked()//обработка кнопки спама
{
    if(!fl_talk)//включение
    {
        timer->start(10);//стартуем таймер
        fl_talk=true;
        ui->pushButton_spam->setText("Отключить спам");
    }
    else //выключение
    {
        timer->stop();//останавливаем
        counter=0;
        fl_talk=false;
        ui->pushButton_spam->setText("Включить спам");

    }
}

void MainWindow::on_timer()//обработка таймера
{
    counter++;//увеличиваем счетчик

    if(counter%100==0)
    {

        if(!station)//если мы клиент
        {
            auto r=rand()%4;
            TCP_SOCKET->write("["+ui->lineEdit_name->text().toUtf8()+"]"+random[r].toUtf8());
            auto Time=QTime::currentTime().toString("HH:mm");
            ui->textEdit_input_2->append("<font color=#235AF0>"+ random[r] + " "+"</font>" + "<font size=1>"+Time+"</font>");
            textLeft();
        }
        else//если сервер
        {
            auto r=rand()%4;
            MessageToAllClients("Сервер: "+random[r],5000);
            auto Time=QTime::currentTime().toString("HH:mm");
            ui->textEdit_input_2->append("<font color=#d60096>"+ random[r] + " "+"</font>" + "<font size=1>"+Time+"</font>");
            textLeft();
        }

    }
}

void MainWindow::on_pushButton_file_clicked()
{

    QString filePath = QFileDialog::getOpenFileName(this, "Выберите документ", "../");

    if(!filePath.isEmpty())
    {


    }
    else
    {
        ui->textEdit_input_2->append("Неправильный выбор пути к файлу");
        textCenter();
    }
}


