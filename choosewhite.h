#ifndef CHOOSEWHITE_H
#define CHOOSEWHITE_H

#include <QDialog>

namespace Ui {
class choosewhite;
}

class choosewhite : public QDialog
{
    Q_OBJECT

public:
    explicit choosewhite(QWidget *parent = 0);
    ~choosewhite();

private slots:


    void on_whorsebutton_clicked();

    void on_wbishopbutton_clicked();

    void on_wtowerbutton_clicked();

    void on_wqueenbutton_clicked();

private:
    Ui::choosewhite *ui;
};

#endif // CHOOSEWHITE_H
