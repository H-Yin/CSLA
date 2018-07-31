/*
535. Encode and Decode TinyURL
Note: This is a companion problem to the System Design problem : Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https ://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.
Design the encode and decode methods for the TinyURL service.There is no restriction on how your encode / decode algorithm should work.You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
*/

#include <stdio.h>
#include <stdlib.h>

/** Encodes a URL to a shortened URL. */
char* encode(char* longUrl) {
	char allChars[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ:/-";
	int i = 0,j = 0, count=0, num=0;

	while (longUrl[i] != '\0'){
		num = 0;
		for (j = 0; j < 6 && longUrl[i] != '\0'; j++)
		{
			num = num * 2 + longUrl[i];
			i++;
		}
		printf("%d\n", num);
	}
	return NULL;
}

/** Decodes a shortened URL to its original URL. */
char* decode(char* shortUrl) {
	return NULL;
}
#ifdef A535
int main(){
	char longURL[] = "https://leetcode.com/problems/design-tinyurl";
	char *shortURL = encode(longURL);
	printf("L:%s\n", longURL);
	getchar();
	/*printf("S:%s\n", shortURL);
	printf("L:%s\n", decode(shortURL));*/
}
#endif