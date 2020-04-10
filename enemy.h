#ifndef ENEMY_H
#define ENEMY_H
#include <QString>
#include <QJsonObject>

class Enemy
{
public:
    Enemy();

    const QJsonObject get_stats(){return stats;}
    const QJsonObject get_hero_data(){return hero_data;}

    const QString get_summoner_name(){return summoner_name;}
    const QString get_hero_name(){return hero_name;}
    const QString get_hero_lore(){return lore;}

    const double get_skin_id(){return skin_id;}

    const int get_level(){return level;}
    const int get_id(){return id;}



    void set_stats(QJsonObject object){stats = object;}
    void set_hero_data(QJsonObject object){hero_data = object;}

    void set_summoner_name(QString object){summoner_name = object;}
    void set_hero_name(QString name){hero_name = name;}
    void set_hero_lore(QString name){lore = name;}

    void set_skin_id(double name){skin_id = name;}

    void set_level(int object){level = object;}
    void set_id(int object){id = object;}

private:
    QString hero_name;
    QString lore;
    QJsonObject hero_data;
    double skin_id;
    QString summoner_name;
    int level;
    int id;
    QJsonObject stats;
};

#endif // ENEMY_H
