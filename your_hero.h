#ifndef YOUR_HERO_H
#define YOUR_HERO_H

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <climits>
#include <QLineSeries>
using namespace QtCharts;

class Your_hero
{
public:
    Your_hero();

    void set_active_player_Passive(QJsonObject object){active_player_Passive = object;}
    void set_active_player_Q(QJsonObject object){active_player_Q = object;}
    void set_active_player_W(QJsonObject object){active_player_W = object;}
    void set_active_player_E(QJsonObject object){active_player_E = object;}
    void set_active_player_R(QJsonObject object){active_player_R = object;}
    void set_stats(QJsonObject object){stats = object;}
    void set_hero_data(QJsonObject object){hero_data = object;}
    void set_full_runes(QJsonObject object){full_runes = object;}
    void set_items(QJsonArray object){items = object;}

    void set_summoner_name(QString object){summoner_name = object;}
    void set_hero_name(QString name){hero_name = name;}
    void set_hero_lore(QString name){lore = name;}

    void set_skin_id(double name){skin_id = name;}
    void set_current_gold(double object){current_gold = object;}
    void set_game_time(double object){game_time = object;}

    void set_level(int object){level = object;}
    void set_id(int object){id = object;}

    void append_attack_series(double x, double y) {attack_series->append(x,y);}
    void append_gold_series(double x, double y)  {gold_series->append(x,y);}



    QJsonObject get_active_player_Passive() const {return active_player_Passive;}
    QJsonObject get_active_player_Q() const {return active_player_Q;}
    QJsonObject get_active_player_W() const {return active_player_W;}
    QJsonObject get_active_player_E() const {return active_player_E;}
    QJsonObject get_active_player_R() const {return active_player_R;}
    QJsonObject get_stats() const {return stats;}
    QJsonObject get_hero_data() const {return hero_data;}
    QJsonObject get_full_runes() const {return full_runes;}
    QJsonArray get_items() const {return items;}

    QString get_summoner_name() const {return summoner_name;}
    QString get_hero_name() const {return hero_name;}
    QString get_hero_lore() const {return lore;}

    QLineSeries* get_attack_series() const{return attack_series;}
    QLineSeries* get_gold_series() const {return gold_series;}

    double get_skin_id() const {return skin_id;}
    double get_current_gold() const {return current_gold;}
    double get_game_time() const{ return game_time;}


    int get_level() const {return level;}
    int get_id() const {return id;}

private:
    QString hero_name;
    QString lore;
    QString summoner_name;

    double skin_id;
    double game_time;
    double current_gold;

    int level;
    int id;

     QJsonObject hero_data;
    QJsonObject active_player_Passive;
    QJsonObject active_player_Q;
    QJsonObject active_player_W;
    QJsonObject active_player_E;
    QJsonObject active_player_R;
    QJsonObject full_runes;
    QJsonObject stats;
    QJsonArray items;

    QLineSeries* attack_series;
    QLineSeries* gold_series;

};

#endif // YOUR_HERO_H
