#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chessLib.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


int **createBoard(){

    int **board = (int**)malloc(8*sizeof(int*));

    for(int i = 0;i < 8;i++){
        *(board + i) = (int*)malloc(8*sizeof(int));
    }

    return board;
}

void haraketYazdir(char tas,poz ilkPozisyon){

    poz *tasinHaraketleri;
    int tasHaraketSayisi = 0;

    int konumi = 8 - ilkPozisyon.yatay;
    int konumj = (int)ilkPozisyon.dusey - 65;


    if(tas == 'S'){

        tasinHaraketleri = haraketSah(ilkPozisyon);
        tasHaraketSayisi = sahHaraketSayisi(konumi,konumj);

    }else if(tas == 'V'){

        tasinHaraketleri = haraketVezir(ilkPozisyon);
        tasHaraketSayisi = vezirHaraketSayisi(konumi,konumj);

    }else if(tas == 'F'){

        tasinHaraketleri = haraketFil(ilkPozisyon);
        tasHaraketSayisi = filHaraketSayisi(konumi,konumj);

    }else if(tas == 'A'){

        tasinHaraketleri = haraketAt(ilkPozisyon);
        tasHaraketSayisi = atHaraketSayisi(konumi,konumj);

    }else if(tas == 'K'){

        tasinHaraketleri = haraketKale(ilkPozisyon);
        tasHaraketSayisi = kaleHaraketSayisi(konumi,konumj);

    }else if(tas == 'P'){

        tasinHaraketleri = haraketPiyon(ilkPozisyon);
        tasHaraketSayisi = piyonHaraketSayisi(konumi,konumj);

    }

    
    int **board;
    board = createBoard();

    int tmpKonumi = 0;
    int tmpKonumj = 0;

    for(int i = 0;i < 8;i++){

        printf("%s%d %s| ",KBLU,(8-i),KYEL);

        for(int j = 0;j < 8;j++){

            if(i == konumi && j == konumj){
                printf("%s2 ",KCYN);
            }else{

                int varMi = 0;

                for(int k = 0 ; k < tasHaraketSayisi;k++){

                    tmpKonumi = 8 - tasinHaraketleri[k].yatay;
                    tmpKonumj = (int)tasinHaraketleri[k].dusey - 65;
                    //printf("\nkonumlar i: %d j: %d \n",tmpKonumi,tmpKonumj);
                    if(i == tmpKonumi && j == tmpKonumj){
                        varMi = 1;
                        break;
                    }

                }

                if(varMi == 1){
                    printf("%s1 ",KGRN);
                }else{
                    printf("%s0 ",KMAG);
                }

            }

        }
        if(i != 8){
            printf("\n");
        }
    }

    printf("%s   ~~~~~~~~~~~~~~~~\n",KYEL);
    printf("%s    A B C D E F G H\n",KBLU);


}

poz *haraketSah(poz ilkPozisyon){

    int sahi = 8 - ilkPozisyon.yatay;
    int sahj = (int)ilkPozisyon.dusey - 65;

    int sahinHareketleriArrayIndex = 0;
    poz *sahinHareketleriArray = (poz*)malloc(sahHaraketSayisi(sahi,sahj)*sizeof(poz));

    for(int i = sahi - 1;i <= sahi+1;i++){

        for(int j = sahj -1;j <= sahj +1;j++){

            if( !(i == sahi && j == sahj) && ( i <= 7 && j <= 7) && ( 0 <= i && 0 <= j) ){
                
                poz hrkt;
                hrkt.yatay = 8 - i;
                hrkt.dusey = (char)(j + 65);
                sahinHareketleriArray[sahinHareketleriArrayIndex] = hrkt;
                
                sahinHareketleriArrayIndex++;

            }

        }
    }

    return sahinHareketleriArray;
}

