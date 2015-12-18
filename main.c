#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h" // TAD

void matrixCalculation(double **ma, double **mb, double **resultm, int dim, double *norm, int count) // Calculates the matrix
{

	if(count == 0) // First time that happens the multiplication
		matrixCopy(ma, mb, dim); // Copies the ma matrix to the mb matrix

	matrixMultiplication(ma, mb, resultm, dim); // Multiplies the ma matrix by the mb matrix and saves in a resultm matrix

	*norm = matrixNorm(resultm, mb, dim); // Calculates the norm of the resultm matrix - mb matrix
  
	matrixCopy(resultm, mb, dim); // Copies the resultm matrix to the mb matrix
}

int main(int argc, char *argv[]) // Main function
{
	int dim; // Matrix dimension
	int count; // Multiplication counter
	double dampfac; // Damping Factor
	double norm = 1;// Norms of the matrix and equals to one just to be sure that it won't get a memory trash
	double **ma, **mb, **resultm; // Matrixes of the program
	
	scanf("%d %lf", &dim, &dampfac);

	ma = matrixAlocation(dim);
	mb = matrixAlocation(dim);
	resultm = matrixAlocation(dim);

	ma = constructMatrix(ma, dim);
	ma = stochasticMatrix(ma, dampfac, dim);

	for(count = 0; count <= 2000 && norm > pow(10, -12); count++) // Tests the convergent stop condition
		matrixCalculation(ma, mb, resultm, dim, &norm, count);

	outputPrinter(mb, dim);

	ma = matrixDisallocation(dim, ma);
	mb = matrixDisallocation(dim, mb);
	resultm = matrixDisallocation(dim, resultm);

	return (0);
}
