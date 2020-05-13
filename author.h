#ifndef AUTHOR_H
#define AUTHOR_H

#include <QDialog>
#include <QPixmap>
#include <QDebug>

namespace Ui {
class Author;
}
/**
 * @brief Klasa okna przedstawiającego informacje o autorze oprogramowania
 */
class Author : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor klasy
     * @param parent : Widget rodzic
     */
    explicit Author(QWidget *parent = nullptr);
    ~Author();
protected:
    /**
      * @brief Event zmiany rozmiaru okna
      * @param wZdarz : Parametr zmiany rozmiaru
      */
     virtual void resizeEvent(QResizeEvent *wZdarz);
private slots:
    /**
     * @brief Slot zmiany położenia splittera
     * @param pos : Nowa pozycja splittera
     * @param index : Indeks uchwytu
     */
    void on_splitter_splitterMoved(int pos, int index);

private:
    /**
     * @brief ui
     */
    Ui::Author *ui;
    /**
     * @brief Pole przechowujace zdjecie autora
     */
    QSharedPointer<QPixmap> pix;
    /**
     * @brief Pole przechowujace logo Qt
     */
    QSharedPointer<QPixmap> pix_qt;
};

#endif // AUTHOR_H
