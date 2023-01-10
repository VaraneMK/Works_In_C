#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog> //библиотека с диалоговыми окнами для работы с файлами
#include <QMessageBox>
//#include <QTextDecoder> // для поддержки русского языка
#include <QCloseEvent>//событие закрытия окна

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Menu_Opem_triggered();

    void on_Menu_SaveAs_triggered();

    void closeEvent(QCloseEvent *event);//будем изменять обработчик закрытия формы

    void on_Menu_Create_triggered();

    void on_Menu_Save_triggered();

    void on_Menu_Exit_triggered();

    void on_textEdit_textChanged();

private:
    Ui::MainWindow *ui;
    QString WindowName="Блокнот"; //универсальная переменная для хранения адреса последнего используещегося файла
    QString filter="Text files (*.txt)"; // фильр разрешенных типов файла
    QString defaultDirectory="Z\\Files";//стандартная директория
    //QString createDirectore ="Z:\\Files\\Unnamed.txt";

    bool textchanged=false; // переменная,обозначающая изменялся ли текст или нет
    bool openfile=false;
    //QTextCodec *codec= QTextCodec::codecForName("Windows-1251");
   // QTextDecoder *decoder;
    void FuncOpen(QString &fileName);

    bool Status=false;//сигнал об изменение текста


    bool fl=false;//переменная,обозначающая успешность выполнения
};

#endif // MAINWINDOW_H
