/*

160. Intersection of Two Linked Lists

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
					↘
						c1 → c2 → c3
					↗
B:     b1 → b2 → b3
begin to intersect at node c1.

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

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	struct ListNode *preA = headA, *preB = headB;
	int flag = 0;
	if (preA == NULL || preB == NULL){
		return NULL;
	}
	while (preA != preB){
		if (preA == NULL){
			preA = headB;
		}
		else{
			preA = preA->next;
		}
		if (preB == NULL){
			preB = headA;
		}
		else{
			preB = preB->next;
		}

		if (preA->val == preB->val){
			return preA;
		}
	}
	return preA;
}

//
//int main(){
//	struct ListNode *l1, *l2, *pre_L1, *pre_L2, *l3, *look = NULL;
//	int i = 1, n;
//	l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	pre_L1 = l1;
//	pre_L2 = l2;
//	n = 10;
//	for (i = 0; i< n; i++){
//		pre_L1->val = i*2+1;
//		if (i != n - 1){
//			pre_L1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//			pre_L1 = pre_L1->next;
//		}
//		else{
//			pre_L1->next = NULL;
//		}
//	}
//	n = 3;
//	for(i=2; i< n; i++){
//		pre_L2->val = i;
//		if (i!= n-1){
//			pre_L2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//			pre_L2 = pre_L2->next;
//		}else{
//			pre_L2->next = NULL;
//		}
//	}
//	printList(l1);
//	printList(l2);
//	l3 = getIntersectionNode(l1,NULL);
//	//printList();
//	printf("%d\n", l3->val);
//	getchar();
//}
