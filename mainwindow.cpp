#include "mainwindow.h"
//verde selecao( "* { background-color: rgb(124,252,0) }")
//branco ("* { background-color: rgb(255,255,255) }")
//cinza massa ("* { background-color: rgb(169,169,169)}")
Tabuleiro *tabu=new Tabuleiro;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{    
    ui->setupUi(this);
    ui->toolButton->click();
    ui->check->setPixmap(QPixmap(":/img/img/check.png"));
    ui->salvo->setPixmap(QPixmap(":/img/img/salvo.png"));

}


MainWindow::~MainWindow()
{
    delete ui;
}
checkmate::checkmate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkmate)
{    
    ui->setupUi(this);
    if(tabu->stalemate){
        ui->label->setPixmap(QPixmap(":/img/img/stalemate.png"));
    }else{
        ui->label->setPixmap(QPixmap(":/img/img/checkmate.png"));
    }
}
checkmate::~checkmate()
{
    tabu->fechou=true;
    delete ui;
}
void checkmate::on_Sair_clicked()
{
    tabu->fechou=true;
    checkmate::close();

}

void checkmate::on_Novojogo_clicked()
{

    checkmate::close();
    tabu->novojogo();

}
//
void choosewhite::on_whorsebutton_clicked()
{
    tabu->Mostratabul()[tabu->xn][tabu->yn]=3;
    tabu->escolheu=true;
    choosewhite::close();

}

void choosewhite::on_wbishopbutton_clicked()
{
    tabu->Mostratabul()[tabu->xn][tabu->yn]=5;
    tabu->escolheu=true;
    choosewhite::close();
}

void choosewhite::on_wtowerbutton_clicked()
{
    tabu->Mostratabul()[tabu->xn][tabu->yn]=7;
    tabu->escolheu=true;
    choosewhite::close();
}

void choosewhite::on_wqueenbutton_clicked()
{
    tabu->Mostratabul()[tabu->xn][tabu->yn]=9;
    tabu->escolheu=true;
    choosewhite::close();
}

choosewhite::~choosewhite()
{
    if(!tabu->escolheu){
        tabu->Mostratabul()[tabu->xn][tabu->yn]=3;
    }else{
        tabu->escolheu=false;
    }
    delete choosewhite::ui;
}

//
chooseblack::~chooseblack()
{
    if(!tabu->escolheu){
        tabu->Mostratabul()[tabu->xn][tabu->yn]=4;
    }else{
        tabu->escolheu=false;
    }
    delete chooseblack::ui;
}

void chooseblack::on_bhorsebutton_clicked()
{
    tabu->Mostratabul()[tabu->xn][tabu->yn]=4;
    tabu->escolheu=true;
    chooseblack::close();

}

void chooseblack::on_bbishopbutton_clicked()
{
    tabu->Mostratabul()[tabu->xn][tabu->yn]=6;
    tabu->escolheu=true;
    chooseblack::close();
}

void chooseblack::on_btowerbutton_clicked()
{
    tabu->Mostratabul()[tabu->xn][tabu->yn]=8;
    tabu->escolheu=true;
    chooseblack::close();
}

void chooseblack::on_bqueenbutton_clicked()
{
    tabu->Mostratabul()[tabu->xn][tabu->yn]=10;
    tabu->escolheu=true;
    chooseblack::close();
}
//
void MainWindow::on_pushButton_07_clicked()
{   
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=0;
            tabu->y=7;
            ui->pushButton_07->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;

        }else{
            tabu->xn=0;
            tabu->yn=7;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}


void MainWindow::on_pushButton_00_clicked()
{    
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=0;
            tabu->y=0;
            ui->pushButton_00->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=0;
            tabu->yn=0;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }

    }
}
void MainWindow::on_pushButton_01_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=0;
            tabu->y=1;
            ui->pushButton_01->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=0;
            tabu->yn=1;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }

    }
}
void MainWindow::on_pushButton_02_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=0;
            tabu->y=2;
            ui->pushButton_02->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=0;
            tabu->yn=2;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }

    }
}
void MainWindow::on_pushButton_03_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=0;
            tabu->y=3;
            ui->pushButton_03->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=0;
            tabu->yn=3;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }

    }
}
void MainWindow::on_pushButton_04_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=0;
            tabu->y=4;
            ui->pushButton_04->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=0;
            tabu->yn=4;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }

    }
}
void MainWindow::on_pushButton_05_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=0;
            tabu->y=5;
            ui->pushButton_05->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=0;
            tabu->yn=5;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }

    }
}
void MainWindow::on_pushButton_06_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=0;
            tabu->y=6;
            ui->pushButton_06->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=0;
            tabu->yn=6;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }

    }
}
//10
void MainWindow::on_pushButton_10_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=1;
            tabu->y=0;
            ui->pushButton_10->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=1;
            tabu->yn=0;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_11_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=1;
            tabu->y=1;
            ui->pushButton_11->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=1;
            tabu->yn=1;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_12_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=1;
            tabu->y=2;
            ui->pushButton_12->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=1;
            tabu->yn=2;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_13_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=1;
            tabu->y=3;
            ui->pushButton_13->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=1;
            tabu->yn=3;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_14_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=1;
            tabu->y=4;
            ui->pushButton_14->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=1;
            tabu->yn=4;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_15_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=1;
            tabu->y=5;
            ui->pushButton_15->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=1;
            tabu->yn=5;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_16_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=1;
            tabu->y=6;
            ui->pushButton_16->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=1;
            tabu->yn=6;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_17_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=1;
            tabu->y=7;
            ui->pushButton_17->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=1;
            tabu->yn=7;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
//20
void MainWindow::on_pushButton_20_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=2;
            tabu->y=0;
            ui->pushButton_20->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=2;
            tabu->yn=0;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_21_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=2;
            tabu->y=1;
            ui->pushButton_21->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=2;
            tabu->yn=1;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_22_clicked()
{

    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=2;
            tabu->y=2;
            ui->pushButton_22->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=2;
            tabu->yn=2;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }

    }
}
void MainWindow::on_pushButton_23_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=2;
            tabu->y=3;
            ui->pushButton_23->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=2;
            tabu->yn=3;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_24_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=2;
            tabu->y=4;
            ui->pushButton_24->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=2;
            tabu->yn=4;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_25_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=2;
            tabu->y=5;
            ui->pushButton_25->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=2;
            tabu->yn=5;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_26_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=2;
            tabu->y=6;
            ui->pushButton_26->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=2;
            tabu->yn=6;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_27_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=2;
            tabu->y=7;
            ui->pushButton_27->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=2;
            tabu->yn=7;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
//30
void MainWindow::on_pushButton_30_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=3;
            tabu->y=0;
            ui->pushButton_30->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=3;
            tabu->yn=0;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_31_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=3;
            tabu->y=1;
            ui->pushButton_31->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=3;
            tabu->yn=1;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_32_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=3;
            tabu->y=2;
            ui->pushButton_32->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=3;
            tabu->yn=2;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_33_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=3;
            tabu->y=3;
            ui->pushButton_33->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=3;
            tabu->yn=3;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_34_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=3;
            tabu->y=4;
            ui->pushButton_34->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=3;
            tabu->yn=4;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_35_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=3;
            tabu->y=5;
            ui->pushButton_35->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=3;
            tabu->yn=5;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_36_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=3;
            tabu->y=6;
            ui->pushButton_36->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=3;
            tabu->yn=6;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_37_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=3;
            tabu->y=7;
            ui->pushButton_37->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=3;
            tabu->yn=7;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
//40
void MainWindow::on_pushButton_40_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=4;
            tabu->y=0;
            ui->pushButton_40->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=4;
            tabu->yn=0;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_41_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=4;
            tabu->y=1;
            ui->pushButton_41->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=4;
            tabu->yn=1;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_42_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=4;
            tabu->y=2;
            ui->pushButton_42->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=4;
            tabu->yn=2;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_43_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=4;
            tabu->y=3;
            ui->pushButton_43->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=4;
            tabu->yn=3;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_44_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=4;
            tabu->y=4;
            ui->pushButton_44->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=4;
            tabu->yn=4;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_45_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=4;
            tabu->y=5;
            ui->pushButton_45->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=4;
            tabu->yn=5;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_46_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=4;
            tabu->y=6;
            ui->pushButton_46->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=4;
            tabu->yn=6;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_47_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=4;
            tabu->y=7;
            ui->pushButton_47->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=4;
            tabu->yn=7;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
//50
void MainWindow::on_pushButton_50_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=5;
            tabu->y=0;
            ui->pushButton_50->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=5;
            tabu->yn=0;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_51_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=5;
            tabu->y=1;
            ui->pushButton_51->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=5;
            tabu->yn=1;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_52_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=5;
            tabu->y=2;
            ui->pushButton_52->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=5;
            tabu->yn=2;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_53_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=5;
            tabu->y=3;
            ui->pushButton_53->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=5;
            tabu->yn=3;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_54_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=5;
            tabu->y=4;
            ui->pushButton_54->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=5;
            tabu->yn=4;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_55_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=5;
            tabu->y=5;
            ui->pushButton_55->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=5;
            tabu->yn=5;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_56_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=5;
            tabu->y=6;
            ui->pushButton_56->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=5;
            tabu->yn=6;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_57_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=5;
            tabu->y=7;
            ui->pushButton_57->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=5;
            tabu->yn=7;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
//60
void MainWindow::on_pushButton_60_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=6;
            tabu->y=0;
            ui->pushButton_60->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=6;
            tabu->yn=0;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_61_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=6;
            tabu->y=1;
            ui->pushButton_61->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=6;
            tabu->yn=1;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_62_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=6;
            tabu->y=2;
            ui->pushButton_62->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=6;
            tabu->yn=2;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_63_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=6;
            tabu->y=3;
            ui->pushButton_63->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=6;
            tabu->yn=3;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_64_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=6;
            tabu->y=4;
            ui->pushButton_64->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=6;
            tabu->yn=4;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_65_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=6;
            tabu->y=5;
            ui->pushButton_65->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=6;
            tabu->yn=5;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_66_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=6;
            tabu->y=6;
            ui->pushButton_66->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=6;
            tabu->yn=6;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_67_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=6;
            tabu->y=7;
            ui->pushButton_67->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=6;
            tabu->yn=7;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
//70
void MainWindow::on_pushButton_70_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=7;
            tabu->y=0;
            ui->pushButton_70->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=7;
            tabu->yn=0;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_71_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=7;
            tabu->y=1;
            ui->pushButton_71->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=7;
            tabu->yn=1;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_72_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=7;
            tabu->y=2;
            ui->pushButton_72->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=7;
            tabu->yn=2;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_73_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=7;
            tabu->y=3;
            ui->pushButton_73->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=7;
            tabu->yn=3;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_74_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=7;
            tabu->y=4;
            ui->pushButton_74->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=7;
            tabu->yn=4;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_75_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=7;
            tabu->y=5;
            ui->pushButton_75->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=7;
            tabu->yn=5;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_76_clicked()
{
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=7;
            tabu->y=6;
            ui->pushButton_76->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=7;
            tabu->yn=6;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}
void MainWindow::on_pushButton_77_clicked()
{    
    if(!tabu->fechou){
        if(tabu->sel){
            tabu->x=7;
            tabu->y=7;
            ui->pushButton_77->setStyleSheet("* { background-color: rgb(124,252,0) }");
            tabu->sel=false;
        }else{
            tabu->xn=7;
            tabu->yn=7;
            tabu->pecaanda();
            ui->toolButton->click();
            tabu->sel=true;
        }
    }
}

