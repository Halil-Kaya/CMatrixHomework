#include <stdio.h>
#include "chessLib.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

int main(){


    poz ilk;
    ilk.dusey = 'D';
    ilk.yatay = 8;
    char tas = 'V';
    haraketYazdir(tas,ilk);
    while(1){
        printf("%stasi degistirmek icin c'e basiniz\n",KGRN);
        printf("%skordinatlari degistirmek icin k'ya basiniz\n",KYEL);
        printf("%sekrana bastirmak icin p'ye basiniz\n",KBLU);
        printf("%sCikmak icin x'e basiniz\n",KRED);
        char secim;
        scanf("%c",&secim);

        if(secim == 'c'){

            printf("%stas giriniz şah: S, vezir: V, fil: F, at: A, kale: K\n",KGRN);
            scanf(" %c",&tas);
            printf("degismis tas = %c\n",tas);


        }else if(secim == 'k'){

            printf("%sdusey kismini giriniz (A ,B ,C ,D ,E ,F ,G ,H)\n",KYEL);
            scanf(" %c",&ilk.dusey);

            int yatayKordinat = ilk.yatay;
            printf("yatay kismini giriniz (1 dan 8 e kadar)\n");
            scanf("%d",&yatayKordinat);
            ilk.yatay = yatayKordinat;

        }else if(secim == 'p'){

            printf("\n\n");
            haraketYazdir(tas,ilk);
            printf("\n\n");

        }else if(secim == 'x'){
            
            printf("tekrar bekleriz!\n");
            break;

        }


        haraketYazdir(tas,ilk);
    }

    return 0;
}