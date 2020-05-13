#ifndef TIPS_WINDOW_H
#define TIPS_WINDOW_H

#include <QDialog>
#include <QRandomGenerator>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <tips_message.h>
#include <enemy.h>
#include <QMessageBox>
namespace Ui {
class Tips_window;
}

/**
 * @brief Okno wyswietlajace informacje o podpowiedziach dla gracza
 */
class Tips_window : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor klasy
     * @param parent: Widget rodzic
     */
    explicit Tips_window(QWidget *parent = nullptr);
    ~Tips_window();
private slots:
    /**
     * @brief Reakcja na nacisniecie przycisku Aktualna Podpowiedz. Generuje losowa podpowiedz.
     */
    void on_pushButton_tip_acc_clicked();
    /**
     * @brief Reakcja na nacisniecie przycisku Ciekawostka. Generuje losowa ciekawostke.
     */
    void on_pushButton_tip_fun_clicked();
    /**
     * @brief Reakcja na nacisniecie przycisku Dodaj Podpowiedz. Dodaje podpowiedz do wybranej kategorii.
     */
    void on_pushButton_tip_add_clicked();
    /**
     * @brief Reakcja na nacisniecie przycisku Uzyskaj Podpowiedz. Generuje podpowiedz z wybranej kategorii.
     */
    void on_pushButton_tip_get_clicked();
    /**
     * @brief Metoda odpowiada za obsluzenie informacji otrzymanych z okna Menu.
     * @param data: Otrzymane informacje
     */
    void receive_data(const Tips_message &data);
private:
    /**
     * @brief ui
     */
    Ui::Tips_window *ui;
    /**
     * @brief Wskaznik na tablice przechwoujaca obiekty przeciwnikow
     */
    Enemy *enemies;
    /**
     * @brief Wskaznik obiekt aktywnego gracza
     */
    Your_hero your_hero;
};

#endif // TIPS_WINDOW_H
