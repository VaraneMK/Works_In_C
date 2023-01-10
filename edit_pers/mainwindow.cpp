#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)//начало программы
{
    ui->setupUi(this);
    ui->pushButton_Clear->click();//вызов очистки
    ui->lineEdit_Points->setReadOnly(true);//блокируем изменение(режим только для чтения)
    ui->label_info->hide();
    QPixmap orda(":/resource/img/pngegg.png");//изображение фракции-Орда
    QPixmap alliance(":/resource/img/pngegg (1).png");//изображение фракции-Альянс
    int w=ui->label_image->width();//переменная для хранения ширины
    int h=ui->label_image->height();//переменная для хранения высоты
    ui->label_image->setPixmap(orda.scaled(w, h, Qt::KeepAspectRatio));
    ui->label_image->hide();
    ui->label_image_2->setPixmap(alliance.scaled(w, h, Qt::KeepAspectRatio));
    ui->label_image_2->hide();
}



MainWindow::~MainWindow()//Деструктор
{
    delete ui;
}


void MainWindow::func_class()//классовая система
{
    int hp,mp,atk,def;
    hp=8*str+2*dex;//рассчитывание здоровья
    mp=8*intel+dex+luck;//рассчитывание маны
    atk=6*str+2*dex+2*luck;//рассчитывание атаки
    def=7*dex+3*luck;//рассчитывание защиты

    if ((str>=7)&&(luck>=7)) //классовая система №1-Монах
    {
        ui->label_Class_Value->setText("Монах");
        ui->label_info->setText("Вне зависимости от предпочитаемого стиля монахи в бою полагаются\nв основном на свои кулаки и ноги.Его безоружные атаки\nочень быстры и опасны.");
        ui->label_info->show();
    }
    else if (((str>3)&&(intel>=4)&&((dex>=5)&&(dex<15))&&(luck>3))||((dex>10)&&(intel>3)))//классовая система №2-Паладин
    {
        ui->label_Class_Value->setText("Паладин");
        ui->label_info->setText("Паладины бьются с врагом лицом к лицу,полагаясь на тяжелые доспехи\nи навыки целительства.Прочный щит или двуручное оружие — не столь\nважно, чем владеет паладин.Он сумеет не только защитить соратников\nот вражеских когтей и клинков,но и удержит группу на ногах при помощи\nисцеляющих заклинаний.");
        ui->label_info->show();
    }
    else if (((str>=7)&&((dex>=4)||(luck>4)))||(str>=10)) //классовая система №3-Воин
    {
        ui->label_Class_Value->setText("Воин");
        ui->label_info->setText("Воины тщательно готовятся к бою,а с противником сражаются лицом к\nлицу, принимая все удары на свои доспехи.Они пользуются различными\nбоевыми тактиками и применяют разнообразное оружие,чтобы\nзащитить своих более хрупких союзников.Для максимальной\nэффективности воины должны контролировать свою ярость — ту силу,\nчто питает их наиболее опасные атаки.");
        ui->label_info->show();
    }
    else if(((str>=4)&&(str<=6))&&((dex>=4)&&(dex<=6))&&((intel>=4)&&(intel<=6))&&((luck>=4)&&(luck<=6)))//классовая система №4-Друид
    {
        ui->label_Class_Value->setText("Друид");
        ui->label_info->setText("Друиды могут подходить к сражению совершенно по-разному.\nОни вольны играть почти любую роль в команде: быть целителями, танками или бойцами,\nно должны помнить об особенностях каждой роли.\nДруид вынужден внимательно подбирать облик к ситуации,\nтак как каждый из них служит определенной цели.");
        ui->label_info->show();
    }
    else if ((((str>=4)&&(str<=9))&&(intel>=6))||(intel>10))//классовая система №5-Маг
    {
        ui->label_Class_Value->setText("Маг");
        ui->label_info->setText("Маги уничтожают врагов тайными заклинаниями. Несмотря на\nмагическую силу, маги хрупки, не носят тяжелых доспехов, поэтому\nуязвимы в ближнем бою. Умные маги при помощи заклинаний\nудерживают врага на расстоянии или вовсе обездвиживают его.");
        ui->label_info->show();
    }
    else if (((dex>=7)&&((luck>=2)&&(luck<7))&&(str>=2))||(luck>10))//классовая система №6-Охотник
    {
        if(ui->radioButton_Sex_M->isChecked())
        {
            ui->label_Class_Value->setText("Охотник");
            ui->label_info->setText("Охотники бьют врага на расстоянии или в ближнем бою, приказывая\nпитомцам атаковать, пока сами натягивают тетиву, заряжают ружье или\nразят древковым оружием. Их оружие действенно и вблизи, и издалека.\nКроме того, охотники очень подвижны. Они могут уклониться от атаки\nили задержать противника, контролируя поле боя.");
            ui->label_info->show();
        }
        else
        {
            ui->label_Class_Value->setText("Охотница");
            ui->label_info->setText("Охотники бьют врага на расстоянии или в ближнем бою, приказывая\nпитомцам атаковать, пока сами натягивают тетиву, заряжают ружье или\nразят древковым оружием. Их оружие действенно и вблизи, и издалека.\nКроме того, охотники очень подвижны. Они могут уклониться от атаки\nили задержать противника, контролируя поле боя.");
            ui->label_info->show();
        }
    }
    else if ((dex>=3)&&(luck>6))//классовая система №7-Разбойник
    {
        if(ui->radioButton_Sex_M->isChecked())
        {
            ui->label_Class_Value->setText("Разбойник");
            ui->label_info->setText("Разбойники часто нападают из теней,начиная бой комбинацией\nсвирепых ударов.В затяжном бою они изматывают врага тщательно\nпродуманной серией атак,прежде чем нанести решающий удар.\nРазбойнику следует внимательно отнестись к выбору противника,чтобы\nоптимально использовать тактику, и не упустить момент,когда надо\nспрятаться или бежать, если ситуация складывается не в их пользу.");
            ui->label_info->show();
        }
        else
        {
            ui->label_Class_Value->setText("Разбойница");
            ui->label_info->setText("Разбойники часто нападают из теней,начиная бой комбинацией\nсвирепых ударов.В затяжном бою они изматывают врага тщательно\nпродуманной серией атак,прежде чем нанести решающий удар.\nРазбойнику следует внимательно отнестись к выбору противника,чтобы\nоптимально использовать тактику, и не упустить момент,когда надо\nспрятаться или бежать, если ситуация складывается не в их пользу.");
            ui->label_info->show();
        }
    }
    else if(((dex>=5)&&(intel>=5))||((intel>=5)&&(luck>=4)))//классовая система №8-Жрец
    {
        if(ui->radioButton_Sex_M->isChecked())
        {
            ui->label_Class_Value->setText("Жрец");
            ui->label_info->setText("Жрецы могут задействовать мощную целительную магию, чтобы спасти\nсебя и своих спутников. Им подвластны и сильные атакующие заклинания,\nно физическая слабость заставляет жрецов бояться сближения с противником.");
            ui->label_info->show();
        }
        else
        {
            ui->label_Class_Value->setText("Жрица");
            ui->label_info->setText("Жрецы могут задействовать мощную целительную магию, чтобы спасти\nсебя и своих спутников. Им подвластны и сильные атакующие заклинания,\nно физическая слабость заставляет жрецов бояться сближения с противником.");
            ui->label_info->show();
        }
    }
    else
    {
        ui->label_Class_Value->setText("Мистик");
        ui->label_info->setText("Ваш класс не предсказуем.Он может обладать\nабсолютно разными силами и качествами.");
        ui->label_info->show();
    }



    ui->label_HP_Value->setNum(hp);
    ui->label_MP_Value->setNum(mp);
    ui->label_Atk_value->setNum(atk);
    ui->label_Def_Value->setNum(def);

}




