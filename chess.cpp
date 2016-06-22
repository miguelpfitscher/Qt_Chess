#include "chess.h"

Tabuleiro::Tabuleiro(){
    int **tabul = (int**) malloc(8 * sizeof (int*));
    int i;
    for (i = 0; i <= 7; i++) {
        *(tabul + i) = (int*) malloc(8 * sizeof (int));

    }
    sel=true;
    branco=true;
    hist=false;
    fechou=false;
    ya=0;
    contagem=0;
    stalemate=false;
    numb.clear();
    nump.clear();
    reiandoub=false;
    reiandoup=false;
    check=false;
    escolheu=false;
    nomedoarquivo="";
    iniciatab(tabul);
    tab=tabul;
}
int** Tabuleiro::Mostratabul(){
    return tab;
}
void Tabuleiro::pecaanda(){
    if (tab[x][y] != 0) {
        if (branco == true) {
            if (tab[x][y] % 2 != 0) {
                if (tab[x][y] == 1) {
                    if (calc_block(tab, x, y, xn, yn, true)) {
                        peaoanda(tab, x, y, hist, ya, xn, yn, branco);
                        if (calc_posi_rei(tab, xn,yn, branco)) {
                            check=true;

                        }
                        if(!branco){
                            contagem++;
                        }
                    }
                } else if (tab[x][y] == 3) {
                    if (calc_block(tab, x, y, xn, yn, true)) {
                        cavaloanda(tab, x, y, xn, yn, branco);
                        if (calc_posi_rei(tab, xn,yn, branco)) {
                            check=true;
                        }
                        if(!branco){
                            contagem++;
                        }
                    }
                } else if (tab[x][y] == 5) {
                    if (calc_block(tab, x, y, xn, yn, true)) {
                        bispoanda(tab, x, y, xn, yn, branco);
                        if (calc_posi_rei(tab, xn,yn, branco)) {
                            check=true;

                        }
                        if(!branco){
                            contagem++;
                        }

                    }
                } else if (tab[x][y] == 7) {
                    if (calc_block(tab, x, y, xn, yn, true)) {
                        torreanda(tab, x, y, xn, yn, branco);
                        if (calc_posi_rei(tab, xn,yn, branco)) {
                            check=true;

                        }
                        if(!branco){
                            contagem++;
                        }
                    }
                } else if (tab[x][y] == 9) {
                    if (calc_block(tab, x, y, xn, yn, true)) {
                        rainhaanda(tab, x, y, xn, yn, branco);
                        if (calc_posi_rei(tab, xn,yn, branco)) {
                            check=true;

                        }
                        if(!branco){
                            contagem++;
                        }

                    }
                } else if (tab[x][y] == 11) {
                    reianda(tab, x, y, reiandoub, xn,yn, branco);
                    if(!branco){
                        contagem++;
                    }
                }
            }
        } else {
            if (tab[x][y] % 2 == 0) {
                if (tab[x][y] == 2) {
                    if (calc_block(tab, x, y, xn, yn, false)) {
                        peaoanda(tab, x, y, hist, ya, xn, yn, branco);
                        if (calc_posi_rei(tab, xn,yn, branco)) {
                            check=true;

                        }
                        if(branco){
                            contagem++;
                        }
                    }

                } else if (tab[x][y] == 4) {
                    if (calc_block(tab, x, y, xn, yn, false)) {
                        cavaloanda(tab, x, y, xn, yn, branco);
                        if (calc_posi_rei(tab, xn,yn, branco)) {
                            check=true;

                        }
                        if(branco){
                            contagem++;
                        }
                    }
                } else if (tab[x][y] == 6) {
                    if (calc_block(tab, x, y, xn, yn, false)) {
                        bispoanda(tab, x, y, xn, yn, branco);
                        if (calc_posi_rei(tab, xn,yn, branco)) {
                            check=true;

                        }
                        if(branco){
                            contagem++;
                        }
                    }
                } else if (tab[x][y] == 8) {
                    if (calc_block(tab, x, y, xn, yn, false)) {
                        torreanda(tab, x, y, xn, yn, branco);
                        if (calc_posi_rei(tab, xn,yn, branco)) {
                            check=true;

                        }
                        if(branco){
                            contagem++;
                        }
                    }
                } else if (tab[x][y] == 10) {
                    if (calc_block(tab, x, y, xn, yn, false)) {
                        rainhaanda(tab, x, y, xn, yn, branco);
                        if (calc_posi_rei(tab, xn,yn, branco)) {
                            check=true;

                        }
                        if(branco){
                            contagem++;
                        }
                    }
                } else if (tab[x][y] == 12) {
                    reianda(tab, x, y, reiandoup, xn,yn, branco);
                    if(branco){
                        contagem++;
                    }

                }
            }
        }
        calc_stalemate();
        if(stalemate||contagem>=50){
            stalemate=true;
            checkmate acabou;
            acabou.exec();
        }
    }
}
Tabuleiro::~Tabuleiro()
{
    for(int i; i<=7; i++){
        free(*(tab+i));
    }
    free(tab);
}
void Tabuleiro::iniciatab(int **tabol) {
    int i;
    for (i = 0; i <= 7; i++) {
        //peao branco 1, peao preto 2
        tabol[1][i] = 1;
        tabol[6][i] = 2;
    }
    //cavalo branco 3, cavalo preto 4
    tabol[0][1] = 3;
    tabol[0][6] = 3;
    tabol[7][6] = 4;
    tabol[7][1] = 4;
    //bispo branco 5, bispo preto 6;
    tabol[0][2] = 5;
    tabol[0][5] = 5;
    tabol[7][5] = 6;
    tabol[7][2] = 6;
    //torre branca 7, torre preta 8;
    tabol[0][0] = 7;
    tabol[0][7] = 7;
    tabol[7][0] = 8;
    tabol[7][7] = 8;
    //rainha branca 9, rainha preta 10;
    tabol[0][3] = 9;
    tabol[7][3] = 10;

    //rei branco 11; rei preto 12;
    tabol[0][4] = 11;
    tabol[7][4] = 12;
    for(i=2; i<=5; i++){
        for(int j=0; j<=7; j++){
            tabol[i][j]=0;
        }
    }
}

void Tabuleiro::novojogo(){
    iniciatab(tab);
    sel=true;
    branco=true;
    hist=false;
    check=false;
    escolheu=false;
    fechou=false;
    stalemate=false;
    contagem=0;
    nump.clear();
    numb.clear();
    ya=0;
    nomedoarquivo="";
    reiandoub=false;
    reiandoup=false;
}
bool Tabuleiro::salvar(){
    QFile salv(nomedoarquivo);
    if(salv.open(QFile::WriteOnly)){
        char *t=(char*) malloc(97 * sizeof (char));
        for(int i=0; i<=7; i++){
            for(int j=0; j<=7; j++){
                *(t+i*8+j)=tab[i][j];
            }
        }
        if(branco==true){
            *(t+64)=15;
        }
        if(branco==false){
            *(t+64)=16;
        }
        for(int i=0; i<=15; i++){
            *(t+i+65)=numb.value(i);
        }
        for(int i=0; i<=15; i++){
            *(t+i+81)=nump.value(i);
        }
        salv.write(t, 97);
        free(t);
        salv.close();
        return true;
    }
    return false;
}

void Tabuleiro::abrir(QString name){
    QFile nova(name);
    if(nova.open(QFile::ReadOnly)){
        char *t=(char*) malloc(97 * sizeof (char));
        nova.read(t, 97);
        for(int i=0; i<=7; i++){
            for(int j=0; j<=7; j++){
                tab[i][j]=*(t+i*8+j);
            }
        }
        if(*(t+64)==15){
            branco=true;
        }
        if(*(t+64)==16){
            branco=false;
        }
        for(int i=0; i<=15; i++){
            numb.append(*(t+i+65));
        }
        for(int i=0; i<=15; i++){
            nump.append(*(t+i+81));
        }
        nomedoarquivo=name;
        free(t);
        nova.close();
    }


}

void roque(int **tab, int yn, bool reiandou, bool &branco) {
    int i, j, t, r;

    if (branco) {
        i = 0;
        t = 7;
        r = 11;
    } else {
        i = 7;
        t = 8;
        r = 12;
    }
    if (!reiandou) {
        if (yn == 6) {
            for (j = 5; j < 7; j++) {
                if (tab[i][j] != 0) {
                    return;
                }
            }
            if (branco) {
                if (calc_checkwhite(tab,  i, 6, 0, yn)) {
                    return;
                }
                if (calc_checkwhite(tab,  i, 5, 0, yn)) {
                    return;
                }
            } else {
                if (calc_checkblack(tab,  i, 6, 7,yn)) {
                    return;
                }
                if (calc_checkblack(tab,  i, 5, 7,yn)) {
                    return;
                }
            }
            if (tab[i][7] == t) {
                tab[i][7] = 0;
                tab[i][6] = r;
                tab[i][5] = t;
                tab[i][4] = 0;
                branco=not branco;
            }
        } else if (yn == 2) {
            for (j = 3; j > 0; j--) {
                if (tab[i][j] != 0) {
                    return;
                }
            }
            if (branco) {
                if (calc_checkwhite(tab,  i, 2, 0,yn)) {
                    return;
                }
                if (calc_checkwhite(tab,  i, 3, 0,yn)) {
                    return;
                }
            } else {
                if (calc_checkblack(tab,  i, 2, 7,yn)) {
                    return;
                }
                if (calc_checkblack(tab,  i, 3, 7,yn)) {
                    return;
                }
            }
            if (tab[i][0] == t) {
                tab[i][0] = 0;
                tab[i][2] = r;
                tab[i][3] = t;
                tab[i][4] = 0;
                branco=not branco;
            }
        }
    }
}



void Tabuleiro::peaoanda(int **tab, int x, int y, bool &hist, int &ya, int xn, int yn, bool &branco) {

    int i, j;
    int guardacont;
    if (tab[x][y] == 1 && x == 1) {

        if ((((xn - x) == 2 || xn - x == 1))&&(tab[xn][yn] == 0) && yn == y) {

            if (xn - x == 2 && tab[xn-1][yn]==0) {
                hist = true;
                ya = y;
                tab[x][y] = 0;
                tab[xn][yn] = 1;
                branco=false;

            } else if(xn-x==1) {
                hist = false;
                tab[x][y] = 0;
                tab[xn][yn] = 1;
                branco=false;
            }


        } else if ((abs(yn - y) == 1)&&(xn - x) == 1 && tab[xn][yn] != 0 && tab[xn][yn]%2==0) {
            tab[x][y] = 0;
            hist = false;

            numb.append(tab[xn][yn]);
            tab[xn][yn] = 1;
            branco=false;

        }
        if(!branco){
            guardacont=contagem;
            contagem=0;
        }
    } else if (tab[x][y] == 2 && x == 6) {
        if (((x - xn) <= 2)&&(tab[xn][yn] == 0) && yn == y) {

            if (x - xn == 2&&tab[xn+1][y]==0) {
                hist = true;
                tab[x][y] = 0;
                tab[xn][y] = 2;
                branco=true;
                ya = y;
            } else if(x-xn==1){
                hist = false;
                tab[x][y] = 0;
                tab[xn][y] = 2;
                branco=true;
            }

        } else if ((abs(yn - y) == 1)&&(x - xn) == 1 && tab[xn][yn]%2!=0) {
            tab[x][y] = 0;

            nump.append(tab[xn][yn]);
            tab[xn][yn] = 2;
            branco=true;
            hist = false;
        }
        if(branco){
            guardacont=contagem;
            contagem=0;
        }
    } else if (tab[x][y] == 1) {

        if ((xn - x == 1)&&(tab[xn][yn] == 0) && yn == y) {
            hist = false;
            tab[x][y] = 0;
            branco=false;
            if (xn == 7) {
                choosewhite escolha;
                escolha.setModal(true);
                escolha.exec();

            } else {
                tab[xn][yn] = 1;
            }
        } else if ((abs(yn - y) == 1)&&(xn - x) == 1 && (tab[xn][yn]%2==0&&(tab[xn][yn] != 0) || (hist && ya == yn))) {
            tab[x][y] = 0;
            branco=false;
            if (xn == 7) {

                numb.append(tab[xn][yn]);
                choosewhite escolha;
                escolha.setModal(true);
                escolha.exec();
            } else {
                if (hist&&xn==5&&tab[xn - 1][ya]==2) {

                    numb.append(2);
                    tab[xn - 1][ya] = 0;
                    hist = false;
                }else{
                    numb.append(tab[xn][yn]);
                }

                tab[xn][yn] = 1;
            }
        }
        if(!branco){
            guardacont=contagem;
            contagem=0;
        }
    } else {
        if ((x - xn == 1)&&(tab[xn][yn] == 0) && yn == y) {
            tab[x][y] = 0;
            hist = false;
            branco=true;
            if (xn == 0) {
                chooseblack escolha;
                escolha.setModal(true);
                escolha.exec();

            } else {

                tab[xn][yn] = 2;
            }
        } else if ((abs(yn - y) == 1)&&(x - xn) == 1 && ((tab[xn][yn] %2!= 0) || (hist && ya == yn))) {
            tab[x][y] = 0;
            branco=true;
            if (xn == 0) {

                nump.append(tab[xn][yn]);
                chooseblack escolha;
                escolha.setModal(true);
                escolha.exec();
                hist = false;
            } else {
                if (hist&&xn==2&&tab[xn + 1][ya]==1) {
                    nump.append(1);
                    tab[xn + 1][ya] = 0;
                    hist = false;
                }else{
                    nump.append(tab[xn][yn]);
                }

                tab[xn][yn] = 2;
            }
        }
        if(branco){
            guardacont=contagem;
            contagem=0;
        }
    }

    if (tab[xn][yn] == 1 && tab[x][y] == 0) {
        for (i = 0; i <= 7; i++) {
            for (j = 0; j <= 7; j++) {
                if (tab[i][j] == 11) {
                    break;
                }
            }
            if (tab[i][j] == 11) {
                break;
            }
        }
        if (calc_checkwhite(tab,  i, j, xn, yn)) {
            tab[xn][yn] = 0;
            tab[x][y] = 1;
            branco=true;
            contagem=guardacont;
        }
    } else if (tab[xn][yn] == 2 && tab[x][y] == 0) {
        for (i = 0; i <= 7; i++) {
            for (j = 0; j <= 7; j++) {
                if (tab[i][j] == 12) {
                    break;
                }
            }
            if (tab[i][j] == 12) {
                break;
            }
        }
        if (calc_checkblack(tab,  i, j, xn, yn)) {
            tab[xn][yn] = 0;
            tab[x][y] = 2;
            branco=false;
            contagem=guardacont;
        }
    }
}


