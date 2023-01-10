#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define MAX_MAS 200

#include <QMainWindow>
#include <QMessageBox>//библиотека с окошками сообщений

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
    void on_pushButton_rand_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_tableWidget_cellChanged(int row, int column);

    void on_pushButton_max_clicked();

    void on_pushButton_min_clicked();

    void on_pushButton_sz_clicked();

    void on_pushButton_puz_clicked();

    void on_pushButton_gnom_clicked();

    void on_pushButton_fast_clicked();

    void on_pushButton_comb_clicked();

    void on_pushButton_monkey_clicked();

    void on_pushButton_duble_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_const_clicked();

private:
    Ui::MainWindow *ui;
    bool no_auto_change;
    void quick(int *, int);
    bool sort(int *, int );
    void shuffle(int *, int );
    void monkey(int *, int );
};

#endif // MAINWINDOW_H
