#include <stdio.h>
#include <stdlib.h>
#include "compress.h"
#define satir 5
#define sutun 5

int main(int argc,char **argv) {

	int **A = matrixOlustur(satir, sutun);
	printf("matrixin hali:\n\n");
	ekranaBastirMatrix(satir, sutun, A);


	int sifirOlmayanAdet = sifirOlmayanlariSay(A);

	int *nz = (int*)malloc(satir*sutun*sizeof(int));
	int *rows = (int*)malloc(satir*sutun*sizeof(int));
	int *cols = (int*)malloc(satir*sutun*sizeof(int));
	
	compress_IJ(A,nz,rows,cols,satir,sutun);
	printf("compress_IJ fonksiyonuyla sikistirilmis hali:\n\n");
	ekranaBastirDizi(sifirOlmayanAdet,nz);

	A = decompress_IJ(nz,rows,cols,satir,sutun);
	printf("decompress_IJ fonksiyonuyla acilmis hali:\n\n");
	ekranaBastirMatrix(satir,sutun,A);

	int *col_ind = (int*)malloc(satir*sutun*sizeof(int));
	int *row_ptr = (int*)malloc(satir*sutun*sizeof(int));

	compress_CRS(A,nz,col_ind,row_ptr,satir,sutun);
	printf("compress_CRS fonksiyonuyla sikistirilmis hali:\n\n");
	ekranaBastirDizi(sifirOlmayanAdet,nz);

	A = decompress_CRS(nz,col_ind,row_ptr,satir,sutun);
	printf("decompress_CRS fonksiyonuyla acilmis hali:\n\n");
	ekranaBastirMatrix(satir,sutun,A);

	int *row_ind = (int*)malloc(satir*sutun*sizeof(int));
	int *col_ptr = (int*)malloc(satir*sutun*sizeof(int));

	compress_CCS(A,nz,row_ind,col_ptr,satir,sutun);
	printf("compress_CCS fonksiyonuyla sikistirilmis hali:\n\n");
	ekranaBastirDizi(sifirOlmayanAdet,nz);

	A = decompress_CCS(nz,row_ind,col_ptr,satir,sutun);
	printf("decompress_CCS fonksiyonuyla acilmis hali:\n\n");
	ekranaBastirMatrix(satir,sutun,A);








	return 0;
}

int sifirOlmayanlariSay(int **dizi){

	int adet = 0;
	for (int i = 0; i < satir; i++) {

		for (int j = 0; j < sutun; j++) {

			if ( *(*(dizi + i) + j ) != 0 ) { 

				adet++; 
			}

		}

	}
	return adet;
}