void Tabuleiro::cavaloanda(int **tab, int x, int y, int xn, int yn, bool &branco) {
    int j, i, guardacont;
    if (tab[x][y] == 3) {
        if (tab[xn][yn] % 2 == 0) {
            if ((xn == 2 + x && yn == y + 1 || xn + 2 == x && yn + 1 == y || xn + 1 == x && yn + 2 == y || xn == x + 1 && yn == y + 2 || xn == 2 + x && yn + 1 == y || xn + 2 == x && yn == y + 1 || xn == x + 1 && yn + 2 == y || xn + 1 == x && yn == y + 2)) {
                tab[x][y] = 0;
                if(tab[xn][yn]!=0){

                    guardacont=contagem;
                    contagem=0;
                    numb.append(tab[xn][yn]);
                }
                tab[xn][yn] = 3;
                branco=false;
            }
        }

    } else {
        if (tab[xn][yn] % 2 != 0 || tab[xn][yn] == 0) {
            if ((xn == 2 + x && yn == y + 1 || xn + 2 == x && yn + 1 == y || xn + 1 == x && yn + 2 == y || xn == x + 1 && yn == y + 2 || xn == 2 + x && yn + 1 == y || xn + 2 == x && yn == y + 1 || xn == x + 1 && yn + 2 == y || xn + 1 == x && yn == y + 2)) {
                tab[x][y] = 0;
                if(tab[xn][yn]!=0){

                    guardacont=contagem;
                    contagem=0;
                    nump.append(tab[xn][yn]);
                }
                tab[xn][yn] = 4;
                branco=true;
            }
        }
    }
    if (tab[xn][yn] == 3 && tab[x][y] == 0) {
        for (i = 0; i <= 7; i++) {
            for (j = 0; j <= 7; j++) {
                if (tab[i][j] == 11) {
                    break;
                }
            }
            if (tab[i][j] == 11) {
                break;
            }
        }
        if (calc_checkwhite(tab,  i, j, xn, yn)) {
            tab[xn][yn] = 0;
            tab[x][y] = 3;
            contagem=guardacont;

            branco=true;

        }
    } else if (tab[xn][yn] == 4 && tab[x][y] == 0) {
        for (i = 0; i <= 7; i++) {
            for (j = 0; j <= 7; j++) {
                if (tab[i][j] == 12) {
                    break;
                }
            }
            if (tab[i][j] == 12) {
                break;
            }
        }
        if (calc_checkblack(tab,  i, j, xn, yn)) {
            tab[xn][yn] = 0;
            tab[x][y] = 4;
            contagem=guardacont;

            branco=false;

        }
    }
}

void Tabuleiro::bispoanda(int **tab, int x, int y, int xn, int yn, bool &branco) {
    bool anda = true;
    int guardacont;
    int i, j;
    if (tab[x][y] == 5) {
        if ((xn + yn) == (x + y) || abs(xn - yn) == abs(x - y)) {

            if (xn > x && yn > y) {
                int i, j = y + 1;
                for (i = x + 1; i < xn; i++) {
                    if (tab[i][j] != 0) {
                        anda = false;
                    }
                    j++;
                }
            } else if (xn < x && yn > y) {
                int i, j = y + 1;
                for (i = x - 1; i > xn; i--) {
                    if (tab[i][j] != 0) {
                        anda = false;
                    }
                    j++;
                }
            } else if (xn > x && yn < y) {
                int i, j = y - 1;
                for (i = x + 1; i < xn; i++) {
                    if (tab[i][j] != 0) {
                        anda = false;
                    }
                    j--;
                }
            } else if (xn < x && yn < y) {
                int i, j = y - 1;
                for (i = x - 1; i > xn; i--) {
                    if (tab[i][j] != 0) {
                        anda = false;
                    }
                    j--;
                }
            }
            if (tab[xn][yn] % 2 != 0) {
                anda = false;
            }
            if (anda) {
                tab[x][y] = 0;
                if(tab[xn][yn]!=0){
                    guardacont=contagem;
                    contagem=0;

                    numb.append(tab[xn][yn]);
                }
                tab[xn][yn] = 5;
                branco=false;
            }
        }
    } else {
        if (((xn + yn) == (x + y) || abs(xn - yn) == abs(x - y))) {

            if (xn > x && yn > y) {
                int i, j = y + 1;
                for (i = x + 1; i < xn; i++) {
                    if (tab[i][j] != 0) {
                        anda = false;
                    }
                    j++;
                }
            } else if (xn < x && yn > y) {
                int i, j = y + 1;
                for (i = x - 1; i > xn; i--) {
                    if (tab[i][j] != 0) {
                        anda = false;
                    }
                    j++;
                }
            } else if (xn > x && yn < y) {
                int i, j = y - 1;
                for (i = x + 1; i < xn; i++) {
                    if (tab[i][j] != 0) {
                        anda = false;
                    }
                    j--;
                }
            } else if (xn < x && yn < y) {
                int i, j = y - 1;
                for (i = x - 1; i > xn; i--) {
                    if (tab[i][j] != 0) {
                        anda = false;
                    }
                    j--;
                }
            }
            if (tab[xn][yn] % 2 == 0 && tab[xn][yn] != 0) {
                anda = false;
            }
            if (anda) {
                tab[x][y] = 0;
                if(tab[xn][yn]!=0){
                    guardacont=contagem;
                    contagem=0;

                    nump.append(tab[xn][yn]);
                }
                tab[xn][yn] = 6;
                branco=true;
            }
        }
    }
    if (tab[xn][yn] == 5 && tab[x][y] == 0) {
        for (i = 0; i <= 7; i++) {
            for (j = 0; j <= 7; j++) {
                if (tab[i][j] == 11) {
                    break;
                }
            }
            if (tab[i][j] == 11) {
                break;
            }
        }
        if (calc_checkwhite(tab,  i, j, xn, yn)) {
            tab[xn][yn] = 0;
            tab[x][y] = 5;
            contagem=guardacont;

            branco=true;
        }
    } else if (tab[xn][yn] == 6 && tab[x][y] == 0) {
        for (i = 0; i <= 7; i++) {
            for (j = 0; j <= 7; j++) {
                if (tab[i][j] == 12) {
                    break;
                }
            }
            if (tab[i][j] == 12) {
                break;
            }
        }
        if (calc_checkblack(tab,  i, j, xn, yn)) {
            tab[xn][yn] = 0;
            tab[x][y] = 6;
            contagem=guardacont;


            branco=false;
        }
    }
}

void Tabuleiro::torreanda(int **tab, int x, int y, int xn, int yn, bool &branco) {
    int i;
    bool anda = true;
    int guardacont;
    int j;
    if (tab[x][y] == 7) {
        if (xn == x) {
            if (y < yn) {
                for (i = y + 1; i < yn; i++) {
                    if (tab[xn][i] != 0) {
                        anda = false;
                    }
                }
            } else if (y > yn) {
                for (i = y - 1; i > yn; i--) {
                    if (tab[xn][i] != 0) {
                        anda = false;
                    }
                }
            }
        } else if (yn == y) {
            if (x < xn) {
                for (i = x + 1; i < xn; i++) {
                    if (tab[i][yn] != 0) {
                        anda = false;
                    }
                }
            } else if (y > yn) {
                for (i = x - 1; i > xn; i--) {
                    if (tab[i][yn] != 0) {
                        anda = false;
                    }
                }
            }
        }else{
            anda=false;
        }
        if (tab[xn][yn] % 2 != 0) {
            anda = false;
        }
        if (anda) {
            tab[x][y] = 0;
            if(tab[xn][yn]!=0){

                guardacont=contagem;
                contagem=0;
                numb.append(tab[xn][yn]);
            }
            tab[xn][yn] = 7;
            branco=false;
        }
    } else {
        if (xn == x) {
            if (y < yn) {
                for (i = y + 1; i < yn; i++) {
                    if (tab[xn][i] != 0) {
                        anda = false;
                    }
                }
            } else if (y > yn) {
                for (i = y - 1; i > yn; i--) {
                    if (tab[xn][i] != 0) {
                        anda = false;
                    }
                }
            }
        } else if (yn == y) {
            if (x < xn) {
                for (i = x + 1; i < xn; i++) {
                    if (tab[i][yn] != 0) {
                        anda = false;
                    }
                }
            } else if (y > yn) {
                for (i = x - 1; i > xn; i--) {
                    if (tab[i][yn] != 0) {
                        anda = false;
                    }
                }
            }
        }else{
            anda=false;
        }
        if (tab[xn][yn] % 2 == 0 && tab[xn][yn] != 0) {
            anda = false;
        }
        if (anda) {
            tab[x][y] = 0;
            if(tab[xn][yn]!=0){

                guardacont=contagem;
                contagem=0;
                nump.append(tab[xn][yn]);
            }
            tab[xn][yn] = 8;
            branco=true;
        }
    }
    if (tab[xn][yn] == 7 && tab[x][y] == 0) {
        for (i = 0; i <= 7; i++) {
            for (j = 0; j <= 7; j++) {
                if (tab[i][j] == 11) {
                    break;
                }
            }
            if (tab[i][j] == 11) {
                break;
            }
        }
        if (calc_checkwhite(tab,  i, j, xn, yn)) {
            tab[xn][yn] = 0;
            tab[x][y] = 7;
            contagem=guardacont;

            branco=true;
        }
    } else if (tab[xn][yn] == 8 && tab[x][y] == 0) {
        for (i = 0; i <= 7; i++) {
            for (j = 0; j <= 7; j++) {
                if (tab[i][j] == 12) {
                    break;
                }
            }
            if (tab[i][j] == 12) {
                break;
            }
        }
        if (calc_checkblack(tab,  i, j, xn, yn)) {
            tab[xn][yn] = 0;
            tab[x][y] = 8;
            contagem=guardacont;

            branco=false;
        }
    }
}

