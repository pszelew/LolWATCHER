#include "hero_window.h"
#include "ui_hero_window.h"

Hero_window::Hero_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hero_window)
{
    ui->setupUi(this);
}

Hero_window::~Hero_window()
{
    delete ui;
}
