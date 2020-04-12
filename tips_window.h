#ifndef TIPS_WINDOW_H
#define TIPS_WINDOW_H

#include <QDialog>

namespace Ui {
class Tips_window;
}

class Tips_window : public QDialog
{
    Q_OBJECT

public:
    explicit Tips_window(QWidget *parent = nullptr);
    ~Tips_window();

private:
    Ui::Tips_window *ui;
};

#endif // TIPS_WINDOW_H
