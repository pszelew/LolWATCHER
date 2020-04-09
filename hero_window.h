#ifndef HERO_WINDOW_H
#define HERO_WINDOW_H

#include <QDialog>

namespace Ui {
class Hero_window;
}

class Hero_window : public QDialog
{
    Q_OBJECT

public:
    explicit Hero_window(QWidget *parent = nullptr);
    ~Hero_window();

private:
    Ui::Hero_window *ui;
};

#endif // HERO_WINDOW_H
