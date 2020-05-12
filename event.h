#ifndef EVENT_H
#define EVENT_H
#include <QString>

class Event
{
public:
    Event();
    Event(int ID, double Time, QString Name){eventID = ID; eventTime = Time; eventName = Name;}
    int get_eventID() const {return eventID;}
    int get_KilledTeam() const  {return killedTeam;}

    double get_eventTime() const {return eventTime;}

    QString get_eventName() const {return eventName;}
    QString get_killerName() const {return killerName;}

    void set_eventID(int object){eventID = object;}
    void set_KilledTeam(int object){killedTeam = object;}

    void set_eventTime(double object){eventTime = object;}

    void set_eventName(QString object){eventName = object;}
    void set_killerName(QString object){killerName = object;}


private:
    int eventID;
    double eventTime;
    int killedTeam;

    QString eventName;
    QString killerName;
};

#endif // EVENT_H
