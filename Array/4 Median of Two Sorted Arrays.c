#include<stdio.h>
#include<stdlib.h>

/*
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int indexA = 0, indexB = 0, indexC = 0;
	int length = nums1Size + nums2Size;
	int * temp = (int*)malloc(sizeof(int)*length);

	if (length <=0)
	{
		return 0.0;
	}

	while (indexA < nums1Size || indexB < nums2Size )
	{
		if (indexA == nums1Size)
		{
			temp[indexC] = nums2[indexB];
			indexB++;
		}
		else if (indexB == nums2Size )
		{
			temp[indexC] = nums1[indexA];
			indexA++;
		}
		else if (nums1[indexA] <= nums2[indexB])
		{
			temp[indexC] = nums1[indexA];
			indexA++;
		}
		else{
			temp[indexC] = nums2[indexB];
			indexB++;
		}
		printf("%d  %d\n",indexC,temp[indexC]);
		if (indexC >= length / 2){
			break;
		}
		indexC++;
	}
	if (length % 2){
		return temp[length / 2];
	}
	else{
		return (temp[length / 2] + temp[length / 2-1]) / 2.0;
	}
}
*/
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int indexA = 0, indexB = 0, indexC = 0;
	int length = (nums1Size + nums2Size);
	int * temp = (int*)malloc(sizeof(int)*(length / 2 + 1));

	if (nums1Size <= 0 && nums2Size <= 0)
	{
		return 0.0;
	}

	while (indexA < nums1Size || indexB < nums2Size)
	{
		if (indexA == nums1Size)
		{
			temp[indexC] = nums2[indexB];
			indexB++;
		}
		else if (indexB == nums2Size)
		{
			temp[indexC] = nums1[indexA];
			indexA++;
		}
		else if (nums1[indexA] <= nums2[indexB])
		{
			temp[indexC] = nums1[indexA];
			indexA++;
		}
		else{
			temp[indexC] = nums2[indexB];
			indexB++;
		}
		if (indexC >= length / 2){
			break;
		}
		indexC++;
	}
	if (length % 2){
		return temp[length/2];
	}
	else{
		return (temp[length/2] + temp[length/2 - 1]) / 2.0;
	}
}

//int main(){
//	int a[] = { 2,2,2,2};
//	int b[] = {2,2,2};
//	printf("%f", findMedianSortedArrays(a, 4, b, 3));
//	getchar();
//	return 0;
//}