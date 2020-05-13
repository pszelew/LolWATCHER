#ifndef ENEMY_H
#define ENEMY_H
#include <QString>
#include <QJsonObject>
#include <QJsonArray>
/**
 * @brief Klasa przechwujaca informacje o przeciwniku
 */
class Enemy
{
public:
    /**
     * @brief Konstruktor klasy
     */
    Enemy();
    /**
     * @brief Metoda zwraca statystyki bohatera
     * @return Statystyki bohatera
     */
    const QJsonObject get_stats(){return stats;}
    /**
     * @brief Metoda zwraca informacje o bohaterze
     * @return Informacje o bohaterze
     */
    const QJsonObject get_hero_data(){return hero_data;}
    /**
     * @brief Metoda zwraca obiekt zawierający informacje o umiejętnościach bohatera
     * @return Infrmacje o umiejętnościach bohatera
     */
    const QJsonObject get_spells(){return summonerSpells;}
    /**
     * @brief Metoda zwraca nick przywoływacza
     * @return Nick przywoływacza
     */
    const QString get_summoner_name(){return summoner_name;}
    /**
     * @brief Metoda zwraca nazwę bohatera
     * @return Nazwa bohatera
     */
    const QString get_hero_name(){return hero_name;}
    /**
     * @brief Metoda zwraca historie bohatera
     * @return Historria bohatera
     */
    const QString get_hero_lore(){return lore;}
    /**
     * @brief Metoda zwraca liste przedmiotow bohatera
     * @return Lista przedmiotow bohatera
     */
    const QJsonArray get_items() const {return items;}
    /**
     * @brief Metoda zwraca ID skinu bohatera
     * @return ID skinu
     */
    double get_skin_id() const {return skin_id;}
    /**
     * @brief Metoda zwraca poziom maestrii gracza na danym bohaterze
     * @return Poziom maestrii
     */
    double get_masteryLvl() const {return masteryLvl;}
    /**
     * @brief Metoda zwraca punkty maestrii gracza na danym bohaterze
     * @return Punkty maestrii
     */
    double get_masteryPts() const {return masteryPts;}
    /**
     * @brief Metoda zwraca aktualny poziom postaci
     * @return Poziom postaci
     */
    int get_level()const {return level;}
    /**
     * @brief Metoda zwraca ID postaci
     * @return ID postaci
     */
    int get_id()const {return id;}


    /**
     * @brief Metoda ustawia statystyki bohatera
     * @param object : Statystyki bohatera
     */
    void set_stats(QJsonObject object){stats = object;}
    /**
     * @brief Metoda ustawia informacje o bohaterze
     * @param object: Informacje o bohaterze
     */
    void set_hero_data(QJsonObject object){hero_data = object;}
    /**
     * @brief Metoda ustawia umiejętności bohatera
     * @param object: Umiejętności bohatera
     */
    void set_spells(QJsonObject object){summonerSpells = object;}
    /**
     * @brief Metoda ustawia nazwę przywoływacza
     * @param object: Nazwa przywoływacza
     */
    void set_summoner_name(QString object){summoner_name = object;}
    /**
     * @brief Metoda ustawia nazwę postaci
     * @param name: Nazwa postaci
     */
    void set_hero_name(QString name){hero_name = name;}
    /**
     * @brief Metoda ustawia historię postaci
     * @param name: Historia postaci
     */
    void set_hero_lore(QString name){lore = name;}
    /**
     * @brief Metoda ustawia przedmioty postaci
     * @param object: Posiadane przedmioty
     */
    void set_items(QJsonArray object){items = object;}
    /**
     * @brief Metoda ustawia ID skinu postaci
     * @param name: ID skinu postaci
     */
    void set_skin_id(double name){skin_id = name;}
    /**
     * @brief Metoda ustawia poziom maestrii gracza na danej postaci
     * @param lvl: Poziom maestrii
     */
    void set_masteryLvl(double lvl){masteryLvl = lvl;}
    /**
     * @brief Metoda ustawia ilosc puntkow maestrii gracza na danej postaci
     * @param points: Punkty maestrii
     */
    void set_masteryPts(double points){masteryPts = points;}
    /**
     * @brief Metoda ustawia poziom postaci
     * @param lvl: Poziom postaci
     */
    void set_level(int lvl){level = lvl;}
    /**
     * @brief Metoda ustawia ID postaci. ID wykorzystane jest do odczytu danych z plikow gry. ID przyjmuje wartosci od 0 do 9.
     * @param id_val: ID postaci
     */
    void set_id(int id_val){id = id_val;}

private:
    /**
     * @brief Nazwa postaci
     */
    QString hero_name;
    /**
     * @brief Historia postaci
     */
    QString lore;
    /**
     * @brief Informacje o postaci
     */
    QJsonObject hero_data;
    /**
     * @brief ID skinu postaci
     */
    double skin_id;
    /**
     * @brief Nazwa przywolywacza
     */
    QString summoner_name;
    /**
     * @brief Level postaci
     */
    int level;
    /**
     * @brief ID postaci. Sluzy do odczytu danych z plikow gry. ID miesci sie w przedziale od 0 do 9
     */
    int id;
    /**
     * @brief Statystyki postaci
     */
    QJsonObject stats;
    /**
     * @brief Przedmioty postaci
     */
    QJsonArray items;
    /**
     * @brief Czary przywolywacza postaci
     */
    QJsonObject summonerSpells;
    /**
     * @brief Poziom maestrii postaci
     */
    double masteryLvl;
    /**
     * @brief Punkty maestrii postaci
     */
    double masteryPts;

};

#endif // ENEMY_H
