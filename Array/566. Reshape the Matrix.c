/*
566. Reshape the Matrix
In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.
You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.
The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.
If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
Example 1:
Input:
nums =
[[1,2],
[3,4]]
r = 1, c = 4
Output:
[[1,2,3,4]]
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


// #define A566
#ifdef A566

int** matrixReshape(int** nums, int numsRowSize, int numsColSize, int r, int c, int** columnSizes, int* returnSize) {
	int **newArray = NULL;
	int i = 0, j = 0, s = 0, t = 0;
	if (r*c > numsRowSize* numsColSize){
		r = numsRowSize;
		c = numsColSize;
	}
	newArray = (int**)malloc(sizeof(int*)*r);
	*columnSizes = (int*)malloc(sizeof(int)*r);
	*returnSize = r;
	for (i = 0; i < r; i++)
	{
		newArray[i] = (int*)malloc(sizeof(int)*c);
		(*columnSizes)[i] = c;
		for (j = 0; j < c; j++){
			s = (i*c + j) / numsColSize;
			t = (i*c + j) % numsColSize;
			newArray[i][j] = nums[s][t];
		}
	}
	return newArray;
}

int main(){
	int a[3][4] = { { 0, 0, 0,1 }, { 0, 1, 1,2 }, { 1, 0, 1,3 } };

	int *colSize;
	int rowSize, i, j;
	int **ret;
	int **newImage = (int**)malloc(sizeof(int*)* 3);
	for (i = 0; i < 3; i++)
	{
		newImage[i] = (int*)malloc(sizeof(int)* 4);
		for (j = 0; j < 4; j++){
			newImage[i][j] = a[i][j];
			// printf("%d, %d\n", newImage[i][j], a[i][j]);
		}
	}
	ret = matrixReshape(newImage, 3, 4, 6, 3, &colSize, &rowSize);
	for (i = 0; i < rowSize; i++){
		for (j = 0; j < colSize[i]; j++){
			printf("%d ", ret[i][j]);
		}
		printf("\n");
	}
	return 0;
}

#endif