#include "enemy_window.h"
#include "ui_enemy_window.h"

Enemy_window::Enemy_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Enemy_window)
{
    ui->setupUi(this);
    //inicjacja tablicy przechwoujacej grafiki przedmiotow
    pix_items = new QPixmap[35];
    pix_spells = new QPixmap[10];

    //ustawienie obrazkow na domyslne - czarne
    pix_enemies = new QPixmap[5];
    for(int i = 0;i <5;i++)
        pix_enemies[i] = QPixmap("/home/patyk/QT_tutorial/Lolwatcher_0_1/img/tiles/black.jpg");
    for(int i = 0;i <35;i++)
        pix_items[i] = QPixmap("/home/patyk/QT_tutorial/Lolwatcher_0_1/img/tiles/black.jpg");
    for(int i = 0;i <10;i++)
        pix_spells[i] = QPixmap("/home/patyk/QT_tutorial/Lolwatcher_0_1/img/tiles/black.jpg");
    //talica przechowujaca uchwyty do kolejnych obrazkow
    label_items = new QLabel*[35];
    label_spells = new QLabel *[10];
    int i=0;
    //tutaj przypisuje kolejne obrazki do odpowiednich tabel
    label_items[i++] = ui->label_item0_en1;
    label_items[i++] = ui->label_item1_en1;
    label_items[i++] = ui->label_item2_en1;
    label_items[i++] = ui->label_item3_en1;
    label_items[i++] = ui->label_item4_en1;
    label_items[i++] = ui->label_item5_en1;
    label_items[i++] = ui->label_item6_en1;
    label_items[i++] = ui->label_item0_en2;
    label_items[i++] = ui->label_item1_en2;
    label_items[i++] = ui->label_item2_en2;
    label_items[i++] = ui->label_item3_en2;
    label_items[i++] = ui->label_item4_en2;
    label_items[i++] = ui->label_item5_en2;
    label_items[i++] = ui->label_item6_en2;
    label_items[i++] = ui->label_item0_en3;
    label_items[i++] = ui->label_item1_en3;
    label_items[i++] = ui->label_item2_en3;
    label_items[i++] = ui->label_item3_en3;
    label_items[i++] = ui->label_item4_en3;
    label_items[i++] = ui->label_item5_en3;
    label_items[i++] = ui->label_item6_en3;
    label_items[i++] = ui->label_item0_en4;
    label_items[i++] = ui->label_item1_en4;
    label_items[i++] = ui->label_item2_en4;
    label_items[i++] = ui->label_item3_en4;
    label_items[i++] = ui->label_item4_en4;
    label_items[i++] = ui->label_item5_en4;
    label_items[i++] = ui->label_item6_en4;
    label_items[i++] = ui->label_item0_en5;
    label_items[i++] = ui->label_item1_en5;
    label_items[i++] = ui->label_item2_en5;
    label_items[i++] = ui->label_item3_en5;
    label_items[i++] = ui->label_item4_en5;
    label_items[i++] = ui->label_item5_en5;
    label_items[i++] = ui->label_item6_en5;

    i=0;
    label_spells[i++] = ui->label_spell1_en1;
    label_spells[i++] = ui->label_spell2_en1;
    label_spells[i++] = ui->label_spell1_en2;
    label_spells[i++] = ui->label_spell2_en2;
    label_spells[i++] = ui->label_spell1_en3;
    label_spells[i++] = ui->label_spell2_en3;
    label_spells[i++] = ui->label_spell1_en4;
    label_spells[i++] = ui->label_spell2_en4;
    label_spells[i++] = ui->label_spell1_en5;
    label_spells[i++] = ui->label_spell2_en5;
}

Enemy_window::~Enemy_window()
{
    delete ui;
}

