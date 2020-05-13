#ifndef START_H
#define START_H

#include <QMainWindow>
#include <QPixmap>
#include <QSoundEffect>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMovie>
#include <QSize>
#include <QNetworkAccessManager>
#include <QMessageBox>
#include "ustawienia.h"
#include "author.h"
#include "menu.h"



QT_BEGIN_NAMESPACE
namespace Ui { class Start; }
QT_END_NAMESPACE

/**
 * @brief Okno startowe programu
 */
class Start : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor klasy
     * @param parent: Widget rodzic
     */
    Start(QWidget *parent = nullptr);
    ~Start();
protected slots:
    /**
     * @brief Metoda obslugujaca otrzymanie danych z serwera lokalnego gry
     * @param reply: Otrzymane dane
     */
    void on_results(QNetworkReply *reply);
protected:
    /**
     * @brief Metoda wywolywana przy zmianie rozmiaru okna
     * @param wZdarz: Parametry zmiany rozmiaru okna
     */
    virtual void resizeEvent(QResizeEvent *wZdarz);
private slots:
    /**
     * @brief Reakcja na nacisniecie przyskisku Ustawienia. Otworzenie okna Ustawienia.
     */
    void on_button_settings_clicked();
    /**
     * @brief Reakcja na nacisniecie przycisku Autor. Otworzenie okna Autor.
     */
    void on_button_author_clicked();
    /**
     * @brief Reakcja na nacisniecie przycisku Polacz. Otworzenie okna Menu.
     */
    void on_button_connect_clicked();
    /**
     * @brief Aktualizacja stanu okna po zmianie ustawien.
     * @param result: Kod aktualizacji.
     */
    void update_window(int result);
signals:
    /**
     * @brief Wyslanie ustawien do okna Menu.
     * @param settings: Wysylane ustawienia
     */
    void send_settings(QString *settings);
private:
    /**
     * @brief Skalowanie zawartosci okna
     */
    void update_content();
    /**
     * @brief Wskaznik do tablicy przechwujacej ustawienia
     */
    QString *settings;
    /**
     * @brief ui
     */
    Ui::Start *ui;
    /**
     * @brief Manager polaczenia z lokalnym serwerem gry
     */
    QNetworkAccessManager *networkManager;
    /**
     * @brief Uchwyt do okna Ustawienia
     */
    Ustawienia* ust;
    /**
     * @brief Uchwyt do okna Autor
     */
    QSharedPointer<Author> auth;
    /**
     * @brief Uchwyt do okna Menu
     */
    Menu* menu;
    /**
     * @brief Odtwarzacz muzyki w tle
     */
    QMediaPlayer* player;
    /**
     * @brief Playlista z muzyka w tle
     */
    QMediaPlaylist* playlist;
    /**
     * @brief Wskaznik na tlo okna startowego
     */
    QMovie* gif;
    /**
     * @brief Czy okno powinno byc zainicjalizowane. true: tak, false: nie.
     */
    bool to_initialize;


};
#endif // START_H
