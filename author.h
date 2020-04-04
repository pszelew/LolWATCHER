#ifndef AUTHOR_H
#define AUTHOR_H

#include <QDialog>
#include <QPixmap>
#include <QDebug>
namespace Ui {
class Author;
}

class Author : public QDialog
{
    Q_OBJECT

public:
    explicit Author(QWidget *parent = nullptr);
    ~Author();
protected:
     virtual void resizeEvent(QResizeEvent *wZdarz);
private slots:
    void on_splitter_splitterMoved(int pos, int index);

private:
    Ui::Author *ui;
    QSharedPointer<QPixmap> pix;
    QSharedPointer<QPixmap> pix_qt;
};

#endif // AUTHOR_H
