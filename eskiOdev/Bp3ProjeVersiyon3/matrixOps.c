#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include "matrixOps.h"


/**
* matrixOps.c
* mainde calicasak fonksiyonlarim burada.
* 1.odev
* 02/12/2019 Kodu oluşturduğunuz Tarih
* Halil ibrahim Kaya   halilibrahim.kaya@stu.fsm.edu.tr
*/


void dondur(int** dizi,int satir,int sutun,int yon,int kacTur){

    //x^2-(x-2)^2-1
    
    /*benim algoritma bolgeye gore çalişiyor

        2 3 4
        4 5 6
        7 8 9 
        
        matrixi olsun bu matrixin bolgesi sole

         +ust+
        +2 3 4 +
     sol 4 5 6 sag
        +7 8 9 +
         +alt+

        sonraki işlem ise şu eger ki sola dogru çevirmek istersem 0-0 daki adresi saga 
        dogru yer degiştirtiyorum
        or:
        2 3 4     3 2 4      3 4 2
        4 5 6 --> 4 5 6 -->> 4 5 6
        7 8 9     7 8 9      7 8 9

        artik sag bolgeye geldik o if' e girerek o kismi yer degistirtiyor

        3 4 2     3 4 6      3 4 6
        4 5 6 --> 4 5 2 -->> 4 5 9
        7 8 9     7 8 9      7 8 2
        
        artik alt bolgedeyiz yani alt bolgeyi aktif ederek ordaki if calisiyor

        3 4 6     3 4 6      3 4 6
        4 5 9 --> 4 5 9 -->> 4 5 9
        7 8 2     7 2 8      2 7 8
        
        son bolge olarak da sag bolgeye geciyor sag=1 yani aktif
    
        3 4 6     3 4 6 
        4 5 9 --> 2 5 9  --->> boylece matrixi sola dondurmus olduk
        2 7 8     4 7 8 

        eger saga dondurmek isteseydik islem bu sefer sola dogru ilerleyecekti yani tam tersi

        bu islemi ise 7 defa yapıyoruz
        2x2 luk matrixte -->> 3 defa
        3x3 luk matrixte -->> 7 defa
        4x4 luk matrixte -->> 11 defa
        
        bunun formulu ise f(x)=x^2-(x-2)^2-1
        bu formule gore kac defa islem yapmam geregtigini hesaplayabiliyorum 
        or:
        
        3x3 
        f(x)=x^2-(x-2)^2-1 -->>> f(3)=3^2-(3-2)^2-1 --->>> 7 
        
        4x4
        f(x)=x^2-(x-2)^2-1 -->>> f(4)=4^2-(4-2)^2-1 --->>> 11 
        

        eger sekil kare degilde dikdortgen olursa da
        oncelikle en kisa kenarin uzunluguna gore hesapliyorum
        or:
        4x7 lik bi matrix te en kisa 4 oldugu icin 4'e gore hesapliyorum
        f(x)=x^2-(x-2)^2-1 -->>> f(4)=4^2-(4-2)^2-1 --->>> 11 
        ondan sonra kenarlarin arasindaki farki buluyorum |4-7|=3
        bu 3 sayisini 2 ile carpiyorum >> 6
        formulden cikan cevap 11 di bunla toplayinca >> 11+6 >>17
        yani 17 defa islem yapmasi gerekiyor

        iste algoritmam boyle calisiyor :)
    */



    int islemSayisi=0;//kac defa islem yapmam gerektigini tutan degisken
    
    //f(x)=x^2-(x-2)^2-1
    
    if(satir==sutun){
        islemSayisi= sutun*sutun-(sutun-2)*(sutun-2)-1;//eger kareyse degiskenin degeri boyle kaliyor 
    }else if(satir>sutun){
        islemSayisi= sutun*sutun-(sutun-2)*(sutun-2)-1;   // sutun kucukse hesaplamam
        islemSayisi+=2*(satir-sutun);
    }else if(satir<sutun){
        islemSayisi= satir*satir-(satir-2)*(satir-2)-1; //satir kucukse hesaplamam
        islemSayisi+=2*(sutun-satir);
    }


    int ust=1,sol=0,sag=0,asagi=0;//bolgelerim eger aktif ise 1 degilse 0
    int asagiSinir=1; //en asagida j'nin kordinati 1 ise asagiyi pasif ediyor ve sol bolgeyi aktif ediyor
    int ustSinir=sutun-2; //ust sinir sagdan 2 gerideki kordinatta sinir
    int sagSinir=satir-2;
    int solSinir=1;

    if(yon==1){//eger saga donecekse kontrollerim daha farklı oluyor bu sefer soldan saga gore degerler
        ust=0,sol=1,sag=0,asagi=0;
        asagiSinir=satir-2;
        ustSinir=1;
        sagSinir=1;
        solSinir=sutun-2;
    }
    int temp=0;
    int i=0,j=0;

    int k=0;

    for(k=0;k<islemSayisi*kacTur;k++){//eger 2 tur atmasini isterse islem sayisini tur sayisi ile carpiyorum
    
    
        if(ust==1){
            if(j==ustSinir){//eger ki ust kisimda giderken sinira geldiyse buraya giriyor
                ust=0;//sinira geldigi icin ust kismi sifir yapiyorum boylece artik ust kisimda islem yapmiyacak
                if(yon==1){//eger yon 1 ise yani saga gore ise sol kismi aktif ediyorum
                sol=1;
                }else{//degilse sag kismi aktif ediyorum
                sag=1;
                }
            }
            //yanindaki deger ile yer degistiriyor
            temp=*(*(dizi+i)+j);;
            *(*(dizi+i)+j)=*(*(dizi+i)+(j-yon));//eger yon 1 ise yani sag ise solla yer degistiriyor eger sol ise sag ile yer degistiriyor
            *(*(dizi+i)+(j-yon))=temp;
            //-----------------------------------

            j=j-yon;//eger yon 1 ise bir azaltiyor -1 ise bir artiriyor
       
        }else if(sag==1){//sag bolge aktif
            if(i==sagSinir){//sag sinira gelirse burdaki kontrole geliyor ve yer degistiriyor
                sag=0;
                if(yon==1){//eger yon sag ise
                ust=1;//ust kismi aktif ediyor
                }else{
                asagi=1;//degilse asagi
                }   
            }
            //yanindaki deger ile yer degistiriyor
            temp=*(*(dizi+i)+j);
            *(*(dizi+i)+j)=*(*(dizi+(i-yon))+j);
            *(*(dizi+(i-yon))+j)=temp;
            i=i-yon;
        //diger kisimlara da ayni sekilde kontrol ediyor ve islem yapiyor
        }else if(sol==1){
            if(i==asagiSinir){
                sol=0;
                if(yon==1){
                asagi=1;
                }else{
                ust=1;
                }
            }
            temp=*(*(dizi+i)+j);
            *(*(dizi+i)+j)=*(*(dizi+(i+yon))+j);
            *(*(dizi+(i+yon))+j)=temp;
            i=i+yon;
      
        }else if(asagi==1){
            if(j==solSinir){
                asagi=0;
                if(yon==1){
                sag=1;
                }else{
                sol=1;
                }           
            }
            temp=*(*(dizi+i)+j);
            *(*(dizi+i)+j)=*(*(dizi+i)+(j+yon));
            *(*(dizi+i)+(j+yon))=temp;
            j=j+yon;

        }
    }
}



