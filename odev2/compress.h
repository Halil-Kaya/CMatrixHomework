/*
 * compress.h
 *
 *  Created on: 15 Kas 2020
 *      Author: X550V
 */

#ifndef COMPRESS_H_
#define COMPRESS_H_

void compress_IJ(int **A, int *nz, int *rows, int *cols, int N, int M);
int **decompress_IJ(int *nz, int *rows, int *cols, int N, int M);
void compress_CRS(int **A, int *nz, int *col_ind, int *row_ptr, int N, int M);
int **decompress_CRS(int *nz, int *col_ind, int *row_ptr, int N, int M);
void compress_CCS(int **A, int *nz, int *row_ind, int *col_ptr, int N, int M);
int **decompress_CCS(int *nz, int *row_ind, int *col_ptr, int N, int M);
int **createMatrix(int, int);
void printMatrix(int, int, int**);
#endif /* COMPRESS_H_ */
