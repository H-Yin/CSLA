/*
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

/*

常规方法

struct ListNode* partition(struct ListNode* head, int x) {
	struct ListNode *pre = NULL, *cur = head, *last_pre = NULL;
	struct ListNode* new_head = (struct ListNode*)malloc(sizeof(struct ListNode));
	new_head->next = head;
	pre = new_head;
	while (cur)
	{
		// 查找比x小的值
		if (last_pre && cur->val < x)
		{
			pre->next = cur->next;
			// 头插法
			cur->next = last_pre->next;
			last_pre->next = cur;
			last_pre = cur;
		}
		else {
			// 记录第一个大于x的节点的前一个节点
			if (!last_pre && cur->val >= x)
			{
				last_pre = pre;
			}
			pre = pre->next;
		}
		cur = pre->next;
	}
	return new_head->next;
}*/

struct ListNode* partition(struct ListNode* head, int x) {
	struct ListNode min_head, max_head;
	struct ListNode *L = &min_head, *R = &max_head;
	while (head){
		if (head->val < x){
			L->next = head;
			L = L->next;
		}
		else{
			R->next = head;
			R = R->next;
		}
		head = head->next;
	}
	R->next = NULL;
	L->next = max_head.next;
	
	return min_head.next;
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
//		pre_L1->val = i%2 ? i: 10-i;
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
//	l3 = partition(l1, 5);
//	printList(l3);
//	getchar();
//}