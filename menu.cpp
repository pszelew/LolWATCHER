#include "menu.h"
#include "ui_menu.h"




Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu), to_initialize(true)
{
    ui->setupUi(this);
    //inicjacja tla
    pix_background = QSharedPointer<QPixmap>(new QPixmap(":/images/img/Teemo_4.jpg"));

    //odczyt ustawien z pliku data.conf
    QFile data_conf("/home/patyk/QT_tutorial/Lolwatcher_0_1/data.conf");

    if (!data_conf.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Nie udalo sie utworzyc pliku z ustawieniami: data.conf";
        return;
    }

    QTextStream in(&data_conf);

    url = in.readLine().remove("ip = ");
    port = in.readLine().remove("port = ");
    language = in.readLine().remove("language = ");
    update_freq = in.readLine().remove("update_freq = ").toInt();
    window_width = in.readLine().remove("window_width = ").toInt();
    window_height = in.readLine().remove("window_height = ").toInt();
    QString max_read = in.readLine().remove("maximized = ");
    qDebug() << max_read;
    if(max_read=="true")
        maximized = true;
    else
        maximized = false;
    api_key = in.readLine().remove("api_key = ");
    int x = this->width();
    int y = this->height();

    //inicjalizacja twojego bohatera
    your_hero = QSharedPointer<Your_hero>(new Your_hero);
    //inicjalizacja tablicy przeciwnikow
    enemies = new Enemy[5];
    //ustawienia sieci
    networkManager_api = new QNetworkAccessManager();
    networkManager = new QNetworkAccessManager();

    //polaczenie timera ze slotem pobierajacym dane z sieci
     timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()), this, SLOT(update_json()));
     timer->start(update_freq);
     connect(networkManager, SIGNAL(finished(QNetworkReply *)), this, SLOT(on_results(QNetworkReply *)));
     connect(networkManager_api, SIGNAL(finished(QNetworkReply *)), this, SLOT(on_results_api(QNetworkReply *)));


     //zaktualizuj dane w aplikacji plik
     update_json();

    //ustawienia wstepne splitera
    ui->splitter->setSizes({ 50000, 50000 });
    ui->splitter_2->setSizes({ 50000, 50000 });
    splitter_1_pos = ui->splitter->sizes()[0];


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

    ui->label_enemies->setStyleSheet(frame_back);
    ui->label_your_hero->setStyleSheet(frame_back);
    ui->label_tips->setStyleSheet(frame_back);
    ui->label_events->setStyleSheet(frame_back);
    ui->label_your_hero_pic->setStyleSheet(frame);
    ui->label_tip_current->setStyleSheet(frame_back);

    ui->label_towers_1->setStyleSheet(table_1);
    ui->label_towers_1_ans->setStyleSheet(table_1);
    ui->label_dragons_1->setStyleSheet(table_1);
    ui->label_dragons_1_ans->setStyleSheet(table_1);
    ui->label_barons_1->setStyleSheet(table_1);
    ui->label_barons_1_ans->setStyleSheet(table_1);

    ui->label_towers_2->setStyleSheet(table_2);
    ui->label_towers_2_ans->setStyleSheet(table_2);
    ui->label_dragons_2->setStyleSheet(table_2);
    ui->label_dragons_2_ans->setStyleSheet(table_2);
    ui->label_barons_2->setStyleSheet(table_2);
    ui->label_barons_2_ans->setStyleSheet(table_2);

    ui->label_enemy_1_pic->setStyleSheet(frame);
    ui->label_enemy_2_pic->setStyleSheet(frame);
    ui->label_enemy_3_pic->setStyleSheet(frame);
    ui->label_enemy_4_pic->setStyleSheet(frame);
    ui->label_enemy_5_pic->setStyleSheet(frame);

    ui->label_last->setStyleSheet(frame_back);
    ui->label_last_event->setStyleSheet(frame_back);

    QGraphicsDropShadowEffect *effect_e_1 = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *effect_e_2 = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *effect_e_3 = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *effect_e_4 = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *effect_e_5 = new QGraphicsDropShadowEffect(this);

    effect_e_1->setBlurRadius(0);
    effect_e_2->setBlurRadius(0);
    effect_e_3->setBlurRadius(0);
    effect_e_4->setBlurRadius(0);
    effect_e_5->setBlurRadius(0);

    effect_e_1->setColor(QColor("#000000"));
    effect_e_2->setColor(QColor("#000000"));
    effect_e_3->setColor(QColor("#000000"));
    effect_e_4->setColor(QColor("#000000"));
    effect_e_5->setColor(QColor("#000000"));

    effect_e_1->setOffset(1,1);
    effect_e_2->setOffset(1,1);
    effect_e_3->setOffset(1,1);
    effect_e_4->setOffset(1,1);
    effect_e_5->setOffset(1,1);

    ui->label_enemy_1_name->setGraphicsEffect(effect_e_1);
    ui->label_enemy_2_name->setGraphicsEffect(effect_e_2);
    ui->label_enemy_3_name->setGraphicsEffect(effect_e_3);
    ui->label_enemy_4_name->setGraphicsEffect(effect_e_4);
    ui->label_enemy_5_name->setGraphicsEffect(effect_e_5);




    //ustawiewnie obrazka your_hero
    pix = QSharedPointer<QPixmap>(new QPixmap("/home/patyk/QT_tutorial/Lolwatcher_0_1/img/tiles/black.jpg"));

    set_hero_width(0.25*x);
    set_hero_height(0.25*y);
    ui->label_your_hero_pic->setPixmap(pix->scaled(get_hero_width(),get_hero_height(), Qt::KeepAspectRatio));
    ui->label_your_hero_pic->setMinimumHeight(std::min(get_hero_width(), get_hero_height()));
    ui->label_your_hero_pic->setMinimumWidth(std::min(get_hero_width(), get_hero_height()));

    //ustawienie obrazkow enemies
    pix_enemies = new QPixmap[5];
    for(int i = 0;i <5;i++)
        pix_enemies[i] = QPixmap("/home/patyk/QT_tutorial/Lolwatcher_0_1/img/tiles/black.jpg");
}

