#ifndef USTAWIENIA_H
#define USTAWIENIA_H

#include <QDialog>
#include <QDebug>
#include <QFile>
namespace Ui {
class Ustawienia;
}

/**
 * @brief Okno pozwalajace dokonac zmian w ustawieniach programu
 */
class Ustawienia : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor klasy
     * @param parent: Widget rodzic
     * @param settings: Tablica z dotychczasowymi ustawieniami. Domyslnie 'nullptr'.
     */
    explicit Ustawienia(QWidget *parent = nullptr, QString settings[]= nullptr);
    ~Ustawienia();

private slots:
    /**
     * @brief Reakcja na nacisniecie przycisku zatwierdz. Aktualizacja ustawien okna i programu.
     */
    void on_button_apply_clicked();
private:
    /**
     * @brief ui
     */
    Ui::Ustawienia *ui;
};

#endif // USTAWIENIA_H
