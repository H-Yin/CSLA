#ifndef _MY_STRING_H
#define _MY_STRING_H


#define IS_LETTER(a) (((a)>='a' && (a)<='z') || ((a)>='A' && (a)<='Z'))
#define IS_NUMSER(a) ((a)>='0' && (a)<='9')
#define TO_LOWER_CASE(a) ((a)>='A' && (a)<='Z' ? ((a)-'A'+'a'):(a))
#define EQUAL_WITHOUT_CASE(a, b) ((IS_LETTER(a) && IS_LETTER(b))?(TO_LOWER_CASE(a)==TO_LOWER_CASE(b)):(a)==(b))


char toUpperCase(char a);
char toLowerCase(char a);

#endif