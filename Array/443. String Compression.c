/*
443. String Compression
Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.

Follow up:
Could you solve it using only O(1) extra space?
Example 1:
Input:
["a","a","b","b","c","c","c"]
Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
Example 2:
Input:
["a"]
Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.
Example 3:
Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.
Note:
All characters have an ASCII value in [35, 126].
1 <= len(chars) <= 1000.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

//#define A443
#ifdef A443

int compress(char* chars, int charsSize) {
	int i=0, p=0, subLen=1, numLen=0, count=0;
	for (p = 0; p < charsSize;)
	{
		for (i = p + 1, subLen = 1; i<charsSize && chars[p] == chars[i]; i++)
		{
			subLen++;
		}
		p = p + subLen;
		if (subLen > 1){
			numLen = 0;
			while (subLen)
			{
				subLen = subLen / 10;
				numLen++;
			}
			count += numLen;
		}
		count += 1;
	}
	return count;
}


int main(){
	char a[] = {'a','a','b','b','c','c','c'};
	compress(a, 6);
	return 0;
}

#endif