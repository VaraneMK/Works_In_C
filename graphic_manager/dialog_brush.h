#ifndef DIALOG_BRUSH_H
#define DIALOG_BRUSH_H

#include <QDialog>
#include "my_pen.h"
#include "my_brush.h"
#include "QColorDialog"

namespace Ui {
class Dialog_brush;
}

class Dialog_brush : public QDialog, public my_pen
{
    Q_OBJECT

public:
    explicit Dialog_brush(QWidget *parent = nullptr);
    ~Dialog_brush();

    void setValue(my_brush n_pen);//установка кисти
    QColor color;

private slots:

    void on_pushButton_ok_clicked();

    void on_pushButton_clicked();

    void on_pushbutton_cancel_clicked();

private:
    Ui::Dialog_brush *ui;
};

#endif // DIALOG_BRUSH_H
