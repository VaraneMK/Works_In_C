#ifndef DIALOG_GEO_H
#define DIALOG_GEO_H

#include <QDialog>
#include "pixel.h"
#include "tochka.h"
#include <QPainter>
#include <QColorDialog>
#include <QMessageBox>
#include "polygon.h"
#include "geo.h"
#include <QPainterPath>
#include <QDebug>


namespace Ui {
class Dialog_geo;
}

class Dialog_geo : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_geo(QWidget *parent = nullptr);
    ~Dialog_geo();
    void arrayForSending();

signals:
    void ExportTochkaGeog(std::vector<tochka> mas);//сигнал экспорта вектора точек

public slots:
    void on_pushButton_add_clicked();

private slots:

    void on_spinBox_valueChanged(int arg1);

    void on_tableWidget_cellChanged(int row, int column);

    void on_pushButton_clicked();

    void on_tableWidget_2_cellChanged(int row, int column);

private:
    Ui::Dialog_geo *ui;
};

#endif // DIALOG_GEO_H
