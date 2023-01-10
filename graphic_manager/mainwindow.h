#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include "dialog.h"
#include "dialog_points.h"
#include <QFile>
#include <QMessageBox>
#include <QVector>
#include "dialog_brush.h"
#include "primitive.h"
#include <vector>
#include "ellipse.h"
#include "polygon.h"

#include "polyline.h"
#include "m_widget.h"


#include "QFileDialog"
#define KOL_COL 8
#define FILE_NAME "save.dat"

namespace Ui {
    class MainWindow;
}




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
   // QVector<T_OBJ_DATA> obj_data;
    bool no_auto_change;

    void drawAll();
    int status=0;

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_pushButtonSave_clicked();

    void on_pushButtonLoad_clicked();

    void on_tableWidget_cellChanged(int row, int column);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<Primitive*> primitives;
    std::vector<tochka>* MainPoints=nullptr;//ломанная
    std::vector<tochka>* MainPointsPl=nullptr;//многоугольник




protected slots:
    void Combo_click(int arg1);
    void color_click(void);
    void color_click_br(void);
    void points_click(void);
};

#endif // MAINWINDOW_H
