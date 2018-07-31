/*

82. Remove Duplicates from Sorted List II

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

#include<stdio.h>
#include<stdlib.h>

#include "MyList.h"
//Definition for singly-linked list.

/*  9999999999 + 0 => overflow
struct ListNode* addTwoNumbers2(struct ListNode* l1, struct ListNode* l2) {
	unsigned long int a = 0, b = 0;
	struct ListNode *cur1 = l1, *cur2 = l2;
	struct ListNode new_head;
	struct ListNode *new_cur = &new_head, *temp;
	new_cur->next = NULL;

	while (cur1 || cur2)
	{
		if (cur1)
		{
			a = a * 10 + cur1->val;
			cur1 = cur1->next;
		}
		if (cur2)
		{
			b = b * 10 + cur2->val;
			cur2 = cur2->next;
		}
		printf("%ld,%ld\n", a, b);
	}
	printf("%ld,%ld\n", a, b);
	a = a + b;
	printf("%ld\n", a);
	if (a == 0)
	{
		temp = (struct ListNode*)malloc(sizeof(struct ListNode));
		temp->val = 0;
		temp->next = NULL;
		return temp;
	}
	while (a > 0)
	{
		temp = (struct ListNode*)malloc(sizeof(struct ListNode));
		temp->val = a % 10;
		temp->next = new_cur->next;
		new_cur->next = temp;
		a = a / 10;
	}
	return new_head.next;
}
*/
//ListNode* addToFront(int val, ListNode* head){
//	ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
//	temp->val = val;
//	temp->next = head;
//	return temp;
//}
//
//ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
//	int n1 = 0, n2 = 0, carry = 0;
//	ListNode *curr1 = l1, *curr2 = l2, *res = NULL;
//	while (curr1){ curr1 = curr1->next; n1++; }
//	while (curr2){ curr2 = curr2->next; n2++; }
//	curr1 = l1; curr2 = l2;
//	while (n1 > 0 && n2 > 0){
//		int sum = 0;
//		if (n1 >= n2){ sum += curr1->val; curr1 = curr1->next; n1--; }
//		if (n2 > n1){ sum += curr2->val; curr2 = curr2->next; n2--; }
//		res = addToFront(sum, res);
//	}
//	curr1 = res; res = NULL;
//	while (curr1){
//		curr1->val += carry; carry = curr1->val / 10;
//		res = addToFront(curr1->val % 10, res);
//		curr2 = curr1;
//		curr1 = curr1->next;
//		free(curr2);
//	}
//	if (carry) res = addToFront(1, res);
//	return res;
//}

//
//int main(){
//	struct ListNode *l1, *l2, *pre_L1, *pre_L2, *l3;
//	int i = 1,m = 10, n = 1;
//	l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	pre_L1 = l1;
//	pre_L2 = l2;
//	for (i = 0; i< m; i++){
//		// pre_L1->val = i<7  ? i>3 ? 1: 4: i;
//		pre_L1->val = 9;
//		if (i != m - 1){
//			pre_L1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//			pre_L1 = pre_L1->next;
//		}
//		else{
//			pre_L1->next = NULL;
//		}
//	}
//	
//	for(i=0; i< n; i++){
//		// pre_L2->val = (i + 1)*(i+2) % 10;
//		pre_L2->val = 0;
//		if (i != n-1 ){
//			pre_L2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//			pre_L2 = pre_L2->next;
//		}else{
//			pre_L2->next = NULL;
//		}
//	}
//
//	printList(l1);
//	printList(l2);
//	l3 = addTwoNumbers2(l1, l2);
//	printList(l3);
//	getchar();
//}
