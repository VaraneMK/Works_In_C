#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //========Открываем файл со стилями и передаем виджетам==============
    QFile style_file(":new/style.css");
    style_file.open(QFile::ReadOnly);

    auto style = QString::fromUtf8(style_file.readAll());
    ui->textEdit_input->setReadOnly(true);
    //    ui->textEdit_output->setReadOnly(true);

    ui->pushButton_create->setStyleSheet(style);
    ui->pushButton_send->setStyleSheet(style);

    ui->lineEdit_port->setPlaceholderText("Введите порт получателя");
    ui->lineEdit_port->setStyleSheet(style);

    ui->lineEdit_adress->setStyleSheet(style);
    ui->lineEdit_adress->setPlaceholderText("Введите адрес получателя");

    ui->lineEdit_message->setStyleSheet(style);
    ui->lineEdit_message->setPlaceholderText("Напишите сообщение...");

    ui->lineEdit_our_port->setStyleSheet(style);
    ui->lineEdit_our_port->setPlaceholderText("Введите ваш порт");
    ui->textEdit_input->setStyleSheet(style);

    //=========================================================================

    //==================Выводим наш IP-адрес============================================
    auto adr=QNetworkInterface::allAddresses();
    ui->label_our_adress->setText("Наш IP-адрес: <b>"+adr[2].toString()+"</b>");

    //==================================================================================


    //==================Задаем шрифт для корректного отображения смайликов============================================
    QFontDatabase fontDB;
    fontDB.addApplicationFont(":/A Font Supporting Emoji.ttf");
    qApp->setFont(QFont(QStringLiteral("A Font Supporting Emoji")));
    //==================================================================================
    ui->lineEdit_message->setClearButtonEnabled(true);


    //==================Задаем иконку===========================================
    QIcon message(":new/send_121758(1).ico");
    ui->lineEdit_message->addAction(message, QLineEdit::LeadingPosition);
    //    ui->lineEdit_message->addAction(emoji, QLineEdit::TrailingPosition);
    //==================================================================================

    //==================Задаем иконку для окна с эмодзи===========================================
    QIcon emoji(":new/bubblesmiley_102154.ico");
    ui->tabWidget->setCurrentIndex(0);
    ui->pushButton->setIcon(emoji);
    //==================================================================================
    QFile style_Emoji(":new/styleeSmile.css");
    style_Emoji.open(QFile::ReadOnly);

    auto styleEmoji = QString::fromUtf8(style_Emoji.readAll());
    ui->pushButton->setStyleSheet(styleEmoji);


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

    connect(ui->lineEdit_message, &QLineEdit::returnPressed, this, &MainWindow::on_pushButton_send_clicked);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_create_clicked()
{
    bool fl1;
    port=ui->lineEdit_port->text().toInt(&fl1);//проверка на корректность данных
    if(fl1)
    {
//        int ip;
//        ip=ui->lineEdit_our_port->text().toInt(fl1);//проверка на корректность данных
        if(ui->lineEdit_our_port->text()!=nullptr)
        {
            our_port=ui->lineEdit_our_port->text().toInt(&fl1);//проверка на корректность данных
            if(fl1)
            {

                ui->label_seans->setText("Сеанс с: IP: <font color=#b300b3>"+QString(ui->lineEdit_adress->text())+"</font>;PORT: <font color=#b300b3>"+QString(ui->lineEdit_port->text().toUtf8())+"</font>.");
                udpsocket= new QUdpSocket(this);
                udpsocket->bind(QHostAddress::Any,quint16(our_port));
                connect(udpsocket,&QUdpSocket::readyRead,this,&MainWindow::read_data);
                adress= new QHostAddress;
                adress->setAddress(ui->lineEdit_adress->text());
                fl=true;
                ui->tabWidget->setCurrentIndex(1);
            }
            else
            {
                QMessageBox::information(this,"Предупреждение","Значение порта не корректно!",QMessageBox::Ok);//сообщение об ошибке
            }
        }
        else
        {
            QMessageBox::information(this,"Предупреждение","Значение IP-адреса не корректно!",QMessageBox::Ok);//сообщение об ошибке
        }
    }
    else
    {
        QMessageBox::information(this,"Предупреждение","Значение порта получателя не корректно!",QMessageBox::Ok);//сообщение об ошибке
    }
}


