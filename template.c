
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// #define Atest
#ifdef Atest

void getNexts(char *t, int *Next){
	int i = 1, j = 0;
	Next[0] = 0;
	while (t[i] != '\0'){
		if (j == 0 || t[i] == t[j]){
			Next[i++] = ++j;
		}
		else{
			j = Next[j-1];
		}
		printf("i = %d, j = %d, next=%d\n", i, j, Next[i-1]);
	}
}

void printTArray(int* nums, int numsSize)
{
	printf("[");
	for (int i = 0; i < numsSize; i++){
		printf("%d, ", nums[i]);
	}
	printf("]\n");
}

int main(){
	int a[100];
	char b[] = "abbabb";
	getNexts(b, a);
	printTArray(a, strlen(b)+1);
	return 0 ;
}


#endif