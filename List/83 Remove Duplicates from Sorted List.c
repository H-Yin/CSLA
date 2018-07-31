/*

83. Remove Duplicates from Sorted List

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

#include<stdio.h>
#include<stdlib.h>
//Definition for singly-linked list.
#include "MyList.h"
/*
// ³õÊ¼°æ
struct ListNode* deleteDuplicates(struct ListNode* head) {

	struct ListNode *pre = head, *cur, *temp;
	while (pre && pre->next){
		cur = pre->next;
		if (cur->val == pre->val){
			temp = cur;
			cur = cur->next;
			pre->next = cur;
			free(temp);
		}
		else
		{
			pre = pre->next;
		}
	}	
	return head;
}
*/
// ÌáÉý°æ
struct ListNode* deleteDuplicates(struct ListNode* head) {

	struct ListNode *pre = head, *cur;
	while (pre && pre->next){
		cur = pre->next;
		if (cur->val == pre->val){
			pre->next = cur->next;
			free(cur);
			cur = pre->next;
		}
		else
		{
			pre = pre->next;
		}
	}
	return head;
}


//int main(){
//	struct ListNode *l1, *l2, *pre_L1, *pre_L2, *l3;
//	int i = 1;
//	l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	pre_L1 = l1;
//	pre_L2 = l2;
//	for (i = 0; i< 10; i++){
//		// pre_L1->val = i < 5 ? 1 : 2;
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
//	l3 = deleteDuplicates(l1);
//	printList(l3);
//	getchar();
//}