void MainWindow::read_data()//чтение сообщения
{
    char *date;
    int size;
    size=int(udpsocket->pendingDatagramSize());
    if(size>0)
    {
        date=new char[size+1];
        udpsocket->readDatagram(date,size);
        date[size]=0;//завершающий 0 - признак конца
        QString str;
        str=QString::fromUtf8(date,size);
        //        ui->textEdit_input->append("Cобеседник: <font color=#b300b3>" + str +"</font>" + " (ip:"+QString(ui->lineEdit_adress->text())+";port:"+QString(ui->lineEdit_port->text().toUtf8())+")");

        auto Time=QTime::currentTime().toString("HH:mm");//узнаём время получения сообщения
        ui->textEdit_input->append("<font color=#b300b3>" + str +"</font>"+" "+ "<font size=1>"+Time+"</font>");//выводим полученное сообщение

        //========================Делаем отображние сообщения с правой стороны QTextEdit===================================================
        QTextCursor newCursor = ui->textEdit_input->textCursor();
        newCursor.movePosition(QTextCursor::End);
        ui->textEdit_input->setTextCursor(newCursor);
        QTextBlockFormat textBlockFormat = newCursor.blockFormat();
        textBlockFormat.setAlignment(Qt::AlignRight);
        newCursor.mergeBlockFormat(textBlockFormat);
        ui->textEdit_input->setTextCursor(newCursor);



        delete []date;
    }

    //    QHostAddress sender;
    //    quint16 senderPort;

    //    while(udpsocket->hasPendingDatagrams())
    //    {
    //        QByteArray datagram;
    //        datagram.resize(udpsocket->pendingDatagramSize()); // узнаём размер сообщения
    //        udpsocket->readDatagram(datagram.data(),datagram.size(),&sender,&senderPort);//считываем данные
    //        ui->textEdit_input->append("<font color=red" + QString(datagram)+"</font>");
    //    }
}
void MainWindow::on_pushButton_send_clicked()
{
    if(fl)
    {
        //        char *date;
        //        int size;
        //        size=ui->lineEdit_message->text().length();
        //        QByteArray ba=ui->lineEdit_message->text().toUtf8();
        //        date=ba.data();
        //        udpsocket->writeDatagram(date,size,*adress,quint16(port));
        //        ui->textEdit_output->append(ui->lineEdit_message->text());
        //        ui->textEdit_input->append("Вы: <font color=#235AF0>"+ ui->lineEdit_message->text() + "</font>");

        auto x=ui->lineEdit_message->text();
        if(x!=nullptr)
        {

            auto Time=QTime::currentTime().toString("HH:mm");
            udpsocket->writeDatagram(ui->lineEdit_message->text().toUtf8(),*adress,quint16(port));
            ui->textEdit_input->append("<font color=#235AF0>"+ ui->lineEdit_message->text() + " "+"</font>" + "<font size=1>"+Time+"</font>");
            QTextCursor newCursor = ui->textEdit_input->textCursor();
            newCursor.movePosition(QTextCursor::End);
            ui->textEdit_input->setTextCursor(newCursor);
            QTextBlockFormat textBlockFormat = newCursor.blockFormat();
            textBlockFormat.setAlignment(Qt::AlignLeft);
            newCursor.mergeBlockFormat(textBlockFormat);
            ui->textEdit_input->setTextCursor(newCursor);
            ui->lineEdit_message->clear();
        }
    }
    else
    {
        QMessageBox::information(this,"Предупреждение","Вы не создали соединение!",QMessageBox::Ok);
    }

}

void MainWindow::on_pushButton_clicked()
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


void MainWindow::on_pushButton1_clicked()
{
    QString str=ui->lineEdit_message->text()+"\U0001F600";
    ui->lineEdit_message->setText(str);
    ui->lineEdit_message->setFocus();
}

void MainWindow::on_pushButton2_clicked()
{
    QString str=ui->lineEdit_message->text()+"\U0001F601";
    ui->lineEdit_message->setText(str);
    ui->lineEdit_message->setFocus();
}

void MainWindow::on_pushButton3_clicked()
{
    QString str=ui->lineEdit_message->text()+"\U0001F602";
    ui->lineEdit_message->setText(str);
    ui->lineEdit_message->setFocus();
}

void MainWindow::on_pushButton4_clicked()
{
    QString str=ui->lineEdit_message->text()+"\U0001F603";
    ui->lineEdit_message->setText(str);
    ui->lineEdit_message->setFocus();
}

void MainWindow::on_pushButton5_clicked()
{
    QString str=ui->lineEdit_message->text()+"\U0001F604";
    ui->lineEdit_message->setText(str);
    ui->lineEdit_message->setFocus();
}

void MainWindow::on_pushButton6_clicked()
{
    QString str=ui->lineEdit_message->text()+"\U0001F605";
    ui->lineEdit_message->setText(str);
    ui->lineEdit_message->setFocus();
}

void MainWindow::on_pushButton7_clicked()
{
    QString str=ui->lineEdit_message->text()+"\U0001F606";
    ui->lineEdit_message->setText(str);
    ui->lineEdit_message->setFocus();
}

void MainWindow::on_pushButton8_clicked()
{
    QString str=ui->lineEdit_message->text()+"\U0001F607";
    ui->lineEdit_message->setText(str);
    ui->lineEdit_message->setFocus();
}

void MainWindow::on_pushButton9_clicked()
{
    QString str=ui->lineEdit_message->text()+"\U0001F608";
    ui->lineEdit_message->setText(str);
    ui->lineEdit_message->setFocus();
}

void MainWindow::on_pushButton10_clicked()
{
    QString str=ui->lineEdit_message->text()+"\U0001F62D";
    ui->lineEdit_message->setText(str);
    ui->lineEdit_message->setFocus();
}

void MainWindow::on_pushButton11_clicked()
{
    QString str=ui->lineEdit_message->text()+"\U0001F60D";
    ui->lineEdit_message->setText(str);
    ui->lineEdit_message->setFocus();
}

void MainWindow::on_pushButton12_clicked()
{
    QString str=ui->lineEdit_message->text()+"\U0001F499";
    ui->lineEdit_message->setText(str);
    ui->lineEdit_message->setFocus();
}

