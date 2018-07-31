/*
537. Complex Number Multiplication
Given two strings representing two complex numbers.
You need to return a string representing their multiplication.Note i2 = -1 according to the definition.
Note:
The input strings will not have extra blank.
The input strings will be given in the form of a + bi, where the integer a and b will both belong to the range of[-100, 100].And the output should be also in this form.
*/
#include <stdio.h>
#include <stdlib.h>

// #define A537
#ifdef A537

char* complexNumberMultiply(char* a, char* b) {
	char *ret = (char*)malloc(sizeof(char)* 20);
	int x1=0, y1=0, x2=0, y2=0, x3 =0, y3 =0;
	int i = 0,j;
	int num[6] = { -1, -1, -1, -1, -1, -1 }, s, t;
	// 字符串转化为 x1, y1, x2, y2,
	while (a[i] != '+'){		
		if (a[i] != '-'){
			x1 = x1 * 10 + (a[i] - '0');
		}
		i++;
	}
	if (a[0] == '-')
	{
		x1 = 0 - x1;
	}

	j = i+1;
	while (a[j] != 'i')
	{
		if (a[j] != '-'){
			y1 = y1 * 10 + (a[j] - '0');
		}
		j++;
	}
	if (a[i+1] == '-')
	{
		y1 = 0 - y1;
	}

	i = j = 0;
	while (b[i] != '+')
	{
		if (b[i] != '-'){
			x2 = x2 * 10 + (b[i] - '0');
		}
		i++;	
	}
	if (b[0] == '-')
	{
		x2 = 0 - x2;
	}

	j = i+1;
	while (b[j] != 'i'){
		if (b[j] != '-'){
			y2 = y2 * 10 + (b[j] - '0');
		}
		j++;
	}
	if (b[i+1] == '-'){
		y2 = 0 - y2;
	}
	// 计算 x3,y3
	x3 = x1*x2 - y1*y2;
	y3 = x1*y2 + x2*y1;
	// 转换成字符串
	i = j = 0;
	if (x3 < 0)
	{
		ret[i] = '-';
		i ++;
		x3 = 0 - x3;
	}
	j = 0;
	s = x3;
	while (s >= 0){
		num[j] = s % 10;
		s = s / 10;
		if (s == 0){
			break;
		}
		j++;
	}
	j = 6;
	while (j)
	{
		j--;
		if (num[j] < 0){
			continue;
		}
		else{
			ret[i] = num[j] + '0';
			num[j] = -1;
			i++;
		}
		
	}
	ret[i] = '+';
	i++;
	if (y3 < 0)
	{
		ret[i] = '-';
		i++;
		y3 = 0 - y3;
	}
	j = 0;
	s = y3;
	while (s >= 0){
		num[j] = s % 10;
		s = s / 10;
		if (s == 0){
			break;
		}
		j++;
	}
	j = 6;
	while (j--)
	{
		if (num[j] < 0){
			continue;
		}
		else{
			ret[i] = num[j] + '0';
			i++;
		}
	}
	ret[i] = 'i';
	ret[i + 1] = '\0';
	return ret;
}

int main(){
	printf("%s", complexNumberMultiply("1+-1i", "3+-4i"));
	getchar();
	return 0;
}

#endif