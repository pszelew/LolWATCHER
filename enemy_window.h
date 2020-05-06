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

class Enemy_window : public QDialog
{
    Q_OBJECT

public:
    explicit Enemy_window(QWidget *parent = nullptr);
    ~Enemy_window();
protected:
    virtual void resizeEvent(QResizeEvent *wZdarz);
private slots:
    void receive_data(Enemy* heros);
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Enemy_window *ui;
    QPixmap* pix_enemies;
    QPixmap* pix_items;
    QPixmap* pix_spells;
    QLabel** label_items;
    QLabel** label_spells;
    QString current_heros[5];


};

#endif // ENEMY_WINDOW_H
