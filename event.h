#ifndef EVENT_H
#define EVENT_H
#include <QString>
/**
 * @brief Klasa przechowujaca informacje o wydarzeniach odczytanych z gry.
 */
class Event
{
public:
    /**
     * @brief Konstruktor klasy
     */
    Event();
    /**
     * @brief Konstruktor klasy
     * @param ID: ID wydarzenia
     * @param Time: Czas wydarzenia
     * @param Name: Nazwa wydarzenia
     */
    Event(int ID, double Time, QString Name){eventID = ID; eventTime = Time; eventName = Name;}
    /**
     * @brief Metoda zwraca ID eventu
     * @return ID eventu
     */
    int get_eventID() const {return eventID;}
    /**
     * @brief Metoda zwraca ID druzyny ktora dokonala zabojstwa
     * @return ID druzyny
     */
    int get_KilledTeam() const  {return killedTeam;}
    /**
     * @brief Metoda zwraca czas wydarzenia
     * @return Czas wydarzenia
     */
    double get_eventTime() const {return eventTime;}
    /**
     * @brief Metoda zwraca nazwe wydarzenia
     * @return Nazwa wydarznia
     */
    QString get_eventName() const {return eventName;}
    /**
     * @brief Metoda zwraca nazwe zabojcy
     * @return Nazwa zabojcy
     */
    QString get_killerName() const {return killerName;}

    /**
     * @brief Metoda zwraca ID wydarzenia
     * @param id_val: ID wydarzenia
     */
    void set_eventID(int id_val){eventID = id_val;}
    /**
     * @brief Metoda ustawia druzyne dokonujaca zabojstwa
     * @param team: Druzyna dokonujaca zabojstwa
     */
    void set_KilledTeam(int team){killedTeam = team;}
    /**
     * @brief Metoda ustawia czas wydarzenia
     * @param time: Czas wydarzenia
     */
    void set_eventTime(double time){eventTime = time;}
    /**
     * @brief Metoda ustawia nazwe wydarzenia
     * @param name: Nazwa wydarzenia
     */
    void set_eventName(QString name){eventName = name;}
    /**
     * @brief Metoda ustawia nazwe zabojcy
     * @param name: Nazwa zabojcy
     */
    void set_killerName(QString name){killerName = name;}

private:
    /**
     * @brief ID wydarzenia
     */
    int eventID;
    /**
     * @brief Czas wydarzenia
     */
    double eventTime;
    /**
     * @brief Druzyna dokonujaca zabojstwa
     */
    int killedTeam;
    /**
     * @brief Nazwa wydarzenia
     */
    QString eventName;
    /**
     * @brief Nazwa zabojcy
     */
    QString killerName;
};

#endif // EVENT_H
