#include "tips_window.h"
#include "ui_tips_window.h"

Tips_window::Tips_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tips_window)
{
    ui->setupUi(this);
}

Tips_window::~Tips_window()
{
    delete ui;
}
