#include "hero_window.h"
#include "ui_hero_window.h"

Hero_window::Hero_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hero_window)
{
    ui->setupUi(this);
    //ustawienie outline'u
    QString table_1("QLabel {""border-style: solid;"
                   "border-width: 1px;"
                   "border-color: black; "
                   "background-color: rgba(0,0,128,70%);"
                   "}");
    QString table_2("QLabel {""border-style: solid;"
                   "border-width: 1px;"
                   "border-color: black; "
                   "background-color: rgba(128,0,0,70%);"
                   "}");
    QString frame_back("QLabel {""border-style: solid;"
                       "border-width: 1px;"
                       "border-color: black; "
                       "background-color: rgba(0,0,0,70%);"
                       "}");
    QString frame("QLabel {""border-style: solid;"
                   "border-width: 1px;"
                   "border-color: black; "
                   "}");

    ui->label_pic_pass->setStyleSheet(frame);


    //ustawienia wykresu atak
    ui->attack_view->setRenderHint(QPainter::Antialiasing);

    time_temp = 0;

    attack_axisX = new QValueAxis;
    attack_axisY = new QValueAxis;
    attack_chart = new QChart;
    attack_series = new QLineSeries;

    ui->attack_view->setChart(attack_chart);

    attack_chart->addSeries(attack_series);

    attack_chart->addAxis(attack_axisX,Qt::AlignBottom);

    attack_chart->addAxis(attack_axisY,Qt::AlignLeft);

    attack_series->attachAxis(attack_axisX);

    attack_series->attachAxis(attack_axisY);

    attack_axisX->setTickCount(5);
    attack_axisX->setRange(0, 0);
    attack_axisY->setRange(0, 500);
    attack_chart->legend()->hide();
    attack_chart->setTitle("Atak w czasie");

    //ustawienia wykresu zloto
    ui->gold_view->setRenderHint(QPainter::Antialiasing);
    gold_axisX = new QValueAxis;
    gold_axisY = new QValueAxis;
    gold_chart = new QChart;
    gold_series = new QLineSeries;

    ui->gold_view->setChart(gold_chart);

    gold_chart->addSeries(gold_series);

    gold_chart->addAxis(gold_axisX,Qt::AlignBottom);
    gold_chart->addAxis(gold_axisY,Qt::AlignLeft);

    gold_series->attachAxis(gold_axisX);
    gold_series->attachAxis(gold_axisY);

    gold_axisX->setRange(0, 0);
    gold_axisY->setRange(0, 5000);
    gold_chart->legend()->hide();
    gold_chart->setTitle("Złoto w czasie");
}

Hero_window::~Hero_window()
{
    delete ui;
}

