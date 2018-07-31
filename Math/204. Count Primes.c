/*
204. Count Primes
Description:
Count the number of prime numbers less than a non-negative number, n.
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

// #define A204
#ifdef A204

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

int countPrimes(int n) {
	int i = 1, ret = 0;
	if (n <3){
		return 0;
	}
	// 2，
	ret += 2;
	for (i = 5; i<n; i += 6){
		if (isPrime(i) == 1){
			ret++;
		}
		if (i + 2 < n && isPrime(i + 2) == 1){
			ret++;
		}
	}
	return ret;
}

int countPrimes(int n) {
	if (n < 3) return 0;
	bool *bitflag = (bool *)malloc(sizeof(bool)* n);
	memset(bitflag, 0, n);
	int sum = 1;
	int i, j, temp = (int)sqrt(n);
	for (i = 3; i < temp; i += 2){
		if (!bitflag[i]) {
			sum++;
			for (j = i*i; j < n; j += i){
				bitflag[j] = 1;
			}
		}
	}
	for (; i < n; i += 2){
		if (!bitflag[i]) {
			sum++;
		}
	}
	free(bitflag);
	return sum;
}

int main(){
	// (2) 定义使用到的变量
	//int i = 2;
	//LARGE_INTEGER freq;
	//LARGE_INTEGER start_t, stop_t;
	//// (3) 获取性能计数器的频率
	//QueryPerformanceFrequency(&freq);
	//// (4) 获取开始时的滴答数和结束时的滴答数
	//QueryPerformanceCounter(&start_t);
	//for (i = 0; i < 400000; i++){
	//	isPrime(i);
	//}
	//QueryPerformanceCounter(&stop_t);
	//// (5) 计算时间间隔。为保留精度，要注意计算方式
	//double internel = (double)(stop_t.QuadPart - start_t.QuadPart) * 1000.0 / freq.QuadPart; // ms
	
	printf("%d", countPrimes(100));
	getchar();
}

#endif