/*
343. Integer Break
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58.
*/
#include <stdio.h>

// #define A343
#ifdef A343

// µÝ¹é·¨
//int subIntegerBreak(int n){
//	if (n == 2 || n == 3 || n == 4)
//	{
//		return n;
//	}
//	return 3 * subIntegerBreak(n - 3);
//}
//int integerBreak(int n) {
//	if (n == 2)
//	{
//		return 1;
//	}
//	else if (n == 3)
//	{
//		return 2;
//	}
//	else{
//		return subIntegerBreak(n);
//	}
//}

// µü´ú·¨
int integerBreak(int n) {
	int ret = 1, i=0, x=n;
	if (n == 2)
	{
		ret = 1;
	}
	else if (n == 3)
	{
		ret=2;
	}
	else{
		if (n % 3 == 1)
		{
			ret *= 4;
			x = n - 4;
		}
		for (; x > 2; x = x - 3)
		{
			ret = ret * 3;
		}
		if (x == 2){
			ret = ret * 2;
		}
	}
	return ret;
}

int main(){
	printf("%d", integerBreak(58));
	getchar();
	return 0;
}
#endif