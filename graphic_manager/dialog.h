#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "my_pen.h"
#include "QColorDialog"

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog, public my_pen
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void setStyleVisible(bool fl);
    void setValue(my_pen n_pen);//установка карандаша
    QColor color;

private slots:
    void on_buttonBox_accepted();

    void on_horizontalSlider_valueChanged(int value);

    void on_pushbutton_color_clicked();

private:
    Ui::Dialog *ui;
    bool styleVisible;
};

#endif // DIALOG_H
