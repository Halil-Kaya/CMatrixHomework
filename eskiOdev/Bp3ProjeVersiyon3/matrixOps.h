#ifndef matrixOps
#define matrixOps


/**
* matrixOps.h
* matrixOps.c 'nin kutuphanesi
* 1.odev
* 02/12/2019 Kodu oluşturduğunuz Tarih
* Halil ibrahim Kaya   halilibrahim.kaya@stu.fsm.edu.tr
*/


//parametre uyarisi veriyor
void parametreUyarisi();


//girilen satir,sutun ve araligin dogru olup olmadigini kontrol ediyor
int matrixOlusturmaKontrol(int satir,int sutun,int aralik);


//girilen degerlere gore matrix olusturuyor
int** matrixOlustur(int** dizi,int satir,int sutun,int aralik);

//matrisi girilen yon ve tura gore istenilen yore donduruyor
void dondur(int** dizi,int satir,int sutun,int yon,int kacTur);

//girilen inputun sayi olup olmadigini kontrol ediyor eger sayiysa 1 degilse 0 donuyor
int sayiMiKontrol(char *h);

//diziyi ekrana basıyor
void ekranaBas(int** dizi,int satir,int sutun);

#endif