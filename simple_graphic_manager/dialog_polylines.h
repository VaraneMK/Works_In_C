#ifndef DIALOG_POLYLINES_H
#define DIALOG_POLYLINES_H

#include <QDialog>
#include "pixel.h"
#include "tochka.h"
#include <QPainter>
#include <QColorDialog>
#include <QMessageBox>
#include "polygon.h"
#include <QPainterPath>
#include <QDebug>

namespace Ui {
class Dialog_polylines;
}

class Dialog_polylines : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_polylines(QWidget *parent = nullptr);
    ~Dialog_polylines();
    void arrayForSending();

signals:
    void ExportTochkaPl(std::vector<tochka> mas);//сигнал экспорта вектора точек

public slots:
    void on_pushButton_add_clicked();

private slots:

    void on_spinBox_valueChanged(int arg1);

    void on_tableWidget_cellChanged(int row, int column);

    void on_pushButton_clicked();

private:
    Ui::Dialog_polylines *ui;
};

#endif // DIALOG_POLYLINES_H