void Tabuleiro::rainhaanda(int **tab, int x, int y, int xn, int yn, bool &branco) {
    int i, j;
    bool anda = true;
    int guardacont;
    if (tab[x][y] == 9) {
        if ((xn + yn) == (x + y) || abs(xn - yn) == abs(x - y)) {

            if (xn > x && yn > y) {
                int i, j = y + 1;
                for (i = x + 1; i < xn; i++) {
                    if (tab[i][j] != 0) {
                        anda = false;
                    }
                    j++;
                }
            } else if (xn < x && yn > y) {
                int i, j = y + 1;
                for (i = x - 1; i > xn; i--) {
                    if (tab[i][j] != 0) {
                        anda = false;
                    }
                    j++;
                }
            } else if (xn > x && yn < y) {
                int i, j = y - 1;
                for (i = x + 1; i < xn; i++) {
                    if (tab[i][j] != 0) {
                        anda = false;
                    }
                    j--;
                }
            } else if (xn < x && yn < y) {
                int i, j = y - 1;
                for (i = x - 1; i > xn; i--) {
                    if (tab[i][j] != 0) {
                        anda = false;
                    }
                    j--;
                }
            }
            if (tab[xn][yn] % 2 != 0) {
                anda = false;
            }
            if (anda) {
                tab[x][y] = 0;
                if(tab[xn][yn]!=0){

                    guardacont=contagem;
                    contagem=0;
                    numb.append(tab[xn][yn]);
                }
                tab[xn][yn] = 9;
                branco=false;
            }
        }

        if (xn == x) {
            if (y < yn) {
                for (i = y + 1; i < yn; i++) {
                    if (tab[xn][i] != 0) {
                        anda = false;
                    }
                }
            } else if (y > yn) {
                for (i = y - 1; i > yn; i--) {
                    if (tab[xn][i] != 0) {
                        anda = false;
                    }
                }
            }
        } else if (yn == y) {
            if (x < xn) {
                for (i = x + 1; i < xn; i++) {
                    if (tab[i][yn] != 0) {
                        anda = false;
                    }
                }
            } else if (y > yn) {
                for (i = x - 1; i > xn; i--) {
                    if (tab[i][yn] != 0) {
                        anda = false;
                    }
                }
            }
        }else{
            anda=false;
        }
        if (tab[xn][yn] % 2 != 0) {
            anda = false;
        }
        if (anda) {
            tab[x][y] = 0;
            if(tab[xn][yn]!=0){

                guardacont=contagem;
                contagem=0;
                numb.append(tab[xn][yn]);
            }
            tab[xn][yn] = 9;
            branco=false;
        }
    } else {
        if ((xn + yn) == (x + y) || abs(xn - yn) == abs(x - y)) {

            if (xn > x && yn > y) {
                int i, j = y + 1;
                for (i = x + 1; i < xn; i++) {
                    if (tab[i][j] != 0) {
                        anda = false;
                    }
                    j++;
                }
            } else if (xn < x && yn > y) {
                int i, j = y + 1;
                for (i = x - 1; i > xn; i--) {
                    if (tab[i][j] != 0) {
                        anda = false;
                    }
                    j++;
                }
            } else if (xn > x && yn < y) {
                int i, j = y - 1;
                for (i = x + 1; i < xn; i++) {
                    if (tab[i][j] != 0) {
                        anda = false;
                    }
                    j--;
                }
            } else if (xn < x && yn < y) {
                int i, j = y - 1;
                for (i = x - 1; i > xn; i--) {
                    if (tab[i][j] != 0) {
                        anda = false;
                    }
                    j--;
                }
            }
            if (tab[xn][yn] % 2 == 0 && tab[xn][yn] != 0) {
                anda = false;
            }
            if (anda) {
                tab[x][y] = 0;
                if(tab[xn][yn]!=0){

                    guardacont=contagem;
                    contagem=0;
                    nump.append(tab[xn][yn]);
                }
                tab[xn][yn] = 10;
                branco=true;
            }
        }
        if (xn == x) {
            if (y < yn) {
                for (i = y + 1; i < yn; i++) {
                    if (tab[xn][i] != 0) {
                        anda = false;
                    }
                }
            } else if (y > yn) {
                for (i = y - 1; i > yn; i--) {
                    if (tab[xn][i] != 0) {
                        anda = false;
                    }
                }
            }
        } else if (yn == y) {
            if (x < xn) {
                for (i = x + 1; i < xn; i++) {
                    if (tab[i][yn] != 0) {
                        anda = false;
                    }
                }
            } else if (y > yn) {
                for (i = x - 1; i > xn; i--) {
                    if (tab[i][yn] != 0) {
                        anda = false;
                    }
                }
            }
        }else{
            anda=false;
        }
        if (tab[xn][yn] % 2 == 0 && tab[xn][yn] != 0) {
            anda = false;
        }
        if (anda) {
            tab[x][y] = 0;
            if(tab[xn][yn]!=0){

                guardacont=contagem;
                contagem=0;
                nump.append(tab[xn][yn]);
            }
            tab[xn][yn] = 10;
            branco=true;
        }
    }
    if (tab[xn][yn] == 9 && tab[x][y] == 0) {
        for (i = 0; i <= 7; i++) {
            for (j = 0; j <= 7; j++) {
                if (tab[i][j] == 11) {
                    break;
                }
            }
            if (tab[i][j] == 11) {
                break;
            }
        }
        if (calc_checkwhite(tab,  i, j, xn, yn)) {
            tab[xn][yn] = 0;

            contagem=guardacont;
            tab[x][y] = 9;
            branco=true;
        }
    } else if (tab[xn][yn] == 10 && tab[x][y] == 0) {
        for (i = 0; i <= 7; i++) {
            for (j = 0; j <= 7; j++) {
                if (tab[i][j] == 12) {
                    break;
                }
            }
            if (tab[i][j] == 12) {
                break;
            }
        }
        if (calc_checkblack(tab,  i, j, xn, yn)) {
            tab[xn][yn] = 0;

            contagem=guardacont;
            tab[x][y] = 10;
            branco=false;
        }
    }
}

void Tabuleiro::reianda(int **tab, int x, int y, bool &reiandou, int xn, int yn, bool &branco) {
    bool anda = true;
    if (branco) {

        if (calc_checkwhite(tab,  xn, yn, x, y)) {
            anda = false;
        }
        if(xn<=6){
            if(yn<=6){
                if(tab[xn+1][yn+1]==12){
                    anda=false;
                }
            }
            if(yn>=1){
                if(tab[xn+1][yn-1]==12){
                    anda=false;
                }
            }
            if(tab[xn+1][yn]==12){
                anda=false;
            }
        }
        if(xn>=1){
            if(yn<=6){
                if(tab[xn-1][yn+1]==12){
                    anda=false;
                }
            }
            if(yn>=1){
                if(tab[xn-1][yn-1]==12){
                    anda=false;
                }
            }
            if(tab[xn-1][yn]==12){
                anda=false;
            }
        }
        if(yn>=1){
            if(tab[xn][yn-1]==12){
                anda=false;
            }
        }
        if(yn<=6){
            if(tab[xn][yn+1]==12){
                anda=false;
            }
        }

        if ((!((xn + yn) == (x + y) || abs(xn - yn) == abs(x - y))) && abs(y - yn) > 1 || abs(x - xn) > 1) {
            anda = false;

        }
        if (tab[xn][yn] % 2 != 0) {
            anda = false;
        }
        if (anda) {

            if(tab[xn][yn]!=0){
                contagem=0;
                numb.append(tab[xn][yn]);
            }
            tab[xn][yn] = 11;
            tab[x][y] = 0;
            reiandou = true;
            branco=false;
        }
        if (abs(y - yn) == 2) {
            roque(tab, yn, reiandou, branco);
            if(!branco){
                contagem=0;
            }
        }
    } else {

        if (calc_checkblack(tab,  xn, yn, x, y)) {
            anda = false;
        }
        if(xn<=6){
            if(yn<=6){
                if(tab[xn+1][yn+1]==11){
                    anda=false;
                }
            }
            if(yn>=1){
                if(tab[xn+1][yn-1]==11){
                    anda=false;
                }
            }
            if(tab[xn+1][yn]==11){
                anda=false;
            }
        }
        if(xn>=1){
            if(yn<=6){
                if(tab[xn-1][yn+1]==11){
                    anda=false;
                }
            }
            if(yn>=1){
                if(tab[xn-1][yn-1]==11){
                    anda=false;
                }
            }
            if(tab[xn-1][yn]==11){
                anda=false;
            }
        }
        if(yn>=1){
            if(tab[xn][yn-1]==11){
                anda=false;
            }
        }
        if(yn<=6){
            if(tab[xn][yn+1]==11){
                anda=false;
            }
        }

        if ((!((xn + yn) == (x + y) || abs(xn - yn) == abs(x - y))) && abs(y - yn) > 1 || abs(x - xn) > 1) {
            anda = false;

        }
        if (tab[xn][yn] % 2 == 0 && tab[xn][yn] != 0) {
            anda = false;
        }
        if (anda) {

            if(tab[xn][yn]!=0){

                contagem=0;
                nump.append(tab[xn][yn]);
            }
            tab[xn][yn] = 12;
            tab[x][y] = 0;
            reiandou = true;
            branco=true;
        }
        if (abs(y - yn) == 2) {
            roque(tab, yn, reiandou, branco);

        }
    }
}

