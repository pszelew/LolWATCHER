#ifndef YOUR_HERO_H
#define YOUR_HERO_H

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <climits>

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

    void set_summoner_name(QString object){summoner_name = object;}
    void set_hero_name(QString name){hero_name = name;}
    void set_hero_lore(QString name){lore = name;}

    void set_skin_id(double name){skin_id = name;}
    void set_current_gold(double object){current_gold = object;}

    void set_level(int object){level = object;}
    void set_id(int object){id = object;}



    const QJsonObject get_active_player_Passive(){return active_player_Passive;}
    const QJsonObject get_active_player_Q(){return active_player_Q;}
    const QJsonObject get_active_player_W(){return active_player_W;}
    const QJsonObject get_active_player_E(){return active_player_E;}
    const QJsonObject get_active_player_R(){return active_player_R;}
    const QJsonObject get_stats(){return stats;}
    const QJsonObject get_hero_data(){return hero_data;}
    const QJsonObject get_full_runes(){return full_runes;}

    const QString get_summoner_name(){return summoner_name;}
    const QString get_hero_name(){return hero_name;}
    const QString get_hero_lore(){return lore;}

    const double get_skin_id(){return skin_id;}
    const double get_current_gold(){return current_gold;}

    const int get_level(){return level;}
    const int get_id(){return id;}



private:
    QString hero_name;
    QString lore;
    QJsonObject hero_data;
    double skin_id;
    QString summoner_name;
    double current_gold;
    int level;
    int id;

    QJsonObject active_player_Passive;
    QJsonObject active_player_Q;
    QJsonObject active_player_W;
    QJsonObject active_player_E;
    QJsonObject active_player_R;
    QJsonObject full_runes;
    QJsonObject stats;
};

#endif // YOUR_HERO_H
