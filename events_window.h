#ifndef EVENTS_WINDOW_H
#define EVENTS_WINDOW_H

#include <QDialog>
#include <QDebug>
#include <QList>
#include <event.h>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QScrollArea>
namespace Ui {
class Events_window;
}
/**
 * @brief Okno wyswietlajace wydarzenia podczas rozgrywki
 */
class Events_window : public QDialog
{
    Q_OBJECT
public:
    /**
     * @brief Konstruktor klasy
     * @param parent:
     */
    explicit Events_window(QWidget *parent = nullptr);
    ~Events_window();
protected slots:
    /**
     * @brief Metoda odbierajaca dane z okna Menu
     * @param data: Odebrane dane
     */
    void receive_data(QList<Event> data);
    /**
     * @brief Metoda resetuje eventy z aktualnej gry
     */
    void reset_game(){current_event = 0; delete(layout_scroll); layout_scroll = new QGridLayout();};
private:
    /**
     * @brief ui
     */
    Ui::Events_window *ui;
    /**
     * @brief Glowny layout okna
     */
    QVBoxLayout *layout_main;
    /**
     * @brief Layout obszaru SCROLL
     */
    QGridLayout *layout_scroll;
    /**
     * @brief Widget obszaru SCROLL
     */
    QWidget *widget_scroll;
    /**
     * @brief Obszar SCROLL
     */
    QScrollArea *scroll;

    /**
     * @brief Tytul okna
     */
    QLabel *title;
    /**
     * @brief ID najnowszego wydarzenia
     */
    int current_event;
};

#endif // EVENTS_WINDOW_H
