/*
733. Flood Fill
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).
Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.
To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.
At the end, return the modified image.
Example 1:
Input:
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation:
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:
The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


// #define A733
#ifdef A733


int** subFloodFill(int** image, int imageRowSize, int imageColSize, int sr, int sc, int newColor, int oldColor) {
	if ((sr >= 0 && sr < imageRowSize) && (sc >= 0 && sc < imageColSize)){
		if (image[sr][sc] == oldColor)
		{
			image[sr][sc] = newColor;
			subFloodFill(image, imageRowSize, imageColSize, sr - 1, sc, newColor, oldColor);
			subFloodFill(image, imageRowSize, imageColSize, sr + 1, sc, newColor, oldColor);
			subFloodFill(image, imageRowSize, imageColSize, sr, sc - 1, newColor, oldColor);
			subFloodFill(image, imageRowSize, imageColSize, sr, sc + 1, newColor, oldColor);
		}
	}
	return image;
}

int** floodFill(int** image, int imageRowSize, int imageColSize, int sr, int sc, int newColor, int** columnSizes, int* returnSize) {
	int **newImage = NULL;
	int i = 0,j=0;
	newImage = (int**)malloc(sizeof(int*)*imageRowSize);
	*columnSizes = (int*)malloc(sizeof(int)*imageRowSize);
	*returnSize = imageRowSize;
	for (i = 0; i < imageRowSize; i++)
	{
		newImage[i] = (int*)malloc(sizeof(int)*imageColSize);
		(*columnSizes)[i] = imageColSize;
		for (j = 0; j < imageColSize; j++){
			newImage[i][j] = image[i][j];
		}
	}
	if ((sr >= 0 && sr < imageRowSize) && (sc >= 0 && sc < imageColSize && image[sr][sc] != newColor)){
		subFloodFill(newImage, imageRowSize, imageColSize, sr, sc, newColor, image[sr][sc]);
	}
	return newImage;
}


int main(){
	int a[3][3] = { { 0, 0, 0 }, { 0, 1, 1 }, { 1, 0, 1 } };

	int *colSize;
	int rowSize, i, j;
	int **ret;
	int **newImage = (int**)malloc(sizeof(int*)* 2);
	for (i = 0; i < 2; i++)
	{
		newImage[i] = (int*)malloc(sizeof(int)*3);
		for (j = 0; j < 3; j++){
			newImage[i][j] = a[i][j];
			printf("%d, %d\n", newImage[i][j], a[i][j]);
		}
	}
	ret = floodFill(newImage, 2, 3, 1, 1, 1, &colSize,&rowSize);
	for (i = 0; i < rowSize; i++){
		for (j = 0; j < colSize[i]; j++){
			printf("%d ", ret[i][j]);
		}
		printf("\n");
	}

	return 0;
}

#endif