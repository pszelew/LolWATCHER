#include "tips_window.h"
#include "ui_tips_window.h"

Tips_window::Tips_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tips_window)
{
    ui->setupUi(this);
    ui->splitter->setSizes({ 50000, 50000 });
    ui->splitter_2->setSizes({ 50000, 50000 });
    on_pushButton_tip_acc_clicked();
    on_pushButton_tip_fun_clicked();
    ui->comboBox_tip_add->insertItem(0, "Gra");
    ui->comboBox_tip_add->insertItem(1, "Postaci");
    ui->comboBox_tip_add->insertItem(2, "Ciekawostka");
}

Tips_window::~Tips_window()
{
    delete ui;
}

void Tips_window::on_pushButton_tip_acc_clicked()
{
    int lenght;
    int rand;
    QRandomGenerator generator = QRandomGenerator::securelySeeded();
    QString temp;
    QFile tipsGame(QCoreApplication::applicationDirPath() + "/data/tipsGame.txt");
    if (!tipsGame.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Nie udalo sie utworzyc pliku z podpowiedziami: data.conf";
        return;
    }
    QTextStream in(&tipsGame);
    lenght = in.readLine().toInt();
    rand = generator.bounded(0, lenght);
    for(int i=0; i<lenght;++i)
    {
        in.readLine();
        temp = in.readLine();
        if(i == rand)
            break;
    }

    ui->label_tip_acc_val->setText("<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">" + temp + "</span></p></body></html>");

}

void Tips_window::on_pushButton_tip_fun_clicked()
{
    int lenght;
    int rand;
    QRandomGenerator generator = QRandomGenerator::securelySeeded();
    QString temp;
    QFile tipsGame(QCoreApplication::applicationDirPath() + "/data/tipsFunFacts.txt");
    if (!tipsGame.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Nie udalo sie utworzyc pliku z podpowiedziami: data.conf";
        return;
    }
    QTextStream in(&tipsGame);
    lenght = in.readLine().toInt();
    rand = generator.bounded(0, lenght);
    for(int i=0; i<lenght;++i)
    {
        in.readLine();
        temp = in.readLine();
        if(i == rand)
            break;
    }

    ui->label_tip_fun_val->setText("<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">" + temp + "</span></p></body></html>");

}
