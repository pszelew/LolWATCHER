#include "enemy_window.h"
#include "ui_enemy_window.h"

Enemy_window::Enemy_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Enemy_window)
{
    ui->setupUi(this);
}

Enemy_window::~Enemy_window()
{
    delete ui;
}
