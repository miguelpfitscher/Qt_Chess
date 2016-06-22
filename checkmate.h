#ifndef CHECKMATE_H
#define CHECKMATE_H

#include <QDialog>

namespace Ui {
class checkmate;
}

class checkmate : public QDialog
{
    Q_OBJECT

public:
    explicit checkmate(QWidget *parent = 0);
    ~checkmate();

private slots:
    void on_Novojogo_clicked();

    void on_Sair_clicked();

private:
    Ui::checkmate *ui;
};

#endif // CHECKMATE_H
