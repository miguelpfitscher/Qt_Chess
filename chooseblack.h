#ifndef CHOOSEBLACK_H
#define CHOOSEBLACK_H

#include <QDialog>

namespace Ui {
class chooseblack;
}

class chooseblack : public QDialog
{
    Q_OBJECT

public:
    explicit chooseblack(QWidget *parent = 0);
    ~chooseblack();
private slots:
    void on_bhorsebutton_clicked();

    void on_bbishopbutton_clicked();

    void on_btowerbutton_clicked();

    void on_bqueenbutton_clicked();
private:
    Ui::chooseblack *ui;
};

#endif // CHOOSEBLACK_H
