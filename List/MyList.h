#ifndef _MYLIST_H_
#define _MYLIST_H_

#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct RandomListNode {
	int label;
	struct RandomListNode *next;
	struct RandomListNode *random;
};

void printList(struct ListNode* L);
void printRandomList(struct RandomListNode* L);

struct ListNode* createList(int * nodeArray, int nodeSize);
#endif