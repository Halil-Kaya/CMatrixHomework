#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "matrixOps.h"

/**
* main.c
* sistem main uzerinden calisiyor.
* 1.odev
* 02/12/2019 Kodu oluşturduğunuz Tarih
* Halil ibrahim Kaya   halilibrahim.kaya@stu.fsm.edu.tr
*/


int main(int argc, char *argv[]){

    if(argc<6||argc>6){
        parametreUyarisi();
        return 0;
    }
    

    if(sayiMiKontrol((char*)argv[1])==0){
        printf("\nsatiri sayi olarak giriniz!\n");
        return 0;
    }else if(sayiMiKontrol((char*)argv[2])==0){
        printf("\nsutunu sayi olarak giriniz!\n");
        return 0;
    }else if(sayiMiKontrol((char*)argv[3])==0){
        printf("\nyonu sayı olarak giriniz!\n");
        return 0;
    }else if(sayiMiKontrol((char*)argv[4])==0){
        printf("\naraligi sayi olarak giriniz!\n");
        return 0;
    }else if(sayiMiKontrol((char*)argv[5])==0){
        printf("\nkac tur atacagini sayi olarak giriniz!\n");
        return 0;
    }




    int satir=atoi(argv[1]);
    int sutun=atoi(argv[2]);
    int yon=atoi(argv[3]);
    int aralik=atoi(argv[4]);
    int kacTur=atoi(argv[5]);

    


    if(satir<=0||sutun<=0){
        parametreUyarisi();
        printf("satir veya sütün hatali girildi programdan cikiliyor...\n");
        return 0;
    }else if(!(yon==1||yon==-1)){
        parametreUyarisi();
        printf("yon hatali girildi programdan cikiliyor\n");
        return 0;
    }else if(aralik<=0){
        parametreUyarisi();
        printf("aralik hatali girildi programdan cikiliyor...\n");
        return 0;
    }else if(kacTur<0){
        parametreUyarisi();
        printf("tur sayisi hatali girildi programdan cikiliyor...\n");
        return 0;
    }

    int **dizi;


    dizi=matrixOlustur(dizi,satir,sutun,aralik);
    
    int kontrol2=1;
    int kontrol3=1;
    int kontrol4=1;

    int secenek=1;
    char *sayiMi=malloc(100*sizeof(char));
       
    
    while(1){
        

        if(secenek==1){
            if(kontrol2==1&&kontrol3==1&&kontrol4==1){
                
                printf("\nsatir: %d",satir);
                printf(" sutun: %d",sutun);
                printf(" yon: %d",yon);
                printf(" aralik: %d",aralik);
                printf(" kactur: %d\n",kacTur);

                printf("onceki hali: \n");
                ekranaBas(dizi,satir,sutun);
                dondur(dizi,satir,sutun,yon,kacTur);
                printf("simdiki hali: \n");
                ekranaBas(dizi,satir,sutun);

            }else
            {
                if(kontrol2==0){
                    printf("matrix hatali 2'ye basarak matrixi duzgun olusturunuz.\n");
                }else if(kontrol3==0){
                    printf("yonu yanlis girdiniz 3'e basarak yonu tekrar giriniz.\n");
                }else if(kontrol4==0){
                    printf("adim sayisini yanlis girdiniz 4'e basarak adim sayisini tekrar giriniz.\n");
                }
            }
            
            

        }else if(secenek==2){
            printf("\nyeni satir sayisini giriniz: ");
            gets(sayiMi);
            if(sayiMiKontrol(sayiMi)==1){
                satir=atoi(sayiMi);
            }else{
                printf("\n sayi girmediniz satiri sayi girin\n");
                secenek=0;
                continue;
            }
            
            printf("\nyeni sutun sayisini giriniz: ");
            gets(sayiMi);
            if(sayiMiKontrol(sayiMi)==1){
                sutun=atoi(sayiMi);
            }else{
                printf("\n sayi girmediniz sutunu sayi girin\n");
                secenek=0;
                kontrol2=0;
                continue;
            }

            printf("\naraligi giriniz: ");
            gets(sayiMi);
            if(sayiMiKontrol(sayiMi)==1){
                aralik=atoi(sayiMi);
            }else{
                printf("\n sayi girmediniz araligi sayi girin\n");
                secenek=0;
                kontrol2=0;
                continue;
            }


            if(matrixOlusturmaKontrol(satir,sutun,aralik)==0){
                printf("degerler hatali tekrar deneyiniz...");
                kontrol2=0;
            }else{
                
                dizi=matrixOlustur(dizi,satir,sutun,aralik);
                ekranaBas(dizi,satir,sutun);
                kontrol2=1;
            }

        }else if(secenek==3){
            printf("\nyeni yonu giriniz: ");
            gets(sayiMi);
            if(sayiMiKontrol(sayiMi)==1){
                yon=atoi(sayiMi);
            }else{
                printf("\n sayi girmediniz yonu sayi girin\n");
                secenek=0;
                continue;
            }


            if(!(yon==1||yon==-1)){
                printf("deger hatali tekrar deneyiniz.");
                kontrol3=0;
            }else{
                kontrol3=1;
            }


        }else if(secenek==4){
            printf("step sayisini giriniz: ");
            gets(sayiMi);
            if(sayiMiKontrol(sayiMi)==1){
                kacTur=atoi(sayiMi);
            }else{
                printf("\n sayi girmediniz kactur donecegini sayi girin\n");
                secenek=0;
                continue;
            }


            if(kacTur<0){
                printf("gecersiz deger girdiniz tekrar deneyiniz.");
                kontrol4=0;
            }else
            {
                kontrol4=1;
            }

        }else if(secenek==5){
            printf("\nprogramdan cikiloyor umarim hosunuza gitmistir :).\n");
            free(dizi);
            free(sayiMi);
            return 0;
        }else{
            printf("\ngecersiz bir deger girdiniz...\n");
        }

        printf("\n1- Uygulamayi Calistir.\n");
        printf("2- Matrix Olustur.\n");
        printf("3- Direction.\n");
        printf("4-Step number.\n");
        printf("5-Exit.\n");
        gets(sayiMi);

        if(sayiMiKontrol(sayiMi)==1){
            secenek=atoi(sayiMi);
        }else{
            printf("\n sayi girmediniz secenegi sayi girin\n");
            secenek=0;
            continue;
        }
        
        

    }


    




    return 0;
}