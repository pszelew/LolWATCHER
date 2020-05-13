#ifndef HERO_WINDOW_H
#define HERO_WINDOW_H
#include <QDialog>
#include <QDebug>
#include <your_hero.h>
#include <QPixmap>
#include <QLineSeries>
#include <QChart>
#include <QValueAxis>
#include <QDateTimeAxis>
#include <QRandomGenerator>
#include <QDesktopServices>
#include <QToolTip>

using namespace QtCharts;

namespace Ui {
class Hero_window;
}
/**
 * @brief Okno przedstawiajace informacje o bohaterze aktywnego gracza
 */
class Hero_window : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor klasy
     * @param parent: Widger rodzic
     */
    explicit Hero_window(QWidget *parent = nullptr);
    ~Hero_window();
private slots:
    /**
     * @brief Metoda odbierajaca informacje z okna Menu
     * @param hero: Odebrane informacje
     */
    void receive_data(const Your_hero &hero);
    /**
     * @brief Metoda bedaca reakcja na wcisniety przycisk. Przekierowuje do strony internetowej prezentujacej danego bohatera
     */
    void on_pushButton_clicked();

private:
    /**
     * @brief ui
     */
    Ui::Hero_window *ui;
    /**
     * @brief Grafika postaci
     */
    QSharedPointer<QPixmap> pix;
    /**
     * @brief Grafika umiejetnosci pasywnej
     */
    QSharedPointer<QPixmap> pix_pass;
    /**
     * @brief Grafika umiejetnosci q
     */
    QSharedPointer<QPixmap> pix_q;
    /**
     * @brief Grafika umiejetnosci w
     */
    QSharedPointer<QPixmap> pix_w;
    /**
     * @brief Grafika umiejetnosci e
     */
    QSharedPointer<QPixmap> pix_e;
    /**
     * @brief Grafika umiejetnosci r
     */
    QSharedPointer<QPixmap> pix_r;
    /**
     * @brief Grafika przedmioty 0.
     */
    QSharedPointer<QPixmap> pix_it0;
    /**
     * @brief Grafika przedmioty 1.
     */
    QSharedPointer<QPixmap> pix_it1;
    /**
     * @brief Grafika przedmiotu 2.
     */
    QSharedPointer<QPixmap> pix_it2;
    /**
     * @brief Grafika przedmiotu 3.
     */
    QSharedPointer<QPixmap> pix_it3;
    /**
     * @brief Grafika przedmiotu 4.
     */
    QSharedPointer<QPixmap> pix_it4;
    /**
     * @brief Grafika przedmiotu 5.
     */
    QSharedPointer<QPixmap> pix_it5;
    /**
     * @brief Grafika przedmiotu 6.
     */
    QSharedPointer<QPixmap> pix_it6;

    /**
     * @brief Wskaznik na os X wykresu Atak
     */
    QValueAxis *attack_axisX;
    /**
     * @brief Wskaznik na os Y wykresu Atak
     */
    QValueAxis *attack_axisY;
    /**
     * @brief Seria danych wykresu Atak
     */
    QLineSeries* attack_series;
    /**
     * @brief Wskaznik na wykres Atak
     */
    QChart *attack_chart;
    /**
     * @brief Wskaznik na os X wykresy Zloto
     */
    QValueAxis *gold_axisX;
    /**
     * @brief Wskaznik na os Y wykresu Zloto
     */
    QValueAxis *gold_axisY;
    /**
     * @brief Wskaznik na serie danych wykresu zloto
     */
    QLineSeries* gold_series;
    /**
     * @brief Wskaznik na wykres Zloto
     */
    QChart *gold_chart;
    /**
     * @brief Obecna ilosc zlota gracza
     */
    QString current_hero;

};

#endif // HERO_WINDOW_H
