#ifndef MY_WIDGET_H
#define MY_WIDGET_H

#include <QWidget>
#include <QPainter>

class My_widget : public QWidget
{
    Q_OBJECT
public:
    explicit My_widget(QWidget *parent = nullptr);
    QImage im;

signals:

public slots:
    void paintEvent(QPaintEvent *);
};

#endif // MY_WIDGET_H