Menu::~Menu()
{
    delete ui;
}

void Menu::resizeEvent(QResizeEvent *wZdarz)
{
    int w = ui->label_your_hero_pic->width();
    int h = ui->label_your_hero_pic->height();
    int x = this->width();
    int y = this->height();

    if(to_initialize&&maximized)
    {
        this->showMaximized();
        to_initialize = false;
    }
    else if(to_initialize)
    {
        this->resize(window_width, window_height);
        to_initialize = false;
    }

    QPalette palette;
    palette.setBrush(QPalette::Background, pix_background->scaled(this->size(), Qt::IgnoreAspectRatio));
    this->setPalette(palette);
    QList<int> test = ui->splitter->sizes();
    if(test[0]!=0)
    {
        if(ui->label_enemy_1_pic->width()<ui->label_enemy_1_pic->height())
        {
            ui->label_enemy_1_pic->setMaximumHeight(ui->label_enemy_1_pic->width());
            ui->label_enemy_2_pic->setMaximumHeight(ui->label_enemy_1_pic->width());
            ui->label_enemy_3_pic->setMaximumHeight(ui->label_enemy_1_pic->width());
            ui->label_enemy_4_pic->setMaximumHeight(ui->label_enemy_1_pic->width());
            ui->label_enemy_5_pic->setMaximumHeight(ui->label_enemy_1_pic->width());
            ui->label_enemy_1_pic->resize(ui->label_enemy_1_pic->height(), ui->label_enemy_1_pic->height());
            ui->label_enemy_2_pic->resize(ui->label_enemy_1_pic->height(), ui->label_enemy_1_pic->height());
            ui->label_enemy_3_pic->resize(ui->label_enemy_1_pic->height(), ui->label_enemy_1_pic->height());
            ui->label_enemy_4_pic->resize(ui->label_enemy_1_pic->height(), ui->label_enemy_1_pic->height());
            ui->label_enemy_5_pic->resize(ui->label_enemy_1_pic->height(), ui->label_enemy_1_pic->height());

            ui->label_enemy_1_pic->setPixmap(pix_enemies[0].scaled(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->height(),Qt::KeepAspectRatio));
            ui->label_enemy_2_pic->setPixmap(pix_enemies[1].scaled(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->height(),Qt::KeepAspectRatio));
            ui->label_enemy_3_pic->setPixmap(pix_enemies[2].scaled(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->height(),Qt::KeepAspectRatio));
            ui->label_enemy_4_pic->setPixmap(pix_enemies[3].scaled(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->height(),Qt::KeepAspectRatio));
            ui->label_enemy_5_pic->setPixmap(pix_enemies[4].scaled(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->height(),Qt::KeepAspectRatio));
        }
        else
        {
            ui->label_enemy_1_pic->setMaximumHeight(ui->label_enemy_1_pic->width());
            ui->label_enemy_2_pic->setMaximumHeight(ui->label_enemy_1_pic->width());
            ui->label_enemy_3_pic->setMaximumHeight(ui->label_enemy_1_pic->width());
            ui->label_enemy_4_pic->setMaximumHeight(ui->label_enemy_1_pic->width());
            ui->label_enemy_5_pic->setMaximumHeight(ui->label_enemy_1_pic->width());
            ui->label_enemy_1_pic->resize(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->width());
            ui->label_enemy_2_pic->resize(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->width());
            ui->label_enemy_3_pic->resize(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->width());
            ui->label_enemy_4_pic->resize(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->width());
            ui->label_enemy_5_pic->resize(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->width());
            ui->label_enemy_1_pic->setPixmap(pix_enemies[0].scaled(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->height(),Qt::KeepAspectRatio));
            ui->label_enemy_2_pic->setPixmap(pix_enemies[1].scaled(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->height(),Qt::KeepAspectRatio));
            ui->label_enemy_3_pic->setPixmap(pix_enemies[2].scaled(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->height(),Qt::KeepAspectRatio));
            ui->label_enemy_4_pic->setPixmap(pix_enemies[3].scaled(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->height(),Qt::KeepAspectRatio));
            ui->label_enemy_5_pic->setPixmap(pix_enemies[4].scaled(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->height(),Qt::KeepAspectRatio));
        }
    }
}