int sahHaraketSayisi(int sahi,int sahj){
    int haraketSayisi = 0;

    if( ( sahj == 0 && (sahi == 0 || sahi == 7) ) || (sahj == 7 && ( sahi == 0 || sahi == 7))){
        haraketSayisi = 3;
    }else if( ( sahj == 0 && (sahi != 0 && sahi != 7) ) || (sahj == 7 && ( sahi != 0 && sahi != 7)) ){
        haraketSayisi = 5;
    }else {
        haraketSayisi = 8;
    }

    return haraketSayisi;
}

poz *haraketVezir(poz ilkPozisyon){

    int veziri = 8 - ilkPozisyon.yatay;
    int vezirj = (int)ilkPozisyon.dusey - 65;

    int vezirinHareketleriArrayIndex = 0;
    poz *vezirinHareketleriArray = (poz*)malloc(vezirHaraketSayisi(veziri,vezirj)*sizeof(poz));

    int tmpVeziri = 0;
    int tmpVezirj = 0;

    //sol ust kordinatlar
    tmpVeziri = veziri - 1;
    tmpVezirj = vezirj - 1;

    while (tmpVeziri >= 0 && tmpVezirj >= 0){

        poz hrkt;
        hrkt.yatay = 8 - tmpVeziri;
        hrkt.dusey = (char)(tmpVezirj + 65);
        vezirinHareketleriArray[vezirinHareketleriArrayIndex] = hrkt;
        vezirinHareketleriArrayIndex++;

        tmpVeziri--;
        tmpVezirj--;
    }

    //sag alt kordinatlar
    tmpVeziri = veziri + 1;
    tmpVezirj = vezirj + 1;

    while (tmpVeziri <= 7 && tmpVezirj <= 7){

        poz hrkt;
        hrkt.yatay = 8 - tmpVeziri;
        hrkt.dusey = (char)(tmpVezirj + 65);
        vezirinHareketleriArray[vezirinHareketleriArrayIndex] = hrkt;
        vezirinHareketleriArrayIndex++;

        tmpVeziri++;
        tmpVezirj++;
    }

    //sol taraf kordinatlar
    tmpVeziri = veziri;
    tmpVezirj = vezirj - 1;

    while (tmpVezirj >= 0){
        
        poz hrkt;
        hrkt.yatay = 8 - tmpVeziri;
        hrkt.dusey = (char)(tmpVezirj + 65);
        vezirinHareketleriArray[vezirinHareketleriArrayIndex] = hrkt;
        vezirinHareketleriArrayIndex++;

        tmpVezirj--;
    }

    //sag taraf kordinatlar
    tmpVeziri = veziri;
    tmpVezirj = vezirj + 1;

    while (tmpVezirj <= 7){
        
        poz hrkt;
        hrkt.yatay = 8 - tmpVeziri;
        hrkt.dusey = (char)(tmpVezirj + 65);
        vezirinHareketleriArray[vezirinHareketleriArrayIndex] = hrkt;
        vezirinHareketleriArrayIndex++;

        tmpVezirj++;
    }

    //yukari taraf kordinatlar
    tmpVeziri = veziri - 1;
    tmpVezirj = vezirj;

    while (tmpVeziri >= 0){
        
        poz hrkt;
        hrkt.yatay = 8 - tmpVeziri;
        hrkt.dusey = (char)(tmpVezirj + 65);
        vezirinHareketleriArray[vezirinHareketleriArrayIndex] = hrkt;
        vezirinHareketleriArrayIndex++;

        tmpVeziri--;
    }

    //asagi taraf kordinatlar
    tmpVeziri = veziri + 1;
    tmpVezirj = vezirj;

    while (tmpVeziri <= 7){
        
        poz hrkt;
        hrkt.yatay = 8 - tmpVeziri;
        hrkt.dusey = (char)(tmpVezirj + 65);
        vezirinHareketleriArray[vezirinHareketleriArrayIndex] = hrkt;
        vezirinHareketleriArrayIndex++;

        tmpVeziri++;
    }

    //sol alt taraf kordinatlar
    tmpVeziri = veziri + 1;
    tmpVezirj = vezirj - 1;

    while (tmpVeziri <= 7 && tmpVezirj >= 0){
        
        poz hrkt;
        hrkt.yatay = 8 - tmpVeziri;
        hrkt.dusey = (char)(tmpVezirj + 65);
        vezirinHareketleriArray[vezirinHareketleriArrayIndex] = hrkt;
        vezirinHareketleriArrayIndex++;

        tmpVeziri++;
        tmpVezirj--;
    }

    //sag ust taraf kordinatlar
    tmpVeziri = veziri - 1;
    tmpVezirj = vezirj + 1;

    while (tmpVeziri >= 0 && tmpVezirj <= 7){
        
        poz hrkt;
        hrkt.yatay = 8 - tmpVeziri;
        hrkt.dusey = (char)(tmpVezirj + 65);
        vezirinHareketleriArray[vezirinHareketleriArrayIndex] = hrkt;
        vezirinHareketleriArrayIndex++;

        tmpVeziri--;
        tmpVezirj++;
    }

    return vezirinHareketleriArray;

}


