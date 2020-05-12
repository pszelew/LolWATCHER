#ifndef TIPS_WINDOW_H
#define TIPS_WINDOW_H

#include <QDialog>
#include <QRandomGenerator>
#include <QFile>
#include <QTextStream>
#include <QDebug>
namespace Ui {
class Tips_window;
}

class Tips_window : public QDialog
{
    Q_OBJECT

public:
    explicit Tips_window(QWidget *parent = nullptr);
    ~Tips_window();

private slots:
    void on_pushButton_tip_acc_clicked();

    void on_pushButton_tip_fun_clicked();

private:
    Ui::Tips_window *ui;
};

#endif // TIPS_WINDOW_H