void Enemy_window::resizeEvent(QResizeEvent *wZdarz)
{
    if(ui->label_pic_1->width()<ui->label_pic_1->height())
    {
        ui->label_pic_1->setMaximumHeight(ui->label_pic_1->width());
        ui->label_pic_2->setMaximumHeight(ui->label_pic_2->width());
        ui->label_pic_3->setMaximumHeight(ui->label_pic_3->width());
        ui->label_pic_4->setMaximumHeight(ui->label_pic_4->width());
        ui->label_pic_5->setMaximumHeight(ui->label_pic_5->width());
        //-->
        for(int i=0;i<35;++i)
        {
            label_items[i]->setMaximumHeight(label_items[i]->width());
        }
        for(int i=0;i<10;++i)
        {
            label_spells[i]->setMaximumHeight(label_spells[i]->width());
        }
        //<--

        ui->label_pic_1->resize(ui->label_pic_1->height(), ui->label_pic_1->height());
        ui->label_pic_2->resize(ui->label_pic_2->height(), ui->label_pic_2->height());
        ui->label_pic_3->resize(ui->label_pic_3->height(), ui->label_pic_3->height());
        ui->label_pic_4->resize(ui->label_pic_4->height(), ui->label_pic_4->height());
        ui->label_pic_5->resize(ui->label_pic_5->height(), ui->label_pic_5->height());

        //-->
        for(int i=0;i<35;++i)
        {
            label_items[i]->resize(label_items[i]->height(), label_items[i]->height());
        }
        for(int i=0;i<10;++i)
        {
            label_items[i]->resize(label_spells[i]->height(), label_spells[i]->height());
        }
        //<--

        ui->label_pic_1->setPixmap(pix_enemies[0].scaled(ui->label_pic_1->width(), ui->label_pic_1->height(),Qt::KeepAspectRatio));
        ui->label_pic_2->setPixmap(pix_enemies[1].scaled(ui->label_pic_2->width(), ui->label_pic_2->height(),Qt::KeepAspectRatio));
        ui->label_pic_3->setPixmap(pix_enemies[2].scaled(ui->label_pic_3->width(), ui->label_pic_3->height(),Qt::KeepAspectRatio));
        ui->label_pic_4->setPixmap(pix_enemies[3].scaled(ui->label_pic_4->width(), ui->label_pic_4->height(),Qt::KeepAspectRatio));
        ui->label_pic_5->setPixmap(pix_enemies[4].scaled(ui->label_pic_5->width(), ui->label_pic_5->height(),Qt::KeepAspectRatio));

        //-->
        for(int i=0;i<35;++i)
        {
            label_items[i]->setPixmap(pix_items[i].scaled(label_items[i]->width(), label_items[i]->height(),Qt::KeepAspectRatio));
        }
        for(int i=0;i<10;++i)
        {
            label_spells[i]->setPixmap(pix_spells[i].scaled(label_spells[i]->width(), label_spells[i]->height(),Qt::KeepAspectRatio));
        }
        //<--
    }
    else
    {
        ui->label_pic_1->setMaximumHeight(ui->label_pic_1->width());
        ui->label_pic_2->setMaximumHeight(ui->label_pic_2->width());
        ui->label_pic_3->setMaximumHeight(ui->label_pic_3->width());
        ui->label_pic_4->setMaximumHeight(ui->label_pic_4->width());
        ui->label_pic_5->setMaximumHeight(ui->label_pic_5->width());
        //-->
        for(int i=0;i<35;++i)
        {
            label_items[i]->setMaximumHeight(label_items[i]->width());
        }
        for(int i=0;i<10;++i)
        {
            label_spells[i]->setMaximumHeight(label_spells[i]->width());
        }
        //<--

        ui->label_pic_1->resize(ui->label_pic_1->width(), ui->label_pic_1->width());
        ui->label_pic_2->resize(ui->label_pic_2->width(), ui->label_pic_2->width());
        ui->label_pic_3->resize(ui->label_pic_3->width(), ui->label_pic_3->width());
        ui->label_pic_4->resize(ui->label_pic_4->width(), ui->label_pic_4->width());
        ui->label_pic_5->resize(ui->label_pic_5->width(), ui->label_pic_5->width());

        //-->
        for(int i=0;i<35;++i)
        {
            label_items[i]->resize(label_items[i]->width(), label_items[i]->width());
        }
        for(int i=0;i<10;++i)
        {
            label_spells[i]->resize(label_spells[i]->width(), label_spells[i]->width());
        }

        //<--

        ui->label_pic_1->setPixmap(pix_enemies[0].scaled(ui->label_pic_1->width(), ui->label_pic_1->height(),Qt::KeepAspectRatio));
        ui->label_pic_2->setPixmap(pix_enemies[1].scaled(ui->label_pic_2->width(), ui->label_pic_2->height(),Qt::KeepAspectRatio));
        ui->label_pic_3->setPixmap(pix_enemies[2].scaled(ui->label_pic_3->width(), ui->label_pic_3->height(),Qt::KeepAspectRatio));
        ui->label_pic_4->setPixmap(pix_enemies[3].scaled(ui->label_pic_4->width(), ui->label_pic_4->height(),Qt::KeepAspectRatio));
        ui->label_pic_5->setPixmap(pix_enemies[4].scaled(ui->label_pic_5->width(), ui->label_pic_5->height(),Qt::KeepAspectRatio));

        //-->
        for(int i=0;i<35;++i)
        {
            label_items[i]->setPixmap(pix_items[i].scaled(label_items[i]->width(), label_items[i]->height(),Qt::KeepAspectRatio));
        }
        for(int i=0;i<10;++i)
        {
            label_spells[i]->setPixmap(pix_spells[i].scaled(label_spells[i]->width(), label_spells[i]->height(),Qt::KeepAspectRatio));
        }
        //<--

    }
}

