#ifndef DIALOG_POINTS_H
#define DIALOG_POINTS_H

#include <QDialog>
#include "tochka.h"

namespace Ui {
    class Dialog_points;
}

class Dialog_points : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_points(QWidget *parent = 0);
    ~Dialog_points();
    void OpenD(std::vector<tochka> * Points);

private slots:
    void on_spinBox_valueChanged(int arg1);



    void on_pushButton_Cancel_clicked();

    void on_pushButton_OK_clicked();

    void on_tableWidget_cellChanged(int row, int column);

private:
    Ui::Dialog_points *ui;
    bool is_ok;
    int count;
    std::vector<tochka>* MainPoints=nullptr;
};

#endif // DIALOG_POINTS_H
