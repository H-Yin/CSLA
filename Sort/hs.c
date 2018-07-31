
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
		//�ӽ���λ��=2*�������λ�ã�+1
		iChild = 2 * i + 1;
		//�õ��ӽ���нϴ�Ľ��
		if (iChild<n - 1 && a[iChild + 1]>a[iChild])
			++iChild;
		//����ϴ���ӽ����ڸ������ô�ѽϴ���ӽ�������ƶ����滻���ĸ����
		if (a[i]<a[iChild])
		{
			nTemp = a[i];
			a[i] = a[iChild];
			a[iChild] = nTemp;
		}
		else break; //�����˳�ѭ��
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