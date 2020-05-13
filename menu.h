

#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QPixmap>
#include <QDebug>
#include <QTimer>
#include <QList>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QUrl>
#include <QFile>
#include <QGraphicsDropShadowEffect>
#include <algorithm>
#include <string>
#include <your_hero.h>
#include <hero_window.h>
#include <enemy_window.h>
#include <events_window.h>
#include <tips_window.h>
#include <enemy.h>
#include <climits>
#include <QResizeEvent>
#include <QStyle>
#include <QRandomGenerator>
#include <event.h>
#include <QArrayData>
#include "tips_message.h"
namespace Ui {
class Menu;
}


/**
 * @brief Glowne okno programu umozliwiajace dostep do wiekszosci jego funkcji
 */
class Menu : public QMainWindow
{
    Q_OBJECT
public:
    /**
     * @brief Konstruktor klasy
     * @param parent: Widget rodzic
     */
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();
    /**
     * @brief Metoda ustawia szerokosc obrazka Twoj Bohater
     * @param width: Szerokosc
     */
    void set_hero_width(int width){hero_width = width;};
    /**
     * @brief Metoda ustawia wysokosc obrazka Twoj Bohater
     * @param height: Wysokosc
     */
    void set_hero_height(int height){hero_height = height;};
    /**
     * @brief Metoda zwraca szerokosc obrazka Twoj Bohater
     * @return Szerokosc obrazka
     */
    int get_hero_width(){return hero_width;};
    /**
     * @brief Metoda zwraca wysokosc obrazka Twoj Bohater
     * @return Wysokosc obrazka
     */
    int get_hero_height(){return hero_height;};
    /**
     * @brief Metoda sprawdza czy zaszla zmiana w liscie przeciwnikow
     * @param names: Tablica przechowujaca imiona postaci przeciwnikow
     * @param skin: Tablica przechwoujaca ID skinow przeciwnikow
     * @return true: doszlo do zmiany przeciwnikow
     * @return false: nie doszlo do zmiany przeciwnikow
     */
    bool check_if_enemy_changed(QString names[], double skin[]);
    /**
     * @brief Metoda zwraca ID bohatera aktualnego gracza w plikach z gry
     * @param players: Obiekt przechowujacy informacje o wszystkich graczach
     * @param name: Nazwa aktywnego gracza
     * @return ID postaci aktualnego gracza
     */
    int find_your_id(QJsonObject players[], QString name);
protected:
    /**
     * @brief Metoda wywolywana przy powiekszaniu okna
     * @param wZdarz: Parametry powiekszania
     */
    virtual void resizeEvent(QResizeEvent *wZdarz);
protected slots:
    /**
      * @brief Metoda odpowiadajaca za odbior ustawieni z okna Start
      * @param ust: Wskaznik do tablicy przechowujacej ustawienia
      */
     void get_settings(QString *ust);
     /**
      * @brief Metoda odpowiadajaca za pobranie odpowiednich plikow JSON z serwera lokalnego gry, jak i globalnej bazy danych
      */
     void update_json();
     /**
      * @brief Metoda aktualizuje pojawiajace sie na ekranie wskazowki
      */
     void update_tip();
     /**
      * @brief Metoda uaktualniajaca pola w oknie Menu, aktualizujaca pola klasy Menu oraz wysylacjaca informacje do pozostalych klas
      * @param reply
      */
     void on_results(QNetworkReply *reply);
     /**
      * @brief Metoda obsluguje pobranie danych o 1. przeciwniku z globalnej bazy danych
      * @param reply: Pobrane informacje
      */
     void on_resultsapiEn1(QNetworkReply *reply);
     /**
      * @brief Metoda obsluguje pobranie danych o 2. przeciwniku z globalnej bazy danych
      * @param reply: Pobrane informacje
      */
     void on_resultsapiEn2(QNetworkReply *reply);
     /**
      * @brief Metoda obsluguje pobranie danych o 3. przeciwniku z globalnej bazy danych
      * @param reply: Pobrane informacje
      */
     void on_resultsapiEn3(QNetworkReply *reply);
     /**
      * @brief Metoda obsluguje pobranie danych o 4. przeciwniku z globalnej bazy danych
      * @param reply: Pobrane informacje
      */
     void on_resultsapiEn4(QNetworkReply *reply);
     /**
      * @brief Metoda obsluguje pobranie danych o 5. przeciwniku z globalnej bazy danych
      * @param reply: Pobrane informacje
      */
     void on_resultsapiEn5(QNetworkReply *reply);

