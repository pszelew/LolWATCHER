#include "start.h"
#include "ui_start.h"
#include <QPixmap>
#include <QDebug>
#include <QGraphicsEffect>


Start::Start(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Start)
{
    QString ver = "ver 0.1, 20/04/04";
    ui->setupUi(this);
    //minimalna wielkosc okna
    this->setMinimumSize(300, 200);

    //ustawienie wersji programu
    ui->label_version->setText(ver);
    ui->label_version->setAlignment(Qt::AlignCenter);
    ui->label_version->setStyleSheet("QLabel {color : white; }");


    //ustawienie tla programu
    gif = new QMovie(":/images/img/lucian.gif");
    ui->label_background->move(0,0);
    //ui->label_background->setPixmap(pix->scaled(w,h));
    ui->label_background->setMovie(gif);
    gif->start();

    //ustawienie przezroczystosci przyciskow

    auto effect = new QGraphicsOpacityEffect(this);
    effect->setOpacity(0);
    ui->button_settings->setGraphicsEffect(effect);
    ui->button_settings->setAutoFillBackground(true);

    auto effect_2 = new QGraphicsOpacityEffect(this);
    effect_2->setOpacity(0);
    ui->button_author->setGraphicsEffect(effect_2);
    ui->button_author->setAutoFillBackground(true);

    auto effect_3 = new QGraphicsOpacityEffect(this);
    effect_3->setOpacity(0);
    ui->button_connect->setGraphicsEffect(effect_3);
    ui->button_connect->setAutoFillBackground(true);


    //ustawienie outline'u
    ui->label_author->setStyleSheet("QLabel {""border-style: solid;"
     "border-width: 1px;"
     "border-color: white; "
     "}");

    ui->label_settings->setStyleSheet("QLabel {"
     "border-style: solid;"
     "border-width: 1px;"
     "border-color: white; "
     "}");

    ui->label_connect->setStyleSheet("QLabel {"
     "border-style: solid;"
     "border-width: 1px;"
     "border-color: white; "
     "}");

    //ustawienie tematu dzwiekowego
    player = new QMediaPlayer;
    playlist = new QMediaPlaylist;

    playlist->addMedia(QUrl::fromLocalFile("/home/patyk/QT_tutorial/Lolwatcher_0_1/sounds/theme.mp3"));
    playlist->setCurrentIndex(1);
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(playlist);


    player->setVolume(50);
    player->play();

    //ustawienie logo
    //pix = QSharedPointer<QPixmap>(new QPixmap(":/images/img/logo.png"));

}

Start::~Start()
{
    delete ui;
}

void Start::resizeEvent(QResizeEvent *wZdarz)
{
    int x = this->width();
    int y = this->height();
    float ratio = float(x)/float(y);
    QFont font = ui->label_logo->font();
    gif->setScaledSize(QSize(x,y));
    //skalowanie tla
        ui->label_background->resize(x,y);
        //ui->label_background->setPixmap(pix->scaled(x,y));
        ui->label_background->setMovie(gif);

    //skalowanie logo
        if(int(0.04*x)<0.1*y)
        {
            font.setPointSize(0.04*x);
            ui->label_logo->setFont(font);
            font.setPointSize(0.02*x);
            ui->label_logo_2->setFont(font);
        }
        else
        {
            font.setPointSize(0.1*y);
            ui->label_logo->setFont(font);
            font.setPointSize(0.05*y);
            ui->label_logo_2->setFont(font);
        }

        ui->label_logo->move(0.25*x,0.1*y);
        ui->label_logo_2->move(0.25*x,0.25*y);

        ui->label_logo->resize(0.5*x,0.15*y);
        ui->label_logo_2->resize(0.5*x,0.10*y);

     //skalowanie przycisku start

        if(int(0.02*x)<0.05*y)
        {
            font.setPointSize(0.02*x);
            ui->button_connect->setFont(font);
            ui->label_connect->setFont(font);
        }
        else
        {
            font.setPointSize(0.05*y);
            ui->button_connect->setFont(font);
            ui->label_connect->setFont(font);
        }

        ui->button_connect->move(0.4*x,0.7*y);
        ui->button_connect->resize(0.2*x,0.2*y);
        ui->label_connect->move(0.4*x,0.7*y);
        ui->label_connect->resize(0.2*x,0.2*y);

        //skalowanie przycisku version
        if(int(0.0117*x)<0.02*y)
        {
            font.setPointSize(0.0117*x);
            ui->label_version->setFont(font);
        }
        else
        {
            font.setPointSize(0.02*y);
            ui->label_version->setFont(font);
        }

        ui->label_version->move(0.40*x,0.9*y);
        ui->label_version->resize(0.2*x,0.1*y);


    //skalowanie przycisku author i labelu author
        if(int(0.0117*x)<0.02*y)
        {
            font.setPointSize(0.0117*x);
            ui->button_author->setFont(font);
            ui->label_author->setFont(font);
        }
        else
        {
            font.setPointSize(0.02*y);
            ui->button_author->setFont(font);
            ui->label_author->setFont(font);
        }

        ui->button_author->move(0.05*x,0.9*y);
        ui->button_author->resize(0.12*x,0.05*y);
        ui->label_author->move(0.05*x,0.9*y);
        ui->label_author->resize(0.12*x,0.05*y);

    //skalowanie przycisku ustawienia
        if(int(0.0117*x)<0.02*y)
        {
            font.setPointSize(0.0117*x);
            ui->button_settings->setFont(font);
            ui->label_settings->setFont(font);
        }
        else
        {
            font.setPointSize(0.02*y);
            ui->button_settings->setFont(font);
            ui->label_settings->setFont(font);
        }

        ui->button_settings->move(0.83*x,0.9*y);
        ui->button_settings->resize(0.12*x,0.05*y);

        ui->label_settings->move(0.83*x,0.9*y);
        ui->label_settings->resize(0.12*x,0.05*y);



}


void Start::on_button_settings_clicked()
{
   ust = QSharedPointer<Ustawienia>(new Ustawienia(this));
   ust->setModal(true);
   ust->show();
}

void Start::on_button_author_clicked()
{
    auth = QSharedPointer<Author>(new Author(this));
    auth->setModal(true);
    auth->show();
}

void Start::on_button_connect_clicked()
{
    menu = QSharedPointer<Menu>(new Menu(this));
    menu->setModal(true);
    menu->show();
}