#ifndef START_H
#define START_H

#include <QMainWindow>
#include <QPixmap>
#include <QSoundEffect>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMovie>
#include <QSize>
#include "ustawienia.h"
#include "author.h"
#include "menu.h"



QT_BEGIN_NAMESPACE
namespace Ui { class Start; }
QT_END_NAMESPACE

class Start : public QMainWindow
{
    Q_OBJECT

public:
    Start(QWidget *parent = nullptr);
    ~Start();
protected:
    virtual void resizeEvent(QResizeEvent *wZdarz);
private slots:
    void on_button_settings_clicked();

    void on_button_author_clicked();

    void on_button_connect_clicked();

private:
    Ui::Start *ui;
    QSharedPointer<QPixmap> pix;
    QSharedPointer<Ustawienia> ust;
    QSharedPointer<Author> auth;
    QSharedPointer<Menu> menu;
    QMediaPlayer* player;
    QMediaPlaylist* playlist;
    QMovie* gif;

};
#endif // START_H
