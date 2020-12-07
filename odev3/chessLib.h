#ifndef CHESSLIB_H_
#define CHESSLIB_H_

typedef struct poz
{
    short yatay;
    char dusey;
}poz;

int **createBoard();

void haraketYazdir(char,poz);

poz *haraketSah(poz);

int sahHaraketSayisi(int,int);

poz *haraketVezir(poz);

int vezirHaraketSayisi(int,int);

poz *haraketFil(poz);

int filHaraketSayisi(int,int);

poz *haraketAt(poz);

int atHaraketSayisi(int,int);

poz *haraketKale(poz);

int kaleHaraketSayisi(int,int);

poz *haraketPiyon(poz);

int piyonHaraketSayisi(int,int);


#endif