//diziyi donerek ekrana basiyor
void ekranaBas(int** dizi,int satir,int sutun){
    int i=0;
    int j=0;
    for(i=0;i<satir;i++){
        for(j=0;j<sutun;j++){
            printf("%d ",*(*(dizi+i)+j));
        }
        printf("\n");
    }
    printf("\n-------------------------------------\n");
}





int** matrixOlustur(int** dizi,int satir,int sutun,int aralik){
    dizi=(int**)malloc(satir*sizeof(int*));//girilen satir degeri kadar hafizada yer olusturuyor
    int i=0;
    int j=0;

    for(i=0;i<satir;i++){
        *(dizi+i)=(int*)malloc(sutun*sizeof(int));//satir kadar hafizada yer ayarliyor
    }

    srand (( unsigned ) time (NULL) ); //random sayı uretiyor
    rand()%aralik;

    for(i=0;i<satir;i++){
        for(j=0;j<sutun;j++){
            *(*(dizi+i)+j)=rand()%aralik; // diziyi donerek icerisine aralik kadar random sayi atiyor
        }
    }
    return dizi;//sonunda olusan diziyi donduruyor
}

void parametreUyarisi(){
    printf("fazla veya eksik parametre girdiniz 1.: satir 2.: sutun 3.: yon 4.: aralik 5.'i parametre ise kactur donecegidir.\n");
}


int sayiMiKontrol(char *h){
    //sayi mi kontrol soyle calisiyor oncelikle kullanicidan alinan input string olarak aliniyor
    //sonra bu string kontrol ediliyor bu bir sayi mi diye eger sayiysa 1 degilse 0 donuyor
    int len=0;
    while(*(h+len)!='\0'){
        len++;//stringin uzunlugunu buluyor
    }

    if(len==2){
        if(*(h)=='-'&&sayiMiKontrol((h+1))==1){
            //eger dizinin uzunlugu 2 y se ve basindaki string '-' ise ondan sonraki kismini fonksiyona
            //sokup kontrol ediyor sayi mi diye 
            //sayiysa 1 donuyor
            return 1;
        }
    }

    int kontrol=1;
    int i=0;
    for(i=0;i<len;i++){
       
        if(((int)(*(h+i)))<=57&&((int)(*(h+i)))>=48){//ascii koduna gore eger sayiysa bi islem yapmiyor
           
        }else{//degilse kontrolu 0 a esitleyerek return 0 donmesini sagliyor yani sayi degil
            kontrol=0;
        }
    }
    return kontrol;
}




int matrixOlusturmaKontrol(int satir,int sutun,int aralik){

    if(satir<=0||sutun<=0||aralik<=0){
        return 0;
    }

    return 1;
}


