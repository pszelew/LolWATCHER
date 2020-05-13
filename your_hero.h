#ifndef YOUR_HERO_H
#define YOUR_HERO_H

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <climits>
#include <QLineSeries>
using namespace QtCharts;

/**
 * @brief Obiekt tej klasy reprezentuje bohatera aktywnego gracza
 */
class Your_hero
{
public:
    /**
     * @brief Konstruktor klasy
     */
    Your_hero();
    /**
     * @brief Ustawienie umiejetnosci pasywnej
     * @param object: Umiejetnosc pasywna
     */
    void set_active_player_Passive(QJsonObject object){active_player_Passive = object;}
    /**
     * @brief Ustawienie umiejetnosci Q
     * @param object: Umiejetnosc Q
     */
    void set_active_player_Q(QJsonObject object){active_player_Q = object;}
    /**
     * @brief Ustawienie umiejetnosci W
     * @param object: Umiejetnosc W
     */
    void set_active_player_W(QJsonObject object){active_player_W = object;}
    /**
     * @brief Ustawienie umiejetnosci E
     * @param object: Umiejetnosc E
     */
    void set_active_player_E(QJsonObject object){active_player_E = object;}
    /**
     * @brief Ustawienie umiejetnosci R
     * @param object: Umiejetnosc R
     */
    void set_active_player_R(QJsonObject object){active_player_R = object;}
    /**
     * @brief Ustawienie Statystyk postaci
     * @param object: Statystyki postaci
     */
    void set_stats(QJsonObject object){stats = object;}
    /**
     * @brief Ustawienie informacji o postaci
     * @param object: Informacje o postaci
     */
    void set_hero_data(QJsonObject object){hero_data = object;}
    /**
     * @brief Ustawienie pelnych run postaci
     * @param object: Pelne runy postaci
     */
    void set_full_runes(QJsonObject object){full_runes = object;}
    /**
     * @brief Ustawienie przedmiotow postacji
     * @param object: Posiadane przedmioty
     */
    void set_items(QJsonArray object){items = object;}
    /**
     * @brief Ustawienie nazwy przywolywacza
     * @param name: Nazwa przywolywacza
     */
    void set_summoner_name(QString name){summoner_name = name;}
    /**
     * @brief Ustawienie nazwy postaci
     * @param name: Nazwa postaci
     */
    void set_hero_name(QString name){hero_name = name;}
    /**
     * @brief Ustawienie historii postaci
     * @param story: Historia postaci
     */
    void set_hero_lore(QString story){lore = story;}
    /**
     * @brief Ustawienie druzyny postaci
     * @param name: Druzyna postaci
     */
    void set_hero_team(QString name){team = name;}
    /**
     * @brief Ustawienie ID skinu postaci
     * @param id_val: ID skinu postaci
     */
    void set_skin_id(double id_val){skin_id = id_val;}
    /**
     * @brief Ustawienie aktualnego zlota postaci
     * @param gold: Zloto postaci
     */
    void set_current_gold(double gold){current_gold = gold;}
    /**
     * @brief Ustawienie aktualnego czasu w rozgrywce
     * @param object: Czas w rozgrywce
     */
    void set_game_time(double object){game_time = object;}
    /**
     * @brief Ustawienie aktualnego poziomu postaci
     * @param object: Poziom postaci
     */
    void set_level(int object){level = object;}
    /**
     * @brief Ustawienie aktualnego ID postaci. Wartosci od 0 do 9
     * @param object: ID postaci
     */
    void set_id(int object){id = object;}
    /**
     * @brief Dodanie elementu do serii danych wykresu Atak
     * @param x: czas
     * @param y: wartosc
     */
    void append_attack_series(double x, double y) {attack_series->append(x,y);}
    /**
     * @brief Dodanie elementu do serii danych wykresu Zloto
     * @param x: czas
     * @param y: wartosc
     */
    void append_gold_series(double x, double y)  {gold_series->append(x,y);}