bool calc_block(int **tab, int i, int j, int xn, int yn, bool branco) {
    int peca,peca2;
    int numant = 0;
    int numdepo = 0;
    int k, l, m, n;
    m = i;
    n = j;
    if (branco) {
        for (i = 0; i <= 7; i++) {
            for (j = 0; j <= 7; j++) {
                if (tab[i][j] == 11) {
                    break;
                }
            }
            if (tab[i][j] == 11) {
                break;
            }
        }
        //parte bispo e rainha
        if (i <= 6 && j <= 6) {
            k = i + 1;
            l = j + 1;
            if (tab[k][l] == 6 || tab[k][l] == 10) {
                numant++;
            }
            if(tab[k][l]==0){
                while (tab[k][l] == 0 && k < 7 && l < 7) {
                    k++;
                    l++;
                }
                if(k<=7&&l<=7){
                    if (tab[k][l] == 6 || tab[k][l] == 10) {
                        numant++;
                    }
                }
            }
        }
        if (i <= 6 && j >= 1) {
            k = i + 1;
            l = j - 1;
            if (tab[k][l] == 6 || tab[k][l] == 10) {
                numant++;
            }
            if(tab[k][l]==0){
                while (tab[k][l] == 0 && k < 7 && l > 0) {
                    k++;
                    l--;
                }
                if(k<=7&&l>=0){
                    if (tab[k][l] == 6 || tab[k][l] == 10) {
                        numant++;
                    }
                }
            }
        }
        if (i >= 1 && j <= 6) {
            k = i - 1;
            l = j + 1;
            if (tab[k][l] == 6 || tab[k][l] == 10) {
                numant++;
            }
            if(tab[k][l]==0){
                while (tab[k][l] == 0 && k > 0 && l < 7) {
                    k--;
                    l++;
                }
                if(k>=0&&l<=7){
                    if (tab[k][l] == 6 || tab[k][l] == 10) {
                        numant++;
                    }
                }
            }
        }
        if (i >= 1 && j >= 1) {
            k = i - 1;
            l = j - 1;
            if (tab[k][l] == 6 || tab[k][l] == 10) {
                numant++;
            }
            if(tab[k][l]==0){
                while (tab[k][l] == 0 && k > 0 && l > 0) {
                    k--;
                    l--;
                }
                if(k>=0&&l>=0){
                    if (tab[k][l] == 6 || tab[k][l] == 10) {
                        numant++;
                    }
                }
            }
        }
        //rainha e torre
        if (i <= 6) {
            k = i + 1;
            if (tab[k][j] == 8 || tab[k][j] == 10) {
                numant++;
            }
            if(tab[k][j]==0){
                while (tab[k][j] == 0 && k < 7) {
                    k++;
                }
                if(k<=7){
                    if (tab[k][j] == 8 || tab[k][j] == 10) {
                        numant++;
                    }
                }
            }
        }
        if (j <= 6) {
            k = j + 1;
            if (tab[i][k] == 8 || tab[i][k] == 10) {
                numant++;
            }
            if(tab[i][k]==0){
                while (tab[i][k] == 0 && k < 7) {
                    k++;
                }
                if(k<=7){
                    if (tab[i][k] == 8 || tab[i][k] == 10) {
                        numant++;
                    }
                }
            }
        }
        if (i >= 1) {
            k = i - 1;
            if (tab[k][j] == 8 || tab[k][j] == 10) {
                numant++;
            }
            if(tab[k][j]==0){
                while (tab[k][j] == 0 && k > 0) {
                    k--;
                }
                if(k>=0){
                    if (tab[k][j] == 8 || tab[k][j] == 10) {
                        numant++;
                    }
                }
            }
        }
        if (j >= 1) {
            k = j - 1;
            if (tab[i][k] == 8 || tab[i][k] == 10) {
                numant++;
            }
            if(tab[i][k]==0){
                while (tab[i][k] == 0 && k > 0) {
                    k--;
                }
                if(k>=0){
                    if (tab[i][k] == 8 || tab[i][k] == 10) {
                        numant++;
                    }
                }
            }
        }
        peca = tab[m][n];
        peca2=tab[xn][yn];
        tab[xn][yn]=peca;
        tab[m][n] = 0;
        for (i = 0; i <= 7; i++) {
            for (j = 0; j <= 7; j++) {
                if (tab[i][j] == 11) {
                    break;
                }
            }
            if (tab[i][j] == 11) {
                break;
            }
        }
        if (i <= 6 && j <= 6) {
            k = i + 1;
            l = j + 1;
            if (tab[k][l] == 6 || tab[k][l] == 10) {
                numdepo++;
            }
            if(tab[k][l]==0){
                while (tab[k][l] == 0 && k < 7 && l < 7) {
                    k++;
                    l++;
                }
                if(k<=7&&l<=7){
                    if (tab[k][l] == 6 || tab[k][l] == 10) {
                        numdepo++;
                    }
                }
            }
        }
        if (i <= 6 && j >= 1) {
            k = i + 1;
            l = j - 1;
            if (tab[k][l] == 6 || tab[k][l] == 10) {
                numdepo++;
            }
            if(tab[k][l]==0){
                while (tab[k][l] == 0 && k < 7 && l > 0) {
                    k++;
                    l--;
                }
                if(k<=7&&l>=0){
                    if (tab[k][l] == 6 || tab[k][l] == 10) {
                        numdepo++;
                    }
                }
            }
        }
        if (i >= 1 && j <= 6) {
            k = i - 1;
            l = j + 1;
            if (tab[k][l] == 6 || tab[k][l] == 10) {
                numdepo++;
            }
            if(tab[k][l]==0){
                while (tab[k][l] == 0 && k > 0 && l < 7) {

                    k--;
                    l++;
                }
                if(k>=0&&l<=7){
                    if (tab[k][l] == 6 || tab[k][l] == 10) {
                        numdepo++;
                    }
                }
            }
        }
        if (i >= 1 && j >= 1) {
            k = i - 1;
            l = j - 1;
            if (tab[k][l] == 6 || tab[k][l] == 10) {
                numdepo++;
            }
            if(tab[k][l]==0){
                while (tab[k][l] == 0 && k > 0 && l > 0) {
                    k--;
                    l--;
                }
                if(k>=0&&l>=0){
                    if (tab[k][l] == 6 || tab[k][l] == 10) {
                        numdepo++;
                    }
                }
            }
        }
        //rainha e torre
        if (i <= 6) {
            k = i + 1;
            if (tab[k][j] == 8 || tab[k][j] == 10) {
                numdepo++;
            }
            if(tab[k][j]==0){
                while (tab[k][j] == 0 && k < 7) {
                    k++;
                }
                if(k<=7){
                    if (tab[k][j] == 8 || tab[k][j] == 10) {
                        numdepo++;
                    }
                }
            }
        }
        if (j <= 6) {
            k = j + 1;
            if (tab[i][k] == 8 || tab[i][k] == 10) {
                numdepo++;
            }
            if(tab[i][k]==0){
                while (tab[i][k] == 0 && k < 7) {
                    k++;
                }
                if(k<=7){
                    if (tab[i][k] == 8 || tab[i][k] == 10) {
                        numdepo++;
                    }
                }
            }
        }
        if (i >= 1) {
            k = i - 1;
            if (tab[k][j] == 8 || tab[k][j] == 10) {
                numdepo++;
            }
            if(tab[k][j]==0){
                while (tab[k][j] == 0 && k > 0) {
                    k--;
                }
                if(k>=0){
                    if (tab[k][j] == 8 || tab[k][j] == 10) {
                        numdepo++;
                    }
                }
            }
        }
        if (j >= 1) {
            k = j - 1;
            if (tab[i][k] == 8 || tab[i][k] == 10) {
                numdepo++;
            }
            if(tab[i][k]==0){
                while (tab[i][k] == 0 && k > 0) {
                    k--;
                }
                if(k>=0){
                    if (tab[i][k] == 8 || tab[i][k] == 10) {
                        numdepo++;
                    }
                }
            }
        }
        tab[m][n] = peca;
        tab[xn][yn]=peca2;
        if (numdepo <= numant) {
            return true;
        }

    } else {
        for (i = 0; i <= 7; i++) {
            for (j = 0; j <= 7; j++) {
                if (tab[i][j] == 12) {
                    break;
                }
            }
            if (tab[i][j] == 12) {
                break;
            }
        }

        //parte bispo e rainha
        if (i <= 6 && j <= 6) {
            k = i + 1;
            l = j + 1;
            if (tab[k][l] == 5 || tab[k][l] == 9) {
                numant++;
            }
            if(tab[k][l]==0){
                while (tab[k][l] == 0 && (k < 7 && l < 7)) {
                    k++;
                    l++;
                }
                if(k<=7&&l<=7){
                    if (tab[k][l] == 5 || tab[k][l] == 9) {
                        numant++;
                    }
                }
            }
        }
        if (i <= 6 && j >= 1) {
            k = i + 1;
            l = j - 1;
            if (tab[k][l] == 5 || tab[k][l] == 9) {
                numant++;
            }
            if(tab[k][l]==0){
                while (tab[k][l] == 0 && k < 7 && l > 0) {
                    k++;
                    l--;
                }
                if(k<=7&&l>=0){
                    if (tab[k][l] == 5 || tab[k][l] == 9) {
                        numant++;
                    }
                }
            }
        }
        if (j <= 6 && i >= 1) {
            k = i - 1;
            l = j + 1;
            if (tab[k][l] == 5 || tab[k][l] == 9) {
                numant++;
            }
            if(tab[k][l]==0){
                while (tab[k][l] == 0 && k > 0 && l < 7) {
                    k--;
                    l++;
                }
                if(k>=0&&l<=7){
                    if (tab[k][l] == 5 || tab[k][l] == 9) {
                        numant++;
                    }
                }
            }
        }
        if (i >= 1 && j >= 1) {
            k = i - 1;
            l = j - 1;
            if (tab[k][l] == 5 || tab[k][l] == 9) {
                numant++;
            }
            if(tab[k][l]==0){
                while (tab[k][l] == 0 && k > 0 && l > 0) {
                    k--;
                    l--;
                }
                if(k>=0&&l>=0){
                    if (tab[k][l] == 5 || tab[k][l] == 9) {
                        numant++;
                    }
                }
            }
        }

        //rainha e torre
        k = i + 1;
        if (i <= 6) {
            if (tab[k][j] == 7 || tab[k][j] == 9) {
                numant++;
            }
            if(tab[k][j]==0){
                while (tab[k][j] == 0 && k < 7) {
                    k++;
                }
                if(k<=7){
                    if (tab[k][j] == 7 || tab[k][j] == 9) {
                        numant++;
                    }
                }
            }
        }
        if (j <= 6) {
            k = j + 1;
            if (tab[i][k] == 7 || tab[i][k] == 9) {
                numant++;
            }
            if(tab[i][k]==0){
                while (tab[i][k] == 0 && k < 7) {
                    k++;
                }
                if(k<=7){
                    if (tab[i][k] == 7 || tab[i][k] == 9) {
                        numant++;
                    }
                }
            }
        }
        if (i >= 1) {
            k = i - 1;
            if (tab[k][j] == 7 || tab[k][j] == 9) {
                numant++;
            }
            if(tab[k][j]==0){
                while (tab[k][j] == 0 && k > 0) {
                    k--;
                }
                if(k>=0){
                    if (tab[k][j] == 7 || tab[k][j] == 9) {
                        numant++;
                    }
                }
            }
        }
        if (j >= 1) {
            k = j - 1;
            if (tab[i][k] == 7 || tab[i][k] == 9) {
                numant++;
            }
            if(tab[i][k]==0){
                while (tab[i][k] == 0 && k > 0) {
                    k--;
                }
                if(k>=0){
                    if (tab[i][k] == 7 || tab[i][k] == 9) {
                        numant++;
                    }
                }
            }
        }
        peca = tab[m][n];
        peca2=tab[xn][yn];
        tab[xn][yn]=peca;
        tab[m][n] = 0;
        for (i = 0; i <= 7; i++) {
            for (j = 0; j <= 7; j++) {
                if (tab[i][j] == 12) {
                    break;
                }
            }
            if (tab[i][j] == 12) {
                break;
            }
        }
        //parte bispo e rainha
        if (i <= 6 && j <= 6) {
            k = i + 1;
            l = j + 1;
            if (tab[k][l] == 5 || tab[k][l] == 9) {
                numdepo++;
            }
            if(tab[k][l]==0){
                while (tab[k][l] == 0 && (k < 7 && l < 7)) {
                    k++;
                    l++;
                }
                if(k<=7&&l<=7){
                    if (tab[k][l] == 5 || tab[k][l] == 9) {
                        numdepo++;
                    }
                }
            }
        }
        if (i <= 6 && j >= 1) {
            k = i + 1;
            l = j - 1;
            if (tab[k][l] == 5 || tab[k][l] == 9) {
                numdepo++;
            }
            if(tab[k][l]==0){
                while (tab[k][l] == 0 && k < 7 && l > 0) {
                    k++;
                    l--;
                }
                if(k<=7&&l>=0){
                    if (tab[k][l] == 5 || tab[k][l] == 9) {
                        numdepo++;
                    }
                }
            }
        }
        if (j <= 6 && i >= 1) {
            k = i - 1;
            l = j + 1;
            if (tab[k][l] == 5 || tab[k][l] == 9) {
                numdepo++;
            }
            if(tab[k][l]==0){
                while (tab[k][l] == 0 && k > 0 && l < 7) {
                    k--;
                    l++;
                }
                if(k>=0&&l<=7){
                    if (tab[k][l] == 5 || tab[k][l] == 9) {
                        numdepo++;
                    }
                }
            }
        }
        if (i >= 1 && j >= 1) {
            k = i - 1;
            l = j - 1;
            if (tab[k][l] == 5 || tab[k][l] == 9) {
                numdepo++;
            }
            if(tab[k][l]==0){
                while (tab[k][l] == 0 && k > 0 && l > 0) {
                    k--;
                    l--;
                }
                if(k>=0&&l>=0){
                    if (tab[k][l] == 5 || tab[k][l] == 9) {
                        numdepo++;
                    }
                }
            }
        }

        //rainha e torre
        k = i + 1;
        if (i <= 6) {
            if (tab[k][j] == 7 || tab[k][j] == 9) {
                numdepo++;
            }
            if(tab[k][j]==0){
                while (tab[k][j] == 0 && k < 7) {
                    k++;
                }
                if(k<=7){
                    if (tab[k][j] == 7 || tab[k][j] == 9) {
                        numdepo++;
                    }
                }
            }
        }
        if (j <= 6) {
            k = j + 1;
            if (tab[i][k] == 7 || tab[i][k] == 9) {
                numdepo++;
            }
            if(tab[i][k]==0){
                while (tab[i][k] == 0 && k < 7) {
                    k++;
                }
                if(k<=7){
                    if (tab[i][k] == 7 || tab[i][k] == 9) {
                        numdepo++;
                    }
                }
            }
        }
        if (i >= 1) {
            k = i - 1;
            if (tab[k][j] == 7 || tab[k][j] == 9) {
                numdepo++;
            }
            if(tab[k][j]==0){
                while (tab[k][j] == 0 && k > 0) {
                    k--;
                }
                if(k>=0){
                    if (tab[k][j] == 7 || tab[k][j] == 9) {
                        numdepo++;
                    }
                }
            }
        }
        if (j >= 1) {
            k = j - 1;
            if (tab[i][k] == 7 || tab[i][k] == 9) {
                numdepo++;
            }
            if(tab[i][k]==0){
                while (tab[i][k] == 0 && k > 0) {
                    k--;
                }
                if(k>=0){
                    if (tab[i][k] == 7 || tab[i][k] == 9) {
                        numdepo++;
                    }
                }
            }
        }
        tab[m][n] = peca;
        tab[xn][yn]=peca2;
        if (numdepo <= numant) {
            return true;
        }
    }
    return false;
}

