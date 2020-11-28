/*
 * compress.c
 *
 *  Created on: 15 Kas 2020
 *      Author: X550V
 */

#include <stdio.h>
#include <stdlib.h>
#include "compress.h"
#include <time.h>

void compress_CRS(int **A, int *nz, int *col_ind, int *row_ptr, int N, int M) {
	int count = 0, count2 = 0;
	int rowCheck = 1;
	// Creating nz, col_ind and row_ptr
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] != 0) { // E�er matrisin gelen eleman� 0' dan farkl� ise nz'ye ekliyoruz.
				nz[count] = (int) A[i][j]; // creating nz
				col_ind[count] = j;             // creating col_ind
				if (rowCheck == 1) { // Sat�r�n 0'dan farkl� ilk eleman� ise row_ptr'ye
					row_ptr[count2] = count; // ekliyoruz ve sat�r de�i�ene kadar buraya girmiyoruz.
					count2++;
					rowCheck = 0;
				}
				count++;
			}
		}
		rowCheck = 1;
	}
	row_ptr[count2] = count;              //row_ptr nin son eleman�n� ekliyoruz.
}

int** decompress_CRS(int *nz, int *col_ind, int *row_ptr, int N, int M) {
	int **A = createMatrix(N, M); // D�nd�rece�imiz matrisimiz i�in bellekte yer a��yoruz.
	int count = 0, count2 = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (col_ind[count] == j) { // col_ind deki b�t�n de�erleri s�tunlar�m�zla kar��la�t�r�yoruz
				if (count != row_ptr[count2]) { // e�er e�it ��karsa row_ptr de bulunanan ilk sat�r elemanlar� i�in bir kontrol yap�yoruz
					A[i][j] = (int) nz[count]; // bu kontrolleri ge�en yerlere nz deki elemanlar� ge�emeyen yerlerede 0 lar� yerle�tiriyoruz.
					count++;
				} else {
					A[i][j] = 0;
				}
			} else {
				A[i][j] = 0;
			}
		}
		count2++;
	}
	return A;
}

void compress_CCS(int **A, int *nz, int *row_ind, int *col_ptr, int N, int M) {
	int count = 0, count2 = 0;
	int colCheck = 1;
	// Creating nz, col_ind and row_ptr
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[j][i] != 0) { // E�er matrisin gelen eleman� 0' dan farkl� ise nz'ye ekliyoruz.
				nz[count] = (int) A[j][i]; // Ancak burada CRS'den farkl� olarak ilkten s�tundaki say�lar� al�yoruz, creating nz
				row_ind[count] = j;             // creating row_ind
				if (colCheck == 1) { // S�tunun 0'dan farkl� ilk eleman� ise col_ptr'ye
					col_ptr[count2] = count; // ekliyoruz ve s�tun de�i�ene kadar buraya girmiyoruz.
					count2++;
					colCheck = 0;
				}
				count++;
			}
		}
		colCheck = 1;
	}
	col_ptr[count2] = count;

}

int** decompress_CCS(int *nz, int *row_ind, int *col_ptr, int N, int M) {
	int **A = createMatrix(N, M); // D�nd�rece�imiz matrisimiz i�in bellekte yer a��yoruz.
	int count = 0, count2 = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (row_ind[count] == j) { // col_ind deki b�t�n de�erleri s�tunlar�m�zla kar��la�t�r�yoruz
				if (count != col_ptr[count2]) { // e�er e�it ��karsa row_ptr de bulunanan ilk sat�r elemanlar� i�in bir kontrol yap�yoruz
					A[j][i] = (int) nz[count]; // bu kontrolleri ge�en yerlere nz deki elemanlar� ge�emeyen yerlerede 0 lar� yerle�tiriyoruz.
					count++;
				} else {
					A[j][i] = 0;
				}
			} else {
				A[j][i] = 0;
			}
		}
		count2++;
	}
	return A;
}

void compress_IJ(int **A, int *nz, int *rows, int *cols, int N, int M) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] != 0) { // If the element of this index different than 0.
				nz[count] = (int) A[i][j]; // Then we add it to the nz list.
				rows[count] = i; // Adding row index to given rows list.
				cols[count] = j; // Adding column index to the given cols list.
				count++;  //and we increase count.
			}
		}
	}
}

int** decompress_IJ(int *nz, int *rows, int *cols, int N, int M) {
	int **A = createMatrix(N, M); // We create the matrix that we return.
	int counter = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (rows[counter] == i && cols[counter] == j) { // If the value of rows is equals to i
				                                            // and the value of cols is equals to j
				                                            // it means that the place we need to put to value in nz.
				A[i][j] = nz[counter];                      // We put the value.
				counter++;                                  // and we increase the counter.
			}
			else{
				A[i][j] = 0;                                // else there is no value to put except 0, We put zero.
			}
		}
	}
	return A;
}

int** createMatrix(int n, int m) {
	int **M;
	M = (int**) calloc(n, sizeof(int*));
	for (int i = 0; i < m; i++) {
		M[i] = (int*) calloc(m, sizeof(int));
	}
	srand(time(0));
	int count = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			count++;
			if ((count + i + j + rand() % 3) % rand() % 5 == 0
					|| ((count + i + j + rand() % 3) % rand() % 4) == 0) { // matrisimize daha �ok random
				M[i][j] = 0;                                               // 0 eklemek i�in b�yle bir �ey yazd�m.
			} else {
				M[i][j] = rand() % 10 + 1; // matrisimizi random int ler ile dolduruyoruz.
			}
		}
	return M;
}
void printMatrix(int n, int m, int **M) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d   ", M[i][j]);
		}
		puts("");
	}
	puts("-----------");
}