    /**
     * @brief Metoda zwraca umiejetnosc pasywna postaci
     * @return Umiejetnosc pasywna
     */
    QJsonObject get_active_player_Passive() const {return active_player_Passive;}
    /**
     * @brief Metoda zwraca umiejetnosc Q postaci
     * @return Umiejetnosc Q
     */
    QJsonObject get_active_player_Q() const {return active_player_Q;}
    /**
     * @brief Metoda zwraca umiejetnosc W postaci
     * @return Umiejetnosc W
     */
    QJsonObject get_active_player_W() const {return active_player_W;}
    /**
     * @brief Metoda zwraca umiejetnosc E postaci
     * @return Umiejetnosc E
     */
    QJsonObject get_active_player_E() const {return active_player_E;}
    /**
     * @brief Metoda zwraca umiejetnosc R postaci
     * @return Umiejetnosc R
     */
    QJsonObject get_active_player_R() const {return active_player_R;}
    /**
     * @brief Metoda zwraca statystyki postaci
     * @return Statystyki postaci
     */
    QJsonObject get_stats() const {return stats;}
    /**
     * @brief Metoda zwraca dane postaci
     * @return Dane postaci
     */
    QJsonObject get_hero_data() const {return hero_data;}
    /**
     * @brief Metoda zwraca pelne runy postaci
     * @return Pelne runy
     */
    QJsonObject get_full_runes() const {return full_runes;}
    /**
     * @brief Metoda zwraca przedmioty postaci
     * @return Przedmioty postaci
     */
    QJsonArray get_items() const {return items;}
    /**
     * @brief Metoda zwraca nazwe przywolywacza
     * @return Nazwa przywolywacza
     */
    QString get_summoner_name() const {return summoner_name;}
    /**
     * @brief Metoda zwraca nazwe postaci
     * @return Nazwa postaci
     */
    QString get_hero_name() const {return hero_name;}
    /**
     * @brief Metoda zwraca historie postaci
     * @return Historia postaci
     */
    QString get_hero_lore() const {return lore;}
    /**
     * @brief Metoda zwraca druzyne aktywnego gracza
     * @return Druzyna aktywnego gracza
     */
    QString get_hero_team() const {return team;}
    /**
     * @brief Metoda zwraca serie danych wykresu Atak
     * @return
     */
    QLineSeries* get_attack_series() const{return attack_series;}
    /**
     * @brief Metoda zwraca serie danych wykresu Zloto
     * @return
     */
    QLineSeries* get_gold_series() const {return gold_series;}
    /**
     * @brief Metoda zwraca ID skinu postaci
     * @return ID skinu postaci
     */
    double get_skin_id() const {return skin_id;}
    /**
     * @brief Metoda zwraca aktualny stan konta postaci
     * @return Stan konta postaci
     */
    double get_current_gold() const {return current_gold;}
    /**
     * @brief Metoda zwraca aktualny czas w grze
     * @return Aktualny czas w grze
     */
    double get_game_time() const{ return game_time;}

    /**
     * @brief Metoda zwraca aktualny poziom postaci
     * @return Poziom postaci
     */
    int get_level() const {return level;}
    /**
     * @brief Metoda zwraca ID postaci
     * @return ID postaci
     */
    int get_id() const {return id;}

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
     * @brief Nazwa przywolywacza
     */
    QString summoner_name;
    /**
     * @brief Druzyna aktywnego gracza
     */
    QString team;
    /**
     * @brief ID skinu postaci
     */
    double skin_id;
    /**
     * @brief Aktualny czas w grze
     */
    double game_time;
    /**
     * @brief Aktualny stan konsta postaci
     */
    double current_gold;
    /**
     * @brief Poziom postaci
     */
    int level;
    /**
     * @brief ID postaci
     */
    int id;
    /**
     * @brief Informacje o postaci
     */
    QJsonObject hero_data;
    /**
     * @brief Umiejetnosc pasywna postaci
     */
    QJsonObject active_player_Passive;
    /**
     * @brief Umiejetnosc Q postaci
     */
    QJsonObject active_player_Q;
    /**
     * @brief Umiejetnosc W postaci
     */
    QJsonObject active_player_W;
    /**
     * @brief Umiejetnosc E postaci
     */
    QJsonObject active_player_E;
    /**
     * @brief Umiejetnosc R postaci
     */
    QJsonObject active_player_R;
    /**
     * @brief Pelne runy postaci
     */
    QJsonObject full_runes;
    /**
     * @brief Statystyki postaci
     */
    QJsonObject stats;
    /**
     * @brief Przedmioty postaci
     */
    QJsonArray items;

    /**
     * @brief Seria danych wykresu Atak
     */
    QLineSeries* attack_series;
    /**
     * @brief Seria danych wykresu Zloto
     */
    QLineSeries* gold_series;

};

#endif // YOUR_HERO_H
