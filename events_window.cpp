#include "events_window.h"
#include "ui_events_window.h"

Events_window::Events_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Events_window)
{
    ui->setupUi(this);
}

Events_window::~Events_window()
{
    delete ui;
}
