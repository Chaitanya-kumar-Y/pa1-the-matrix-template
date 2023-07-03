#include <stdio.h>
#include <time.h>
#include <xmmintrin.h> // header for intrinsic functions
#include <x86intrin.h> // header for intrinsic functions

// dimensions of the matrices
#define MAX_DIM     2000
// block size for blocking matrix multiplication
#define BLOCK_SIZE	100

// function to generate random numbers
double fRand(double fMin, double fMax) {
	
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

// function to initialize a matrix with random values
void initialize_matrix(double *matrix, int rows, int cols) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i * cols + j] = fRand(0.0001, 1.000); // random values between 0 and 1
		}
	}
}

// function to perform normal matrix multiplication
void normal_mat_mul(double *A, double *B, double *C) {
	
	for (int i = 0; i < MAX_DIM; i++) {
		for (int j = 0; j < MAX_DIM; j++) {
			for (int k = 0; k < MAX_DIM; k++) {
				C[i * MAX_DIM + j] += A[i * MAX_DIM + k] * B[k * MAX_DIM + j];
			}
		}
	}
}

// function to perform blocking matrix multiplication
void blocking_mat_mul(double *A, double *B, double *C, int block_size) {

	
}

// function to perform matrix multiplication with software prefetching
void prefetch_mat_mul(double *A, double *B, double *C) {
	
	
}

// function to perform matrix multiplication with SIMD instructions
void simd_mat_mul(double *A, double *B, double *C) {

	
}

// NOTE: DO NOT CHANGE ANYTHING BELOW THIS LINE
// main function
int main() {

	// variables definition and initialization
	clock_t t_normal_mult, t_blocking_mult, t_prefetch_mult, t_simd_mult;
	double time_normal_mult, time_blocking_mult, time_prefetch_mult, time_simd_mult;

	double *A = (double *)malloc(MAX_DIM * MAX_DIM * sizeof(double));
	double *B = (double *)malloc(MAX_DIM * MAX_DIM * sizeof(double));
	double *C = (double *)calloc(MAX_DIM * MAX_DIM, sizeof(double));

	// initialize random seed
	srand(time(NULL));

	// initialize matrices A and B with random values
	initialize_matrix(A, MAX_DIM, MAX_DIM);
	initialize_matrix(B, MAX_DIM, MAX_DIM);

	// perform normal matrix multiplication
	t_normal_mult = clock();
	normal_mat_mul(A, B, C);
	t_normal_mult = clock() - t_normal_mult;

	time_normal_mult = ((double)t_normal_mult) / CLOCKS_PER_SEC; // in seconds
	printf("Normal matrix multiplication took %f seconds to execute \n\n", time_normal_mult);

	// perform blocking matrix multiplication
	t_blocking_mult = clock();
	blocking_mat_mul(A, B, C, BLOCK_SIZE);
	t_blocking_mult = clock() - t_blocking_mult;

	time_blocking_mult = ((double)t_blocking_mult) / CLOCKS_PER_SEC; // in seconds
	printf("Blocking matrix multiplication took %f seconds to execute \n", time_blocking_mult);
	printf("Gain in performance: %f \n\n", time_normal_mult / time_blocking_mult);

	// perform matrix multiplication with prefetching
	t_prefetch_mult = clock();
	prefetch_mat_mul(A, B, C);
	t_prefetch_mult = clock() - t_prefetch_mult;

	time_prefetch_mult = ((double)t_prefetch_mult) / CLOCKS_PER_SEC; // in seconds
	printf("Prefetching matrix multiplication took %f seconds to execute \n", time_prefetch_mult);
	printf("Gain in performance: %f \n\n", time_normal_mult / time_prefetch_mult);

	// perform matrix multiplication with SIMD instructions
	t_simd_mult = clock();
	simd_mat_mul(A, B, C);
	t_simd_mult = clock() - t_simd_mult;

	time_simd_mult = ((double)t_simd_mult) / CLOCKS_PER_SEC; // in seconds
	printf("SIMD matrix multiplication took %f seconds to execute \n", time_simd_mult);
	printf("Gain in performance: %f \n\n", time_normal_mult / time_simd_mult);

	// free allocated memory
	free(A);
	free(B);
	free(C);

	return 0;
}