bool kill_this(int **tab, int i, int j,int xn, int yn, bool branco, bool block) {
    if (branco) {
        int k, l;
        if (i != 0) {
            if (j != 7) {
                if (block) {
                    if (tab[i - 1][j] == 1 && calc_block(tab, i - 1, j, xn, yn, branco)) {
                        return true;
                    }
                    if(i>=2){
                        if (i == 3 && tab[i - 2][j] == 1 && calc_block(tab, i - 2, j, xn, yn, branco)) {
                            return true;
                        }
                    }
                } else {
                    if (tab[i - 1][j + 1] == 1 && calc_block(tab, i - 1, j + 1, xn, yn, branco)) {//peao
                        return true;

                    }
                }
            }
            if (j != 0) {
                if (block) {
                    if (tab[i - 1][j] == 1 && calc_block(tab, i - 1, j, xn, yn, branco)) {
                        return true;
                    }
                    if(i>=2){
                        if (i == 3 && tab[i - 2][j] == 1 && calc_block(tab, i - 2, j, xn, yn, branco)) {
                            return true;
                        }
                    }
                } else {
                    if (tab[i - 1][j - 1] == 1 && calc_block(tab, i - 1, j - 1, xn, yn, branco)) {
                        return true;
                    }
                }
            }
        }

        if (i <= 5) {//cavalo
            if (j <= 6) {
                if (tab[2 + i][j + 1] == 3 && calc_block(tab, i + 2, j + 1, xn, yn, branco)) {
                    return true;
                }
            }
            if (j >= 1) {
                if (tab[i + 2][j - 1] == 3 && calc_block(tab, i + 2, j - 1, xn, yn, branco)) {
                    return true;
                }
            }
        }
        if (i <= 6) {
            if (j <= 5) {
                if (tab[i + 1][j + 2] == 3 && calc_block(tab, i + 1, j + 2, xn, yn, branco)) {
                    return true;
                }
            }
            if (j >= 2) {
                if (tab[i + 1][j - 2] == 3 && calc_block(tab, i + 1, j - 2,xn, yn, branco)) {
                    return true;
                }
            }
        }
        if (i >= 1) {
            if (j >= 2) {
                if (tab[i - 1][j - 2] == 3 && calc_block(tab, i - 1, j - 2,xn, yn, branco)) {
                    return true;
                }
            }
            if (j <= 5) {
                if (tab[i - 1][j + 2] == 3 && calc_block(tab, i - 1, j + 2,xn, yn, branco)) {
                    return true;
                }
            }
        }
        if (i >= 2) {
            if (j >= 1) {
                if (tab[i - 2][j - 1] == 3 && calc_block(tab, i - 2, j - 1, xn, yn,branco)) {
                    return true;
                }
            }
            if (j <= 6) {
                if (tab[i - 2][j + 1] == 3 && calc_block(tab, i - 2, j + 1, xn, yn,branco)) {
                    return true;
                }
            }
        }
        //parte bispo e rainha
        if (i <= 6 && j <= 6) {
            k = i + 1;
            l = j + 1;
            if ((tab[k][l] == 5 || tab[k][l] == 9) && calc_block(tab, k, l,xn, yn, branco)) {
                return true;
            }
            while (tab[k][l] == 0 && (k < 7 && l < 7)) {
                k++;
                l++;
            }
            if(k<=7&&l<=7){
                if ((tab[k][l] == 5 || tab[k][l] == 9) && calc_block(tab, k, l,xn, yn, branco)) {
                    return true;
                }
            }
        }
        if (i <= 6 && j >= 1) {
            k = i + 1;
            l = j - 1;
            if ((tab[k][l] == 5 || tab[k][l] == 9) && calc_block(tab, k, l,xn, yn, branco)) {
                return true;
            }
            while (tab[k][l] == 0 && k < 7 && l > 0) {
                k++;
                l--;
            }
            if(k<=7&&l>=0){
                if ((tab[k][l] == 5 || tab[k][l] == 9) && calc_block(tab, k, l,xn, yn, branco)) {
                    return true;
                }
            }
        }
        if (j <= 6 && i >= 1) {
            k = i - 1;
            l = j + 1;
            if ((tab[k][l] == 5 || tab[k][l] == 9) && calc_block(tab, k, l,xn, yn, branco)) {
                return true;
            }
            while (tab[k][l] == 0 && k > 0 && l < 7) {
                k--;
                l++;
            }
            if(k>=0&&l<=7){
                if ((tab[k][l] == 5 || tab[k][l] == 9) && calc_block(tab, k, l,xn, yn, branco)) {
                    return true;
                }
            }
        }
        if (i >= 1 && j >= 1) {
            k = i - 1;
            l = j - 1;
            if ((tab[k][l] == 5 || tab[k][l] == 9) && calc_block(tab, k, l,xn, yn, branco)) {
                return true;
            }
            while (tab[k][l] == 0 && k > 0 && l > 0) {
                k--;
                l--;
            }
            if(k>=0&&l>=0){
                if ((tab[k][l] == 5 || tab[k][l] == 9) && calc_block(tab, k, l,xn, yn, branco)) {
                    return true;
                }
            }
        }

        //rainha e torre
        k = i + 1;
        if (i <= 6) {

            if ((tab[k][j] == 7 || tab[k][j] == 9) && calc_block(tab, k, j,xn, yn, branco)) {
                return true;
            }
            while (tab[k][j] == 0 && k < 7) {
                k++;
            }
            if(k<=7){
                if ((tab[k][j] == 7 || tab[k][j] == 9) && calc_block(tab, k, j,xn, yn, branco)) {
                    return true;
                }
            }
        }
        if (j <= 6) {
            k = j + 1;
            if ((tab[k][j] == 7 || tab[k][j] == 9) && calc_block(tab, i, k,xn, yn, branco)) {
                return true;
            }
            while (tab[i][k] == 0 && k < 7) {
                k++;
            }
            if(k<=7){
                if ((tab[k][j] == 7 || tab[k][j] == 9) && calc_block(tab, i, k,xn, yn, branco)) {
                    return true;
                }
            }
        }
        if (i >= 1) {
            k = i - 1;
            if ((tab[k][j] == 7 || tab[k][j] == 9) && calc_block(tab, k, j,xn, yn, branco)) {
                return true;
            }
            while (tab[k][j] == 0 && k > 0) {
                k--;
            }
            if(k>=0){
                if ((tab[k][j] == 7 || tab[k][j] == 9) && calc_block(tab, k, j,xn, yn, branco)) {
                    return true;
                }
            }
        }
        if (j >= 1) {
            k = j - 1;
            if ((tab[k][j] == 7 || tab[k][j] == 9) && calc_block(tab, i, k,xn, yn, branco)) {
                return true;
            }
            while (tab[i][k] == 0 && k > 0) {
                k--;
            }
            if(k>=0){
                if ((tab[k][j] == 7 || tab[k][j] == 9) && calc_block(tab, k, l,xn, yn, branco)) {
                    return true;
                }
            }
        }

    } else {
        int k, l;
        if (i <= 6) {
            if (j <= 6) {
                if (block) {
                    if (tab[i + 1][j] == 2) {
                        if (calc_block(tab, i + 1, j,xn, yn, branco)) {
                            return true;
                        }
                    }
                    if(i<=5){
                        if (i == 4 && tab[i + 2][j] == 2 && calc_block(tab, i + 2, j,xn, yn, branco)) {
                            return true;
                        }
                    }
                } else {
                    if (tab[i + 1][j + 1] == 2 && calc_block(tab, i + 1, j + 1,xn, yn, branco)) {//check peao
                        return true;
                    }
                }
            }
            if (j >= 1) {

                if (block) {
                    if (tab[i + 1][j] == 2 && calc_block(tab, i + 1, j,xn, yn, branco)) {
                        return true;
                    }
                    if(i<=5){
                        if (i == 4 && tab[i + 2][j] == 2 && calc_block(tab, i + 2, j,xn, yn, branco)) {
                            return true;
                        }
                    }
                } else {
                    if (tab[i + 1][j - 1] == 2 && calc_block(tab, i + 1, j - 1,xn, yn, branco)) {
                        return true;
                    }
                }

            }
        }

        if (i <= 5) {//cavalo
            if (j <= 6) {
                if (tab[2 + i][j + 1] == 4) {
                    if (calc_block(tab, 2 + i, j + 1,xn, yn, branco)) {
                        return true;
                    }
                }
            }
            if (j >= 1) {
                if (tab[i + 2][j - 1] == 4) {
                    if (calc_block(tab, i + 2, j - 1,xn, yn, branco)) {
                        return true;
                    }
                }
            }
        }
        if (i <= 6) {
            if (j <= 5) {
                if (tab[i + 1][j + 2] == 4) {
                    if (calc_block(tab, i + 1, j + 2,xn, yn, branco)) {
                        return true;
                    }
                }
            }
            if (j >= 2) {
                if (tab[i + 1][j - 2] == 4) {
                    if (calc_block(tab, i + 1, j - 2,xn, yn, branco)) {
                        return true;
                    }
                }
            }
        }
        if (i >= 1) {
            if (j >= 2) {
                if (tab[i - 1][j - 2] == 4) {
                    if (calc_block(tab, i - 1, j - 2,xn, yn, branco)) {
                        return true;
                    }
                }
            }
            if (j <= 5) {
                if (tab[i - 1][j + 2] == 4) {
                    if (calc_block(tab, i - 1, j + 2,xn, yn, branco)) {
                        return true;
                    }
                }
            }
        }
        if (i >= 2) {
            if (j >= 1) {
                if (tab[i - 2][j - 1] == 4) {
                    if (calc_block(tab, i - 2, j - 1,xn, yn, branco)) {
                        return true;
                    }
                }
            }
            if (j <= 6) {
                if (tab[i - 2][j + 1] == 4) {
                    if (calc_block(tab, i - 2, j + 1,xn, yn, branco)) {
                        return true;
                    }
                }
            }
        }

        //parte bispo e rainha
        if (i <= 6 && j <= 6) {
            k = i + 1;
            l = j + 1;
            if ((tab[k][l] == 6 || tab[k][l] == 10) && calc_block(tab, k, l,xn, yn, branco)) {
                return true;
            }
            while (tab[k][l] == 0 && k < 7 && l < 7) {

                k++;
                l++;
            }
            if(k<=7&& l<=7){
                if ((tab[k][l] == 6 || tab[k][l] == 10) && calc_block(tab, k, l,xn, yn, branco)) {
                    return true;
                }
            }
        }
        if (i <= 6 && j >= 1) {
            k = i + 1;
            l = j - 1;
            if ((tab[k][l] == 6 || tab[k][l] == 10) && calc_block(tab, k, l,xn, yn, branco)) {
                return true;
            }
            while (tab[k][l] == 0 && k < 7 && l > 0) {
                k++;
                l--;
            }
            if(k<=7&& l>=0){
                if ((tab[k][l] == 6 || tab[k][l] == 10) && calc_block(tab, k, l,xn, yn, branco)) {
                    return true;
                }
            }
        }
        if (i >= 1 && j <= 6) {
            k = i - 1;
            l = j + 1;
            if ((tab[k][l] == 6 || tab[k][l] == 10) && calc_block(tab, k, l,xn, yn, branco)) {
                return true;
            }
            while (tab[k][l] == 0 && k > 0 && l < 7) {
                k--;
                l++;
            }
            if(k>=0&& l<=7){
                if ((tab[k][l] == 6 || tab[k][l] == 10) && calc_block(tab, k, l,xn, yn, branco)) {
                    return true;
                }
            }
        }
        if (i >= 1 && j >= 1) {
            k = i - 1;
            l = j - 1;
            if ((tab[k][l] == 6 || tab[k][l] == 10) && calc_block(tab, k, l,xn, yn, branco)) {
                return true;
            }
            while (tab[k][l] == 0 && k > 0 && l > 0) {
                k--;
                l--;
            }
            if(k>=0&& l>=0){
                if ((tab[k][l] == 6 || tab[k][l] == 10) && calc_block(tab, k, l,xn, yn, branco)) {
                    return true;
                }
            }
        }
        //rainha e torre
        if (i <= 6) {
            k = i + 1;
            if (tab[k][j] == 8 || tab[k][j] == 10 && calc_block(tab, k, j,xn, yn, branco)) {
                return true;
            }
            while (tab[k][j] == 0 && k < 7) {
                k++;
            }
            if(k<=7){
                if (tab[k][j] == 8 || tab[k][j] == 10 && calc_block(tab, k, j,xn, yn, branco)) {
                    return true;
                }
            }
        }
        if (j <= 6) {
            k = j + 1;
            if (tab[k][j] == 8 || tab[k][j] == 10 && calc_block(tab, i, k,xn, yn, branco)) {
                return true;
            }
            while (tab[i][k] == 0 && k < 7) {
                k++;
            }
            if(k<=7){
                if (tab[k][j] == 8 || tab[k][j] == 10 && calc_block(tab, i, k,xn, yn, branco)) {
                    return true;
                }
            }
        }
        if (i >= 1) {
            k = i - 1;
            if (tab[k][j] == 8 || tab[k][j] == 10 && calc_block(tab, k, j,xn, yn, branco)) {
                return true;
            }
            while (tab[k][j] == 0 && k > 0) {
                k--;
            }
            if(k>=0){
                if (tab[k][j] == 8 || tab[k][j] == 10 && calc_block(tab, k, j,xn, yn, branco)) {
                    return true;
                }
            }
        }
        if (j >= 1) {
            k = j - 1;
            if (tab[k][j] == 8 || tab[k][j] == 10 && calc_block(tab, i, k,xn, yn, branco)) {
                return true;
            }
            while (tab[i][k] == 0 && k > 0) {
                k--;
            }
            if(k>=0){
                if (tab[k][j] == 8 || tab[k][j] == 10 && calc_block(tab, i, k,xn,yn, branco)) {

                    return true;
                }
            }
        }

    }
    return false;
}