void MainWindow::on_pushButton_Clear_clicked()
{
    ui->label_HP_Value->clear();
    ui->label_MP_Value->clear();
    ui->label_Atk_value->clear();
    ui->label_Def_Value->clear();
    ui->label_Class_Value->clear();
    ui->label_info->clear();
    ui->lineEdit_Name->clear();
    ui->lineEdit_Dex->clear();
    ui->lineEdit_Int->clear();
    ui->lineEdit_Str->clear();
    ui->lineEdit_Luck->clear();
    ui->label_image->hide();
    ui->label_image_2->hide();
    if(ui->radioButton_Sex_M->isChecked())
    {
        ui->radioButton_Sex_M->setAutoExclusive(false);
        ui->radioButton_Sex_M->setChecked(false);
        ui->radioButton_Sex_M->setAutoExclusive(true);
    }
    else if (ui->radioButton_Sex_W->isChecked())
    {
        ui->radioButton_Sex_W->setAutoExclusive(false);
        ui->radioButton_Sex_W->setChecked(false);
        ui->radioButton_Sex_W->setAutoExclusive(true);
    }
    if(ui->radioButton_race_human->isChecked())
    {
        ui->radioButton_race_human->setAutoExclusive(false);
        ui->radioButton_race_human->setChecked(false);
        ui->radioButton_race_human->setAutoExclusive(true);
    }
    else if (ui->radioButton_race_elf->isChecked())
    {
        ui->radioButton_race_elf->setAutoExclusive(false);
        ui->radioButton_race_elf->setChecked(false);
        ui->radioButton_race_elf->setAutoExclusive(true);
    }
    else if (ui->radioButton_race_orc->isChecked())
    {
        ui->radioButton_race_orc->setAutoExclusive(false);
        ui->radioButton_race_orc->setChecked(false);
        ui->radioButton_race_orc->setAutoExclusive(true);
    }
    else if (ui->radioButton_race_goblin->isChecked())
    {
        ui->radioButton_race_goblin->setAutoExclusive(false);
        ui->radioButton_race_goblin->setChecked(false);
        ui->radioButton_race_goblin->setAutoExclusive(true);
    }
    ui->lineEdit_Name->setStyleSheet("color: rgb(0, 0, 0)");
    ui->lineEdit_Str->setStyleSheet("color: rgb(0, 0, 0)");
    ui->lineEdit_Dex->setStyleSheet("color: rgb(0, 0, 0)");
    ui->lineEdit_Int->setStyleSheet("color: rgb(0, 0, 0)");
    ui->lineEdit_Luck->setStyleSheet("color: rgb(0, 0, 0)");
    ui->lineEdit_Points->setStyleSheet("color: rgb(0, 0, 0)");
    points=20;//кол-во очков
    ui->lineEdit_Points->setText(QString::number(points));//преобразуем число в текст и записываем в lineedit
}

