#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double **matrixAlocation(int dimension) // Function for the matrix allocation using a calloc and the input dimension
{
	double **m;
	int i; // Counter

	if(dimension < 1)
	{
		printf("Error : Invalid dimensionension of the matrix.\n");
		return (NULL);
	}

	m = (double**) calloc (dimension, sizeof(double));
		if(m == NULL)
		{
			printf("Error : Insuficient memory to allocate the matrix.\n");
			return (NULL);
		}
		for(i = 0; i < dimension; i++)
		{
			m[i] = (double*) calloc (dimension, sizeof(double));
				if(m[i] == NULL)
				{
					printf("Error : Insuficient memory to allocate the matrix.\n");
					return (NULL);
				}

		}

	return (m); // Returns the pointer to the matrix
}

double **matrixDisallocation(int dimension, double **m) // Function to free the allocated space for the matrix
{
	int i; // Counter

	if(m == NULL)
		return (NULL);

	if(dimension < 1)
	{
		printf("Error : Invalid dimensionension of the matrix.\n");
		return (m);
	}

	for(i = 0; i < dimension; i++)
		free (m[i]);

	free (m);

	return (NULL); // Returns a null pointer, because the matrix has already been disallocated
}

double matrixNorm(double **ma, double **mb, int dimension) // Calculates the matrix norm
{
	int i, j;
	double norm = 0;

	for(i = 0; i < dimension; i++)
	{
    	for(j = 0; j < dimension; j++)
      	{
      		norm += pow((ma[i][j] - mb[i][j]), 2);

      	}
	}

    return (norm);    
}

void matrixMultiplication(double **ma, double **mb, double **resultm, int dimension) // Multiplicates the ma matrix and the mb matrix and stores the results on the resultm matrix
{
	int i, j, k;

	for(i = 0; i < dimension; i++) // Do the matrix multiplication
	{
	    for(j = 0; j < dimension; j++)
	      {
	      	resultm[i][j] = 0;

	        for(k = 0; k < dimension; k++)
	        {
	        	resultm[i][j] += mb[i][k] * ma[k][j];
	        }
	    }
	}
}

void matrixCopy(double **ma, double **mb, int dimension) // Copies the ma matrix to a mb matrix
{
	int i, j;

	for(i = 0; i < dimension; i++)
	{
	   	for(j = 0; j < dimension; j++)
	   	{
	   		mb[i][j] = ma[i][j];	      	
	   	}
    }	
}

double **constructMatrix(double **m, int dim) // Function to construct the matrix from the input file
{
	int x, y; // Matrix dimensions
	int i, j, k; // Counters
	int sum; // Sum of the line

	while(scanf("%d %d", &x, &y) != EOF) // Reads the input file and construct the matrix
	{
		m[x][y] = 1.00;
	}

	for(i = 0; i < dim; i++) // Checks if the line sum is 0. If it's true, it replaces all the line for 1.
	{
		sum = 0;
		for(j = 0; j < dim; j++)
		{
			sum += m[i][j];

			if(j == dim-1 && sum == 0)
			{
				for(k = 0; k < dim; k++)
				{
					m[i][k] = 1.00;
				}
			}
		}
	}
	return (m);
}

double **stochasticMatrix(double **m, double dampfac, int dimension) // Function that does the Stochastic Matrix, apllies the damping factor and calls the multiplication of matrix function
{
	int i, j, k; // Counters
	int sum; // Sum of the line and a counter

	for(i = 0; i < dimension; i++)
	{
		sum = 0;
		for(j = 0; j < dimension; j++)
		{
			sum += m[i][j];
			
			if(j == dimension-1)
			{
				for(k = 0; k < dimension; k++)
				{
					if(m[i][k] == 1.00)
						m[i][k] /= sum;
				}
			}
		}
	}

	for(i = 0; i < dimension; i++)
	{
		for(j = 0; j < dimension; j++)
		{
			m[i][j] = (((1 - dampfac) * m[i][j]) + (dampfac/dimension));
		}
	}
	return (m);
}

void outputPrinter(double **m, int dimension) // Prints the output in the stdout
{
	int i;

	for(i = 0; i < dimension; i++){
		printf("%d %.4lf\n", i, m[i][i]);
	}
}