int vezirHaraketSayisi(int veziri,int vezirj){

    int haraketSayisi = 14;

    if(veziri >= vezirj){

        haraketSayisi += vezirj;
        haraketSayisi += 7 - veziri;

    }else{

        haraketSayisi += veziri;
        haraketSayisi += 7 - vezirj;

    }

    if((veziri + vezirj) >= 7){

        haraketSayisi += 7 - veziri;
        haraketSayisi += 7 - vezirj;

    }else{

        haraketSayisi += vezirj;
        haraketSayisi += veziri;

    }


    return haraketSayisi;

}

poz *haraketFil(poz ilkPozisyon){

    int fili = 8 - ilkPozisyon.yatay;
    int filj = (int)ilkPozisyon.dusey - 65;

    int filinHareketleriArrayIndex = 0;
    poz *filinHareketleriArray = (poz*)malloc(filHaraketSayisi(fili,filj)*sizeof(poz));

    int tmpFili = 0;
    int tmpFilj = 0;


    //sol ust kordinatlar
    tmpFili = fili - 1;
    tmpFilj = filj - 1;

    while (tmpFili >= 0 && tmpFilj >= 0){
        
        poz hrkt;
        hrkt.yatay = 8 - tmpFili;
        hrkt.dusey = (char)(tmpFilj + 65);
        filinHareketleriArray[filinHareketleriArrayIndex] = hrkt;
        filinHareketleriArrayIndex++;

        tmpFili--;
        tmpFilj--;
    }

    //sag alt kordinatlar
    tmpFili = fili + 1;
    tmpFilj = filj + 1;

    while (tmpFili <= 7 && tmpFilj <= 7){

        poz hrkt;
        hrkt.yatay = 8 - tmpFili;
        hrkt.dusey = (char)(tmpFilj + 65);
        filinHareketleriArray[filinHareketleriArrayIndex] = hrkt;
        filinHareketleriArrayIndex++;

        tmpFili++;
        tmpFilj++;
    }

    //sol alt taraf kordinatlar
    tmpFili = fili + 1;
    tmpFilj = filj - 1;

    while (tmpFili <= 7 && tmpFilj >= 0){

        poz hrkt;
        hrkt.yatay = 8 - tmpFili;
        hrkt.dusey = (char)(tmpFilj + 65);
        filinHareketleriArray[filinHareketleriArrayIndex] = hrkt;
        filinHareketleriArrayIndex++;

        tmpFili++;
        tmpFilj--;
    }

    //sag ust taraf kordinatlar
    tmpFili = fili - 1;
    tmpFilj = filj + 1;

    while (tmpFili >= 0 && tmpFilj <= 7){

        poz hrkt;
        hrkt.yatay = 8 - tmpFili;
        hrkt.dusey = (char)(tmpFilj + 65);
        filinHareketleriArray[filinHareketleriArrayIndex] = hrkt;
        filinHareketleriArrayIndex++;

        tmpFili--;
        tmpFilj++;
    }

    return filinHareketleriArray;

}

