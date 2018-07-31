
// #define A3
#ifdef A3

#include<stdio.h>

int subString(char *s, char *t){
	int i=0, j=0;
	while (s[i] != '\0' && t[j] != '\0')
	{
		// 相等就继续匹配
		if (s[i] == t[j]){
			i++;
			j++;
		}
		else{
			// 不相等就回溯
			i = i - j+1;
			j = 0;
		}
		// 判断是否匹配成功
		if (t[j] == '\0'){
			return i-j;
		}
	}
	return -1;
}
//
//int lengthOfLongestSubstring(char* s) {
//	int L = 0, R = 0, len = 0, max_len = 0;
//	char * p = s, *q =s;
//	while (*p != '\0' && *q != '\0'){
//		q = p+1;
//		while (*q != '\0' && *p != *q){
//			q++;
//		}
//		len = q - p + 1;
//		p = q;
//		max_len = max_len < len ? len : max_len;
//	}
//	return max_len;
//}
int main(){
	printf("%d\n", subString("abccbas","as"));
	return 0;
}

#endif