bool calc_checkmateblack(int **tab, int i, int j, int xn, int yn, int sit) {
    int k, l;
    if (i <= 6) {
        if (tab[i + 1][j] == 0) {
            if (calc_checkblack(tab,  i + 1, j, xn, yn) == false) {
                return false;
            }
        }
        if (j <= 6) {
            if (tab[i + 1][j + 1] == 0) {
                if (calc_checkblack(tab,  i + 1, j + 1,xn, yn) == false) {
                    return false;
                }

            }
        }
        if (j >= 1) {
            if (tab[i + 1][j - 1] == 0) {
                if (calc_checkblack(tab,  i + 1, j - 1,xn, yn) == false) {
                    return false;
                }
            }
        }
    }
    if (i >= 1) {

        if (tab[i - 1][j] == 0) {
            if (calc_checkblack(tab,  i - 1, j,xn, yn) == false) {
                return false;
            }
        }
        if (j >= 1) {
            if (tab[i - 1][j - 1] == 0) {
                if (calc_checkblack(tab,  i - 1, j - 1, xn, yn)==false) {
                    return false;
                }
            }
        }
        if (j <= 6) {
            if (tab[i - 1][j + 1] == 0) {
                if (calc_checkblack(tab,  i - 1, j + 1, xn, yn)==false) {
                    return false;
                }
            }
        }
    }
    if (j <= 6) {
        if (tab[i][j + 1] == 0) {
            if (calc_checkblack(tab,  i, j + 1, xn, yn)==false) {
                return false;
            }
        }
    }
    if (j >= 1) {
        if (tab[i][j - 1] == 0) {
            if (calc_checkblack(tab,  i, j - 1, xn, yn)==false) {
                return false;
            }
        }
    }
    if (sit == 0) {//peao i-1 j+1
        if (calc_checkblack(tab,  i - 1, j + 1, xn, yn)==false) {
            return false;
        }
        if (kill_this(tab, i - 1, j + 1, xn, yn, false, false)) {
            return false;
        }
    } else if (sit == 1) {//peao i-1 j-1
        if (calc_checkblack(tab,  i - 1, j - 1, xn, yn)==false) {
            return false;
        }
        if (kill_this(tab, i - 1, j - 1, xn, yn, false, false)) {
            return false;
        }
    } else if (sit == 2) {//cavalo 2 + i j + 1
        if (kill_this(tab, i + 2, j + 1, xn, yn, false, false)) {
            return false;
        }
    } else if (sit == 3) {//cavalo 2 + i j - 1
        if (kill_this(tab, i + 2, j - 1, xn, yn, false, false)) {
            return false;
        }
    } else if (sit == 4) {//cavalo 1 + i j + 2
        if (kill_this(tab, i + 1, j + 2, xn, yn, false, false)) {
            return false;
        }
    } else if (sit == 5) {//cavalo 1 + i j - 2
        if (kill_this(tab, i + 1, j - 2, xn, yn, false, false)) {
            return false;
        }
    } else if (sit == 6) {//cavalo  i-1 j - 2
        if (kill_this(tab, i - 1, j - 2, xn, yn, false, false)) {
            return false;
        }
    } else if (sit == 7) {//cavalo i-1 j + 2
        if (kill_this(tab, i - 1, j + 2, xn, yn, false, false)) {
            return false;
        }
    } else if (sit == 8) {//cavalo  i-2 j - 1
        if (kill_this(tab, i - 2, j - 1, xn, yn, false, false)) {
            return false;
        }
    } else if (sit == 9) {//cavalo i-2 j + 1
        if (kill_this(tab, i - 2, j + 1, xn, yn, false, false)) {
            return false;
        }
    } else if (sit == 10) {//bispo j++ i++
        if (tab[i + 1][j + 1] == 5 || tab[i + 1][j + 1] == 9) {
            if (calc_checkblack(tab,  i + 1, j + 1, xn, yn)==false || kill_this(tab, i + 1, j + 1, xn, yn, false, false)) {
                return false;
            }
        }
        k = i + 1;
        l = j + 1;
        while (tab[k][l] == 0 && k <= 7 && l <= 7) {
            if (kill_this(tab, k, l, xn, yn, false, true)) {
                return false;
            }
            k++;
            l++;
        }
        if (kill_this(tab, k, l, xn, yn, false, false)) {
            return false;
        }
    } else if (sit == 11) {//bispo j-- i++
        if (tab[i + 1][j - 1] == 5 || tab[i + 1][j - 1] == 9) {
            if (calc_checkblack(tab,  i + 1, j - 1, xn, yn)==false || kill_this(tab, i + 1, j - 1, xn, yn, false, false)) {
                return false;
            }
        }
        k = i + 1;
        l = j - 1;
        while (tab[k][l] == 0 && k <= 7 && l >= 0) {
            if (kill_this(tab, k, l, xn, yn, false, true)) {
                return false;
            }
            k++;
            l--;
        }
        if (kill_this(tab, k, l, xn, yn, false, false)) {
            return false;
        }
    } else if (sit == 12) {//bispo j++ i--
        if (tab[i - 1][j + 1] == 5 || tab[i - 1][j + 1] == 9) {
            if (calc_checkblack(tab,  i - 1, j + 1, xn, yn)==false || kill_this(tab, i - 1, j + 1, xn, yn, false, false)) {
                return false;
            }
        }
        k = i - 1;
        l = j + 1;
        while (tab[k][l] == 0 && k >= 0 && l <= 7) {
            if (kill_this(tab, k, l, xn, yn, false, true)) {
                return false;
            }
            k--;
            l++;
        }
        if (kill_this(tab, k, l, xn, yn, false, false)) {
            return false;
        }
    } else if (sit == 13) {//bispo j-- i--
        if (tab[i - 1][j - 1] == 5 || tab[i - 1][j - 1] == 9) {
            if (calc_checkblack(tab,  i - 1, j - 1, xn, yn)==false || kill_this(tab, i - 1, j - 1, xn, yn, false, false)) {
                return false;
            }
        }
        k = i - 1;
        l = j - 1;
        while (tab[k][l] == 0 && k >= 0 && l >= 0) {
            if (kill_this(tab, k, l, xn, yn, false, true)) {
                return false;
            }
            k--;
            l--;

        }

        if (kill_this(tab, k, l, xn, yn, false, false)) {
            return false;
        }
    } else if (sit == 14) {//torre i++
        if (tab[i + 1][j] == 7 || tab[i + 1][j] == 9) {
            if (calc_checkblack(tab,  i + 1, j, xn, yn)==false || kill_this(tab, i + 1, j, xn, yn, false, false)) {
                return false;
            }
        }
        k = i + 1;
        while (tab[k][j] == 0 && k <= 7) {
            if (kill_this(tab, k, j, xn, yn, false, true)) {
                return false;
            }
            k++;
        }
        if (kill_this(tab, k, j, xn, yn, false, false)) {
            return false;
        }
    } else if (sit == 15) {//torre j++
        if (tab[i][j + 1] == 7 || tab[i][j + 1] == 9) {
            if (calc_checkblack(tab,  i, j + 1, xn, yn)==false || kill_this(tab, i, j + 1, xn, yn, false, false)) {
                return false;
            }
        }
        k = j + 1;
        while (tab[i][k] == 0 && k <= 7) {
            if (kill_this(tab, i, k, xn, yn, false, true)) {
                return false;
            }
            k++;
        }
        if (kill_this(tab, i, k, xn, yn, false, false)) {
            return false;
        }
    } else if (sit == 16) {//torre i--
        if (tab[i - 1][j] == 7 || tab[i - 1][j] == 9) {
            if (calc_checkblack(tab,  i - 1, j, xn, yn)==false || kill_this(tab, i - 1, j, xn, yn, false, false)) {
                return false;
            }
        }
        k = i - 1;
        while (tab[k][j] == 0 && k >= 0) {
            if (kill_this(tab, k, j, xn, yn, false, true)) {
                return false;
            }
            k--;
        }
        if (kill_this(tab, k, j, xn, yn, false, false)) {
            return false;
        }
    } else if (sit == 17) {//torre j--
        if (tab[i][j - 1] == 7 || tab[i][j - 1] == 9) {
            if (calc_checkblack(tab,  i, j - 1, xn, yn)==false || kill_this(tab, i, j - 1, xn, yn, false, false)) {
                return false;
            }
        }
        k = j - 1;
        while (tab[i][k] == 0 && k >= 0) {
            if (kill_this(tab, i, k, xn, yn, false, true)) {
                return false;
            }
            k--;
        }
        if (kill_this(tab, i, k,xn,yn,  false, false)) {
            return false;
        }
    }
    checkmate acabou;
    acabou.exec();
    return true;

}

bool calc_checkmatewhite(int **tab,  int i, int j, int xn, int yn, int sit) {
    int k, l;
    if (i <= 6) {
        if (tab[i + 1][j] == 0) {
            if (calc_checkwhite(tab,  i + 1, j, xn, yn)==false) {
                return false;
            }
        }
        if (j <= 6) {
            if (tab[i + 1][j + 1] == 0) {
                if (calc_checkwhite(tab,  i + 1, j + 1, xn, yn)==false) {
                    return false;
                }
            }
        }
        if (j >= 1) {
            if (tab[i + 1][j - 1] == 0) {
                if (calc_checkwhite(tab,  i + 1, j - 1, xn, yn)==false) {
                    return false;
                }
            }
        }
    }
    if (i >= 1) {
        if (tab[i - 1][j] == 0) {
            if (calc_checkwhite(tab,  i - 1, j, xn, yn)==false) {
                return false;
            }
        }
        if (tab[i - 1][j - 1] == 0) {
            if (calc_checkwhite(tab,  i - 1, j - 1, xn, yn)==false) {
                return false;
            }
        }
        if (tab[i - 1][j + 1] == 0) {
            if (calc_checkwhite(tab,  i - 1, j + 1, xn, yn)==false) {
                return false;
            }
        }
    }
    if (j <= 6) {
        if (tab[i][j + 1] == 0) {
            if (calc_checkwhite(tab,  i, j + 1, xn, yn)==false) {
                return false;
            }
        }
    }
    if (j >= 1) {
        if (tab[i][j - 1] == 0) {
            if (calc_checkwhite(tab,  i, j - 1, xn, yn)==false) {

                return false;
            }
        }
    }
    if (sit == 0) {//peao i+1 j+1
        if (calc_checkwhite(tab,  i + 1, j + 1, xn, yn)==false) {
            return false;
        }
        if (kill_this(tab, i + 1, j + 1, xn, yn, true, false)) {
            return false;
        }
    } else if (sit == 1) {//peao i+1 j-1
        if (calc_checkwhite(tab,  i + 1, j - 1, xn, yn)==false) {
            return false;
        }
        if (kill_this(tab, i + 1, j - 1, xn, yn, true, false)) {
            return false;
        }
    } else if (sit == 2) {//cavalo 2 + i j + 1
        if (kill_this(tab, i + 2, j + 1, xn, yn, true, false)) {
            return false;
        }
    } else if (sit == 3) {//cavalo 2 + i j - 1
        if (kill_this(tab, i + 2, j - 1, xn, yn, true, false)) {
            return false;
        }
    } else if (sit == 4) {//cavalo 1 + i j + 2
        if (kill_this(tab, i + 1, j + 2, xn, yn, true, false)) {
            return false;
        }
    } else if (sit == 5) {//cavalo 1 + i j - 2
        if (kill_this(tab, i + 1, j - 2, xn, yn, true, false)) {
            return false;
        }
    } else if (sit == 6) {//cavalo  i-1 j - 2
        if (kill_this(tab, i - 1, j - 2, xn, yn, true, false)) {
            return false;
        }
    } else if (sit == 7) {//cavalo i-1 j + 2
        if (kill_this(tab, i - 1, j + 2, xn, yn, true, false)) {
            return false;
        }
    } else if (sit == 8) {//cavalo  i-2 j - 1
        if (kill_this(tab, i - 2, j - 1, xn, yn, true, false)) {
            return false;
        }
    } else if (sit == 9) {//cavalo i-2 j + 1
        if (kill_this(tab, i - 2, j + 1, xn, yn, true, false)) {
            return false;
        }
    } else if (sit == 10) {//bispo j++ i++
        if (tab[i + 1][j + 1] == 6 || tab[i + 1][j + 1] == 10) {
            if (calc_checkwhite(tab,  i + 1, j + 1, xn, yn)==false || kill_this(tab, i + 1, j + 1, xn, yn, true, false)) {
                return false;
            }
        }
        k = i + 1;
        l = j + 1;
        while (tab[k][l] == 0 && k <= 7 && l <= 7) {
            if (kill_this(tab, k, l, xn, yn, true, true)) {
                return false;
            }
            k++;
            l++;
        }
        if (kill_this(tab, k, l, xn, yn, true, false)) {
            return false;
        }
    } else if (sit == 11) {//bispo j-- i++
        if (tab[i + 1][j - 1] == 6 || tab[i + 1][j - 1] == 10) {
            if (calc_checkwhite(tab,  i + 1, j - 1, xn, yn)==false || kill_this(tab, i + 1, j - 1, xn, yn, true, false)) {
                return false;
            }
        }
        k = i + 1;
        l = j - 1;
        while (tab[k][l] == 0 && k <= 7 && l >= 0) {
            if (kill_this(tab, k, l, xn, yn, true, true)) {
                return false;
            }
            k++;
            l--;
        }
        if (kill_this(tab, k, l, xn, yn, true, false)) {
            return false;
        }
    } else if (sit == 12) {//bispo j++ i--
        if (tab[i - 1][j + 1] == 6 || tab[i - 1][j + 1] == 10) {
            if (calc_checkwhite(tab,  i - 1, j + 1, xn, yn)==false || kill_this(tab, i - 1, j + 1, xn, yn, true, false)) {
                return false;
            }
        }
        k = i - 1;
        l = j + 1;
        while (tab[k][l] == 0 && k >= 0 && l <= 7) {
            if (kill_this(tab, k, l, xn, yn, true, true)) {
                return false;
            }
            k--;
            l++;
        }
        if (kill_this(tab, k, l, xn, yn, true, false)) {
            return false;
        }
    } else if (sit == 13) {//bispo j-- i--
        if (tab[i - 1][j - 1] == 6 || tab[i - 1][j - 1] == 10) {
            if (calc_checkwhite(tab,  i - 1, j - 1, xn, yn)==false || kill_this(tab, i - 1, j - 1, xn, yn, true, false)) {
                return false;
            }
        }
        k = i - 1;
        l = j - 1;
        while (tab[k][l] == 0 && k >= 0 && l >= 0) {
            if (kill_this(tab, k, l, xn, yn, true, true)) {
                return false;
            }
            k--;
            l--;

        }

        if (kill_this(tab, k, l, xn, yn, true, false)) {
            return false;
        }
    } else if (sit == 14) {//torre i++
        if (tab[i + 1][j] == 8 || tab[i + 1][j] == 10) {
            if (calc_checkwhite(tab,  i + 1, j, xn, yn)==false || kill_this(tab, i + 1, j, xn, yn, true, false)) {
                return false;
            }
        }
        k = i + 1;
        while (tab[k][j] == 0 && k <= 7) {
            if (kill_this(tab, k, j, xn, yn, true, true)) {
                return false;
            }
            k++;
        }
        if (kill_this(tab, k, j, xn, yn, true, false)) {
            return false;
        }
    } else if (sit == 15) {//torre j++
        if (tab[i][j + 1] == 8 || tab[i][j + 1] == 10) {
            if (calc_checkwhite(tab,  i, j + 1, xn, yn)==false || kill_this(tab, i, j + 1, xn, yn, true, false)) {
                return false;
            }
        }
        k = j + 1;
        while (tab[i][k] == 0 && k <= 7) {
            if (kill_this(tab, i, k, xn, yn, true, true)) {
                return false;
            }
            k++;
        }
        if (kill_this(tab, i, k, xn, yn, true, false)) {
            return false;
        }
    } else if (sit == 16) {//torre i--
        if (tab[i - 1][j] == 8 || tab[i - 1][j] == 10) {
            if (calc_checkwhite(tab,  i - 1, j, xn, yn)==false || kill_this(tab, i - 1, j, xn, yn, true, false)) {
                return false;
            }
        }
        k = i - 1;
        while (tab[k][j] == 0 && k >= 0) {
            if (kill_this(tab, k, j, xn, yn, true, true)) {
                return false;
            }
            k--;
        }
        if (kill_this(tab, k, j, xn, yn, true, false)) {
            return false;
        }
    } else if (sit == 17) {//torre j--
        if (tab[i][j - 1] == 8 || tab[i][j - 1] == 10) {
            if (calc_checkwhite(tab,  i, j - 1, xn, yn)==false || kill_this(tab, i, j - 1, xn, yn, true, false)) {
                return false;
            }
        }
        k = j - 1;
        while (tab[i][k] == 0 && k >= 0) {
            if (kill_this(tab, i, k, xn, yn, true, true)) {
                return false;
            }
            k--;
        }
        if (kill_this(tab, i, k, xn, yn, true, false)) {
            return false;
        }
    }
    checkmate acabou;
    acabou.exec();
    return true;
}

