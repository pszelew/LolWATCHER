#ifndef YOUR_HERO_H
#define YOUR_HERO_H

#include <QDialog>

namespace Ui {
class Your_hero;
}

class Your_hero : public QDialog
{
    Q_OBJECT

public:
    explicit Your_hero(QWidget *parent = nullptr);
    ~Your_hero();

private:
    Ui::Your_hero *ui;
};

#endif // YOUR_HERO_H
