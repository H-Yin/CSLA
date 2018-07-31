/*
206. Reverse Linked List

*/


#include<stdio.h>

#include<stdlib.h>

#include <stdbool.h>
#include "MyList.h"

/* 迭代法
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode new_head;
	struct ListNode *pre = head, *cur = NULL, *new_pre = NULL;
	new_head.next = head;
	new_pre = &new_head;
	while (pre && pre->next)
	{
		cur = pre->next;
		// 头插法
		pre->next = cur->next;
		cur->next = new_pre->next;
		new_pre->next = cur;
	}
	return new_head.next;
}

*/

struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode new_head;
	struct ListNode *pre = head, *cur = NULL, *new_pre = NULL;
	new_head.next = head;
	new_pre = &new_head;
	while (pre && pre->next)
	{
		cur = pre->next;
		// 头插法
		pre->next = cur->next;
		cur->next = new_pre->next;
		new_pre->next = cur;
	}
	return new_head.next;
}

//
//int main(){
//	struct ListNode *l1, *l2, *pre_L1, *pre_L2, *l3, *look = NULL;
//	int i = 1,n;
//	l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	pre_L1 = l1;
//	pre_L2 = l2;
//	n = 1;
//	for (i = 0; i< n; i++){
//		pre_L1->val = i;
//		if (i != n-1){
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
//	l3 = reverseList(NULL);
//	printList(l3);
//	getchar();
//}