bool calc_checkblack(int **tab, int i, int j, int xn, int yn) {
    int k, l;
    bool check = false;
    if (i >= 1) {
        if (j <= 6) {
            if (tab[i - 1][j + 1] == 1) {//check peao
                check = true;
                if (tab[i][j] == 12) {
                    if(calc_checkmateblack(tab,  i, j, xn, yn, 0)){
                        check=false;
                    }
                }
                return check;
            }
        }
        if (j >= 1) {
            if (tab[i - 1][j - 1] == 1) {
                check = true;
                if (tab[i][j] == 12) {
                    if(calc_checkmateblack(tab,  i, j,xn, yn, 1)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }

    if (i <= 5) {//cavalo
        if (j <= 6) {
            if (tab[2 + i][j + 1] == 3) {
                check = true;
                if (tab[i][j] == 12) {
                    if(calc_checkmateblack(tab,  i, j,xn, yn, 2)){
                        check=false;
                    }
                }
                return check;
            }
        }
        if (j >= 1) {
            if (tab[i + 2][j - 1] == 3) {
                check = true;
                if (tab[i][j] == 12) {
                    if(calc_checkmateblack(tab,  i, j,xn, yn, 3)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }
    if (i <= 6) {
        if (j <= 5) {
            if (tab[i + 1][j + 2] == 3) {
                check = true;
                if (tab[i][j] == 12) {
                    if(calc_checkmateblack(tab,  i, j, xn, yn,4)){
                        check=false;
                    }
                }
                return check;
            }
        }
        if (j >= 2) {
            if (tab[i + 1][j - 2] == 3) {
                check = true;
                if (tab[i][j] == 12) {
                    if(calc_checkmateblack(tab,  i, j,xn, yn, 5)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }
    if (i >= 1) {
        if (j >= 2) {
            if (tab[i - 1][j - 2] == 3) {
                check = true;
                if (tab[i][j] == 12) {
                    if(calc_checkmateblack(tab,  i, j,xn, yn, 6)){
                        check=false;
                    }
                }
                return check;
            }
        }
        if (j <= 5) {
            if (tab[i - 1][j + 2] == 3) {
                check = true;
                if (tab[i][j] == 12) {
                    if(calc_checkmateblack(tab,  i, j,xn, yn, 7)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }
    if (i >= 2) {
        if (j >= 1) {
            if (tab[i - 2][j - 1] == 3) {
                check = true;
                if (tab[i][j] == 12) {
                    if(calc_checkmateblack(tab,  i, j,xn, yn, 8)){
                        check=false;
                    }
                }
                return check;
            }
        }
        if (j <= 6) {
            if (tab[i - 2][j + 1] == 3) {
                check = true;
                if (tab[i][j] == 12) {
                    if(calc_checkmateblack(tab,  i, j,xn, yn, 9)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }

    //parte bispo e rainha
    if (i <= 6 && j <= 6) {
        k = i + 1;
        l = j + 1;
        if (tab[k][l] == 5 || tab[k][l] == 9) {
            check = true;
            if (tab[i][j] == 12) {
                if(calc_checkmateblack(tab,  i, j,xn, yn, 10)){
                    check=false;
                }
            }
            return check;
        }
        while ((tab[k][l] == 0||tab[k][l] == 12) && (k < 7 && l < 7)) {
            k++;
            l++;
        }

        if(k<=7&&l<=7){
            if (tab[k][l] == 5 || tab[k][l] == 9) {
                check = true;
                if (tab[i][j] == 12) {
                    if(calc_checkmateblack(tab,  i, j, xn, yn,10)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }
    if (i <= 6 && j >= 1) {
        k = i + 1;
        l = j - 1;
        if (tab[k][l] == 5 || tab[k][l] == 9) {
            check = true;
            if (tab[i][j] == 12) {
                if(calc_checkmateblack(tab,  i, j,xn, yn, 11)){
                    check=false;
                }
            }
            return check;
        }
        while ((tab[k][l] == 0||tab[k][l] == 12) && k < 7 && l > 0) {
            k++;
            l--;
        }
        if(k<=7&&l>=0){
            if (tab[k][l] == 5 || tab[k][l] == 9) {
                check = true;
                if (tab[i][j] == 12) {
                    if(calc_checkmateblack(tab,  i, j,xn, yn, 11)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }
    if (j <= 6 && i >= 1) {
        k = i - 1;
        l = j + 1;
        if (tab[k][l] == 5 || tab[k][l] == 9) {
            check = true;
            if (tab[i][j] == 12) {
                if(calc_checkmateblack(tab,  i, j,xn, yn, 12)){
                    check=false;
                }
            }
            return check;
        }
        while ((tab[k][l] == 0||tab[k][l] == 12) && k > 0 && l < 7) {
            k--;
            l++;
        }
        if(k>=0 && l<=7){
            if (tab[k][l] == 5 || tab[k][l] == 9) {
                check = true;
                if (tab[i][j] == 12) {
                    if(calc_checkmateblack(tab,  i, j,xn, yn, 12)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }
    if (i >= 1 && j >= 1) {
        k = i - 1;
        l = j - 1;
        if (tab[k][l] == 5 || tab[k][l] == 9) {
            check = true;
            if (tab[i][j] == 12) {
                if(calc_checkmateblack(tab,  i, j,xn, yn, 13)){
                    check=false;
                }
            }
            return check;
        }
        while ((tab[k][l] == 0||tab[k][l] == 12) && k > 0 && l > 0) {
            k--;
            l--;
        }

        if(k>=0&&l>=0){
            if (tab[k][l] == 5 || tab[k][l] == 9) {
                check = true;
                if (tab[i][j] == 12) {
                    if(calc_checkmateblack(tab,  i, j,xn, yn, 13)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }

    //rainha e torre
    k = i + 1;
    if (i <= 6) {
        if (tab[k][j] == 7 || tab[k][j] == 9) {
            check = true;
            if (tab[i][j] == 12) {
                if(calc_checkmateblack(tab,  i, j,xn, yn, 14)){
                    check=false;
                }
            }
            return check;
        }
        while ((tab[k][j] == 0||tab[k][j] == 12) && k < 7) {
            k++;
        }
        if(k<=7){
            if (tab[k][j] == 7 || tab[k][j] == 9) {
                check = true;
                if (tab[i][j] == 12) {
                    if(calc_checkmateblack(tab,  i, j,xn, yn, 14)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }
    if (j <= 6) {
        k = j + 1;
        if (tab[i][k] == 7 || tab[i][k] == 9) {
            check = true;
            if (tab[i][j] == 12) {
                if(calc_checkmateblack(tab,  i, j,xn, yn, 15)){
                    check=false;
                }
            }
            return check;
        }
        while ((tab[i][k] == 0||tab[i][k] == 12) && k < 7) {
            k++;
        }
        if(k<=7){
            if (tab[i][k] == 7 || tab[i][k] == 9) {
                check = true;
                if (tab[i][j] == 12) {
                    if(calc_checkmateblack(tab,  i, j,xn, yn, 15)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }
    if (i >= 1) {
        k = i - 1;
        if (tab[k][j] == 7 || tab[k][j] == 9) {
            check = true;
            if (tab[i][j] == 12) {
                if(calc_checkmateblack(tab,  i, j,xn, yn, 16)){
                    check=false;
                }
            }
            return check;
        }
        while ((tab[k][j] == 0||tab[k][j] == 12) && k > 0) {
            k--;
        }
        if(k>=0){
            if (tab[k][j] == 7 || tab[k][j] == 9) {
                check = true;
                if (tab[i][j] == 12) {
                    if(calc_checkmateblack(tab,  i, j,xn, yn, 16)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }
    if (j >= 1) {
        k = j - 1;
        if (tab[i][k] == 7 || tab[i][k] == 9) {
            check = true;
            if (tab[i][j] == 12) {
                if(calc_checkmateblack(tab,  i, j,xn, yn, 17)){
                    check=false;
                }
            }
            return check;
        }
        while ((tab[i][k] == 0||tab[i][k] == 12) && k > 0) {
            k--;
        }
        if(k>=0){
            if (tab[i][k] == 7 || tab[i][k] == 9) {
                check = true;
                if (tab[i][j] == 12) {
                    if(calc_checkmateblack(tab,  i, j,xn, yn, 17)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }

    return check;
}

bool calc_checkwhite(int **tab, int i, int j, int xn, int yn) {
    bool check = false;
    int k, l;

    if (i <= 6) {
        if (j <= 6) {
            if (tab[i + 1][j + 1] == 2) {//check peao
                check = true;
                if (tab[i][j] == 11) {
                    if(calc_checkmatewhite(tab,  i, j,xn, yn, 0)){
                        check=false;
                    }
                }
                return check;
            }
        }
        if (j >= 1) {
            if (i <= 6) {
                if (tab[i + 1][j - 1] == 2) {
                    check = true;
                    if (tab[i][j] == 11) {
                        if(calc_checkmatewhite(tab,  i, j,xn, yn, 1)){
                            check=false;
                        }
                    }
                    return check;
                }
            }
        }
    }

    if (i <= 5) {//cavalo
        if (j <= 6) {
            if (tab[2 + i][j + 1] == 4) {
                check = true;
                if (tab[i][j] == 11) {
                    if(calc_checkmatewhite(tab,  i, j, xn, yn,2)){
                        check=false;
                    }

                }
                return check;
            }
        }
        if (j >= 1) {
            if (tab[i + 2][j - 1] == 4) {
                check = true;
                if (tab[i][j] == 11) {
                    if(calc_checkmatewhite(tab,  i, j, xn, yn,3)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }
    if (i <= 6) {
        if (j <= 5) {
            if (tab[i + 1][j + 2] == 4) {
                check = true;
                if (tab[i][j] == 11) {
                    if(calc_checkmatewhite(tab,  i, j, xn, yn,4)){
                        check=false;
                    }
                }
                return check;
            }
        }
        if (j >= 2) {
            if (tab[i + 1][j - 2] == 4) {
                check = true;
                if (tab[i][j] == 11) {
                    if(calc_checkmatewhite(tab,  i, j, xn, yn,5)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }
    if (i >= 1) {
        if (j >= 2) {
            if (tab[i - 1][j - 2] == 4) {
                check = true;
                if (tab[i][j] == 11) {
                    if(calc_checkmatewhite(tab,  i, j, xn, yn,6)){
                        check=false;
                    }
                }
                return check;
            }
        }
        if (j <= 5) {
            if (tab[i - 1][j + 2] == 4) {
                check = true;
                if (tab[i][j] == 11) {
                    if(calc_checkmatewhite(tab,  i, j, xn, yn,7)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }
    if (i >= 2) {
        if (j <= 1) {
            if (tab[i - 2][j - 1] == 4) {
                check = true;
                if (tab[i][j] == 11) {
                    if(calc_checkmatewhite(tab,  i, j,xn, yn, 8)){
                        check=false;
                    }
                }
                return check;
            }
        }
        if (j >= 6) {
            if (tab[i - 2][j + 1] == 4) {
                check = true;
                if (tab[i][j] == 11) {
                    if(calc_checkmatewhite(tab,  i, j,xn, yn, 9)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }

    //parte bispo e rainha
    if (i <= 6 && j <= 6) {
        k = i + 1;
        l = j + 1;
        if (tab[k][l] == 6 || tab[k][l] == 10) {
            check = true;
            if (tab[i][j] == 11) {
                if(calc_checkmatewhite(tab,  i, j, xn, yn,10)){
                    check=false;
                }
            }
            return check;
        }
        while ((tab[k][l] == 0||tab[k][l] == 11) && k < 7 && l < 7) {
            k++;
            l++;
        }
        if(k<=7&&l<=7){
            if (tab[k][l] == 6 || tab[k][l] == 10) {
                check = true;
                if (tab[i][j] == 11) {
                    if(calc_checkmatewhite(tab,  i, j, xn, yn,10)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }
    if (i <= 6 && j >= 1) {
        k = i + 1;
        l = j - 1;
        if (tab[k][l] == 6 || tab[k][l] == 10) {
            check = true;
            if (tab[i][j] == 11) {
                if(calc_checkmatewhite(tab,  i, j, xn, yn,11)){
                    check=false;
                }
            }
            return check;
        }
        while ((tab[k][l] == 0||tab[k][l] == 11) && k < 7 && l > 0) {
            k++;
            l--;
        }
        if(k<=7&&l>=0){
            if (tab[k][l] == 6 || tab[k][l] == 10) {
                check = true;
                if (tab[i][j] == 11) {
                    if(calc_checkmatewhite(tab,  i, j,xn, yn, 11)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }
    if (i >= 1 && j <= 6) {
        k = i - 1;
        l = j + 1;
        if (tab[k][l] == 6 || tab[k][l] == 10) {
            check = true;
            if (tab[i][j] == 11) {
                if(calc_checkmatewhite(tab,  i, j, xn, yn,12)){
                    check=false;
                }

            }
            return check;
        }
        while ((tab[k][l] == 0||tab[k][l] == 11) && k > 0 && l < 7) {
            k--;
            l++;
        }
        if(k>=0&&l<=7){
            if (tab[k][l] == 6 || tab[k][l] == 10) {
                check = true;
                if (tab[i][j] == 11) {
                    if(calc_checkmatewhite(tab,  i, j, xn, yn,12)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }
    if (i >= 1 && j >= 1) {
        k = i - 1;
        l = j - 1;
        if (tab[k][l] == 6 || tab[k][l] == 10) {
            check = true;
            if (tab[i][j] == 11) {
                if(calc_checkmatewhite(tab,  i, j,xn, yn, 13)){
                    check=false;
                }
            }
            return check;
        }
        while ((tab[k][l] == 0||tab[k][l] == 11) && k > 0 && l > 0) {
            k--;
            l--;
        }
        if(k>=0&&l>=0){
            if (tab[k][l] == 6 || tab[k][l] == 10) {
                check = true;
                if (tab[i][j] == 11) {
                    if(calc_checkmatewhite(tab,  i, j, xn, yn,13)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }
    //rainha e torre
    if (i <= 6) {
        k = i + 1;
        if (tab[k][j] == 8 || tab[k][j] == 10) {
            check = true;
            if (tab[i][j] == 11) {
                if(calc_checkmatewhite(tab,  i, j, xn, yn,14)){
                    check=false;
                }
            }
            return check;
        }
        while ((tab[k][j] == 0||tab[k][j] == 11) && k < 7) {
            k++;
        }
        if(k<=7){
            if (tab[k][j] == 8 || tab[k][j] == 10) {
                check = true;
                if (tab[i][j] == 11) {
                    if(calc_checkmatewhite(tab,  i, j,xn, yn, 14)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }
    if (j <= 6) {
        k = j + 1;
        if (tab[i][k] == 8 || tab[i][k] == 10) {
            check = true;
            if (tab[i][j] == 11) {
                if(calc_checkmatewhite(tab,  i, j,xn, yn, 15)){
                    check=false;
                }
            }
            return check;
        }
        while ((tab[i][k] == 0||tab[i][k] == 11) && k < 7) {
            k++;
        }
        if(k<=7){
            if (tab[i][k] == 8 || tab[i][k] == 10) {
                check = true;
                if (tab[i][j] == 11) {
                    if(calc_checkmatewhite(tab,  i, j, xn, yn,15)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }
    if (i >= 1) {
        k = i - 1;
        if (tab[k][j] == 8 || tab[k][j] == 10) {
            check = true;
            if (tab[i][j] == 11) {
                if(calc_checkmatewhite(tab, i, j,xn, yn, 16)){
                    check=false;
                }
            }
            return check;
        }
        while ((tab[k][j] == 0||tab[k][j] == 11) && k > 0) {
            k--;
        }
        if(k>=0){
            if (tab[k][j] == 8 || tab[k][j] == 10) {
                check = true;
                if (tab[i][j] == 11) {
                    if(calc_checkmatewhite(tab, i, j,xn, yn, 16)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }
    if (j >= 1) {
        k = j - 1;
        if (tab[i][k] == 8 || tab[i][k] == 10) {
            check = true;
            if (tab[i][j] == 11) {
                if(calc_checkmatewhite(tab, i, j,xn, yn, 17)){
                    check=false;
                }
            }
            return check;
        }
        while ((tab[i][k] == 0||tab[i][k] == 11) && k > 0) {
            k--;
        }
        if(k>=0){
            if (tab[i][k] == 8 || tab[i][k] == 10) {
                check = true;
                if (tab[i][j] == 11) {

                    if(calc_checkmatewhite(tab, i, j, xn, yn,17)){
                        check=false;
                    }
                }
                return check;
            }
        }
    }

    return check;
}

bool calc_posi_rei(int **tab,int xn, int yn, bool branco) {
    int i, j;
    for (i = 0; i <= 7; i++) {
        for (j = 0; j <= 7; j++) {
            if (!branco) {
                if (tab[i][j] == 12) {
                    if (calc_checkblack(tab, i, j, xn, yn)) {
                        return true;
                    }
                }
            } else {
                if (tab[i][j] == 11) {
                    if (calc_checkwhite(tab, i, j, xn, yn)) {

                        return true;
                    }
                }
            }
        }
    }
    return false;
}


void Tabuleiro::calc_stalemate(){
    int pec=0;
    int peca, peca2, posbx, posby, pospx, pospy;
    bool cinz1, cinz2;
    for(int i=0; i<=7; i++){
        for(int j=0; j<=7; j++){
            if(tab[i][j]!=0&&tab[i][j]!=12&&tab[i][j]!=11){
                pec++;

                if(pec==1){
                    if(i%2==0&&j%2==0){
                        cinz1=true;
                    }else{
                        cinz1=false;
                    }
                    peca=tab[i][j];
                }else if(pec==2){
                    if(i%2==0&&j%2==0){
                        cinz2=true;
                    }else{
                        cinz2=false;
                    }
                    peca2=tab[i][j];
                }

            }
            else if(tab[i][j]==11){
                posbx=i;
                posby=j;
            }else if(tab[i][j]==12){
                pospx=i;
                pospy=j;
            }

        }
    }

    if(pec>2){
        stalemate=false;
    }
    else if(pec==1){
        if(peca==1||peca==2||peca==7||peca==8||peca==9||peca==10){
            stalemate=false;

        }else{
            stalemate=true;
            return;
        }
    }else{
        if(peca==3&&peca2==4||peca==4&&peca2==3||peca==5&&peca2==6&&((cinz1==true&&cinz2==true)||(cinz1==false&&cinz2==false))){
            stalemate=true;
            return;
        }else{
            stalemate=false;

        }
    }
    if(branco){
        if(posbx<=6){
            if(calc_checkwhite(tab, posbx+1, posby, xn, yn)){
                stalemate=true;
            }else{
                stalemate=false;
                return;
            }
            if(posby<=6){
                if(calc_checkwhite(tab, posbx+1, posby+1, xn, yn)){
                    stalemate=true;
                }else{
                    stalemate=false;
                    return;
                }
            }
            if(posby>=1){
                if(calc_checkwhite(tab, posbx+1, posby-1, xn, yn)){
                    stalemate=true;
                }else{
                    stalemate=false;
                    return;
                }
            }
        }
        if(posbx>=1){
            if(calc_checkwhite(tab, posbx-1, posby, xn, yn)){
                stalemate=true;
            }else{
                stalemate=false;
                return;
            }
            if(posby<=6){
                if(calc_checkwhite(tab, posbx-1, posby+1, xn, yn)){
                    stalemate=true;
                }else{
                    stalemate=false;
                    return;
                }
            }
            if(posbx>=1){

                if(calc_checkwhite(tab, posbx-1, posby-1, xn, yn)){
                    stalemate=true;
                }else{
                    stalemate=false;
                    return;
                }
            }
        }
        if(posby>=1){
            if(calc_checkwhite(tab, posbx, posby-1, xn, yn)){
                stalemate=true;
            }else{
                stalemate=false;
                return;
            }
        }
        if(posby<=6){
            if(calc_checkwhite(tab, posbx, posby+1, xn, yn)){
                stalemate=true;
            }else{
                stalemate=false;
                return;
            }
        }
    }else{
        if(pospx<=6){
            if(calc_checkblack(tab, pospx+1, pospy, xn, yn)){
                stalemate=true;
            }else{
                stalemate=false;
                return;
            }
            if(pospy<=6){
                if(calc_checkblack(tab, pospx+1, pospy+1, xn, yn)){
                    stalemate=true;
                }else{
                    stalemate=false;
                    return;
                }
            }
            if(pospy>=1){
                if(calc_checkblack(tab, pospx+1, pospy-1, xn, yn)){
                    stalemate=true;
                }else{
                    stalemate=false;
                    return;
                }
            }
        }
        if(pospx>=1){
            if(calc_checkblack(tab, pospx-1, pospy, xn, yn)){
                stalemate=true;
            }else{
                stalemate=false;
                return;
            }
            if(pospy<=6){
                if(calc_checkblack(tab, pospx-1, pospy+1, xn, yn)){
                    stalemate=true;
                }else{
                    stalemate=false;
                    return;
                }
            }
            if(pospx>=1){

                if(calc_checkblack(tab, pospx-1, pospy-1, xn, yn)){
                    stalemate=true;
                }else{
                    stalemate=false;
                    return;
                }
            }
        }
        if(pospy>=1){
            if(calc_checkblack(tab, pospx, pospy-1, xn, yn)){
                stalemate=true;
            }else{
                stalemate=false;
                return;
            }
        }
        if(pospy<=6){
            if(calc_checkblack(tab, pospx, pospy+1, xn, yn)){
                stalemate=true;
            }else{
                stalemate=false;
                return;
            }
        }
    }
    for(int i=0; i<=7; i++){
        for(int j=0; j<=7; j++){
            if(tab[i][j]!=0&&tab[i][j]!=12&&tab[i][j]!=11){
                if(i!=0){
                    if(calc_block(tab, i, j, 0,0,branco)){
                        stalemate=false;
                        return;
                    }else{
                        stalemate=true;
                    }
                }else{
                    if(calc_block(tab, i, j, 1,0,branco)){
                        stalemate=false;
                        return;
                    }else{
                        stalemate=true;
                    }
                }
            }
        }
    }

}

