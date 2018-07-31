/*
203. Remove Linked List Elements

Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

*/

#include<stdio.h>

#include<stdlib.h>

#include <stdbool.h>

#include "MyList.h"

struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode new_head;
	struct ListNode *cur=head, *new_pre = NULL;
	new_head.next = head;
	new_pre = &new_head;
	while (cur){
		if (cur->val == val)
		{
			new_pre->next = cur->next;
			free(cur);
			cur = new_pre->next;
		}
		else
		{
			cur = cur->next;
			new_pre = new_pre->next;
		}
	}
	return new_head.next;
}

//
//int main(){
//	struct ListNode *l1, *l2, *pre_L1, *pre_L2, *l3, *look = NULL;
//	int i = 1;
//	l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	pre_L1 = l1;
//	pre_L2 = l2;
//	for (i = 0; i< 10; i++){
//		pre_L1->val = 1;
//		if (i != 9){
//			pre_L1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//			pre_L1 = pre_L1->next;
//		}
//		else{
//			pre_L1->next = NULL;
//		}
//	}
//	/*
//	for(i=5; i< 6; i++){
//	pre_L2->val = i;
//	if (i!=5){
//	pre_L2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//	pre_L2 = pre_L2->next;
//	}else{
//	pre_L2->next = NULL;
//	}
//	}*/
//	printList(l1);
//	// printList(l2);
//	l3 = removeElements(l1,1);
//	printList(l3);
//	getchar();
//}
