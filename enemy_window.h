#ifndef ENEMY_WINDOW_H
#define ENEMY_WINDOW_H

#include <QDialog>

namespace Ui {
class Enemy_window;
}

class Enemy_window : public QDialog
{
    Q_OBJECT

public:
    explicit Enemy_window(QWidget *parent = nullptr);
    ~Enemy_window();

private:
    Ui::Enemy_window *ui;
};

#endif // ENEMY_WINDOW_H
