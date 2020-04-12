#include "ustawienia.h"
#include "ui_ustawienia.h"

Ustawienia::Ustawienia(QWidget *parent, QString settings[]) :
    QDialog(parent),
    ui(new Ui::Ustawienia)
{
    ui->setupUi(this);
    ui->line_ip->setText(settings[0]);
    ui->line_port->setText(settings[1]);
    ui->line_lang->setText(settings[2]);
    ui->line_freq->setText(settings[3]);
    ui->line_width->setText(settings[4]);
    ui->line_height->setText(settings[5]);
    if(settings[6]=="true")
        ui->checkBox_max->setChecked(true);
    else
        ui->checkBox_max->setChecked(false);
    ui->line_api->setText(settings[7]);
}

Ustawienia::~Ustawienia()
{
    delete ui;
}

void Ustawienia::on_button_apply_clicked()
{
    QString ip = ui->line_ip->text();
    QString port = ui->line_port->text();
    QString lang = ui->line_lang->text();
    QString freq = ui->line_freq->text();
    QString width = ui->line_width->text();
    QString height = ui->line_height->text();
    QString api = ui->line_api->text();
    QString check;
    if(ui->checkBox_max->isChecked())
        check = "true";
    else
        check = "false";

    QFile data_conf("/home/patyk/QT_tutorial/Lolwatcher_0_1/data.conf");

    if (!data_conf.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Nie udalo sie utworzyc pliku z ustawieniami: data.conf";
        return;
    }

    QTextStream out(&data_conf);

    out << "ip = " << ip << "\n";
    out << "port = " << port << "\n";
    out << "language = " << lang << "\n";
    out << "update_freq = " << freq << "\n";
    out << "window_width = " << width << "\n";
    out << "window_height = " << height << "\n";
    out << "maximized = "<< check << "\n";
    out << "api_key = " <<api<<"\n";

    data_conf.close();
    this->finished(42);
}
