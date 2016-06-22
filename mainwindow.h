#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QMainWindow>
#include "chess.h"
#include "ui_mainwindow.h"
#include "ui_checkmate.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_pushButton_07_clicked();
    void on_pushButton_00_clicked();
    void on_pushButton_06_clicked();
    void on_pushButton_05_clicked();
    void on_pushButton_04_clicked();
    void on_pushButton_03_clicked();
    void on_pushButton_02_clicked();
    void on_pushButton_01_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_27_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_26_clicked();
    void on_pushButton_25_clicked();
    void on_pushButton_24_clicked();
    void on_pushButton_23_clicked();
    void on_pushButton_22_clicked();
    void on_pushButton_21_clicked();
    void on_pushButton_37_clicked();
    void on_pushButton_30_clicked();
    void on_pushButton_36_clicked();
    void on_pushButton_35_clicked();
    void on_pushButton_34_clicked();
    void on_pushButton_33_clicked();
    void on_pushButton_32_clicked();
    void on_pushButton_31_clicked();
    void on_pushButton_47_clicked();
    void on_pushButton_40_clicked();
    void on_pushButton_46_clicked();
    void on_pushButton_45_clicked();
    void on_pushButton_44_clicked();
    void on_pushButton_43_clicked();
    void on_pushButton_42_clicked();
    void on_pushButton_41_clicked();
    void on_pushButton_57_clicked();
    void on_pushButton_50_clicked();
    void on_pushButton_56_clicked();
    void on_pushButton_55_clicked();
    void on_pushButton_54_clicked();
    void on_pushButton_53_clicked();
    void on_pushButton_52_clicked();
    void on_pushButton_51_clicked();
    void on_pushButton_67_clicked();
    void on_pushButton_60_clicked();
    void on_pushButton_66_clicked();
    void on_pushButton_65_clicked();
    void on_pushButton_64_clicked();
    void on_pushButton_63_clicked();
    void on_pushButton_62_clicked();
    void on_pushButton_61_clicked();
    void on_pushButton_77_clicked();
    void on_pushButton_70_clicked();
    void on_pushButton_76_clicked();
    void on_pushButton_75_clicked();
    void on_pushButton_74_clicked();
    void on_pushButton_73_clicked();
    void on_pushButton_72_clicked();
    void on_pushButton_71_clicked();
    //
    void on_toolButton_clicked();


    void on_actionNovo_triggered();

    void on_actionSair_triggered();

    void on_actionAbrir_triggered();

    void on_actionSalvar_triggered();

    void on_actionSalvar_como_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
