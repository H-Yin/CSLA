/*
A matrix is Toeplitz if every diagonal from top - left to bottom - right has the same element.
Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
Example 1:
Input : matrix = [[1, 2, 3, 4], [5, 1, 2, 3], [9, 5, 1, 2]]
Output : True
Explanation :
1234
5123
9512
In the above grid, the diagonals are "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]", and in each diagonal all elements are the same, so the answer is True.
Example 2:
Input : matrix = [[1, 2], [2, 2]]
Output : False
Explanation :
The diagonal "[1, 2]" has different elements.
Note :

	 matrix will be a 2D array of integers.
	 matrix will have a number of rows and columns in range[1, 20].
	 matrix[i][j] will be integers in range[0, 99].
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


// #define A766
#ifdef A766

bool isToeplitzMatrix(int** matrix, int matrixRowSize, int *matrixColSizes) {
	int i = 0, j = 0, k = 0, flag = 0;
	for (i = 0; i < *matrixColSizes; i++)
	{
		j = 0;
		k = i;
		while (k+1 < *matrixColSizes && j+1<matrixRowSize)
		{
			if (matrix[j+1][k+1]!=matrix[j][k])
			{
				return false;
			}
			j++;
			k++;
		}
	}
	for (i = 1; i < matrixRowSize; i++)
	{
		j = i;
		k = 0;
		while (k + 1 < *matrixColSizes && j + 1<matrixRowSize)
		{
			if (matrix[j + 1][k + 1] != matrix[j][k])
			{
				return false;
			}
			j++;
			k++;
		}
	}
	return true;
}

int main(){
	for (int i = 0; i < 100; i++){
		printf("%d, %d\n", i, i);
	}
	return 0;
}

#endif

