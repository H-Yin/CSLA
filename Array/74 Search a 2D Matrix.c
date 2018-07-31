#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
	bool res = false;
	int r, low=0, high=matrixRowSize-1, mid, key;
	while (low <= high)
	{
		mid = (low + high) / 2;
		printf("%d\n", *((int *)matrix + mid * matrixColSize + 0));
		if (target == *((int *)matrix + mid * matrixColSize+0))
		{
			return true;
		}
		else if (target < *((int *)matrix + mid * matrixColSize + 0))
		{
			high = mid-1;
		}
		else  if (target > *((int *)matrix + (mid + 1) * matrixColSize - 1)){
			low = mid + 1;
		}
		else{
			low = mid;
			break;
		}
		
	}
	printf("<%d,%d,%d\n", low, high, mid);
	if (low > high)
	{
		return false;
	}
	key = low;
	low = 0;
	high = matrixColSize-1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		printf("---%d\n", *((int *)(matrix + key * matrixColSize) + mid));
		if (*((int *)matrix + key * matrixColSize + mid) == target)
		{
			return true;
		}
		else if (target < *((int *)matrix + key * matrixColSize + mid))
		{
			high = mid-1;
		}else{
			low = mid+1;
		}
	}
	return false;
}

//int main(){
//
//	int a[][4] = { 
//		{ 1, 3, 5, 7 },
//		{ 10, 11, 16, 20 },
//		{ 23, 30, 34, 50 } 
//	};
//	
//	if (searchMatrix((int **)a, 3, 4, 16)){
//		printf("true");
//	}
//	else{
//		printf("false");
//	}
//
//	getchar();
//	return 0;
//}