#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QTimer>
#include <QMessageBox>
#include <QMovie>
#include <QRadioButton>

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
    void pb_click();

    void on_pushButton_start_clicked();

    void on_radioButton1_2_clicked();

    void on_radioButton1_1_clicked();

    void on_radioButton1_3_clicked();

    void on_radioButton1_4_clicked();

    void on_radioButton2_1_clicked();

    void on_radioButton2_2_clicked();

    void on_radioButton2_3_clicked();

    void on_radioButton2_4_clicked();

    void on_radioButton3_1_clicked();

    void on_radioButton3_2_clicked();

    void on_radioButton3_3_clicked();

    void on_radioButton3_4_clicked();

    void on_radioButton4_1_clicked();

    void on_radioButton4_2_clicked();

    void on_radioButton4_3_clicked();

    void on_radioButton4_4_clicked();

    void on_radioButton5_1_clicked();

    void on_radioButton5_2_clicked();

    void on_radioButton5_3_clicked();

    void on_radioButton5_4_clicked();

    void on_pushButton_clicked();

    void on_timer(void); //слот обработки события таймера

    void on_downtimer(void);

    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_4_clicked();

    void on_commandLinkButton_5_clicked();

    void on_pushButton_again_clicked();

    void on_pushButton_exit_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<int> trAnswer={3,4,1,2,2};//правильные ответы
    std::vector<int> stAnswer={0,0,0,0,0};//вектор для хранения ответов пользователя
    int answer=0;//счетчик правильных ответов
    QMovie mo;//для отображения гиф файлов
    QTimer * timer;//указатель на класс Таймер

    int counter; //счетчик

    QTimer * downtimer;//указатель на класс Таймер
    int downcounter; //счетчик
};

#endif // MAINWINDOW_H
