#include "your_hero.h"
#include "ui_your_hero.h"

Your_hero::Your_hero(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Your_hero)
{
    ui->setupUi(this);
}

Your_hero::~Your_hero()
{
    delete ui;
}