void Enemy_window::receive_data(Enemy* heros)
{
    //ustawienie grafik przeciwnikow
    for(int i=0;i<5;++i)
    {
       pix_enemies[i] = QPixmap("/home/patyk/QT_tutorial/Lolwatcher_0_1/img/tiles/"+ heros[i].get_hero_name() +"_"+QString::number(heros[i].get_skin_id())+".jpg");
    }

    ui->label_pic_1->setPixmap(pix_enemies[0].scaled(ui->label_pic_1->width(),ui->label_pic_1->height(), Qt::KeepAspectRatio));
    ui->label_pic_2->setPixmap(pix_enemies[1].scaled(ui->label_pic_2->width(),ui->label_pic_2->height(), Qt::KeepAspectRatio));
    ui->label_pic_3->setPixmap(pix_enemies[2].scaled(ui->label_pic_3->width(),ui->label_pic_3->height(), Qt::KeepAspectRatio));
    ui->label_pic_4->setPixmap(pix_enemies[3].scaled(ui->label_pic_4->width(),ui->label_pic_4->height(), Qt::KeepAspectRatio));
    ui->label_pic_5->setPixmap(pix_enemies[4].scaled(ui->label_pic_5->width(),ui->label_pic_5->height(), Qt::KeepAspectRatio));

    //ustawienie nazw bohaterow pod grafikami
   ui->label_name_1->setText(heros[0].get_hero_name());
   ui->label_name_2->setText(heros[1].get_hero_name());
   ui->label_name_3->setText(heros[2].get_hero_name());
   ui->label_name_4->setText(heros[3].get_hero_name());
   ui->label_name_5->setText(heros[4].get_hero_name());

   //ustawienie przedmiotów przeciwników
   for(int i=0; i<35;i++)
    {
        pix_items[i] = QPixmap("/home/patyk/QT_tutorial/Lolwatcher_0_1/img/item/"+ QString::number(heros[i/7].get_items().at(i%7).toObject().value("itemID").toDouble()) +".png");
        label_items[i]->setPixmap(pix_items[i].scaled(label_items[i]->width(),label_items[i]->height(), Qt::KeepAspectRatio));
    }


    //ustawienie spelli przeciwnikow
    for(int i=0; i<10;i++)
    {
        QString temp = heros[i/2].get_spells().value(heros[i/2].get_spells().keys().at(i%2)).toObject().value("displayName").toString();
        if(temp=="Duch")
            pix_spells[i] = QPixmap("/home/patyk/QT_tutorial/Lolwatcher_0_1/img/spell/SummonerHaste.png");
        else if(temp == "Uzdrowienie")
            pix_spells[i] = QPixmap("/home/patyk/QT_tutorial/Lolwatcher_0_1/img/spell/SummonerHeal.png");
        else if(temp == "Oczyszczenie")
            pix_spells[i] = QPixmap("/home/patyk/QT_tutorial/Lolwatcher_0_1/img/spell/SummonerBoost.png");
        else if(temp == "Teleportacja")
            pix_spells[i] = QPixmap("/home/patyk/QT_tutorial/Lolwatcher_0_1/img/spell/SummonerTeleport.png");
        else if(temp == "Porażenie")
            pix_spells[i] = QPixmap("/home/patyk/QT_tutorial/Lolwatcher_0_1/img/spell/SummonerSmite.png");
        else if(temp == "Bariera")
            pix_spells[i] = QPixmap("/home/patyk/QT_tutorial/Lolwatcher_0_1/img/spell/SummonerBarrier.png");
        else if(temp == "Podpalenie")
            pix_spells[i] = QPixmap("/home/patyk/QT_tutorial/Lolwatcher_0_1/img/spell/SummonerDot.png");
        else if(temp == "Wyczerpanie")
            pix_spells[i] = QPixmap("/home/patyk/QT_tutorial/Lolwatcher_0_1/img/spell/SummonerExhaust.png");
        else if (temp == "Błysk")
            pix_spells[i] = QPixmap("/home/patyk/QT_tutorial/Lolwatcher_0_1/img/spell/SummonerFlash.png");
        else if (temp == "Czystość")
            pix_spells[i] = QPixmap("/home/patyk/QT_tutorial/Lolwatcher_0_1/img/spell/SummonerMana.png");

        label_spells[i]->setPixmap(pix_spells[i].scaled(label_spells[i]->width(),label_spells[i]->height(), Qt::KeepAspectRatio));
    }

    //ustawienie maestrii przeciwnikow
    ui->label_maestry_1_en1->setText("Lvl: "+ QString::number(heros[0].get_masteryLvl()));
    ui->label_maestry_2_en1->setText("Pts: "+ QString::number(heros[0].get_masteryPts()));
    ui->label_maestry_1_en2->setText("Lvl: "+ QString::number(heros[1].get_masteryLvl()));
    ui->label_maestry_2_en2->setText("Pts: "+ QString::number(heros[1].get_masteryPts()));
    ui->label_maestry_1_en3->setText("Lvl: "+ QString::number(heros[2].get_masteryLvl()));
    ui->label_maestry_2_en3->setText("Pts: "+ QString::number(heros[2].get_masteryPts()));
    ui->label_maestry_1_en4->setText("Lvl: "+ QString::number(heros[3].get_masteryLvl()));
    ui->label_maestry_2_en4->setText("Pts: "+ QString::number(heros[3].get_masteryPts()));
    ui->label_maestry_1_en5->setText("Lvl: "+ QString::number(heros[4].get_masteryLvl()));
    ui->label_maestry_2_en5->setText("Pts: "+ QString::number(heros[4].get_masteryPts()));

}

