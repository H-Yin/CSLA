#include "stdio.h"
/*
Divide two integers without using multiplication, division and mod operator.
If it is overflow, return MAX_INT.
*/

int divide(int dividend, int divisor) {
	long int res = 0;
	int flag = 0;
	unsigned long int a, b;
	if (divisor == 0){
		return (int)((1 << 31) - 1);
	}

	a = dividend < 0 ? 0 - dividend : dividend;
	flag = dividend < 0 ? 1 : 0;

	b = divisor < 0 ? 0 - (long int)divisor : (long int)divisor;
	flag = divisor < 0 ? (flag ? 0 : 1) : flag;

	printf("%ld, %ld\n", a, b);
	while (a >= b){
		res++;
		a = a - b;
	}
	if (res >(long int)((1 << 31)))
	{
		return (int)((1 << 31) - 1);
	}
	return flag ? 0 - res : res;
}

double myPow(double x, int n) {
	double res = 1.0;
	if (n < 0){
		x = 1.0 / x;
		n = 0 - n;
	}
	if ( n %2)
	{
		res = x;
		n = n - 1;
	}
	else{
		res = x;
	}
	while (n){
		res = res * x;
		n = n >> 1;
	}
	return res;
}

//int main(){
//	int a = -2147483647 - 1, b = -1;
//	// printf("%ld,%d\n", (long)2147483648, b);
//	//printf("%d", divide(a, b));
//	printf("%lf", myPow(0.2, 5));
//	getchar();
//	return 0;
//}