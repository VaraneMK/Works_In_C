#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

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

    void on_pushButton_drawIm_clicked();

    void on_pushButton_3_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_day_clicked();

    void on_pushButton_night_clicked();

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::MainWindow *ui;
    bool fl_draw;
    int value;
    bool setDay;
};

#endif // MAINWINDOW_H
