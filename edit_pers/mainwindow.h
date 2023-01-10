#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>//библиотека с окошками сообщений
#include <ctime>
#include <QPixmap>//бибилиотека для отображения изображения

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void func_class(void);

private slots:
    void on_pushButton_Clear_clicked();

    void on_pushButton_Create_clicked();

    void on_pushButton_random_clicked();

private:
    Ui::MainWindow *ui;
    int points;//Для максимума очков

    int str,dex,intel,luck;
    QString male_human[15]={"Артас","Болевар","Себастьян","Патинас","Уилшугар","Андрок","Вальдроелл","Пирсини","Арбиникт","Дайдиас","Франклидон","Марденмат","Ланглаам","Вариан","Андуин"};//Массив с мужскими именами для людей
    QString female_human[15]={"Ирона","Каррилет","Далсалия","Каджерни","Венбекка","Вейн","Сона","Джаэна","Джайна","Филримина","Люкс","Андингхэйл","Катарина","Элизабет","Алисия"};//Массив с женскими именами для людей
    QString male_elf[15]={"Фейнедрон","Шейрамир","Деренсин","Тайдоэль","Киндревир","Синренрас","Джанфиндас","Гарверрий","Фонариун","Гарлонрос","Тесджадрелл","Бренмидрелл","Ардреал","Лидонис","Рейкан"};//Массив с мужскими именами для эльфов
    QString female_elf[15]={"Фадайас","Цинленльда","Шейваншия","Мауя","Грасинея","Бьянтана","Кинедисс","Айльдриат","Кисанриэль","Валаси","Фрейсанлисса","Джетарльда","Тивалисса","Ирканаль","Шая"};//Массив с женскими именами для эльфов
    QString male_orc[15]={"Каррилод","Вазегру","Кракморнер","Рунрлод","Боригар","Альренкус","Регбеги","Одтадир","Дартергат","Гонгроветт","Гарош","Тудлилий","Мундо","Тралл","Громмаш"};//Массив с мужскими именами для орков
    QString female_orc[15]={"Ланрилса","Кайанта","Нависа","Лугнеша","Мурая","Чинтими","Актоша","Джайриша","Гагадина","Моккиха","Саргулда","Дунея","Грешгача","Мутанида","Шомаса"};//Массив с женскими именами для орков
    QString male_goblin[15]={"Смукратель","Пивитов","Нозпруфикс","Фенкраджок","Комбкусно","Зажегон","Маквевид","Одтадир","Пилилюк","Бедлотель","Златовзрыв","Залтюс","Грязелам","Агхаликс","Грекрегон"};//Массив с мужскими именами для гоблинов
    QString female_goblin[15]={"Лайбирикс","Кабана","Марбази","Зелварзи","Лайрази","Грираникс","Микзлани","Хамбарезли","Скобидак","Кусворзо","Зелбизи","Пенвартель","Хамзлата","Миктоза","Марворни"};//Массив с женскими именами для гоблинов

};
#endif // MAINWINDOW_H