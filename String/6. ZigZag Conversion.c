
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

// #define A6
#ifdef A6

char* convert(char* s, int numRows) {
	char *ret,*p;
	int flag, a, b, step = (numRows - 1) * 2;
	int i=0,j=0,k=0, len=0;
	for (p = s; *p; p++, len++);
	ret = (char*)malloc(sizeof(char)*(len + 1));
	ret[len] = '\0';
	for (i = 0; i < numRows; i++)
	{
		a = step - i * 2;
		b = i * 2;
		for (j = i, flag=1; j < len;)
		{
			ret[k] = s[j];
			if (flag % 2){
				if (a != 0){
					j += a;
				}
				else if (b != 0)
				{
					j += b;
				}
				else
				{
					j++;
				}
			}
			else 
			{
				ret[k] = s[j];
				if (b != 0){
					j += b;
				}
				else if (a != 0){
					j += a;
				}
				else
				{
					j++;
				}
			}
			k++;
			flag++;
		}
	}
	return ret;
}

int main(){

	convert("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco",61);
	getchar();
	return 0;
}

#endif