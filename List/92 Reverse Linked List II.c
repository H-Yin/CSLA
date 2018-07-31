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
//Definition for singly-linked list.
#include "MyList.h"

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
	struct ListNode new_head;
	struct ListNode *pre = &new_head, *cur = head, *last;
	new_head.next = head;
	int i = 1;
	while (head && i < n)
	{
		// 找到需要移动的节点last ,头插法
		if (i >= m){
			last = cur->next;
			cur->next = last->next;
			// 头插法
			last->next = pre->next;
			pre->next = last;
		}
		else{ // 跳过前m个节点
			pre = pre->next;
			cur = cur->next;
		}
		i++;
	}
	return new_head.next;
}

//
//int main(){
//	struct ListNode *l1, *l2, *pre_L1, *pre_L2, *l3;
//	int i = 1;
//	l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	pre_L1 = l1;
//	pre_L2 = l2;
//	for (i = 0; i< 10; i++){
//		pre_L1->val = i % 2 ? i : 10 - i;
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
//	l3 = reverseBetween(l1, 10,10);
//	printList(l3);
//	getchar();
//}