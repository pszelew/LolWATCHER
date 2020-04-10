#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QPixmap>
#include <QDebug>
#include <QTimer>
#include <QList>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QUrl>
#include <QFile>
#include <QGraphicsDropShadowEffect>
#include <algorithm>
#include <string>
#include <your_hero.h>
#include <hero_window.h>
#include <enemy_window.h>
#include <enemy.h>
#include <climits>
#include <QResizeEvent>

namespace Ui {
class Menu;
}



class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();
protected:
    virtual void resizeEvent(QResizeEvent *wZdarz);
protected slots:
     void update_json();
     void on_results(QNetworkReply *reply);
private slots:
     void on_button_your_hero_clicked();
     void on_splitter_splitterMoved(int pos, int index);
     void on_button_enemies_clicked();

private:
    Ui::Menu *ui;
    QSharedPointer<Hero_window> her;
    QSharedPointer<Enemy_window> enem;
    QSharedPointer<QPixmap> pix;
    QSharedPointer<QPixmap> pix_background;
    QPixmap* pix_enemies;
    QTimer *timer;
    QNetworkAccessManager *networkManager;
    QSharedPointer<Your_hero> your_hero;
    Enemy* enemies;
    int splitter_1_pos;
    int splitter_2_pos;
    bool to_initialize;

    QString url;
    QString port;
    QString language;
    int update_freq;
    int window_width;
    int window_height;
    bool maximized;

    int hero_width=0;
    int hero_height=0;

    void set_hero_width(int width){hero_width = width;};
    void set_hero_height(int height){hero_height = height;};

    int get_hero_width(){return hero_width;};
    int get_hero_height(){return hero_height;};

    bool check_if_enemy_changed(QString names[], double skin[]);
    int find_your_id(QJsonObject players[], QString name);

};

#endif // MENU_H
