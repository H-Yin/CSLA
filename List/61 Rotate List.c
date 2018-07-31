/*

61. Rotate List

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/


#include<stdio.h>
#include<stdlib.h>

#include "MyList.h"
//Definition for singly-linked list.

struct ListNode* rotateRight(struct ListNode* head, int k) {
	struct ListNode *pre = head, *tail = head;
	pre = head;
	tail = head;
	int i = k, len = 0;
	while (head && tail && i){
		// 设置窗口的前端指针，找到第n个节点
		while (tail && i){
			tail = tail->next;
			len++;
			i--;
		}
		// k > len 求余
		if (i > 0){
			tail = head;
			i = k % len;
		}
	}
	if (head && tail){
		// 窗口滑动，
		while (tail && tail->next){
			pre = pre->next;
			tail = tail->next;
		}
		// 指针调整
		tail->next = head;
		head = pre->next;
		pre->next = NULL;
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
//		pre_L1->val = i;
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
//	l3 = rotateRight(l1, 11);
//	printList(l3);
//	getchar();
//}
