#ifndef matrix
#define matrix
#include <stdio.h>
#include <stdlib.h>

double **matrixAlocation(int dimension); // Function for the matrix allocation using a calloc and the input dimension

double **matrixDisallocation(int dimension, double **m); // Function to free the allocated space for the matrix

double matrixNorm(double **ma, double **mb, int dimension); // Calculates the matrix norm

void matrixMultiplication(double **ma, double **mb, double **resultm, int dimension); // Multiplicates the ma matrix and the mb matrix and stores the results on the resultm matrix

void matrixCopy(double **ma, double **mb, int dimension); // Copies the ma matrix to a mb matrix

double **constructMatrix(double **m, int dimension); // Function to construct the matrix from the input file

double **stochasticMatrix(double **m, double dampfac, int dimension); // Function that does the Stochastic Matrix, apllies the damping factor and calls the multiplication of matrix

void outputPrinter(double **m, int dimension); // Prints the output in the stdout

#endif
