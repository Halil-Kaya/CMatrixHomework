#ifndef COMPRESS_H_
#define COMPRESS_H_

int **matrixOlustur(int, int);

void ekranaBastirMatrix(int, int, int**);

void ekranaBastirDizi(int,int*);

void compress_IJ(int **dizi, int *nz, int *rows, int *cols, int satir, int sutun);

int **decompress_IJ(int *nz, int *rows, int *cols, int satir, int sutun);

void compress_CRS(int **dizi, int *nz, int *col_ind, int *row_ptr, int satir, int sutun);

int **decompress_CRS(int *nz, int *col_ind, int *row_ptr, int satir, int sutun);

void compress_CCS(int **dizi, int *nz, int *row_ind, int *col_ptr, int satir, int sutun);

int **decompress_CCS(int *nz, int *row_ind, int *col_ptr, int satir, int sutun);

#endif