void Enemy_window::on_pushButton_1_clicked()
{
    QDesktopServices::openUrl(QUrl("https://eune.leagueoflegends.com/pl-pl/champions/"+ui->label_name_1->text().toLower()+"/", QUrl::TolerantMode));
}

void Enemy_window::on_pushButton_2_clicked()
{
    QDesktopServices::openUrl(QUrl("https://eune.leagueoflegends.com/pl-pl/champions/"+ui->label_name_2->text().toLower()+"/", QUrl::TolerantMode));
}

void Enemy_window::on_pushButton_3_clicked()
{
    QDesktopServices::openUrl(QUrl("https://eune.leagueoflegends.com/pl-pl/champions/"+ui->label_name_3->text().toLower()+"/", QUrl::TolerantMode));
}

void Enemy_window::on_pushButton_4_clicked()
{
    QDesktopServices::openUrl(QUrl("https://eune.leagueoflegends.com/pl-pl/champions/"+ui->label_name_4->text().toLower()+"/", QUrl::TolerantMode));
}

void Enemy_window::on_pushButton_5_clicked()
{
    QDesktopServices::openUrl(QUrl("https://eune.leagueoflegends.com/pl-pl/champions/"+ui->label_name_5->text().toLower()+"/", QUrl::TolerantMode));
}
