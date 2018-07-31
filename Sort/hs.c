
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


// #define A204
#ifdef A204

void printArray(int* nums, int numsSize)
{
	printf("[");
	for (int i = 0; i < numsSize; i++){
		printf("%d, ", nums[i]);
	}
	printf("]\n");
}

bool HeapAdjust(int a[], int i, int n)
{
	int iChild, nTemp;
	for (; 2 * i + 1 < n; i = iChild)
	{
		//子结点的位置=2*（父结点位置）+1
		iChild = 2 * i + 1;
		//得到子结点中较大的结点
		if (iChild<n - 1 && a[iChild + 1]>a[iChild])
			++iChild;
		//如果较大的子结点大于父结点那么把较大的子结点往上移动，替换它的父结点
		if (a[i]<a[iChild])
		{
			nTemp = a[i];
			a[i] = a[iChild];
			a[iChild] = nTemp;
		}
		else break; //否则退出循环
	}
}

void HeapSort(int a[], int n){
	int j;
	for (j = n / 2; j > 0; j--){
		HeapAdjust(a, j, n);
	}
	printArray(a, n);
}




int main(){
	for (int i = 0; i < 100; i++){
		printf("%d, %d\n", i, i);
	}
	return 0;
}

#endif