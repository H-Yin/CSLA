/*

92 Reverse Linked List II

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

#include<stdio.h>
#include<stdlib.h>

#include "MyList.h"

//Definition for singly-linked list.

struct RandomListNode *copyRandomList(struct RandomListNode *head) {
	struct RandomListNode * cur = head;
	struct RandomListNode * temp =NULL,*new_head = NULL,*new_cur=NULL;
	if (!head)
	{
		return NULL;
	}
	while (cur)
	{
		temp = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
		temp->label = cur->label;
		temp->next = cur->next;
		cur->next = temp;
		cur = cur->next->next;
	}
	cur = head;
	while (cur)
	{
		if (cur->random){
			cur->next->random = cur->random->next;
		}
		cur = cur->next->next;
	}
	cur = head;
	new_head = head->next;
	while (cur)
	{
		new_cur = cur->next;
		cur->next = new_cur->next;
		if (new_cur->next){
			new_cur->next = new_cur->next->next;
		}
		cur = cur->next;
	}
	return new_head;
}


//
//int main(){
//	struct RandomListNode *l1, *l2, *pre_L1, *pre_L2, *l3;
//	int i = 1;
//	l1 = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
//	l2 = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
//	pre_L1 = l1;
//	pre_L2 = l2;
//	for (i = 0; i< 10; i++){
//		pre_L1->label = i % 2 ? i : 10 - i;
//		if (i != 9){
//			pre_L1->next = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
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
//	l3 = copyRandomList(NULL);
//	printList(l3);
//	getchar();
//}