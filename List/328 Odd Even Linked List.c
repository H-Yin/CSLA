/*

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.
*/

#include<stdio.h>
#include<stdlib.h>
//Definition for singly-linked list.
#include "MyList.h"

struct ListNode* oddEvenList(struct ListNode* head) {
	struct ListNode odd_head, even_head;
	struct ListNode *cur = head, *odd_cur = NULL, *even_cur = NULL;
	odd_head.next = NULL;
	even_head.next = NULL;

	odd_cur = &odd_head;
	even_cur = &even_head;

	int i = 1;
	while (cur)
	{
		// 判断
		if (i % 2)
		{
			odd_cur->next = cur;
			odd_cur = odd_cur->next;
		}
		else
		{
			even_cur->next = cur;
			even_cur = even_cur->next;
		}
		cur = cur->next;
		i++;
	}
	// 处理链表结尾
	even_cur->next = NULL;
	// 连接两个链表
	odd_cur->next = even_head.next;
	return odd_head.next;
}
//
//int main(){
//	struct ListNode *l1, *l2, *pre_L1, *pre_L2, *l3;
//	int i = 1 , n = 3;
//	l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	l1->next = NULL;
//
//	pre_L1 = l1;
//	pre_L2 = l2;
//	for (i = 0; i< n; i++){
//		pre_L1->val = i+1;
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
//	l3 = oddEvenList(l1);
//	printList(l3);
//	getchar();
//}
