#include "author.h"
#include "ui_author.h"

Author::Author(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Author)
{
    ui->setupUi(this);

    //minimalna wielkosc okna
    this->setMinimumSize(300, 200);

    //ustawienie tla programu
    pix = QSharedPointer<QPixmap>(new QPixmap(":/images/img/profile.png"));
    //ustawienie ikony Qt
    pix_qt = QSharedPointer<QPixmap>(new QPixmap(":/images/img/QtIcon.png"));

    //ustawienia wstepne splitera
    auto equalWidth = std::max(ui->label_pict->minimumSizeHint().width(),
                               ui->label->minimumSizeHint().width());
    ui->splitter->setSizes({ equalWidth, equalWidth });

    int w = ui->label->width();
    int h = ui->label->height();

    qDebug() <<"w:"<< w<<"h: "<<h<<"\n";


    ui->label_pict->setPixmap(pix->scaled(w,h));
    ui->label_pict->resize(w,h);
}

Author::~Author()
{
    delete ui;
}

void Author::resizeEvent(QResizeEvent *wZdarz)
{
    int x = this->width();
    int y = this->height();

    int w = ui->label_pict->width();
    int h = ui->label_pict->height();
    //skalowanie zdjecia
    ui->label_pict->setPixmap(pix->scaled(w,h,Qt::KeepAspectRatio));



    //skalowanie ikony qt
    ui->label_qt->resize(0.2*x,0.1*y);
    w = ui->label_qt->width();
    h = ui->label_qt->height();
    ui->label_qt->setPixmap(pix_qt->scaled(w,h,Qt::KeepAspectRatio));


}

void Author::on_splitter_splitterMoved(int pos, int index)
{
    int w = ui->label_pict->width();
    int h = ui->label_pict->height();
    ui->label_pict->resize(w,h);
    ui->label_pict->setPixmap(pix->scaled(w,h,Qt::KeepAspectRatio));
}
