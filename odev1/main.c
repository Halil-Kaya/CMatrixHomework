#include<stdio.h>
#include<stdlib.h>
#include <time.h>

float** matrixMatrixMultiply(float** matrix1,float** matrix2);
float** matrixOlustur();
void ekranaBas(float** dizi);

int boyut = 0;

int main(){

    boyut = 2;

    float **matrix1;
    matrix1 = matrixOlustur();
    printf("\n\tmatrix1\t\n");
    ekranaBas(matrix1);

    float **matrix2;
    matrix2 = matrixOlustur();
    printf("\n\tmatrix2\t\n");
    ekranaBas(matrix2);


    float** sonuc;
    sonuc = matrixMatrixMultiply(matrix1,matrix2);
    
    printf("\n\tsonuc\t\n");
    ekranaBas(sonuc);

    return 0;
}

float** matrixMatrixMultiply(float** matrix1,float** matrix2){
    float **sonuc;
    sonuc=(float**)malloc(boyut*sizeof(float*));//girilen satir degeri kadar hafizada yer olusturuyor
    int i=0;
    int j=0;
    int k=0;

    for(i=0;i<boyut;i++){
        *(sonuc+i)=(float*)malloc(boyut*sizeof(float));//satir kadar hafizada yer ayarliyor
    }
    

    for(i=0;i<boyut;i++){
        for(j=0;j<boyut;j++){
            for(k = 0;k < boyut;k++){
                *(*(sonuc+i)+j) += ( *(*(matrix1+i)+k) )  *  ( *(*(matrix2+k)+j) ); // diziyi donerek icerisine aralik kadar random sayi atiyor
            }
        }
    }


    return sonuc;
}


//diziyi donerek ekrana basiyor
void ekranaBas(float** dizi){
    int i=0;
    int j=0;
    for(i=0;i<boyut;i++){
        for(j=0;j<boyut;j++){
            printf("%f ",*(*(dizi+i)+j));
        }
        printf("\n");
    }
    printf("\n-------------------------------------\n");
}

float** matrixOlustur(){
    float** dizi;
    dizi=(float**)malloc(boyut*sizeof(float*));//girilen satir degeri kadar hafizada yer olusturuyor
    int i=0;
    int j=0;

    for(i=0;i<boyut;i++){
        *(dizi+i)=(float*)malloc(boyut*sizeof(float));//satir kadar hafizada yer ayarliyor
    }

    srand (( unsigned ) time (NULL) ); //random sayı uretiyor

    for(i=0;i<boyut;i++){
        for(j=0;j<boyut;j++){
            *(*(dizi+i)+j)=((float)rand()/(float)(RAND_MAX) * 1000); // diziyi donerek icerisine aralik kadar random sayi atiyor
        }
    }
    return dizi;//sonunda olusan diziyi donduruyor
}