     /**
      * @brief Metoda obsluguje pobranie maestrii 1. przeciwnika z globalnej bazy danych
      * @param reply: Pobrane informacje
      */
     void on_resultsmasteryEn1(QNetworkReply *reply);
     /**
      * @brief Metoda obsluguje pobranie maestrii 2. przeciwnika z globalnej bazy danych
      * @param reply: Pobrane informacje
      */
     void on_resultsmasteryEn2(QNetworkReply *reply);
     /**
      * @brief Metoda obsluguje pobranie maestrii 3. przeciwnika z globalnej bazy danych
      * @param reply: Pobrane informacje
      */
     void on_resultsmasteryEn3(QNetworkReply *reply);
     /**
      * @brief Metoda obsluguje pobranie maestrii 4. przeciwnika z globalnej bazy danych
      * @param reply: Pobrane informacje
      */
     void on_resultsmasteryEn4(QNetworkReply *reply);
     /**
      * @brief Metoda obsluguje pobranie maestrii 5. przeciwnika z globalnej bazy danych
      * @param reply: Pobrane informacje
      */
     void on_resultsmasteryEn5(QNetworkReply *reply);

     /**
      * @brief Metoda obsluguje zdarzenie zamkniecia okna Twoj Bohater
      * @param results: Kod zamkniecia
      */
     void onHeroWindowClosed(int results);
     /**
      * @brief Metoda obsluguje zdarzenie zamkniecia okna Przeciwnicy
      * @param results: Kod zamkniecia
      */
     void onEnemyWindowClosed(int results);
     /**
      * @brief Metoda obsluguje zdarzenie zamkniecia okna Wydarzenia
      * @param results: Kod zamkniecia
      */
     void onEventsWindowClosed(int results);
     /**
      * @brief Metoda obsluguje zdarzenie zamkniecia okna Podpowiedzi
      * @param results: Kod zamkniecia
      */
     void onTipsWindowClosed(int results);
     /**
      * @brief Reakcja na nacisniecie przycisku Twoj Bohater. Otworzenie okna Twoj Bohater
      */
     void on_button_your_hero_clicked();
     /**
      * @brief Reakcja na nacisniecie przycisku Przeciwnicy. Otworzenie okna Przeciwnicy
      */
     void on_button_enemies_clicked();
     /**
      * @brief Reakcja na nacisniecie przycisku Wydarzenia. Otworzenie okna Wydarzenia
      */
     void on_button_events_clicked();
     /**
      * @brief Reakcja na nacisniecie przycisku Podpowiedzi. Otworzenie okna Podpowiedzi
      */
     void on_button_tips_clicked();
     /**
      * @brief Reakcja na zdarzenie zmienienia pozycji przez Splitter
      * @param pos: Pozycja
      * @param index: ID uchwytu Splittera
      */
     void on_splitter_splitterMoved(int pos, int index);
signals:
     /**
      * @brief Wyslanie danych do okna Twoj Bohater
      * @param data: Wysylane dane
      */
     void update_hero(const Your_hero &data);
     /**
      * @brief Wyslanie danych do okna Przeciwnicy
      * @param data: Wysylane dane
      */
     void update_enemies(Enemy* data);
     /**
      * @brief Wyslanie danych do okna Wydarzenia
      * @param data: Wysylane dane
      */
     void update_events(QList<Event> data);
     /**
      * @brief Wyslanie danych do okna Podpowiedzi
      * @param data: Wysylane dane
      */
     void update_tips(const Tips_message &data);
     /**
      * @brief Sygnal resetu gry
      */
     void reset_game();
private:
     /**
     * @brief ui
     */
    Ui::Menu *ui;
    /**
     * @brief Wskaznik na okno Twoj Bohater
     */
    Hero_window* her;
    /**
     * @brief Wskaznik na tablice przeciwnikow
     */
    Enemy_window* enem;
    /**
     * @brief Wskaznik na okno Podpowiedzi
     */
    Tips_window* tip;
    /**
     * @brief Wskaznik na okno Wydarzenia
     */
    Events_window* eve;
    /**
     * @brief Wskaznik na obraz postaci aktywnego gracza
     */
    QSharedPointer<QPixmap> pix;
    /**
     * @brief Wskaznik na tlo okna
     */
    QSharedPointer<QPixmap> pix_background;
    /**
     * @brief Wskaznik na tablice z grafikami przeciwnikow
     */
    QPixmap* pix_enemies;
    /**
     * @brief Timer aktualizujacy dane w aplikacji
     */
    QTimer *timer;
    /**
     * @brief Timer aktualizujacy wskazowki w menu
     */
    QTimer *timerTips;
    /**
     * @brief Manager polaczenia z API dla przeciwnika 1.
     */
    QNetworkAccessManager *networkManager_apiEn1;
    /**
     * @brief Manager polaczenia z API dla przeciwnika 2.
     */
    QNetworkAccessManager *networkManager_apiEn2;
    /**
     * @brief Manager polaczenia z API dla przeciwnika 3.
     */
    QNetworkAccessManager *networkManager_apiEn3;
    /**
     * @brief Manager polaczenia z API dla przeciwnika 4.
     */
    QNetworkAccessManager *networkManager_apiEn4;
    /**
     * @brief Manager polaczenia z API dla przeciwnika 5.
     */
    QNetworkAccessManager *networkManager_apiEn5;
    /**
     * @brief Manager polaczenia z API dla maestrii przeciwnika 1.
     */
    QNetworkAccessManager *networkManager_masteryEn1;
    /**
     * @brief Manager polaczenia z API dla maestrii przeciwnika 2.
     */
    QNetworkAccessManager *networkManager_masteryEn2;
    /**
     * @brief Manager polaczenia z API dla maestrii przeciwnika 3.
     */
    QNetworkAccessManager *networkManager_masteryEn3;
    /**
     * @brief Manager polaczenia z API dla maestrii przeciwnika 4.
     */
    QNetworkAccessManager *networkManager_masteryEn4;
    /**
     * @brief Manager polaczenia z API dla maestrii przeciwnika 5.
     */
    QNetworkAccessManager *networkManager_masteryEn5;
    /**
     * @brief Manager polaczenia dla lokalnej rozgrywki
     */
    QNetworkAccessManager *networkManager;
    /**
     * @brief Wskaznik na obiekt przechowujacy informacje o aktywnym graczu
     */
    QSharedPointer<Your_hero> your_hero;
    /**
     * @brief Wskaznik na tablice obiektow przechwoujacych informacje o przeciwnikach
     */
    Enemy* enemies;
    /**
     * @brief Struktrua przechwoujaca wiadomosc dla okna Podpowiedzi
     */
    Tips_message tips_message;
    /**
     * @brief Pozycja splittera 1.
     */
    int splitter_1_pos;
    /**
     * @brief Pozycja splittera 2.
     */
    int splitter_2_pos;

