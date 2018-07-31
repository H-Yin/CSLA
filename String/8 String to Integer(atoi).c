
#include <stdlib.h>
#include <stdio.h>

int myAtoi(char* str) {
	long int res = 0;
	int flag = 0;
	int MAX = (1 << 31) - 1;
	char *p = str;

	if (str == ""){
		return 0;
	}
	// Ìø¹ý ¿Õ¸ñ
	printf("1:%s\n", p);
	while (p && *p == ' '){
		p++;
	}
	printf("1:%s\n", p);
	if (*p == '-'){
		flag = 1;
	}
	else if (*p == '+'){
		flag = 0;
	}
	else if (*p >= '0' && *p <= '9'){
		res = *p - '0';
	}
	else{
		return 0;
	}
	p++;
	printf("1:%s\n", p);
	while (p && *p >= '0' && *p <= '9'){
		res = res * 10 + *p - '0';
		// ÅÐ¶ÏÒç³ö
		printf("3:%d\n", res);
		if (flag == 0 && res > MAX){
			return MAX;
		}
		else if (flag == 1 && res - 1 > MAX){
			return 0 - MAX-1;
		}
		p++;
	}
	
	return (int)(flag ? 0 - res : res);
}


//int main(void)
//{
//	int n;
//	char *str = "97189273619873618276319783619872637";
//	n = myAtoi(str);
//	printf("n=%d\n", n);
//	getchar();
//	return 0;
//}