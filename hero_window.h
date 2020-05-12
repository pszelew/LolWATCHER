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

class Hero_window : public QDialog
{
    Q_OBJECT

public:
    explicit Hero_window(QWidget *parent = nullptr);
    ~Hero_window();
private slots:
    void receive_data(const Your_hero &hero);
    void on_pushButton_clicked();

private:
    Ui::Hero_window *ui;
    QSharedPointer<QPixmap> pix;
    QSharedPointer<QPixmap> pix_pass;
    QSharedPointer<QPixmap> pix_q;
    QSharedPointer<QPixmap> pix_w;
    QSharedPointer<QPixmap> pix_e;
    QSharedPointer<QPixmap> pix_r;
    QSharedPointer<QPixmap> pix_it0;
    QSharedPointer<QPixmap> pix_it1;
    QSharedPointer<QPixmap> pix_it2;
    QSharedPointer<QPixmap> pix_it3;
    QSharedPointer<QPixmap> pix_it4;
    QSharedPointer<QPixmap> pix_it5;
    QSharedPointer<QPixmap> pix_it6;

    int time_temp;

    QValueAxis *attack_axisX;
    QValueAxis *attack_axisY;
    QLineSeries* attack_series;
    QChart *attack_chart;
    QValueAxis *gold_axisX;
    QValueAxis *gold_axisY;
    QLineSeries* gold_series;
    QChart *gold_chart;
    QString current_hero;



};

#endif // HERO_WINDOW_H
