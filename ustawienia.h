#ifndef USTAWIENIA_H
#define USTAWIENIA_H

#include <QDialog>
#include <QDebug>
#include <QFile>
namespace Ui {
class Ustawienia;
}

class Ustawienia : public QDialog
{
    Q_OBJECT

public:
    explicit Ustawienia(QWidget *parent = nullptr, QString settings[]= nullptr);
    ~Ustawienia();

private slots:
    void on_button_apply_clicked();
private:
    Ui::Ustawienia *ui;
};

#endif // USTAWIENIA_H
