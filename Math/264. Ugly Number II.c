/*
264. Ugly Number II
Write a program to find the n-th ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note that 1 is typically treated as an ugly number, and n does not exceed 1690.
*/

#include <stdio.h>
/*
263. Ugly Number
Write a program to check whether a given number is an ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
Note that 1 is typically treated as an ugly number.
*/
#include <stdbool.h>

// #define A264
#ifdef A264
/*
bool isUgly(int num) {
	int x = num;
	// positive numbers
	if (num <= 0){
		return false;
	}
	while (x % 2 == 0)
	{
		x /= 2;
	}
	while (x % 3 == 0)
	{
		x /= 3;
	}
	while (x % 5 == 0)
	{
		x /= 5;
	}
	if (x == 1)
	{
		return true;
	}
	return false;
}
// ²âÊÔ 1352 Ê±³¬Ê±
int nthUglyNumber(int n) {
	int i = 0, j= 0;
	while (i < n )
	{
		j++;
		if (isUgly(j)){
			i++;
		}
	}
	return j;
}
*/

bool isUgly(int num) {
	int x = num;
	// positive numbers
	if (num <= 0){
		return false;
	}
	while (x % 2 == 0)
	{
		x /= 2;
	}
	while (x % 3 == 0)
	{
		x /= 3;
	}
	while (x % 5 == 0)
	{
		x /= 5;
	}
	if (x == 1)
	{
		return true;
	}
	return false;
}

int main(){
	printf("%d", nthUglyNumber(1352));
	getchar();
}
#endif