void MainWindow::on_pushButton_Create_clicked()
{
    QString name;
    int dlina;
    QFont font = ui->lineEdit_Name->font();
    font.setPixelSize(20);

    bool flag;//признак успешной генерации

    name=ui->lineEdit_Name->text();
    dlina=name.length();
    if((dlina<3)||(dlina>20))
    {
        flag=false;
        ui->lineEdit_Name->setFont(font);
        ui->lineEdit_Name->setStyleSheet("color: rgb(255, 0, 0)");
        QMessageBox::warning(this,"Ошибка","Длина имени должны быть от 3 до 20 символов.");
    }
    else
    {
        ui->lineEdit_Name->setStyleSheet("color: rgb(0, 0, 0)");
        ui->lineEdit_Name->setFont(font);
        flag=true;
    }
    if(flag)//вместо создания вложенных условий
    {
        if((!ui->radioButton_race_human->isChecked())&&(!ui->radioButton_race_elf->isChecked())&&(!ui->radioButton_race_orc->isChecked())&&(!ui->radioButton_race_goblin->isChecked()))//проверяем выбор расы
        {
            flag=false;
            QMessageBox::warning(this,"Ошибка","Раса не выбрана.");
        }
        else
        {
            flag=true;
        }
    }
    if(flag)//вместо создания вложенных условий
    {
        if((!ui->radioButton_Sex_M->isChecked())&&(!ui->radioButton_Sex_W->isChecked()))//проверяем выбор пола
        {
            flag=false;
            QMessageBox::warning(this,"Ошибка","Пол не выбран.");
        }
        else
        {
            flag=true;
        }
    }
    str=0;
    if(flag)//сила
    {
        str=ui->lineEdit_Str->text().toInt(&flag);
        if(!flag)
        {
            ui->lineEdit_Str->setFont(font);
            ui->lineEdit_Str->setStyleSheet("color: rgb(255, 0, 0)");
            QMessageBox::warning(this,"Ошибка","Неверное значение параметра \"Cила\".");
        }
        else
        {
            if((ui->radioButton_race_human->isChecked())||(ui->radioButton_race_elf->isChecked()))
            {
                if((str<1)||(str>10))//диапазон значения силы у людей и эльфов
                {
                    flag=false;
                    ui->lineEdit_Str->setFont(font);
                    ui->lineEdit_Str->setStyleSheet("color: rgb(255, 0, 0)");
                    QMessageBox::warning(this,"Ошибка","\"Cила\"должна быть от 1 до 10 включительно");

                }
            }
            else if (ui->radioButton_race_orc->isChecked())
            {
                if((str<3)||(str>13))//диапазон значения силы у орков
                {
                    flag=false;
                    ui->lineEdit_Str->setFont(font);
                    ui->lineEdit_Str->setStyleSheet("color: rgb(255, 0, 0)");
                    QMessageBox::warning(this,"Ошибка","\"Cила\"должна быть от 3 до 13 включительно");
                }
            }
            else if (ui->radioButton_race_goblin)
            {
                if((str<1)||(str>8))//диапазон значения силы у гоблинов
                {
                    flag=false;
                    ui->lineEdit_Str->setFont(font);
                    ui->lineEdit_Str->setStyleSheet("color: rgb(255, 0, 0)");
                    QMessageBox::warning(this,"Ошибка","\"Cила\"должна быть от 1 до 7 включительно");
                }
            }
        }
    }
    dex=4;
    if(flag)//Ловкость
    {
        ui->lineEdit_Str->setStyleSheet("color: rgb(0, 0, 0)");
        ui->lineEdit_Str->setFont(font);
        dex=ui->lineEdit_Dex->text().toInt(&flag);
        if(!flag)
        {
            ui->lineEdit_Dex->setFont(font);
            ui->lineEdit_Dex->setStyleSheet("color: rgb(255, 0, 0)");
            QMessageBox::warning(this,"Ошибка","Неверное значение параметра \"Ловкость\".");
        }
        else
        {
            if(ui->radioButton_race_human->isChecked())
            {
                if((dex<1)||(dex>10))//диапазон значения ловкости у людей
                {
                    flag=false;
                    ui->lineEdit_Dex->setFont(font);
                    ui->lineEdit_Dex->setStyleSheet("color: rgb(255, 0, 0)");
                    QMessageBox::warning(this,"Ошибка","\"Ловкость\"должна быть от 1 до 10 включительно");
                }
            }
            else if (ui->radioButton_race_elf->isChecked())
            {
                if((dex<3)||(dex>12))//диапазон значения ловкости у эльфов
                {
                    flag=false;
                    ui->lineEdit_Dex->setFont(font);
                    ui->lineEdit_Dex->setStyleSheet("color: rgb(255, 0, 0)");
                    QMessageBox::warning(this,"Ошибка","\"Ловкость\"должна быть от 3 до 13 включительно");
                }
            }
            else if ((ui->radioButton_race_orc->isChecked())||(ui->radioButton_race_goblin->isChecked()))
            {
                if((dex<1)||(dex>8))//диапазон значения ловкости у орков и гоблинов
                {
                    flag=false;
                    ui->lineEdit_Dex->setFont(font);
                    ui->lineEdit_Dex->setStyleSheet("color: rgb(255, 0, 0)");
                    QMessageBox::warning(this,"Ошибка","\"Ловкость\"должна быть от 1 до 8 включительно");
                }
            }
        }
    }
    intel=7;
    if(flag)//Интеллект
    {
        ui->lineEdit_Dex->setStyleSheet("color: rgb(0, 0, 0)");
        ui->lineEdit_Dex->setFont(font);
        intel=ui->lineEdit_Int->text().toInt(&flag);
        if(!flag)
        {
            ui->lineEdit_Int->setFont(font);
            ui->lineEdit_Int->setStyleSheet("color: rgb(255, 0, 0)");
            QMessageBox::warning(this,"Ошибка","Неверное значение параметра \"Интеллект\".");
        }
        else
        {
            if(ui->radioButton_race_human->isChecked())
            {
                if((intel<3)||(intel>12))//диапазон значения интелекта у людей
                {
                    flag=false;
                    ui->lineEdit_Int->setFont(font);
                    ui->lineEdit_Int->setStyleSheet("color: rgb(255, 0, 0)");
                    QMessageBox::warning(this,"Ошибка","\"Интеллект\"должна быть от 3 до 12 включительно");
                }
            }
            else if ((ui->radioButton_race_elf->isChecked())||(ui->radioButton_race_goblin->isChecked()))
            {
                if((intel<1)||(intel>10))//диапазон значения интелекта у эльфов и гоблинов
                {
                    flag=false;
                    ui->lineEdit_Int->setFont(font);
                    ui->lineEdit_Int->setStyleSheet("color: rgb(255, 0, 0)");
                    QMessageBox::warning(this,"Ошибка","\"Интеллект\"должна быть от 1 до 10 включительно");
                }
            }
            else if (ui->radioButton_race_orc->isChecked())
            {
                if((intel<1)||(intel>8))//диапазон значения интелекта у орков
                {
                    flag=false;
                    ui->lineEdit_Int->setFont(font);
                    ui->lineEdit_Int->setStyleSheet("color: rgb(255, 0, 0)");
                    QMessageBox::warning(this,"Ошибка","\"Интеллект\"должна быть от 1 до 8 включительно");
                }
            }

        }
    }
    luck=3;
    if(flag)//Удача
    {
        ui->lineEdit_Int->setStyleSheet("color: rgb(0, 0, 0)");
        ui->lineEdit_Int->setFont(font);
        luck=ui->lineEdit_Luck->text().toInt(&flag);
        if(!flag)
        {
            ui->lineEdit_Luck->setFont(font);
            ui->lineEdit_Luck->setStyleSheet("color: rgb(255, 0, 0)");
            QMessageBox::warning(this,"Ошибка","Неверное значение параметра \"Удача\".");
        }
        else
        {
            if((ui->radioButton_race_human->isChecked())||(ui->radioButton_race_elf->isChecked())||(ui->radioButton_race_orc->isChecked()))
            {
                if((luck<1)||(luck>10))//диапазон значения удачи у людей,эльфов и орков
                {
                    flag=false;
                    ui->lineEdit_Luck->setFont(font);
                    ui->lineEdit_Luck->setStyleSheet("color: rgb(255, 0, 0)");
                    QMessageBox::warning(this,"Ошибка","\"Удача\"должна быть от 1 до 10 включительно");
                }
            }
            else if (ui->radioButton_race_goblin->isChecked())
            {
                if((luck<2)||(luck>12))//диапазон значения удачи у гоблинов
                {
                    flag=false;
                    ui->lineEdit_Luck->setFont(font);
                    ui->lineEdit_Luck->setStyleSheet("color: rgb(255, 0, 0)");
                    QMessageBox::warning(this,"Ошибка","\"Удача\"должна быть от 2 до 12 включительно");
                }
            }
        }
    }
    if(flag)//сумма очков
    {
        ui->lineEdit_Luck->setStyleSheet("color: rgb(0, 0, 0)");
        ui->lineEdit_Luck->setFont(font);
        int sum=points-(str+dex+intel+luck);
        ui->lineEdit_Points->setText(QString::number(sum));
        if(sum!=0)
        {
            flag=false;
            if(sum>0)
            {
                ui->lineEdit_Points->setStyleSheet("color: rgb(255, 0, 0)");
                QMessageBox::warning(this,"Ошибка","Нужно потратить все очки");
            }
            else
            {
                ui->lineEdit_Points->setStyleSheet("color: rgb(255, 0, 0)");
                QMessageBox::warning(this,"Ошибка","Нельзя тратить больше чем +"+QString::number(points)+"очков.");
            }
        }
    }
    if(flag)//вывод результата
    {
        ui->lineEdit_Points->setStyleSheet("color: rgb(0, 0, 0)");
        ui->lineEdit_Points->setFont(font);
        func_class();
        if((ui->radioButton_race_human->isChecked())||(ui->radioButton_race_elf)->isChecked())//выводим изображение фракции-Альянс
            ui->label_image_2->show();
        else if ((ui->radioButton_race_orc->isChecked())||(ui->radioButton_race_goblin)->isChecked())//выводим изображение фракции-Орда
        {
            ui->label_image->show();
        }
    }
    else
    {
        ui->label_HP_Value->clear();
        ui->label_MP_Value->clear();
        ui->label_Atk_value->clear();
        ui->label_Def_Value->clear();
        ui->label_Class_Value->clear();
        ui->label_info->clear();
        ui->label_image->hide();
        ui->label_image_2->hide();
    }


}