int filHaraketSayisi(int fili,int filj){
    int haraketSayisi = 0;

    if(fili >= filj){

        haraketSayisi += filj;
        haraketSayisi += 7 - fili;

    }else{

        haraketSayisi += fili;
        haraketSayisi += 7 - filj;

    }

    if((fili + filj) >= 7){

        haraketSayisi += 7 - fili;
        haraketSayisi += 7 - filj;

    }else{

        haraketSayisi += filj;
        haraketSayisi += fili;

    }

    return haraketSayisi;
}


poz *haraketAt(poz ilkPozisyon){

    int ati = 8 - ilkPozisyon.yatay;
    int atj = (int)ilkPozisyon.dusey - 65;

    int atinHareketleriArrayIndex = 0;
    poz *atinHareketleriArray = (poz*)malloc(atHaraketSayisi(ati,atj)*sizeof(poz));

    int tmpAti = ati - 2;
    int tmpAtj = atj - 1;

    for(int i = 0 ; i < 4;i++){

        if(i == 2){
            tmpAtj = atj - 1;
            tmpAti += 4;
        }

        if(tmpAti >= 0 && tmpAti <= 7 && tmpAtj >= 0 && tmpAtj <= 7){
            
            poz hrkt;
            hrkt.yatay = 8 - tmpAti;
            hrkt.dusey = (char)(tmpAtj + 65);
            atinHareketleriArray[atinHareketleriArrayIndex] = hrkt;
            atinHareketleriArrayIndex++;

        }

        tmpAtj += 2;
    }

    tmpAti = ati - 1;
    tmpAtj = atj - 2;

    for(int i = 0 ; i < 4;i++){

        if(i == 2){
            tmpAti = ati - 1;
            tmpAtj += 4;
        }

        if(tmpAti >= 0 && tmpAti <= 7 && tmpAtj >= 0 && tmpAtj <= 7){

            poz hrkt;
            hrkt.yatay = 8 - tmpAti;
            hrkt.dusey = (char)(tmpAtj + 65);
            atinHareketleriArray[atinHareketleriArrayIndex] = hrkt;
            atinHareketleriArrayIndex++;

        }

        tmpAti += 2;
    }

    return atinHareketleriArray;

}

int atHaraketSayisi(int ati,int atj){
    int haraketSayisi = 0;

    if(((ati == 0 || ati == 7) && (atj == 0 || atj == 7) )){
        haraketSayisi = 2;
    }else if( (ati == 0 && (atj == 1 || atj == 7)) || ( (ati == 1 || ati == 6) && (atj == 0 || atj == 7))   || (ati == 7 && (atj == 1 || atj == 6)) ){
        haraketSayisi = 3;
    }else if( ((ati == 0 || ati == 7) && (atj >= 2 && atj <= 5)) || ( (atj==0 || atj == 7) && (ati >=2 && ati <=5) || ( (ati == 6 || ati == 1) && (atj == 1 || atj == 6) )   )){
        haraketSayisi = 4;
    }else if( ((atj == 1 || atj == 6) && ( ati >= 2 && ati <= 5)) || ((ati == 1 || ati == 6) && ( atj >= 2 && atj <= 5)) ){
        haraketSayisi = 6;
    }else{
        haraketSayisi = 8;
    }

    return haraketSayisi;
}

