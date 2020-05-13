#include "tips_window.h"
#include "ui_tips_window.h"

Tips_window::Tips_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tips_window)
{
    ui->setupUi(this);
    ui->splitter->setSizes({ 50000, 50000 });
    ui->splitter_2->setSizes({ 50000, 50000 });
    ui->comboBox_tip_add->insertItem(0, "Gra");
    ui->comboBox_tip_add->insertItem(1, "Ciekawostka");

    ui->comboBox_tip_get->insertItem(0, "Gra");
    ui->comboBox_tip_get->insertItem(1, "Ciekawostka");
    ui->comboBox_tip_get->insertItem(2, "Twój bohater");
    ui->comboBox_tip_get->insertItem(3, "Bohaterowie przeciwników");
}

Tips_window::~Tips_window()
{
    delete ui;
}

void Tips_window::on_pushButton_tip_acc_clicked()
{
    int lenght;
    int rand_number;
    int rand_category;

    QString temp;
    QRandomGenerator generator = QRandomGenerator::securelySeeded();
    rand_category = generator.bounded(0,4);

    //podpowiedzi na temat samej rozgrywki
    if(rand_category == 0)
    {
        QFile tipsGame(QCoreApplication::applicationDirPath() + "/data/tips/tipsGame.txt");
        if (!tipsGame.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Nie udalo sie utworzyc pliku z podpowiedziami: data.conf";
            return;
        }

        QTextStream in(&tipsGame);
        lenght = in.readLine().toInt();
        rand_number = generator.bounded(0, lenght);
        for(int i=0; i<lenght;++i)
        {
            in.readLine();
            temp = in.readLine();
            if(i == rand_number)
                break;
        }
    }
    //ciekawostki
    else if(rand_category == 1)
    {
        QFile tipsGame(QCoreApplication::applicationDirPath() + "/data/tips/tipsFunFacts.txt");
        if (!tipsGame.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Nie udalo sie utworzyc pliku z podpowiedziami: data.conf";
            return;
        }
        QTextStream in(&tipsGame);
        lenght = in.readLine().toInt();
        rand_number = generator.bounded(0, lenght);
        for(int i=0; i<lenght;++i)
        {
            in.readLine();
            temp = in.readLine();
            if(i == rand_number)
                break;
        }
    }
    //nasz bohater
    else if(rand_category == 2)
    {
        QJsonArray tips = your_hero.get_hero_data().value("allytips").toArray();
        if(tips.size()>0)
        {
            rand_number = generator.bounded(0, tips.size());
            temp = your_hero.get_hero_name() + ": "+ tips.at(rand_number).toString();
        }
    }

    else if(rand_category == 3)
    {
        int temp_rand = generator.bounded(0, 5);
        QJsonArray tips = enemies[temp_rand].get_hero_data().value("allytips").toArray();
        if(tips.size()>0)
        {
            rand_number = generator.bounded(0, tips.size());
            temp = enemies[temp_rand].get_hero_name() + ": "+ tips.at(rand_number).toString();
        }
    }

    ui->label_tip_acc_val->setText("<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">" + temp + "</span></p></body></html>");

}

void Tips_window::on_pushButton_tip_fun_clicked()
{
    int lenght;
    int rand;
    QRandomGenerator generator = QRandomGenerator::securelySeeded();
    QString temp;
    QFile tipsGame(QCoreApplication::applicationDirPath() + "/data/tips/tipsFunFacts.txt");
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

void Tips_window::receive_data(const Tips_message &data)
{
    your_hero = data.your_hero;
    enemies = data.enemies;
}

void Tips_window::on_pushButton_tip_add_clicked()
{
    QString tip = ui->lineEdit_tip_add->text();
    QMessageBox::StandardButton reply;
    if(tip!="")
    {
        reply = QMessageBox::question(this, "Dodanie pytania", "Czy na pewno chcesz dodać swoją propozycję do bazy programu?",
                                       QMessageBox::Yes|QMessageBox::No);
    }


    if(tip!="" && reply== QMessageBox::Yes)
    {
        QString category;
        QFile file;
        int lenght;
        int index = ui->comboBox_tip_add->currentIndex();
        if(index == 0)
        {
            category = "Game";
        }
        else if(index == 1)
        {
            category = "FunFacts";
        }

        file.setFileName(QCoreApplication::applicationDirPath() + "/data/tips/tips"+ category +".txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Nie udalo sie utworzyc pliku z podpowiedziami";
            return;
        }

        QTextStream in(&file);
        lenght = in.readLine().toInt();
        file.close();


        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug() << "Nie udalo sie utworzyc pliku z podpowiedziami";
            return;
        }
        QTextStream out(&file);

        out << lenght+1<< "\n";
        for(int i=0;i<lenght;++i)
        {
            out << in.readLine() << "\n";
            out << in.readLine() << "\n";
        }
        out << "tip." + QString::number(lenght+1)+ "\n";
        out << tip << "\n";

        ui->lineEdit_tip_add->setText("");
    }
}


void Tips_window::on_pushButton_tip_get_clicked()
{
    int lenght;
    int rand_number;
    int category;

    QString temp;
    QRandomGenerator generator = QRandomGenerator::securelySeeded();
    category = ui->comboBox_tip_get->currentIndex();

    //podpowiedzi na temat samej rozgrywki
    if(category == 0)
    {
        QFile tipsGame(QCoreApplication::applicationDirPath() + "/data/tips/tipsGame.txt");
        if (!tipsGame.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Nie udalo sie utworzyc pliku z podpowiedziami: data.conf";
            return;
        }

        QTextStream in(&tipsGame);
        lenght = in.readLine().toInt();
        rand_number = generator.bounded(0, lenght);
        for(int i=0; i<lenght;++i)
        {
            in.readLine();
            temp = in.readLine();
            if(i == rand_number)
                break;
        }
    }
    //ciekawostki
    else if(category == 1)
    {
        QFile tipsGame(QCoreApplication::applicationDirPath() + "/data/tips/tipsFunFacts.txt");
        if (!tipsGame.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Nie udalo sie utworzyc pliku z podpowiedziami: data.conf";
            return;
        }
        QTextStream in(&tipsGame);
        lenght = in.readLine().toInt();
        rand_number = generator.bounded(0, lenght);
        for(int i=0; i<lenght;++i)
        {
            in.readLine();
            temp = in.readLine();
            if(i == rand_number)
                break;
        }
    }
    //nasz bohater
    else if(category == 2)
    {
        QJsonArray tips = your_hero.get_hero_data().value("allytips").toArray();
        if(tips.size()>0)
        {
            rand_number = generator.bounded(0, tips.size());
            temp = your_hero.get_hero_name() + ": "+ tips.at(rand_number).toString();
        }
    }

    else if(category == 3)
    {
        int temp_rand = generator.bounded(0, 5);
        QJsonArray tips = enemies[temp_rand].get_hero_data().value("allytips").toArray();
        if(tips.size()>0)
        {
            rand_number = generator.bounded(0, tips.size());
            temp = enemies[temp_rand].get_hero_name() + ": "+ tips.at(rand_number).toString();
        }
    }
    ui->label_tip_get_ans->setText("<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">" + temp + "</span></p></body></html>");
}
