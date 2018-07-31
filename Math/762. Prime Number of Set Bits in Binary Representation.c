/*
762. Prime Number of Set Bits in Binary Representation
Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) having a prime number of set bits in their binary representation.

(Recall that the number of set bits an integer has is the number of 1s present when written in binary. For example, 21 written in binary is 10101 which has 3 set bits. Also, 1 is not a prime.)

Input: L = 10, R = 15
Output: 5
Explanation:
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)
Note:

L, R will be integers L <= R in the range [1, 10^6].
R - L will be at most 10000.

*/
#include <stdio.h>

// #define A762
#ifdef A762

int isPrime(int n){
	int i = 5, temp;
	if (n == 2 || n == 3){
		return 1;
	}
	if (n % 2 == 0 || n % 3 == 0){
		return 0;
	}
	temp = (int)sqrt(n);
	while (i <= temp){
		if (n % i == 0 || n % (i + 2) == 0){
			return 0;
		}
		i += 6;
	}
	return 1;
}

int countPrimeSetBits(int L, int R) {
	unsigned int n=0, temp = 0, bits = 0, ret = 0;
	for (n = L; n < R+1; n++){
		temp = n - ((n >> 1) & 033333333333) - ((n >> 2) & 011111111111);
		bits = ((temp + (temp >> 3)) & 030707070707) % 63;
		if (bits != 1 && isPrime(bits) == 1){
			ret++;
		}
	}
	return ret;
}

int main(){
	printf("%d", countPrimeSetBits(6,10));
	getchar();
}
#endif
