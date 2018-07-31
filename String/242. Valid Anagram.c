/*
242. Valid Anagram
Given two strings s and t, write a function to determine if t is an anagram of s.
For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

// #define A242
#ifdef A242
/* 理解有误，并不判定顺序相反的两个单词
bool isAnagram(char* s, char* t) {

	int i=0, len = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	len = i+1;
	i = 0;
	while (t[i] != '\0')
	{
		if (t[i] != s[len - i - 1])
		{
			return false;
		}
		i++;
	}
	if (i == len - 1){
		return true;
	}
	return false;
}
*/

bool isAnagram(char* s, char* t) {
	int s_len[26] = {0};
	int t_len[26] = { 0 };
	memset(s_len, 0, sizeof(s_len));
	memset(s_len, 0, sizeof(t_len));
	int i = 0, len = 0;
	while (s[i] != '\0')
	{
		s_len[s[i]-'a']++;
	}
	i = 0;
	while (t[i] != '\0')
	{
		t_len[t[i] - 'a']++;
	}
	i = 0;
	while (i < 26)
	{
		if (s_len[i] != t_len[i])
		{
			return false;
		}
		i++;
	}
	return true;
}
int main(){
	printf("%d", isAnagram("abce", "decba"));
	getchar();
	return 0;
}

#endif