void Menu::update_json()
{
     networkManager->get(QNetworkRequest(QUrl("http://"+url+":"+port+"/liveclientdata/allgamedata")));
     networkManager_api->get(QNetworkRequest(QUrl("https://eun1.api.riotgames.com/lol/summoner/v4/summoners/by-name/pepit9889?api_key="+api_key)));
}

void Menu::on_results(QNetworkReply *reply)
{
    if(!reply->error())
    {
        //pobranie calego dokumentu
        QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
        QJsonObject root = document.object();

        if(root.keys().length()!=0)
        {
            qDebug()<<"Udalo sie wczytac";

            //wczytanie danych aktywnego gracza
            QJsonObject active_player = root.value(root.keys().at(0)).toObject();

            your_hero->set_active_player_Passive(active_player.value("abilities").toObject().value("Passive").toObject());
            your_hero->set_active_player_Q(active_player.value("abilities").toObject().value("Q").toObject());
            your_hero->set_active_player_W(active_player.value("abilities").toObject().value("W").toObject());
            your_hero->set_active_player_E(active_player.value("abilities").toObject().value("E").toObject());
            your_hero->set_active_player_R(active_player.value("abilities").toObject().value("R").toObject());
            your_hero->set_stats(active_player.value("championStats").toObject());
            your_hero->set_current_gold(active_player.value("currentGold").toDouble());
            your_hero->set_level(active_player.value("level").toInt());
            your_hero->set_full_runes(active_player.value("fullRunes").toObject()); //na razie wrzucone wszystko na raz
            //wczytanie wczytanie nazwy przywolywacza
            QString read_active_summoner_name = active_player.value("summonerName").toString();

            //wczytanie danych pozostalych graczy
            QJsonObject players[10];
            for(int i = 0; i<10; i++)
                players[i] = root.value(root.keys().at(1)).toArray().at(i).toObject();
            //poszukanie id aktualnego gracza
            int your_id = find_your_id(players, read_active_summoner_name);
            your_hero->set_id(your_id);

            //wczytanie nazwy bohatera
            QString read_hero_name = players[your_id].value("championName").toString();
            //wczytanie skinu bohatera
            double read_skin_id = players[your_id].value("skinID").toDouble();
            //wczytanie KDA
            double read_active_summoner_kills = players[your_id].value("scores").toObject().value("kills").toDouble();
            double read_active_summoner_deaths = players[your_id].value("scores").toObject().value("deaths").toDouble();
            double read_active_summoner_assists = players[your_id].value("scores").toObject().value("assists").toDouble();

            //wczytanie ilosci zabitych stworow
            QString read_active_summoner_cs = QString::number(players[your_id].value("scores").toObject().value("creepScore").toDouble());

            //deklaracja zmiennej przechowujacej loreers[your_id].value("
            QString read_hero_lore = your_hero->get_hero_lore();

            QString read_active_summoner_kda = QString::number(read_active_summoner_kills) +"/"+ QString::number(read_active_summoner_deaths) +"/"+ QString::number(read_active_summoner_assists);
            //jesli nastapila zmiana bohatera/skinu naszego bohatera
            if(read_hero_name!=your_hero->get_hero_name()||read_skin_id!=your_hero->get_skin_id())
            {
                    //ustawienie danych dla konkretnego bohatera
                    your_hero->set_hero_name(read_hero_name);
                    your_hero->set_skin_id(read_skin_id);

                    //odczytanie danych lokalnego pliku json dla aktualnie wybranego bohatera
                    QFile load_hero_data(":/data/champion/data/champion/"+read_hero_name+".json");
                    if (!load_hero_data.open(QIODevice::ReadOnly))
                    {
                            qDebug() << ("Nie udalo się otworzyć pliku z danymi bohatera");
                            return;
                    }

                    QJsonDocument document_hero_data = QJsonDocument::fromJson(load_hero_data.readAll());
                    QJsonObject root_hero_data = document_hero_data.object().value("data").toObject().value(read_hero_name).toObject();

                    your_hero->set_hero_data(root_hero_data);
                    //ustawienie tekstu pod grafika
                    QString title = root_hero_data.value("title").toString();
                    ui->label_your_hero_name->setText("<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">"+ read_hero_name +"</p><p align=\"center\"><span style=\" color:#ffffff;\">"+title+"</p></body></html>");

                    //ustawienie grafiki pod obrazem
                    pix = QSharedPointer<QPixmap>(new QPixmap("/home/patyk/QT_tutorial/Lolwatcher_0_1/img/tiles/"+ read_hero_name +"_"+QString::number(read_skin_id)+".jpg"));
                    ui->label_your_hero_pic->setPixmap(pix->scaled(get_hero_width(),get_hero_height(), Qt::KeepAspectRatio));
                    //wczytanie opisu bohatera
                    read_hero_lore = root_hero_data.value("lore").toString();
                    your_hero->set_hero_lore(read_hero_lore);
            }

            //wczytanie nazw i skinow przeciwnikow
            QString read_enemies_names[5];
            double read_enemies_skins[5];

            if(your_id<5)
            {
                for(int i = 0; i<5;++i)
                {
                    read_enemies_names[i] =  players[i+5].value("championName").toString();
                    read_enemies_skins[i] =  players[i+5].value("skinID").toDouble();
                    enemies[i].set_id(i+5);
                }
            }
            else
            {
                for(int i = 0; i<5;++i)
                {
                    read_enemies_names[i] =  players[i].value("championName").toString();
                    read_enemies_skins[i] =  players[i].value("skinID").toDouble();
                    enemies[i].set_id(i);
                }
            }

            //wczytanie KDA kazdego z przeciwknikow
            double read_enemy_kills[5];
            double read_enemy_deaths[5];
            double read_enemy_assists[5];
            double read_enemy_cs[5];
            QString read_enemy_kda[5];

            for (int i =0 ;i<5;++i)
            {
                read_enemy_kills[i] = players[enemies[i].get_id()].value("scores").toObject().value("kills").toDouble();
                read_enemy_deaths[i] = players[enemies[i].get_id()].value("scores").toObject().value("deaths").toDouble();
                read_enemy_assists[i] = players[enemies[i].get_id()].value("scores").toObject().value("assists").toDouble();
                read_enemy_cs[i] = players[enemies[i].get_id()].value("scores").toObject().value("creepScore").toDouble();
                read_enemy_kda[i] = QString::number(read_enemy_kills[0]) +"/"+ QString::number(read_enemy_deaths[0]) +"/"+ QString::number(read_enemy_assists[0]);
            }


            //jesli zmienil sie choc jeden przeciwnik, to zaktualizujmy przeciwnikow
            if(check_if_enemy_changed(read_enemies_names, read_enemies_skins))
            {
                //ustawienie nazw postaci w klasie
                for (int i =0;i<5;i++)
                {
                    enemies[i].set_hero_name(read_enemies_names[i]);
                    enemies[i].set_skin_id(read_enemies_skins[i]);
                }

               //ustawienie ich miniatur
               for(int i=0;i<5;++i)
               {
                  pix_enemies[i] = QPixmap("/home/patyk/QT_tutorial/Lolwatcher_0_1/img/tiles/"+ read_enemies_names[i] +"_"+QString::number(read_enemies_skins[i])+".jpg");
               }

               ui->label_enemy_1_pic->setPixmap(pix_enemies[0].scaled(ui->label_enemy_1_pic->width(),ui->label_enemy_1_pic->height(), Qt::KeepAspectRatio));
               ui->label_enemy_2_pic->setPixmap(pix_enemies[1].scaled(ui->label_enemy_2_pic->width(),ui->label_enemy_2_pic->height(), Qt::KeepAspectRatio));
               ui->label_enemy_3_pic->setPixmap(pix_enemies[2].scaled(ui->label_enemy_3_pic->width(),ui->label_enemy_3_pic->height(), Qt::KeepAspectRatio));
               ui->label_enemy_4_pic->setPixmap(pix_enemies[3].scaled(ui->label_enemy_4_pic->width(),ui->label_enemy_4_pic->height(), Qt::KeepAspectRatio));
               ui->label_enemy_5_pic->setPixmap(pix_enemies[4].scaled(ui->label_enemy_5_pic->width(),ui->label_enemy_5_pic->height(), Qt::KeepAspectRatio));

            }


            //tutaj zmienimy napis na srodku pola twoja postac
            ui->label_your_hero->setText("<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; color:#ffffff;\">Twoja postać</span></p><p align=\"center\"><span style=\" font-size:12pt; color:#ffffff;\">Bohater: "+read_hero_name+"</span></p><p align=\"center\"><span style=\" font-size:12pt; color:#ffffff;\">Gracz: "+read_active_summoner_name+"</span></p><p align=\"center\"><span style=\" font-size:12pt; color:#ffffff;\">K/D/A: "+ read_active_summoner_kda + " "+read_active_summoner_cs+ " cs</span></p><p align=\"center\"><span style=\" font-size:12pt; color:#ffffff;\">"+read_hero_lore+"</span></p></body></html>");
            ui->label_enemy_1_name->setText("<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">"+read_enemies_names[0]+"</span></p><p align=\"center\"><span style=\" color:#ffffff;\">"+read_enemy_kda[0]+" "+ QString::number(read_enemy_cs[0])+"</span></p></body></html>");
            ui->label_enemy_2_name->setText("<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">"+read_enemies_names[1]+"</span></p><p align=\"center\"><span style=\" color:#ffffff;\">"+read_enemy_kda[1]+" "+ QString::number(read_enemy_cs[1])+"</span></p></body></html>");
            ui->label_enemy_3_name->setText("<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">"+read_enemies_names[2]+"</span></p><p align=\"center\"><span style=\" color:#ffffff;\">"+read_enemy_kda[2]+" "+ QString::number(read_enemy_cs[2])+"</span></p></body></html>");
            ui->label_enemy_4_name->setText("<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">"+read_enemies_names[3]+"</span></p><p align=\"center\"><span style=\" color:#ffffff;\">"+read_enemy_kda[3]+" "+ QString::number(read_enemy_cs[3])+"</span></p></body></html>");
            ui->label_enemy_5_name->setText("<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">"+read_enemies_names[4]+"</span></p><p align=\"center\"><span style=\" color:#ffffff;\">"+read_enemy_kda[4]+" "+ QString::number(read_enemy_cs[4])+"</span></p></body></html>");




        }
        else
          qDebug() << "Niepowodzenie odczytu pliku json\n";
     }
     else
        qDebug() << "Nie nawiazano polaczenia z serwerem\n";
}

