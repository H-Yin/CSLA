/*
278. First Bad Version
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.
Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// #define A278
#ifdef A278

bool isBadVersion(int version){
	if (version > 0){
		return true;
	}
	return false;
}

int firstBadVersion(int n) {
	int left = 1L, right = n, mid, ret;
	while (left <= right){
		// ·ÀÖ¹Òç³ö
		mid = (int)(left / 2.0 + right / 2.0);
		ret = isBadVersion(mid);
		if (ret){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	ret = left / 2 + right / 2 + 1;
	if (ret > n){
		return n;
	}
	return ret;
}

int main(){
	printf("%d\n", firstBadVersion(1));
	return 0;
}

#endif