    /**
     * @brief Ilosc wiez zniszczonych przez druzyne aktywnego gracza
     */
    int count_towers_b;
    /**
     * @brief Ilosc smokow druzyny aktywnego gracza
     */
    int count_dragons_b;
    /**
     * @brief Ilosc baronow druzyny aktywnego gracza
     */
    int count_barons_b;
    /**
     * @brief Ilosc zabojstw druzyny aktywnego gracza
     */
    int count_kills_b;
    /**
     * @brief Ilosc wiez zniszczonych przez przeciwnikow
     */
    int count_towers_r;
    /**
     * @brief Ilosc smokow druzyny przeciwnikow
     */
    int count_dragons_r;
    /**
     * @brief Ilosc baronow druzyny przeciwnikow
     */
    int count_barons_r;
    /**
     * @brief Ilosc zabojstw przeciwnikow
     */
    int count_kills_r;
    /**
     * @brief Czy menu powinno jeszcze zostac zainicjalizowae. true: tak, false: nie
     */
    bool to_initialize;
    /**
     * @brief URL serwera danych
     */
    QString url;
    /**
     * @brief Port serwera danych
     */
    QString port;
    /**
     * @brief Jezyk programu
     */
    QString language;
    /**
     * @brief Klucz API
     */
    QString api_key;
    /**
     * @brief Czestotliwosc aktualizacji programu
     */
    int update_freq;
    /**
     * @brief Szerokosc okna
     */
    int window_width;
    /**
     * @brief Wysokosc okna
     */
    int window_height;
    /**
     * @brief Czy okno jest zmaksymalizowane
     */
    bool maximized;
    /**
     * @brief Wskaznik na tablice z ustawieniami
     */
    QString *settings;
    /**
     * @brief Lista wydarzen
     */
    QList<Event> events;
    /**
     * @brief Szerokosc grafiki postaci aktywnego gracza
     */
    int hero_width;
    /**
     * @brief Wysokosc grafiki aktywnego gracza
     */
    int hero_height;
    /**
     * @brief ID najnowszego wydarzenia
     */
    int current_event;

};

#endif // MENU_H