poz *haraketKale(poz ilkPozisyon){

    int kalei = 8 - ilkPozisyon.yatay;
    int kalej = (int)ilkPozisyon.dusey - 65;

    int kaleninHareketleriArrayIndex = 0;
    poz *kaleninHareketleriArray = (poz*)malloc(kaleHaraketSayisi(kalei,kalej)*sizeof(poz));

    int tmpKalei = 0;
    int tmkKalej = 0;

    //sol taraf kordinatlar
    tmpKalei = kalei;
    tmkKalej = kalej - 1;

    while (tmkKalej >= 0){

        poz hrkt;
        hrkt.yatay = 8 - tmpKalei;
        hrkt.dusey = (char)(tmkKalej + 65);
        kaleninHareketleriArray[kaleninHareketleriArrayIndex] = hrkt;
        kaleninHareketleriArrayIndex++;

        tmkKalej--;
    }

    //sag taraf kordinatlar
    tmpKalei = kalei;
    tmkKalej = kalej + 1;

    while (tmkKalej <= 7){

        poz hrkt;
        hrkt.yatay = 8 - tmpKalei;
        hrkt.dusey = (char)(tmkKalej + 65);
        kaleninHareketleriArray[kaleninHareketleriArrayIndex] = hrkt;
        kaleninHareketleriArrayIndex++;
        
        tmkKalej++;
    }

    //yukari taraf kordinatlar
    tmpKalei = kalei - 1;
    tmkKalej = kalej;

    while (tmpKalei >= 0){
        poz hrkt;
        hrkt.yatay = 8 - tmpKalei;
        hrkt.dusey = (char)(tmkKalej + 65);
        kaleninHareketleriArray[kaleninHareketleriArrayIndex] = hrkt;
        kaleninHareketleriArrayIndex++;
        
        tmpKalei--;
    }

    //asagi taraf kordinatlar
    tmpKalei = kalei + 1;
    tmkKalej = kalej;

    while (tmpKalei <= 7){
        poz hrkt;
        hrkt.yatay = 8 - tmpKalei;
        hrkt.dusey = (char)(tmkKalej + 65);
        kaleninHareketleriArray[kaleninHareketleriArrayIndex] = hrkt;
        kaleninHareketleriArrayIndex++;
        
        tmpKalei++;
    }

    return kaleninHareketleriArray;

}

int kaleHaraketSayisi(int kalei,int kalej){
    return 14;
}

poz *haraketPiyon(poz ilkPozisyon){

    int piyoni = 8 - ilkPozisyon.yatay;
    int piyonj = (int)ilkPozisyon.dusey - 65;

    int piyonunHareketleriArrayIndex = 0;
    poz *piyonunHareketleriArray = (poz*)malloc(kaleHaraketSayisi(piyoni,piyonj)*sizeof(poz));

    if(piyoni == 6){

        for(int i = 0; i < 2 ;i++){

            piyoni--;

            if( (piyoni >= 0 && piyoni <= 7) && (piyonj >= 0 && piyonj <= 7) ){
                poz hrkt;
                hrkt.yatay = 8 - piyoni;
                hrkt.dusey = (char)(piyonj + 65);
                piyonunHareketleriArray[piyonunHareketleriArrayIndex] = hrkt;
                piyonunHareketleriArrayIndex++;

            }

        }

    }else{

        piyoni--;

        if( (piyoni >= 0 && piyoni <= 7) && (piyonj >= 0 && piyonj <= 7) ){

                poz hrkt;
                hrkt.yatay = 8 - piyoni;
                hrkt.dusey = (char)(piyonj + 65);
                piyonunHareketleriArray[piyonunHareketleriArrayIndex] = hrkt;
                piyonunHareketleriArrayIndex++;

        }

    }

    return piyonunHareketleriArray;

}

int piyonHaraketSayisi(int piyoni,int piyonj){
    int haraketSayisi = 0;

    if(piyoni == 6){
        haraketSayisi = 2;
    }else if(piyoni == 0){
        haraketSayisi = 0;
    }else{
        haraketSayisi = 1;
    }

    return haraketSayisi;
}
