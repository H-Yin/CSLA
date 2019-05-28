/*******************************************************************
*  File        : 215. Kth Largest Element in an Array.c
*  Author      : H.Yin
*  Email       : csustyinhao@gmail.com
*  Created     : 2019-01-08 08:07:33(+0000)
*  Modified    : 2019-01-08 08:07:59(+0000)
*  GitHub      : https://github.com/H-Yin/CSLA
*  Description : Kth Largest Element in an Array
*******************************************************************/

/*
215. Kth Largest Element in an Array
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/
// Based Insertion sort

#include<stdio.h>
#include<stdlib.h>

void print(int *L, int n){
    int i = 0;
    for(i = 0; i < n ;i++){
        printf("%d ", L[i]);
    }
    printf("\n");
}

int findK_insertion_sort(int k, int *L, int n)
{
    int temp;
    int i = 0, j = 0;
    for(i = 1; i < k ;i++){
        for(j = i; j > 0 && L[j-1] < L[j]; j--){
            temp = L[j-1];
            L[j-1] = L[j];
            L[j] = temp;
        }
    }
    print(L, n);
    printf("--------------\n");
    for(i = k; i < n-1 ;i++){
        temp = L[i];
        for(j = k-1; j > 0 && L[j] < L[i]; j--){
            L[j] = L[j-1];
            printf("%d,  %d, %d \n",L[i], L[j-1], L[j]);
        }
        L[j] = temp;
        printf("--------------\n");
        print(L, n);
    }
    return L[k-1];
}


// Based quick sort
int findK_quick_sort(int k,int *L,int left,int right)
{
    // partition start
	int i = left, j = right, guard = L[left];
	if( k > right +1){
	    return -1;
	}
	while (i < j)
	{
		while (i < j && L[j] <= guard)
			j--;
		L[i] = L[j];		
		
		while (i < j && L[i] >= guard)
			i++;
		L[j] = L[i];
	}	
	L[i] = guard;
	// partition end
	// k-1 因为序号与下标差 1
	if(i == k-1)
	{
		return L[i];
	}
	else if(i > k-1)
		return findK_quick_sort(k, L, left, i-1);
	else
		return findK_quick_sort(k, L, i+1, right);
}

int findKthLargest(int* nums, int numsSize, int k) {
    return findK_insertion_sort(k, nums, numsSize);
    // return findK_quick_sort(k, nums, 0, numsSize-1);
}

int main(){
    int a[] = {2,4,6,6,8,4,2,8,9,0};
    
    
    printf("%d\n", findKthLargest(a, 10, 2));
    
    return 0;
}
