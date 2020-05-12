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

class Events_window : public QDialog
{
    Q_OBJECT
public:
    explicit Events_window(QWidget *parent = nullptr);
    ~Events_window();
protected slots:
    void receive_data(QList<Event> data);

private:
    Ui::Events_window *ui;
    QVBoxLayout *layout_main;
    QGridLayout *layout_scroll;
    QWidget *widget_scroll;
    QScrollArea *scroll;

    QLabel *title;

    int current_event;
    int count_towers;
    int count_dragons;
    int count_barons;

};

#endif // EVENTS_WINDOW_H
