#ifndef M_WIDGET_H
#define M_WIDGET_H

#include <QWidget>
#include <QPainter>

class m_widget : public QWidget
{
    Q_OBJECT
public:
    explicit m_widget(QWidget *parent = nullptr);
    QImage im;
    void create_im(int size_x,int size_y);//создание картинки

private:
    bool im_created;

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *);
};

#endif // M_WIDGET_H
