#ifndef CHESS_H
#define CHESS_H

#include <QFile>
#include "checkmate.h"
#include "choosewhite.h"
#include "chooseblack.h"




bool calc_checkblack(int **tab, int i, int j, int xn, int yn);
bool calc_checkwhite(int **tab,int i, int j, int xn, int yn);
bool calc_posi_rei(int **tab,int xn, int yn, bool branco);
bool calc_block(int **tab, int i, int j, int xn, int yn, bool branco);

class Tabuleiro
{
    int **tab;


public:
    Tabuleiro();
    int **Mostratabul();
    ~Tabuleiro();
    void pecaanda();
    void abrir(QString name);
    void iniciatab(int **tabol);
    void novojogo();
    bool salvar();
    void bispoanda(int **tab, int x, int y, int xn, int yn, bool &branco);
    void rainhaanda(int **tab, int x, int y, int xn, int yn, bool &branco);
    void reianda(int **tab, int x, int y, bool &reiandou, int xn, int yn, bool &branco);
    void cavaloanda(int **tab, int x, int y, int xn, int yn, bool &branco);
    void torreanda(int **tab, int x, int y, int xn, int yn, bool &branco);
    void peaoanda(int **tab, int x, int y, bool &hist, int &ya, int xn, int yn, bool &branco);
    void calc_stalemate();
    bool reiandoub;
    QString nomedoarquivo;
    bool reiandoup;
    bool branco;
    bool stalemate;
    int contagem;
    bool hist;
    bool sel;
    QList<int> numb;
    QList<int> nump;
    int ya;
    int x, y;
    int xn, yn;
    bool escolheu;
    bool check;
    bool fechou;
};

#endif // CHESS_H
