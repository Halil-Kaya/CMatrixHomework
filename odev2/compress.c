#include <stdio.h>
#include <stdlib.h>
#include "compress.h"
#include <time.h>

int** matrixOlustur(int satir, int sutun){

    int** dizi;
    dizi=(int**)malloc(satir*sizeof(int*));
    int i=0;
    int j=0;

    for(i=0;i<satir;i++){
        *(dizi+i)=(int*)malloc(sutun*sizeof(int));
    }

    srand (( unsigned ) time (NULL) ); 

    for(i=0;i<satir;i++){

        for(j=0;j<sutun;j++){

            *(*(dizi+i)+j)= rand() % 10 ;

		}

    }

	for(int i = 0 ; i < satir*sutun-satir-sutun ; i++){
		*(*(dizi + rand() % satir )+ rand() % sutun) = 0;
	}


    return dizi;
}

void ekranaBastirDizi(int boyut,int *dizi){

	for(int i = 0; i < boyut ;i++){
		printf("%d ", *(dizi + i) );
	} 

	printf("\n---------------------------------------\n");

}

void ekranaBastirMatrix(int satir, int sutun, int **dizi) {

	for (int i = 0; i < satir; i++) {

		for (int j = 0; j < sutun; j++) {

			printf("%d ", *(*(dizi + i) + j ));

		}

		printf("\n");

	}

	printf("---------------------------------------\n");
}



void compress_CRS(int **dizi, int *nz, int *col_ind, int *row_ptr, int satir, int sutun) {


	int satirKontrol = 1;
	int index1 = 0;
	int index2 = 0;

	for (int i = 0; i < satir; i++) {
		
		for (int j = 0; j < satir; j++) {
		
			if (*(*(dizi + i) + j) != 0) { 
		
				*(nz + index1) = *(*(dizi + i) + j); 
				*(col_ind + index1) = j;             
		
				if (satirKontrol == 1) { 
		
					*(row_ptr + index2) = index1;
					satirKontrol = 0;
					index2++;
		
				}
		
				index1++;
		
			}
		
		}

		satirKontrol = 1;

	}

	*(row_ptr + index2) = index1;

}

int** decompress_CRS(int *nz, int *col_ind, int *row_ptr, int satir, int sutun) {
	
	int **dizi = matrixOlustur(satir, sutun);
	int index1 = 0;
	int index2 = 1;
	
	for (int i = 0; i < satir; i++) {
	
		for (int j = 0; j < sutun; j++) {
	
			if ( *(col_ind + index1) == j ) { 
	
				if (index1 != *(row_ptr + index2)) { 
	
					*(*(dizi + i) + j ) = *(nz + index1);
					index1++;
	
				} else {
	
					*(*(dizi + i) + j ) = 0;
	
				}
			} else {
	
				*(*(dizi + i) + j ) = 0;
			}
		}
	
		index2++;
	
	}
	
	return dizi;
}

void compress_CCS(int **dizi, int *nz, int *row_ind, int *col_ptr, int satir, int sutun) {

	int sutunKontrol = 1;
	int index1 = 0;
	int index2 = 0;

	for (int i = 0; i < satir; i++) {

		for (int j = 0; j < sutun; j++) {

			if (*(*(dizi + i) + j ) != 0) { 

				*(nz + index1) = *(*(dizi + i) + j); 
				*(row_ind + index1) = j;  

				if (sutunKontrol == 1) { 

					*(col_ptr + index2) = index1;
					index2++;
					sutunKontrol = 0;

				}

				index1++;

			}

		}

		sutunKontrol = 1;
	}

	*(col_ptr + index2) = index1;

}

int** decompress_CCS(int *nz, int *row_ind, int *col_ptr, int satir, int sutun) {

	int **dizi = matrixOlustur(satir, sutun); 
	int index1 = 0;
	int index2 = 1;

	for (int i = 0; i < satir; i++) {

		for (int j = 0; j < sutun; j++) {

			if (*(row_ind + index1) == j) { 

				if (index1 == *(col_ptr + index2)) {
					
					*(*(dizi + i) + j ) = 0;

				} else {

					*(*(dizi + i) + j ) = *(nz + index1); 
					index1++;					

				}

			} else {

				*(*(dizi + i) + j ) = 0;

			}
		}

		index2++;

	}

	return dizi;
}

void compress_IJ(int **dizi, int *nz, int *rows, int *cols, int satir, int sutun) {

	int index = 0;
	for (int i = 0; i < satir; i++) {

		for (int j = 0; j < sutun; j++) {

			if ( *(*(dizi + i) + j ) != 0 ) { 

				*(nz + index) = *(*(dizi + i) + j); 
				*(rows + index) = i; 
				*(cols + index) = j; 
				index++; 
			}

		}

	}
}

int** decompress_IJ(int *nz, int *rows, int *cols, int satir, int sutun) {

	int **dizi = matrixOlustur(satir, sutun); 
	int sayac = 0;
	for (int i = 0; i < satir; i++) {

		for (int j = 0; j < sutun; j++) {

			if (*(rows + sayac) == i && *(cols + sayac) == j) {
				                                           
				*(*(dizi + i) + j ) = *(nz + sayac);                     
				sayac++;                                  

			}
			else{

				*(*(dizi + i) + j ) = 0;                              

			}
		}
	}

	return dizi;

}

