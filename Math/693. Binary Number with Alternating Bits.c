/*
693. Binary Number with Alternating Bits
Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.
Input: 5
Output : True
Explanation :
The binary representation of 5 is : 101
Example 2 :
Input : 7
Output : False
Explanation :
The binary representation of 7 is : 111.
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

// #define A693
#ifdef A693

bool hasAlternatingBits(int n){
	int x = n, y;
	// ��ȡ�����Ľ���λ��01 ��10
	y = x % 4;
	// 00 �� 11 ʧ��
	if (y == 0 || y == 3)
	{
		return false;
	}
	x = x / 4;
	while (x)
	{
		// ÿ��λ�ж�һ���Ƿ�Ϊ����λ
		if (x % 4 != y){
			return false;
		}
		x = x / 4;
	}
	return true;
}

int main(){
	for (int i = 1; i < 100; i++){
		printf("%d, %d\n", i, hasAlternatingBits(i));
	}
	
	getchar();
	return 0;
}

#endif