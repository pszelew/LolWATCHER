

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
#include <events_window.h>
#include <tips_window.h>
#include <enemy.h>
#include <climits>
#include <QResizeEvent>
#include <QStyle>
#include <QRandomGenerator>

namespace Ui {
class Menu;
}



class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();
    void set_hero_width(int width){hero_width = width;};
    void set_hero_height(int height){hero_height = height;};

    int get_hero_width(){return hero_width;};
    int get_hero_height(){return hero_height;};

    bool check_if_enemy_changed(QString names[], double skin[]);
    int find_your_id(QJsonObject players[], QString name);
protected:
    virtual void resizeEvent(QResizeEvent *wZdarz);
protected slots:

     void get_settings(QString *ust);
     void update_json();
     void on_results(QNetworkReply *reply);
     void on_resultsapiEn1(QNetworkReply *reply);
     void on_resultsapiEn2(QNetworkReply *reply);
     void on_resultsapiEn3(QNetworkReply *reply);
     void on_resultsapiEn4(QNetworkReply *reply);
     void on_resultsapiEn5(QNetworkReply *reply);

     void on_resultsmasteryEn1(QNetworkReply *reply);
     void on_resultsmasteryEn2(QNetworkReply *reply);
     void on_resultsmasteryEn3(QNetworkReply *reply);
     void on_resultsmasteryEn4(QNetworkReply *reply);
     void on_resultsmasteryEn5(QNetworkReply *reply);

     void onHeroWindowClosed(int results);
     void onEnemyWindowClosed(int results);
     void onEventsWindowClosed(int results);
     void onTipsWindowClosed(int results);

     void on_button_your_hero_clicked();
     void on_splitter_splitterMoved(int pos, int index);
     void on_button_enemies_clicked();
     void on_button_events_clicked();
     void on_button_tips_clicked();
signals:
     void update_hero(const Your_hero &data);
     void update_enemies(Enemy* data);
private:
    Ui::Menu *ui;
    Hero_window* her;
    Enemy_window* enem;
    Tips_window* tip;
    Events_window* eve;
    QSharedPointer<QPixmap> pix;
    QSharedPointer<QPixmap> pix_background;
    QPixmap* pix_enemies;
    QTimer *timer;
    QNetworkAccessManager *networkManager_apiEn1;
    QNetworkAccessManager *networkManager_apiEn2;
    QNetworkAccessManager *networkManager_apiEn3;
    QNetworkAccessManager *networkManager_apiEn4;
    QNetworkAccessManager *networkManager_apiEn5;
    QNetworkAccessManager *networkManager_masteryEn1;
    QNetworkAccessManager *networkManager_masteryEn2;
    QNetworkAccessManager *networkManager_masteryEn3;
    QNetworkAccessManager *networkManager_masteryEn4;
    QNetworkAccessManager *networkManager_masteryEn5;
    QNetworkAccessManager *networkManager;
    QSharedPointer<Your_hero> your_hero;
    Enemy* enemies;
    int splitter_1_pos;
    int splitter_2_pos;
    bool to_initialize;

    QString url;
    QString port;
    QString language;
    QString api_key;
    int update_freq;
    int window_width;
    int window_height;
    bool maximized;

    QString *settings;


    int hero_width=0;
    int hero_height=0;

};

#endif // MENU_H