void Hero_window::receive_data(const Your_hero &hero)
{    
    //tutaj trzeba wypisać odpowiednie dane na ekran
    QString read_hero_name = hero.get_hero_name().replace(" ","").replace("'", "");

    double read_skin_id = hero.get_skin_id();

    //ustawienie nazwy bohatera
    ui->label_name->setText(read_hero_name);


    pix = QSharedPointer<QPixmap>(new QPixmap(QCoreApplication::applicationDirPath() + "/img/tiles/"+ read_hero_name +"_"+QString::number(read_skin_id)+".jpg"));
    pix_pass = QSharedPointer<QPixmap>(new QPixmap(QCoreApplication::applicationDirPath() +"/img/passive/"+ read_hero_name +"_Passive.png"));
    pix_q = QSharedPointer<QPixmap>(new QPixmap(QCoreApplication::applicationDirPath()+"/img/spell/"+ read_hero_name +"Q.png"));
    pix_w = QSharedPointer<QPixmap>(new QPixmap(QCoreApplication::applicationDirPath()+"/img/spell/"+ read_hero_name +"W.png"));
    pix_e = QSharedPointer<QPixmap>(new QPixmap(QCoreApplication::applicationDirPath()+"/img/spell/"+ read_hero_name +"E.png"));
    pix_r = QSharedPointer<QPixmap>(new QPixmap(QCoreApplication::applicationDirPath()+"/img/spell/"+ read_hero_name +"R.png"));

    ui->label_pic->setPixmap(pix->scaled(ui->label_pic->width(),ui->label_pic->height(), Qt::KeepAspectRatio));

    ui->label_pic_pass->setPixmap(pix_pass->scaled(50,50, Qt::KeepAspectRatio));
    ui->label_pic_q->setPixmap(pix_q->scaled(50,50, Qt::KeepAspectRatio));
    ui->label_pic_w->setPixmap(pix_w->scaled(50,50, Qt::KeepAspectRatio));
    ui->label_pic_e->setPixmap(pix_e->scaled(50,50, Qt::KeepAspectRatio));
    ui->label_pic_r->setPixmap(pix_r->scaled(50,50, Qt::KeepAspectRatio));

    //wczytanie danych do wykresow
    attack_series->replace(QList<QPointF>());
    attack_series->append(hero.get_attack_series()->points());
    attack_axisX->setRange(0, hero.get_game_time());

    gold_series->replace(QList<QPointF>());
    gold_series->append(hero.get_gold_series()->points());
    gold_axisX->setRange(0, hero.get_game_time());

    //wczytanie danych o przedmiotach
    pix_it6 = QSharedPointer<QPixmap>(new QPixmap(QCoreApplication::applicationDirPath() + "/img/item/"+ QString::number(hero.get_items().at(6).toObject().value("itemID").toDouble()) +".png"));
    ui->label_pic_item6->setPixmap(pix_it6->scaled(50,50, Qt::KeepAspectRatio));
    ui->label_item6->setText(hero.get_items().at(6).toObject().value("displayName").toString());

    pix_it5 = QSharedPointer<QPixmap>(new QPixmap(QCoreApplication::applicationDirPath() +"/img/item/"+ QString::number(hero.get_items().at(5).toObject().value("itemID").toDouble()) +".png"));
    ui->label_pic_item5->setPixmap(pix_it5->scaled(50,50, Qt::KeepAspectRatio));
    ui->label_item5->setText(hero.get_items().at(5).toObject().value("displayName").toString());

    pix_it4 = QSharedPointer<QPixmap>(new QPixmap(QCoreApplication::applicationDirPath() + "/img/item/"+ QString::number(hero.get_items().at(4).toObject().value("itemID").toDouble()) +".png"));
    ui->label_pic_item4->setPixmap(pix_it4->scaled(50,50, Qt::KeepAspectRatio));
    ui->label_item4->setText(hero.get_items().at(4).toObject().value("displayName").toString());

    pix_it3 = QSharedPointer<QPixmap>(new QPixmap(QCoreApplication::applicationDirPath() + "/img/item/"+ QString::number(hero.get_items().at(3).toObject().value("itemID").toDouble()) +".png"));
    ui->label_pic_item3->setPixmap(pix_it3->scaled(50,50, Qt::KeepAspectRatio));
    ui->label_item3->setText(hero.get_items().at(3).toObject().value("displayName").toString());

    pix_it2 = QSharedPointer<QPixmap>(new QPixmap(QCoreApplication::applicationDirPath() +"/img/item/"+ QString::number(hero.get_items().at(2).toObject().value("itemID").toDouble()) +".png"));
    ui->label_pic_item2->setPixmap(pix_it2->scaled(50,50, Qt::KeepAspectRatio));
    ui->label_item2->setText(hero.get_items().at(2).toObject().value("displayName").toString());

    pix_it1 = QSharedPointer<QPixmap>(new QPixmap(QCoreApplication::applicationDirPath() +"/img/item/"+ QString::number(hero.get_items().at(1).toObject().value("itemID").toDouble()) +".png"));
    ui->label_pic_item1->setPixmap(pix_it1->scaled(50,50, Qt::KeepAspectRatio));
    ui->label_item1->setText(hero.get_items().at(1).toObject().value("displayName").toString());

    pix_it0 = QSharedPointer<QPixmap>(new QPixmap(QCoreApplication::applicationDirPath() + "/img/item/"+ QString::number(hero.get_items().at(0).toObject().value("itemID").toDouble()) +".png"));
    ui->label_pic_item0->setPixmap(pix_it0->scaled(50,50, Qt::KeepAspectRatio));
    ui->label_item0->setText(hero.get_items().at(0).toObject().value("displayName").toString());


    //ustawienie statystyk
    ui->label_attack->setText(QString::number(hero.get_stats().value("attackDamage").toDouble(), 'f', 0));
    ui->label_ap->setText(QString::number(hero.get_stats().value("abilityPower").toDouble(), 'f', 0));
    ui->label_armor->setText(QString::number(hero.get_stats().value("armor").toDouble(), 'f', 0));
    ui->label_res->setText(QString::number(hero.get_stats().value("magicResist").toDouble(), 'f', 0));
    ui->label_cdr->setText(QString::number(hero.get_stats().value("cooldownReduction").toDouble(), 'f', 0));
    ui->label_attack_speed->setText(QString::number(hero.get_stats().value("cattackSpeed").toDouble(), 'f', 0));
    ui->label_nieust->setText(QString::number(hero.get_stats().value("tenacity").toDouble(), 'f', 0));
    ui->label_speed->setText(QString::number(hero.get_stats().value("moveSpeed").toDouble(), 'f', 0));
    ui->label_gold->setText(QString::number(hero.get_current_gold(), 'f', 0));
    ui->label_gold->setText(QString::number(hero.get_current_gold(), 'f', 0));
    ui->label_lvl->setText(QString::number(hero.get_level(), 'f', 0));




}

void Hero_window::on_pushButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://eune.leagueoflegends.com/pl-pl/champions/"+ui->label_name->text().toLower()+"/", QUrl::TolerantMode));
}