void MainWindow::on_pushButton_random_clicked()
{
    bool flag=true;//признак успешной генерации
    int gend;//Для выбора случайной пола
    ui->lineEdit_Name->setStyleSheet("color: rgb(0, 0, 0)");
    ui->lineEdit_Str->setStyleSheet("color: rgb(0, 0, 0)");
    ui->lineEdit_Dex->setStyleSheet("color: rgb(0, 0, 0)");
    ui->lineEdit_Luck->setStyleSheet("color: rgb(0, 0, 0)");
    ui->lineEdit_Int->setStyleSheet("color: rgb(0, 0, 0)");
    QFont font = ui->lineEdit_Name->font();
    font.setPixelSize(20);
    gend=rand()%2+1;
    if (gend==2)
        ui->radioButton_Sex_W->click();
    else if(gend==1)
        ui->radioButton_Sex_M->click();
    if(flag)
    {
        int race;//Для выбора случайной расы
        race=rand()%4+1;
        if(race==1)
            ui->radioButton_race_human->click();
        else if(race==2)
            ui->radioButton_race_elf->click();
        else if(race==3)
            ui->radioButton_race_orc->click();
        else if(race==4)
            ui->radioButton_race_goblin->click();
    }


    if(flag)//вместо создания вложенных условий // выбор случайных имён
    {
        if (gend==2)
        {
            if(ui->radioButton_race_human->isChecked())
                ui->lineEdit_Name->setText(female_human[rand()%15]);//женские имена для людей
            else if (ui->radioButton_race_elf->isChecked())
            {
                ui->lineEdit_Name->setText(female_elf[rand()%15]);//женские имена для эльфов
            }
            else if (ui->radioButton_race_orc->isChecked())
            {
                ui->lineEdit_Name->setText(female_orc[rand()%15]);//женские имена для орков
            }
            else if (ui->radioButton_race_goblin->isChecked())
            {
                ui->lineEdit_Name->setText(female_goblin[rand()%15]);//женские имена для гоблинов
            }
        }
        else if (gend==1)
        {
            if(ui->radioButton_race_human->isChecked())
                ui->lineEdit_Name->setText(male_human[rand()%15]);//мужские имена для людей
            else if (ui->radioButton_race_elf->isChecked())
            {
                ui->lineEdit_Name->setText(male_elf[rand()%15]);//мужские имена для эльфов
            }
            else if (ui->radioButton_race_orc->isChecked())
            {
                ui->lineEdit_Name->setText(male_orc[rand()%15]);//мужские имена для орков
            }
            else if (ui->radioButton_race_goblin->isChecked())
            {
                ui->lineEdit_Name->setText(male_goblin[rand()%15]);//мужские имена для гоблинов
            }
        }
    }
    if (flag)
    {
        if(ui->radioButton_race_human->isChecked())//случайные показатели для человека
        {
            do
            {
                str=rand()%10+1;
                dex=rand()%10+1;
                intel=rand()%12+3;
                luck=rand()%10+1;
            }
            while (str+dex+intel+luck!=20);

            ui->lineEdit_Str->setText(QString::number(str));
            ui->lineEdit_Dex->setText(QString::number(dex));
            ui->lineEdit_Int->setText(QString::number(intel));
            ui->lineEdit_Luck->setText(QString::number(luck));
            ui->lineEdit_Points->setText(QString::number(0));
        }
        else if (ui->radioButton_race_elf->isChecked())//случайные показатели для эльфа
        {
            do
            {
                str=rand()%10+1;
                dex=rand()%12+3;
                intel=rand()%10+1;
                luck=rand()%10+1;
            }
            while (str+dex+intel+luck!=20);

            ui->lineEdit_Str->setText(QString::number(str));
            ui->lineEdit_Dex->setText(QString::number(dex));
            ui->lineEdit_Int->setText(QString::number(intel));
            ui->lineEdit_Luck->setText(QString::number(luck));
            ui->lineEdit_Points->setText(QString::number(0));
        }
        else if (ui->radioButton_race_orc->isChecked()) //случайные показатели для орка
        {
            do
            {
                str=rand()%12+3;
                dex=rand()%8+1;
                intel=rand()%8+1;
                luck=rand()%10+1;
            }
            while (str+dex+intel+luck!=20);

            ui->lineEdit_Str->setText(QString::number(str));
            ui->lineEdit_Dex->setText(QString::number(dex));
            ui->lineEdit_Int->setText(QString::number(intel));
            ui->lineEdit_Luck->setText(QString::number(luck));
            ui->lineEdit_Points->setText(QString::number(0));
        }
        else if (ui->radioButton_race_goblin->isChecked()) //случайные показатели для гоблина
        {
            do
            {
                str=rand()%8+1;
                dex=rand()%8+1;
                intel=rand()%10+1;
                luck=rand()%12+2;
            }
            while (str+dex+intel+luck!=20);

            ui->lineEdit_Str->setText(QString::number(str));
            ui->lineEdit_Dex->setText(QString::number(dex));
            ui->lineEdit_Int->setText(QString::number(intel));
            ui->lineEdit_Luck->setText(QString::number(luck));
            ui->lineEdit_Points->setText(QString::number(0));
        }
    }
    if(flag)
    {
        ui->lineEdit_Points->setStyleSheet("color: rgb(0, 0, 0)");
        ui->lineEdit_Points->setFont(font);
        func_class();//вызываем классовую систему
        if((ui->radioButton_race_human->isChecked())||(ui->radioButton_race_elf)->isChecked())//выводим изображение фракции-Альянс
        {
            ui->label_image_2->show();
            ui->label_image->hide();
        }
        else if ((ui->radioButton_race_orc->isChecked())||(ui->radioButton_race_goblin)->isChecked())//выводим изображение фракции-Орда
        {
            ui->label_image->show();
            ui->label_image_2->hide();
        }
    }
    else
    {
        ui->label_HP_Value->clear();
        ui->label_MP_Value->clear();
        ui->label_Atk_value->clear();
        ui->label_Def_Value->clear();
        ui->label_Class_Value->clear();
        ui->label_info->clear();
        ui->label_image->hide();
        ui->label_image_2->hide();

    }

}

