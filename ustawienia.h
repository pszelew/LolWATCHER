#ifndef USTAWIENIA_H
#define USTAWIENIA_H

#include <QDialog>

namespace Ui {
class Ustawienia;
}

class Ustawienia : public QDialog
{
    Q_OBJECT

public:
    explicit Ustawienia(QWidget *parent = nullptr);
    ~Ustawienia();

private:
    Ui::Ustawienia *ui;
};

#endif // USTAWIENIA_H