void Menu::on_results_api(QNetworkReply *reply)
{
    if(!reply->error())
    {
        qDebug() << "otrzymano informacje z serwera";
        QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
        QJsonObject root = document.object();
        qDebug()<< root;
    }
    else
    {
        qDebug()<< "blad odczytu z API";
    }
}


void Menu::on_button_your_hero_clicked()
{
    her = QSharedPointer<Hero_window>(new Hero_window(this));
    her->setModal(true);
    her->show();
}


bool Menu::check_if_enemy_changed(QString names[], double skin[])
{
    for(int i = 0;i<5;++i)
    {
        if(names[i]!=enemies[i].get_hero_name()||skin[i]!=enemies[i].get_skin_id())
        {
            return true;
        }
    }
    return false;
}

int Menu::find_your_id(QJsonObject players[], QString name)
{
    for(int i = 0; i<10;i++)
    {
        if(players[i].value("summonerName").toString()==name)
            return i;
    }
    return -1;
}

void Menu::on_splitter_splitterMoved(int pos, int index)
{

    QList<int> test = ui->splitter->sizes();
    qDebug() << test<< "<";
    //jesli sie rozszerza
    if(test.first()!=0&&splitter_1_pos>pos)
    {
        //ustawienie maksymalnej wysokosci zeby nam sie nie rozjechalo
        ui->label_enemy_1_pic->setMaximumHeight(ui->label_enemy_1_pic->width());
        ui->label_enemy_2_pic->setMaximumHeight(ui->label_enemy_1_pic->width());
        ui->label_enemy_3_pic->setMaximumHeight(ui->label_enemy_1_pic->width());
        ui->label_enemy_4_pic->setMaximumHeight(ui->label_enemy_1_pic->width());
        ui->label_enemy_5_pic->setMaximumHeight(ui->label_enemy_1_pic->width());
        ui->label_enemy_1_pic->resize(ui->label_enemy_1_pic->height(), ui->label_enemy_1_pic->height());
        ui->label_enemy_2_pic->resize(ui->label_enemy_1_pic->height(), ui->label_enemy_1_pic->height());
        ui->label_enemy_3_pic->resize(ui->label_enemy_1_pic->height(), ui->label_enemy_1_pic->height());
        ui->label_enemy_4_pic->resize(ui->label_enemy_1_pic->height(), ui->label_enemy_1_pic->height());
        ui->label_enemy_5_pic->resize(ui->label_enemy_1_pic->height(), ui->label_enemy_1_pic->height());
        ui->label_enemy_1_pic->setPixmap(pix_enemies[0].scaled(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->height(),Qt::KeepAspectRatio));
        ui->label_enemy_2_pic->setPixmap(pix_enemies[1].scaled(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->height(),Qt::KeepAspectRatio));
        ui->label_enemy_3_pic->setPixmap(pix_enemies[2].scaled(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->height(),Qt::KeepAspectRatio));
        ui->label_enemy_4_pic->setPixmap(pix_enemies[3].scaled(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->height(),Qt::KeepAspectRatio));
        ui->label_enemy_5_pic->setPixmap(pix_enemies[4].scaled(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->height(),Qt::KeepAspectRatio));
    }
    //jesli zmniejszamy splitter
    else if(splitter_1_pos<pos||test.first()==0)
    {
        ui->label_enemy_1_pic->setMaximumHeight(ui->label_enemy_1_pic->width());
        ui->label_enemy_2_pic->setMaximumHeight(ui->label_enemy_1_pic->width());
        ui->label_enemy_3_pic->setMaximumHeight(ui->label_enemy_1_pic->width());
        ui->label_enemy_4_pic->setMaximumHeight(ui->label_enemy_1_pic->width());
        ui->label_enemy_5_pic->setMaximumHeight(ui->label_enemy_1_pic->width());
        ui->label_enemy_1_pic->resize(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->width());
        ui->label_enemy_2_pic->resize(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->width());
        ui->label_enemy_3_pic->resize(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->width());
        ui->label_enemy_4_pic->resize(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->width());
        ui->label_enemy_5_pic->resize(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->width());
        ui->label_enemy_1_pic->setPixmap(pix_enemies[0].scaled(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->height(),Qt::KeepAspectRatio));
        ui->label_enemy_2_pic->setPixmap(pix_enemies[1].scaled(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->height(),Qt::KeepAspectRatio));
        ui->label_enemy_3_pic->setPixmap(pix_enemies[2].scaled(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->height(),Qt::KeepAspectRatio));
        ui->label_enemy_4_pic->setPixmap(pix_enemies[3].scaled(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->height(),Qt::KeepAspectRatio));
        ui->label_enemy_5_pic->setPixmap(pix_enemies[4].scaled(ui->label_enemy_1_pic->width(), ui->label_enemy_1_pic->height(),Qt::KeepAspectRatio));
    }
    else
        splitter_1_pos=pos;
}

void Menu::on_button_enemies_clicked()
{
    enem = QSharedPointer<Enemy_window>(new Enemy_window(this));
    enem->setModal(true);
    enem->show();
}

void Menu::on_button_events_clicked()
{
    eve = QSharedPointer<Events_window>(new Events_window(this));
    eve->setModal(true);
    eve->show();
}

void Menu::on_button_tips_clicked()
{
    tip = QSharedPointer<Tips_window>(new Tips_window(this));
    tip->setModal(true);
    tip->show();
}
