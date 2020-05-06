#ifndef EVENTS_WINDOW_H
#define EVENTS_WINDOW_H

#include <QDialog>
#include <QDebug>
namespace Ui {
class Events_window;
}

class Events_window : public QDialog
{
    Q_OBJECT

public:
    explicit Events_window(QWidget *parent = nullptr);
    ~Events_window();
private:
    Ui::Events_window *ui;

};

#endif // EVENTS_WINDOW_H
