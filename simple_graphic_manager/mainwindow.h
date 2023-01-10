#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pixel.h"
#include "line.h"
#include "rect.h"
#include "circle.h"
#include "ellipse.h"
#include <QPainter>
#include <QColorDialog>
#include <QMessageBox>
#include "dialog.h"
#include "polygon.h"
#include "arc.h"
#include "polyline.h"
#include <QDebug>
#include "geo.h"
#include "dialog_geo.h"
#include <QLabel>


namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
        polygon pol;
        polyline pl_new;


public slots:
    void ImportTochka(std::vector<tochka> mas);//слот импорта вектора точек многоугольника
    void ImportTochkaPl(std::vector<tochka> mas);//слот импорта вектора точек ломанной линии

private slots:

    void on_pushButton_clear_clicked();

    void on_pushButton_draw_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_horizontalSlider_penW_valueChanged(int value);

    void on_pushButton_clicked();

    void on_comboBox_pen_currentIndexChanged(int);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
