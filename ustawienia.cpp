#include "ustawienia.h"
#include "ui_ustawienia.h"

Ustawienia::Ustawienia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ustawienia)
{
    ui->setupUi(this);
}

Ustawienia::~Ustawienia()
{
    delete ui;
}
