#include <stdio.h>
/*
263. Ugly Number
Write a program to check whether a given number is an ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
Note that 1 is typically treated as an ugly number.
*/
#include <stdbool.h>

// #define A263
#ifdef A263

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
	printf("%d", isUgly(20));
	getchar();
}
#endif