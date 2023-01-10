#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "pixel.h"
#include "tochka.h"
#include <QPainter>
#include <QColorDialog>
#include <QMessageBox>
#include "polygon.h"
#include <QPainterPath>
#include <QDebug>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    friend polygon;

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void arrayForSending();

signals:
    void ExportTochka(std::vector<tochka> mas);//сигнал экспорта вектора точек

public slots:
    void on_pushButton_add_clicked();

private slots:

    void on_spinBox_valueChanged(int arg1);

    void on_tableWidget_cellChanged(int row, int column);

    void on_pushButton_clicked();



private:
    Ui::Dialog *ui;

};

#endif // DIALOG_H
