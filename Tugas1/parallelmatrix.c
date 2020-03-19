#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_SIZE 1000

int main () {
	int i, j ,k;
	int row = 1000, col = 1000; 
   	int *A = (int *)malloc(row * col * sizeof(int)); // Alokasi Dinamis Array Dua Dimensi Menggunakan Single Pointer
   	int *B = (int *)malloc(row * col * sizeof(int)); // Alokasi Dinamis Array Dua Dimensi Menggunakan Single Pointer
   	int *C = (int *)malloc(row * col * sizeof(int)); // Alokasi Dinamis Array Dua Dimensi Menggunakan Single Pointer
	long start, finish; // Clock
	double exec_time;
	
	
	// Membangkitkan Nilai Elemen untuk Matriks A dan Matriks B
	for(i=0;i<MATRIX_SIZE;i++){
		for(j=0;j<MATRIX_SIZE;j++){
   			*(A + i*col + j) = j*100;
   			*(B + i*col + j) = j*100;
		}
	}

	// Mengkalkulasi Perkalian Matriks
	start = clock(); // Mulai Clock Saat Kalkulasi
	#pragma omp parallel shared(A,B,C) private(i,j,k) 
	{
		#pragma omp for  schedule(static)
		for(i=0;i<MATRIX_SIZE;i++){
			for(j=0;j<MATRIX_SIZE;j++){
				*(C + i*col + j) = 0;
				for(k=0;k<MATRIX_SIZE;k++){
					*(C + i*col + j) += ((*(A + k*col + j))*(*(B + j*col + k)));
				}
			}
		}
	}
	finish = clock();
	
	// Mencetak Nilai Elemen Matriks C
//	for(i=0;i<MATRIX_SIZE;i++){
//		for(j=0;j<MATRIX_SIZE;j++){
//			printf("%d\n", 	*(C + i*col + j));
//		}
//	}

	exec_time = (double) (finish - start)/CLOCKS_PER_SEC;
	printf("exec_time %1f\n", exec_time);
	
	return 0;
}
