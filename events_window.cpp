#include "events_window.h"
#include "ui_events_window.h"

Events_window::Events_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Events_window), current_event(0), count_towers(0), count_dragons(0), count_barons(0)
{
    ui->setupUi(this);

    layout_scroll = new QGridLayout();

    ui->scrollAreaWidgetContents->setLayout(layout_scroll);
}

Events_window::~Events_window()
{
    delete ui;
}

void Events_window::receive_data(QList<Event> data)
{
    for (int i =current_event;i<data.length();++i)
    {
        QLabel *temp_time = new QLabel();
        QLabel *temp_name = new QLabel();
        int time_val = data.at(i).get_eventTime();
        QString name_val = data.at(i).get_eventName();
        QString temp_1;
        QString temp_2;
        if(time_val/60<10)
            temp_1 = "0" + QString::number(time_val/60);
        else
            temp_1 = QString::number(time_val/60);
        if(time_val%60<10)
            temp_2 = "0" + QString::number(time_val%60);
        else
            temp_2 = QString::number(time_val%60);
        temp_time->setText(temp_1+ ":" +temp_2);

        if(name_val == "GameStart")
            temp_name->setText("Początek gry");
        else if(name_val == "MinionsSpawning")
            temp_name->setText("Pojawienie się stworów");
        else if(name_val == "ChampionKill")
            temp_name->setText(data.at(i).get_killerName()+ " pokonał przeciwnika");
        else if(name_val == "FirstBlood")
            temp_name->setText("Gracz " + data.at(i).get_killerName()+" przelewa pierwszą krew. Gratulacje!");
        else if(name_val == "FirstBrick")
            temp_name->setText(data.at(i).get_killerName()+" zniszczył pierwszą wieżę. Gratulacje!");
        else if(name_val == "TurretKilled")
            temp_name->setText(data.at(i).get_killerName()+" zniszczył wieżę");
        else temp_name->setText(name_val);

        temp_name->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred));
        layout_scroll->addWidget(temp_time, i, 0);
        layout_scroll->addWidget(temp_name, i, 1);
    }

    current_event = data.length();
}
