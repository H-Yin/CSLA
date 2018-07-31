/*
13. Roman to Integer
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include <stdio.h>

// #define A13
#ifdef A13


// ¼´¢ñ£¨1£©¡¢X£¨10£©¡¢C£¨100£©¡¢M£¨1000£©¡¢V£¨5£©¡¢L£¨50£©¡¢D£¨500£©

int romanToInt(char* s) {
	int ret = 0;
	int i = 0,j=0;
	while (s[i] !='\0'){
		j = i + 1;
		if (s[j] != '\0')
		{
			if (s[i] == 'I' && s[j] == 'V'){
				ret += 4;
			}
			else if (s[i] == 'I' && s[j] == 'X')
			{
				ret += 9;
			}
			else if (s[i] == 'X' && s[j] == 'L')
			{
				ret += 40;
			}
			else if (s[i] == 'X' && s[j] == 'C'){
				ret += 90;
			}
			else if (s[i] == 'C' && s[j] == 'D')
			{
				ret += 400;
			}
			else if (s[i] == 'C' && s[j] == 'M')
			{
				ret += 900;
			}
			else{
				switch (s[i])
				{
				case 'D':ret += 500; break;
				case 'L':ret += 50; break;
				case 'V':ret += 5; break;
				case 'M':ret += 1000; break;
				case 'C':ret += 100; break;
				case 'X':ret += 10; break;
				case 'I':ret += 1; break;
				default:break;
				}
				i = i + 1;
				continue;
			}
			i = j + 1;
		}
		else
		{
			switch (s[i])
			{
			case 'D':ret += 500; break;
			case 'L':ret += 50; break;
			case 'V':ret += 5; break;
			case 'M':ret += 1000; break;
			case 'C':ret += 100; break;
			case 'X':ret += 10; break;
			case 'I':ret += 1; break;
			default:break;
			}
			i++;
		}
	}
	return ret;
}
// 1000+900+90+9
int main(){
	printf("%d", romanToInt("MCMXCVI"));
	getchar();
}

#endif