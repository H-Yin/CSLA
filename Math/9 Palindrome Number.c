/*
9. Palindrome Number

*/

#include <stdio.h>
#include <stdbool.h>

// #define A9
#ifdef A9

/*
bool isPalindrome(int x) {
	long int t = 0 , s;
	if (x < 0)
	{
		return false;
	}
	s = x < 0 ? 0 - x : x;
	while (s > 0)
	{
		t = t * 10 + s % 10;
		s = s / 10;
	}
	s = x < 0 ? 0 - x : x;
	return (t == (long int)s);
}
*/
bool isPalindrome(int x) {
	long int t = 0, s = x;
	if (x < 0 || (x > 0 && x % 10 ==0 ))
	{
		return false;
	}
	// Ñ­»·Ò»°ë
	while (s > t)
	{
		t = t * 10 + s % 10;
		s = s / 10;
	}
	return (t == s || t / 10 == s);
}

//int main(){
//
//	printf("%d\n", isPalindrome(123));
//	getchar();
//	return 0;
//}
#endif