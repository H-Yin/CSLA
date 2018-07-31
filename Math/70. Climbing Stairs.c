/*
70. Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// #define A70
#ifdef A70
/*
// n =44 超时
int climbStairs(int n) {
	if (n == 1 || n == 2)
	{
		return n;
	}
	return climbStairs(n - 1) + climbStairs(n - 2);
}
*/

int climbStairs(int n) {
	int i = 1;
	int *res, sum = 0;
	if (n == 1 || n == 2){
		return n;
	}
	// 空间换时间
	res = (int *)malloc(sizeof(int)*(n+1)), sum=0;
	res[1] = 1;
	res[2] = 2;
	for (i = 3; i <= n; i++){
		res[i] = res[i - 1] + res[i - 2];
	}
	sum = res[n];
	free(res);
	return sum;
}

int main(){
	printf("%d", climbStairs(44));
	return 0;
}

#endif