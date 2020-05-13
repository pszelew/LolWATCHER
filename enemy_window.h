#ifndef ENEMY_WINDOW_H
#define ENEMY_WINDOW_H

#include <QDialog>
#include <QDebug>
#include <enemy.h>
#include <QLabel>
#include <QDesktopServices>
#include <QUrl>
namespace Ui {
class Enemy_window;
}

/**
 * @brief Okno wyswietlajace informacje o przeciwnikach
 */
class Enemy_window : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor klasy
     * @param parent: Klasa rodzic
     */
    explicit Enemy_window(QWidget *parent = nullptr);
    ~Enemy_window();
protected:
    /**
     * @brief Event powiekszenia okna
     * @param wZdarz: Parametr powiekszenia
     */
    virtual void resizeEvent(QResizeEvent *wZdarz);
private slots:
    /**
     * @brief Metoda odbierajaca dane z okna Menu
     * @param heros
     */
    void receive_data(Enemy* heros);
    /**
     * @brief Reakcja na przycisk 1. bohatera. Otworzenie URL
     */
    void on_pushButton_1_clicked();
    /**
     * @brief Reakcja na przycisk 2. bohatera. Otworzenie URL
     */
    void on_pushButton_2_clicked();
    /**
     * @brief Reakcja na przycisk 3. bohatera. Otworzenie URL
     */
    void on_pushButton_3_clicked();
    /**
     * @brief Reakcja na przycisk 4. bohatera. Otworzenie URL
     */
    void on_pushButton_4_clicked();
    /**
     * @brief Reakcja na przycisk 5. bohatera. Otworzenie URL
     */
    void on_pushButton_5_clicked();

private:
    /**
     * @brief ui
     */
    Ui::Enemy_window *ui;
    /**
     * @brief Wskaznik na tablice grafik postaci przeciwnikow
     */
    QPixmap* pix_enemies;
    /**
     * @brief Wskaznik na tablice grafik przedmiotow przeciwnikow
     */
    QPixmap* pix_items;
    /**
     * @brief Wskaznik na tablice grafik czarow przywolywacza przeciwnikow
     */
    QPixmap* pix_spells;
    /**
     * @brief Wskaznik na wskaznik na labele przechowujace grafiki z przedmiotami
     */
    QLabel** label_items;
    /**
     * @brief Wskaznik na wskaznik na labele przechowujace grafiki z czarami przywolywacza
     */
    QLabel** label_spells;

};

#endif // ENEMY_WINDOW_H
