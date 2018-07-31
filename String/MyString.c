#include "MyString.h"

char toLowerCase(char a){
	if (a >= 'A' && a <= 'Z'){
		return a - 'A' + 'a';
	}
	return a;
}

char toUpperCase(char a){
	if (a >= 'a' && a <= 'z'){
		return a - 'a' + 'A';
	}
	return a;
}