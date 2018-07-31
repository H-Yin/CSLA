/*
20. Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

// #define A20
#ifdef A20

// 利用顺序栈
bool isValid(char* s) {
	char *temp = NULL,*p;
	int i=1, len = strlen(s);
	bool ret = true;
	temp = (char*)malloc(sizeof(char)*(len + 1));
	temp[0] = '\0'; // 防止 i-1 越界
	for (p = s; *p; p++)
	{
		if (*p == '[' || *p == '(' || *p == '{'){
			temp[i] = *p;
			i++;
		}
		else{
			// i-1是栈顶
			if ((*p == ']' && temp[i-1] == '[')
				|| (*p == '}' && temp[i-1] == '{')
				|| (*p == ')' && temp[i-1] == '('))
			{
				i--;
			}
			else{
				ret = false;
				break;
			}
		}
	}
	if (i > 1){
		ret = false;
	}
	free(temp);
	return ret;
}

int main(){
	printf("%d", isValid("[{{}}]{}(()()())"));
	getchar();
	return 0;
}

#endif