void MainWindow::on_toolButton_clicked()
{

    ui->salvo->setVisible(false);
    ui->check->setVisible(tabu->check);
    tabu->check=false;
    //

    if(tabu->numb.value(0)==2){
        ui->mat_b01->setPixmap(QPixmap(":/img/img/minibpeao.png"));
    }else if(tabu->numb.value(0)==4){
        ui->mat_b01->setPixmap(QPixmap(":/img/img/minibhorse.png"));
    }else if(tabu->numb.value(0)==6){
        ui->mat_b01->setPixmap(QPixmap(":/img/img/minibbishop.png"));
    }else if(tabu->numb.value(0)==8){
        ui->mat_b01->setPixmap(QPixmap(":/img/img/minibtower.png"));
    }else if(tabu->numb.value(0)==10){
        ui->mat_b01->setPixmap(QPixmap(":/img/img/minibqueen.png"));
    }else{
        ui->mat_b01->setPixmap(QPixmap(""));
    }

    if(tabu->numb.value(1)==2){
        ui->mat_b02->setPixmap(QPixmap(":/img/img/minibpeao.png"));
    }else if(tabu->numb.value(1)==4){
        ui->mat_b02->setPixmap(QPixmap(":/img/img/minibhorse.png"));
    }else if(tabu->numb.value(1)==6){
        ui->mat_b02->setPixmap(QPixmap(":/img/img/minibbishop.png"));
    }else if(tabu->numb.value(1)==8){
        ui->mat_b02->setPixmap(QPixmap(":/img/img/minibtower.png"));
    }else if(tabu->numb.value(1)==10){
        ui->mat_b02->setPixmap(QPixmap(":/img/img/minibqueen.png"));
    }else{
        ui->mat_b02->setPixmap(QPixmap(""));
    }

    if(tabu->numb.value(2)==2){
        ui->mat_b03->setPixmap(QPixmap(":/img/img/minibpeao.png"));
    }else if(tabu->numb.value(2)==4){
        ui->mat_b03->setPixmap(QPixmap(":/img/img/minibhorse.png"));
    }else if(tabu->numb.value(2)==6){
        ui->mat_b03->setPixmap(QPixmap(":/img/img/minibbishop.png"));
    }else if(tabu->numb.value(2)==8){
        ui->mat_b03->setPixmap(QPixmap(":/img/img/minibtower.png"));
    }else if(tabu->numb.value(2)==10){
        ui->mat_b03->setPixmap(QPixmap(":/img/img/minibqueen.png"));
    }else{
        ui->mat_b03->setPixmap(QPixmap(""));
    }

    if(tabu->numb.value(3)==2){
        ui->mat_b04->setPixmap(QPixmap(":/img/img/minibpeao.png"));
    }else if(tabu->numb.value(3)==4){
        ui->mat_b04->setPixmap(QPixmap(":/img/img/minibhorse.png"));
    }else if(tabu->numb.value(3)==6){
        ui->mat_b04->setPixmap(QPixmap(":/img/img/minibbishop.png"));
    }else if(tabu->numb.value(3)==8){
        ui->mat_b04->setPixmap(QPixmap(":/img/img/minibtower.png"));
    }else if(tabu->numb.value(3)==10){
        ui->mat_b04->setPixmap(QPixmap(":/img/img/minibqueen.png"));
    }else{
        ui->mat_b04->setPixmap(QPixmap(""));
    }

    if(tabu->numb.value(4)==2){
        ui->mat_b05->setPixmap(QPixmap(":/img/img/minibpeao.png"));
    }else if(tabu->numb.value(4)==4){
        ui->mat_b05->setPixmap(QPixmap(":/img/img/minibhorse.png"));
    }else if(tabu->numb.value(4)==6){
        ui->mat_b05->setPixmap(QPixmap(":/img/img/minibbishop.png"));
    }else if(tabu->numb.value(4)==8){
        ui->mat_b05->setPixmap(QPixmap(":/img/img/minibtower.png"));
    }else if(tabu->numb.value(4)==10){
        ui->mat_b05->setPixmap(QPixmap(":/img/img/minibqueen.png"));
    }else{
        ui->mat_b05->setPixmap(QPixmap(""));
    }

    if(tabu->numb.value(5)==2){
        ui->mat_b06->setPixmap(QPixmap(":/img/img/minibpeao.png"));
    }else if(tabu->numb.value(5)==4){
        ui->mat_b06->setPixmap(QPixmap(":/img/img/minibhorse.png"));
    }else if(tabu->numb.value(5)==6){
        ui->mat_b06->setPixmap(QPixmap(":/img/img/minibbishop.png"));
    }else if(tabu->numb.value(5)==8){
        ui->mat_b06->setPixmap(QPixmap(":/img/img/minibtower.png"));
    }else if(tabu->numb.value(5)==10){
        ui->mat_b06->setPixmap(QPixmap(":/img/img/minibqueen.png"));
    }else{
        ui->mat_b06->setPixmap(QPixmap(""));
    }

    if(tabu->numb.value(6)==2){
        ui->mat_b07->setPixmap(QPixmap(":/img/img/minibpeao.png"));
    }else if(tabu->numb.value(6)==4){
        ui->mat_b07->setPixmap(QPixmap(":/img/img/minibhorse.png"));
    }else if(tabu->numb.value(6)==6){
        ui->mat_b07->setPixmap(QPixmap(":/img/img/minibbishop.png"));
    }else if(tabu->numb.value(6)==8){
        ui->mat_b07->setPixmap(QPixmap(":/img/img/minibtower.png"));
    }else if(tabu->numb.value(6)==10){
        ui->mat_b07->setPixmap(QPixmap(":/img/img/minibqueen.png"));
    }else{
        ui->mat_b07->setPixmap(QPixmap(""));
    }

    if(tabu->numb.value(7)==2){
        ui->mat_b08->setPixmap(QPixmap(":/img/img/minibpeao.png"));
    }else if(tabu->numb.value(7)==4){
        ui->mat_b08->setPixmap(QPixmap(":/img/img/minibhorse.png"));
    }else if(tabu->numb.value(7)==6){
        ui->mat_b08->setPixmap(QPixmap(":/img/img/minibbishop.png"));
    }else if(tabu->numb.value(7)==8){
        ui->mat_b08->setPixmap(QPixmap(":/img/img/minibtower.png"));
    }else if(tabu->numb.value(7)==10){
        ui->mat_b08->setPixmap(QPixmap(":/img/img/minibqueen.png"));
    }else{
        ui->mat_b08->setPixmap(QPixmap(""));
    }

    if(tabu->numb.value(8)==2){
        ui->mat_b09->setPixmap(QPixmap(":/img/img/minibpeao.png"));
    }else if(tabu->numb.value(8)==4){
        ui->mat_b09->setPixmap(QPixmap(":/img/img/minibhorse.png"));
    }else if(tabu->numb.value(8)==6){
        ui->mat_b09->setPixmap(QPixmap(":/img/img/minibbishop.png"));
    }else if(tabu->numb.value(8)==8){
        ui->mat_b09->setPixmap(QPixmap(":/img/img/minibtower.png"));
    }else if(tabu->numb.value(8)==10){
        ui->mat_b09->setPixmap(QPixmap(":/img/img/minibqueen.png"));
    }else{
        ui->mat_b09->setPixmap(QPixmap(""));
    }

    if(tabu->numb.value(9)==2){
        ui->mat_b10->setPixmap(QPixmap(":/img/img/minibpeao.png"));
    }else if(tabu->numb.value(9)==4){
        ui->mat_b10->setPixmap(QPixmap(":/img/img/minibhorse.png"));
    }else if(tabu->numb.value(9)==6){
        ui->mat_b10->setPixmap(QPixmap(":/img/img/minibbishop.png"));
    }else if(tabu->numb.value(9)==8){
        ui->mat_b10->setPixmap(QPixmap(":/img/img/minibtower.png"));
    }else if(tabu->numb.value(9)==10){
        ui->mat_b10->setPixmap(QPixmap(":/img/img/minibqueen.png"));
    }else{
        ui->mat_b10->setPixmap(QPixmap(""));
    }

    if(tabu->numb.value(10)==2){
        ui->mat_b11->setPixmap(QPixmap(":/img/img/minibpeao.png"));
    }else if(tabu->numb.value(10)==4){
        ui->mat_b11->setPixmap(QPixmap(":/img/img/minibhorse.png"));
    }else if(tabu->numb.value(10)==6){
        ui->mat_b11->setPixmap(QPixmap(":/img/img/minibbishop.png"));
    }else if(tabu->numb.value(10)==8){
        ui->mat_b11->setPixmap(QPixmap(":/img/img/minibtower.png"));
    }else if(tabu->numb.value(10)==10){
        ui->mat_b11->setPixmap(QPixmap(":/img/img/minibqueen.png"));
    }else{
        ui->mat_b11->setPixmap(QPixmap(""));
    }

    if(tabu->numb.value(11)==2){
        ui->mat_b12->setPixmap(QPixmap(":/img/img/minibpeao.png"));
    }else if(tabu->numb.value(11)==4){
        ui->mat_b12->setPixmap(QPixmap(":/img/img/minibhorse.png"));
    }else if(tabu->numb.value(11)==6){
        ui->mat_b12->setPixmap(QPixmap(":/img/img/minibbishop.png"));
    }else if(tabu->numb.value(11)==8){
        ui->mat_b12->setPixmap(QPixmap(":/img/img/minibtower.png"));
    }else if(tabu->numb.value(11)==10){
        ui->mat_b12->setPixmap(QPixmap(":/img/img/minibqueen.png"));
    }else{
        ui->mat_b12->setPixmap(QPixmap(""));
    }

    if(tabu->numb.value(12)==2){
        ui->mat_b13->setPixmap(QPixmap(":/img/img/minibpeao.png"));
    }else if(tabu->numb.value(12)==4){
        ui->mat_b13->setPixmap(QPixmap(":/img/img/minibhorse.png"));
    }else if(tabu->numb.value(12)==6){
        ui->mat_b13->setPixmap(QPixmap(":/img/img/minibbishop.png"));
    }else if(tabu->numb.value(12)==8){
        ui->mat_b13->setPixmap(QPixmap(":/img/img/minibtower.png"));
    }else if(tabu->numb.value(12)==10){
        ui->mat_b13->setPixmap(QPixmap(":/img/img/minibqueen.png"));
    }else{
        ui->mat_b13->setPixmap(QPixmap(""));
    }

    if(tabu->numb.value(13)==2){
        ui->mat_b14->setPixmap(QPixmap(":/img/img/minibpeao.png"));
    }else if(tabu->numb.value(13)==4){
        ui->mat_b14->setPixmap(QPixmap(":/img/img/minibhorse.png"));
    }else if(tabu->numb.value(13)==6){
        ui->mat_b14->setPixmap(QPixmap(":/img/img/minibbishop.png"));
    }else if(tabu->numb.value(13)==8){
        ui->mat_b14->setPixmap(QPixmap(":/img/img/minibtower.png"));
    }else if(tabu->numb.value(13)==10){
        ui->mat_b14->setPixmap(QPixmap(":/img/img/minibqueen.png"));
    }else{
        ui->mat_b14->setPixmap(QPixmap(""));
    }

    if(tabu->numb.value(14)==2){
        ui->mat_b15->setPixmap(QPixmap(":/img/img/minibpeao.png"));
    }else if(tabu->numb.value(14)==4){
        ui->mat_b15->setPixmap(QPixmap(":/img/img/minibhorse.png"));
    }else if(tabu->numb.value(14)==6){
        ui->mat_b15->setPixmap(QPixmap(":/img/img/minibbishop.png"));
    }else if(tabu->numb.value(14)==8){
        ui->mat_b15->setPixmap(QPixmap(":/img/img/minibtower.png"));
    }else if(tabu->numb.value(14)==10){
        ui->mat_b15->setPixmap(QPixmap(":/img/img/minibqueen.png"));
    }else{
        ui->mat_b15->setPixmap(QPixmap(""));
    }

    if(tabu->numb.value(15)==2){
        ui->mat_b16->setPixmap(QPixmap(":/img/img/minibpeao.png"));
    }else if(tabu->numb.value(15)==4){
        ui->mat_b16->setPixmap(QPixmap(":/img/img/minibhorse.png"));
    }else if(tabu->numb.value(15)==6){
        ui->mat_b16->setPixmap(QPixmap(":/img/img/minibbishop.png"));
    }else if(tabu->numb.value(15)==8){
        ui->mat_b16->setPixmap(QPixmap(":/img/img/minibtower.png"));
    }else if(tabu->numb.value(15)==10){
        ui->mat_b16->setPixmap(QPixmap(":/img/img/minibqueen.png"));
    }else{
        ui->mat_b16->setPixmap(QPixmap(""));
    }



    if(tabu->nump.value(0)==1){
        ui->mat_p01->setPixmap(QPixmap(":/img/img/miniwpeao.png"));
    }else if(tabu->nump.value(0)==3){
        ui->mat_p01->setPixmap(QPixmap(":/img/img/miniwhorse.png"));
    }else if(tabu->nump.value(0)==5){
        ui->mat_p01->setPixmap(QPixmap(":/img/img/miniwbishop.png"));
    }else if(tabu->nump.value(0)==7){
        ui->mat_p01->setPixmap(QPixmap(":/img/img/miniwtower.png"));
    }else if(tabu->nump.value(0)==9){
        ui->mat_p01->setPixmap(QPixmap(":/img/img/miniwqueen.png"));
    }else{
        ui->mat_p01->setPixmap(QPixmap(""));
    }

    if(tabu->nump.value(1)==1){
        ui->mat_p02->setPixmap(QPixmap(":/img/img/miniwpeao.png"));
    }else if(tabu->nump.value(1)==3){
        ui->mat_p02->setPixmap(QPixmap(":/img/img/miniwhorse.png"));
    }else if(tabu->nump.value(1)==5){
        ui->mat_p02->setPixmap(QPixmap(":/img/img/miniwbishop.png"));
    }else if(tabu->nump.value(1)==7){
        ui->mat_p02->setPixmap(QPixmap(":/img/img/miniwtower.png"));
    }else if(tabu->nump.value(1)==9){
        ui->mat_p02->setPixmap(QPixmap(":/img/img/miniwqueen.png"));
    }else{
        ui->mat_p02->setPixmap(QPixmap(""));
    }

    if(tabu->nump.value(2)==1){
        ui->mat_p03->setPixmap(QPixmap(":/img/img/miniwpeao.png"));
    }else if(tabu->nump.value(2)==3){
        ui->mat_p03->setPixmap(QPixmap(":/img/img/miniwhorse.png"));
    }else if(tabu->nump.value(2)==5){
        ui->mat_p03->setPixmap(QPixmap(":/img/img/miniwbishop.png"));
    }else if(tabu->nump.value(2)==7){
        ui->mat_p03->setPixmap(QPixmap(":/img/img/miniwtower.png"));
    }else if(tabu->nump.value(2)==9){
        ui->mat_p03->setPixmap(QPixmap(":/img/img/miniwqueen.png"));
    }else{
        ui->mat_p03->setPixmap(QPixmap(""));
    }

    if(tabu->nump.value(3)==1){
        ui->mat_p04->setPixmap(QPixmap(":/img/img/miniwpeao.png"));
    }else if(tabu->nump.value(3)==3){
        ui->mat_p04->setPixmap(QPixmap(":/img/img/miniwhorse.png"));
    }else if(tabu->nump.value(3)==5){
        ui->mat_p04->setPixmap(QPixmap(":/img/img/miniwbishop.png"));
    }else if(tabu->nump.value(3)==7){
        ui->mat_p04->setPixmap(QPixmap(":/img/img/miniwtower.png"));
    }else if(tabu->nump.value(3)==9){
        ui->mat_p04->setPixmap(QPixmap(":/img/img/miniwqueen.png"));
    }else{
        ui->mat_p04->setPixmap(QPixmap(""));
    }

    if(tabu->nump.value(4)==1){
        ui->mat_p05->setPixmap(QPixmap(":/img/img/miniwpeao.png"));
    }else if(tabu->nump.value(4)==3){
        ui->mat_p05->setPixmap(QPixmap(":/img/img/miniwhorse.png"));
    }else if(tabu->nump.value(4)==5){
        ui->mat_p05->setPixmap(QPixmap(":/img/img/miniwbishop.png"));
    }else if(tabu->nump.value(4)==7){
        ui->mat_p05->setPixmap(QPixmap(":/img/img/miniwtower.png"));
    }else if(tabu->nump.value(4)==9){
        ui->mat_p05->setPixmap(QPixmap(":/img/img/miniwqueen.png"));
    }else{
        ui->mat_p05->setPixmap(QPixmap(""));
    }

    if(tabu->nump.value(5)==1){
        ui->mat_p06->setPixmap(QPixmap(":/img/img/miniwpeao.png"));
    }else if(tabu->nump.value(5)==3){
        ui->mat_p06->setPixmap(QPixmap(":/img/img/miniwhorse.png"));
    }else if(tabu->nump.value(5)==5){
        ui->mat_p06->setPixmap(QPixmap(":/img/img/miniwbishop.png"));
    }else if(tabu->nump.value(5)==7){
        ui->mat_p06->setPixmap(QPixmap(":/img/img/miniwtower.png"));
    }else if(tabu->nump.value(5)==9){
        ui->mat_p06->setPixmap(QPixmap(":/img/img/miniwqueen.png"));
    }else{
        ui->mat_p06->setPixmap(QPixmap(""));
    }

    if(tabu->nump.value(6)==1){
        ui->mat_p07->setPixmap(QPixmap(":/img/img/miniwpeao.png"));
    }else if(tabu->nump.value(6)==3){
        ui->mat_p07->setPixmap(QPixmap(":/img/img/miniwhorse.png"));
    }else if(tabu->nump.value(6)==5){
        ui->mat_p07->setPixmap(QPixmap(":/img/img/miniwbishop.png"));
    }else if(tabu->nump.value(6)==7){
        ui->mat_p07->setPixmap(QPixmap(":/img/img/miniwtower.png"));
    }else if(tabu->nump.value(6)==9){
        ui->mat_p07->setPixmap(QPixmap(":/img/img/miniwqueen.png"));
    }else{
        ui->mat_p07->setPixmap(QPixmap(""));
    }

    if(tabu->nump.value(7)==1){
        ui->mat_p08->setPixmap(QPixmap(":/img/img/miniwpeao.png"));
    }else if(tabu->nump.value(7)==3){
        ui->mat_p08->setPixmap(QPixmap(":/img/img/miniwhorse.png"));
    }else if(tabu->nump.value(7)==5){
        ui->mat_p08->setPixmap(QPixmap(":/img/img/miniwbishop.png"));
    }else if(tabu->nump.value(7)==7){
        ui->mat_p08->setPixmap(QPixmap(":/img/img/miniwtower.png"));
    }else if(tabu->nump.value(7)==9){
        ui->mat_p08->setPixmap(QPixmap(":/img/img/miniwqueen.png"));
    }else{
        ui->mat_p08->setPixmap(QPixmap(""));
    }

    if(tabu->nump.value(8)==1){
        ui->mat_p09->setPixmap(QPixmap(":/img/img/miniwpeao.png"));
    }else if(tabu->nump.value(8)==3){
        ui->mat_p09->setPixmap(QPixmap(":/img/img/miniwhorse.png"));
    }else if(tabu->nump.value(8)==5){
        ui->mat_p09->setPixmap(QPixmap(":/img/img/miniwbishop.png"));
    }else if(tabu->nump.value(8)==7){
        ui->mat_p09->setPixmap(QPixmap(":/img/img/miniwtower.png"));
    }else if(tabu->nump.value(8)==9){
        ui->mat_p09->setPixmap(QPixmap(":/img/img/miniwqueen.png"));
    }else{
        ui->mat_p09->setPixmap(QPixmap(""));
    }

    if(tabu->nump.value(9)==1){
        ui->mat_p10->setPixmap(QPixmap(":/img/img/miniwpeao.png"));
    }else if(tabu->nump.value(9)==3){
        ui->mat_p10->setPixmap(QPixmap(":/img/img/miniwhorse.png"));
    }else if(tabu->nump.value(9)==5){
        ui->mat_p10->setPixmap(QPixmap(":/img/img/miniwbishop.png"));
    }else if(tabu->nump.value(9)==7){
        ui->mat_p10->setPixmap(QPixmap(":/img/img/miniwtower.png"));
    }else if(tabu->nump.value(9)==9){
        ui->mat_p10->setPixmap(QPixmap(":/img/img/miniwqueen.png"));
    }else{
        ui->mat_p10->setPixmap(QPixmap(""));
    }

    if(tabu->nump.value(10)==1){
        ui->mat_p11->setPixmap(QPixmap(":/img/img/miniwpeao.png"));
    }else if(tabu->nump.value(10)==3){
        ui->mat_p11->setPixmap(QPixmap(":/img/img/miniwhorse.png"));
    }else if(tabu->nump.value(10)==5){
        ui->mat_p11->setPixmap(QPixmap(":/img/img/miniwbishop.png"));
    }else if(tabu->nump.value(10)==7){
        ui->mat_p11->setPixmap(QPixmap(":/img/img/miniwtower.png"));
    }else if(tabu->nump.value(10)==9){
        ui->mat_p11->setPixmap(QPixmap(":/img/img/miniwqueen.png"));
    }else{
        ui->mat_p11->setPixmap(QPixmap(""));
    }

    if(tabu->nump.value(11)==1){
        ui->mat_p12->setPixmap(QPixmap(":/img/img/miniwpeao.png"));
    }else if(tabu->nump.value(11)==3){
        ui->mat_p12->setPixmap(QPixmap(":/img/img/miniwhorse.png"));
    }else if(tabu->nump.value(11)==5){
        ui->mat_p12->setPixmap(QPixmap(":/img/img/miniwbishop.png"));
    }else if(tabu->nump.value(11)==7){
        ui->mat_p12->setPixmap(QPixmap(":/img/img/miniwtower.png"));
    }else if(tabu->nump.value(11)==9){
        ui->mat_p12->setPixmap(QPixmap(":/img/img/miniwqueen.png"));
    }else{
        ui->mat_p12->setPixmap(QPixmap(""));
    }

    if(tabu->nump.value(12)==1){
        ui->mat_p13->setPixmap(QPixmap(":/img/img/miniwpeao.png"));
    }else if(tabu->nump.value(12)==3){
        ui->mat_p13->setPixmap(QPixmap(":/img/img/miniwhorse.png"));
    }else if(tabu->nump.value(12)==5){
        ui->mat_p13->setPixmap(QPixmap(":/img/img/miniwbishop.png"));
    }else if(tabu->nump.value(12)==7){
        ui->mat_p13->setPixmap(QPixmap(":/img/img/miniwtower.png"));
    }else if(tabu->nump.value(12)==9){
        ui->mat_p13->setPixmap(QPixmap(":/img/img/miniwqueen.png"));
    }
    else{
        ui->mat_p13->setPixmap(QPixmap(""));
    }

    if(tabu->nump.value(13)==1){
        ui->mat_p14->setPixmap(QPixmap(":/img/img/miniwpeao.png"));
    }else if(tabu->nump.value(13)==3){
        ui->mat_p14->setPixmap(QPixmap(":/img/img/miniwhorse.png"));
    }else if(tabu->nump.value(13)==5){
        ui->mat_p14->setPixmap(QPixmap(":/img/img/miniwbishop.png"));
    }else if(tabu->nump.value(13)==7){
        ui->mat_p14->setPixmap(QPixmap(":/img/img/miniwtower.png"));
    }else if(tabu->nump.value(13)==9){
        ui->mat_p14->setPixmap(QPixmap(":/img/img/miniwqueen.png"));
    }else{
        ui->mat_p14->setPixmap(QPixmap(""));
    }

    if(tabu->nump.value(14)==1){
        ui->mat_p15->setPixmap(QPixmap(":/img/img/miniwpeao.png"));
    }else if(tabu->nump.value(14)==3){
        ui->mat_p15->setPixmap(QPixmap(":/img/img/miniwhorse.png"));
    }else if(tabu->nump.value(14)==5){
        ui->mat_p15->setPixmap(QPixmap(":/img/img/miniwbishop.png"));
    }else if(tabu->nump.value(14)==7){
        ui->mat_p15->setPixmap(QPixmap(":/img/img/miniwtower.png"));
    }else if(tabu->nump.value(14)==9){
        ui->mat_p15->setPixmap(QPixmap(":/img/img/miniwqueen.png"));
    }else{
        ui->mat_p15->setPixmap(QPixmap(""));
    }


    if(tabu->nump.value(15)==1){
        ui->mat_p16->setPixmap(QPixmap(":/img/img/miniwpeao.png"));
    }else if(tabu->nump.value(15)==3){
        ui->mat_p16->setPixmap(QPixmap(":/img/img/miniwhorse.png"));
    }else if(tabu->nump.value(15)==5){
        ui->mat_p16->setPixmap(QPixmap(":/img/img/miniwbishop.png"));
    }else if(tabu->nump.value(15)==7){
        ui->mat_p16->setPixmap(QPixmap(":/img/img/miniwtower.png"));
    }else if(tabu->nump.value(15)==9){
        ui->mat_p16->setPixmap(QPixmap(":/img/img/miniwqueen.png"));
    }else{
        ui->mat_p16->setPixmap(QPixmap(""));
    }



    //0
    ui->pushButton_00->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_01->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_02->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_03->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_04->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_05->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_06->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_07->setStyleSheet("* { background-color: rgb(255,255,255)}");
    //1
    ui->pushButton_10->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_11->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_12->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_13->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_14->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_15->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_16->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_17->setStyleSheet("* { background-color: rgb(169,169,169)}");
    //2
    ui->pushButton_20->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_21->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_22->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_23->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_24->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_25->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_26->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_27->setStyleSheet("* { background-color: rgb(255,255,255)}");
    //3
    ui->pushButton_30->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_31->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_32->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_33->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_34->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_35->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_36->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_37->setStyleSheet("* { background-color: rgb(169,169,169)}");
    //4
    ui->pushButton_40->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_41->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_42->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_43->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_44->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_45->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_46->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_47->setStyleSheet("* { background-color: rgb(255,255,255)}");
    //5
    ui->pushButton_50->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_51->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_52->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_53->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_54->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_55->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_56->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_57->setStyleSheet("* { background-color: rgb(169,169,169)}");
    //6
    ui->pushButton_60->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_61->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_62->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_63->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_64->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_65->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_66->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_67->setStyleSheet("* { background-color: rgb(255,255,255)}");
    //7
    ui->pushButton_70->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_71->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_72->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_73->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_74->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_75->setStyleSheet("* { background-color: rgb(169,169,169)}");
    ui->pushButton_76->setStyleSheet("* { background-color: rgb(255,255,255)}");
    ui->pushButton_77->setStyleSheet("* { background-color: rgb(169,169,169)}");
    //
    QIcon ico(":/img/img/wpeao.png");
    if(tabu->branco){
        ui->toolButton->setIcon(ico);
    }
    if(tabu->Mostratabul()[0][0]==1){
        ui->pushButton_00->setIcon(ico);
    }
    if(tabu->Mostratabul()[0][1]==1){
        ui->pushButton_01->setIcon(ico);
    }
    if(tabu->Mostratabul()[0][2]==1){
        ui->pushButton_02->setIcon(ico);
    }
    if(tabu->Mostratabul()[0][3]==1){
        ui->pushButton_03->setIcon(ico);
    }
    if(tabu->Mostratabul()[0][4]==1){
        ui->pushButton_04->setIcon(ico);
    }
    if(tabu->Mostratabul()[0][5]==1){
        ui->pushButton_05->setIcon(ico);
    }
    if(tabu->Mostratabul()[0][6]==1){
        ui->pushButton_06->setIcon(ico);
    }
    if(tabu->Mostratabul()[0][7]==1){
        ui->pushButton_07->setIcon(ico);
    }
    //
    if(tabu->Mostratabul()[1][0]==1){
        ui->pushButton_10->setIcon(ico);
    }
    if(tabu->Mostratabul()[1][1]==1){
        ui->pushButton_11->setIcon(ico);
    }
    if(tabu->Mostratabul()[1][2]==1){
        ui->pushButton_12->setIcon(ico);
    }
    if(tabu->Mostratabul()[1][3]==1){
        ui->pushButton_13->setIcon(ico);
    }
    if(tabu->Mostratabul()[1][4]==1){
        ui->pushButton_14->setIcon(ico);
    }
    if(tabu->Mostratabul()[1][5]==1){
        ui->pushButton_15->setIcon(ico);
    }
    if(tabu->Mostratabul()[1][6]==1){
        ui->pushButton_16->setIcon(ico);
    }
    if(tabu->Mostratabul()[1][7]==1){
        ui->pushButton_17->setIcon(ico);
    }
    //
    if(tabu->Mostratabul()[2][0]==1){
        ui->pushButton_20->setIcon(ico);
    }
    if(tabu->Mostratabul()[2][1]==1){
        ui->pushButton_21->setIcon(ico);
    }
    if(tabu->Mostratabul()[2][2]==1){
        ui->pushButton_22->setIcon(ico);
    }
    if(tabu->Mostratabul()[2][3]==1){
        ui->pushButton_23->setIcon(ico);
    }
    if(tabu->Mostratabul()[2][4]==1){
        ui->pushButton_24->setIcon(ico);
    }
    if(tabu->Mostratabul()[2][5]==1){
        ui->pushButton_25->setIcon(ico);
    }
    if(tabu->Mostratabul()[2][6]==1){
        ui->pushButton_26->setIcon(ico);
    }
    if(tabu->Mostratabul()[2][7]==1){
        ui->pushButton_27->setIcon(ico);
    }
    //
    if(tabu->Mostratabul()[3][0]==1){
        ui->pushButton_30->setIcon(ico);
    }
    if(tabu->Mostratabul()[3][1]==1){
        ui->pushButton_31->setIcon(ico);
    }
    if(tabu->Mostratabul()[3][2]==1){
        ui->pushButton_32->setIcon(ico);
    }
    if(tabu->Mostratabul()[3][3]==1){
        ui->pushButton_33->setIcon(ico);
    }
    if(tabu->Mostratabul()[3][4]==1){
        ui->pushButton_34->setIcon(ico);
    }
    if(tabu->Mostratabul()[3][5]==1){
        ui->pushButton_35->setIcon(ico);
    }
    if(tabu->Mostratabul()[3][6]==1){
        ui->pushButton_36->setIcon(ico);
    }
    if(tabu->Mostratabul()[3][7]==1){
        ui->pushButton_37->setIcon(ico);
    }
    //
    if(tabu->Mostratabul()[4][0]==1){
        ui->pushButton_40->setIcon(ico);
    }
    if(tabu->Mostratabul()[4][1]==1){
        ui->pushButton_41->setIcon(ico);
    }
    if(tabu->Mostratabul()[4][2]==1){
        ui->pushButton_42->setIcon(ico);
    }
    if(tabu->Mostratabul()[4][3]==1){
        ui->pushButton_43->setIcon(ico);
    }
    if(tabu->Mostratabul()[4][4]==1){
        ui->pushButton_44->setIcon(ico);
    }
    if(tabu->Mostratabul()[4][5]==1){
        ui->pushButton_45->setIcon(ico);
    }
    if(tabu->Mostratabul()[4][6]==1){
        ui->pushButton_46->setIcon(ico);
    }
    if(tabu->Mostratabul()[4][7]==1){
        ui->pushButton_47->setIcon(ico);
    }
    //
    if(tabu->Mostratabul()[5][0]==1){
        ui->pushButton_50->setIcon(ico);
    }
    if(tabu->Mostratabul()[5][1]==1){
        ui->pushButton_51->setIcon(ico);
    }
    if(tabu->Mostratabul()[5][2]==1){
        ui->pushButton_52->setIcon(ico);
    }
    if(tabu->Mostratabul()[5][3]==1){
        ui->pushButton_53->setIcon(ico);
    }
    if(tabu->Mostratabul()[5][4]==1){
        ui->pushButton_54->setIcon(ico);
    }
    if(tabu->Mostratabul()[5][5]==1){
        ui->pushButton_55->setIcon(ico);
    }
    if(tabu->Mostratabul()[5][6]==1){
        ui->pushButton_56->setIcon(ico);
    }
    if(tabu->Mostratabul()[5][7]==1){
        ui->pushButton_57->setIcon(ico);
    }
    //
    if(tabu->Mostratabul()[6][0]==1){
        ui->pushButton_60->setIcon(ico);
    }
    if(tabu->Mostratabul()[6][1]==1){
        ui->pushButton_61->setIcon(ico);
    }
    if(tabu->Mostratabul()[6][2]==1){
        ui->pushButton_62->setIcon(ico);
    }
    if(tabu->Mostratabul()[6][3]==1){
        ui->pushButton_63->setIcon(ico);
    }
    if(tabu->Mostratabul()[6][4]==1){
        ui->pushButton_64->setIcon(ico);
    }
    if(tabu->Mostratabul()[6][5]==1){
        ui->pushButton_65->setIcon(ico);
    }
    if(tabu->Mostratabul()[6][6]==1){
        ui->pushButton_66->setIcon(ico);
    }
    if(tabu->Mostratabul()[6][7]==1){
        ui->pushButton_67->setIcon(ico);
    }
    //
    if(tabu->Mostratabul()[7][0]==1){
        ui->pushButton_70->setIcon(ico);
    }
    if(tabu->Mostratabul()[7][1]==1){
        ui->pushButton_71->setIcon(ico);
    }
    if(tabu->Mostratabul()[7][2]==1){
        ui->pushButton_72->setIcon(ico);
    }
    if(tabu->Mostratabul()[7][3]==1){
        ui->pushButton_73->setIcon(ico);
    }
    if(tabu->Mostratabul()[7][4]==1){
        ui->pushButton_74->setIcon(ico);
    }
    if(tabu->Mostratabul()[7][5]==1){
        ui->pushButton_75->setIcon(ico);
    }
    if(tabu->Mostratabul()[7][6]==1){
        ui->pushButton_76->setIcon(ico);
    }
    if(tabu->Mostratabul()[7][7]==1){
        ui->pushButton_77->setIcon(ico);
    }
    //
    //
    QIcon bpeao(":/img/img/bpeao.png");
    if(!tabu->branco){
        ui->toolButton->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[0][0]==2){
        ui->pushButton_00->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[0][1]==2){
        ui->pushButton_01->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[0][2]==2){
        ui->pushButton_02->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[0][3]==2){
        ui->pushButton_03->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[0][4]==2){
        ui->pushButton_04->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[0][5]==2){
        ui->pushButton_05->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[0][6]==2){
        ui->pushButton_06->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[0][7]==2){
        ui->pushButton_07->setIcon(bpeao);
    }
    //
    if(tabu->Mostratabul()[1][0]==2){
        ui->pushButton_10->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[1][1]==2){
        ui->pushButton_11->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[1][2]==2){
        ui->pushButton_12->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[1][3]==2){
        ui->pushButton_13->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[1][4]==2){
        ui->pushButton_14->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[1][5]==2){
        ui->pushButton_15->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[1][6]==2){
        ui->pushButton_16->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[1][7]==2){
        ui->pushButton_17->setIcon(bpeao);
    }
    //
    if(tabu->Mostratabul()[2][0]==2){
        ui->pushButton_20->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[2][1]==2){
        ui->pushButton_21->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[2][2]==2){
        ui->pushButton_22->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[2][3]==2){
        ui->pushButton_23->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[2][4]==2){
        ui->pushButton_24->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[2][5]==2){
        ui->pushButton_25->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[2][6]==2){
        ui->pushButton_26->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[2][7]==2){
        ui->pushButton_27->setIcon(bpeao);
    }
    //
    if(tabu->Mostratabul()[3][0]==2){
        ui->pushButton_30->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[3][1]==2){
        ui->pushButton_31->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[3][2]==2){
        ui->pushButton_32->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[3][3]==2){
        ui->pushButton_33->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[3][4]==2){
        ui->pushButton_34->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[3][5]==2){
        ui->pushButton_35->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[3][6]==2){
        ui->pushButton_36->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[3][7]==2){
        ui->pushButton_37->setIcon(bpeao);
    }
    //
    if(tabu->Mostratabul()[4][0]==2){
        ui->pushButton_40->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[4][1]==2){
        ui->pushButton_41->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[4][2]==2){
        ui->pushButton_42->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[4][3]==2){
        ui->pushButton_43->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[4][4]==2){
        ui->pushButton_44->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[4][5]==2){
        ui->pushButton_45->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[4][6]==2){
        ui->pushButton_46->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[4][7]==2){
        ui->pushButton_47->setIcon(bpeao);
    }
    //
    if(tabu->Mostratabul()[5][0]==2){
        ui->pushButton_50->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[5][1]==2){
        ui->pushButton_51->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[5][2]==2){
        ui->pushButton_52->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[5][3]==2){
        ui->pushButton_53->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[5][4]==2){
        ui->pushButton_54->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[5][5]==2){
        ui->pushButton_55->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[5][6]==2){
        ui->pushButton_56->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[5][7]==2){
        ui->pushButton_57->setIcon(bpeao);
    }
    //
    if(tabu->Mostratabul()[6][0]==2){
        ui->pushButton_60->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[6][1]==2){
        ui->pushButton_61->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[6][2]==2){
        ui->pushButton_62->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[6][3]==2){
        ui->pushButton_63->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[6][4]==2){
        ui->pushButton_64->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[6][5]==2){
        ui->pushButton_65->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[6][6]==2){
        ui->pushButton_66->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[6][7]==2){
        ui->pushButton_67->setIcon(bpeao);
    }
    //
    if(tabu->Mostratabul()[7][0]==2){
        ui->pushButton_70->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[7][1]==2){
        ui->pushButton_71->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[7][2]==2){
        ui->pushButton_72->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[7][3]==2){
        ui->pushButton_73->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[7][4]==2){
        ui->pushButton_74->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[7][5]==2){
        ui->pushButton_75->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[7][6]==2){
        ui->pushButton_76->setIcon(bpeao);
    }
    if(tabu->Mostratabul()[7][7]==2){
        ui->pushButton_77->setIcon(bpeao);
    }
    //
    //
    QIcon ico2(":/img/img/whorse.png");
    if(tabu->Mostratabul()[0][0]==3){
        ui->pushButton_00->setIcon(ico2);
    }
    if(tabu->Mostratabul()[0][1]==3){
        ui->pushButton_01->setIcon(ico2);
    }
    if(tabu->Mostratabul()[0][2]==3){
        ui->pushButton_02->setIcon(ico2);
    }
    if(tabu->Mostratabul()[0][3]==3){
        ui->pushButton_03->setIcon(ico2);
    }
    if(tabu->Mostratabul()[0][4]==3){
        ui->pushButton_04->setIcon(ico2);
    }
    if(tabu->Mostratabul()[0][5]==3){
        ui->pushButton_05->setIcon(ico2);
    }
    if(tabu->Mostratabul()[0][6]==3){
        ui->pushButton_06->setIcon(ico2);
    }
    if(tabu->Mostratabul()[0][7]==3){
        ui->pushButton_07->setIcon(ico2);
    }
    //
    if(tabu->Mostratabul()[1][0]==3){
        ui->pushButton_10->setIcon(ico2);
    }
    if(tabu->Mostratabul()[1][1]==3){
        ui->pushButton_11->setIcon(ico2);
    }
    if(tabu->Mostratabul()[1][2]==3){
        ui->pushButton_12->setIcon(ico2);
    }
    if(tabu->Mostratabul()[1][3]==3){
        ui->pushButton_13->setIcon(ico2);
    }
    if(tabu->Mostratabul()[1][4]==3){
        ui->pushButton_14->setIcon(ico2);
    }
    if(tabu->Mostratabul()[1][5]==3){
        ui->pushButton_15->setIcon(ico2);
    }
    if(tabu->Mostratabul()[1][6]==3){
        ui->pushButton_16->setIcon(ico2);
    }
    if(tabu->Mostratabul()[1][7]==3){
        ui->pushButton_17->setIcon(ico2);
    }
    //
    if(tabu->Mostratabul()[2][0]==3){
        ui->pushButton_20->setIcon(ico2);
    }
    if(tabu->Mostratabul()[2][1]==3){
        ui->pushButton_21->setIcon(ico2);
    }
    if(tabu->Mostratabul()[2][2]==3){
        ui->pushButton_22->setIcon(ico2);
    }
    if(tabu->Mostratabul()[2][3]==3){
        ui->pushButton_23->setIcon(ico2);
    }
    if(tabu->Mostratabul()[2][4]==3){
        ui->pushButton_24->setIcon(ico2);
    }
    if(tabu->Mostratabul()[2][5]==3){
        ui->pushButton_25->setIcon(ico2);
    }
    if(tabu->Mostratabul()[2][6]==3){
        ui->pushButton_26->setIcon(ico2);
    }
    if(tabu->Mostratabul()[2][7]==3){
        ui->pushButton_27->setIcon(ico2);
    }
    //
    if(tabu->Mostratabul()[3][0]==3){
        ui->pushButton_30->setIcon(ico2);
    }
    if(tabu->Mostratabul()[3][1]==3){
        ui->pushButton_31->setIcon(ico2);
    }
    if(tabu->Mostratabul()[3][2]==3){
        ui->pushButton_32->setIcon(ico2);
    }
    if(tabu->Mostratabul()[3][3]==3){
        ui->pushButton_33->setIcon(ico2);
    }
    if(tabu->Mostratabul()[3][4]==3){
        ui->pushButton_34->setIcon(ico2);
    }
    if(tabu->Mostratabul()[3][5]==3){
        ui->pushButton_35->setIcon(ico2);
    }
    if(tabu->Mostratabul()[3][6]==3){
        ui->pushButton_36->setIcon(ico2);
    }
    if(tabu->Mostratabul()[3][7]==3){
        ui->pushButton_37->setIcon(ico2);
    }
    //
    if(tabu->Mostratabul()[4][0]==3){
        ui->pushButton_40->setIcon(ico2);
    }
    if(tabu->Mostratabul()[4][1]==3){
        ui->pushButton_41->setIcon(ico2);
    }
    if(tabu->Mostratabul()[4][2]==3){
        ui->pushButton_42->setIcon(ico2);
    }
    if(tabu->Mostratabul()[4][3]==3){
        ui->pushButton_43->setIcon(ico2);
    }
    if(tabu->Mostratabul()[4][4]==3){
        ui->pushButton_44->setIcon(ico2);
    }
    if(tabu->Mostratabul()[4][5]==3){
        ui->pushButton_45->setIcon(ico2);
    }
    if(tabu->Mostratabul()[4][6]==3){
        ui->pushButton_46->setIcon(ico2);
    }
    if(tabu->Mostratabul()[4][7]==3){
        ui->pushButton_47->setIcon(ico2);
    }
    //
    if(tabu->Mostratabul()[5][0]==3){
        ui->pushButton_50->setIcon(ico2);
    }
    if(tabu->Mostratabul()[5][1]==3){
        ui->pushButton_51->setIcon(ico2);
    }
    if(tabu->Mostratabul()[5][2]==3){
        ui->pushButton_52->setIcon(ico2);
    }
    if(tabu->Mostratabul()[5][3]==3){
        ui->pushButton_53->setIcon(ico2);
    }
    if(tabu->Mostratabul()[5][4]==3){
        ui->pushButton_54->setIcon(ico2);
    }
    if(tabu->Mostratabul()[5][5]==3){
        ui->pushButton_55->setIcon(ico2);
    }
    if(tabu->Mostratabul()[5][6]==3){
        ui->pushButton_56->setIcon(ico2);
    }
    if(tabu->Mostratabul()[5][7]==3){
        ui->pushButton_57->setIcon(ico2);
    }
    //
    if(tabu->Mostratabul()[6][0]==3){
        ui->pushButton_60->setIcon(ico2);
    }
    if(tabu->Mostratabul()[6][1]==3){
        ui->pushButton_61->setIcon(ico2);
    }
    if(tabu->Mostratabul()[6][2]==3){
        ui->pushButton_62->setIcon(ico2);
    }
    if(tabu->Mostratabul()[6][3]==3){
        ui->pushButton_63->setIcon(ico2);
    }
    if(tabu->Mostratabul()[6][4]==3){
        ui->pushButton_64->setIcon(ico2);
    }
    if(tabu->Mostratabul()[6][5]==3){
        ui->pushButton_65->setIcon(ico2);
    }
    if(tabu->Mostratabul()[6][6]==3){
        ui->pushButton_66->setIcon(ico2);
    }
    if(tabu->Mostratabul()[6][7]==3){
        ui->pushButton_67->setIcon(ico2);
    }
    //
    if(tabu->Mostratabul()[7][0]==3){
        ui->pushButton_70->setIcon(ico2);
    }
    if(tabu->Mostratabul()[7][1]==3){
        ui->pushButton_71->setIcon(ico2);
    }
    if(tabu->Mostratabul()[7][2]==3){
        ui->pushButton_72->setIcon(ico2);
    }
    if(tabu->Mostratabul()[7][3]==3){
        ui->pushButton_73->setIcon(ico2);
    }
    if(tabu->Mostratabul()[7][4]==3){
        ui->pushButton_74->setIcon(ico2);
    }
    if(tabu->Mostratabul()[7][5]==3){
        ui->pushButton_75->setIcon(ico2);
    }
    if(tabu->Mostratabul()[7][6]==3){
        ui->pushButton_76->setIcon(ico2);
    }
    if(tabu->Mostratabul()[7][7]==3){
        ui->pushButton_77->setIcon(ico2);
    }
    //
    QImage image4(":/img/img/bhorse.png");
    ico2.addPixmap(QPixmap::fromImage(image4));
    if(tabu->Mostratabul()[0][0]==4){
        ui->pushButton_00->setIcon(ico2);
    }
    if(tabu->Mostratabul()[0][1]==4){
        ui->pushButton_01->setIcon(ico2);
    }
    if(tabu->Mostratabul()[0][2]==4){
        ui->pushButton_02->setIcon(ico2);
    }
    if(tabu->Mostratabul()[0][3]==4){
        ui->pushButton_03->setIcon(ico2);
    }
    if(tabu->Mostratabul()[0][4]==4){
        ui->pushButton_04->setIcon(ico2);
    }
    if(tabu->Mostratabul()[0][5]==4){
        ui->pushButton_05->setIcon(ico2);
    }
    if(tabu->Mostratabul()[0][6]==4){
        ui->pushButton_06->setIcon(ico2);
    }
    if(tabu->Mostratabul()[0][7]==4){
        ui->pushButton_07->setIcon(ico2);
    }
    //
    if(tabu->Mostratabul()[1][0]==4){
        ui->pushButton_10->setIcon(ico2);
    }
    if(tabu->Mostratabul()[1][1]==4){
        ui->pushButton_11->setIcon(ico2);
    }
    if(tabu->Mostratabul()[1][2]==4){
        ui->pushButton_12->setIcon(ico2);
    }
    if(tabu->Mostratabul()[1][3]==4){
        ui->pushButton_13->setIcon(ico2);
    }
    if(tabu->Mostratabul()[1][4]==4){
        ui->pushButton_14->setIcon(ico2);
    }
    if(tabu->Mostratabul()[1][5]==4){
        ui->pushButton_15->setIcon(ico2);
    }
    if(tabu->Mostratabul()[1][6]==4){
        ui->pushButton_16->setIcon(ico2);
    }
    if(tabu->Mostratabul()[1][7]==4){
        ui->pushButton_17->setIcon(ico2);
    }
    //
    if(tabu->Mostratabul()[2][0]==4){
        ui->pushButton_20->setIcon(ico2);
    }
    if(tabu->Mostratabul()[2][1]==4){
        ui->pushButton_21->setIcon(ico2);
    }
    if(tabu->Mostratabul()[2][2]==4){
        ui->pushButton_22->setIcon(ico2);
    }
    if(tabu->Mostratabul()[2][3]==4){
        ui->pushButton_23->setIcon(ico2);
    }
    if(tabu->Mostratabul()[2][4]==4){
        ui->pushButton_24->setIcon(ico2);
    }
    if(tabu->Mostratabul()[2][5]==4){
        ui->pushButton_25->setIcon(ico2);
    }
    if(tabu->Mostratabul()[2][6]==4){
        ui->pushButton_26->setIcon(ico2);
    }
    if(tabu->Mostratabul()[2][7]==4){
        ui->pushButton_27->setIcon(ico2);
    }
    //
    if(tabu->Mostratabul()[3][0]==4){
        ui->pushButton_30->setIcon(ico2);
    }
    if(tabu->Mostratabul()[3][1]==4){
        ui->pushButton_31->setIcon(ico2);
    }
    if(tabu->Mostratabul()[3][2]==4){
        ui->pushButton_32->setIcon(ico2);
    }
    if(tabu->Mostratabul()[3][3]==4){
        ui->pushButton_33->setIcon(ico2);
    }
    if(tabu->Mostratabul()[3][4]==4){
        ui->pushButton_34->setIcon(ico2);
    }
    if(tabu->Mostratabul()[3][5]==4){
        ui->pushButton_35->setIcon(ico2);
    }
    if(tabu->Mostratabul()[3][6]==4){
        ui->pushButton_36->setIcon(ico2);
    }
    if(tabu->Mostratabul()[3][7]==4){
        ui->pushButton_37->setIcon(ico2);
    }
    //
    if(tabu->Mostratabul()[4][0]==4){
        ui->pushButton_40->setIcon(ico2);
    }
    if(tabu->Mostratabul()[4][1]==4){
        ui->pushButton_41->setIcon(ico2);
    }
    if(tabu->Mostratabul()[4][2]==4){
        ui->pushButton_42->setIcon(ico2);
    }
    if(tabu->Mostratabul()[4][3]==4){
        ui->pushButton_43->setIcon(ico2);
    }
    if(tabu->Mostratabul()[4][4]==4){
        ui->pushButton_44->setIcon(ico2);
    }
    if(tabu->Mostratabul()[4][5]==4){
        ui->pushButton_45->setIcon(ico2);
    }
    if(tabu->Mostratabul()[4][6]==4){
        ui->pushButton_46->setIcon(ico2);
    }
    if(tabu->Mostratabul()[4][7]==4){
        ui->pushButton_47->setIcon(ico2);
    }
    //
    if(tabu->Mostratabul()[5][0]==4){
        ui->pushButton_50->setIcon(ico2);
    }
    if(tabu->Mostratabul()[5][1]==4){
        ui->pushButton_51->setIcon(ico2);
    }
    if(tabu->Mostratabul()[5][2]==4){
        ui->pushButton_52->setIcon(ico2);
    }
    if(tabu->Mostratabul()[5][3]==4){
        ui->pushButton_53->setIcon(ico2);
    }
    if(tabu->Mostratabul()[5][4]==4){
        ui->pushButton_54->setIcon(ico2);
    }
    if(tabu->Mostratabul()[5][5]==4){
        ui->pushButton_55->setIcon(ico2);
    }
    if(tabu->Mostratabul()[5][6]==4){
        ui->pushButton_56->setIcon(ico2);
    }
    if(tabu->Mostratabul()[5][7]==4){
        ui->pushButton_57->setIcon(ico2);
    }
    //
    if(tabu->Mostratabul()[6][0]==4){
        ui->pushButton_60->setIcon(ico2);
    }
    if(tabu->Mostratabul()[6][1]==4){
        ui->pushButton_61->setIcon(ico2);
    }
    if(tabu->Mostratabul()[6][2]==4){
        ui->pushButton_62->setIcon(ico2);
    }
    if(tabu->Mostratabul()[6][3]==4){
        ui->pushButton_63->setIcon(ico2);
    }
    if(tabu->Mostratabul()[6][4]==4){
        ui->pushButton_64->setIcon(ico2);
    }
    if(tabu->Mostratabul()[6][5]==4){
        ui->pushButton_65->setIcon(ico2);
    }
    if(tabu->Mostratabul()[6][6]==4){
        ui->pushButton_66->setIcon(ico2);
    }
    if(tabu->Mostratabul()[6][7]==4){
        ui->pushButton_67->setIcon(ico2);
    }
    //
    if(tabu->Mostratabul()[7][0]==4){
        ui->pushButton_70->setIcon(ico2);
    }
    if(tabu->Mostratabul()[7][1]==4){
        ui->pushButton_71->setIcon(ico2);
    }
    if(tabu->Mostratabul()[7][2]==4){
        ui->pushButton_72->setIcon(ico2);
    }
    if(tabu->Mostratabul()[7][3]==4){
        ui->pushButton_73->setIcon(ico2);
    }
    if(tabu->Mostratabul()[7][4]==4){
        ui->pushButton_74->setIcon(ico2);
    }
    if(tabu->Mostratabul()[7][5]==4){
        ui->pushButton_75->setIcon(ico2);
    }
    if(tabu->Mostratabul()[7][6]==4){
        ui->pushButton_76->setIcon(ico2);
    }
    if(tabu->Mostratabul()[7][7]==4){
        ui->pushButton_77->setIcon(ico2);
    }
    //
    int num;
    QIcon bishop;
    QImage image5(":/img/img/wbishop.png");
    bishop.addPixmap(QPixmap::fromImage(image5));
    num=5;
    if(tabu->Mostratabul()[0][0]==num){
        ui->pushButton_00->setIcon(bishop);
    }
    if(tabu->Mostratabul()[0][1]==num){
        ui->pushButton_01->setIcon(bishop);
    }
    if(tabu->Mostratabul()[0][2]==num){
        ui->pushButton_02->setIcon(bishop);
    }
    if(tabu->Mostratabul()[0][3]==num){
        ui->pushButton_03->setIcon(bishop);
    }
    if(tabu->Mostratabul()[0][4]==num){
        ui->pushButton_04->setIcon(bishop);
    }
    if(tabu->Mostratabul()[0][5]==num){
        ui->pushButton_05->setIcon(bishop);
    }
    if(tabu->Mostratabul()[0][6]==num){
        ui->pushButton_06->setIcon(bishop);
    }
    if(tabu->Mostratabul()[0][7]==num){
        ui->pushButton_07->setIcon(bishop);
    }
    //
    if(tabu->Mostratabul()[1][0]==num){
        ui->pushButton_10->setIcon(bishop);
    }
    if(tabu->Mostratabul()[1][1]==num){
        ui->pushButton_11->setIcon(bishop);
    }
    if(tabu->Mostratabul()[1][2]==num){
        ui->pushButton_12->setIcon(bishop);
    }
    if(tabu->Mostratabul()[1][3]==num){
        ui->pushButton_13->setIcon(bishop);
    }
    if(tabu->Mostratabul()[1][4]==num){
        ui->pushButton_14->setIcon(bishop);
    }
    if(tabu->Mostratabul()[1][5]==num){
        ui->pushButton_15->setIcon(bishop);
    }
    if(tabu->Mostratabul()[1][6]==num){
        ui->pushButton_16->setIcon(bishop);
    }
    if(tabu->Mostratabul()[1][7]==num){
        ui->pushButton_17->setIcon(bishop);
    }
    //
    if(tabu->Mostratabul()[2][0]==num){
        ui->pushButton_20->setIcon(bishop);
    }
    if(tabu->Mostratabul()[2][1]==num){
        ui->pushButton_21->setIcon(bishop);
    }
    if(tabu->Mostratabul()[2][2]==num){
        ui->pushButton_22->setIcon(bishop);
    }
    if(tabu->Mostratabul()[2][3]==num){
        ui->pushButton_23->setIcon(bishop);
    }
    if(tabu->Mostratabul()[2][4]==num){
        ui->pushButton_24->setIcon(bishop);
    }
    if(tabu->Mostratabul()[2][5]==num){
        ui->pushButton_25->setIcon(bishop);
    }
    if(tabu->Mostratabul()[2][6]==num){
        ui->pushButton_26->setIcon(bishop);
    }
    if(tabu->Mostratabul()[2][7]==num){
        ui->pushButton_27->setIcon(bishop);
    }
    //
    if(tabu->Mostratabul()[3][0]==num){
        ui->pushButton_30->setIcon(bishop);
    }
    if(tabu->Mostratabul()[3][1]==num){
        ui->pushButton_31->setIcon(bishop);
    }
    if(tabu->Mostratabul()[3][2]==num){
        ui->pushButton_32->setIcon(bishop);
    }
    if(tabu->Mostratabul()[3][3]==num){
        ui->pushButton_33->setIcon(bishop);
    }
    if(tabu->Mostratabul()[3][4]==num){
        ui->pushButton_34->setIcon(bishop);
    }
    if(tabu->Mostratabul()[3][5]==num){
        ui->pushButton_35->setIcon(bishop);
    }
    if(tabu->Mostratabul()[3][6]==num){
        ui->pushButton_36->setIcon(bishop);
    }
    if(tabu->Mostratabul()[3][7]==num){
        ui->pushButton_37->setIcon(bishop);
    }
    //
    if(tabu->Mostratabul()[4][0]==num){
        ui->pushButton_40->setIcon(bishop);
    }
    if(tabu->Mostratabul()[4][1]==num){
        ui->pushButton_41->setIcon(bishop);
    }
    if(tabu->Mostratabul()[4][2]==num){
        ui->pushButton_42->setIcon(bishop);
    }
    if(tabu->Mostratabul()[4][3]==num){
        ui->pushButton_43->setIcon(bishop);
    }
    if(tabu->Mostratabul()[4][4]==num){
        ui->pushButton_44->setIcon(bishop);
    }
    if(tabu->Mostratabul()[4][5]==num){
        ui->pushButton_45->setIcon(bishop);
    }
    if(tabu->Mostratabul()[4][6]==num){
        ui->pushButton_46->setIcon(bishop);
    }
    if(tabu->Mostratabul()[4][7]==num){
        ui->pushButton_47->setIcon(bishop);
    }
    //
    if(tabu->Mostratabul()[5][0]==num){
        ui->pushButton_50->setIcon(bishop);
    }
    if(tabu->Mostratabul()[5][1]==num){
        ui->pushButton_51->setIcon(bishop);
    }
    if(tabu->Mostratabul()[5][2]==num){
        ui->pushButton_52->setIcon(bishop);
    }
    if(tabu->Mostratabul()[5][3]==num){
        ui->pushButton_53->setIcon(bishop);
    }
    if(tabu->Mostratabul()[5][4]==num){
        ui->pushButton_54->setIcon(bishop);
    }
    if(tabu->Mostratabul()[5][5]==num){
        ui->pushButton_55->setIcon(bishop);
    }
    if(tabu->Mostratabul()[5][6]==num){
        ui->pushButton_56->setIcon(bishop);
    }
    if(tabu->Mostratabul()[5][7]==num){
        ui->pushButton_57->setIcon(bishop);
    }
    //
    if(tabu->Mostratabul()[6][0]==num){
        ui->pushButton_60->setIcon(bishop);
    }
    if(tabu->Mostratabul()[6][1]==num){
        ui->pushButton_61->setIcon(bishop);
    }
    if(tabu->Mostratabul()[6][2]==num){
        ui->pushButton_62->setIcon(bishop);
    }
    if(tabu->Mostratabul()[6][3]==num){
        ui->pushButton_63->setIcon(bishop);
    }
    if(tabu->Mostratabul()[6][4]==num){
        ui->pushButton_64->setIcon(bishop);
    }
    if(tabu->Mostratabul()[6][5]==num){
        ui->pushButton_65->setIcon(bishop);
    }
    if(tabu->Mostratabul()[6][6]==num){
        ui->pushButton_66->setIcon(bishop);
    }
    if(tabu->Mostratabul()[6][7]==num){
        ui->pushButton_67->setIcon(bishop);
    }
    //
    if(tabu->Mostratabul()[7][0]==num){
        ui->pushButton_70->setIcon(bishop);
    }
    if(tabu->Mostratabul()[7][1]==num){
        ui->pushButton_71->setIcon(bishop);
    }
    if(tabu->Mostratabul()[7][2]==num){
        ui->pushButton_72->setIcon(bishop);
    }
    if(tabu->Mostratabul()[7][3]==num){
        ui->pushButton_73->setIcon(bishop);
    }
    if(tabu->Mostratabul()[7][4]==num){
        ui->pushButton_74->setIcon(bishop);
    }
    if(tabu->Mostratabul()[7][5]==num){
        ui->pushButton_75->setIcon(bishop);
    }
    if(tabu->Mostratabul()[7][6]==num){
        ui->pushButton_76->setIcon(bishop);
    }
    if(tabu->Mostratabul()[7][7]==num){
        ui->pushButton_77->setIcon(bishop);
    }
    //
    QImage image6(":/img/img/bbishop.png");
    bishop.addPixmap(QPixmap::fromImage(image6));
    num=6;
    if(tabu->Mostratabul()[0][0]==num){
        ui->pushButton_00->setIcon(bishop);
    }
    if(tabu->Mostratabul()[0][1]==num){
        ui->pushButton_01->setIcon(bishop);
    }
    if(tabu->Mostratabul()[0][2]==num){
        ui->pushButton_02->setIcon(bishop);
    }
    if(tabu->Mostratabul()[0][3]==num){
        ui->pushButton_03->setIcon(bishop);
    }
    if(tabu->Mostratabul()[0][4]==num){
        ui->pushButton_04->setIcon(bishop);
    }
    if(tabu->Mostratabul()[0][5]==num){
        ui->pushButton_05->setIcon(bishop);
    }
    if(tabu->Mostratabul()[0][6]==num){
        ui->pushButton_06->setIcon(bishop);
    }
    if(tabu->Mostratabul()[0][7]==num){
        ui->pushButton_07->setIcon(bishop);
    }
    //
    if(tabu->Mostratabul()[1][0]==num){
        ui->pushButton_10->setIcon(bishop);
    }
    if(tabu->Mostratabul()[1][1]==num){
        ui->pushButton_11->setIcon(bishop);
    }
    if(tabu->Mostratabul()[1][2]==num){
        ui->pushButton_12->setIcon(bishop);
    }
    if(tabu->Mostratabul()[1][3]==num){
        ui->pushButton_13->setIcon(bishop);
    }
    if(tabu->Mostratabul()[1][4]==num){
        ui->pushButton_14->setIcon(bishop);
    }
    if(tabu->Mostratabul()[1][5]==num){
        ui->pushButton_15->setIcon(bishop);
    }
    if(tabu->Mostratabul()[1][6]==num){
        ui->pushButton_16->setIcon(bishop);
    }
    if(tabu->Mostratabul()[1][7]==num){
        ui->pushButton_17->setIcon(bishop);
    }
    //
    if(tabu->Mostratabul()[2][0]==num){
        ui->pushButton_20->setIcon(bishop);
    }
    if(tabu->Mostratabul()[2][1]==num){
        ui->pushButton_21->setIcon(bishop);
    }
    if(tabu->Mostratabul()[2][2]==num){
        ui->pushButton_22->setIcon(bishop);
    }
    if(tabu->Mostratabul()[2][3]==num){
        ui->pushButton_23->setIcon(bishop);
    }
    if(tabu->Mostratabul()[2][4]==num){
        ui->pushButton_24->setIcon(bishop);
    }
    if(tabu->Mostratabul()[2][5]==num){
        ui->pushButton_25->setIcon(bishop);
    }
    if(tabu->Mostratabul()[2][6]==num){
        ui->pushButton_26->setIcon(bishop);
    }
    if(tabu->Mostratabul()[2][7]==num){
        ui->pushButton_27->setIcon(bishop);
    }
    //
    if(tabu->Mostratabul()[3][0]==num){
        ui->pushButton_30->setIcon(bishop);
    }
    if(tabu->Mostratabul()[3][1]==num){
        ui->pushButton_31->setIcon(bishop);
    }
    if(tabu->Mostratabul()[3][2]==num){
        ui->pushButton_32->setIcon(bishop);
    }
    if(tabu->Mostratabul()[3][3]==num){
        ui->pushButton_33->setIcon(bishop);
    }
    if(tabu->Mostratabul()[3][4]==num){
        ui->pushButton_34->setIcon(bishop);
    }
    if(tabu->Mostratabul()[3][5]==num){
        ui->pushButton_35->setIcon(bishop);
    }
    if(tabu->Mostratabul()[3][6]==num){
        ui->pushButton_36->setIcon(bishop);
    }
    if(tabu->Mostratabul()[3][7]==num){
        ui->pushButton_37->setIcon(bishop);
    }
    //
    if(tabu->Mostratabul()[4][0]==num){
        ui->pushButton_40->setIcon(bishop);
    }
    if(tabu->Mostratabul()[4][1]==num){
        ui->pushButton_41->setIcon(bishop);
    }
    if(tabu->Mostratabul()[4][2]==num){
        ui->pushButton_42->setIcon(bishop);
    }
    if(tabu->Mostratabul()[4][3]==num){
        ui->pushButton_43->setIcon(bishop);
    }
    if(tabu->Mostratabul()[4][4]==num){
        ui->pushButton_44->setIcon(bishop);
    }
    if(tabu->Mostratabul()[4][5]==num){
        ui->pushButton_45->setIcon(bishop);
    }
    if(tabu->Mostratabul()[4][6]==num){
        ui->pushButton_46->setIcon(bishop);
    }
    if(tabu->Mostratabul()[4][7]==num){
        ui->pushButton_47->setIcon(bishop);
    }
    //
    if(tabu->Mostratabul()[5][0]==num){
        ui->pushButton_50->setIcon(bishop);
    }
    if(tabu->Mostratabul()[5][1]==num){
        ui->pushButton_51->setIcon(bishop);
    }
    if(tabu->Mostratabul()[5][2]==num){
        ui->pushButton_52->setIcon(bishop);
    }
    if(tabu->Mostratabul()[5][3]==num){
        ui->pushButton_53->setIcon(bishop);
    }
    if(tabu->Mostratabul()[5][4]==num){
        ui->pushButton_54->setIcon(bishop);
    }
    if(tabu->Mostratabul()[5][5]==num){
        ui->pushButton_55->setIcon(bishop);
    }
    if(tabu->Mostratabul()[5][6]==num){
        ui->pushButton_56->setIcon(bishop);
    }
    if(tabu->Mostratabul()[5][7]==num){
        ui->pushButton_57->setIcon(bishop);
    }
    //
    if(tabu->Mostratabul()[6][0]==num){
        ui->pushButton_60->setIcon(bishop);
    }
    if(tabu->Mostratabul()[6][1]==num){
        ui->pushButton_61->setIcon(bishop);
    }
    if(tabu->Mostratabul()[6][2]==num){
        ui->pushButton_62->setIcon(bishop);
    }
    if(tabu->Mostratabul()[6][3]==num){
        ui->pushButton_63->setIcon(bishop);
    }
    if(tabu->Mostratabul()[6][4]==num){
        ui->pushButton_64->setIcon(bishop);
    }
    if(tabu->Mostratabul()[6][5]==num){
        ui->pushButton_65->setIcon(bishop);
    }
    if(tabu->Mostratabul()[6][6]==num){
        ui->pushButton_66->setIcon(bishop);
    }
    if(tabu->Mostratabul()[6][7]==num){
        ui->pushButton_67->setIcon(bishop);
    }
    //
    if(tabu->Mostratabul()[7][0]==num){
        ui->pushButton_70->setIcon(bishop);
    }
    if(tabu->Mostratabul()[7][1]==num){
        ui->pushButton_71->setIcon(bishop);
    }
    if(tabu->Mostratabul()[7][2]==num){
        ui->pushButton_72->setIcon(bishop);
    }
    if(tabu->Mostratabul()[7][3]==num){
        ui->pushButton_73->setIcon(bishop);
    }
    if(tabu->Mostratabul()[7][4]==num){
        ui->pushButton_74->setIcon(bishop);
    }
    if(tabu->Mostratabul()[7][5]==num){
        ui->pushButton_75->setIcon(bishop);
    }
    if(tabu->Mostratabul()[7][6]==num){
        ui->pushButton_76->setIcon(bishop);
    }
    if(tabu->Mostratabul()[7][7]==num){
        ui->pushButton_77->setIcon(bishop);
    }
    //
    QIcon tower;
    QImage image7(":/img/img/wtower.png");
    tower.addPixmap(QPixmap::fromImage(image7));
    num=7;
    if(tabu->Mostratabul()[0][0]==num){
        ui->pushButton_00->setIcon(tower);
    }
    if(tabu->Mostratabul()[0][1]==num){
        ui->pushButton_01->setIcon(tower);
    }
    if(tabu->Mostratabul()[0][2]==num){
        ui->pushButton_02->setIcon(tower);
    }
    if(tabu->Mostratabul()[0][3]==num){
        ui->pushButton_03->setIcon(tower);
    }
    if(tabu->Mostratabul()[0][4]==num){
        ui->pushButton_04->setIcon(tower);
    }
    if(tabu->Mostratabul()[0][5]==num){
        ui->pushButton_05->setIcon(tower);
    }
    if(tabu->Mostratabul()[0][6]==num){
        ui->pushButton_06->setIcon(tower);
    }
    if(tabu->Mostratabul()[0][7]==num){
        ui->pushButton_07->setIcon(tower);
    }
    //
    if(tabu->Mostratabul()[1][0]==num){
        ui->pushButton_10->setIcon(tower);
    }
    if(tabu->Mostratabul()[1][1]==num){
        ui->pushButton_11->setIcon(tower);
    }
    if(tabu->Mostratabul()[1][2]==num){
        ui->pushButton_12->setIcon(tower);
    }
    if(tabu->Mostratabul()[1][3]==num){
        ui->pushButton_13->setIcon(tower);
    }
    if(tabu->Mostratabul()[1][4]==num){
        ui->pushButton_14->setIcon(tower);
    }
    if(tabu->Mostratabul()[1][5]==num){
        ui->pushButton_15->setIcon(tower);
    }
    if(tabu->Mostratabul()[1][6]==num){
        ui->pushButton_16->setIcon(tower);
    }
    if(tabu->Mostratabul()[1][7]==num){
        ui->pushButton_17->setIcon(tower);
    }
    //
    if(tabu->Mostratabul()[2][0]==num){
        ui->pushButton_20->setIcon(tower);
    }
    if(tabu->Mostratabul()[2][1]==num){
        ui->pushButton_21->setIcon(tower);
    }
    if(tabu->Mostratabul()[2][2]==num){
        ui->pushButton_22->setIcon(tower);
    }
    if(tabu->Mostratabul()[2][3]==num){
        ui->pushButton_23->setIcon(tower);
    }
    if(tabu->Mostratabul()[2][4]==num){
        ui->pushButton_24->setIcon(tower);
    }
    if(tabu->Mostratabul()[2][5]==num){
        ui->pushButton_25->setIcon(tower);
    }
    if(tabu->Mostratabul()[2][6]==num){
        ui->pushButton_26->setIcon(tower);
    }
    if(tabu->Mostratabul()[2][7]==num){
        ui->pushButton_27->setIcon(tower);
    }
    //
    if(tabu->Mostratabul()[3][0]==num){
        ui->pushButton_30->setIcon(tower);
    }
    if(tabu->Mostratabul()[3][1]==num){
        ui->pushButton_31->setIcon(tower);
    }
    if(tabu->Mostratabul()[3][2]==num){
        ui->pushButton_32->setIcon(tower);
    }
    if(tabu->Mostratabul()[3][3]==num){
        ui->pushButton_33->setIcon(tower);
    }
    if(tabu->Mostratabul()[3][4]==num){
        ui->pushButton_34->setIcon(tower);
    }
    if(tabu->Mostratabul()[3][5]==num){
        ui->pushButton_35->setIcon(tower);
    }
    if(tabu->Mostratabul()[3][6]==num){
        ui->pushButton_36->setIcon(tower);
    }
    if(tabu->Mostratabul()[3][7]==num){
        ui->pushButton_37->setIcon(tower);
    }
    //
    if(tabu->Mostratabul()[4][0]==num){
        ui->pushButton_40->setIcon(tower);
    }
    if(tabu->Mostratabul()[4][1]==num){
        ui->pushButton_41->setIcon(tower);
    }
    if(tabu->Mostratabul()[4][2]==num){
        ui->pushButton_42->setIcon(tower);
    }
    if(tabu->Mostratabul()[4][3]==num){
        ui->pushButton_43->setIcon(tower);
    }
    if(tabu->Mostratabul()[4][4]==num){
        ui->pushButton_44->setIcon(tower);
    }
    if(tabu->Mostratabul()[4][5]==num){
        ui->pushButton_45->setIcon(tower);
    }
    if(tabu->Mostratabul()[4][6]==num){
        ui->pushButton_46->setIcon(tower);
    }
    if(tabu->Mostratabul()[4][7]==num){
        ui->pushButton_47->setIcon(tower);
    }
    //
    if(tabu->Mostratabul()[5][0]==num){
        ui->pushButton_50->setIcon(tower);
    }
    if(tabu->Mostratabul()[5][1]==num){
        ui->pushButton_51->setIcon(tower);
    }
    if(tabu->Mostratabul()[5][2]==num){
        ui->pushButton_52->setIcon(tower);
    }
    if(tabu->Mostratabul()[5][3]==num){
        ui->pushButton_53->setIcon(tower);
    }
    if(tabu->Mostratabul()[5][4]==num){
        ui->pushButton_54->setIcon(tower);
    }
    if(tabu->Mostratabul()[5][5]==num){
        ui->pushButton_55->setIcon(tower);
    }
    if(tabu->Mostratabul()[5][6]==num){
        ui->pushButton_56->setIcon(tower);
    }
    if(tabu->Mostratabul()[5][7]==num){
        ui->pushButton_57->setIcon(tower);
    }
    //
    if(tabu->Mostratabul()[6][0]==num){
        ui->pushButton_60->setIcon(tower);
    }
    if(tabu->Mostratabul()[6][1]==num){
        ui->pushButton_61->setIcon(tower);
    }
    if(tabu->Mostratabul()[6][2]==num){
        ui->pushButton_62->setIcon(tower);
    }
    if(tabu->Mostratabul()[6][3]==num){
        ui->pushButton_63->setIcon(tower);
    }
    if(tabu->Mostratabul()[6][4]==num){
        ui->pushButton_64->setIcon(tower);
    }
    if(tabu->Mostratabul()[6][5]==num){
        ui->pushButton_65->setIcon(tower);
    }
    if(tabu->Mostratabul()[6][6]==num){
        ui->pushButton_66->setIcon(tower);
    }
    if(tabu->Mostratabul()[6][7]==num){
        ui->pushButton_67->setIcon(tower);
    }
    //
    if(tabu->Mostratabul()[7][0]==num){
        ui->pushButton_70->setIcon(tower);
    }
    if(tabu->Mostratabul()[7][1]==num){
        ui->pushButton_71->setIcon(tower);
    }
    if(tabu->Mostratabul()[7][2]==num){
        ui->pushButton_72->setIcon(tower);
    }
    if(tabu->Mostratabul()[7][3]==num){
        ui->pushButton_73->setIcon(tower);
    }
    if(tabu->Mostratabul()[7][4]==num){
        ui->pushButton_74->setIcon(tower);
    }
    if(tabu->Mostratabul()[7][5]==num){
        ui->pushButton_75->setIcon(tower);
    }
    if(tabu->Mostratabul()[7][6]==num){
        ui->pushButton_76->setIcon(tower);
    }
    if(tabu->Mostratabul()[7][7]==num){
        ui->pushButton_77->setIcon(tower);
    }
    //
    QImage image8(":/img/img/btower.png");
    tower.addPixmap(QPixmap::fromImage(image8));
    num=8;
    if(tabu->Mostratabul()[0][0]==num){
        ui->pushButton_00->setIcon(tower);
    }
    if(tabu->Mostratabul()[0][1]==num){
        ui->pushButton_01->setIcon(tower);
    }
    if(tabu->Mostratabul()[0][2]==num){
        ui->pushButton_02->setIcon(tower);
    }
    if(tabu->Mostratabul()[0][3]==num){
        ui->pushButton_03->setIcon(tower);
    }
    if(tabu->Mostratabul()[0][4]==num){
        ui->pushButton_04->setIcon(tower);
    }
    if(tabu->Mostratabul()[0][5]==num){
        ui->pushButton_05->setIcon(tower);
    }
    if(tabu->Mostratabul()[0][6]==num){
        ui->pushButton_06->setIcon(tower);
    }
    if(tabu->Mostratabul()[0][7]==num){
        ui->pushButton_07->setIcon(tower);
    }
    //
    if(tabu->Mostratabul()[1][0]==num){
        ui->pushButton_10->setIcon(tower);
    }
    if(tabu->Mostratabul()[1][1]==num){
        ui->pushButton_11->setIcon(tower);
    }
    if(tabu->Mostratabul()[1][2]==num){
        ui->pushButton_12->setIcon(tower);
    }
    if(tabu->Mostratabul()[1][3]==num){
        ui->pushButton_13->setIcon(tower);
    }
    if(tabu->Mostratabul()[1][4]==num){
        ui->pushButton_14->setIcon(tower);
    }
    if(tabu->Mostratabul()[1][5]==num){
        ui->pushButton_15->setIcon(tower);
    }
    if(tabu->Mostratabul()[1][6]==num){
        ui->pushButton_16->setIcon(tower);
    }
    if(tabu->Mostratabul()[1][7]==num){
        ui->pushButton_17->setIcon(tower);
    }
    //
    if(tabu->Mostratabul()[2][0]==num){
        ui->pushButton_20->setIcon(tower);
    }
    if(tabu->Mostratabul()[2][1]==num){
        ui->pushButton_21->setIcon(tower);
    }
    if(tabu->Mostratabul()[2][2]==num){
        ui->pushButton_22->setIcon(tower);
    }
    if(tabu->Mostratabul()[2][3]==num){
        ui->pushButton_23->setIcon(tower);
    }
    if(tabu->Mostratabul()[2][4]==num){
        ui->pushButton_24->setIcon(tower);
    }
    if(tabu->Mostratabul()[2][5]==num){
        ui->pushButton_25->setIcon(tower);
    }
    if(tabu->Mostratabul()[2][6]==num){
        ui->pushButton_26->setIcon(tower);
    }
    if(tabu->Mostratabul()[2][7]==num){
        ui->pushButton_27->setIcon(tower);
    }
    //
    if(tabu->Mostratabul()[3][0]==num){
        ui->pushButton_30->setIcon(tower);
    }
    if(tabu->Mostratabul()[3][1]==num){
        ui->pushButton_31->setIcon(tower);
    }
    if(tabu->Mostratabul()[3][2]==num){
        ui->pushButton_32->setIcon(tower);
    }
    if(tabu->Mostratabul()[3][3]==num){
        ui->pushButton_33->setIcon(tower);
    }
    if(tabu->Mostratabul()[3][4]==num){
        ui->pushButton_34->setIcon(tower);
    }
    if(tabu->Mostratabul()[3][5]==num){
        ui->pushButton_35->setIcon(tower);
    }
    if(tabu->Mostratabul()[3][6]==num){
        ui->pushButton_36->setIcon(tower);
    }
    if(tabu->Mostratabul()[3][7]==num){
        ui->pushButton_37->setIcon(tower);
    }
    //
    if(tabu->Mostratabul()[4][0]==num){
        ui->pushButton_40->setIcon(tower);
    }
    if(tabu->Mostratabul()[4][1]==num){
        ui->pushButton_41->setIcon(tower);
    }
    if(tabu->Mostratabul()[4][2]==num){
        ui->pushButton_42->setIcon(tower);
    }
    if(tabu->Mostratabul()[4][3]==num){
        ui->pushButton_43->setIcon(tower);
    }
    if(tabu->Mostratabul()[4][4]==num){
        ui->pushButton_44->setIcon(tower);
    }
    if(tabu->Mostratabul()[4][5]==num){
        ui->pushButton_45->setIcon(tower);
    }
    if(tabu->Mostratabul()[4][6]==num){
        ui->pushButton_46->setIcon(tower);
    }
    if(tabu->Mostratabul()[4][7]==num){
        ui->pushButton_47->setIcon(tower);
    }
    //
    if(tabu->Mostratabul()[5][0]==num){
        ui->pushButton_50->setIcon(tower);
    }
    if(tabu->Mostratabul()[5][1]==num){
        ui->pushButton_51->setIcon(tower);
    }
    if(tabu->Mostratabul()[5][2]==num){
        ui->pushButton_52->setIcon(tower);
    }
    if(tabu->Mostratabul()[5][3]==num){
        ui->pushButton_53->setIcon(tower);
    }
    if(tabu->Mostratabul()[5][4]==num){
        ui->pushButton_54->setIcon(tower);
    }
    if(tabu->Mostratabul()[5][5]==num){
        ui->pushButton_55->setIcon(tower);
    }
    if(tabu->Mostratabul()[5][6]==num){
        ui->pushButton_56->setIcon(tower);
    }
    if(tabu->Mostratabul()[5][7]==num){
        ui->pushButton_57->setIcon(tower);
    }
    //
    if(tabu->Mostratabul()[6][0]==num){
        ui->pushButton_60->setIcon(tower);
    }
    if(tabu->Mostratabul()[6][1]==num){
        ui->pushButton_61->setIcon(tower);
    }
    if(tabu->Mostratabul()[6][2]==num){
        ui->pushButton_62->setIcon(tower);
    }
    if(tabu->Mostratabul()[6][3]==num){
        ui->pushButton_63->setIcon(tower);
    }
    if(tabu->Mostratabul()[6][4]==num){
        ui->pushButton_64->setIcon(tower);
    }
    if(tabu->Mostratabul()[6][5]==num){
        ui->pushButton_65->setIcon(tower);
    }
    if(tabu->Mostratabul()[6][6]==num){
        ui->pushButton_66->setIcon(tower);
    }
    if(tabu->Mostratabul()[6][7]==num){
        ui->pushButton_67->setIcon(tower);
    }
    //
    if(tabu->Mostratabul()[7][0]==num){
        ui->pushButton_70->setIcon(tower);
    }
    if(tabu->Mostratabul()[7][1]==num){
        ui->pushButton_71->setIcon(tower);
    }
    if(tabu->Mostratabul()[7][2]==num){
        ui->pushButton_72->setIcon(tower);
    }
    if(tabu->Mostratabul()[7][3]==num){
        ui->pushButton_73->setIcon(tower);
    }
    if(tabu->Mostratabul()[7][4]==num){
        ui->pushButton_74->setIcon(tower);
    }
    if(tabu->Mostratabul()[7][5]==num){
        ui->pushButton_75->setIcon(tower);
    }
    if(tabu->Mostratabul()[7][6]==num){
        ui->pushButton_76->setIcon(tower);
    }
    if(tabu->Mostratabul()[7][7]==num){
        ui->pushButton_77->setIcon(tower);
    }
    //
    QIcon queen;
    QImage image9(":/img/img/wqueen.png");
    queen.addPixmap(QPixmap::fromImage(image9));
    num=9;
    if(tabu->Mostratabul()[0][0]==num){
        ui->pushButton_00->setIcon(queen);
    }
    if(tabu->Mostratabul()[0][1]==num){
        ui->pushButton_01->setIcon(queen);
    }
    if(tabu->Mostratabul()[0][2]==num){
        ui->pushButton_02->setIcon(queen);
    }
    if(tabu->Mostratabul()[0][3]==num){
        ui->pushButton_03->setIcon(queen);
    }
    if(tabu->Mostratabul()[0][4]==num){
        ui->pushButton_04->setIcon(queen);
    }
    if(tabu->Mostratabul()[0][5]==num){
        ui->pushButton_05->setIcon(queen);
    }
    if(tabu->Mostratabul()[0][6]==num){
        ui->pushButton_06->setIcon(queen);
    }
    if(tabu->Mostratabul()[0][7]==num){
        ui->pushButton_07->setIcon(queen);
    }
    //
    if(tabu->Mostratabul()[1][0]==num){
        ui->pushButton_10->setIcon(queen);
    }
    if(tabu->Mostratabul()[1][1]==num){
        ui->pushButton_11->setIcon(queen);
    }
    if(tabu->Mostratabul()[1][2]==num){
        ui->pushButton_12->setIcon(queen);
    }
    if(tabu->Mostratabul()[1][3]==num){
        ui->pushButton_13->setIcon(queen);
    }
    if(tabu->Mostratabul()[1][4]==num){
        ui->pushButton_14->setIcon(queen);
    }
    if(tabu->Mostratabul()[1][5]==num){
        ui->pushButton_15->setIcon(queen);
    }
    if(tabu->Mostratabul()[1][6]==num){
        ui->pushButton_16->setIcon(queen);
    }
    if(tabu->Mostratabul()[1][7]==num){
        ui->pushButton_17->setIcon(queen);
    }
    //
    if(tabu->Mostratabul()[2][0]==num){
        ui->pushButton_20->setIcon(queen);
    }
    if(tabu->Mostratabul()[2][1]==num){
        ui->pushButton_21->setIcon(queen);
    }
    if(tabu->Mostratabul()[2][2]==num){
        ui->pushButton_22->setIcon(queen);
    }
    if(tabu->Mostratabul()[2][3]==num){
        ui->pushButton_23->setIcon(queen);
    }
    if(tabu->Mostratabul()[2][4]==num){
        ui->pushButton_24->setIcon(queen);
    }
    if(tabu->Mostratabul()[2][5]==num){
        ui->pushButton_25->setIcon(queen);
    }
    if(tabu->Mostratabul()[2][6]==num){
        ui->pushButton_26->setIcon(queen);
    }
    if(tabu->Mostratabul()[2][7]==num){
        ui->pushButton_27->setIcon(queen);
    }
    //
    if(tabu->Mostratabul()[3][0]==num){
        ui->pushButton_30->setIcon(queen);
    }
    if(tabu->Mostratabul()[3][1]==num){
        ui->pushButton_31->setIcon(queen);
    }
    if(tabu->Mostratabul()[3][2]==num){
        ui->pushButton_32->setIcon(queen);
    }
    if(tabu->Mostratabul()[3][3]==num){
        ui->pushButton_33->setIcon(queen);
    }
    if(tabu->Mostratabul()[3][4]==num){
        ui->pushButton_34->setIcon(queen);
    }
    if(tabu->Mostratabul()[3][5]==num){
        ui->pushButton_35->setIcon(queen);
    }
    if(tabu->Mostratabul()[3][6]==num){
        ui->pushButton_36->setIcon(queen);
    }
    if(tabu->Mostratabul()[3][7]==num){
        ui->pushButton_37->setIcon(queen);
    }
    //
    if(tabu->Mostratabul()[4][0]==num){
        ui->pushButton_40->setIcon(queen);
    }
    if(tabu->Mostratabul()[4][1]==num){
        ui->pushButton_41->setIcon(queen);
    }
    if(tabu->Mostratabul()[4][2]==num){
        ui->pushButton_42->setIcon(queen);
    }
    if(tabu->Mostratabul()[4][3]==num){
        ui->pushButton_43->setIcon(queen);
    }
    if(tabu->Mostratabul()[4][4]==num){
        ui->pushButton_44->setIcon(queen);
    }
    if(tabu->Mostratabul()[4][5]==num){
        ui->pushButton_45->setIcon(queen);
    }
    if(tabu->Mostratabul()[4][6]==num){
        ui->pushButton_46->setIcon(queen);
    }
    if(tabu->Mostratabul()[4][7]==num){
        ui->pushButton_47->setIcon(queen);
    }
    //
    if(tabu->Mostratabul()[5][0]==num){
        ui->pushButton_50->setIcon(queen);
    }
    if(tabu->Mostratabul()[5][1]==num){
        ui->pushButton_51->setIcon(queen);
    }
    if(tabu->Mostratabul()[5][2]==num){
        ui->pushButton_52->setIcon(queen);
    }
    if(tabu->Mostratabul()[5][3]==num){
        ui->pushButton_53->setIcon(queen);
    }
    if(tabu->Mostratabul()[5][4]==num){
        ui->pushButton_54->setIcon(queen);
    }
    if(tabu->Mostratabul()[5][5]==num){
        ui->pushButton_55->setIcon(queen);
    }
    if(tabu->Mostratabul()[5][6]==num){
        ui->pushButton_56->setIcon(queen);
    }
    if(tabu->Mostratabul()[5][7]==num){
        ui->pushButton_57->setIcon(queen);
    }
    //
    if(tabu->Mostratabul()[6][0]==num){
        ui->pushButton_60->setIcon(queen);
    }
    if(tabu->Mostratabul()[6][1]==num){
        ui->pushButton_61->setIcon(queen);
    }
    if(tabu->Mostratabul()[6][2]==num){
        ui->pushButton_62->setIcon(queen);
    }
    if(tabu->Mostratabul()[6][3]==num){
        ui->pushButton_63->setIcon(queen);
    }
    if(tabu->Mostratabul()[6][4]==num){
        ui->pushButton_64->setIcon(queen);
    }
    if(tabu->Mostratabul()[6][5]==num){
        ui->pushButton_65->setIcon(queen);
    }
    if(tabu->Mostratabul()[6][6]==num){
        ui->pushButton_66->setIcon(queen);
    }
    if(tabu->Mostratabul()[6][7]==num){
        ui->pushButton_67->setIcon(queen);
    }
    //
    if(tabu->Mostratabul()[7][0]==num){
        ui->pushButton_70->setIcon(queen);
    }
    if(tabu->Mostratabul()[7][1]==num){
        ui->pushButton_71->setIcon(queen);
    }
    if(tabu->Mostratabul()[7][2]==num){
        ui->pushButton_72->setIcon(queen);
    }
    if(tabu->Mostratabul()[7][3]==num){
        ui->pushButton_73->setIcon(queen);
    }
    if(tabu->Mostratabul()[7][4]==num){
        ui->pushButton_74->setIcon(queen);
    }
    if(tabu->Mostratabul()[7][5]==num){
        ui->pushButton_75->setIcon(queen);
    }
    if(tabu->Mostratabul()[7][6]==num){
        ui->pushButton_76->setIcon(queen);
    }
    if(tabu->Mostratabul()[7][7]==num){
        ui->pushButton_77->setIcon(queen);
    }
    //
    QIcon bqueen;
    QImage image10(":/img/img/bqueen.png");
    bqueen.addPixmap(QPixmap::fromImage(image10));
    num=10;
    if(tabu->Mostratabul()[0][0]==num){
        ui->pushButton_00->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[0][1]==num){
        ui->pushButton_01->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[0][2]==num){
        ui->pushButton_02->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[0][3]==num){
        ui->pushButton_03->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[0][4]==num){
        ui->pushButton_04->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[0][5]==num){
        ui->pushButton_05->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[0][6]==num){
        ui->pushButton_06->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[0][7]==num){
        ui->pushButton_07->setIcon(bqueen);
    }
    //
    if(tabu->Mostratabul()[1][0]==num){
        ui->pushButton_10->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[1][1]==num){
        ui->pushButton_11->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[1][2]==num){
        ui->pushButton_12->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[1][3]==num){
        ui->pushButton_13->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[1][4]==num){
        ui->pushButton_14->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[1][5]==num){
        ui->pushButton_15->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[1][6]==num){
        ui->pushButton_16->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[1][7]==num){
        ui->pushButton_17->setIcon(bqueen);
    }
    //
    if(tabu->Mostratabul()[2][0]==num){
        ui->pushButton_20->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[2][1]==num){
        ui->pushButton_21->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[2][2]==num){
        ui->pushButton_22->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[2][3]==num){
        ui->pushButton_23->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[2][4]==num){
        ui->pushButton_24->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[2][5]==num){
        ui->pushButton_25->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[2][6]==num){
        ui->pushButton_26->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[2][7]==num){
        ui->pushButton_27->setIcon(bqueen);
    }
    //
    if(tabu->Mostratabul()[3][0]==num){
        ui->pushButton_30->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[3][1]==num){
        ui->pushButton_31->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[3][2]==num){
        ui->pushButton_32->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[3][3]==num){
        ui->pushButton_33->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[3][4]==num){
        ui->pushButton_34->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[3][5]==num){
        ui->pushButton_35->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[3][6]==num){
        ui->pushButton_36->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[3][7]==num){
        ui->pushButton_37->setIcon(bqueen);
    }
    //
    if(tabu->Mostratabul()[4][0]==num){
        ui->pushButton_40->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[4][1]==num){
        ui->pushButton_41->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[4][2]==num){
        ui->pushButton_42->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[4][3]==num){
        ui->pushButton_43->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[4][4]==num){
        ui->pushButton_44->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[4][5]==num){
        ui->pushButton_45->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[4][6]==num){
        ui->pushButton_46->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[4][7]==num){
        ui->pushButton_47->setIcon(bqueen);
    }
    //
    if(tabu->Mostratabul()[5][0]==num){
        ui->pushButton_50->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[5][1]==num){
        ui->pushButton_51->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[5][2]==num){
        ui->pushButton_52->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[5][3]==num){
        ui->pushButton_53->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[5][4]==num){
        ui->pushButton_54->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[5][5]==num){
        ui->pushButton_55->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[5][6]==num){
        ui->pushButton_56->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[5][7]==num){
        ui->pushButton_57->setIcon(bqueen);
    }
    //
    if(tabu->Mostratabul()[6][0]==num){
        ui->pushButton_60->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[6][1]==num){
        ui->pushButton_61->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[6][2]==num){
        ui->pushButton_62->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[6][3]==num){
        ui->pushButton_63->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[6][4]==num){
        ui->pushButton_64->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[6][5]==num){
        ui->pushButton_65->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[6][6]==num){
        ui->pushButton_66->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[6][7]==num){
        ui->pushButton_67->setIcon(bqueen);
    }
    //
    if(tabu->Mostratabul()[7][0]==num){
        ui->pushButton_70->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[7][1]==num){
        ui->pushButton_71->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[7][2]==num){
        ui->pushButton_72->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[7][3]==num){
        ui->pushButton_73->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[7][4]==num){
        ui->pushButton_74->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[7][5]==num){
        ui->pushButton_75->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[7][6]==num){
        ui->pushButton_76->setIcon(bqueen);
    }
    if(tabu->Mostratabul()[7][7]==num){
        ui->pushButton_77->setIcon(bqueen);
    }
    //
    QIcon king;
    QImage image11(":/img/img/wking.png");
    king.addPixmap(QPixmap::fromImage(image11));
    num=11;
    if(tabu->Mostratabul()[0][0]==num){
        ui->pushButton_00->setIcon(king);
    }
    if(tabu->Mostratabul()[0][1]==num){
        ui->pushButton_01->setIcon(king);
    }
    if(tabu->Mostratabul()[0][2]==num){
        ui->pushButton_02->setIcon(king);
    }
    if(tabu->Mostratabul()[0][3]==num){
        ui->pushButton_03->setIcon(king);
    }
    if(tabu->Mostratabul()[0][4]==num){
        ui->pushButton_04->setIcon(king);
    }
    if(tabu->Mostratabul()[0][5]==num){
        ui->pushButton_05->setIcon(king);
    }
    if(tabu->Mostratabul()[0][6]==num){
        ui->pushButton_06->setIcon(king);
    }
    if(tabu->Mostratabul()[0][7]==num){
        ui->pushButton_07->setIcon(king);
    }
    //
    if(tabu->Mostratabul()[1][0]==num){
        ui->pushButton_10->setIcon(king);
    }
    if(tabu->Mostratabul()[1][1]==num){
        ui->pushButton_11->setIcon(king);
    }
    if(tabu->Mostratabul()[1][2]==num){
        ui->pushButton_12->setIcon(king);
    }
    if(tabu->Mostratabul()[1][3]==num){
        ui->pushButton_13->setIcon(king);
    }
    if(tabu->Mostratabul()[1][4]==num){
        ui->pushButton_14->setIcon(king);
    }
    if(tabu->Mostratabul()[1][5]==num){
        ui->pushButton_15->setIcon(king);
    }
    if(tabu->Mostratabul()[1][6]==num){
        ui->pushButton_16->setIcon(king);
    }
    if(tabu->Mostratabul()[1][7]==num){
        ui->pushButton_17->setIcon(king);
    }
    //
    if(tabu->Mostratabul()[2][0]==num){
        ui->pushButton_20->setIcon(king);
    }
    if(tabu->Mostratabul()[2][1]==num){
        ui->pushButton_21->setIcon(king);
    }
    if(tabu->Mostratabul()[2][2]==num){
        ui->pushButton_22->setIcon(king);
    }
    if(tabu->Mostratabul()[2][3]==num){
        ui->pushButton_23->setIcon(king);
    }
    if(tabu->Mostratabul()[2][4]==num){
        ui->pushButton_24->setIcon(king);
    }
    if(tabu->Mostratabul()[2][5]==num){
        ui->pushButton_25->setIcon(king);
    }
    if(tabu->Mostratabul()[2][6]==num){
        ui->pushButton_26->setIcon(king);
    }
    if(tabu->Mostratabul()[2][7]==num){
        ui->pushButton_27->setIcon(king);
    }
    //
    if(tabu->Mostratabul()[3][0]==num){
        ui->pushButton_30->setIcon(king);
    }
    if(tabu->Mostratabul()[3][1]==num){
        ui->pushButton_31->setIcon(king);
    }
    if(tabu->Mostratabul()[3][2]==num){
        ui->pushButton_32->setIcon(king);
    }
    if(tabu->Mostratabul()[3][3]==num){
        ui->pushButton_33->setIcon(king);
    }
    if(tabu->Mostratabul()[3][4]==num){
        ui->pushButton_34->setIcon(king);
    }
    if(tabu->Mostratabul()[3][5]==num){
        ui->pushButton_35->setIcon(king);
    }
    if(tabu->Mostratabul()[3][6]==num){
        ui->pushButton_36->setIcon(king);
    }
    if(tabu->Mostratabul()[3][7]==num){
        ui->pushButton_37->setIcon(king);
    }
    //
    if(tabu->Mostratabul()[4][0]==num){
        ui->pushButton_40->setIcon(king);
    }
    if(tabu->Mostratabul()[4][1]==num){
        ui->pushButton_41->setIcon(king);
    }
    if(tabu->Mostratabul()[4][2]==num){
        ui->pushButton_42->setIcon(king);
    }
    if(tabu->Mostratabul()[4][3]==num){
        ui->pushButton_43->setIcon(king);
    }
    if(tabu->Mostratabul()[4][4]==num){
        ui->pushButton_44->setIcon(king);
    }
    if(tabu->Mostratabul()[4][5]==num){
        ui->pushButton_45->setIcon(king);
    }
    if(tabu->Mostratabul()[4][6]==num){
        ui->pushButton_46->setIcon(king);
    }
    if(tabu->Mostratabul()[4][7]==num){
        ui->pushButton_47->setIcon(king);
    }
    //
    if(tabu->Mostratabul()[5][0]==num){
        ui->pushButton_50->setIcon(king);
    }
    if(tabu->Mostratabul()[5][1]==num){
        ui->pushButton_51->setIcon(king);
    }
    if(tabu->Mostratabul()[5][2]==num){
        ui->pushButton_52->setIcon(king);
    }
    if(tabu->Mostratabul()[5][3]==num){
        ui->pushButton_53->setIcon(king);
    }
    if(tabu->Mostratabul()[5][4]==num){
        ui->pushButton_54->setIcon(king);
    }
    if(tabu->Mostratabul()[5][5]==num){
        ui->pushButton_55->setIcon(king);
    }
    if(tabu->Mostratabul()[5][6]==num){
        ui->pushButton_56->setIcon(king);
    }
    if(tabu->Mostratabul()[5][7]==num){
        ui->pushButton_57->setIcon(king);
    }
    //
    if(tabu->Mostratabul()[6][0]==num){
        ui->pushButton_60->setIcon(king);
    }
    if(tabu->Mostratabul()[6][1]==num){
        ui->pushButton_61->setIcon(king);
    }
    if(tabu->Mostratabul()[6][2]==num){
        ui->pushButton_62->setIcon(king);
    }
    if(tabu->Mostratabul()[6][3]==num){
        ui->pushButton_63->setIcon(king);
    }
    if(tabu->Mostratabul()[6][4]==num){
        ui->pushButton_64->setIcon(king);
    }
    if(tabu->Mostratabul()[6][5]==num){
        ui->pushButton_65->setIcon(king);
    }
    if(tabu->Mostratabul()[6][6]==num){
        ui->pushButton_66->setIcon(king);
    }
    if(tabu->Mostratabul()[6][7]==num){
        ui->pushButton_67->setIcon(king);
    }
    //
    if(tabu->Mostratabul()[7][0]==num){
        ui->pushButton_70->setIcon(king);
    }
    if(tabu->Mostratabul()[7][1]==num){
        ui->pushButton_71->setIcon(king);
    }
    if(tabu->Mostratabul()[7][2]==num){
        ui->pushButton_72->setIcon(king);
    }
    if(tabu->Mostratabul()[7][3]==num){
        ui->pushButton_73->setIcon(king);
    }
    if(tabu->Mostratabul()[7][4]==num){
        ui->pushButton_74->setIcon(king);
    }
    if(tabu->Mostratabul()[7][5]==num){
        ui->pushButton_75->setIcon(king);
    }
    if(tabu->Mostratabul()[7][6]==num){
        ui->pushButton_76->setIcon(king);
    }
    if(tabu->Mostratabul()[7][7]==num){
        ui->pushButton_77->setIcon(king);
    }
    //
    QIcon bking;
    QImage image12(":/img/img/bking.png");
    bking.addPixmap(QPixmap::fromImage(image12));
    num=12;
    if(tabu->Mostratabul()[0][0]==num){
        ui->pushButton_00->setIcon(bking);
    }
    if(tabu->Mostratabul()[0][1]==num){
        ui->pushButton_01->setIcon(bking);
    }
    if(tabu->Mostratabul()[0][2]==num){
        ui->pushButton_02->setIcon(bking);
    }
    if(tabu->Mostratabul()[0][3]==num){
        ui->pushButton_03->setIcon(bking);
    }
    if(tabu->Mostratabul()[0][4]==num){
        ui->pushButton_04->setIcon(bking);
    }
    if(tabu->Mostratabul()[0][5]==num){
        ui->pushButton_05->setIcon(bking);
    }
    if(tabu->Mostratabul()[0][6]==num){
        ui->pushButton_06->setIcon(bking);
    }
    if(tabu->Mostratabul()[0][7]==num){
        ui->pushButton_07->setIcon(bking);
    }
    //
    if(tabu->Mostratabul()[1][0]==num){
        ui->pushButton_10->setIcon(bking);
    }
    if(tabu->Mostratabul()[1][1]==num){
        ui->pushButton_11->setIcon(bking);
    }
    if(tabu->Mostratabul()[1][2]==num){
        ui->pushButton_12->setIcon(bking);
    }
    if(tabu->Mostratabul()[1][3]==num){
        ui->pushButton_13->setIcon(bking);
    }
    if(tabu->Mostratabul()[1][4]==num){
        ui->pushButton_14->setIcon(bking);
    }
    if(tabu->Mostratabul()[1][5]==num){
        ui->pushButton_15->setIcon(bking);
    }
    if(tabu->Mostratabul()[1][6]==num){
        ui->pushButton_16->setIcon(bking);
    }
    if(tabu->Mostratabul()[1][7]==num){
        ui->pushButton_17->setIcon(bking);
    }
    //
    if(tabu->Mostratabul()[2][0]==num){
        ui->pushButton_20->setIcon(bking);
    }
    if(tabu->Mostratabul()[2][1]==num){
        ui->pushButton_21->setIcon(bking);
    }
    if(tabu->Mostratabul()[2][2]==num){
        ui->pushButton_22->setIcon(bking);
    }
    if(tabu->Mostratabul()[2][3]==num){
        ui->pushButton_23->setIcon(bking);
    }
    if(tabu->Mostratabul()[2][4]==num){
        ui->pushButton_24->setIcon(bking);
    }
    if(tabu->Mostratabul()[2][5]==num){
        ui->pushButton_25->setIcon(bking);
    }
    if(tabu->Mostratabul()[2][6]==num){
        ui->pushButton_26->setIcon(bking);
    }
    if(tabu->Mostratabul()[2][7]==num){
        ui->pushButton_27->setIcon(bking);
    }
    //
    if(tabu->Mostratabul()[3][0]==num){
        ui->pushButton_30->setIcon(bking);
    }
    if(tabu->Mostratabul()[3][1]==num){
        ui->pushButton_31->setIcon(bking);
    }
    if(tabu->Mostratabul()[3][2]==num){
        ui->pushButton_32->setIcon(bking);
    }
    if(tabu->Mostratabul()[3][3]==num){
        ui->pushButton_33->setIcon(bking);
    }
    if(tabu->Mostratabul()[3][4]==num){
        ui->pushButton_34->setIcon(bking);
    }
    if(tabu->Mostratabul()[3][5]==num){
        ui->pushButton_35->setIcon(bking);
    }
    if(tabu->Mostratabul()[3][6]==num){
        ui->pushButton_36->setIcon(bking);
    }
    if(tabu->Mostratabul()[3][7]==num){
        ui->pushButton_37->setIcon(bking);
    }
    //
    if(tabu->Mostratabul()[4][0]==num){
        ui->pushButton_40->setIcon(bking);
    }
    if(tabu->Mostratabul()[4][1]==num){
        ui->pushButton_41->setIcon(bking);
    }
    if(tabu->Mostratabul()[4][2]==num){
        ui->pushButton_42->setIcon(bking);
    }
    if(tabu->Mostratabul()[4][3]==num){
        ui->pushButton_43->setIcon(bking);
    }
    if(tabu->Mostratabul()[4][4]==num){
        ui->pushButton_44->setIcon(bking);
    }
    if(tabu->Mostratabul()[4][5]==num){
        ui->pushButton_45->setIcon(bking);
    }
    if(tabu->Mostratabul()[4][6]==num){
        ui->pushButton_46->setIcon(bking);
    }
    if(tabu->Mostratabul()[4][7]==num){
        ui->pushButton_47->setIcon(bking);
    }
    //
    if(tabu->Mostratabul()[5][0]==num){
        ui->pushButton_50->setIcon(bking);
    }
    if(tabu->Mostratabul()[5][1]==num){
        ui->pushButton_51->setIcon(bking);
    }
    if(tabu->Mostratabul()[5][2]==num){
        ui->pushButton_52->setIcon(bking);
    }
    if(tabu->Mostratabul()[5][3]==num){
        ui->pushButton_53->setIcon(bking);
    }
    if(tabu->Mostratabul()[5][4]==num){
        ui->pushButton_54->setIcon(bking);
    }
    if(tabu->Mostratabul()[5][5]==num){
        ui->pushButton_55->setIcon(bking);
    }
    if(tabu->Mostratabul()[5][6]==num){
        ui->pushButton_56->setIcon(bking);
    }
    if(tabu->Mostratabul()[5][7]==num){
        ui->pushButton_57->setIcon(bking);
    }
    //
    if(tabu->Mostratabul()[6][0]==num){
        ui->pushButton_60->setIcon(bking);
    }
    if(tabu->Mostratabul()[6][1]==num){
        ui->pushButton_61->setIcon(bking);
    }
    if(tabu->Mostratabul()[6][2]==num){
        ui->pushButton_62->setIcon(bking);
    }
    if(tabu->Mostratabul()[6][3]==num){
        ui->pushButton_63->setIcon(bking);
    }
    if(tabu->Mostratabul()[6][4]==num){
        ui->pushButton_64->setIcon(bking);
    }
    if(tabu->Mostratabul()[6][5]==num){
        ui->pushButton_65->setIcon(bking);
    }
    if(tabu->Mostratabul()[6][6]==num){
        ui->pushButton_66->setIcon(bking);
    }
    if(tabu->Mostratabul()[6][7]==num){
        ui->pushButton_67->setIcon(bking);
    }
    //
    if(tabu->Mostratabul()[7][0]==num){
        ui->pushButton_70->setIcon(bking);
    }
    if(tabu->Mostratabul()[7][1]==num){
        ui->pushButton_71->setIcon(bking);
    }
    if(tabu->Mostratabul()[7][2]==num){
        ui->pushButton_72->setIcon(bking);
    }
    if(tabu->Mostratabul()[7][3]==num){
        ui->pushButton_73->setIcon(bking);
    }
    if(tabu->Mostratabul()[7][4]==num){
        ui->pushButton_74->setIcon(bking);
    }
    if(tabu->Mostratabul()[7][5]==num){
        ui->pushButton_75->setIcon(bking);
    }
    if(tabu->Mostratabul()[7][6]==num){
        ui->pushButton_76->setIcon(bking);
    }
    if(tabu->Mostratabul()[7][7]==num){
        ui->pushButton_77->setIcon(bking);
    }
    //

    QIcon nada;
    num=0;
    if(tabu->Mostratabul()[0][0]==num){
        ui->pushButton_00->setIcon(nada);
    }
    if(tabu->Mostratabul()[0][1]==num){
        ui->pushButton_01->setIcon(nada);
    }
    if(tabu->Mostratabul()[0][2]==num){
        ui->pushButton_02->setIcon(nada);
    }
    if(tabu->Mostratabul()[0][3]==num){
        ui->pushButton_03->setIcon(nada);
    }
    if(tabu->Mostratabul()[0][4]==num){
        ui->pushButton_04->setIcon(nada);
    }
    if(tabu->Mostratabul()[0][5]==num){
        ui->pushButton_05->setIcon(nada);
    }
    if(tabu->Mostratabul()[0][6]==num){
        ui->pushButton_06->setIcon(nada);
    }
    if(tabu->Mostratabul()[0][7]==num){
        ui->pushButton_07->setIcon(nada);
    }
    //
    if(tabu->Mostratabul()[1][0]==num){
        ui->pushButton_10->setIcon(nada);
    }
    if(tabu->Mostratabul()[1][1]==num){
        ui->pushButton_11->setIcon(nada);
    }
    if(tabu->Mostratabul()[1][2]==num){
        ui->pushButton_12->setIcon(nada);
    }
    if(tabu->Mostratabul()[1][3]==num){
        ui->pushButton_13->setIcon(nada);
    }
    if(tabu->Mostratabul()[1][4]==num){
        ui->pushButton_14->setIcon(nada);
    }
    if(tabu->Mostratabul()[1][5]==num){
        ui->pushButton_15->setIcon(nada);
    }
    if(tabu->Mostratabul()[1][6]==num){
        ui->pushButton_16->setIcon(nada);
    }
    if(tabu->Mostratabul()[1][7]==num){
        ui->pushButton_17->setIcon(nada);
    }
    //
    if(tabu->Mostratabul()[2][0]==num){
        ui->pushButton_20->setIcon(nada);
    }
    if(tabu->Mostratabul()[2][1]==num){
        ui->pushButton_21->setIcon(nada);
    }
    if(tabu->Mostratabul()[2][2]==num){
        ui->pushButton_22->setIcon(nada);
    }
    if(tabu->Mostratabul()[2][3]==num){
        ui->pushButton_23->setIcon(nada);
    }
    if(tabu->Mostratabul()[2][4]==num){
        ui->pushButton_24->setIcon(nada);
    }
    if(tabu->Mostratabul()[2][5]==num){
        ui->pushButton_25->setIcon(nada);
    }
    if(tabu->Mostratabul()[2][6]==num){
        ui->pushButton_26->setIcon(nada);
    }
    if(tabu->Mostratabul()[2][7]==num){
        ui->pushButton_27->setIcon(nada);
    }
    //
    if(tabu->Mostratabul()[3][0]==num){
        ui->pushButton_30->setIcon(nada);
    }
    if(tabu->Mostratabul()[3][1]==num){
        ui->pushButton_31->setIcon(nada);
    }
    if(tabu->Mostratabul()[3][2]==num){
        ui->pushButton_32->setIcon(nada);
    }
    if(tabu->Mostratabul()[3][3]==num){
        ui->pushButton_33->setIcon(nada);
    }
    if(tabu->Mostratabul()[3][4]==num){
        ui->pushButton_34->setIcon(nada);
    }
    if(tabu->Mostratabul()[3][5]==num){
        ui->pushButton_35->setIcon(nada);
    }
    if(tabu->Mostratabul()[3][6]==num){
        ui->pushButton_36->setIcon(nada);
    }
    if(tabu->Mostratabul()[3][7]==num){
        ui->pushButton_37->setIcon(nada);
    }
    //
    if(tabu->Mostratabul()[4][0]==num){
        ui->pushButton_40->setIcon(nada);
    }
    if(tabu->Mostratabul()[4][1]==num){
        ui->pushButton_41->setIcon(nada);
    }
    if(tabu->Mostratabul()[4][2]==num){
        ui->pushButton_42->setIcon(nada);
    }
    if(tabu->Mostratabul()[4][3]==num){
        ui->pushButton_43->setIcon(nada);
    }
    if(tabu->Mostratabul()[4][4]==num){
        ui->pushButton_44->setIcon(nada);
    }
    if(tabu->Mostratabul()[4][5]==num){
        ui->pushButton_45->setIcon(nada);
    }
    if(tabu->Mostratabul()[4][6]==num){
        ui->pushButton_46->setIcon(nada);
    }
    if(tabu->Mostratabul()[4][7]==num){
        ui->pushButton_47->setIcon(nada);
    }
    //
    if(tabu->Mostratabul()[5][0]==num){
        ui->pushButton_50->setIcon(nada);
    }
    if(tabu->Mostratabul()[5][1]==num){
        ui->pushButton_51->setIcon(nada);
    }
    if(tabu->Mostratabul()[5][2]==num){
        ui->pushButton_52->setIcon(nada);
    }
    if(tabu->Mostratabul()[5][3]==num){
        ui->pushButton_53->setIcon(nada);
    }
    if(tabu->Mostratabul()[5][4]==num){
        ui->pushButton_54->setIcon(nada);
    }
    if(tabu->Mostratabul()[5][5]==num){
        ui->pushButton_55->setIcon(nada);
    }
    if(tabu->Mostratabul()[5][6]==num){
        ui->pushButton_56->setIcon(nada);
    }
    if(tabu->Mostratabul()[5][7]==num){
        ui->pushButton_57->setIcon(nada);
    }
    //
    if(tabu->Mostratabul()[6][0]==num){
        ui->pushButton_60->setIcon(nada);
    }
    if(tabu->Mostratabul()[6][1]==num){
        ui->pushButton_61->setIcon(nada);
    }
    if(tabu->Mostratabul()[6][2]==num){
        ui->pushButton_62->setIcon(nada);
    }
    if(tabu->Mostratabul()[6][3]==num){
        ui->pushButton_63->setIcon(nada);
    }
    if(tabu->Mostratabul()[6][4]==num){
        ui->pushButton_64->setIcon(nada);
    }
    if(tabu->Mostratabul()[6][5]==num){
        ui->pushButton_65->setIcon(nada);
    }
    if(tabu->Mostratabul()[6][6]==num){
        ui->pushButton_66->setIcon(nada);
    }
    if(tabu->Mostratabul()[6][7]==num){
        ui->pushButton_67->setIcon(nada);
    }
    //
    if(tabu->Mostratabul()[7][0]==num){
        ui->pushButton_70->setIcon(nada);
    }
    if(tabu->Mostratabul()[7][1]==num){
        ui->pushButton_71->setIcon(nada);
    }
    if(tabu->Mostratabul()[7][2]==num){
        ui->pushButton_72->setIcon(nada);
    }
    if(tabu->Mostratabul()[7][3]==num){
        ui->pushButton_73->setIcon(nada);
    }
    if(tabu->Mostratabul()[7][4]==num){
        ui->pushButton_74->setIcon(nada);
    }
    if(tabu->Mostratabul()[7][5]==num){
        ui->pushButton_75->setIcon(nada);
    }
    if(tabu->Mostratabul()[7][6]==num){
        ui->pushButton_76->setIcon(nada);
    }
    if(tabu->Mostratabul()[7][7]==num){
        ui->pushButton_77->setIcon(nada);
    }
    //
}



void MainWindow::on_actionNovo_triggered()
{    
    tabu->novojogo();
    ui->toolButton->click();

}

void MainWindow::on_actionSair_triggered()
{
    tabu->~Tabuleiro();
    MainWindow::close();

}

void MainWindow::on_actionAbrir_triggered()
{

    QString name = QFileDialog::getOpenFileName(this, "Abrir");
    if(!name.isEmpty()){
        tabu->abrir(name);
        ui->toolButton->click();
    }


}

void MainWindow::on_actionSalvar_triggered()
{
    if(tabu->nomedoarquivo.isEmpty()){
        on_actionSalvar_como_triggered();
    }else{
        if(tabu->salvar()){
            ui->salvo->setVisible(true);
        }
    }
}

void MainWindow::on_actionSalvar_como_triggered()
{
    QString name = QFileDialog::getSaveFileName(this, "Salvar");
    if(!name.isEmpty()){
        tabu->nomedoarquivo=name;
        if(tabu->salvar()){
            ui->salvo->setVisible(true);
        }


    }

}
